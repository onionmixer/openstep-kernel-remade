# old IPC 송수신과 버퍼 상태 정적 검토

## 판정

수신 인터럽트는 새 메시지 복사가 완료된 상태가 아니다. 원본 `ipc_mqueue_receive`의 인터럽트 분기는 메시지 출력 없이 반환하고, `msg_receive`도 호출자 메시지를 새로 복사하지 않은 채 old IPC 오류로 변환한다. report54의 kernserv 루프는 이 반환을 dispatch 전 처리 위치로 연결한다. 실제 오동작이나 이전 요청 재실행 여부는 별도의 연속 상태 검증이 필요하다.

[범위](SCOPE.md), [원본·계산 증거](ipc-evidence.json), [이전 증거 보존](preservation.json), [남은 분석](OPEN_ITEMS.md)을 함께 보존한다. Ghidra 스킬의 원본 명령·호출 인자·타입 교차 확인을 보존 export에 적용했다. 원본 DB/export, 참조 소스와 복원 커널은 수정하지 않았다.

Python으로 본문 8개, 명령 691개, 1993바이트를 원본 LC_SEGMENT 파일 위치 및 기존 디코더와 대조했다. report54의 main 수신 창 52개 명령도 재대조했다. 입력 32개와 이전 파일 642개의 해시를 확인했다. 이는 정적 범위 대조이며 독립 계획 검토·동적 실행·전체 IPC 의미 검증은 아니다.

## `msg_receive` (`0x001588d4`)의 실제 ABI

Ghidra는 이 함수를 `void`와 복잡한 다중 포인터 타입으로 출력한다. 그러나 마지막 `0x001589ed`에서 호출한 `msg_return_translate`의 EAX가 epilogue에서 보존되어 반환된다. 원본을 void 함수로 복원하면 안 된다. 수신 timeout을 다중 포인터 인자로 표현한 것도 디컴파일 추론이지 실제 타입 증거가 아니다.

호출 초기에 caller message의 local port와 capacity를 저장한다. 그 뒤의 핵심 호출은 다음과 같다.

- `0x0015890d`: `ipc_mqueue_copyin(space, saved_name, &mqueue, &object)`.
- `0x0015894a`: `ipc_mqueue_receive(mqueue, option & 0x100, max_size, timeout, 0, 0, &kmsg_or_size, &seqno)`.
- `0x00158958`: 반환 뒤 `ipc_object_release(object)`.

RCV_LARGE가 설정되면 max_size는 저장한 capacity, 아니면 DWORD 최대값이다. RCV_INTERRUPT는 queue 옵션으로 직접 전달되지 않고 wrapper의 재시도 정책에 사용된다. kernserv의 `0x1500`에서는 timeout만 queue 옵션으로 전달하고, capacity를 최대 크기로 사용하며, 인터럽트는 상위로 반환한다.

Darwin 참조 `kern/ipc_mig.c`에는 대응되는 흐름이 있지만 queue receive에 OLD_FORMAT 옵션과 추가 인자가 있다. 해당 호출을 원본 ABI에 그대로 복사할 수 없다.

## 인터럽트의 queue → wrapper → kernserv 연결

원본 queue receive (`0x0014acd4`)가 IPC 완료 전 깨어난 상태이면 `0x0014ae69`에서 수신 대기열에서 현재 스레드를 제거한다. 이어 스레드 `+0x44`의 wait result를 확인한다.

- 값 1: timeout을 0으로 바꿔 queue를 다시 검사한다.
- 값 2 또는 3: queue lock을 해제하고 `0x0014ae8c`에서 `MACH_RCV_INTERRUPTED`를 반환한다. 이 분기는 `*kmsgp`와 `*seqnop`를 쓰지 않는다.
- 그 밖의 값: 원본은 queue를 다시 검사한다. Darwin 참조의 일부 default panic 동작과 다르므로 소스의 switch를 그대로 채택하지 않는다.

값의 이름은 참조 `sched_prim.h`의 TIMED_OUT/INTERRUPTED/SHOULD_TERMINATE와 대응한다. 스케줄러가 실제로 어떤 조건에서 이 값을 만들고 경쟁을 해결하는지는 미완료다.

`msg_receive`는 인터럽트 반환 시 thread의 halt 조건을 처리한 뒤 RCV_INTERRUPT가 없으면 copyin부터 재시도한다. RCV_INTERRUPT가 있으면 새 메시지 copyout/put 없이 오류를 변환한다. 원본 caller buffer를 이 wrapper가 갱신하는 경로는 TOO_LARGE의 크기 저장 또는 수신 성공 이후 복사 경로다. opaque callee의 임의 alias나 메모리 손상까지 배제하는 증명은 아니다.

| 경계 | kernserv caller 메시지에 대한 확인 사실 |
|---|---|
| 수신 직전 | main이 local port를 port_set으로, 크기를 현재 capacity로 설정한다. |
| queue 인터럽트 | 새 kmsg/seqno를 출력하지 않는다. |
| wrapper 반환 | 새 메시지를 복사하지 않고 `RCV_INTERRUPTED`를 반환한다. |
| main의 다음 분기 | 성공 경로와 같은 dispatch 전 처리 위치로 간다. |

따라서 local port까지 포함한 이전 요청이 그대로 남는다는 설명은 부정확하다. local port와 크기는 이미 main이 덮어썼고, 다른 필드는 이전 내용 또는 아직 의미가 확정되지 않은 내용일 수 있다. 이 상태에서 notification/port dispatch가 어떤 효과를 내는지는 실제 입력·초기화·포트 값·동시성을 연결해야 판정할 수 있다.

## TOO_LARGE와 성공 경로는 다르다

queue에 대기 중인 첫 메시지가 max_size보다 크면 `0x0014ad0f`에서 출력 슬롯에 **포인터가 아니라 필요한 크기**를 쓰고 queue lock을 해제한다. 이 분기는 해당 메시지를 dequeue하지 않는다. 대기 스레드가 TOO_LARGE 상태로 깨어난 경우에도 `0x0014ae51`에서 크기를 출력한다. 그 상태의 생산자와 소유권은 추가 분석 대상이다.

wrapper는 `MACH_RCV_TOO_LARGE`를 받으면 `0x001589a8`에서 caller의 msg_size만 갱신한다. report54의 main 재할당 경로가 읽는 값이 이것이다. payload나 다른 헤더 필드를 새 메시지로 채우는 동작은 아니다.

한편 queue가 성공을 반환한 뒤 wrapper가 다시 메시지 크기와 saved capacity를 비교하여 초과를 발견하면 kmsg를 destroy하고 TOO_LARGE를 반환한다. 이 분기에는 caller msg_size 갱신이 없다. 정상적인 RCV_LARGE 입력에서 이 분기가 도달 가능한지 여부를 이번 정적 분석만으로 확정하지 않는다.

크기가 허용되면 `0x001589ce`에서 `ipc_kmsg_copyout_compat(kmsg, space, map)`을 호출한다. **그 결과가 nonzero여도 이 wrapper에는 다음 복사를 건너뛰는 분기가 없다.** kmsg의 size에 delta를 더하고 `0x001589e7`에서 caller로 복사한 뒤, 저장해 둔 copyout 결과를 변환한다. copyout 오류일 때 kmsg가 어떤 상태와 크기를 갖는지는 다음 핵심 검증 항목이다.

## 오류 변환과 실제 반환값

`msg_return_translate` (`0x001540dc`)는 AH 마스크를 적용한다. Python 계산 결과 입력 마스크는 `0xffffc3ff`, 제거되는 부가 오류 비트는 `0x3c00`이다. 이번 경로에 필요한 CMP/Jcc와 반환 지점은 다음과 같다.

| 내부 결과 | old IPC 결과 |
|---|---|
| 성공 | 0 |
| `0x10004003` 수신 timeout | -203 |
| `0x10004004` 수신 TOO_LARGE | -204 |
| `0x10004005` 수신 interrupt | -207 |
| `0x10000004` 송신 timeout | -103 |
| `0x10000007` 송신 interrupt | -108 |
| `0x1000000d` 송신 버퍼 부족 | 메시지를 출력한 뒤 -108 |

따라서 old 오류 이름만으로 원래 원인을 유일하게 복구할 수 없다. 알려지지 않은 내부 값은 panic 분기로 갈 수 있으며, 모든 정수를 일반적인 오류값으로 돌려주는 함수가 아니다. 표는 원본의 정적 분기 추적과 Python signed 변환 결과이지 실행 시험 결과가 아니다.

## `msg_send` (`0x00158774`)와 kmsg 생성

원본은 msg_size를 DWORD 산술로 정렬하고 upper bound를 확인한다. 정상적인 비음수 크기 범위에서는 정렬 크기 `round4(size)`, delta `size-round4(size)`를 사용한다. `0x001587c3`의 호출은 `ipc_kmsg_get_from_kernel(msg, rounded_size, delta, &kmsg)`로 **인자 4개**다. Darwin 참조의 option 인자가 추가된 선언과 다르다.

`ipc_kmsg_get_from_kernel` (`0x00147688`)은 정렬 크기에 `0x14`를 더해 kalloc하고, 성공 시 allocation size `+8`, marequest `+0xc`, delta `+0x10`, header `+0x14`를 다룬다. 실제 복사량은 rounded_size+delta이고 이후 kmsg header size를 rounded_size로 기록한다. 정상 범위에서는 원래 크기만 복사하며 정렬 패딩을 새로 0으로 채우는 명령은 없다.

예를 들어 Python 계산에서 입력 25는 rounded=28, delta=-3, 복사량=25이다. 최소 헤더 크기, DWORD overflow 및 호출자 버퍼 extent를 이 wrapper/get helper가 모두 검증하는 것은 아니다. 증거의 경계 산술 사례는 상한 비교의 한계를 보이기 위한 것이며 유효 메시지나 실제 오류 실행으로 취급하지 않는다.

복사 후 `ipc_kmsg_copyin_compat`가 실패하면 kmsg allocation 형태에 따라 해제한 뒤 오류를 변환한다. 성공 이후 SEND_NOTIFY는 원본에서 panic이다. SEND_TIMEOUT과 SEND_SWITCH는 queue send 옵션으로 변환되고, SEND_INTERRUPT는 wrapper 재시도 중단 조건으로 사용된다. queue send가 실패하고 재시도가 끝나면 kmsg를 destroy한다. 이로부터 port/VM 참조가 모든 실패 경로에서 정확히 회수된다고 확대할 수는 없다.

## kmsg put과 실제 byte copy

`ipc_kmsg_put_to_kernel` (`0x00147770`)은 kmsg `+0x14`에서 caller로 지정 크기를 bcopy한 다음 allocation kind를 처리한다. `+8` 값이 -2이면 device interrupt release, -3이면 netipc release, -1이면 이 본문에서 해제하지 않는다. 그 외에는 kfree 경로다. 이름과 sentinel만으로 각각의 메모리 수명 전체를 확정하지 않는다.

`bcopy` (`0x001013cc`)는 인자 순서를 바꿔 `memcpy(destination, source, count)` (`0x001013e4`)를 호출한다. 원본 memcpy는 REP 문자열 명령과 잔여 바이트 복사를 사용한다. 이 함수 본문에 CLD 또는 overlap 검사는 없다. 정상적인 전방 복사 해석에는 DF-clear 등 호출 환경 조건이 필요하며, 일반적인 overlap-safe memmove 계약으로 대체하지 않는다. 디컴파일의 전방 C loop는 이러한 머신 상태 조건을 표현하지 못한다.

## 참조 소스 채택 제한과 다음 분석

Darwin `ipc_kmsg.h`에는 `ikm_sender`와 확장된 구조가 있고, kmsg get/queue receive의 인자 및 포맷 처리도 원본과 다르다. 이번에 확인한 원본 오프셋을 해당 헤더의 host sizeof로 재해석해서는 안 된다. 의미가 대응되는 부분과 ABI가 다른 부분을 분리해야 한다.

다음은 copyout_compat의 오류 후 kmsg 상태, queue send의 대기·소유권·수신자 전달, thread wait 결과 생성자, kernserv의 notification/dispatch 연속 상태다. 현재 결과는 실제 부팅·동시 실행·GCC 2.7 실컴파일 또는 전체 원본 분석 완료를 증명하지 않는다.

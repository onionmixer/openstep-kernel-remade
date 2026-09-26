# compat copyout: 성공 반환과 내부 실패 처리

## report55의 미확정 사항 갱신

원본 `ipc_kmsg_copyout_compat`는 정상적으로 제어를 반환할 때 **항상 0**을 반환한다. report55에서 wrapper만 보고 남겨 둔 “callee의 nonzero 오류 반환 후 put” 가능성은 이 정확한 callee의 정상 반환 경로로는 뒷받침되지 않는다. wrapper가 반환값 검사 없이 put하는 사실은 유지되지만, 다음 검증 대상은 **성공 반환 안에서 일부 포트·메모리를 잃거나 0으로 바꾸는 처리**다.

이 갱신은 이전 보고서의 조건부 미완료 항목을 좁히는 것이다. 과거 증거 파일은 수정하지 않았다. fault·panic·비복귀 또는 stack 손상을 정상 반환과 혼동하지 않는다.

[범위](SCOPE.md), [원본·정적 CFG·계산 증거](copyout-evidence.json), [이전 파일 보존](preservation.json), [남은 분석](OPEN_ITEMS.md)을 보존한다. Ghidra 스킬의 함수·참조·타입 교차 확인을 보존 export에 적용했다. 계산은 Python만 사용했다.

## 원본 재대조와 반환 증명 범위

본문 3개, 명령 448개, 1244바이트를 원본 파일 위치와 디코더에 대조했다. report55의 caller 창 17개 명령도 재대조했다. 입력 16개를 지문 기록하고 이전 파일 648개를 재해시했다. Ghidra 입력은 full-analysis manifest와 일치한다.

`0x00149c60` 본문의 정상 RET는 `0x0014a0d5` 하나다. Python으로 원본 명령의 정적 분기 그래프를 만들고 `0x0014a0ca` 노드를 제거했을 때 entry에서 RET에 도달할 수 없음을 확인했다. 그 노드는 `XOR EAX,EAX`이며 뒤 epilogue는 EAX를 바꾸지 않는다.

이 그래프는 모든 CALL이 정상 반환할 수 있다고 모델링했다. 하위 함수의 실제 실패·panic·비국소 제어 이전·동시성·메모리 안전을 검증한 것이 아니다. 동적 실행이나 독립 계획 검토로 집계하지 않는다.

## header 변환은 원자적 rollback이 아니다

원본은 kmsg `+0x14`의 bits, `+0x1c`의 destination object, `+0x20`의 reply object를 읽는다.

- destination이 active이면 `ipc_object_copyout_dest(space, object, remote_type, &name)`를 호출한다. inactive이면 reference를 감소시키고 필요 시 zone 해제 경로를 거친 뒤 이름을 0으로 한다. 객체의 active/참조/락 계약 전체는 아직 미검증이다.
- reply가 0 또는 -1이면 이름 0. 유효 객체의 compat copyout이 실패하면 `ipc_object_destroy`를 호출하고 reply 이름을 0으로 한다. 상위 오류 반환으로 전환하지 않는다.
- 그 뒤 old header를 kmsg에 덮어쓴다. unused 하위 비트는 0, simple은 complex bit의 반대, size와 type/id는 원래 헤더에서 가져오고 local/remote port는 변환한 이름이다.

`0x00149d77`은 CLD 후 6 DWORD, Python 계산으로 24바이트를 복사한다. simple이면 바로 정상 반환 경로로 간다. complex이면 본문 변환을 계속한다. header와 앞선 descriptor 변환을 일괄 되돌리는 경로는 이 본문에 없다. size는 기존 값을 다시 쓰며 kmsg delta `+0x10`을 직접 수정하는 명령은 없다. 잘못된 alias 입력이나 하위 함수의 예상 밖 쓰기까지 배제하는 주장은 아니다.

Darwin 참조 `ipc/ipc_kmsg.c`도 header를 원자적으로 처리하지 않고, 문제 포트·메모리를 0으로 표현하며 성공을 반환하는 정책을 설명한다. 이는 정책 대응이며 구조체·인자 ABI 전체 동일성의 증명이 아니다.

## complex descriptor 진행과 내부 실패

본문은 kmsg `+0x2c`에서 시작하여 `header + size`까지 진행한다. short descriptor는 4바이트, long descriptor는 12바이트이다. number·element size를 읽어 DWORD 산술로 byte length를 계산하고 inline 데이터는 정렬 길이만큼, out-of-line(OOL) 데이터는 주소 슬롯만큼 진행한다.

입력 descriptor가 시작 범위 안에 있다는 것과 descriptor 전체·payload·포인터 배열이 유효하다는 것은 다르다. 이 본문에는 그 모든 범위 검증이 없다. 특히 포트 순회는 각 원소를 DWORD로 다루므로 size/count의 생산자 불변식을 확인해야 한다.

| 내부 사건 | 이 본문의 처리 | 정상 상위 반환 |
|---|---|---|
| reply/body 포트 변환 실패 | 해당 object destroy 호출, 슬롯 또는 이름 0 | 0 |
| OOL 포트용 대상 VM 할당 실패 | 현재 descriptor의 자원 정리 경로, 주소 슬롯 0, 다음 descriptor로 진행 | 0 |
| OOL 일반 메모리 vm_move 실패 | source VM deallocate 호출 후 주소 0 | 0 |
| OOL 포트 배열 copyoutmap 실패 | 반환값을 검사하지 않고 source 배열 kfree, 대상 주소는 유지 | 0 |

표의 0은 함수가 최종 RET까지 정상 도달한다는 조건이다. 정리 호출 자체가 성공했는지, 모든 권한이 정확히 해제되는지는 별도 검증 대상이다.

### OOL 포트 할당 실패의 정리 범위

`0x00149e4b`의 vm_allocate가 실패하면 descriptor 시작과 데이터 시작 사이를 대상으로 정리 루프가 실행된다. 유효 포트 object에 destroy를 호출하고 OOL 배열을 kfree하는 흐름이다. 이것을 이미 처리한 메시지 전체나 뒤쪽 모든 descriptor의 rollback이라고 표현해서는 안 된다.

실패 경로는 정상 포트 타입 변환 지점 `0x00149f9b`를 건너뛰고 주소를 0으로 한다. 이 단계에서 number/size를 모두 0으로 만들거나 descriptor 타입까지 정상 변환한다고 가정하지 않는다. old 메시지 소비자가 이를 어떻게 해석하는지 추가 확인이 필요하다.

### OOL 일반 메모리와 포트 배열의 차이

일반 메모리는 `0x0014a08d`에서 `vm_move(ipc_soft_map, source, target_map, length, 0, &address)`를 호출한다. 이어 `0x0014a0a1`에서 source 영역을 deallocate하고 저장했던 vm_move 결과를 검사한다. 실패이면 주소를 0으로 쓴다. deallocate 결과로 이를 다시 보정하는 분기는 없다.

포트 배열은 앞서 대상 공간을 할당하고 원소별 권한을 변환한 뒤 `0x0014a05a`에서 `copyoutmap(target_map, source_array, address, length)`을 호출한다. 이후 EAX 검사 없이 `0x0014a064`에서 source 배열을 kfree한다. 그러므로 주소가 nonzero라는 사실만으로 배열 내용이 성공적으로 복사되었다고 판단할 수 없다. 이 경로가 실제로 실패하는 입력은 이번에 실행하지 않았다.

## 포트 타입의 허용 범위는 단계마다 다르다

본문의 is_port 검사는 unsigned `name - 0x10 <= 5`이다. 그러나 `ipc_object_copyout_type_compat` (`0x0014c0e4`)가 정상 변환하는 것은 다음과 같다.

- 16 → old `MSG_TYPE_PORT_ALL`(5).
- 17, 18 → old `MSG_TYPE_PORT`(6).
- 다른 값으로 helper를 호출하면 panic 경로다.

따라서 넓은 분류 검사만 보고 모든 port-any 이름이 정상 copyout 가능하다고 하면 안 된다. 송신 단계에서 권한 타입을 carried form으로 정규화하는 계약을 확인해야 한다. 증거 JSON의 범위 밖 helper 결과는 **그 helper를 호출했을 경우**이며, 본문이 non-port descriptor에도 무조건 helper를 호출한다는 뜻이 아니다.

## `copyoutmap` (`0x00174120`)의 제한

이 helper는 다음 분기를 가진다.

1. target map `+0x24`가 kernel_pmap과 같으면 bcopy 후 0.
2. 그 외에 target map이 현재 task의 map과 같으면 copyout의 반환값을 전달.
3. 그 외에는 복사하지 않고 1을 반환.

일반적인 임의 map 간 복사 구현이 아니다. Darwin `vm/vm_kern.c`의 대응 함수도 이 제한을 가진다. 앞서의 포트 배열 경로는 이 반환값을 무시한다. 다만 `msg_receive`는 호출 초기에 현재 map을 보관해 전달하므로, foreign-map 분기가 해당 정상 호출에서 반드시 발생한다고 주장하지 않는다. 다른 호출자·map 변경·copyout fault를 구분해야 한다.

kernel_pmap 분기의 bcopy와 current-map 분기의 copyout 내부 안전성, target allocation의 후속 회수, 권한 설치와 복사 사이의 실패 의미는 미완료다.

## 다음 분석 경계

report55의 첫 미완료 항목은 “nonzero copyout 반환”에서 “성공 반환으로 표현되는 부분 손실과 자원 회수”로 갱신한다. 이어갈 핵심은 `ipc_object_copyout_compat`/destroy의 권한 소유권, 송신 copyin의 carried-type·크기 검증, OOL VM 이동/해제의 실제 계약, 수신 소비자의 null/미변환 descriptor 처리다.

원본 정상 반환 0을 입증한 것은 모든 내부 동작 성공이나 안전성의 증명이 아니다. 새 동적 검증·복원 구현·GCC 2.7 실컴파일은 수행하지 않았고 전체 목표도 미완료다.

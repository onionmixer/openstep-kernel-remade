# 송신 권한의 lookup·copyin·receive clear 원본 검토

## 결과와 검증 범위

송신 wrapper 아래의 권한 복제/이전, 죽은 객체의 entry 변환, 성공/오류의 출력·락 해제를 원본 본문으로 연결했다. 동시에 **락 대기 루프의 메모리 읽기가 Ghidra C의 표현과 달리 반복 구간 밖에 있는 패턴**을 확인했다. 이 때문에 이전 보고서의 lock 요약도 경합 시 진행성까지 입증한 것으로 해석하면 안 된다.

[증거](right-copyin-evidence.json)에 함수 5개, 명령어 806개, 본문 2365바이트를 보존했다. Python으로 원본 Mach-O segment를 직접 읽어 VA/file offset을 계산하고 보존 decoder의 원본 읽기·명령 길이, Ghidra 본문 범위·직접 분기 목적지를 대조했다. 이전 보고서 57의 일부 락 패턴은 별도 12개 명령어 window로 다시 대조했다. 입력 fingerprint 32개와 이전 산출물 666개의 해시도 확인했다. 원본 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다.

Ghidra 스킬은 보존 ASM/C의 읽기 전용 비교에 적용했다. 모든 계산은 Python으로 수행했다. 독립 계획 검토 미확보 상태를 유지하며 새 검증 프로그램·동적 실행·DB/원본/`07_kernel` 수정·GCC 2.7 실빌드는 하지 않았다. 아래는 callee 정상 반환과 유효 입력 불변조건을 전제로 한 정적 계약이며, 전이적 소유권·동시성의 완결 증명이 아니다.

## 중요한 보정: 락 경합 루프

예를 들어 `_ipc_right_lookup_write`의 원본은 다음 순서이다.

```text
0x14db18  MOV EAX,[EDX]
0x14db1a  TEST EAX,EAX
0x14db1c  JNZ 0x14db1a       ; raw 75 fc
```

분기 변위와 목적지는 Python에서 원본 바이트로 계산했다. TEST/JNZ 내부에는 EAX 변경이나 메모리 재읽기가 없다. 따라서 이 구간 진입 시 EAX가 비제로이면, 다른 실행 주체가 락 메모리만 0으로 바꾸어도 이 명령 순환 자체는 그것을 관찰하지 못한다. 외부에서 실행 상태/레지스터/코드를 바꾸지 않는다는 조건하의 원본 명령 의미이다. 실제 경합 발생, 부팅 후 패치 유무, CPU 구성 및 interrupt/context 경로는 검증하지 않았다. 이를 관측된 시스템 정지나 전체 커널의 진행성 실패로 확대하지 않는다.

메모리 읽기에서 0을 얻으면 XCHG로 1을 넣고 이전 값과 1을 XOR하여 시도 결과를 판단한다. 경쟁한 XCHG의 이전 값이 1이면 바깥 루프로 돌아가 다시 load한다. 이 **바깥 retry**와 위의 **안쪽 register-only loop**는 다르다. Ghidra C의 `while (*lock != 0)`를 메모리 재관찰 보장으로 받아들이면 안 된다.

이번 본문에서 확인한 해당 패턴은 11곳이다. 별도 제한 확인에서는 보고서 57의 object copyout compat에서 3곳, space reference에서 1곳을 찾았다. [보고서 57](../continuous-review-20260912-57/README.md)의 “lock 후/해제 후”는 획득 경로를 통과한 경우의 순서 설명으로 제한한다. 과거 파일은 변경하지 않고 이 보정을 연결한다. 전체 커널의 동일 패턴 전수 여부는 아직 판정하지 않았다.

Darwin 참고 `mach/i386/simple_lock.h`는 `boolean_t locked` 및 plain `while (slock->locked)`와 inline XCHG를 사용한다. 이 소스는 원본 코드 형태와 관련된 참고일 뿐, 정확한 원본 소스·컴파일러 옵션·최적화 원인이나 GCC 2.7 재현 결과를 입증하지 않는다. 원본과 다른 메모리 반복 읽기를 임의로 넣는 것은 별도 정책/수정 판단이며 이번 단계에서 하지 않았다.

## 이름 lookup과 락 소유권

`_ipc_right_lookup_write` (`0x14db08`)는 space+8의 락 획득 경로를 통과한 뒤 space+0xc active를 검사한다. dead space이면 락을 0으로 XCHG하고 `0x10`을 반환한다. active이면 `_ipc_entry_lookup(space,name)`을 호출한다. null이면 space를 unlock하고 `0xf`; nonnull이면 `*entryp`를 쓰고 0을 반환하며 **space 락은 유지한다**. 실패에서는 entryp를 쓰지 않는다. 상수는 SDK의 INVALID_TASK/INVALID_NAME과 대응한다.

`_ipc_entry_lookup` (`0x145e98`)는 자체 락 획득/해제 없이 name의 index(`name >> 8`)를 space+0x18 table size와 unsigned 비교한다. 범위 안에서는 space+0x14 table에 16바이트 stride로 접근한다. entry bits의 high generation byte를 `(name << 24) & 0xffffffff`와 비교한다. generation 일치라도 type mask `0x1f0000`이 0이면 null이다. generation 불일치에서 collision bit `0x800000`가 있으면, 또는 index가 범위 밖이고 space+0x38 tree total이 비제로이면 `_ipc_splay_tree_lookup(space+0x20,name)`을 호출한다. tree 결과는 그대로 반환하며 그 하위 구조의 정확성은 아직 검증하지 않았다.

[보고서 58](../continuous-review-20260912-58/README.md)의 wrapper가 lookup 성공 후 right copyin을 호출하는 순서는 이 락 유지 계약과 맞는다. right copyin은 space active를 재검사하지 않으므로 진입 시 락·active·entry 일관성이 전제이다.

## 헤더 권한 copyin

`_ipc_right_copyin_header` (`0x150364`)는 `(space,name,entry,objectp,typep)`를 받는다. type 판정은 entry bits & `0x1f0000`이다. 모든 정상적인 성공 반환은 objectp/typep를 채우고 0이며, 오류는 출력 포인터를 쓰지 않고 space를 unlock한다. panic 경로는 정상 반환 계약에서 제외한다.

| entry 타입 | 원본 성공 경로 | 메시지 내부 타입 |
| --- | --- | --- |
| RECEIVE `0x20000` | port lock 후 space unlock, mscount/srights/object refs 증가, port unlock | SEND `0x11` |
| SEND `0x10000`, SEND_RECEIVE `0x30000` | port active 확인 후 space unlock, srights/object refs 증가, port unlock | SEND `0x11` |
| SEND_ONCE `0x40000` | 요청 취소 처리, port unlock, entry object를 0으로 만들고 entry dealloc, 알림용 권한 복사, space unlock, 알림 호출 | SEND_ONCE `0x12` |
| PORT_SET `0x80000`, DEAD_NAME `0x100000` | space unlock 후 INVALID_RIGHT `0x11` | 출력 없음 |
| 그 밖의 mask 값 | panic 호출 | 정상 출력 계약 없음 |

RECEIVE 경로는 active/receiver/name을 추가 검사하지 않는다. 참고 소스의 해당 assert를 원본 runtime 검사로 옮겨 설명하면 안 된다. SEND 계열과 SEND_ONCE는 port+8 signed 음수 여부로 active를 구분한다. SEND_ONCE 성공은 이 본문에서 port refs/sorights를 증가·감소시키지 않고 기존 참조를 메시지로 이전하는 형태이다. entry 제거와 참조 감소를 같은 것으로 보아서는 안 된다.

SEND_ONCE에서 entry request가 있으면 `ipc_port_dncancel(port,name,request)` 후 request=0을 저장한다. compat bit가 있으면 `ipc_space_release(space)`를 호출하고 일반 dn 알림 대상은 0으로 둔다. entry 제거 후 space+0x44의 notify port를 `ipc_port_copy_send`로 복사하고 space를 unlock한다. dn 대상이 비제로이면 일반 port_deleted, 복사한 notify가 0/`0xffffffff`가 아니면 compat port_deleted를 호출한다. 이 notification/ref callee 전체는 이번 본문 대조로 검증되지 않는다.

## body compat 권한의 복제/이전

`_ipc_right_copyin_compat` (`0x14fecc`)는 `(space,name,entry,old_type,dealloc,objectp)`를 받는다. old type 5/6만 switch에서 인정하며 그 외는 panic 경로이다. 이는 caller가 5/6에 한해서만 호출한다는 이전 분석과 맞지만, caller가 다른 타입을 일반 데이터로 통과시키는 문제까지 해소하지 않는다.

| old 타입·dealloc | 필수 entry 조건 | 성공 시 처리 |
| --- | --- | --- |
| 6·비제로 | type가 정확히 SEND | 살아 있는 port의 요청을 취소하고 hash/entry를 제거한다. 본문에서 srights/ref를 변화시키지 않고 메시지로 이전한다. SEND_RECEIVE는 이 분기에서 거부한다. |
| 6·0 | SEND/RECEIVE bit 중 하나 이상 | 살아 있는 port에서 srights/ref 증가. SEND가 없으면 mscount도 증가한다. entry는 유지한다. |
| 5·비제로 | RECEIVE bit 필요 | entry 제거, SEND도 있었다면 srights 감소 및 마지막 sender의 nsrequest 분리, receiver clear와 receiver name/destination 0, unlock 후 알림. 기존 참조 이전으로 본문에 ref 증가 없음. |
| 5·0 | RECEIVE bit 필요 | SEND가 없으면 srights 증가와 SEND/uref=1 추가. hash insert, RECEIVE bit 제거, entry 유지. receiver clear와 name/destination 0, 메시지용 ref 증가. |

type 5의 두 경로는 RECEIVE 소유의 port active/receiver 일관성을 별도 runtime 비교 없이 신뢰한다. dealloc이 0이어도 RECEIVE 권한은 이동하며, 그 이름에 SEND 권한을 남긴다는 점이 중요하다. dealloc 비제로를 단순 “uref 하나 줄이기”로 구현해서도 안 된다. type 6의 dealloc 성공은 entry 전체를 제거한다.

type 5·dealloc 비제로에서 SEND가 있고 이전 srights가 1이면 감소 후 마지막 sender로 판정한다. nsrequest가 비제로인 경우 port+0x24를 0으로 만들고 이전 mscount를 저장한다. receiver clear 후 port unlock, no_senders/port_deleted 알림 순이며 저장 mscount를 사용한다. 이 경로의 entry/hash/notification 하위 함수가 내부에서 무엇을 하는지까지 단정하지 않는다.

## 죽은 port 경로는 실패여도 상태를 바꾼다

header의 SEND/SEND_ONCE 경로 및 body type 6의 active 검사 실패에서는 port를 unlock한 후 원본에 inline된 죽은 권한 정리를 수행한다. SEND bit가 있으면 marequest가 설정된 경우 취소하고 hash delete를 호출한다. 이어 object release를 호출한다.

compat entry는 request/object를 0으로 두고 entry dealloc한다. 일반 entry는 type를 DEAD_NAME으로 바꾸고 request가 있었으면 request=0과 bits 증가를 수행하며 object=0을 저장한다. 마지막 오류 분류는 저장한 초기 compat bit에 따라 INVALID_NAME `0xf` 또는 INVALID_RIGHT `0x11`이다. 이미 DEAD_NAME/PORT_SET인 헤더의 직접 거부 경로는 이 변환 경로와 다르다.

따라서 “실패이므로 entry나 참조에는 아무 변화가 없다”는 가정은 틀리다. 반대로 출력 objectp는 성공 전에 쓰지 않으므로 caller의 부분 cleanup은 이전 성공 prefix를 대상으로 한다. 이것만으로 하위 해제·요청 소유권을 모두 증명한 것은 아니다.

일반 dead-name 변환의 request에 따른 bits 증가는 원본에서 DWORD INC이며 uref saturation 검사 분기가 없다. Python으로 계산하면 urefs 65535에 대한 단순 증가가 type bit까지 전파될 수 있다. Darwin 참고 소스에는 `urefs < MACH_PORT_UREFS_MAX` assert가 있으나 원본에서 그 비교를 확인하지 못했다. request 생성 시의 불변조건을 확인해야 하며, 이 조합이 실제 생성·도달한다고 판정한 것은 아니다.

## receiver clear의 세부 효과와 Ghidra 순서 차이

`_ipc_port_clear_receiver` (`0x14c89c`)는 이미 port가 locked/active라는 전제의 helper다. pset(port+0x30)이 있으면 pset lock 경로 후 `ipc_pset_remove(pset,port)`를 호출한다. **pset+4 ref 수는 `0x14c8ca`에서 unlock(`0x14c8cf`) 전에 읽고**, 그 저장값이 0이면 unlock 후 object zone을 선택해 zfree한다. Ghidra C는 ref 조건의 메모리 읽기를 unlock 뒤에 놓으므로 동시성 검토에서는 원본 순서를 사용해야 한다.

pset이 없으면 port+0x40 message queue lock 경로 후 `ipc_mqueue_changed(queue,0x10004009)`를 호출하고 queue를 unlock한다. 이후 공통으로 mscount(port+0x18)=0, 다시 queue lock 후 seqno(port+0x34)=0, queue unlock이다. port 자체의 lock은 caller가 유지하며 이 함수가 receiver name/destination까지 지우는 것은 아니다. 그 필드 0 저장은 위 body caller에 있다.

Ghidra의 반환값은 마지막 XCHG에 남은 incidental EAX이다. 참고 소스 선언은 void이고 검토한 caller는 이를 검사하지 않는다. 이를 업무 상태 반환값으로 복원하면 안 된다. pset remove, mqueue changed의 wakeup/ref 내부는 추가 분석 대상이다.

## 다음 작업과 전체 판정

락 루프 문제는 범용 simple_lock/빌드·실행 환경 전제로 연결하여 다루되, 이번 원본 분석을 임의 수정으로 바꾸지 않는다. 즉시 이어갈 정적 범위는 요청 취소/space release, entry dealloc/hash 및 receiver clear의 pset/mqueue 호출 계약이다. [미완료 항목](OPEN_ITEMS.md)에 전체 범위를 유지한다. 전체 의미 분석, GCC 2.7 실컴파일 및 부팅 검증은 아직 미완료다.

# 88차 — SCSI 요청의 큐·완료·조건 잠금

## 확인한 범위

원본의 비동기 완료 후보에서 B의 오류 WORD·잔여 길이를 기록하고 biodone을 호출하는
경로를 연결했다. 제출 큐의 지역 반환 계약, worker의 dequeue/명령 분기,
동기·비동기 해제 책임과 조건 잠금의 실제 명령도 대조했다.
doSdBuf의 실제 전송·완료 도달성 및 실행 시 메서드 등록은 아직 미해결이다.

Python 결과: 17개 본문, 781개 instruction head, 2,222바이트, 직접 분기 59개,
직접 CALL 75개, 간접 분기 1개, 명시적 중요 operand 검사 135개다.
선택 본문의 Ghidra 경고는 0개이나, 아래와 같은 의미 차이가 남아 있어 무경고를
정확성 증명으로 쓰지 않았다. register-only 재시험 spin 2곳, method list 4개/entry 32개,
category window 3개, NXConditionLock class 1개, selector slot 17개,
class 이름 참조 slot 2개, 참조 행 804개, jump-table entry 8개를 보존했다.
입력 62개와 기존 파일 819개를 해시 대조했다. bzero/memset의 예비 열람 파일 4개는
입력에는 포함하지만 전체 raw-검증 본문에는 포함하지 않는다.

[원본 증거 JSON](object-lifetime-evidence.json), [범위](SCOPE.md),
[잔여 작업](OPEN_ITEMS.md), [검증 결과](checkpoint.json),
[기존 파일 보존 해시](preservation.json), [87차 연결](../continuous-review-20260913-87/README.md).

## 원본 metadata 연결

87차 SCSIDisk `Private` list `0x1f88f8`의 alloc/enqueue/free/initResources 후보와,
`Thread` list `0x1f8990`의 unlockIoQLock/sdIoComplete/doSdBuf 후보를 재대조했다.
category pointer는 각각 `0x2078d0`, `0x2078e4`다.
IODisk `kernelDiskMethods` list `0x1f87f8`, pointer `0x2078bc`는
`completeTransfer:withStatus:actualLength:` → `0x1ac298`을 담는다.

NXConditionLock의 원본 class `0x1fa1f4`는 method list `0x1fc334`를 가리킨다.
해당 list의 initWith/free/lock/unlock/lockWhen/unlockWith를 검토했다.
`0x1f9d64`의 파일 값은 NXConditionLock **이름** 주소이고 class의 superclass도
파일에서는 Object 이름 주소다. 아직 loader fixup·category override·실제 receiver
생성이 입증된 것은 아니다. 아래 연결은 해당 원본 IMP가 선택된다는 조건부 계약이다.

## 요청 R의 할당과 해제

`allocSdBuf:(pending)` 후보 `0x1ad828`은 IOMalloc에 `0x44`(68)바이트를 요청하고
그 반환 포인터로 bzero(R, 0x44)를 호출한다. 자체 NULL 검사나 할당 실패 분기는 없다.
IOMalloc `0x1a5448`은 kalloc `0x15a75c`의 반환 EAX를 그대로 전달한다.
Ghidra의 void 출력만으로 이 반환을 지우면 안 된다.

pending 비영이면 R `+0x18`에 저장한다. pending==0이면 NXConditionLock에 alloc을
보내고 그 반환을 R `+0x1c`에 먼저 저장한 뒤 initWith:(0)을 호출한다.
initWith 반환값으로 그 필드를 교체하지 않는다. bzero의 호출과 인자는 확인했으나
실제 주소 유효성·memset 전체 동작은 이번에 종단 간 확정하지 않았다.

`freeSdBuf:(R)` 후보 `0x1ad880`은 R `+0x18`==0일 때만 R `+0x1c` 객체에 free를
보내고, 그 뒤 IOFree(R, 0x44)를 호출한다. IOFree `0x1a5458`은
kfree `0x15a824`로 같은 포인터와 길이를 전달한다. 자체 queue unlink·완료 확인·
pending B 해제·중복 free 검사는 없다.

이번에 읽거나 기록한 주요 R 필드는 다음과 같다. 전체 구조체 타입을 확정한 표는 아니다.

| offset | 선택 본문에서 확인한 역할 |
|---|---|
| `+0` | 명령 DWORD |
| `+4`, `+8`, `+0xc`, `+0x10` | 87차 block, block count, buffer, client |
| `+0x14` | abort에서 검사하는 별도 포인터; B로 단정하지 않음 |
| `+0x18`, `+0x1c` | pending B 또는 0, 동기 조건 잠금 객체 |
| `+0x20` BYTE | mask 1로 큐 선택 |
| `+0x24`, `+0x28` | 완료 시 읽는 actualLength, status DWORD |
| `+0x2c`, `+0x30` | next/previous 요청 또는 queue sentinel |

## enqueue와 제출 이후 접근

`0x1ad774`는 먼저 R.status=`0xffffffff`(-1), 그 뒤 self `+0x1b8` 객체에 lock을 보낸다.
R.flags&1이면 self `+0x1a8`, 아니면 `+0x1b0` queue를 선택한다.
빈 queue의 sentinel은 자기 주소를 가리키며, 삽입은 R을 tail에 붙이는 순서다.
일반 node의 next/prev는 `+0x2c/+0x30`, sentinel의 head/tail은 `+0/+4`다.
큐가 잠겨 있다는 호출 전제 아래서만 중간 링크 상태를 배타적으로 해석할 수 있다.

삽입 후 queue lock에 unlockWith:(1)을 호출한다. **그 호출 뒤** `0x1ad7ed`에서
R `+0x18`을 다시 읽는다. 비영이면 EAX=0으로 반환하며 이 함수 자체의 추가 실패
반환은 없다. 따라서 이 비동기 enqueue 후보가 정상 반환한 경로에서 87차의
sdstrategy 자체 오류 완료 분기가 곧바로 실행된다고 볼 수 없다.

동기 R이면 R.lock에 lockWhen:(1), unlockWith:(0)을 차례로 보낸 다음
R.status를 읽어서 반환한다. 대기 primitive/IMP의 정상 동작은 별도 조건이다.

중요한 잔여 수명 조건: queue 공개·unlock/통지 이후에도 제출 측이 R을 읽는다.
아래 비동기 완료는 R을 해제할 수 있으므로, worker가 먼저 완료하는 native 순서가
가능한지와 그때 R이 아직 유효한지 확인해야 한다. 원본에 이 후속 읽기가 있다는
사실은 확정했지만, 실제 use-after-free 발생은 아직 입증하지 않았다.

## 완료 전달과 B 기록

`sdIoComplete:(R)` 후보 `0x1ae6f8`:

- pending 비영이면 `completeTransfer:(B) withStatus:(R+0x28) actualLength:(R+0x24)`를
  self에 보내고, 그 호출이 돌아온 뒤 `freeSdBuf:(R)`를 보낸다.
- pending==0이면 R.lock에 unlockWith:(1)을 보내고, 자체 R 해제는 하지 않는다.
  87차의 동기 common caller가 실제 길이를 읽고 해제하는 흐름과 연결된다.

`completeTransfer` 후보 `0x1ac298`은 status 비영이면 먼저 B.flags BYTE에 mask 4를 OR한다.
status==0일 때 기존 flag 4를 지우지는 않는다. 어느 경우든 errnoFromReturn:(status)을
호출하여 low AX를 B `+0x1c` WORD에 저장한다. 이어 B `+0x14` request에서
actualLength를 DWORD로 빼 B `+0x28` residual에 저장하고 `biodone(0x11aad4)`을 호출한다.
actualLength<=request 검사, residual clamp, 자체 중복 완료 guard는 없다.

이에 따라 '호출된 완료 후보 안에서 상태/길이를 기록하고 biodone으로 넘어간다'는
연결은 확인됐다. 반면 '모든 제출 요청이 정확히 한 번 이 후보로 온다'는 아직 미확정이다.
실제 errno override, actualLength writer, biodone 이후 B 수명, doSdBuf의 모든 오류·재시도
경로를 확인해야 한다. JSON의 잔여 길이 wrap·기존 flag 유지·조건부 flag-only 오류 예시는
유한 정수 계산이며 native 발생 사례가 아니다.

## worker 초기화 및 queue 선택

`initResources(0x1acf48)`는 queue sentinel 두 개를 초기화하고 queue lock `+0x1b8`,
추가 조건 lock `+0x1c0`에 alloc/initWith:(0)을 보낸다. setLastReadyState:(1),
count `+0x1c4`=0, BYTE `+0x1c8`=0, BYTE `+0x18a`&=0xfc,
DWORD `+0x18c`=0을 수행한다.

그 뒤 Python으로 계산한 6회 반복에서 IOForkThread(sdIoThread,self)를 호출하고,
반환값을 `+0x190/+0x194/+0x198/+0x19c/+0x1a0/+0x1a4`에 저장한 다음
`+0x18c`를 증가시킨다. 이 값은 성공한 스레드 수로 검증되지 않았다.
SCSIDisk의 이 `+0x18c`를 87차 IOLogicalDisk의 physical-block-size 필드와 혼동하지 않는다.
같은 offset이어도 서로 다른 class의 지역 증거다.

`sdIoThread(0x1adf7c)`는 queue lock에 lockWhen:(1)을 보낸 뒤 `+0x1b0` queue를 먼저
비울 때까지 dequeue(self,0)를 호출한다. 그 뒤 `+0x1a8` queue에 대해 상태를 조회한다.
첫 lastReadyState 호출이 2이거나 **별도 두 번째 호출**이 3이거나 BYTE `+0x1c8`이
비영이면 처리를 멈춘다. 아니면 dequeue(self,1)를 호출하고 반복한다.
두 상태 조회 사이의 값이 같다고 가정하지 않았다.

끝에서 상태를 다시 읽고, queue `+0x1a8`이 남아 있으며
상태 1 + isRemovable의 AL 비영, 또는 상태 2, 또는 BYTE `+0x1c8` 비영이면
unlockIoQLock 호출 뒤 volCheckRequest(self,2)를 호출한다. 다른 경우에도 unlockIoQLock을
호출하고 바깥 루프로 돌아간다. 자체 정상 RET는 없다.

`unlockIoQLock(0x1ae74c)`은 `+0x1b0`이 비어 있지 않거나,
`+0x1a8`이 비어 있지 않고 fresh readyState가 2/3이 아니며 `+0x1c8`==0이면
condition=1로 unlockWith를 보낸다. 아니면 0이다. condition=1이면 그 뒤
thread_block `0x165328`도 호출한다. 단순 unlock으로 축약하면 이 양보 지점이 누락된다.

## dequeue 명령 분기 `0x1ae094`

두 번째 인자는 BYTE로 읽어 queue를 선택한다. 빈 queue면 원본 로그 후 반환한다.
비어 있지 않으면 head R을 먼저 unlink한다. mode 비영이면 추가 lock 아래
`+0x1c4`를 증가시키고, 명령 4일 때 BYTE `+0x1c8`=1 및 volCheckEjecting(self,2)를
수행한 뒤 unlockWith:(현재 count)한다.

원본 `0x1ae160`의 jump table과 unsigned 명령<=7 검사를 직접 대조했다.

| 명령 | 원본 동작 경계 |
|---|---|
| 0–3 | queue lock unlock → doSdBuf:(R) → queue lock lock |
| 4 | queue unlock → 추가 lock의 lockWhen:(1), unlock → doSdBuf → queue lock |
| 5 | `+0x1a8`에 남은 요청을 unlink하며 queue unlock, status=-1102, 완료, queue lock 반복 |
| 6 | 현재 R.status=0, sdIoComplete:(R); 자체 queue unlock 없이 완료 호출 |
| 7 | queue unlock, R.status=0, sdIoComplete, IOExitThread 호출 |
| >7 (unsigned) | 자체 doSdBuf/완료/requeue 없이 후처리로 진행 |

명령 5의 drain은 R `+0x14`가 비NULL이면 그 포인터 `+0x1c`에 **DWORD 0x10**도 쓴다.
이는 B.error WORD store와 다르다. actualLength를 자체에선 새로 쓰지 않는다.
drain 종료 뒤 현재 명령 요청은 6의 처리로 이어진다.
mode 비영일 때 공통 후처리는 추가 lock 아래 count를 감소시키고 unlockWith:(count)한다.
IOExitThread가 실제로 반환하는지는 별도 분석이므로 명령 7의 후처리 도달을 단정하지 않는다.
명령 0/1은 87차 read/write wrapper와 연결되지만 다른 명령 writer와 mode 전제도 필요하다.

## NXConditionLock 후보와 디컴파일 누락

상태 객체 C의 `+4`는 내부 P를 가리킨다. P `+0`은 내부 simple lock,
`+4`는 write lock, `+8`은 condition이다. initWith는 super init 전에 읽은 P를
보존하며, P==0일 때 kalloc(0xc), simple_lock_alloc, lock_alloc을 호출한다.
super 반환을 self로 교체하지 않고, allocation NULL을 자체 검사하지 않는다.
그 뒤 내부 simple lock=0, lock_init(write lock,1), condition=인자를 쓴다.

lock은 lock_write를 호출한다. unlock은 condition 값을 바꾸지 않고
thread_wakeup_prim(P+8,1,0)을 호출한 다음 lock_done 한다.
lockWhen은 write lock을 얻고 condition을 비교한다. 불일치면 내부 simple lock 획득
후 write lock을 놓고 thread_sleep(P+8, simple-lock-pointer, 0), write lock 재획득,
condition 재검사로 이어진다. thread_sleep 내부의 원자적 wait 등록/해제와 wake의 의미는
이번에 전체 입증하지 않았다. 반환 시 자체 write-lock release는 없다.

unlockWith는 내부 simple lock 획득 후 condition을 저장하고 내부 lock을 XCHG로
0으로 만든 다음 thread_wakeup_prim(P+8,1,0), lock_done 순서다.
일반 unlock과 달리 condition store와 내부 simple lock이 있다.

특히 내부 spin의 원본은 다음과 같다.

- lockWhen: LOAD `0x1a8f3c`, TEST `0x1a8f3e`, JNZ **TEST** `0x1a8f40`.
- unlockWith: LOAD `0x1a8f94`, TEST `0x1a8f96`, JNZ **TEST** `0x1a8f98`.

두 JNZ의 원본 바이트는 `75fc`다. 비영 EAX로 이 내부 루프에 들어가면 해당 루프는
메모리를 재읽지 않는다. 따라서 메모리 lock 값이 나중에 0이 되는 것만으로는
이 instruction sequence를 벗어나지 않는다. Ghidra C의 반복 메모리 읽기 표현과 다르다.
이후 XCHG 경쟁 실패 경로에는 LOAD로 돌아가는 별도 분기가 있다.
실제 초기 비영 값의 도달성·SMP/스케줄링·다른 writer는 여전히 미확정이며,
원본 분기 차이를 즉시 native 교착 증명으로 확대하지 않는다.

free는 내부 write lock, simple lock, P를 해제한 뒤 super free를 보낸다.
자체 waiter drain·owner 검사·P 필드 초기화가 없으므로 호출자의 quiescence 근거가 필요하다.

## 판정과 다음 연결

큐 공개→dequeue→완료 후보→B 기록→biodone과 동기/비동기 해제 분기를 지역 수준에서
연결했다. 다만 일반 read/write의 doSdBuf `0x1ad8b0`은 아직 연결의 핵심 미해결 본문이다.
다음에는 그 status/actualLength writer, 장치 호출·복사·재시도·완료 분기를 검토한다.
등록/fixup, 빠른 완료와 enqueue 후속 읽기, 조건 잠금 경쟁·primitive 계약을 함께 유지한다.
이 지역 검토의 파일 검증 통과를 전체 원본 분석 완료로 해석하지 않는다.

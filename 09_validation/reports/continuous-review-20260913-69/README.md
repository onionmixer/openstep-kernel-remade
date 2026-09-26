# 메시지 큐 송수신: 소유권·대기·재개

**송신 성공은 메시지가 receiver에 실제 전달됐다는 보장이 아니다.** 원본은 inactive port와 circular message를 파괴한 뒤 성공을 반환한다. 반면 송신 timeout·interrupted 반환은 kmsg를 파괴하지 않아 caller 책임이 남는다. 수신의 TOO_LARGE는 출력 슬롯에 메시지 포인터가 아니라 필요한 크기를 쓰며, 큐에서 기다리던 메시지를 꺼내지 않는다.

보고서 68의 checkpoint와 파일을 재검증했다. 이전 턴은 right_destroy 의미와 원본 증거를 확정한 실제 진전이다. Ghidra 스킬을 보존 출력의 읽기 전용 대조에 적용하고, 모든 계산은 Python으로 수행했다. 원본·참고 소스·DB·export·기존 확정 보고서·07_kernel은 보존했다. 새 독립 계획 검토·구현·새 실행 검증 프로그램·동적 실행·GCC 2.7 빌드는 수행하지 않았다.

## 증거 범위

[정적 증거](mqueue-evidence.json)에 전체 본문 바이트·VA/file mapping·독립 디코딩·직접 분기/호출·stack operand·필드/옵션/timeout 계산과 입력 해시를 기록했다. [보존 목록](preservation.json)은 기존 확정 자료를 잇는다.

| 함수 | 주소 | instruction heads | 본문 바이트 |
|---|---|---:|---:|
| ipc_mqueue_send | 0x14a764 | 226 | 707 |
| ipc_mqueue_receive | 0x14acd4 | 197 | 595 |
| ipc_thread_enqueue | 0x151be8 | 19 | 55 |
| ipc_thread_rmqueue | 0x151c70 | 22 | 71 |
| ipc_kmsg_enqueue | 0x146f38 | 21 | 43 |
| thread_will_wait | 0x1591f4 | 27 | 62 |
| thread_will_wait_with_timeout | 0x159234 | 48 | 119 |
| exception_raise_continue | 0x15746c | 27 | 68 |

Python 집계는 8개 본문, instruction heads 587개, 1720바이트, 직접 분기 88개, 호출 28개다. receive의 unknown ith_state panic에 대한 non-return WARNING 1개를 보존했다. 이것은 전체 caller·스케줄러·timer·kobject 처리의 전이적 검증이 아니다.

## 송신의 진입과 즉시 소비 경로

ABI는 `(kmsg, option, timeout, continuation)`이다. kmsg+0x1c의 destination port를 읽고 lock한다. 참고 소스는 유효한 destination right와 caller가 보유한 kmsg를 전제로 한다. 원본에는 NULL/-1 destination 검사나 전체 header 검증이 없다.

일반 active 검사보다 먼저 port+0xc와 ipc_space_kernel(0x1f624c의 값)을 비교한다. 일치하면 port unlock → kobject_server(kmsg) → reply가 있으면 send(reply,0x10000,0,0) → 성공 반환이다. 이 순서를 정당화하는 참고 소스의 조건은 kernel port 제거 전에 receiver 필드를 비운다는 것이다. 그 모든 생산자·제거 경로를 이번에 검증한 것은 아니며, kobject_server가 메시지를 정확히 어떻게 소비하는지도 별도 범위다.

일반 경로에서 port가 inactive이면 refs를 감소시키고 unlock한다. 감소 결과가 0이면 type zone으로 zfree하며 zone type은 unlock 뒤 읽는다. 이어 0x14a7f1에서 kmsg.remote_port=0, 0x14a7f9에서 kmsg_destroy, 성공 반환이다. destination right를 일반 cleanup으로 다시 처리하지 않도록 먼저 끊는 구조로, send-once 알림이 죽은 destination에 재귀 전달되는 문제를 피하려는 참고 설명과 대응한다.

활성 port에서 다음 중 하나면 queue-limit 대기를 건너뛴다: unsigned msgcount(+0x38) < qlimit(+0x3c), SEND_ALWAYS(0x10000), header remote type byte==0x12(SEND_ONCE). 그 뒤 CIRCULAR(0x40000000)를 검사한다. circular이면 port unlock 후 kmsg_destroy로 소비하고 성공을 반환한다. 이 분기는 dead-port와 달리 remote field를 먼저 0으로 만들지 않는다.

중요하게도 circular 검사는 queue-limit 대기 **뒤**에 있다. 가득 찬 일반 send-right 메시지가 circular이라고 해서 항상 기다리지 않고 즉시 파괴되는 것은 아니다.

## 송신 대기와 timeout 재검사

대기가 필요할 때만 global 0x1e8b54에서 current-thread pointer를 읽어 ESI에 보관한다. SEND_TIMEOUT(0x10)이 있고 timeout==0이면 port unlock 후 0x10000004를 반환한다. timeout이 비영이면 thread_will_wait_with_timeout, 옵션이 없으면 thread_will_wait를 호출한다.

port+0x4c의 blocked sender queue에 thread를 넣고 thread+0x98=0x10000001(IN_PROGRESS), port unlock, thread_block_with_continuation(0)을 호출한다. 송신에서 전달된 continuation 인자를 이 대기 호출에 사용하지 않는다. 반환 후 port를 다시 lock한다.

ith_state==0이면 sender는 IPC 경로에서 이미 queue에서 제거된 것으로 취급하고 일반 active/limit 검사로 돌아간다. 여기서 중복 rmqueue를 하지 않는다. 그 외 ith_state이면 원본은 IN_PROGRESS와의 일치 assert 없이 rmqueue한 뒤 thread+0x44(wait_result)를 본다.

| wait_result | 원본의 처리 |
|---|---|
| 1(TIMED_OUT) | timeout 인자를 0으로 바꾸고 일반 active/limit 검사 재시도 |
| 2, 3(INTERRUPTED, SHOULD_TERMINATE) | port unlock, 0x10000007 반환 |
| signed 값이 1 미만 또는 3 초과 | 일반 active/limit 검사 재시도 |

따라서 timeout으로 깨어나도 그 사이 port가 죽었다면 메시지를 소비하고 성공할 수 있으며, capacity가 생겼다면 정상 진행할 수 있다. 다시 막혀 있고 timeout 옵션이 유지된 경우에 timeout==0 반환으로 간다. timeout event 자체가 결과를 무조건 결정하지 않는다.

읽은 Darwin 소스는 THREAD_RESTART/default에서 panic하지만 원본 0x14a8b2/0x14a8bb는 재시도한다. 이 차이를 참고 소스의 switch로 덮어쓰면 안 된다. 비정상 ith_state나 stale wait_result가 실제로 도달 가능한지, 반복 대기의 진행성이 보장되는지는 scheduler/모든 caller 검증이 남는다.

## Queue 수락과 receiver 전달

메시지가 수락되면 port.msgcount를 먼저 증가시킨다. pset(+0x30)이 없으면 port+0x40 queue, 있으면 pset+0x10 queue를 선택한다. **message queue lock을 얻은 뒤** port lock을 푼다. port/pset 생존과 membership은 메시지 reference 및 caller/pset 이동 경로의 계약에 의존한다.

receiver queue가 비면 kmsg를 message ring tail에 넣고 queue unlock 후 성공을 반환한다. receiver가 있으면 먼저 ring에서 제거하고 max_size와 메시지 size(kmsg+0x18)를 unsigned 비교한다.

작은 receiver에는 ith_state=0x10004004, thread+0x9c=필요한 size를 저장하고 queue lock을 유지한 채 thread_go를 호출한다. 메시지는 이 receiver에 주지 않고 다음 receiver를 검사한다. 모두 작거나 receiver가 없으면 메시지는 큐에 들어간다.

맞는 receiver에는 ith_state=0, thread+0x9c=kmsg, thread+0xa0=기존 port.seqno를 저장하고 port.seqno(+0x34)를 증가시킨다. 이 seqno 처리는 port lock이 아니라 message queue lock 아래에 있다. queue unlock 후 SEND_SWITCH bit(원본 0x20000)가 있으면 thread_go_and_switch(continuation,receiver), 없으면 thread_go(receiver)를 호출한다.

직접 receiver 전달에서도 msgcount는 송신 함수에서 감소하지 않는다. 수신 완료 경로에서 감소한다. TOO_LARGE receiver에는 seqno를 할당하지 않으며, kmsg를 ring에 넣는 시점에도 seqno를 할당하지 않는다. 메시지의 성공 소비와 실제 thread context switch는 서로 다른 판정이다.

## 수신 ABI·queue lock·출력 의미

원본 ABI는 `(queue, option, max_size, timeout, resume, continuation, kmsgp, seqnop)`의 8개 인자다. 직접 EBP stack operand와 exception_raise_continue의 PUSH/ADD ESP,0x20을 대조했다. Darwin에는 추가 list 인자가 있으므로 후대 선언을 그대로 사용할 수 없다.

resume==0의 일반 진입은 queue가 이미 locked라고 전제하며, 본문에서 처음 lock을 얻지 않는다. resume 비영이면 0x14adec로 바로 가서 queue를 **다시 lock**한다. 따라서 resume caller는 이전 block 때 풀린 queue lock과 저장된 thread IPC 상태를 사용해야 한다. 일반 진입의 locked 조건을 resume에도 무조건 적용하면 잘못된다. 두 경로 모두 정상 반환 시 queue lock을 소비한다. caller는 queue가 속한 port/pset reference를 유지해야 한다.

exception_raise_continue는 current thread+0xc4의 port에서 queue+0x40을 계산하고 option=0, max_size=0xffffffff, timeout=0, resume=1, continuation=self, local kmsg/seqno output을 전달한다. 반환값과 output을 continue_slow로 넘긴다. 이 caller에는 queue를 미리 lock하는 명령이 없다. exception 전체 전달·오류 output 사용 규칙은 continue_slow까지 검토하지 않았으므로 미완료다.

| 저장소 | 대기 중 | TOO_LARGE | 성공 |
|---|---|---|---|
| thread+0x98 | RCV_IN_PROGRESS | RCV_TOO_LARGE | 0 |
| thread+0x9c | 수용 가능한 max_size | 필요한 message size | kmsg pointer |
| thread+0xa0 | 이번 대기의 유효값 보장 없음 | 이번 실패에서 쓰지 않음 | 전달된 seqno |
| *kmsgp | 함수가 아직 쓰지 않음 | 필요한 size DWORD | kmsg pointer |

seqnop은 성공 경로에서만 쓴다. timeout/interrupted/port_changed/port_died 경로는 kmsgp와 seqnop을 일괄 0으로 초기화하지 않는다. 반환 상태를 먼저 보지 않고 output을 pointer로 사용하는 것은 잘못된 caller 계약이다.

## 이미 큐에 있는 메시지와 수신 대기

일반 진입은 queue+4의 첫 kmsg를 본다. size가 max_size보다 크면 *kmsgp=size, queue unlock, TOO_LARGE 반환이다. 이때 메시지를 dequeue하거나 msgcount·seqno를 변경하지 않는다. 충분하면 message ring에서 제거하고 destination port의 기존 seqno를 저장한 뒤 증가시킨다. 제거한 kmsg의 next/prev를 self로 재설정하지 않는다.

큐가 비었으면 RCV_TIMEOUT(0x100)과 timeout==0을 확인해 0x10004003을 반환하거나 대기를 준비한다. thread를 queue+8 receiver ring에 넣고 ith_state=0x10004001, ith_msize=max_size를 저장한 뒤 queue unlock한다. continuation 인자가 있으면 그대로 block 호출에 전달하고 없으면 0을 전달한다.

block에서 돌아오거나 resume 진입하면 queue lock 아래 ith_state를 검사한다.

- 0이면 sender가 thread+0x9c/+0xa0에 전달한 kmsg/seqno를 사용한다. 메시지를 다시 queue에서 dequeue하지 않는다.
- TOO_LARGE이면 thread+0x9c의 size를 *kmsgp에 쓰고 unlock 후 상태를 반환한다.
- PORT_CHANGED(0x10004006), PORT_DIED(0x10004009)이면 queue unlock 후 상태를 반환한다. 이때 rmqueue하지 않는 것은 변경/파괴 producer가 이미 receiver를 제거하는 계약과 연결된다.
- IN_PROGRESS이면 스스로 rmqueue하고 wait_result를 판정한다. 1이면 timeout=0으로 바꾸고 queue 검사를 재시도하고, 2/3이면 unlock 후 0x10004005, 나머지는 재시도다. 송신과 마찬가지로 이 wait-result default는 원본에서 panic하지 않는다.
- 다른 ith_state는 0x14aea9의 panic으로 간다. **ith_state 분기의 panic과 wait_result default 재시도를 혼동하면 안 된다.**

timeout 재검사에서는 먼저 큐의 메시지를 검사하므로, 그 사이 메시지가 들어왔으면 timeout 이벤트 뒤에도 메시지를 받을 수 있다. native 동시 event 우선순위 전체가 검증되었다는 뜻은 아니다.

## 수신 성공 마무리와 sender 한 명 깨우기

kmsg가 확보되면 queue unlock(0x14aeba) 후 marequest가 있을 때 destroy(0x14aec7), kmsg+0xc=0(0x14aecc)을 수행한다. 일반 kmsg_clean과 달리 이 경로는 request 슬롯을 비운다. 그 뒤 destination port lock을 얻는다.

port가 active일 때만 msgcount를 감소시키고, blocked sender가 있으며 감소한 msgcount < qlimit이면 첫 sender 하나를 제거한다. 해당 thread의 ith_state=0을 저장하고 port lock을 유지한 채 thread_go를 호출한다. 모든 sender를 한꺼번에 깨우지 않는다. port가 inactive이면 msgcount 감소와 sender wake를 생략한다.

port unlock 후 *kmsgp와 *seqnop를 쓰고 0을 반환한다. kmsg 버퍼나 destination reference를 여기서 소비하지 않으며 이후 copyout/cleanup caller로 메시지 ownership이 넘어간다. native 생존성은 메시지 reference와 관련 caller 조건을 필요로 한다. 이 본문이 header의 circular bit를 직접 clear하는 것은 아니다. send가 circular 메시지를 수신 queue로 보내지 않는 선행 경로와 연결된다.

## Queue helper의 서로 다른 초기화 조건

ipc_thread_enqueue는 빈 queue에 head=thread만 저장하고 thread.next/prev를 self로 초기화하지 않는다. 참고 macro는 이미 self-linked라는 assert를 요구한다. 다중 원소면 tail에 연결한다. receive에 펼쳐진 enqueue 코드도 같다.

ipc_thread_rmqueue는 thread.next가 자기 자신이면 queue head=0으로 한다. 이 경우 head==thread인지 원본에서 검사하지 않는다. 다중 원소에서는 필요하면 head를 다음 원소로 바꾸고 이웃을 연결한 뒤 제거된 thread의 next/prev를 self로 만든다. membership/nonnull 검사·자체 lock·reference release는 없다. 반복 rmqueue의 무해성을 가정할 수 없다.

ipc_kmsg_enqueue는 이와 달리 빈 queue에 head를 넣을 때 kmsg.next/prev를 모두 self로 초기화한다. queue helper들 자체가 메시지 권한을 복제하거나 해제하는 것은 아니다.

## 대기 준비와 timeout 수식

thread_will_wait는 splsched → thread lock(+0x20) → state(+0x4c)의 WAIT bit OR 1 → unlock → splx다. wait_result(+0x44)를 -1로 쓰지 않는다. 참고 소스의 `assert(thread->wait_result = -1)`에 있는 부작용을 assert가 없는 원본에 추가하면 달라진다.

with_timeout은 먼저 global hz(0x1dee30의 값)를 사용해 ticks를 계산한다. 원본은 IMUL 하위 DWORD, ADD 999, EDX=0, unsigned DIV 1000이므로 `(((msecs * hz) mod 2^32 + 999) mod 2^32) // 1000`이다. 그 뒤 thread lock과 WAIT 설정을 수행하고 ticks!=0 또는 msecs==0일 때만 set_timeout(thread+0x118,ticks)를 호출한다. msecs 비영·ticks==0이면 timer를 설정하지 않는다. overflow가 없는 영역의 올림 설명을 전체 DWORD 입력에 대한 안전성 보장으로 확대할 수 없다.

조건부 hz=100 예시에서 msecs 0/1/10/11의 ticks는 각각 0/1/1/2다. 이는 Python 수식 계산이며 runtime hz 측정이나 timer 실행 시험이 아니다. set_timeout·timeout callback·interrupt level과 실제 scheduling은 후속 범위다.

## 참고 소스 차이와 남은 범위

보존 OPENSTEP mach/message.h의 SEND_SWITCH=0x20000이 원본 byte test와 맞는다. Darwin은 0x80000이다. Darwin의 scatter/list/trailer 및 OLD_FORMAT 추가 분기, header-error 전달 경로는 이번 원본 send/receive에 존재하지 않는다. 원본 receive는 성공 시 항상 0을 반환하며 후대의 복합 mr 전달 구조를 그대로 사용하지 않는다.

register-only busy loop는 load 주소 0x14a774, 0x14a87c, 0x14a928, 0x14adec, 0x14aed8, 0x159208, 0x159264에서 확인했다. 각각 JNZ 75fc가 memory load가 아닌 register TEST로 돌아간다. Ghidra memory-reload while를 원본과 동일시하지 않는다.

이번 결과는 큐 송수신과 대기 준비·재개의 정적 계약을 연결한 것이다. [보고서 66](../continuous-review-20260912-66/README.md)의 port/receiver 파괴·thread_go, [보고서 67](../continuous-review-20260913-67/README.md)의 kmsg cleanup 및 [남은 작업](OPEN_ITEMS.md)의 scheduler/timer/caller reference 분석을 계속 연결해야 한다. 전체 원본 의미·GCC 2.7 구현·boot 검증 완료로 판정하지 않는다.

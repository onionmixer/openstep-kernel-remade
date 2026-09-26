# 103차: run queue와 실제 stack/context 전환

OPENSTEP x86 원본과 그 추출 자료만 사용했다. 일반 본문 23개와 panic fallthrough
fragment 5개에서 명령 1,719개/5,446바이트를 원본 재디코드했다.
102차의 선택·swapin 재시도·continuation 연결을 구체화했지만 전체 scheduler,
동시성, 스택 할당기와 CPU descriptor 계약은 아직 미완료다. 계산은 모두 Python이다.

## 같은 offset의 다른 객체를 구분

| 객체 | 이번에 확인한 필드 |
| --- | --- |
| thread T | +8 runq 포인터, +0x58 priority, +0x184 binding 값, +0x28 PCB, +0x2c 현재 stack, +0x30 reserve stack |
| runq 공통 prefix Q | +0x100 lock, +0x104 hint, +0x108 count, 앞부분의 priority별 목록 head |
| processor R | +0x114 state, +0x118 pending thread, +0x11c idle thread, +0x120 quantum, +0x124 관련 표식, +0x12c pset |
| pset G | +0x10c/+0x110 idle 목록, +0x114 idle count, +0x118 idle lock |

R+0x118의 pending thread와 G+0x118의 lock을 혼동하지 않는다.
Q를 모든 경로에서 같은 구체 타입이라고 단정하지 않는다. 원본은 default pset과
processor 자체의 runq prefix를 서로 다른 분기에서 사용한다.

## 선택과 자기 자신 재선택의 조건

`thread_select` 0x163498은 R+0x124=1을 기록한다.
R의 local count가 signed 양수이면 choose_thread를 호출하고 min_quantum을 설정한다.
이 호출 내부에서 local count가 다시 검사되며 pset 선택으로 넘어갈 수 있어,
바깥의 최초 count 검사만으로 반환 thread의 출처를 확정하지 않는다.

나머지 경로는 literal default pset 0x1e9610을 잠근다.
default count가 0이고 현재 T의 상태가 정확히 4이며,
T+0x184가 0 또는 R과 같을 때만 현재 thread를 그대로 선택하는 조기 경로다.
필요하면 thread 잠금 아래 update_priority를 호출한다.
102차의 종료 상태가 유지된다면 이 정확한 state=4 gate는 통과하지 않는다.
하지만 queue에서 꺼내는 다른 경로에는 동일한 state/active 재검사가 없으므로,
이 사실만으로 종료한 thread의 모든 재선택을 배제하지 않는다.

default queue 선택은 hint의 목록 head에서 thread를 제거하고 T+8을 0으로 만든다.
원본 0x163589의 count 기록은 0x1635b3의 unlock보다 앞선다.
C는 `DAT_001e9718` 감소를 unlock 뒤에 표시하므로 동시성 검토에 그 순서를 사용하지 않는다.
일반 선택 경로의 quantum은 policy 필드가 2이면 T+0x5c, 아니면 pset+0x16c에서 가져온다.

`choose_thread` 0x1643c0은 local runq를 잠그고 양수 count를 재검사한다.
hint에서 낮은 index 방향으로 nonempty 목록을 찾고 head를 제거한다.
T+8=0, count 감소, hint 기록 후 잠금을 풀고 포인터를 EAX로 반환한다.
local count가 양수가 아니면 R+0x12c pset의 runq lock을 얻어 choose_pset_thread로 넘긴다.

`choose_pset_thread` 0x16448c는 전달된 runq lock을 자체 시작에서 다시 얻지 않는다.
선택한 두 caller가 먼저 잠근 상태로 호출하며 이 함수가 해제한다.
count가 양수인데 hint 아래의 모든 목록이 비어 음수 index에 도달하면 panic한다.
제거 후 남은 count와 pset flag에 따른 추가 hint 하향 탐색에는 자체 하한 검사가 없어,
count/list 일치와 hint 범위를 별도로 증명해야 한다.

세 dequeue 블록에 보이는 ‘sentinel이면 NULL로 바꿈’ 분기는 직전의 같은 두 레지스터
비교에서 이미 non-equal 조건이 확정된 뒤에 나온다. 사이에 해당 레지스터를 바꾸지 않으므로
그 지역 경로를 실제 NULL 반환으로 세지 않는다. 손상된 목록의 NULL node까지 배제한 것은 아니다.

## enqueue와 priority 갱신

`run_queue_enqueue` 0x163f84는 T+0x58의 DWORD를 unsigned로 비교해,
31보다 크면 진단 출력을 호출하고 지역 index만 31로 바꾼다.
32개 bucket의 stride는 8, 전체 head 구간은 256바이트다.
T+0x58 자체를 정규화하는 쓰기는 없다. 음수처럼 보이는 DWORD도 이 unsigned gate에 걸린다.

runq lock 아래 tail에 T+0/+4를 연결하고, hint를 갱신하고, count를 증가시키고,
T+8에 runq를 기록한 뒤 잠금을 푼다. 자체 본문은 기존 queue 소속, 중복 등록,
active/state 또는 모든 caller의 thread lock/IRQ 조건을 검사하지 않는다.

`thread_setrun` 0x16400c은 필요하면 update_priority를 호출한다.
default idle count가 양수이면 idle processor를 목록에서 제거하고 R+0x118=T,
R+0x114=3을 기록한다. 이 직접 전달 경로는 뒤의 T+0x184 검사보다 먼저다.
이 경로에는 자체 runq count 증가나 T+8 runq 게시가 없다.

idle 직접 전달을 하지 않으면 T+0x184가 0인 경우 default pset,
비영인 경우 global master processor를 runq로 택하고 AST bit 2를 설정한다.
T+0x184에 들어 있는 포인터 자체를 runq로 그대로 사용하는 코드가 아니다.
두 번째 인자가 비영이고 새 T의 저장 priority가 현재 thread보다 signed 비교로 높으면
R+0x124를 0으로 만들고 AST를 요청한다. 이 비교는 보정한 bucket index가 아닌 저장 priority다.

`set_pri` 0x164164는 rem_runq 후 새 인자를 T+0x58에 기록한다.
rem_runq가 0이면 자체 재등록 없이 끝난다. 비영이면 세 번째 인자가 0일 때 기존 runq에,
비영일 때 setrun과 같은 선택 경로로 재등록한다. 여기서도 bucket 보정은 지역 값이다.
update_priority의 계산과 전체 priority writer/입력 범위는 이번에 닫지 않았다.

`rem_runq` 0x164350은 T+8을 먼저 읽고 해당 runq를 잠근 뒤 T+8이 여전히 같은지 확인한다.
같으면 목록 제거/count 감소/T+8=0 후 원래 runq를 EAX로 반환하고,
달라졌거나 처음부터 0이면 EAX=0이다. 한 번의 오래된 포인터 읽기로 제거를 확정하지 않는다.

## idle processor의 등록과 pending 소비

choose_pset_thread가 실행할 thread를 찾지 못하면 runq lock을 풀고 pset idle lock을 얻는다.
R state가 1일 때 2로 바꾸고 idle 목록에 연결하며 count를 증가시킨다.
master processor 여부에 따라 목록의 다른 끝에 삽입한다. 이후 R+0x11c idle thread를 반환한다.

`idle_thread_continue` 0x164624는 pending thread, default count, local count를 감시한다.
processor state 3이면 pending을 가져와 0으로 지우고 state를 1로 바꾼 뒤 invoke한다.
invoke가 0을 반환하면 새로 선택한다. state 2이면 idle lock 아래 재검사하여 목록에서
자신을 제거하고 state 1로 바꾼 뒤 선택한다. state 4/5 경로는 pending이 있으면
다른 idle processor 또는 queue로 다시 보내고 block/선택으로 이어진다. 다른 state에는 panic 경로가 있다.

이 경로와 setrun의 직접 전달을 연결했으나 모든 processor-state writer,
PMSetCpuState, IRQ/spl, 목록 동시성 및 유한 대기를 증명한 것은 아니다.

## 스택 확보·반환과 swapin

`stack_alloc_try` 0x15b398은 cache lock을 얻고 cache count가 비영이면 head를 제거한다.
header+8에 2를 기록하고 header+12를 stack으로 사용한다.
cache에서 얻지 못하면 T+0x30 reserve stack을 쓴다. 둘 다 없으면 0,
있으면 stack_attach를 호출하고 1을 반환한다. 자체 새 backing allocation은 없다.

여기의 count 비영/head sentinel 불일치는 dequeue의 중복 비교 분기와 다르다.
count와 목록이 모순되면 자체 NULL 기반 기록 경로가 남아 있지만,
실제 allocator 상태가 그 조건에 도달하는지는 미확인이다. 장애를 재현했다고 하지 않는다.

`stack_alloc` 0x15b43c는 allocStack을 호출하고 NULL이면 panic하며,
성공하면 stack_attach를 호출한다. allocStack/freeStack의 전체 backing 계약은 미완료다.
`stack_detach` 0x18d238은 T+0x2c를 0으로 만들고 기존 포인터를 EAX로 반환한다.
`stack_free` 0x15b470은 그 값이 T+0x30 reserve와 다를 때만 freeStack을 호출한다.
reserve와 같은 stack은 이 함수 자체에서 반환하지 않는다.

`thread_swapin` 0x168efc는 상태 & 0x300이 0x100이면 이를 0x200으로 바꾸고 queue에 연결한다.
이미 0x200이면 자체 중복 enqueue 없이 반환하고, 다른 값은 panic한다.
이 함수 자체가 thread lock을 새로 얻는 것은 아니므로 caller의 상태 직렬화 전제가 남는다.

`swapin_thread_continue` 0x168ff4는 queue에서 꺼내 잠금을 풀고
stack_alloc(T,0x1639ec)를 호출한다. 그 후 thread lock을 얻어 상태 bit 8/9를 지운다.
이전 상태의 bit 2가 있으면 setrun(T,1)을 호출한다. queue가 비면 assert_wait와 block으로 돌아간다.
stack 공급 요청과 실제 실행 가능 게시를 같은 시점으로 보지 않는다.

## stack attach와 handoff

`stack_attach` 0x18d208은 T+0x2c에 stack을 저장한다.
P=[T+0x28], B=[P]인 저장 영역에 EBP/ESP 필드 +0x3c/+0x38을 stack+0xff4로,
EIP 필드 +0x20을 0x186f74로, EBX 필드 +0x34를 continuation으로 초기화한다.
0xff4는 4,084바이트다. 이것만으로 backing allocation 전체 크기·정렬·초기값을 확정하지 않는다.

`stack_handoff` 0x18d250은 old T+0x2c를 0으로 만들고 그 포인터를 new T+0x2c로 옮긴다.
새 저장 영역의 EBP/ESP와 trampoline을 설정하되 EBX 필드는 0으로 기록한다.
그러나 해당 invoke 경로는 즉시 그 0을 CALL하는 것이 아니라 별도의 T+0x34 continuation으로
이동하므로, 이 초기값만으로 NULL 호출 장애를 선언하지 않는다.

handoff는 active_threads를 new T로 바꾸지만 active_stacks와 stack_pointers를
직접 literal 주소에 다시 쓰지 않는다. 같은 활성 stack을 넘긴다는 기존 global 일치 전제가 필요하다.
일반 `switch_context` 0x18d37c는 이 세 global을 모두 게시하고 stack_pointers를 new stack+0xff4로 만든다.

두 함수는 task가 달라질 때 각 task map의 pmap+0x18을 0/1로 기록한다.
새 B+0x1c와 이전 B+0x1c가 다르면 CR3에 쓴다. C에서는 이 CR3 비교·쓰기가 누락된다.
LDT base/size가 다르면 descriptor를 갱신하고 memory WORD selector로 LLDT한다.
TSS descriptor는 새 B에 0xc0000000을 더한 base와 P+4 크기의 감소값으로 갱신하고 LTR한다.
그 뒤 CR0 bit 3을 설정하는 실제 쓰기도 C에서 누락되거나 반환식처럼 보인다.

selector의 파일 WORD는 0x18/0x20이지만 원본은 메모리에서 읽는다.
runtime writer, descriptor 유효성, GDTR, TLB/FP/IRQ 및 CPU의 실제 소비는 별도 미완료다.
descriptor의 상위 flags 일부 보존과 20-bit limit 절단, size 0의 감소 wrap을
Python으로 기록했으나 실제 잘못된 descriptor 도달을 입증하지는 않았다.

## switch helper의 세 번째 인자와 복귀 문맥

`switch_context`는 old T+0x34에 continuation을 기록한다.
continuation이 비영이면 old-save 포인터 0, 아니면 old B를 전달한다.
두 경우 모두 new B와 이번에 나가는 thread 포인터를 추가로 PUSH하여
`__switch_tss` 0x186f20을 호출한다.

helper 진입 시 물리적 스택 인자는 +4 old-save, +8 new-restore, +12 outgoing-thread 값이다.
old-save가 비영이면 EDI/ESI/EBX/EBP를 저장하고 return address를 POP하여 EIP 필드에,
POP 후 ESP를 저장 ESP 필드에 기록한다. old-save가 0이면 이 저장을 생략하지만 POP은 수행한다.

두 경로 모두 새 저장 영역의 레지스터를 복원하고, POP 후 ESP+8에서 outgoing-thread 값을
EAX로 읽고, 새 ESP로 바꾼 뒤 저장 EIP로 JMP한다. helper 자체에는 RET가 없다.
C의 두 인자 선언은 세 번째 값과 실제 ESP 변경·레지스터 복원을 온전히 표현하지 못한다.

따라서 나중에 재개되는 switch_context의 EAX는 단순히 자기 호출의 고정 반환값이 아니라,
그 재개를 발생시킨 전환의 outgoing-thread 값으로 이어진다. 선택한 invoke는 이를 dispatch에 넘긴다.
이 연결은 원본 stack slot·register 이동에 근거하며 전체 모든 continuation 계약의 증명은 아니다.

새 stack trampoline `__stack_attach` 0x186f74는 EAX를 PUSH하고 복원된 EBX를 CALL한다.
호출이 돌아오면 원본 HLT loop에 들어간다. C의 단순 무한 loop는 HLT를 표현하지 않는다.
`thread_continue` 0x1639ec는 비영 인자를 dispatch에 넘기고 spl0 후 active T+0x34의 continuation을 호출한다.
이는 102차의 stack 교체 JMP helper와 함께 새 stack 최초 진입의 인자 전달을 연결한다.

## 검증 범위

직접 분기 236개, 직접 CALL 75개, 간접 전이 6개, 핵심 명령 211개를 대조했다.
invoke의 원본 wakeup table 15항목도 검증했다. Ghidra 스킬의 본문·호출·제어 흐름
대조 절차를 기존 export/raw 비교에 적용했으며 live DB를 수정하지 않았다.

ASM 5,253개를 manifest와 대조한 지정 조사에서 직접 호출 22개와 literal write 8개를 확인했다.
선택 본문 밖의 초기 context-load writer와 scheduler count write는 edge/write만 확인했으며
그 함수 전체 분석으로 세지 않는다. 전체 alias/bulk writer 조사도 아니다.
register-only spin 21개와 C warning 24행은 실제 deadlock 또는 독립 결함 개수가 아니다.
새 독립 Codex 계획 검토를 받지 않았고 구현 코드는 작성하지 않았다.

[범위](SCOPE.md) · [디컴파일 주의점](DECOMPILER_ISSUES.md) · [남은 분석](OPEN_ITEMS.md)
· [원본 증거](object-lifetime-evidence.json) · [보존 해시](preservation.json) · [검증](checkpoint.json)

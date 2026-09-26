# 102차: halt 완료 조건, AST 소비와 scheduler의 정지 전환

OPENSTEP x86 원본과 그 추출 자료만 사용했다. 다른 프로젝트 소스와 복원 코드는
참고하지 않았다. 101차에서 남긴 thread_halt, 자기 자신 종료, IPC 정리와 reaper 사이를
연결했으나 전체 scheduler·IRQ·참조 수명과 실제 실행의 종료 완료는 아직 미확정이다.

일반 본문 25개와 panic fallthrough fragment 9개의 명령 2,266개/6,625바이트를
원본에서 재디코드했다. 직접 분기 359개, 직접 CALL 151개, 간접 전이 6개,
원본 분기 표 5개/73항목을 대조했다. 모든 주소·크기·비트·해시 계산은 Python이다.

## 원본 상태 필드의 구분

T는 thread다. T+0x24는 참조 수, T+0x40은 hold 수, T+0x44는 대기 결과,
T+0x48은 정지 대기자 관련 값, T+0x4c는 상태, T+0x17c는 thread AST 요청이다.
T+0/+4 링크는 wait/run/reaper 목록에서 재사용되므로 목록별 사용 시점을 구분한다.
아래 ‘정지 표식’은 T+0x4c의 0x10 비트를 뜻한다. 이 표식 하나를 CPU/IRQ/메모리 수명의
전역적인 안전성 증명으로 취급하지 않는다.

## 다른 thread를 halt하는 경로

`thread_halt` 0x167494는 대상이 현재 active thread이면 panic한다.
두 번째 인자 must_halt가 0이면 현재 thread와 대상을 주소 순서로 잠근다.
대상이 이미 정지 표식을 가지면 hold 수를 증가시키고 0을 반환한다.
그렇지 않고 현재 thread에 halt 요청 bit 0이 있으면 현재 thread의 +0x48을 깨우고
5를 반환한다. 이 조기 실패에는 대상 hold 증가가 없다.

must_halt가 0이 아니면 현재 thread의 위 검사를 건너뛰고 대상만 잠근다.
일반 경로는 0x1675ec에서 hold를 증가시키고 상태 bit 1을 설정한다.
다른 halt 처리가 이미 진행 중이면 T+0x48=1을 기록하고
`thread_sleep(T+0x48,T+0x20,1)`을 호출한다. 깨어난 뒤 정지 표식을 먼저 검사하고,
must_halt=0일 때만 현재 thread의 비영 대기 결과에 따른 실패·thread_release 경로를 탄다.
must_halt=1도 sleep의 세 번째 인자는 1이다. ‘강제’라는 이름으로 sleep 종류를 바꾸지 않는다.

이후 T+0x17c의 bit 0을 설정하고 잠금을 풀어
`thread_dowait` 0x1679ec를 호출한다. 비영 결과면 halt 요청 bit를 지우고 대기자를 깨우고
thread_release로 hold를 되돌린 뒤 해당 결과를 반환한다.

thread_dowait는 현재 thread 대상에 panic한다. low nibble 6이면 rem_runq를 시도하고,
성공 시 상태 bit 2를 지우며 T+0x48을 가져와 0으로 만든다.
low nibble 7/0xb/0xe/0xf 및 rem_runq 실패 경로는 sleep과 재검사를 수행한다.
must_halt=1은 이 함수의 자체 결과 변수에 5를 쓰는 분기를 피하므로 정상 반환 시 자체 결과는
0이다. 이것은 기다림의 유한성, 하위 호출 반환, 대상의 실제 정지를 별도로 증명하지 않는다.

dowait가 0을 반환한 뒤에도 halt 완료 처리는 남아 있다.
`clear_wait(T,2,1)` 0x16303c를 호출하지만 이 함수는 상태 bit 3이 설정되어 있으면
자체 정리를 건너뛴다. wait event가 있으면 thread 잠금을 풀고 bucket 잠금을 얻은 뒤,
thread를 다시 잠가 event가 같은지 확인한 후에만 목록에서 제거한다.
모든 wait를 무조건 취소하는 함수로 해석하지 않는다.

다음 continuation은 대상 thread를 직접 다시 실행하지 않고 정지 표식을 설정할 수 있다.

- T+0x34가 0x18dec0 또는 0x18dce0인 경로.
- T+0x34가 0x153f34 또는 0x152904이고 mach_msg_interrupt가 비영을 반환한 경로.

이 경로는 0x16773c에서 상태 0x10을 OR하고 0x167740에서 halt 요청 bit 0을 지운다.
다른 continuation이면 상태 low nibble이 정확히 2인지 검사하고, 아니면 panic한다.
2인 경로는 0x167790에서 0xc를 OR하고 `thread_setrun(T,0)` 후 dowait로 돌아간다.
따라서 halt의 성공을 dowait의 성공 하나와 동일시할 수 없다.

`mach_msg_interrupt` 0x154064는 T+0xdc 객체를 잠그고 T+0x98이 0x10004001인지 검사한다.
일치하면 IPC queue 제거와 객체 release, syscall 반환값 0x10004005 설정을 호출하고
T+0x34를 0x18dec0으로 바꾸며 EAX=1을 반환한다. 불일치하면 EAX=0이다.
하위 IPC 함수의 모든 참조·오류 계약은 이번 범위에 포함하지 않는다.

## 자기 자신 종료와 reaper 등록

`thread_halt_self_with_continuation` 0x1677c4와 `thread_halt_self` 0x1678b4는
현재 T+0x17c의 bit 1을 기준으로 분기한다.

종료 bit가 있으면 IPC thread 정리 → thread_hold → reaper queue 등록 → 상태 0x10 설정
→ reaper 깨우기 → walking_zombie continuation으로 block 순서다.
queue 등록은 T+0/+4를 사용하고 reaper 잠금 아래 수행한다.
이 경로 자체에는 T+0x24 참조 수 감소/임시 1 설정이나 PCB 해제가 없다.
101차 interrupt deallocate의 임시 참조 설정과 혼동하지 않는다.

종료 bit가 없는 halt는 상태 0x10을 설정하고 T+0x17c의 bit 0을 지운 뒤 block한다.
with_continuation 변형은 전달받은 인자를, 일반 변형은 0x18dec0을 continuation으로 쓴다.
이 분기에는 reaper 등록이 없다.

종료 시 지정하는 `walking_zombie` 0x1677b0의 선택 본문은 panic 호출이다.
이는 종료한 thread가 정상 continuation으로 복귀하도록 설계된 경로가 아니다.
그렇다고 전체 scheduler가 재실행을 반드시 막는다는 증명까지 완료한 것은 아니다.

101차 `thread_terminate`의 self 경로가 기록한 종료 요청은 위 AST 소비·self halt를 통해
reaper 경로에 연결된다. other-thread terminate/force_terminate는 must_halt=1을 넘기고
halt 뒤 IPC 종료와 deallocate를 수행한다. 정적 연결과 실제 실행 완료는 구분한다.

## IPC 정리의 반복 진입 gate

`ipc_thread_terminate` 0x159770은 T+0xa8을 잠그고 T+0xac 포인터를 검사한다.
0이면 잠금을 풀고 돌아간다. 비영이면 0x1597b0에서 먼저 0으로 만들고 잠금을 푼 뒤
T+0xb0/+0xb4 send release, +0xc0 special-port 정리, +0xb8 관련 right 정리를 수행한다.
이 보조 포인터들은 0과 0xffffffff를 제외하는 조건이 있다.
마지막에는 처음 가져온 self-port를 정리한다. +0xb8 경로는 T+0xc task의 +0x88 space를 읽는다.

`ipc_task_terminate` 0x159558도 A+0x64 잠금 아래 A+0x68을 0으로 먼저 만든다.
보조 send 포인터는 +0x6c/+0x70/+0x74 및 +0x78부터 DWORD 네 항목이며,
이후 A+0x88 space와 처음 가져온 self-port를 정리한다.

이 gate는 포인터가 다시 게시되지 않는 전제에서 동일한 자체 정리 경로의 반복 진입을 막는다.
그러나 두 번째 호출은 첫 호출의 unlocked 정리가 끝나기를 기다리지 않는다.
전체 동시 종료 완료, 포트 참조 해제와 T/A 참조 수 변화, alias 재게시까지 증명한 것은 아니다.
이 함수 자체에서 bitmap/TSS 수명 계약을 새로 확정하지 않는다.

## AST 생성·소비와 누락된 CLI

`ast_init` 0x156694는 초기 EAX=0에서 need_ast 슬롯을 0으로 쓰고 증가·검사한다.
`ast_check` 0x1566b0는 processor 상태가 1인 경로에서 T+0x17c를 need_ast에 OR한다.
signal 관련 0x20과 scheduler 관련 0x4도 별도 조건으로 설정한다.
다른 processor 상태 분기와 우선순위/queue 검사는 원본대로 기록하되 런타임 불변식은 미확정이다.

`check_for_ast` 0x1929e8은 0x192a04에서 CLI 후 need_ast를 snapshot으로 저장한다.
signal 처리를 거친 뒤에도 0x192aa6의 CLI가 있다. 디컴파일 C에는 이 두 명령이 나타나지 않는다.
자체 본문에 STI가 없다는 사실을 모든 하위 호출을 포함한 최종 IF 값의 증명으로 확장하지 않는다.

0x192ab5는 현재 need_ast에서 snapshot에 들어 있던 비트만 지운다.
무조건 0으로 만드는 것이 아니다. snapshot에 없던 새 비트는 산식상 남고,
snapshot과 같은 비트의 재요청을 구분해 보존하는 산식도 아니다.
Python으로 BYTE snapshot/current 조합 65,536개의 비트 항등식을 검사했다.
이는 동시 요청을 실행·재현하거나 손실 여부를 확정한 결과가 아니다.

이후 T+0x17c & 3이 비영이면 0x192ad1에서 self halt를 호출하고 snapshot loop로 돌아간다.
그 다음에 scheduler block, FP AST 조건을 검사한다.
block continuation은 0x18dec0이다. 지정 직접 CALL 조사에서 check_for_ast로 향하는
0x187057/0x18df4d/0x18e01a를 확인했지만, 이 caller들의 전체 진입 프레임은 이번 선택 본문이 아니다.

## block, 문맥 전환과 정지 대기자 깨우기

`thread_block_with_continuation` 0x163a18과 `thread_block` 0x165328은 need_ast의 bit 2를 지우고
thread_select/thread_invoke를 반복한다. 후자는 continuation 0을 전달한다.
invoke가 0을 반환하면 다시 선택한다. 이 반복만으로 선택 공정성이나 유한 대기를 보장하지 않는다.

`thread_invoke` 0x1635e8은 세 경로를 구분한다.

1. old==new이면 상태 bit 3을 지우고, continuation이 비영이면 spl0/call_continuation을 호출한다.
2. 조건에 맞는 stack handoff에서는 새 thread 상태를 정리하고 need_ast를 교체한 뒤
   stack_handoff를 호출한다. old thread의 continuation과 상태를 기록하고 정지 대기자를 깨운 뒤
   새 thread continuation으로 이동한다.
3. 일반 문맥 전환에서는 필요하면 stack_alloc_try를 호출한다. 공급을 기다려야 하면 swapin을
   요청하고 자체 EAX=0을 반환한다. 성공 경로는 switch_context 반환 EAX를 thread_dispatch에 전달한다.

need_ast 교체 산식은 `(old & 0xbffffffc) | new_thread_AST`다.
기존 bit 0/1/30을 제거한 뒤 새 thread의 요청을 합친다. 하위 machine-context 동작까지
완료한 것으로 세지 않는다. call_continuation 이후의 C `return 1`을 평범한 정상 복귀로 가정하지 않는다.

`thread_dispatch` 0x163ac4는 old continuation이 비영이면 상태 0x100을 OR하고 stack_free를 호출한다.
상태 분류에서는 AH & 0xfc로 bit 8/9를 제거한 DWORD를 비교한다.
이 비교를 low nibble만 검사하는 것으로 축소하면 다른 상위 비트의 조건을 잃는다.
invoke의 handoff 분류는 이 마스킹 없이 자체 상태 DWORD를 비교하므로 두 분류가 완전히 같지도 않다.

정지 경로는 old 상태의 bit 2를 제거하고 T+0x48이 비영이면 이를 0으로 만든 뒤
정확히 event=T+0x48인 대기자들을 깨운다. event hash는 signed 음수라면 DWORD NOT을 한
비음수 값을 59로 나눈 나머지다. `abs(event)`와 같다고 바꾸지 않는다.
wait bucket 잠금 아래 event가 같은 thread를 제거하고 timeout 정리·상태 변경·필요한 setrun을 수행한다.

원본 wait-state 표의 핵심 분류는 다음과 같다.

| low nibble | clear_wait | invoke/dispatch 내부 wakeup |
| --- | --- | --- |
| 1, 9, 0xb | bit 0 제거, bit 2 설정, 결과 기록, setrun | 같은 상태 변경, 결과 0, setrun |
| 3, 5, 7, 0xd, 0xf | bit 0 제거와 결과 기록 | bit 0 제거와 결과 0 |
| 그 밖 | 자체 상태 변경 없이 종료 | panic 경로 |

`thread_sleep` 0x163320은 현재 thread를 event queue에 연결하고 wait 상태를 설정한 뒤,
전달받은 잠금을 0으로 풀고 block한다. 돌아올 때 전달 잠금을 다시 얻는 명령은 자체 본문에 없다.
halt/dowait의 후속 잠금 재획득을 생략하면 계약이 달라진다.

조건부 연결 예시도 Python으로 확인했다. 초기 상태 0x4, 중간 상태 변경 없음,
별도 thread로의 성공적인 해당 전환 경로라는 전제 아래:

`0x4 → hold 후 0x6 → 정지 표식 후 0x16 → 선택 handoff/dispatch 후 0x112`

마지막 값의 low nibble은 2이며 reaper의 해당 경로는 일반 deallocate로 이어진다.
101차 destructor mask 결과도 2다. 이는 조건부 상태 산식이며 native 실행이나
reaper의 실제 실행 순서·참조 균형·CPU 사용 종료를 증명하는 trace가 아니다.

`thread_release` 0x167b2c는 감소 전 hold 수가 정확히 1인 경우에만 상태 bit 1/4를 지운다.
기존 상태 & 5가 0이면 bit 2를 설정하고 setrun한다. 다른 hold 값은 감소만 한다.
0 입력의 wrap 계산을 기록했으나 실제 underflow 발생은 확정하지 않는다.

## 스택 교체 continuation의 실제 ABI

`call_continuation` 0x18d4e0은 continuation과 global 0x1f74d8에서 읽은 stack pointer를
`__call_with_stack` 0x186f7c에 전달한다. helper의 원본 전체는 다음 동작이다.

ESP+4에서 목적지를 EAX로 읽고, ESP+8에서 새 ESP를 읽고, EBP=ESP로 만든 뒤 JMP EAX한다.
새 스택에 return address를 PUSH하는 명령은 없다. 디컴파일은 두 번째 물리적 입력과
스택 교체를 잃고 간접 CALL/return처럼 표현했다. 일반 C 함수 호출 ABI로 읽지 않는다.
새 스택의 준비·소유자·정렬과 continuation별 진입/복귀 조건은 추가 분석 대상이다.

## 검증과 제한

ASM 5,253개를 기존 manifest와 대조한 조사에서 지정 직접 호출 56개와
need_ast literal-displacement write 30개를 원본에서 재디코드했다.
선택 본문 밖 hit는 edge/write 확인만이며 전체 caller 분석으로 세지 않는다.
register-only spin 50개와 C warning 21행을 기록했다. 실제 deadlock 수나 독립 결함 수가 아니다.
Ghidra 스킬의 본문·호출·제어 흐름 대조 절차를 기존 export/raw 비교에 적용했고 DB는 변경하지 않았다.
새 독립 Codex 계획 검토를 받지 않았으며 구현 코드는 작성하지 않았다.

[범위](SCOPE.md) · [디컴파일 주의점](DECOMPILER_ISSUES.md) · [남은 분석](OPEN_ITEMS.md)
· [원본 증거](object-lifetime-evidence.json) · [보존 해시](preservation.json) · [검증](checkpoint.json)

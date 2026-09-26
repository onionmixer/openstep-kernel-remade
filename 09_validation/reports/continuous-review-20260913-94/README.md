# 94차 — recovery 슬롯 초기화·문맥 전환·객체 기준 구분

OPENSTEP 원본 kernel의 분석만 이어갔다. 외부 코드·복원 구현·동적 실행은 사용하지 않았다.
93차는 실제 보고서·원본 바이트 증거를 남긴 진전이며, 이번 시작 시 checkpoint와
원본/입력/보존 해시를 다시 검사했다. 전체 원본 분석은 여전히 미완료다.

## 결과 요약

- recovery 슬롯의 초기화는 `_thread_init`의 `thread_template+0x74=0`과
  `_thread_create`의 전체 template 복사를 통해 연결된다. zero-fill 파일 구간을
  runtime 값으로 읽어낸 결론이 아니라 실제 초기화·복사 명령의 근거다.
- `switch_context`·`stack_handoff`에서 보이는 `+0x74`는 thread의 recovery 슬롯이
  아니라 **PCB의 LDT base**다. `sendsig`와 `catch_interrupt`의 같은 offset도 각각
  u-thread 문맥과 PC monitor record에 속한다. 객체 기준을 확인하지 않은 offset 검색은
  수명 분석의 증거가 될 수 없다.
- 선택한 문맥 전환 본문은 thread recovery 슬롯을 직접 지우거나 복사하지 않는다.
  따라서 “문맥 전환마다 stale recovery가 초기화된다”는 보장은 여기에서 나오지 않는다.
  모든 callee·간접 alias·실제 scheduler 환경까지 확인했다는 뜻은 아니다.
- `__switch_tss`는 새 ESP/EBP를 로드해 간접 JMP하며, 세 번째 인자를 EAX로 전달한다.
  `__return_with_state`는 CALL 프레임을 버리고 저장 상태로 스택을 바꾼 뒤 IRETD한다.
  디컴파일 C의 일반 호출·반환·두 인자 표현으로는 이 계약이 보존되지 않는다.

## 검증과 산출물

Python으로 선택 본문 15개, 5,080바이트, 명령 1,570개를 원본과 대조했다.
직접 branch 180개·CALL 86개, 간접 이동 3개, 중요 operand 166개를 확인했다.
thread_invoke의 원본 table 15개 항목, 객체 기준 추적 8개, 입력 52개,
이전 보존 파일 855개를 재검증했다. 선택 본문 전체 ASM/C는 읽었지만 모든 하위 callee와
동시성·타입·native 환경까지 의미 검증이 끝났다는 판정은 아니다.

별도로 full-pass5 함수 ASM 5,253개를 manifest와 대조한 뒤 양의 `+0x74` operand를
조사했다. 142개 파일에서 260개 고유 명령이 발견됐고, 함수 entry 주소를 immediate로
저장하는 후보는 50개다. 이들은 **완료된 recovery writer 목록이 아니라 조사 후보**다.
본문 밖 코드·절대주소 쓰기·alias를 통한 다른 offset 쓰기는 이 검색의 분모에 없다.

[원본 증거](object-lifetime-evidence.json), [보존 해시](preservation.json),
[재검증 checkpoint](checkpoint.json), [범위](SCOPE.md), [남은 작업](OPEN_ITEMS.md),
[93차 trap consumer 분석](../continuous-review-20260913-93/README.md)을 보존한다.
원본 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다.

## 1. 초기 thread 슬롯: 명시적 zero와 template 복사

`_thread_init 0x166a8c`는 thread zone element 크기 0x18c를 zinit에 전달한다.
`0x166b59`는 원본 symbol `_thread_template`의 주소 0x1f6c00에서 +0x74인
0x1f6c74에 DWORD 0을 쓴다. 이 주소는 __common이므로 파일 매핑으로 초기 DWORD를
읽지 않았으며, 초기화 명령 자체를 증거로 삼았다.

`_thread_create 0x166c48`는 parent가 NULL이면 4, 첫 thread zalloc이 NULL이면 6으로
반환한다. 성공하면 `CLD; ECX=0x63; REP MOVSD`로 template를 새 thread에 복사한다.
Python 계산상 396바이트이며 zone element 크기와 같고 +0x74 DWORD를 포함한다.
그 다음 parent(+0xc), lock(+0x20), tick(+0x70), timeout/PCB/IPC, u-thread(+0x84)
초기화를 수행한다. PCB와 u-thread는 thread 자체와 별도로 할당한다.

이로써 **초기화된 template가 유지된다는 전제에서 새 thread가 recovery 0을 받는
지역 경로**를 확인했다. boot의 thread_init 호출 순서, template의 모든 간접 writer,
초기화 이후 하위 callee의 영향까지 확정한 것은 아니다. 객체 재사용 때 allocator가
자동으로 슬롯을 지운다고 가정할 필요도 없고, 그렇게 주장하지도 않는다.

## 2. 같은 +0x74의 서로 다른 기준 객체

| 원본 접근 | 기준을 만드는 명령 경로 | 이번 판정 |
|---|---|---|
| 93차 0x1924ab | active_threads → thread | recovery 주소 |
| 0x18d570 | pcb_init의 zalloc 결과 → thread+0x28에 저장 | PCB LDT base 쓰기 |
| 0x18d3f5 / 0x18d3fb | new/old thread+0x28 → PCB | LDT base 비교 |
| 0x18d2c8 / 0x18d2cb | handoff new/old thread+0x28 → PCB | LDT base 비교 |
| 0x19357f / 0x193585 | 전역 0x1e875c → switch_unix_context가 thread+0x84로 설정 | u-thread 문맥 필드 |
| 0x187040 | thread+0x28→+0xec→간접 객체→선택 record | PC monitor record 필드 |

`_switch_unix_context 0x106e0c`는 인자 thread의 +0x84를 전역 0x1e875c에 쓰고,
thread+0xc가 가리키는 task의 +0x38을 active_u 0x1e8758에 쓴다.
`sendsig`의 +0x74 clear를 thread recovery clear로 해석하면 기준 포인터 한 단계를
잘못 합친 셈이다. 별도 할당 객체의 정상 비중첩·현재 문맥 일치성은 runtime 전제이며,
임의 손상 상태에서도 절대 alias가 없다고 증명한 것은 아니다.

`catch_interrupt`의 PC record는 index가 unsigned 7 이하일 때
`base+0x88+index*0x84`로 계산된다. 곱셈 상수는 원본 SHL/ADD/LEA를 Python으로
환산한 132바이트다. +0x78/+0x74와 +0x48 조건을 보고 PCcallMonitor를 호출하는 코드이며,
이 +0x74를 recovery 주소의 presence 검사로 해석하지 않는다.

## 3. PCB 초기화와 descriptor 전환

`_pcb_init 0x18d520`은 PCB zalloc 결과를 thread+0x28에 넣고 파일 template 0x1d14ec를
CLD/REP MOVSD로 244바이트 복사한다. PCB[0]=PCB+8, PCB+4=0x68을 설정하고,
task/map/pmap에서 CR3 관련 값을 얻어 PCB+0x24에 넣는다.
PCB+0x74에는 전역 `_ldt` 값에 0xc0000000을 더한 DWORD 값,
PCB+0x78에는 0x18을 넣는다. 이는 thread recovery가 아니다.
선택된 함수 자체에는 zalloc NULL gate가 없으며 allocator 계약은 별도 미완료다.

`switch_context`/`stack_handoff`는 old/new PCB의 이 base/length를 비교하고 다르면
GDT+0x20 descriptor의 base/limit/access를 조립한 뒤 LLDT한다.
TSS descriptor는 GDT+0x18에 PCB[0]+0xc0000000, PCB+4의 length-1로 매번 조립하고
access BYTE=0x89 후 LTR한다. 원본 selector WORD는 각각 0x20/0x18이다.
CR3 값이 다르면 MOV CR3를 실행하고, CR0에 mask 0x8을 OR해 다시 쓴다.

descriptor의 limit 저장은 low WORD와 high nibble로 나뉜다. length=0을 가정하면
DWORD length-1은 0xffffffff이고 저장되는 limit 필드는 0xfffff다.
이는 Python 폭 계산 예이며 실제 0 length가 발생한다는 증거가 아니다.
실제 GDT/LDT/TSS 내용·page table 유효성·CPU 상태·zero length 금지의 상위 계약은 남는다.
디컴파일 C는 일부 CR3/CR0 쓰기를 생략하거나 반환값처럼 표현하므로 명령을 기준으로 분리했다.

## 4. scheduler caller와 global 전환 순서

`_thread_invoke 0x1635e8`에서 old==new이면 thread state mask를 정리하고,
continuation이 nonzero이면 spl0/call_continuation을 거쳐 1을 반환하는 형태다.
다른 thread이면 new thread lock을 잡고 stack/continuation/state를 검사한다.

handoff는 old+0x30이 active_stacks와 다르고 continuation이 nonzero이며,
new state의 `&0x300 ==0x100`인 선택 경로다. new 상태/need_ast를 갱신한 뒤
`switch_unix_context(new)`를 **먼저**, `stack_handoff(old,new)`를 그 다음 호출한다.
일반 switch 경로도 `switch_unix_context(new)` 뒤 `switch_context(old,continuation,new)`
순서다. stack_alloc_try가 실패하거나 swapin 조건이면 thread_swapin 요청 후 0을 반환하는
경로도 있으므로 모든 invoke 호출이 실제 전환했다는 뜻은 아니다.

`switch_context`는 active_threads=new, active_stacks=new+0x2c,
stack_pointers=new stack+0xff4를 쓰고 CR3/descriptor/CR0를 갱신한 뒤 저수준 switch로 간다.
따라서 Unix 전역과 machine 전역이 별도 명령·호출 단계로 바뀌는 사실은 확인했다.
이 중간 상태가 interrupt에 실제 노출되는지는 spl/IRQ/caller의 환경을 확인해야 하며,
이 순서만으로 race를 확정하지 않는다. 선택 switch/handoff 자체에는 CLI나
thread+0x74 reset이 없다.

handoff는 old+0x2c를 0으로 만들고 그 stack을 new+0x2c에 넘긴다.
new TSS형 저장 영역의 EBP/ESP 필드를 stack+0xff4로, PC를 0x186f74로 설정한다.
이 함수는 현재 실행 스택 자체를 바꾸는 __switch_tss를 호출하지 않고 반환하며,
thread_invoke는 old 상태 처리 후 new continuation 호출로 간다.
active_stacks/stack_pointers의 handoff 전제와 continuation의 정확한 프레임 폐기는 후속 범위다.

thread_invoke의 wait-queue 분기 table도 원본으로 확인했다. low nibble 1/9/11은
state의 bit0을 지우고 mask4를 켠 뒤 wait result +0x44=0과 setrun을 수행한다.
3/5/7/13/15는 bit0과 wait result만 정리한다. 나머지는 panic 분기다.
이는 이번에 확인한 wait_result **0 writer**이며, 93차 VM fault의 nonzero 대기 종료
가능성까지 증명하지 않는다. wait queue 수명/타이머/전체 scheduler 상태는 미완료다.

## 5. __switch_tss의 실제 ABI: ESP를 바꾼 뒤 JMP

`0x186f20`의 첫 인자는 old 저장영역이다. nonzero이면 EDI/ESI/EBX/EBP를 각각
old+0x44/+0x40/+0x34/+0x3c에 저장한다. POP으로 CALL 반환 주소를 꺼내 old+0x20에,
그 뒤 ESP를 old+0x38에 저장한다. new 저장영역은 POP 이후 ESP+4에서 얻는다.
new 영역으로부터 EDI/ESI/EBX/EBP를 로드하고, POP 이후 ESP+8의 **세 번째 인자**를
EAX에 둔 뒤 new ESP와 PC를 로드해 `JMP EDX`한다.

old 인자가 0인 경로는 이전 register 저장을 생략하고 같은 방식으로 new 상태에 진입한다.
switch_context는 continuation이 nonzero일 때 old 저장영역 대신 0을 전달한다.
세 번째 인자는 떠나는 thread 포인터이며 switch_context epilogue는 EAX를 덮지 않는다.
thread_invoke의 호출 다음 명령은 EAX를 EBX로 받아 thread_dispatch에 넘긴다.
복귀하는 stack은 다른 invocation의 stack일 수 있으므로 단순 C의 같은 호출 frame 복귀가 아니다.

C 출력에는 두 인자·간접 jump를 call로 취급한다는 경고가 있다.
원본은 간접 CALL/RET가 아니라 두 지점의 간접 JMP이고, 두 경로 모두 새 ESP를 사용한다.
이 경고를 jump table을 찾지 못한 일반 switch 문법 문제로만 처리하지 않았다.
saved PC writer 전체와 new frame 유효성, caller별 continuation 및 native 재개는 남는다.

저수준 switch의 저장 영역에도 thread recovery 슬롯을 옮기는 명령은 없다.
선택 문맥 전환 코드만을 근거로 기존 thread의 recovery 주소가 사라진다고 할 수 없다.
유효한 객체가 유지된다는 전제에서는 그 주소는 thread 객체에 남는 값으로 취급해야 한다.

## 6. thread 종료는 매 전환의 슬롯 초기화가 아님

`thread_deallocate 0x166ea0`는 thread NULL이면 바로 epilogue로 간다.
thread+0x20 lock과 splsched 아래 +0x24 ref를 감소시키며 signed 결과가 양수이면 반환한다.
0 이하이면 ref=1로 되돌리고 pset/task/thread 계층 lock을 잡아 다시 감소·검사한다.
따라서 단순 “한 번 감소해 0이면 곧바로 free” 코드가 아니다.

최종 경로는 타이머·시간 집계·queue unlink·pset 제거·보조 VM 자원 정리 후,
자기 자신(active_threads==thread)이면 panic, state mask가 요구값이 아니어도 panic한다.
그 뒤 task/stack/freeStack/PCB/u-thread/thread zone 반환으로 이어진다.
선택 본문에는 thread+0x74 clear가 없다. panic이 실제로 반환하지 않는지,
각 callee가 어떤 alias를 바꾸는지, 참조 하한·객체 유효성까지 끝낸 판정은 아니다.

`pcb_terminate`는 FP/PC 상태, 필요하면 PCB+0x70의 0xe0 영역과 별도 TSS 영역을 해제하고,
thread+0x28=0 후 PCB를 zfree한다. 이것도 thread+0x74와 다른 필드다.
thread_deallocate의 C에 붙은 register parameter/추가 인자 표현을 실제 호출 ABI로
신뢰하지 않았다. 원본은 thread를 `[EBP+8]`에서 가져오며 selected caller도 이를 push한다.

## 7. thread_exception_return: 일반 RET로 읽으면 안 되는 이유

현재 thread의 PCB+0x70이 nonzero이면 그 +0x84를 saved frame S로 쓴다.
없으면 kalloc(0xe0) 결과를 PCB+0x70에 넣고 +0x84 위치에 파일 template 0x1d15e0을
CLD/REP MOVSD로 92바이트 복사한다. Python 계산상 0x84+92=224로 할당 크기와 같다.
함수 자체에는 kalloc 실패 gate가 없으며, allocator 정책과 native 실패 여부는 미완료다.

S 상대 EFLAGS+0x40=0x200, CS+0x3c=0x63, SS+0x48=0x6b,
DS/ES=0x6b, FS/GS=0을 초기화한다. check_for_ast(S) 후 saved VM mask에 따라
TSS형 저장영역 +4에 S+0x5c 또는 S+0x4c를 설정하고 `__return_with_state(S)`를 호출한다.

`__return_with_state 0x186f04`는 다음 동작을 한다.

1. POP으로 CALL 반환 주소를 버리고, 다음 POP으로 S를 EBX에 얻는다.
2. CLI 후 ESP=S, empty_stacks=1, STI를 실행한다.
3. GS/FS/ES/DS와 PUSHAD 저장값을 복원하고 trap/error 8바이트를 건너뛴다.
4. `IRETD`로 저장된 상태에 복귀한다.

따라서 정상적인 유효 saved frame 경로에서는 thread_exception_return의 CALL 다음
epilogue로 C 함수처럼 돌아오지 않는다. 이 사실을 조건 없는 모든 hardware fault·
malformed frame에서의 nonreturn 보장으로 확대하지 않는다.
선택 return helper에는 thread recovery clear·저장 DF를 무조건 지우는 명령이 없다.
AST 하위 경로의 영향까지 제외한 전체 no-clear 증명은 아니며, 그 구분을 유지한다.

## 8. AST·신호 전달에서의 실제 copy 연결

check_for_ast는 CLI 후 need_ast snapshot을 사용해 프로파일·signal·halt·preemption·FP
경로를 검사한다. preemption 경로의 thread_block_with_continuation 인자는 실제
0x18dec0(thread_exception_return)이다. selected helper는 통상 return 분기에도
STI를 넣지 않으며, 최종 return_with_state가 별도 STI를 수행한다.
signal/scheduler 하위 callee의 모든 IRQ 상태·복구 슬롯 변경은 아직 닫히지 않았다.

sendsig는 signal 인자가 4/8이면 전역 0x1e875c 기반 객체의 +0x74를 읽어 신호 인자로
옮기고 해당 문맥 필드를 0으로 만든다. 이는 thread recovery clear가 아니다.
그 뒤 실제 copyout을 12바이트, 72바이트 순서로 호출하고 각각 EAX 오류를 검사한다.

93차에서 재검증한 copyout 계약에 따르면 첫 호출은 짧은 성공 경로이고 두 번째는
긴 경로다. 따라서 첫 호출의 정상 반환 직후부터 두 번째 호출 전까지를
“sendsig가 recovery를 이미 명시적으로 지웠다”라고 해석하면 틀린다.
후속 긴 copy의 정상 완료에는 copyout 자체의 clear가 있다. 이것은 특정 두 호출의
지역 연결이며, 이 사이에 실제 fault가 발생한다거나 frame이 잘못 복귀한다는 증명은 아니다.

두 번째 copy 전에는 PC record 상태와 saved VM flag도 바뀔 수 있다.
오류 분기는 active_u 관련 signal 상태를 정리하고 psignal(...,4)를 호출한다.
성공 뒤에는 saved EIP/CS/ESP/SS/segment를 signal handler용으로 바꾼다.
부분 user-memory 갱신과 실패 이전 상태 변경을 이 함수가 전부 되돌린다고 가정하지 않는다.
sigreturn·실제 user-state mapping·신호 번호 상한·alternate stack·후속 psig는 추가 분석 대상이다.

## 9. 양의 +0x74 검색의 정확한 의미와 다음 조사

5,253개 ASM 파일의 경로 집합·크기·SHA를 baseline manifest와 대조했다.
일치 operand 260개는 원본 bytes/명령 길이와 displacement를 다시 확인했다.
LEA도 주소 후보로 포함되므로 모든 항목이 메모리 읽기/쓰기인 것은 아니다.
50개 code-pointer store 후보에는 copy/fu/su 계열뿐 아니라 PC emulation 경로가 포함된다.
현재는 원본 함수 entry를 저장한다는 사실만으로 해당 base가 thread라고 확정하지 않았다.

이 자료는 전체 writer를 빠뜨리지 않기 위한 **후속 조사 목록**이지 전체 alias closure가 아니다.
특히 thread_template의 절대주소 초기화처럼 `+0x74` 문구가 없는 실제 관련 write가 존재한다.
base를 미리 더해 `[reg]`에 쓰는 경우, bulk copy, 다른 폭/offset의 겹침, 함수 밖 명령도
별도로 조사해야 한다. 기존 export의 완전성과 원본 전체 executable 영역 coverage도
별도 완료 기준으로 유지한다.

계산은 Python만, 편집은 apply_patch만 사용했다. Ghidra 스킬의 절차에 따라 함수 본문,
C 해석, 참조와 실제 기준 포인터·명령을 나누어 대조했고 live DB는 변경하지 않았다.
새 독립 계획 교차검토 미수신은 통과로 처리하지 않았으며 실패 요청을 재시도·우회하지 않았다.

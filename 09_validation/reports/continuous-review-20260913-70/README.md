# Timer callback과 wait 해제·scheduler 진입

timer의 등록·취소·service adapter에서 thread timeout과 clear_wait까지 연결했다. **reset_timeout의 TRUE는 기존 활성 플래그가 있었다는 뜻이며 callback이 실행되지 않았다는 증명은 아니다.** 또한 thread timeout은 IPC queue의 ith_state를 직접 변경하지 않고 scheduler wait_result를 기록하는 경로를 사용한다.

보고서 69의 checkpoint와 파일을 재검증했다. 이전 턴은 큐 송수신·resume 계약과 증거를 확정한 실제 진전이다. Ghidra 스킬을 보존 export 읽기 전용 대조에 적용했고, 모든 계산은 Python으로 수행했다. 문서·정적 증거만 추가하며 원본·참고 소스·DB·export·기존 확정 보고서·07_kernel을 보존했다. 신규 독립 계획 검토·구현·새 실행 검증 프로그램·동적 실행·GCC 2.7 빌드는 수행하지 않았다.

## 증거 범위

[정적 증거](timer-wait-evidence.json)에 전체 본문 VA/file mapping·원본 바이트·독립 디코딩·직접/간접 제어 이전·switch 표·필드와 정수 계산·입력 해시를 기록했다. [보존 목록](preservation.json)은 이전 확정 자료를 잇는다.

| 함수 | 주소 | instruction heads | 본문 바이트 |
|---|---|---:|---:|
| set_timeout | 0x15bdc4 | 38 | 101 |
| reset_timeout | 0x15be2c | 39 | 111 |
| init_timeout_element | 0x15bda8 | 9 | 27 |
| FUN_0015c0ac (service adapter) | 0x15c0ac | 32 | 83 |
| thread_timeout | 0x162e68 | 10 | 20 |
| thread_set_timeout | 0x162e7c | 37 | 89 |
| thread_timeout_setup | 0x162ed8 | 18 | 70 |
| clear_wait | 0x16303c | 111 | 294 |
| ticks_to_ns_time | 0x1606d0 | 27 | 68 |
| calloutDeadlineFromInterval | 0x1691e8 | 16 | 31 |
| thread_go_and_switch | 0x1590d8 | 75 | 216 |
| thread_block_with_continuation | 0x163a18 | 35 | 87 |

Python 집계는 본문 12개, instruction heads 447개, 1197바이트, 직접 분기 37개, 직접 호출 33개, 간접 제어 이전 3개다. switch 표 2개, DWORD 30개, 120바이트는 함수 코드와 별도로 원본에서 읽었다. 명시적 Ghidra WARNING은 0개지만 아래 ABI·lock 표현 문제는 남아 있다. 전체 callout scheduler/context switch의 검증 수치가 아니다.

## Timer의 등록 필드와 실제 callback 연결

thread_timeout_setup은 thread+0x138에 thread_timeout, +0x13c에 thread pointer를 쓰고 thread+0x118 timer에 init_timeout_element를 호출한다. depress timer에는 thread+0x168에 thread_depress_timeout, +0x16c에 thread pointer를 쓰고 thread+0x148을 초기화한다. depress callback 내부는 이번 범위 밖이다.

timer element 기준으로 user callback은 +0x20, 인자는 +0x24, active/set 필드는 +0x2c다. 따라서 일반 thread timer의 active 필드는 thread+0x144다. init_timeout_element는 element+8=FUN_0015c0ac, +0x10=element 자신, +0x1c=0만 저장한다. **user callback·parameter·active 플래그를 모두 초기화하는 함수가 아니다.** thread 생성 시 저장소 초기화와 set==0 보장은 별도 caller 조건이다.

등록된 adapter FUN_0015c0ac는 splsched 후 timer global lock(0x1e5ba8)을 획득한다. 0x15c0d7/+0x20에서 callback, 0x15c0da/+0x24에서 parameter를 register에 저장하고 0x15c0dd에서 active=0으로 만든다. timer lock을 풀고 splx한 뒤 0x15c0f3에서 저장한 callback을 간접 호출한다. callback/parameter를 unlock 뒤 다시 읽지 않는다. callback NULL 또는 기존 active==0을 검사해 호출을 취소하는 코드도 없다.

이 연결은 등록 필드와 service adapter의 dispatch를 원본으로 확인한 것이다. callout backend가 adapter를 어느 시점·CPU·interrupt 수준에서 호출하고 취소 경합을 어떻게 직렬화하는지까지 증명하지는 않는다. Ghidra의 adapter C는 lock 획득 XCHG/재시도를 불완전하게 표현하므로 빈 LOCK/UNLOCK 표기를 그대로 구현으로 사용할 수 없다.

## set_timeout과 64-bit deadline ABI

set_timeout(element,ticks)는 splsched → timer lock → ticks_to_ns_time → calloutDeadlineFromInterval → calloutEntryDispatchDelayed(element,deadline) → element.set=1 → timer unlock → splx 순서다. callout dispatch 상태를 검사하지 않는다. raw set_timeout에는 Darwin의 spec_proto 비교/필요시 lazy init 분기가 없다. 이미 초기화된 element라는 조건이 중요하다.

ticks_to_ns_time은 ticks를 unsigned DWORD로 읽고 global 0x1f6530/0x1f6534의 low/high DWORD와 곱해 하위 64-bit 결과를 EDX:EAX로 반환한다. 수식은 `(uint32_ticks * uint64_ns_per_tick) mod 2^64`다. high DWORD를 무시하거나 signed ticks로 확장하는 것은 원본과 다르다. ns_per_tick의 초기화·runtime 값·갱신 원자성은 이번에 검증하지 않았다.

calloutDeadlineFromInterval은 interval low/high stack words를 저장하고 clock_value(1)의 EDX:EAX 결과에 ADD/ADC로 interval을 더한다. 결과는 modulo 2^64 deadline이다. clock_value(1)의 정확한 clock domain과 실제 clock monotonicity는 해당 callee 분석이 필요하다.

set_timeout caller는 EDX(high), EAX(low) 순서로 push하여 interval/deadline을 전달한다. 연속 호출 인자 정리는 마지막 ADD ESP,0x18에서 수행한다. Python으로 계산한 stack argument 합은 24바이트다. Ghidra의 undefined8/CONCAT44는 이 register·stack ABI를 나타내는 보조 표현이지 GCC 2.7용 선언 검증 결과가 아니다.

조건부 산술 예시로 ns_per_tick=0x100000001, ticks=2의 결과는 0x200000002이며, now=0xffffffff에 interval=1을 더하면 0x100000000이다. 모두 Python 수식 계산이고 실제 timer 실행 결과는 아니다.

## reset_timeout의 반환값과 취소 경계

reset_timeout은 splsched와 timer lock 아래 element+0x2c를 검사한다. 비영이면 calloutEntryRemove(element)를 호출하고 active=0으로 만든 뒤 unlock/splx 후 TRUE(1)를 반환한다. 이미 0이면 backend remove를 호출하지 않고 FALSE(0)를 반환한다.

TRUE는 backend 제거 성공 상태를 읽어 반환한 것이 아니다. FALSE도 callback이 끝났다는 뜻은 아니다. service adapter는 callback 호출 **전에** active를 0으로 만든다. 따라서 이 플래그 하나만으로 callback in-flight·완료·미실행을 모두 구분할 수 없다. 실제 remove와 service의 race, 재등록, element 수명은 callout backend 및 생성자 분석이 남아 있다.

thread_set_timeout(ticks)는 current thread를 읽고 splsched/thread lock 아래 TH_WAIT가 있을 때만 set_timeout(thread+0x118,ticks)를 호출한다. 이 함수의 인자는 이미 ticks이며 IPC의 millisecond→ticks 변환을 다시 하지 않는다. thread_will_wait_with_timeout과 다른 진입 계약이다.

## thread_timeout은 IPC completion이 아니다

thread_timeout의 원본은 clear_wait(thread,1,0)을 호출할 뿐이다. 참고 헤더의 result=THREAD_TIMED_OUT, interrupt_only=FALSE에 대응한다. 원본에는 timer.set==UNSET assert가 없다. callback 자체가 timer element를 free하거나 IPC sender/receiver ring에서 thread를 제거하지 않는다.

clear_wait도 thread+0x98(ith_state)를 직접 변경하지 않는다. scheduler state와 wait_result(+0x44)를 처리한다. [보고서 69](../continuous-review-20260913-69/README.md)의 mqueue는 깨어난 뒤 ith_state가 아직 IN_PROGRESS이면 IPC ring에서 스스로 제거하고 wait_result를 검사하므로, timeout과 IPC 성공을 구분할 수 있다. scheduler wait queue의 link(+0/+4)와 IPC link(+0x90/+0x94)는 서로 다르다.

## clear_wait: event 재검사와 lock 순서

ABI는 `(thread,result,interrupt_only)`다. splsched와 thread lock을 얻은 뒤 interrupt_only가 비영이고 TH_UNINT가 있으면 상태 변경 없이 unlock/splx한다. timeout callback은 interrupt_only=0이므로 이 배제를 요청하지 않는다.

wait_event(+0x3c)가 비영이면 기존 event를 보관하고 thread lock을 먼저 푼다. event hash bucket lock을 얻은 뒤 thread lock을 다시 얻는다. hash는 event가 signed 음수면 bitwise complement, 아니면 그대로 사용한 값을 59로 나눈 나머지다. abs(event)가 아니다. Python 계산에서 event=-1은 bucket 0, -2는 bucket 1, INT_MIN은 bucket 54다. 원본 IDIV 전 정규화된 값은 비음수다.

0x1630cc에서 현재 wait_event가 저장한 event와 같은지 비교한다. 같으면 thread의 scheduler queue 이웃 link를 연결하고 wait_event=0으로 만든다. 다르면 queue에서 제거하거나 새로운 event bucket으로 재시도하지 않고 bucket lock을 푼 뒤 최종 thread unlock 경로로 간다. 다른 event나 이미 해제된 대기에 예전 요청의 result를 덮어쓰지 않는 조건이다.

처음 event==0이거나 위에서 성공적으로 제거했을 때만 다음 상태 처리를 한다. thread state를 저장하고 timer active가 있으면 reset_timeout을 호출한다. 이때 thread lock은 유지한다. event 변경 경로 또는 interrupt_only 배제 경로는 timer reset도 실행하지 않는다. interrupt_only/TH_UNINT 검사를 relock 뒤 다시 하는 코드는 없다. 이 순서를 확인한 것이 모든 native interleaving의 안전성 증명은 아니다.

## clear_wait와 go_and_switch의 원본 switch 표

clear_wait의 표는 0x163124, go_and_switch의 표는 0x159138이다. 각각 state & 0xf 후 DEC와 unsigned CMP 0xe/JA guard로 접근하며 모든 target이 해당 본문 instruction head인지 검증했다.

| low state | clear_wait | thread_go_and_switch |
|---|---|---|
| 0x1, 0x9, 0xb | WAIT 해제·RUN 설정, wait_result=result, thread_setrun(thread,1) | WAIT 해제·RUN 설정, wait_result=0, CPU/processor-set 조건에 따라 run/setrun |
| 0x3, 0x5, 0x7, 0xd, 0xf | WAIT 해제, wait_result=result, setrun 없음 | WAIT 해제, wait_result=0, setrun 없음 |
| 나머지 | state/wait_result 쓰기 없음 | state/wait_result 쓰기 없음 |

상위 state bits는 유지한다. clear_wait의 default도 그 전에 timer reset을 수행할 수 있다. result를 쓴다고 모두 즉시 runnable queue에 넣는 것은 아니며, clear_wait 호출 자체가 실제 실행을 보장하지 않는다. [보고서 66](../continuous-review-20260912-66/README.md)의 thread_go는 result를 0으로 쓰는 별도 연결이다.

## thread_go_and_switch: 직접 run과 continuation fallback

ABI는 `(continuation, thread)`다. timer reset 후 위 runnable 분기에서 target thread의 processor_set(+0x180)을 확인한다. 그 set의 idle_count(+0x114)가 signed 양수이거나 current thread의 set과 다르면 thread_setrun(thread,1)을 호출한다. 그 외에는 target thread lock을 풀고 thread_run(continuation,thread)로 넘긴다. raw 조건은 idle_count==0이 아니라 양수가 아님을 사용하므로 손상된 음수 값까지 정상 idle 상태로 해석해서는 안 된다.

setrun 경로나 WAIT만 해제한 경로, default는 thread unlock 후 continuation이 비영이면 spl0 → call_continuation(continuation)을 호출한다. 따라서 함수 이름만 보고 언제나 target thread로 직접 switch한다고 결론 낼 수 없다. continuation의 실행/비복귀·stack 교체는 해당 assembly/callee 분석이 남는다.

Ghidra C는 이 함수에서 reset_timeout, thread_run, thread_setrun, call_continuation, splx를 무인자 호출처럼 표시하고 stack local을 만들어낸다. 원본 PUSH로는 각각 timer pointer, `(continuation,thread)`, `(thread,1)`, continuation, saved spl 인자가 확인된다. C 출력의 인자 생략을 ABI로 채택하지 않는다.

## thread_block_with_continuation의 진입 범위

원본은 current thread와 processor pointer를 global에서 저장한 뒤 splsched한다. need_ast의 AST_BLOCK(0x4) bit를 지우고, 이어 같은 global을 다시 읽는 명령도 존재한다. Ghidra C는 이 후속 읽기를 표현하지 않는다.

thread_select(processor)를 호출하고 그 결과를 thread_invoke(current,continuation,selected)에 전달한다. thread_invoke가 0을 반환하면 **thread_select부터 다시** 반복한다. 저장한 current thread·processor를 매번 global에서 다시 읽지 않는다. 비영이면 saved spl로 복원하고 반환한다.

이 wrapper만으로 kernel stack을 실제 폐기했거나 특정 thread에 context switch했다고 검증할 수 없다. thread_select/invoke/run, processor/thread 생존 조건과 machine-dependent switch·call_continuation을 이어서 분석해야 한다.

## 동기화·참고 소스 차이·미완료 항목

이번 register-only busy loop는 8곳이다. set_timeout(0x15bdd4)은 **EDX**를 사용하며, 나머지 load 주소 0x15be3c, 0x15c0bc, 0x162e94, 0x163054, 0x1630a0, 0x1630b8, 0x1590f0은 EAX다. 각 JNZ 75fc는 memory load가 아닌 register TEST로 되돌아간다. EAX 패턴만 검색하면 set_timeout을 놓치므로 이번 정적 검사는 register operand를 일반화했다. 모든 lock 형태 또는 native 진행성을 전수 검증했다는 뜻은 아니다.

Darwin timer는 thread_call/tvalspec/tick_stamp와 lazy initialization을 사용하지만 원본은 NeXT callout 및 64-bit ns deadline 경로다. 레이아웃과 clock domain을 참고 소스 이름만으로 대체하지 않는다. 이번에 확인한 구조 대응과 raw ABI는 실제 GCC 2.7 C/assembly probe를 대신하지 않는다.

[남은 작업](OPEN_ITEMS.md)의 callout backend·scheduler 선택/실행·stack/interrupt 생존 조건을 계속 연결해야 한다. 전체 원본 분석·복원·실컴파일·부팅 완료로 판정하지 않는다.

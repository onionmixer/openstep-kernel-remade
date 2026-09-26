# Callout 대기열·취소 경계·clock backend

70차의 timer adapter를 실제 callout backend와 연결했다. **calloutEntryRemove는 대기열 항목을 제거하지만 실행 중 callback의 종료를 기다리는 함수가 아니다.** status=0은 callback 미실행을 뜻하지 않으며, 만료 처리를 위한 임시 목록에서도 나타난다. 이미 status가 비영인 entry를 delayed dispatch하면 기존 deadline을 갱신하지 않는다.

Ghidra 스킬로 보존된 전체 ASM/C 본문을 읽고 Python으로 원본 Mach-O 매핑·바이트·명령어 경계·직접 분기/호출·데이터와 정수 계산을 검증했다. [증거](callout-clock-evidence.json), [보존 목록](preservation.json), [남은 작업](OPEN_ITEMS.md)을 분리했다. 직전 70차 체크포인트와 입력을 재검증했다. 신규 독립 계획 교차검토·구현·새 실행 검증 프로그램·동적 실행·GCC 2.7 빌드는 수행하지 않았다. 이전 실패 검토를 재요청하거나 우회하지 않았다.

## 검증 범위

Python 집계는 본문 18개, 명령어 946개, 본문 2964바이트, 직접 분기 93개, 직접 호출 52개, 간접 호출 2개다. 원본 데이터 창 4개, register-only busy loop 9곳, 명시적 Ghidra WARNING 3개를 기록했다. 입력 60개와 이전 보존 파일 738개를 해시 검증했다. 이 수치는 아래 본문 범위이며 모든 callout API·scheduler·clock hardware의 완료율이 아니다.

| 함수 | 주소 | 명령어 | 본문 바이트 |
|---|---|---:|---:|
| calloutInitialize | 0x169124 | 42 | 194 |
| calloutEntryDispatch | 0x16982c | 42 | 138 |
| calloutEntryDispatchDelayed | 0x169944 | 112 | 310 |
| calloutEntryRemove | 0x169bbc | 54 | 164 |
| FUN_00169c64: wake helper | 0x169c64 | 26 | 76 |
| FUN_00169cb0: worker continuation | 0x169cb0 | 98 | 343 |
| FUN_00169e0c: creator continuation | 0x169e0c | 43 | 148 |
| FUN_00169ea0: creator entry | 0x169ea0 | 48 | 164 |
| FUN_00169f44: expire callback | 0x169f44 | 164 | 501 |
| FUN_0016a140: worker entry | 0x16a140 | 9 | 24 |
| system_timer_dispatch | 0x187844 | 59 | 210 |
| clock_value | 0x187b98 | 19 | 54 |
| timer_attributes | 0x187c58 | 12 | 24 |
| set_timer_expire_func | 0x187c74 | 9 | 24 |
| set_timer | 0x187c8c | 66 | 185 |
| FUN_00187d48: clock interpolation | 0x187d48 | 114 | 332 |
| ns_hardclock_init | 0x160478 | 23 | 56 |
| hardclock_init | 0x18791c | 6 | 17 |

FUN 명칭에 붙인 역할은 원본 참조·필드·호출 흐름에 따른 분석용 설명이며 복원된 원래 static 함수명이라는 주장이 아니다.

## Entry layout와 상태의 의미

entry+0/+4는 양방향 queue link, +8은 callback, +0xc는 이번 dispatch의 인자, +0x10은 기본 인자, +0x14/+0x18은 deadline low/high, +0x1c는 내부 status다. [70차](../continuous-review-20260913-70/README.md)의 timer element+0x2c인 바깥 set 플래그와 구별한다.

| 내부 status | 이번 원본에서 확인한 의미 | Remove 동작 |
|---|---|---|
| 1 | pending 실행 목록 | unlink, pending count 감소, status=0 |
| 2 | deadline 순서 delayed 목록 | unlink, status=0 |
| 0 | 초기/미등록뿐 아니라 worker가 꺼낸 항목과 expire 임시 목록에도 사용 | queue 변경 없이 반환 |
| 그 외 | 이번 정상 producer가 만들지 않음 | queue 변경 없이 반환 |

backend lock은 0x1e7244, free queue는 0x1e7248, pending queue는 0x1e7250, delayed queue는 0x1e7258이다. 0x1e7260은 pending 수, 0x1e7264는 실행 callback 수, 0x1e7268은 worker 수로 대응된다. 이 역할은 producer/consumer의 증가·감소와 비교에서 유도했다. 손상·overflow·모든 writer의 전수 불변식을 증명한 것은 아니다.

## 초기화와 pool

calloutInitialize는 0x1dfcbc가 0일 때만 실행하며 자체 lock으로 중복 진입을 직렬화하지 않는다. backend lock을 0으로 만들고 각 queue를 self-linked sentinel로 초기화한다. pool 범위는 `[0x1e6a44,0x1e7244)`, stride 0x20이다. Python 계산으로 2048바이트, 64개 entry이며 free queue에 연결한다.

원본 초기화 loop는 link만 쓴다. 각 entry의 callback·인자·deadline·status를 명시적으로 모두 0으로 만드는 loop가 아니며 pending/active/worker count를 별도 store로 초기화하지도 않는다. 해당 전역의 loader 초기값과 호출 순서는 별도 부팅 조건이다. 이번 데이터 읽기는 파일에 실제 존재하는 영역만 대상으로 했으며 file-backed가 아닌 전역을 원본 파일의 0바이트로 꾸미지 않았다.

kernel_thread(kernel_task,FUN_00169ea0,0)를 호출하고 set_timer_expire_func(0,FUN_00169f44) 후 init guard를 1로 만든다. thread 생성이나 callback 등록 성공 상태를 검사하지 않는다. set_timer_expire_func는 첫 인자를 검사하지 않고 global callback 0x1e75e4가 0일 때만 두 번째 인자를 저장한다. 이미 비영인 callback을 교체하지 않으며 동기화·비NULL 인자 검증도 없다. 따라서 초기화 호출만으로 등록 성공과 worker 생성 성공을 보장하지 않는다.

## 즉시 dispatch와 wake helper

calloutEntryDispatch는 splsched/backend lock 아래 status=0일 때만 default argument(+0x10)를 current argument(+0xc)로 복사하고 deadline을 0으로 만든다. pending tail에 append, pending count 증가, status=1 후 FUN_00169c64를 호출한다. status가 비영이면 아무 재등록 없이 unlock/splx한다.

wake helper는 caller가 잡은 backend lock을 **해제하는** helper다. signed 비교로 `worker_count < active_count + pending_count`를 저장하고 unlock 후 thread_wakeup_prim(pending_count 주소,1,0)을 호출한다. 부족 조건이면 worker_count 주소도 같은 인자로 깨운다. 자체 lock 획득이나 spl 복원은 없다. caller가 helper 뒤 다시 unlock하는 것으로 복원하면 계약이 달라진다. thread_wakeup_prim 내부의 실제 깨우기·CPU 실행은 이번 범위 밖이다.

## Delayed dispatch: 중복 요청과 동일 deadline 순서

calloutEntryDispatchDelayed의 stack ABI는 entry와 64-bit deadline의 low/high words다. status 검사가 인자·deadline 쓰기보다 먼저이며 **status!=0이면 기존 deadline과 current argument를 유지하고 반환한다.** 자동 remove/reinsert 또는 deadline 갱신이 아니다. 70차의 set_timeout은 이 backend 호출 뒤 외부 set=1을 무조건 기록하므로 그 store를 새 deadline 채택의 증거로 해석하지 않는다.

status=0이면 default argument를 복사하고 unsigned high/low 비교로 delayed 목록에 삽입한 뒤 status=2로 만든다. 첫 번째로 만난 더 큰 deadline 앞에 넣되, 같은 deadline을 만나면 그 항목 **바로 뒤**에 삽입한다. 같은 deadline 전체 묶음의 마지막까지 지나가지 않으므로 동일 deadline의 FIFO를 보장하는 구현은 아니다.

새 entry가 delayed head일 때만 clock_value(1)를 읽고 timer를 다시 설정한다. 이미 지난 deadline은 interval=0, 그렇지 않으면 unsigned 64-bit 차이를 구한 뒤 timer_attributes(0)의 첫 64-bit 값으로 상한 제한한다. backend lock을 유지한 채 set_timer(0,interval)을 호출하고 마지막에 unlock/splx한다. 정확히 같은 시각은 차이 0 경로다. 반환 상태 검사는 없다.

## Remove의 보장과 비보장

calloutEntryRemove는 splsched/backend lock 아래 위 상태표대로 동작한다. 정상 unlink 이후 status=0으로 만들고, entry 주소가 pool 범위 안이면 free queue에 반환한다. raw 비교는 unsigned 하한 포함·상한 제외다. 주소 범위 검사만 있으며 stride 정렬·정확한 entry 시작 주소·queue membership을 추가 검증하지 않는다.

외부 entry는 unlink 후 자기 link를 self-link로 되돌리지 않는다. callback/current/default argument/deadline 필드도 지우지 않는다. status 0 또는 다른 값이면 pool 반환도 하지 않는다. delayed head를 제거해도 이 함수 안에서는 set_timer로 다음 deadline을 갱신하거나 현재 timer deadline을 지우지 않는다. 이후 timer dispatch와 queue 재검사가 필요하다.

이 함수에는 in-flight callback을 찾거나 완료를 기다리는 경로가 없다. 따라서 backend remove와 70차 reset_timeout 모두 callback 완료 동기화 수단으로 채택할 수 없다. 아직 모든 호출자의 수명·직렬화 조건을 검증하지 않았으므로 이를 곧바로 실제 race 발생 증명으로 확대하지 않는다.

## 만료 전달: stack-local 목록의 status=0 구간

정적 연결은 다음과 같다.

`system_timer_dispatch → expire callback → delayed에서 임시 목록으로 이동 → pending 목록·wakeup → worker → timer adapter → thread_timeout`

FUN_00169f44는 clock_value(1)를 **splsched/backend lock 이전**에 읽어 기준 시각을 저장한다. delayed head부터 deadline<=그 기준 시각인 항목들을 제거하여 stack-local queue에 append하면서 status=0을 쓴다. 하나 꺼낼 때마다 기준 시각을 새로 읽지는 않는다.

delayed 목록이 남았으면 clock을 다시 읽어 다음 head의 interval을 계산하고 set_timer한다. 이 재측정 사이에 다음 항목이 만료되었더라도 현재 임시 목록으로 더 꺼내는 대신 interval=0으로 다음 timer 처리를 요청하는 경로다. delayed 목록이 비면 이 함수에서 새 timer를 설정하지 않는다.

그다음 임시 목록의 항목을 pending tail로 옮겨 count 증가와 status=1을 기록한다. **항목마다 backend lock을 풀고 wakeup을 호출한 뒤 다시 lock을 잡아 나머지 임시 목록을 처리한다.** 그러므로 아직 pending으로 옮기지 않은 항목은 status=0인 채 stack-local 목록에 남아 있는 unlock 구간이 있다. Remove의 status=0 no-op만으로 이 항목의 전달을 취소했다고 볼 수 없다.

이 관찰은 원본 store/branch/unlock 순서다. 다른 CPU나 callback에서 해당 entry에 재등록·free·remove가 실제로 도달할 수 있는지는 interrupt 수준, caller lock, 객체 수명을 더 검증해야 한다. 그 조건을 확인하지 않고 모든 경우에 안전하다거나 실제 경합이 발생한다고 단정하지 않는다.

## Worker: callback 인자와 pool 재사용 시점

FUN_0016a140은 current thread에 stack_privilege를 적용하고 FUN_00169cb0으로 들어간다. worker는 splsched/backend lock 아래 pending count가 signed 양수일 동안 head를 꺼낸다. count가 양수인데 queue가 비어 있으면 NULL을 얻은 뒤 callback 필드를 읽는 경로가 있으므로 count/queue 일치가 필수 caller/producer 불변식이다. 원본에 이를 복구하는 검사는 없다.

0x169d1d에서 callback(+8), 0x169d20에서 current argument(+0xc)를 register에 저장하고 status=0으로 만든다. pool entry이면 free queue에 **callback 호출 전** 반환하고 두 번째 callback 인자를 NULL로 만든다. 외부 entry이면 두 번째 인자는 entry 자신이다. raw PUSH EBX, PUSH ESI, CALL EDI로 callback(current_argument, external_entry_or_NULL)가 확인된다.

active count 증가 → backend unlock → spl0 → 저장한 callback 호출 → splsched → backend lock 재획득 → active count 감소 순서다. callback/argument를 unlock 뒤 entry에서 다시 읽지 않는다. pool이 callback 중 재사용될 수 있도록 저장값과 entry lifetime을 분리한 모양이며, 실제 동시 재사용의 안전성 전체를 증명한 것은 아니다. 70차 timer adapter는 첫 인자로 자기 timer를 받아 user callback/parameter를 다시 저장하고 별도 timer lock 밖에서 사용자 callback을 호출한다.

pending이 없어지면 signed `worker_count - active_count <= 4`일 때 pending count 주소에 assert_wait(event,0)를 설정하고 unlock한 뒤 자기 continuation을 넘겨 block한다. 그 외 경로는 worker count 감소, unlock/spl0, 저장한 current thread에 thread_terminate와 thread_halt_self를 호출한다. block 호출 다음에는 종료 경로로 fall-through하는 실제 명령이 있다. 이를 안전한 일반 C의 반환 호출로 치환하지 않으며 continuation의 비복귀/stack 교체 계약은 후속 scheduler 분석 사항이다.

Ghidra C는 worker의 lock 획득 store를 루프 뒤에 있는 것처럼 표현한다. raw XCHG 획득·재시도 위치를 기준으로 하며 C의 배치를 그대로 복원하지 않는다.

## Worker creator의 생존 조건

creator entry FUN_00169ea0은 stack_privilege 후 creator continuation과 같은 생성/대기 논리를 수행한다. FUN_00169e0c는 current thread를 읽고 splsched/backend lock을 얻어 signed `worker_count < active_count + pending_count`이면 worker count를 먼저 증가시킨다. unlock 후 kernel_thread(current_thread->task,FUN_0016a140,0)를 호출하고 자기 continuation으로 block한다.

생성 결과를 검사하거나 실패 시 count를 되돌리는 코드는 이 본문에 없다. 부족하지 않으면 worker count 주소에 assert_wait(event,0), unlock, block 순서다. 생성 뒤 block이 보통 함수처럼 반환하면 아래 assert_wait/unlock으로 이어지는 명령이 있으므로 실제 continuation 비복귀 조건 확인이 중요하다. native worker 실행, 생성 실패, thread terminate/stack privilege 내부까지 이번에 검증했다고 주장하지 않는다.

## Clock ID와 초기 ns_per_tick

clock_value는 어떤 ID든 먼저 FUN_00187d48을 호출한다. ID 1은 결과 EDX:EAX를 그대로 반환하고, ID 0은 0x1f63e0/0x1f63e4의 64-bit offset을 ADD/ADC로 더한다. 다른 ID는 EAX와 EDX 모두 0으로 만든다. Ghidra의 `int` 반환과 low-word 덧셈만 채택하면 상위 word를 잃는다. ID 1을 이번에는 offset을 더하지 않는 보간 clock으로 확인했으며 실제 단조성·epoch 전체를 보장하지 않는다.

ns_hardclock_init은 signed IDIV로 `1000000000 / hz`를 구하고 DWORD quotient를 sign-extend하여 ns_per_tick low/high 전역에 순차 저장한다. hz==0 guard는 없다. 파일 초기 hz는 Python 해독으로 100이며, 이 값이 유지된다는 조건에서 ns_per_tick은 10000000이다. 실제 boot 시 hz의 값·전체 writer 검증을 대신하지 않는다. hardclock_init에 low/high를 PUSH하지만 해당 callee 본문은 인자를 읽지 않고 0x1e75e8=1만 저장한다.

## Timer 설정: 64-bit 반올림과 overflow 경계

timer_attributes는 ID 0에 대해서만 0x1d14cc를 반환하고 다른 ID에는 NULL을 반환한다. 파일 초기 데이터의 첫 64-bit 값은 0xffffffffffffffff, 다음 64-bit 값은 10000000이다. delayed/expire 경로는 첫 값을 interval 상한으로 사용한다. 데이터의 실제 runtime 불변성과 전체 type 선언은 별도 검증 대상이다.

set_timer는 ID!=0이면 아무 설정도 하지 않는다. ID 0이면 interval에 9999999를 ADD/ADC한 뒤 __udivdi3(합,10000000)를 호출한다. 후속 SHLD/SHL/SUB/SBB/ADD/ADC 묶음의 계수는 Python으로 10000000임을 확인했다. unsigned division ABI를 전제로 한 수식은 다음과 같다.

`q = ((interval + 9999999) mod 2^64) // 10000000`

`deadline = (base_counter + q * 10000000) mod 2^64`

__udivdi3 본문은 이번 범위 밖이므로 나눗셈 callee의 완전한 구현 검증이라고 표시하지 않는다. base counter는 0x1e75d0/0x1e75d4이며 splusclock 뒤 읽어 deadline 0x1e75dc/0x1e75e0에 저장하고 splx한다. 보간 clock_value를 다시 호출해 base로 쓰는 함수가 아니다. 이 함수 본문에는 hardware OUT이나 즉시 callback 호출이 없다.

수식상 interval=1이면 delta=10000000, interval=10000001이면 delta=20000000이다. 하지만 큰 값에서는 더하기가 wrap되므로 무조건적인 수학적 ceil/saturating clamp라고 표현하면 틀린다. 예를 들어 interval=0xffffffffffffffff의 wrapped numerator는 0x98967e이고 q=0이다. Python으로만 계산한 조건부 예시이며 실제 timer 실행 결과가 아니다. overflow 거부나 saturation 분기는 원본 본문에 없다.

## System timer와 보간 입력

system_timer_dispatch는 base counter에 10000000을 ADD/ADC하고 이전 counter snapshot word를 reload word로 갱신한다. optional saved-state로부터 +0x38, +0x3c low bits 또는 +0x42 bit를 사용해 지역 인자를 준비하고 0x1e75e8이 비영이면 FUN_00187938을 호출한다. 이 hardclock callback 내부와 saved-state ABI 전수 검증은 남는다.

등록된 expire callback이 비NULL이고 deadline이 64-bit 0이 아니며 deadline<=현재 base이면, deadline low/high를 먼저 0으로 만들고 저장한 callback에 `(0,0,0)`을 PUSH하여 호출한다. 따라서 deadline=0은 여기서 비활성 sentinel이다. set_timer interval=0은 즉시 callback을 호출하지 않고 base를 저장하므로 base 자체가 0인 특수 상태도 구별해야 한다. 실제 IRQ 진입·serialization·지연은 이번 wrapper만으로 증명하지 않는다.

FUN_00187d48은 splusclock 아래 base low/high와 이전 counter word를 저장한다. OUT DX,AL로 port 0x43에 0을 쓰고, lock-prefixed increment를 수행한 뒤 0x1d14a0에서 읽은 port로 IN을 두 번 수행하여 low/high byte를 합친다. 해당 port의 파일 초기값은 0x40이다. Ghidra가 상수 IN(0x40)로 표시해도 raw는 global word를 읽는다.

새 counter를 전역에 저장하고 splx한 뒤, 새 값이 이전 값보다 unsigned 크게 보이면 지역 base에 10000000을 보정한다. 그 후 reload word를 다시 읽어 `reload - counter` DWORD를 CDQ로 sign-extend한다. shift/add 계수는 Python 계산으로 1000000000, unsigned division 호출의 divisor는 1193167이다. 나눗셈 결과를 지역 base에 ADD/ADC하여 EDX:EAX로 반환한다. reload>=counter가 깨지는 입력에는 정상 양수 보간 수식을 무조건 적용할 수 없다. counter 초기화, wrap 검출의 실제 정확성, IRQ 간섭, hardware frequency와 전체 writer는 후속 검증 대상이다.

## 보존·해석 한계

register-only busy loop 9곳은 각 JNZ 75fc가 memory load가 아니라 같은 register TEST로 돌아가는 것을 검증했다. EAX뿐 아니라 EDX load 경로도 포함했다. 이는 기존 관찰의 추가 위치 확인이지 모든 lock 형태의 전수 검사나 native 진행성 증명은 아니다.

Ghidra WARNING 3개는 calloutInitialize, clock_value, 보간 helper의 겹치는 global 심볼 경고다. 경고가 없는 C에도 lock 위치·64-bit 반환·간접 callback 인자 해석 문제가 있으므로 성공적인 디컴파일을 의미 검증 완료로 취급하지 않는다.

Darwin mach_clock.c/time_out.h의 service_timer와 바깥 set/reset은 비교했지만 참고 구현은 thread_call/tvalspec 경로다. 원본 callout의 상태·queue·64-bit clock을 그 구조체로 바꾸지 않는다. 참고 소스 이름만으로 원본 내부 ABI·동시성 계약을 채우지 않았다. 원본·참고 소스·DB·export·기존 확정 보고서·07_kernel은 보존했으며 전체 원본 분석·복원·GCC 2.7 실컴파일·부팅은 계속 미완료다.

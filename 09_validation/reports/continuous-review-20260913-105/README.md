# 105차 — 스택 통계 호출자와 RW lock·sleep·SPL 계약

원본 OPENSTEP x86 mk-183.34.4만 대조했다. 104차에서 남긴 통계 출력 초기화는
호출자가 기존 max 값으로 초기화하는 것으로 확인했다. cache lock의 필드·획득·해제,
read/write 전환의 서로 다른 실패 계약, sleep 등록과 IRQ 관련 원본 명령을 연결했다.
이 검토만으로 freeStack의 전체 동시성이나 하위 VM 성공을 확정하지 않는다.

## 검증과 자료

104차 fresh 검증을 다시 통과한 뒤 현재 검토를 진행했다. 일반 본문 23개와 기존 fragment
14개, 명령 head 1459개, 본문 3947바이트를 Python/Capstone으로 원본에서 재해독했다.
직접 분기 216개, 직접 CALL 31개, 간접 이동 6개, Ghidra 경고 8줄을 보존했고,
핵심 명령 160개에 별도 assertion을 적용했다. 이 수치는 선택 범위이지 전체 coverage가 아니다.

원본 SHA-256은
`33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다.
현재 입력 118개, 이전 보존 경로 929개를 검사했다. 원본/기존 DB/export/확정 보고서는
변경하지 않았다. 다른 소스·외부 자료는 참조하지 않았고 모든 계산은 Python으로 수행했다.

[명령·계산 증거](object-lifetime-evidence.json) · [검증 checkpoint](checkpoint.json) ·
[보존](preservation.json) · [범위](SCOPE.md) · [디컴파일 주의점](DECOMPILER_ISSUES.md) ·
[남은 분석](OPEN_ITEMS.md)

## 1. lock의 실제 필드와 초기화

`L`은 lock 인자 주소다. 아래 이름은 원본 접근 폭과 분기에서 얻은 분석상 표기이며,
다른 커널의 구조체 정의를 가져온 것이 아니다.

| 위치 | 원본에서 확인한 용도 |
|---|---|
| L+0, DWORD | recursive thread identity, 초기 0xffffffff |
| L+4, WORD | reader count, INC/DEC는 WORD 폭 |
| L+6, WORD의 상위 12비트 | recursive depth, 0x10 단위 가감 |
| L+6, BYTE의 bit 0x1 | read→write upgrade 표시 |
| 같은 BYTE의 bit 0x2 | write 표시/예약 |
| 같은 BYTE의 bit 0x4 | sleeping waiter 표시 |
| 같은 BYTE의 bit 0x8 | 일반 대기 경로의 sleep 허용 표시 |
| L+8, DWORD | 위 필드를 보호하는 내부 interlock |

`lock_init` 0x15b54c는 bzero(L,12)를 호출하고 count/interlock/flags를 설정한다.
L+0=0xffffffff, sleep bit는 인자의 **최하위 1비트만** 사용한다. 따라서 단순한
인자 nonzero 판정이 아니다. 마지막 WORD mask는 0xf여서 recursive depth가 지워진다.
`lock_sleepable` 0x15b594도 interlock 아래 같은 최하위 비트 방식으로 bit 0x8만 바꾼다.

bzero 0x101600→memset 0x101630의 실제 인자를 확인했다. 정확히 size=12/value=0인
경로는 원본 jump table에서 0x1016ff로 진입하여 L+8, L+4, L+0에 DWORD를 쓴다.
Python으로 쓰기 구간의 합집합이 정확히 12바이트임을 확인했다.
memset의 모든 호출 값·큰 길이·overflow까지 의미 검토를 완료한 것은 아니다.

`initKernelStacks` 0x15ab9c가 이 초기화를 cache lock 0x1f63d0과 인자 1로 호출하므로,
초기화가 정상 완료되고 이후 변경되지 않았다는 조건에서 cache lock은 sleep bit가 켜져 있다.
lock 내부 interlock은 0x1f63d8이다. L+0은 정상 write 획득마다 자동으로 thread를
기록하는 일반 owner 필드가 아니다. 아래 recursive API와 구분해야 한다.

## 2. write/read/done의 실제 순서

`lock_write` 0x15b5d0은 L+8 interlock을 획득한 뒤 L+0과 active thread를 비교한다.
같으면 recursive depth만 증가시킨다. 다르면 먼저 기존 write bit가 지워지기를 기다리고,
0x15b69a에서 write bit를 설정한 후 `DWORD[L+4]&0x1ffff`가 0이 되기를 기다린다.
이 mask는 reader WORD와 upgrade bit를 함께 검사한다. 모든 write 대기를 단순 reader
count 검사라고 읽지 않는다. 함수 반환 전에는 내부 interlock을 풀지만 write 표시는 남는다.

`lock_read` 0x15b7d0은 recursive identity가 같거나 flag bits 0x3이 없으면
0x15b87e에서 reader WORD를 증가시킨다. 아니면 write/upgrade 표시가 없어지기를 기다린다.
동일 identity의 read 진입도 여기서는 recursive depth가 아니라 reader count에 반영된다.

`lock_done` 0x15b73c의 우선순위는 reader count가 있으면 그 WORD 감소,
없고 recursive depth가 있으면 depth 감소, 둘 다 없으면 upgrade 표시 또는 write 표시를
지우는 순서다. 임의로 전달한 lock의 소유 thread를 자체 확인하는 일반 unlock 함수라고
해석하지 않는다. 해제 호출의 정당성은 caller 계약이다.

이후 `(DWORD[L+4]&0x4ffff)==0x40000`이면 waiter bit를 지우고
0x15b7bd에서 thread_wakeup_prim(L,0,0)을 호출한다. 즉 reader count 0과 waiter bit를
검사하지만 이 mask 자체가 모든 다른 flag/depth도 0인지 확인하는 것은 아니다.
wakeup 호출은 아직 L+8을 보유한 상태이고, 0x15b7c4에서 interlock을 해제한다.

WORD reader의 가감과 recursive 부분의 가감은 saturation 검사가 아니다.
Python으로 WORD 입력 전체 65536개에 대해 low flags 보존과 상위 12비트 modulo 가감을
검사했다. reader 0의 DEC나 최대 WORD의 INC, recursive 최댓값의 증가에는 wrap이 생긴다.
정상 caller가 해당 경계에 도달한다거나 실제 overflow 결함이 발생했다고 주장하지 않는다.

## 3. upgrade와 try의 반환값·실패 후 보유 상태

| 함수 | 완료 시 반환 | 충돌 시 반환과 read 보유 | 대기 경로 |
|---|---|---|---|
| lock_read_to_write 0x15b890 | 0 | upgrade 표시가 이미 있으면 1; 진입 때 reader를 먼저 감소시켜 read를 돌려주지 않음 | 일반 sleep bit/대기 경로 사용 |
| lock_try_read_to_write 0x15bae8 | 1 | upgrade 표시가 이미 있으면 0; 이 실패 경로에서는 reader 감소 전이라 기존 read 유지 | upgrade를 선점했지만 다른 reader가 남으면 thread_sleep 호출 가능 |
| lock_try_write 0x15ba2c | 1 | busy이면 0 | sleep CALL은 없지만 내부 interlock spin은 있음 |
| lock_try_read 0x15ba98 | 1 | write/upgrade busy이면 0 | sleep CALL은 없지만 내부 interlock spin은 있음 |

일반 upgrade는 0x15b8b0에서 reader를 먼저 감소시킨 뒤 identity/upgrade 충돌을 검사한다.
충돌 경로는 필요하면 wakeup한 다음 1을 반환한다. 따라서 실패 후 caller가 여전히 read를
소유한다고 가정하면 안 된다. 반대로 try upgrade의 충돌 검사는 0x15bb33이며,
충돌하지 않을 때에만 0x15bb4d에서 reader WORD를 감소시킨다.

**try upgrade는 무조건 비수면 함수가 아니다.** 기존 reader count가 1이 아니면
0x15bb5c에서 waiter bit를 세우고 0x15bb64에서 thread_sleep(L,L+8,0)을 호출한다.
이 경로에는 bit 0x8 검사도 없다. 다른 reader가 사라질 때까지 재획득/대기가 반복될 수 있다.
원본의 `try` 이름에서 비차단·유한 시간·sleep 불가를 보충하지 않는다.

try_write는 `DWORD[L+4]&0x3ffff`를 검사하므로 reader/upgrade/write를 함께 검사한다.
try_read는 BYTE flag bits 0x3을 검사한다. recursive identity 일치 경로는 각각 depth 증가,
reader 증가로 바로 이어진다. 내부 interlock 자체의 진행성은 별도 조건이다.

`lock_write_to_read` 0x15b9b0은 reader WORD를 먼저 증가시키고 depth 또는
upgrade/write 표시를 줄인다. waiter bit가 있으면 reader 증가 후에도 wakeup한다.
이는 lock_done의 reader==0 wakeup 조건과 동일한 계약이 아니다.

`lock_set_recursive` 0x15bb9c는 write bit가 없으면 panic을 호출하고, 있으면
L+0에 active thread를 게시한다. `lock_clear_recursive` 0x15bbe0는 identity 불일치에
panic을 호출하며 depth가 0일 때만 L+0을 0xffffffff로 되돌린다.
일반 write/done이 이 identity를 자동 설정/해제한다고 추론하지 않는다.

## 4. spin과 유한 지연 loop를 분리

여러 내부 interlock 경로의 원본은 MOV memory→EAX 뒤 TEST EAX,EAX,
JNZ→같은 TEST이다. NOP를 허용하면 선택 본문에서 30개, 엄격한 인접 패턴은 29개다.
backedge는 메모리 load로 돌아가지 않는다. C의 repeated-memory while 표현을 그대로
진행성 모델로 쓰지 않는다. XCHG old-value가 1이면 load 지점부터 재시도하는 별도
경로는 유지해서 기록했다. 값 0/1 불변식 자체와 native IRQ/경쟁의 영향은 미완료다.

별도로 lock_write/read/upgrade의 유한 지연 loop 4개는 EDX를 감소시키면서
미리 읽은 AL/EAX/AX의 상태를 TEST한다. 예: 0x15b638 load 뒤 backedge
0x15b647→0x15b640에는 새 상태 load가 없다. 이들은 counter가 줄어드는 loop이므로
위 무조건 같은 TEST spin과 동일한 패턴으로 합산하지 않았다.

파일의 lock_wait_time 0x1deddc는 0이다. 해당 값이 유지되면 양수일 때만 실행하는
interlock 임시 해제/유한 지연 경로는 건너뛴다. 이 초기값을 모든 runtime 상태로
확정하지 않는다. 일반 read/write/upgrade는 sleep bit와 busy 조건을 다시 보고
필요하면 waiter bit를 세워 thread_sleep을 호출한다.

## 5. thread_sleep과 별도의 stack 고갈 event

`thread_sleep` 0x163320은 event, 해제할 interlock 주소, interruptible 인자를 받는다.
active thread에 기존 T+0x3c event가 있으면 panic 경로다. splsched 후 nonzero event를
hash bucket에 넣고 T+0/T+4 링크, T+0x3c event, T+0x4c 상태를 게시한다.
interruptible=0인 호출은 상태 BYTE에 0x9를 합치고, nonzero는 0x1을 합친다.

중요한 원본 순서는 다음과 같다.

1. bucket lock과 T+0x20 lock 아래에서 대기열/event/state 게시.
2. T lock 및 bucket lock 해제.
3. **0x16342d에서 splx로 이전 수준 복원.**
4. **0x16343a에서 전달받은 interlock을 XCHG 0으로 해제.**
5. 0x16343e에서 thread_block_with_continuation(0) 호출.

thread_sleep는 전달받은 interlock을 자체 재획득하지 않는다. RW lock의 caller가
복귀 후 다시 L+8을 획득한다. splx에는 아래의 STI/간접 callback 가능성이 있으므로
위 전체 구간을 IF=0인 하나의 atomic 동작으로 표현하지 않는다. 이 순서만으로 실제
deadlock/lost wakeup을 판정하지는 않는다. callback/IRQ caller 전제를 더 닫아야 한다.

`assert_wait` 0x162f20은 같은 계열의 등록/상태 게시와 spl 복원을 수행하지만,
전달받은 lock의 해제나 block을 수행하지 않는다. 따라서 104차 allocStack의
assert_wait(head,0)→waiter flag→cache unlock→thread_block과,
RW lock 내부의 thread_sleep(L,L+8,0)은 서로 다른 계약이다.

Python으로 계산한 event hash와 queue는 다음과 같다.

| 용도 | event | bucket | queue sentinel |
|---|---|---:|---|
| cache lock 경합 | 0x1f63d0 | 15 | 0x1f6a88 |
| 스택 고갈 | 0x1e5b98 | 48 | 0x1f6b90 |

음수 DWORD event는 NOT 후 양수 값으로 나누며 abs가 아니다. bucket 수는 59다.
event=0의 wait는 T 상태만 바꾸고 이 함수들에서 bucket에 등록하지 않는다.
hash 충돌 시에는 wakeup이 T+0x3c의 전체 event 값으로 다시 일치 검사한다.

`thread_wakeup_prim` 0x1631a0은 일치 thread를 목록에서 제거하고 event를 지운 뒤,
필요하면 timeout을 취소한다. low state 1/9/0xb는 wait bit를 지우고 runnable bit를
세워 setrun, 3/5/7/0xd/0xf는 wait bit만 지운다. result는 T+0x44에 게시한다.
그 외 low state는 panic 경로다. 두 번째 인자 0이면 일치 thread들을 계속 찾고,
nonzero이면 하나를 처리한 뒤 멈춘다. 하위 timeout/setrun/실제 block 복귀는 이번에
전체 재검토하지 않았으며 native wakeup 성공·완료 시간을 보장하지 않는다.

## 6. splsched/splx: 수준, IF, callback, 포트 쓰기

`splsched` 0x18be68은 CLI 후 현재 수준 0x1e7714를 6으로 게시하고 이전 값을 보존한다.
이전 수준이 더 높으면 pending slot을 내려가며 처리할 수 있다.
slot의 callback record는 +0=context, +4=code, +8=level로 소비되며,
원본은 slot을 지우고 record level을 게시한 뒤 STI, CALL(context,0,6), CLI 순서다.
record의 소유권/validity와 전체 slot writer는 아직 닫지 않았다.

그 뒤 필요한 경우 mask WORD를 합쳐 0x21/0xa1 포트에 각각 OUT하고,
각 OUT 다음에 통계 DWORD를 LOCK INC한다. **mask shadow 0x1e771c 쓰기는 OUT보다
앞선다.** C는 shadow 쓰기를 뒤로 옮기고 두 INC를 합쳐 표현한다.
마지막 0x18bf29의 STI 후 이전 수준을 EAX로 반환한다. 원래 IF를 저장해 그대로
복구하는 함수가 아니며, splsched 반환 상태를 단순 CLI 유지 상태로 해석하면 안 된다.

`splx` 0x18b544도 CLI 후 요청 수준을 먼저 게시하고, 필요한 pending callback 처리와
mask 갱신을 거쳐 0x18b5fd에서 STI한다. callback 인자는 context,0,요청 수준이다.
요청 수준의 자체 범위 검사는 없으며 pending/mask indexing은 caller의 유효 수준 전제를
필요로 한다. hardware interrupt mask가 차단하는 원인과 CPU IF는 별개로 다뤄야 한다.

RW lock family의 자체 명령에는 CLI/STI/PUSHF/POPF가 없다. 그렇다고 API 전체가
IF를 보존한다고 판정할 수는 없다. sleep/wakeup을 호출하면 이 SPL 경로로 들어간다.
이번 SPL C에는 CLI/STI가 누락되며, 수준·mask 게시 시점도 원본으로 재확인해야 한다.
SPL globals/mask table은 zerofill section으로 확인하여 파일 초기값을 부여하지 않았다.

## 7. host_stack_usage가 통계 출력을 초기화한다

`host_stack_usage` 0x168bb8은 물리 스택 인자 7개를 소비한다. 첫 인자 0이면
0x16을 반환하고 출력들은 건드리지 않는다. nonzero를 받는다는 것 외에 host 객체를
자체 검증하는 추가 경로는 이 본문에 없다.

유효 경로는 stack_usage_lock을 잡아 0x1dfbc8 max 값을 local에 복사하고
**0x168bfa에서 그 lock을 해제한 뒤** stack_statistics(&count,&local_max)를 호출한다.
따라서 104차의 두 번째 출력 기존값 비교는 여기서는 미초기화 local 사용이 아니다.
max snapshot과 cache count/usage 조사는 다른 잠금 구간이므로 하나의 동시 snapshot을
얻었다는 증거도 아니다. 두 lock을 동시에 잡는 순서로 표현하지 않는다.

| 물리 인자 | 성공 시 출력 |
|---|---|
| 2 | 0 |
| 3 | cache count |
| 4와 5 | DWORD(count*0xff4+page_mask)&~page_mask |
| 6 | 초기 max와 cache 사용량 비교 후의 local max |
| 7 | 0 |

shift/sub/LEA 연쇄를 Python으로 대조하여 곱셈 계수가 0xff4임을 확인했다.
이는 header 포함 stride 0x1000이나 stackStats의 실제 페이지 수를 곧바로 보고하는
식이 아니다. cache의 배치·혼합 사용 페이지·하위 residency를 모르는 상태에서
물리 메모리 사용량이라고 확정하지 않는다. 산술은 DWORD wrap이며 그 검사도 없다.

stack_check_usage와 max의 파일 초기값은 0이다. 지정 literal 조사에서 max의 명시
writer는 stack_finalize에서 확인했다. alias/디버거/runtime patch/함수 밖 writer를
닫지 않았으므로 flag가 영원히 0이라고 판정하지 않는다.

## 8. 조사 한계와 다음 작업

manifest에 일치하는 ASM 5253개에서 지정 direct CALL 9개, 지정 global literal 참조
38개를 추출해 각 명령을 raw decode했다. host_stack_usage 호출 0x171bcd와
recursive API의 VM 관련 caller들이 확인됐다. lock_sleepable/try_read_to_write의
지정 direct CALL은 검출되지 않았지만 간접 호출·주소 참조를 닫지 않아 미사용 판정은 아니다.

104차의 freeStack unlock 후 page scan/removal, swapout/swapin의 VM 호출 경계는
여전히 caller와 IRQ·VM 수명 전제가 필요하다. 이번에 RW lock 이름 뒤의 실제 처리를
밝혔다고 그 전제가 모두 충족된 것은 아니다.

Ghidra 스킬의 원본 대조를 기존 export/raw 파일에 적용했다. 신규 독립 Codex 계획 검토는
받지 않았고 재시도/대체 agent로 우회하지 않았다. 분석 코드 파일이나 kernel 구현은
추가하지 않고 inline Python과 이 보고서만 사용했다.
선택 범위의 정적 검증은 통과했으며 **전체 원본 분석 목표는 미완료**다.

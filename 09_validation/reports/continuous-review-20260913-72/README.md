# Callout API 소유권·중복 처리와 실제 caller

남은 공개 callout API 본문과 실제 재등록·해제 caller를 연결했다. **Allocate는 포인터 반환이며, Unique는 pending 목록만 검사한다.** Free의 status==0 검사는 callback 실행 완료를 뜻하지 않는다. WithArgument는 기본 인자를 바꾸지 않고 이번 dispatch 인자만 바꾸며, Remove의 검색 키는 그 현재 인자다.

Ghidra 스킬로 전체 보존 ASM/C/metadata를 대조하고 Python으로 원본 Mach-O 주소/파일 매핑·명령어·직접 제어 이전·해시·집계를 검증했다. [증거](callout-api-evidence.json), [보존 목록](preservation.json), [남은 분석](OPEN_ITEMS.md)을 남긴다. 71차 체크포인트와 입력을 다시 검증했다. 신규 독립 계획 교차검토·구현·새 실행 검증 프로그램·동적 실행·GCC 2.7 실컴파일은 수행하지 않았고 이전 실패 검토를 재요청하거나 우회하지 않았다.

## 범위와 본문 목록

Python 집계는 함수 본문 14개, 명령어 752개, 2395바이트, 직접 분기 101개, 직접 호출 48개, 간접 제어 이전 0개다. 명시적 Ghidra WARNING 4개와 register-only busy loop 8곳을 보존했다. 입력 49개와 이전 보존 파일 744개를 해시 검증했다.

| 함수 | 주소 | 명령어 | 본문 바이트 |
|---|---|---:|---:|
| calloutEntryAllocate | 0x169784 | 20 | 61 |
| calloutEntryFree | 0x1697c4 | 35 | 98 |
| calloutDispatch | 0x169208 | 47 | 187 |
| calloutDispatchUnique | 0x1692d8 | 70 | 251 |
| calloutDispatchDelayed | 0x1693ec | 126 | 372 |
| calloutRemove | 0x16957c | 79 | 235 |
| calloutRemoveAll | 0x16966c | 88 | 276 |
| calloutEntryDispatchWithArgument | 0x1698b8 | 42 | 138 |
| calloutEntryDispatchWithArgumentDelayed | 0x169a80 | 112 | 310 |
| lightning_bolt | 0x102ea4 | 27 | 72 |
| logopen | 0x10bd48 | 34 | 134 |
| logclose | 0x10bdd4 | 26 | 109 |
| logwakeup | 0x10bf74 | 10 | 27 |
| FUN_0010bf90: log callback | 0x10bf90 | 36 | 125 |

full-pass5 functions.json에서 이름이 `_callout`으로 시작하는 export 14개를 Python으로 추출하여 [70차](../continuous-review-20260913-70/README.md)·[71차](../continuous-review-20260913-71/README.md)·이번 본문 검토에 모두 매핑했다. 매핑은 증거의 named_callout_body_coverage에 있고 각 행의 transitive_semantics_complete는 false다. 이것은 해당 이름의 export 본문 누락을 확인한 결과이지 미식별 코드·모든 caller·실행 경합을 포함한 callout 전체 완료 선언이 아니다.

## 할당: Ghidra의 void 반환을 채택하지 않는다

calloutEntryAllocate(callback,default_argument)는 kalloc(0x20)을 호출한다. 원본 EAX가 가리키는 entry에 +8=callback, +0xc=0, +0x10=default_argument, +0x14/+0x18=0, +0x1c=0을 저장하고 EAX를 변경하지 않은 채 반환한다. Python으로 확인한 할당 크기는 32바이트다. +0/+4의 queue link는 이 함수에서 초기화하지 않는다.

원본에는 kalloc 결과 NULL 검사, callback NULL 검사 또는 전체 저장소 zero-fill이 없다. 0x169791의 호출 바로 다음 0x169796부터 EAX를 역참조한다. 실제 allocator의 성공/실패·blocking 계약은 별도 callee 검증이 필요하다.

Ghidra의 callee C는 void로 표시하지만 lightning_bolt는 0x102ecc에서 EAX를 EBX에 저장하고, logopen은 0x10bd86에서 EAX를 전역에 저장한다. 원본 반환 ABI와 caller 사용이 함께 포인터 반환을 뒷받침한다. 이를 근거로 실제 GCC 2.7 타입 선언까지 이미 검증했다고 주장하지는 않는다.

## 해제: status 검사와 객체 수명은 별개

calloutEntryFree는 splsched/backend lock 아래 entry+0x1c를 검사한다. status!=0이면 backend lock을 풀고 panic("calloutEntryFree")으로 간다. 이 panic 경로는 splx를 먼저 하지 않는다. status==0이면 backend unlock → splx → kfree(entry,0x20) 순서다.

이 함수는 pool 범위 검사, allocation provenance 검사, refcount, NULL 검사, remove 또는 callback 완료 대기를 하지 않는다. kfree는 backend lock 밖에서 실행된다. 따라서 아무 status=0 pointer나 Free해도 된다는 계약이 아니며 heap에서 Allocate한 entry와 정적 pool entry를 구별해야 한다.

71차에서 worker는 callback 호출 전에 status=0을 기록하고, expire의 임시 목록도 status=0을 사용함을 확인했다. Free의 허용 조건 하나만으로 다른 코드가 해당 entry를 더는 참조하지 않는다고 증명할 수 없다. 반대로 callback이 entry를 실제로 읽지 않는 경우까지 동일하게 잘못된 해제로 단정하지 않는다. caller별 객체 접근·직렬화·수명 검토가 필요하다.

## 일반 Dispatch: 정적 pool과 초기화 gate

calloutDispatch, calloutDispatchUnique, calloutDispatchDelayed는 초기화 guard 0x1dfcbc가 0이면 아무 등록 없이 반환한다. 이 경로에서 성공/오류 상태를 따로 구성하지 않는다. entry 기반 API와 Remove/RemoveAll에는 같은 초기화 gate가 없다. backend queue 초기화는 그 호출자의 전제다.

일반 Dispatch는 splsched/backend lock 아래 free queue에서 정적 pool entry를 얻는다. free queue가 비면 panic("internalEntryAllocate")이고, 이 본문에는 heap fallback·sleep·오류 반환·panic 전 backend unlock이 없다. 빈 queue 비교와 실제 head 읽기는 모두 backend 획득 뒤에 있다. Ghidra C가 piVar2=free_head를 lock 이전으로 끌어올린 표현을 원본 접근 순서로 채택하지 않는다.

entry+8=callback, +0xc=전달 인자, +0x10=0, deadline=0을 저장하고 pending tail에 append한다. count 증가와 status=1 이후 wake helper를 호출한다. 71차에서 검증한 helper가 backend lock을 풀므로 caller는 saved spl만 복원한다. callback NULL 검사는 없고 같은 callback/인자 요청을 자동 병합하지 않는다.

정적 pool entry는 worker가 꺼낼 때 callback 값을 저장한 다음 pool에 반환되며 callback의 두 번째 인자는 NULL이다. 반면 Allocate로 얻은 외부 entry는 callback에 자기 pointer가 전달되고 worker가 자동 kfree하지 않는다. 이 소유권 차이는 lightning_bolt caller에서 실제로 사용된다.

## Unique: 무엇을 중복으로 보는가

Unique는 backend lock 아래 pending queue만 순회하여 entry+8의 callback과 +0xc의 current argument가 모두 같은 항목을 찾는다. 발견하면 새 pool entry를 얻거나 wake helper를 부르지 않고 unlock/splx한다. 없으면 일반 Dispatch와 같은 할당·append 경로다.

검색에는 delayed queue, expire 임시 목록, 실행 중 callback, default argument(+0x10), deadline이 포함되지 않는다. pool 항목만 검사하는 범위 조건도 없어 pending에 있는 외부 entry가 같은 key라면 중복으로 본다. 따라서 이름만 보고 전체 시스템에 동일 callback이 하나만 존재하거나 동시에 실행되지 않는다고 결론 내리지 않는다.

## 일반 Delayed와 WithArgument 변형

일반 calloutDispatchDelayed의 stack words는 callback, argument, deadline low, deadline high다. pool에서 매번 새 entry를 얻고 callback/current argument/default=0/deadline을 기록한다. 중복 검색은 없다. signed 시간이 아니라 unsigned high/low 비교로 delayed queue에 삽입하고 status=2로 만든다.

같은 deadline을 만나면 그 첫 항목 바로 뒤에 넣는다. 동일 deadline 묶음의 tail까지 지나가지 않으므로 전체 동률 FIFO를 보장하지 않는다. 새 head일 때만 clock_value(1)와 timer_attributes(0)를 읽어 interval을 계산하고 set_timer(0,interval)을 호출한다. 지난 deadline은 0, 나머지는 unsigned 차이와 상한 비교이며 backend lock을 유지한다. 71차의 clock/rounding 한계가 그대로 적용된다.

| API | entry current argument(+0xc) | default(+0x10) | status!=0일 때 |
|---|---|---|---|
| EntryDispatch / EntryDispatchDelayed | default에서 복사 | 유지 | 기존 항목 유지 |
| EntryDispatchWithArgument | caller의 두 번째 인자 | 유지 | 인자 교체 없이 반환 |
| EntryDispatchWithArgumentDelayed | caller의 두 번째 인자 | 유지 | 인자·deadline 교체 없이 반환 |

WithArgumentDelayed는 entry, current argument, deadline low/high 순서의 stack ABI다. 두 변형 모두 status 검사가 모든 인자/deadline store보다 앞에 있다. 즉 이미 대기 중인 callback의 인자를 교체하는 API가 아니다. 이후 인자 없는 EntryDispatch를 호출하면 보존된 default를 다시 복사한다.

## Remove와 RemoveAll: 검색 범위·순서·재활용

두 함수의 key는 `(callback,current_argument)`이며 entry+8/+0xc를 비교한다. default argument나 callback pointer만으로 일치시키지 않는다. WithArgument 사용 후 기본 인자로 Remove하면 같은 entry를 찾는다고 보장할 수 없다.

Remove는 pending 목록의 첫 일치 항목을 우선 제거하고 즉시 마무리한다. pending에 없을 때만 delayed를 검색하며 그 첫 일치 항목을 제거한다. 전체 목록에서 시간상 가장 이른 항목을 선택하는 규칙이 아니다. RemoveAll은 pending 전체 다음 delayed 전체를 순회하여 두 key가 일치하는 항목들을 제거한다.

pending 제거는 count 감소를 동반하고 delayed 제거는 pending count를 바꾸지 않는다. 제거된 entry의 status는 0이 된다. 정적 pool 범위에 속하면 free queue로 돌려보내고 외부 entry는 kfree하지 않는다. 외부 entry의 link·callback·argument·deadline을 전부 지우지도 않는다. pool 판정은 unsigned 주소 범위 검사이며 정렬이나 할당 출처를 추가 검증하지 않는다.

RemoveAll은 각 일치 항목의 next를 ECX에 **먼저 저장**한다. entry를 free queue에 넣으면서 +0 link가 바뀌어도 0x1696fd/0x169760에서 저장한 ECX로 순회를 재개한다. 재활용한 entry의 새 free-list link를 따라가도록 복원하면 원본과 달라진다.

두 함수는 status 값으로 검색 대상을 거르는 대신 실제 pending/delayed queue를 순회한다. 실행 중 callback이나 expire의 stack-local 목록은 검색하지 않는다. callback 종료를 기다리거나 delayed head 제거 후 timer를 재설정하는 경로도 없다. 성공 개수·boolean 취소 확인을 명시적으로 반환하는 함수로 해석하지 않는다.

## lightning_bolt: 외부 entry를 이용한 재등록

원본은 첫 stack 인자를 사용하지 않고 두 번째 인자를 entry로 읽는다. thread_wakeup_prim(&lbolt,0,0)을 호출하고 entry가 NULL일 때만 Allocate(lightning_bolt,0)로 얻는다. 이후 calloutDeadlineFromInterval에 low=0x3b9aca00/high=0을 넘기고 반환된 EDX:EAX와 entry를 EntryDispatchDelayed에 전달한다. Python 해독으로 interval은 1000000000이다.

worker가 외부 entry를 두 번째 callback 인자로 전달하고 status를 미리 0으로 만드는 계약 때문에 같은 entry를 callback에서 재등록할 수 있다. 첫 인자가 아닌 두 번째 인자를 재사용하는 점이 중요하다. 기준은 이전 deadline에 interval을 더하는 방식이 아니라 callback 실행 시 clock_value를 이용한 새 deadline 계산이다. 따라서 정확한 고정 주기·지연 없음·실제 clock 실행까지 검증한 것으로 확대하지 않는다.

Darwin init_main.c에도 callback 인자로 callout을 받아 없으면 할당하는 대응 형태가 있지만, 참고 구현의 tvalspec과 thread_call을 원본의 64-bit ns/callout ABI로 그대로 대체하지 않는다.

## Log의 할당·등록·종료

logopen은 log_open이 비영이면 0x10을 반환한다. 그 외에는 대기 thread 전역을 0으로 만들고 current user 관련 구조에서 signed short 값을 읽어 process/group 전역에 저장한다. Allocate(FUN_0010bf90,0)의 EAX를 0x1e97cc에 저장한 뒤 log_open=1을 쓴다. 이 본문에는 별도 log lock, allocation NULL 검사, open gate의 원자적 경쟁 처리 코드가 없다.

message buffer magic이 다르면 magic과 index를 초기화하고 byte loop로 데이터를 비운다. 원본 CMP/JBE가 포함하는 byte 수는 Python 계산으로 4084다. log subsystem 전체 데이터 구조·read/select/ioctl 계약은 이 초기화만으로 완료하지 않는다.

logwakeup은 log_open을 검사한 뒤 전역 entry를 읽어 EntryDispatch한다. logclose는 log_open=0 → entry를 EBX에 저장 → 전역 entry=0 → EntryRemove(saved) → EntryFree(saved) 순서다. splhigh로 보호하는 대기 thread 전역 분리는 remove/free **이후**에 있다. 따라서 이 후반 splhigh가 앞선 전체 entry 해제를 보호한다고 설명하면 틀린다. close의 NULL entry 처리나 callback join도 없다.

종료 후 대기 thread 전역을 splhigh 아래 가져와 0으로 만들고 splx한 뒤 비NULL이면 thread_deallocate한다. log 상태와 process/group 전역도 정리한다. 전체 장치 close caller의 직렬화·open/close 재진입·IRQ/CPU 접근 규칙은 별도 검증 대상이다.

## Log callback: 인자 미사용과 전역 생존 조건

FUN_0010bf90은 entry/current argument를 stack에서 읽지 않는다. log_open이 0이면 즉시 반환한다. 비영이면 splhigh 아래 대기 thread 전역을 가져와 0으로 만든 후 splx하고, 저장값이 있으면 selwakeup(saved,0)와 thread_deallocate_interrupt(saved)를 호출한다.

그다음 상태 bit 0x4에 따라 gsignal(process/group,0x17), bit 0x8에 따라 wakeup(message_buffer)와 해당 bit 해제를 수행한다. log_open은 callback 진입에서 검사할 뿐 각 후속 작업 전에 다시 검사하지 않는다. 전체 selection·signal·wakeup callee와 보존 참조의 생성자는 아직 범위 밖이다.

따라서 log callback이 해제된 entry pointer를 반드시 역참조한다고 단정할 근거는 없다. 그러나 이 사실만으로 logwakeup/close 사이의 전역 pointer 읽기 경쟁이나 close/open 사이의 전역 상태 재사용까지 안전하다고 증명하지도 못한다. 외부 serialization과 실제 접근 가능 interleaving을 더 확인해야 한다.

Darwin subr_log.c의 logopen/close/wakeup은 LOG_LOCK과 selinfo 및 직접 wakeup 경로를 사용한다. 이번 원본의 할당된 callout entry·지연 callback·thread pointer 처리와 다르므로 참고 소스의 lock/소유권을 원본 사실로 섞지 않는다.

## 경고와 보존 한계

명시적 WARNING 4개는 Free와 일반 Dispatch/Unique/Delayed의 panic 비복귀 표기다. 경고가 없는 Allocate C의 void 반환도 ABI상 잘못된 표현이며, pool head read의 lock 앞 이동도 원본 ASM으로 바로잡아 해석했다.

register-only busy loop 8곳의 JNZ 75fc가 memory load가 아닌 register TEST로 되돌아가는 것을 원본에서 확인했다. load 주소는 0x1697d4, 0x169220, 0x1692f8, 0x16940c, 0x169590, 0x169684, 0x1698c8, 0x169a94다. EDX 경로도 포함한다. 전수 lock 검증·native 진행성·SMP 안전성의 증명은 아니다.

원본·참고 소스·DB·export·기존 확정 보고서·07_kernel은 보존했다. 공개 callout 이름의 본문 목록을 매핑했어도 모든 하위 callee·caller·경합·hardware·최종 GCC 2.7 구현/빌드/부팅은 계속 미완료다.

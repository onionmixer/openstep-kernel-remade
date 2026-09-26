# 97차 — PC 상태 전환·marker 소비자·타이머 취소와 수명

## 결과와 한계

96차에서 남긴 PC monitor/state/marker/timer 소비자를 원본 명령으로 대조했다.
이번 핵심 결과는 상태 전환의 CR0/IRETD 동작, 서로 다른 +0x74 객체,
타이머 대기열 취소와 이미 꺼낸 콜백의 실행을 구분한 것이다.
생성·해제와 콜백 실행의 지역 순서는 확인했으나, 실제 수명 오류의 발생이나
PC subsystem 전체 동작·원본 커널 전체 분석 완료를 주장하지 않는다.

원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
외부 코드 없이 기존 Ghidra export의 본문·호출·제어 이전을 원본 file bytes와 대조했다.
Ghidra 스킬은 C 서명/제어 흐름을 가정하지 않고 명령·폭을 확인하는 절차에 적용했다.
모든 계산은 Python이다. 새 독립 계획 검토는 없으며 통과로 세지 않았다.

Python 집계: 일반 본문 24개, synthetic fragment 1개, 총 25개 본문의
1,385개 instruction head/4,161바이트. 직접 분기 150개, 직접 CALL 83개,
간접 CALL 1개, 핵심 명령 221개를 재확인했다. 일반 state 매핑 24행,
segment 매핑 16행, marker 소비자 3개, register-only spin 패턴 4개를 기록했다.
C 경고는 1행이며, 경고 수가 의미 누락 수나 원본 결함 수라는 뜻은 아니다.
입력 81개와 기존 보존 경로 873개를 검사했다.

자료: [검토 범위](SCOPE.md), [명령·매핑·산식 증거](object-lifetime-evidence.json),
[C 의미 누락 목록](DECOMPILER_ISSUES.md), [보존 해시](preservation.json),
[체크포인트](checkpoint.json), [남은 분석](OPEN_ITEMS.md),
[이전 보고서](../continuous-review-20260913-96/README.md).

## 1. 객체 기준과 같은 offset의 다른 의미

T는 thread, P=`[T+0x28]` PCB, W=`[P+0xec]` wrapper,
M=`[W]` 공용 PC 상태, R=`M+0x88+[M+0x84]*0x84` 개별 레코드로 구분한다.
index는 unsigned 7 이하일 때 이 산식을 쓰며, 일부 소비자는 실패 시 R=0을 만든 뒤에도
R을 역참조한다. 이것은 NULL을 안전하게 처리하는 코드가 아니다. 유효한 등록/index가
호출 전에 보장되는지는 별도 문제다.

S는 saved user state이며, 관련 return 경로는 `[P+0x70]+0x84`를 쓴다.
P+0x70이 없으면 `thread_user_state`가 0xe0바이트 할당 후 S 부분에
원본 `0x1d15e0`의 0x17 DWORD/92바이트를 CLD/REP으로 복사한다.
이 file-backed template는 모두 0이다. 이후 flags=0x200, CS=0x63,
SS/DS/ES=0x6b, FS/GS=0을 저장한다. 기존 S가 있는 경로에는 이 재초기화가 없다.
할당 전체가 초기화되었다거나 live S가 항상 0이라는 의미가 아니다.

| 기준 | offset/폭 | 관찰한 역할 |
|---|---|---|
| T | +0x74 DWORD | 앞선 원본 검증의 trap recovery pointer |
| M | +0x74 WORD | 저장된 ES selector, `0x1a17bd/0x1a17e3` |
| R | +0x74 DWORD | 전달된 pending bitmap, `0x1a1ab0` |
| R | +0x78 DWORD/낮은 BYTE | 아직 전달하지 않은 timer bitmap |
| R | +0x7c DWORD/낮은 BYTE | timer armed bitmap |

Python 산식상 8개 레코드는 M+0x88에서 시작하여 M+0x4a8 직전에 끝난다.
PCcreate의 M+0x4a8=1은 이 레코드 배열 뒤에 있으며, 요청 크기는 0x51c이다.
이 경계 일치는 field writer·할당기 계약 전체를 증명하지 않는다.

## 2. PCcallMonitor와 PCresume의 상태 매핑

다음 표는 S↔M의 직접 MOV 쌍이다. flags에는 별도 변환이 있으므로 전체 변환이
원래 값으로 완전히 복원되는 역함수라고 표현하지 않는다. 정확한 load/store 주소는
증거 JSON의 state_save/state_restore와 segment_save/segment_restore에 있다.

| 저장 항목 | S offset | M offset | 폭 |
|---|---|---|---|
| EAX | 0x2c | 0x40 | DWORD |
| EBX | 0x20 | 0x44 | DWORD |
| ECX | 0x28 | 0x48 | DWORD |
| EDX | 0x24 | 0x4c | DWORD |
| EDI | 0x10 | 0x50 | DWORD |
| ESI | 0x14 | 0x54 | DWORD |
| EBP | 0x18 | 0x58 | DWORD |
| ESP | 0x44 | 0x5c | DWORD |
| SS | 0x48 | 0x60 | WORD |
| flags | 0x40 | 0x64 | DWORD |
| EIP | 0x38 | 0x68 | DWORD |
| CS | 0x3c | 0x6c | WORD |

Monitor는 먼저 M+0x80=0으로 만들고 R+0x6c가 nonzero이면 mask 4를 설정한다.
S의 VM bit에 따라 M+0x80의 mask 1과 segment 저장 위치가 달라진다.
protected state에서는 S+0x0c/0x08/0x04/0x00의 DS/ES/FS/GS를,
VM state에서는 S+0x50/0x4c/0x54/0x58을 M+0x70/0x74/0x78/0x7c로 WORD 저장한다.

M+0x64에는 S flags를 복사한 뒤 R+0x68에 따라 mask 0x200을 OR/AND하고,
`R+0x70 & 0x7000`을 OR한다. 후자는 snapshot의 0x7000 부분을 먼저 지우지 않는다.
R+0x48=0 저장 `0x1a1864` → CR0 읽기/AL|8/CR0 쓰기 → PCdeliverTimers 순서다.
그다음 S의 DS/ES=0x6b, FS/GS=0, CS=0x63, SS=0x6b,
EIP=`[M+0x28]`, ESP=`[R+0x24]`, EBP=0을 기록한다.
S flags `&0xfffdfaff`는 Python 비트 계산으로 8/10/17, 즉 TF/DF/VM을 지운다.
이 본문에서 R+0x58 reason을 새로 쓰거나 timer를 cancel하는 것은 아니다.

Resume는 M이 없거나 protected 표시 상태에서 M+0x6c의 mask 4가 없으면 5를 반환한다.
이것은 selector 전체/descriptor 권한을 검증한 것이 아니다. 이후 R+0x68에는
M flags의 IF를, R+0x6c에는 M+0x80의 mask 4를, R+0x70에는 flags &0x7000을 기록한다.
`PCscheduleTimers` 호출 `0x1a1666`이 R+0x48=1 `0x1a166b`보다 앞선다.
이어서 CR0|8을 기록하고 S를 채운다. S flags는 `&0x50fd7 |0x202`이며
VM 경로에서는 추가로 0x20000을 OR하고 ordinary segment 슬롯을 0으로 만든 뒤
VM segment tail을 채운다.

두 CR0 쓰기는 각 C export에 표현되지 않는다. 단순한 구조체 복사로 대체할 수 없다.
또한 snapshot과 restore 사이의 M/R 변경·index 동일성·IRQ/동시성은 이 매핑만으로 닫히지 않는다.

## 3. 실제 return은 active-thread frame을 사용하는 IRETD 경로

PCcallMonitor/PCresume/marker 성공 경로는 `thread_exception_return(0x18dec0)`을 호출한다.
이 함수는 **전달받은 S 인자를 읽는 함수가 아니라**, active-thread 전역 `0x1e8b54`를
다시 읽고 그 PCB의 S를 선택한다. 따라서 앞서 수정한 S와 실제 복귀 S가 같다는
호출자·thread 전환 불변식이 필요하다.

`_check_for_ast(S)` 호출이 먼저 있고, 복귀하는 경우 S의 VM bit에 따라
S+0x5c 또는 S+0x4c를 `[P의 첫 포인터]+4`에 쓴다. S를 PUSH한 뒤
`0x18df6f`에서 `0x186f04`를 CALL한다.

`0x186f04`는 CALL 복귀 주소를 POP으로 버리고 다음 POP으로 S를 얻어,
CLI → ESP=S → empty_stacks=1 → STI → POP GS/FS/ES/DS → POPAD → ESP+8 → IRETD를 수행한다.
유효한 상태/segment와 AST 복귀를 전제로 이 경로는 C 호출자의 일반 RET로 돌아오지 않는다.
원본에 남은 caller epilogue를 지우거나 DB에 무조건 noreturn을 지정한 것은 아니다.
segment fault·AST·중첩 trap·stack 생존성까지 정적 지역 분석으로 보장하지 않는다.

## 4. Marker 인자의 실제 소비

96차 caller는 FA/FC/FD용 입력을 각각 20/10/20바이트 staging한다.
이번에는 그 소비자의 실제 읽기와 쓰기 폭을 확인했다.

| 소비자 | 입력→S EIP/CS/flags/ESP/SS | flags 변환 | own gate |
|---|---|---|---|
| FA 0x1a18c8 | +0 DWORD / +4 WORD / +8 DWORD / +0xc DWORD / +0x10 WORD | &0x50fd7, OR 0x202 | 입력 +4 BYTE의 mask 4 |
| FC 0x1a1918 | +0 WORD / +2 WORD / +4 WORD / +6 WORD / +8 WORD | &0xfd7, OR 0x202 | 입력 +2 BYTE의 mask 4 |
| FD 0x1a1968 | FA와 같은 읽기 폭 | &0x70fd7, OR 0x20202 | CS bit 검사 없음 |

FC의 EIP/ESP WORD는 MOVZX로 DWORD 저장된다. FA/FC gate 실패는 EAX=0이며
그 실패 분기에는 S 수정이 없다. selector mask 4 검사를 전체 권한 검증으로 부르지 않는다.

FD는 ordinary DS/ES/FS/GS 슬롯을 WORD 0으로 만들지만,
VM segment tail S+0x4c/0x50/0x54/0x58을 자신의 본문에서는 쓰지 않는다.
이 tail은 기존 state 또는 별도 초기화에 의존한다. VM bit를 강제했다고 해서
완전한 VM frame을 이 함수가 모두 초기화했다고 판단할 수 없다.

## 5. PCexception/continuation의 인자와 재선택

PCexception은 R+0x48이 0이면 EAX=0으로 나간다. trap 0xe에서는 CR2를 보존하고,
uthread 전역의 +0x68 BYTE를 저장/0 처리한 뒤 vm_fault를 호출하고 BYTE를 다시 복원한다.
error code mask 2에 따라 요청 protection은 1 또는 3이며 주소는 CR2 &~page_mask다.
vm_fault 실패는 R+0x4c/0x50/0x54에 trap/error/status를 기록한다.

`0x1a1468/0x1a146d/0x1a146e/0x1a146f`는 순서대로 continuation `0x1a1514`,
CR2, status, 1을 PUSH하고 `0x1a1471`에서 `0x1568d8`을 CALL한다.
이후 ESP+0x10이다. C에는 `_exception_with_continuation(1,iVar4)`만 보인다.
callee 정식 prototype을 여기서 새로 확정하지 않되, call-site stack 인자 누락은 기록한다.

continuation `0x1a1514`는 active T/S/M/index/R을 다시 선택한다.
R+0x54가 nonzero이면 R+0x58=1 후 monitor를 호출한다.
그 밖의 공통 종료에서 R+0x58=0이고 R+0x74 또는 timer-pending이 있으면 monitor를 호출하고,
thread_exception_return으로 이어진다. exception 호출 전후의 같은 R·thread·상태와
continuation의 실행/취소/종료 계약은 별도 미완료 항목이다.

## 6. 타이머 상태와 지연값

Timer callback `0x1a19c8`은 R+0x7c mask 2가 있을 때만 동작한다.
R+0x48이 nonzero일 때만 R+0x78에 mask 2를 OR하고, active 여부와 무관하게
해당 armed mask는 DWORD AND로 지운다. `0x1a19e8`의 mask 4 경로에는 active 검사가 없다.
두 콜백에는 자체 잠금 명령이 없다.

Schedule은 expired mask 2를 먼저 지우고, 이미 armed인 timer2를 Remove한 뒤
enable R+0x5c mask 2에 따라 다시 예약하거나 armed mask를 지운다.
timer4의 expired mask는 R+0x74로 넘기고 지운다. timer4는 armed가 아니고 enable인 경우에만
새로 예약하며, 이미 armed인 timer4의 enable이 없어졌다고 이 함수가 곧바로 취소하지 않는다.

R+0x60/0x64의 지연값은 32비트 레지스터에서 LEA×5를 반복하고 SHL 3으로 배율 1000을
적용한다. **32비트 곱셈이 먼저 wrap된 뒤 high DWORD=0**으로 DeadlineFromInterval에 전달된다.
이 helper는 clock_value(1)의 EDX:EAX에 ADD/ADC로 interval을 더한다.
Python에서 wrap 없는 최대 unsigned 입력은 4,294,967이며 다음 입력 4,294,968은
실제 low DWORD 704를 전달한다. 이는 원본 산식의 결과이며 timer 단위·허용 입력 범위·
live overflow 발생 여부까지 확인한 것은 아니다.

PCdeliverTimers는 R+0x78 &6을 R+0x74에 OR한 뒤 R+0x78의 mask 6을 지운다.
PCtimersPending은 R+0x78의 낮은 BYTE mask 6만 검사하며 R+0x74를 검사하지 않는다.
PCcancelTimers는 두 callback/context에 Remove를 호출할 뿐 record bitmap을 직접 지우지 않는다.
PCcancelAllTimers는 8개 레코드에 같은 두 Remove를 수행한다. Python 집계로 호출은 16회다.

## 7. Queue 취소와 콜백 실행의 분리

calloutDispatchDelayed는 전역 `0x1dfcbc`가 0이면 queue에 넣지 않고 종료한다.
그런데 PCscheduleTimers는 이 호출 바로 다음에 armed bit를 설정한다.
따라서 호출이 반환됐다는 사실만으로 queue 등록 성공을 단정할 수 없다.
PC 사용 시 이 gate가 항상 활성화되어 있는지는 초기화 writer 검토가 필요하다.

활성 경로는 free queue에서 entry를 꺼내 callback/context/deadline을 기록하고 delayed queue에
unsigned 64비트 deadline 순으로 삽입한다. 같은 deadline을 만나면 그 entry 뒤에 삽입한다.
새 head이면 현재 clock과 deadline 차를 계산하고 만료 시 0, 아니면 timer attributes 상한으로
제한하여 set_timer를 호출한다. 원본의 panic 뒤 `0x16943e` fragment도 확인했다.
이 fragment는 enclosing EBP에 의존하며 별도 정상 ABI 함수가 아니다. panic 실제 복귀를 가정하지 않는다.

calloutRemove는 먼저 ready queue `0x1e7250`, 없으면 delayed queue `0x1e7258`를 순회한다.
callback +8/context +0xc가 일치하는 **첫 항목 하나**를 제거하고 종료한다.
ready 제거는 `0x1e7260`을 감소시킨다. 해당 entry가 원본 pool 주소 범위에 있으면
free queue로 돌려보낸다. 이 함수에는 실행 중 counter `0x1e7264`의 검사나 종료 대기가 없다.

worker `0x169cb0`의 관찰 순서는 다음과 같다.

1. ready entry unlink 및 ready counter 감소.
2. callback을 EDI, context를 ESI에 저장하고 entry 상태 +0x1c=0.
3. pool entry이면 free queue로 반환하고 두 번째 callback 인자를 NULL로 설정.
4. 실행 중 counter `0x1e7264` 증가 → queue lock 해제 → spl0 호출.
5. 두 번째 인자(entry 또는 NULL), 첫 인자(context)를 PUSH → `CALL EDI`.
6. callback 복귀 후 splsched/재잠금 → 실행 중 counter 감소.

따라서 이미 꺼낸 entry의 callback/context는 queue 밖 레지스터에 있다.
Remove의 queue 검색만으로 이 실행을 찾아 취소하거나 완료를 기다릴 수 없다.
이는 **Remove 자체의 보장 범위**이며, PCdestroy와 실제로 위험하게 겹치는 실행을 입증한 것은 아니다.
delayed→ready 승격·caller 직렬화·thread 종료·IRQ/SMP·중복 예약 여부가 후속 검토다.

이 queue 함수와 worker에는 MOV memory→TEST register→JNZ 같은 TEST라는
원본 `75fc` backedge가 있다. 캡처 값이 nonzero이고 예외적 레지스터 변경이 없으면
backedge는 lock memory를 다시 읽지 않는다. C의 memory polling loop와 구분해야 한다.
현재 lock contention이나 live hang이 관찰되었다고 보고하지 않는다.

## 8. 생성·해제와 LDT 변경의 지역 계약

PCcreate는 active thread의 **caller task map**을 사용하지만 port에서 변환한
**target thread PCB**에 W를 등록한다. 두 task가 같다는 사실을 여기서 가정하지 않는다.
suser 결과가 0일 때 5 반환, object_copyin 실패/NULL target은 4 반환이라는 분기를
기록하며, callee 권한 정책은 이름으로 대체하지 않는다.

이미 W가 있으면 주소 반환 copyout 결과 또는 지정 주소 일치 여부로 반환한다.
새 W 경로의 vm_map_find가 성공한 뒤 주소 copyout이 실패하면
`0x1a0f9c`→thread_deallocate→EAX=4→epilogue로 간다.
이 own path에는 vm_map_remove가 없다. 그 사실만으로 callee 후처리·실제 leak을 확정하지 않는다.

이어 map reference, wrapper kalloc(0xc)/memset, wired allocation(0x51c), shared pmap 연결,
M 초기 필드 저장, target PCB+0xec=W publish 순서다.
wired allocator 반환값을 자신의 caller에서 검사하지 않으며 kalloc NULL의 자체 분기도 없다.
callee가 실패하지 않는지/어떻게 실패하는지/어떤 초기화를 하는지는 별도 확인한다.
짧은 copyin/out의 recovery-slot 후속은 앞선 보고서의 열린 항목과 연결한다.

PCdestroy의 직접 CALL 순서는 pmap_remove → vm_map_remove → vm_map_deallocate →
PCcancelAllTimers → kmem_free → kfree(wrapper)다. user mapping 제거가 cancel보다 앞서고,
kernel 쪽 M 해제는 cancel 뒤다. 본문은 PCB+0xec를 직접 0으로 만들지 않는다.
이는 PCB까지 이어지는 상위 파괴 계약·콜백 종료 보장이 없다는 최종 증명이 아니라
그 보장을 이 함수 안에서 찾을 수 없다는 한정된 결론이다.
page_mask는 zerofill 전역이므로 원본 파일에서 live page size를 만들어 내지 않았다.
rounding은 `(mask+0x51c)&~mask` 및 `(VA+mask+0x51c)&~mask`의 DWORD 산식으로 남겼다.

PCldt는 두 인자가 모두 -1이면 task_default_ldt, 아니면 task_locate_ldt를 호출한다.
성공 0이면 target S의 CS/SS/DS/ES/FS/GS만 지정 selector로 WORD 저장하고
target thread를 deallocate한다. EIP/ESP/flags를 이 성공 블록이 다시 초기화하지 않는다.
LDT callee의 실제 descriptor 저장·bound·권한·동시성 검증은 다음 분석으로 남긴다.

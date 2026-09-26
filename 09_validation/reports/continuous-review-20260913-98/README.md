# 98차 — LDT setter·descriptor 전파와 task/thread 대기 계약

## 결과

LDT 설정 함수와 실제 descriptor load 경로를 원본으로 확인했다.
설정 단계의 주소 검사, size→limit 축약, active thread에 대한 즉시 LLDT,
bootstrap의 base-only 비교, task hold/wait/release의 현재 thread 취급을 구분했다.
이는 지역 원본 분석의 진전이며 전체 LDT/PC subsystem·전체 kernel 완료가 아니다.
가상 산식 반례를 실제 권한 우회·fault·race·동작 재현으로 주장하지 않는다.

원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Ghidra 스킬의 함수 본문/호출/제어 이전 대조를 기존 export와 원본 file bytes에 적용했다.
외부 코드는 사용하지 않았고 계산·재디코드·해시는 모두 Python이다.
새 독립 계획 검토를 받지 않았으며 검토 통과로 표시하지 않는다.

Python 집계: 일반 본문 15개와 synthetic fragment 1개, 총 16개 본문의
1,218개 명령/3,375바이트. 직접 분기 98개, 직접 CALL 52개, 간접 JMP 1개,
핵심 명령 161개, LDT descriptor write 그룹/LLDT 각각 6개,
thread_dowait table 14개 slot, register-only spin 패턴 13개를 확인했다.
warning 1행은 parent panic의 C 경고이며 원본 결함 수가 아니다.
입력 54개와 기존 보존 경로 880개를 검사했다.

자료: [범위와 계획](SCOPE.md), [원본·산식 증거](object-lifetime-evidence.json),
[C 표현 차이](DECOMPILER_ISSUES.md), [보존 해시](preservation.json),
[체크포인트](checkpoint.json), [미완료 항목](OPEN_ITEMS.md),
[이전 보고서](../continuous-review-20260913-97/README.md).

## 1. task machine state와 PC shared state는 별개

A=task, K=`[A+0x40]`, T=task thread-list의 thread, P=`[T+0x28]`로 표기한다.
setter는 K의 첫 DWORD에 base, K+4에 size를 저장하며 K+0x10을 lock 함수에 전달한다.
task+0x1c가 list head이고 관찰한 next는 T+0x10이다.
각 thread에는 **PCB P+0x74/P+0x78**로 LDT base/size를 전파한다.

따라서 P+0x74는 T+0x74 recovery pointer, M+0x74 saved ES WORD,
R+0x74 pending bitmap과 다른 필드다. M은 PC wrapper에서 얻는 shared state이며 K가 아니다.
이 setter 검토만으로 PC emulator가 읽는 M+0x30/0x34/0x38/0x3c의 base/bound writer가
확인되었다고 할 수 없다.

## 2. task_locate_ldt의 검사와 오류

입력은 (A,base,size)이며 둘 다 DWORD로 읽는다.
원본 `0x18d94e/0x18d951`과 `0x18d953/0x18d956/0x18d959`의 성공 조건은
unsigned `base >= map+0x14` 그리고 `map+0x18 > DWORD(base+size)`다.
끝 주소가 upper bound와 같으면 실패한다. LEA 덧셈은 carry 검사 없이 DWORD로 계산된다.

이 own gate에는 size nonzero, 덧셈 overflow, base/size의 descriptor 단위 정렬,
limit에 들어갈 크기 상한, LDT 내용 검사가 없다. 명시적 map pin/wire/copy 호출도 없다.
range 실패는 1, task_hold가 nonzero를 반환하면 4다.
이 gate 이후 다른 callee의 보장·입력의 상위 권한/유효 범위는 별도 검토다.

Python의 **가상 map** min=0/max=0xc0000000으로 산식만 비교하면:

| base | size | DWORD end | own gate |
|---|---|---|---|
| 0x1000 | 0 | 0x1000 | 통과 |
| 0xfffffff0 | 0x20 | 0x10 | 통과 |
| 0x1000 | 0xbffff000 | 0xc0000000 | 실패 |

이는 실제 map 값이나 실제 허용 호출의 관찰이 아니다. 지역 검사 자체를
overflow-safe/zero-size-safe 검사로 표현할 수 없다는 산식 근거다.

## 3. 설정·대기·전파·해제 순서

locate 성공 경로의 순서는 다음과 같다.

1. task_hold(A) → lock_write(K+0x10).
2. **K base/size 저장** → task_dowait(A,1).
3. task spinlock 아래 thread_reference(next T)를 획득하고 task spinlock 해제.
4. 이전 thread reference가 있으면 deallocate한 뒤, 현재 T의 P+0x74/+0x78에 K 값을 복사.
5. T가 active-thread 전역과 같으면 GDT descriptor를 쓰고 LLDT 수행.
6. 현재 T reference를 유지한 채 task lock 재획득/next를 읽고 반복.
7. task lock 해제, 마지막 reference 해제 → task_release(A) → lock_done(K+0x10) → 0 반환.

K의 설정은 task_dowait보다 앞선다. 개별 PCB 갱신 때 task spinlock은 해제되어 있다.
별도 K write lock 호출의 정확한 배타성, task/PCB 수명, 모든 reader의 같은 lock 사용은
이 순서만으로 보장하지 않는다. task_release도 lock_done보다 앞선다.
task_dowait/task_release 등 task_hold 뒤의 callee 결과를 setter가 오류로 전파하는 분기는 없다.

default setter도 같은 구조이며 K base는 `_ldt` 전역의 값에 0xc0000000을 DWORD 더한 값,
size는 0x18이다. 원본 file initializer에서 `_ldt`는 0x1e2260이므로
그 포인터가 그대로라면 저장 base는 Python 계산으로 0xc01e2260이다.
이 값이 runtime에도 같다는 writer closure는 아직 없다.

PCldt caller는 port→target thread 변환 후 두 인자가 모두 -1이면 default,
그 밖에는 locate를 호출한다. 성공이면 target saved-state selector만 재설정한다.
실제 suser/object_copyin의 권한 계약은 이름으로 확정하지 않는다.

## 4. LDT descriptor를 만드는 정확한 폭

선택한 LLDT 경로는 G=`[_gdt]`의 +0x20에 descriptor를 만든다.
size를 DWORD에서 1 감소시킨 후 아래 폭으로 저장한다.

| G offset | 폭 | 값 |
|---|---|---|
| +0x20 | WORD | size-1의 낮은 WORD |
| +0x22 | WORD | base 낮은 WORD |
| +0x24 | BYTE | base >>16 |
| +0x25 | BYTE | (이전 access &0xe0) OR 0x82 |
| +0x26 | BYTE | (이전 flags &0x70) OR (((size-1)>>16)&0xf) |
| +0x27 | BYTE | base >>24 |

원본은 +0x26의 mask 0x80을 AND로 먼저 지운다. 나머지 상위 mask 0x70은 보존한다.
access도 항상 0x82를 통째로 덮는 것은 아니다. Python에서 이전 BYTE 전 범위를 대조하면
결과 집합은 0x82/0xa2/0xc2/0xe2다. 따라서 이전 descriptor bits를 무조건 0이라고 가정하지 않는다.

base는 분리된 WORD/BYTE들을 통해 전체 DWORD가 반영되고, limit은 `(size-1)&0xfffff`이다.
size=0은 encoded limit 0xfffff, size=0x18은 0x17,
size=0x100001은 encoded limit 0이다. 이 truncation/underflow는 원본 산식의 결과이며
해당 요청이 실제로 도달 가능한지나 LLDT가 성공하는지와는 다른 판단이다.

LLDT의 실제 operand는 WORD `[0x1d14ea]`다. 파일 값은 0x20이며 Python 해석으로
index=4/TI=0/RPL=0, descriptor offset=0x20이다. LTR는 `[0x1d14e8]`의 파일 값 0x18이다.
C는 이를 즉시 상수 호출처럼 표시하지만 원본은 memory read다.
원본 `_gdt` 포인터는 0x1e18b0이고 +0x18/+0x20 두 descriptor의 파일 bytes는 0이다.
이는 초기 파일 값일 뿐 load 시점의 GDTR/descriptor 내용이 0이라는 주장이 아니다.

## 5. LLDT 위치 조사와 소비자별 조건

기존 full-pass5 함수 ASM 5,253개를 manifest와 대조하여 LLDT와 두 setter의 직접 CALL을 조사했다.
LLDT 6개와 PCldt의 CALL 2개가 해당한다. 모든 hit를 선택 본문의 원본 명령으로 재디코드했다.
조사 population hash와 hit/file/명령은 JSON의 ASM_survey에 있다.
함수 밖/미식별 코드와 간접 caller까지의 완전성은 이 결과에 포함하지 않는다.

| 본문 | LLDT | 갱신 조건 |
|---|---|---|
| task_locate_ldt | 0x18da63 | 전파 중 T가 active T |
| task_default_ldt | 0x18dbf2 | 전파 중 T가 active T |
| stack_handoff | 0x18d318 | 이전/새 PCB의 base 또는 size가 다름 |
| switch_context | 0x18d44b | 이전/새 PCB의 base 또는 size가 다름 |
| thread_bootstrap_return | 0x18de9b | task/PCB base가 다르고 active T |
| start_initial_context | 0x18e16e | own 경로에서 무조건 descriptor 설정 |

bootstrap의 `0x18de34/0x18de37`은 **base만 비교**한다.
같으면 P+0x78 size 갱신도 LLDT도 건너뛴다. 같은 base에서 size가 달라질 수 없다는
writer 불변식은 아직 증명하지 않았다. switch/handoff는 base와 size 둘 다 비교하지만
같은 주소에 있는 LDT 내용 자체를 비교하지는 않는다.

switch/handoff/initial 경로는 active-thread 갱신, 조건부 또는 무조건 CR3 쓰기,
LDT descriptor/LLDT, TSS descriptor/LTR, CR0|8 변경을 함께 수행한다.
이들 C에서 CR3 쓰기는 빠져 있으며, switch/initial C에는 CR0 쓰기도 없다.
handoff C의 `return in_CR0|8`도 hardware write의 대체가 아니다.
실제 switch_tss의 비표준 제어 이전은 앞선 분석과 연결하되, 이번에 전체 scheduler 동등성을 주장하지 않는다.

## 6. Task/thread hold-wait-release가 보장하는 범위

task_hold는 A+8이 0이면 5 반환한다. 성공 시 A+0x18을 증가시키고 list를 돌면서
캡처한 active T는 제외하고 thread_hold를 호출한다.
thread_hold는 T+0x40 DWORD를 증가시키고 T+0x4c 낮은 BYTE에 mask 2를 OR한다.
이 자체가 즉시 모든 실행을 정지시키는 명령은 아니다.

task_dowait도 active T를 제외한다. 나머지는 reference → task lock 해제 →
이전 reference 해제 → thread_dowait(T,1) → task lock 재획득 순서로 처리한다.
task inactive와 must_wait=0일 때 자체 반환 5 분기가 있지만 setter는 must_wait=1을 전달한다.
task_dowait는 thread_dowait의 반환값을 별도 누적하지 않는다.

thread_dowait는 자신이 active T이면 panic을 호출한다. panic 뒤 0x167a11의
ADD ESP,4 fragment도 원본으로 확인했지만 panic 실제 복귀를 가정하지 않는다.
그 밖에는 T+0x4c의 low nibble로 원본 table `0x167a58`을 선택한다.

- low nibble 6: rem_runq 호출, nonzero면 mask 4 clear/T+0x48=0 뒤 종료 경로.
- 7/0xb/0xe/0xf: T+0x48=1 후 thread_sleep으로 가는 경로.
- 나머지: 지역 종료 경로. 0/1은 unsigned index 범위 검사에서 종료한다.
- sleep 복귀 후 active T+0x44와 must_wait를 검사한다. must_wait=1이면 자체 interrupted=5
  설정 분기를 억제하고 다시 상태를 검사한다.

이는 raw table/분기의 의미다. rem_runq/sleep/wakeup의 전체 상태·queue·실행 보장은 후속 항목이다.

task_release는 A+8=0이면 5 반환, 아니면 A+0x18을 감소시키고 **현재 T를 제외하지 않은**
list 전체에 thread_release를 호출한다. thread_release는 T+0x40을 무조건 1 감소시키고,
이전 값이 1일 때만 상태 mask를 지우고 조건부 thread_setrun을 호출한다.
현재 T가 이 list에 있다면 이 지역 hold/wait에서는 제외되지만 release에서는 감소한다.
Python의 해당 지역 증감은 -1이다. 상위 caller의 기존 hold count·별도 균형 계약 없이
이를 전체의 확정적인 underflow/버그 또는 안전성으로 판단하지 않는다.

thread_reference는 non-NULL T에 대해 T+0x20 lock 아래 T+0x24를 증가시킨다.
참조를 가지고 task lock 밖으로 나가는 구조를 확인했지만 동시 thread 파괴/목록 변경/PCB 소유와
모든 경로의 정확한 reference 균형을 여기서 완료 처리하지 않는다.

## 7. 기본 LDT 초기화와 bootstrap 부수 경로

ldt_init `0x18cbcc`는 `_ldt` pointer의 두 entry를 직접 수정한다.
base를 0으로 쓰고 access=0xfa/0xf2, limit low WORD=0xffff를 기록한다.
code 쪽 limit high nibble은 0xb, data 쪽은 0xf이며 flags의 mask 0xc0을 OR한다.
기존 flags bits 4/5를 통째로 0 초기화하는 것은 아니다.
첫 NULL entry는 이 함수가 쓰지 않으며 원본 파일의 0 값과 runtime 보존 여부를 구분한다.

thread_bootstrap_return의 앞부분에는 K+0xc 크기가 nonzero일 때 선택적으로 TSS를 확장하고
기존 TSS의 0x1a DWORD/104바이트를 CLD/REP 복사하는 경로도 있다.
요청 크기는 K+0xc +0x69이며, 조건에 따라 기존 별도 할당을 해제하고 LTR를 갱신한다.
그 뒤 TSS+0x66 WORD offset으로 목적지를 만들고 K+8에서 K+0xc바이트 memcpy한다.
이 경로도 raw body에 포함했지만 allocation failure·size overflow·bitmap offset/끝 sentinel·
copy caller 계약·동시성까지 확인했다고 표기하지 않는다. task_map_io_ports 및 machine-state
생성/초기화 writer와 연결하는 추가 분석이 필요하다.

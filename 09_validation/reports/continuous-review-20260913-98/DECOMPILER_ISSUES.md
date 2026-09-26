# 98차 C 표현 차이 — 한정된 추가 목록

[97차 목록](../continuous-review-20260913-97/DECOMPILER_ISSUES.md)을 변경하지 않고
이번 선택 본문의 관찰을 추가한다. 전체 kernel 의미 누락 ledger는 아직 미완료다.
원본 ASM/C/DB에 수정이나 임의 prototype 보충을 하지 않는다.

## CR3 write 누락

| 본문 | 원본 write | 실행 조건 |
|---|---|---|
| stack_handoff | 0x18d2c5 MOV CR3,EAX | 이전/새 저장 CR3 값이 다름 |
| switch_context | 0x18d3ef MOV CR3,EAX | 이전/새 저장 CR3 값이 다름 |
| start_initial_context | 0x18e128 MOV CR3,EAX | own 경로에서 무조건 |

[handoff C](../../../04_ghidra/exports/x86/full-pass5/functions/0018d250.c),
[switch C](../../../04_ghidra/exports/x86/full-pass5/functions/0018d37c.c),
[initial C](../../../04_ghidra/exports/x86/full-pass5/functions/0018e0e4.c)는
이 CR3 write를 표현하지 않는다. 원본은 PCB의 첫 포인터가 가리키는 상태 +0x1c에서
새 값을 읽어 사용한다. C에서 active-thread/descriptor 저장만 확인했다고
address-space 전환까지 충실히 표현된 것으로 볼 수 없다.

## CR0 write의 누락과 반환값만 남은 표현

handoff `0x18d367/0x18d36a/0x18d36c`, switch `0x18d49d/0x18d4a0/0x18d4a2`,
initial `0x18e1bd/0x18e1c0/0x18e1c2`는 CR0 읽기 → AL|8 → CR0 쓰기이다.
switch/initial C에는 해당 write가 없다.
handoff C의 54행은 `return in_CR0 | 8`이다. 원본 EAX에 이 결과가 남는 것과 별개로,
반환값만 표현한 C는 실제 CR0 갱신이라는 부수 효과를 보존하지 않는다.
전체 FPU/TS 처리와 모든 caller의 EAX 소비는 추가 확인이 필요하다.

## LLDT/LTR는 누락이 아니라 memory source의 상수화

이번 LLDT 6개는 모두 WORD `[0x1d14ea]`를 읽으며 파일 WORD는 0x20이다.
LTR는 `[0x1d14e8]`을 읽고 파일 WORD는 0x18이다.
C의 LocalDescriptorTableRegister(0x20)/TaskRegister(0x18)는 이 초기값을 상수화한 표현이다.
파일 값과 일치한다는 점은 확인하되, 모든 runtime writer/loader fixup까지 검증한
불변 상수라고 보장하지 않는다. LLDT 자체가 C에서 사라졌다고 잘못 세지 않는다.

## Spin backedge는 memory 재읽기가 아님

선택한 task/thread lock 계열에서 13개의 원본 MOV memory→TEST register→JNZ TEST를 확인했다.
정확한 주소/레지스터와 `75fc` 바이트는 [증거](object-lifetime-evidence.json)의 spin_patterns에 있다.
C의 `while (*lock != 0)` 표현과 달리 같은 TEST로 돌아가는 backedge는 memory를 reload하지 않는다.
캡처 값이 nonzero이고 예외적 register 변경이 없다면 계속 그 값을 검사한다.
전체 native contention/hang 발생을 확인한 결과는 아니다.

## thread_dowait의 table과 synthetic fragment

parent `0x1679ec`는 low-nibble 상태를 unsigned index로 바꿔 원본 table `0x167a58`을 읽는다.
전체 table 14개 slot을 대조했으며 C switch case 6, 7/0xb/0xe/0xf의 분류와 연결된다.
이 부분은 table을 읽지 않고 C만 신뢰한 결과가 아니다.

panic 뒤 `0x167a11`은 enclosing stack의 ADD ESP,4만 own body로 갖는다.
그 C가 parent 후속까지 따라가면서 thread_sleep/wakeup/splx 인자를 줄여 표현하는 것을
새 독립 ABI 함수의 prototype으로 채택하지 않는다. 원본 parent의
`0x167ab7/0x167ab9/0x167abd`는 sleep 전 DWORD 인자들을 PUSH한다.
fragment 존재는 panic이 실제로 복귀한다는 증거가 아니다.

## C 결함과 원본의 지역 조건 구분

bootstrap의 base-only 비교, setter의 wrapped end 검사, size-1의 limit 축약,
task_hold/wait의 현재 thread 제외와 task_release의 전체 순회는 원본에도 있다.
이들을 C만의 버그로 보고 수정하거나 원본에 없는 검사를 보충하지 않는다.
원본 조건을 확인한 것과 native 오류를 입증한 것은 구분한다.

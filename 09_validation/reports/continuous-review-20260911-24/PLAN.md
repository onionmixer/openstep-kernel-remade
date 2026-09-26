# 보고서24 계획 — 최종 CS 및 원본 trap 복구 연결

직전 상태 응답은 새 분석 증거를 만들지 않았다. 이 작업은 report23의 실제 CPU
모델 paging fault에서 아직 실행하지 않은 원본 예외 처리·복귀 경로를 연결한다.
전체 분석 목표를 이 시험의 통과로 축소하지 않는다.

코딩 전 독립 검토는 `/root/trap_plan_review`가 수행했다. 의견은 승인 권한이나
정확성 증명이 아니다. 원본 assembly, 원본 바이트와 SDK layout을 대조한다.

## 실행 게이트

- 원본 최종 far jump로 CS=8을 설정하고 EIP, 실행 API 및 hook의 주소 좌표를
  별도 시험한다. report23의 flat CS=0x48 실행 방식을 무조건 재사용하지 않는다.
- 원본 idt_init과 IDTR relocation을 실행해 vector14의 gate를 검사한다.
- 원본 copyout에서 fault가 발생했을 때 native IDT 전달을 먼저 관찰한다.
  지원되지 않으면 오류와 스냅샷을 보존하고 native 전달을 완료 처리하지 않는다.
- 필요한 경우 실제 fault 스냅샷에 명시적인 same-CPL 예외 프레임을 주입한다.
  error/EIP/CS/EFLAGS와 관찰되지 않은 error-code/RF 입력을 구분한다.
  이 시험은 CPU의 자동 프레임 생성 증거가 아니다.
- 원본 stub → alltraps → catch_trap → kernel_trap → vm_fault →
  vm_map_lookup(empty map) → lock 해제 → recovery → IRETD → 복사 실패
  epilogue → 호출자까지 실행한다. 호출 반환값을 mock하지 않는다.
- active thread/task/map와 uthread pointer+0x68을 합성 fixture로 명시한다.
  empty_stacks=0 조건이며 대체 스택 전환은 이 시험 범위가 아니다.
- lock 상태, VM fault counter, frame의 변경 필드, recover 수명, FS/GS,
  ESP와 callee-saved, EFAULT, fault 전 부분 쓰기 보존을 검사한다.

## 보존 및 판정

원본·기존 Ghidra/IDA DB·reference sources·이전 보고서·07_kernel은 수정하지 않는다.
계산은 Python으로만 수행한다. 새 시험과 산출물은 이 디렉터리에만 둔다.
실행되지 않은 분기를 추정 통과로 처리하지 않는다. VM map lookup miss는 실제
mapped-entry protection 실패나 page-in 성공 증거가 아니다. GCC 2.7 및 실제
부팅·하드웨어 동작 검증은 별도 미완료 의무다.

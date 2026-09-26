# 102차 범위·검토 절차

101차에서 남은 thread_halt/AST/IPC 종료/scheduler 정지 전환을 원본에서 연결한다.
현재 목표는 OPENSTEP 원본 분석뿐이다. `01_resources`, `07_kernel`, 다른 프로젝트 코드와
외부 문헌은 사용하지 않는다. 범위 밖 역사적 보존 항목은 다시 열거나 해시하지 않는다.
원본 바이너리·DB·export와 완료된 보고서는 수정하지 않는다.

## 절차

1. 101차 checkpoint와 범위 내 입력·보존 자료를 새로 검증한다.
2. halt, self halt, AST 소비, IPC 정리 gate와 scheduler의 관련 본문·C를 읽는다.
3. stack 인자, BIT/BYTE/DWORD, 상태 분류, 직접 분기와 원본 간접 표를 대조한다.
4. 호출 edge와 전체 호출 계약, 지역적 정리와 실제 완료 보장을 구분한다.
5. snapshot mask와 조건부 상태 전환은 Python 정적 산식으로만 확인한다.
6. 신규 보고서·증거를 저장하고 원본·기존 자료 보존 및 신규 산출물을 재검증한다.

모든 계산은 Python이다. 새 검증기 파일·에뮬레이터·구현 소스를 만들지 않는다.
실행·에뮬레이션·복원·빌드·포팅은 하지 않는다. Ghidra 스킬의 대조 절차는 기존 export에
적용하며 live DB는 변경하지 않는다. 신규 독립 Codex 계획 검토는 받지 않았고,
앞선 검토 실패를 통과로 바꾸거나 우회 재시도하지 않는다.

## 분모

일반 본문 25개와 분석 fragment 9개, 총 34개 본문에서 명령 2,266개/6,625바이트다.
직접 분기 359개, 직접 CALL 151개, 간접 전이 6개, 핵심 명령 222개를 확인한다.
간접 전이는 원본 분기 표 5개와 stack-replacing JMP 한 곳으로 나뉜다.
표 항목은 총 73개다. register-only spin 50개와 C warning 21행을 기록한다.
fragment warning의 겹치는 문맥을 독립 결함 개수로 세지 않는다.
fragment는 panic 뒤 stack adjustment/fallthrough를 확인한 것이며 독립 호출 ABI로 인정하지 않는다.

일반 본문은 thread_halt, self halt 두 변형, thread_hold/dowait/release,
ipc_thread/task_terminate, ast_init/check, check_for_ast, block 두 변형,
thread_invoke/dispatch/sleep, clear_wait, mach_msg_interrupt, rem_runq,
call_continuation/__call_with_stack, walking_zombie, thread_terminate/force_terminate,
reaper_thread_continue다. 101차 연결 본문은 보존 해시와 raw 재디코드로 다시 대조한다.

입력 109개와 기존 보존 경로 908개를 검사한다.
full-pass5 ASM 5,253개를 각각 기존 manifest와 대조했고 모집단 SHA-256은
742617851f014a94309d47296900fc5e27b5ad5a862f588590559fe5f334471d다.
지정 직접 호출 56개, need_ast literal-displacement write 30개를 재디코드했다.
외부 선택 본문의 hit는 전체 의미 분석이 아니다. alias/bulk/간접/함수 밖 조사 완결은 미확정이다.

snapshot/current BYTE 조합 65,536개는 비트 항등식 검증이다.
조건부 상태 0x4→0x6→0x16→0x112, 참조와 별개인 hold 감소,
event hash 산식과 table target 검증은 실행·동시성·native 종료 증명이 아니다.

[결과](README.md) · [증거](object-lifetime-evidence.json) · [미완료](OPEN_ITEMS.md)

# 103차 범위·검토 절차

102차의 runq 선택·게시와 machine context 미완료 항목을 원본에서 연결한다.
`01_resources`, `07_kernel`, 다른 프로젝트 소스와 외부 문헌은 사용하지 않는다.
원본·DB·export·완료된 보고서를 변경하지 않고 신규 분석 자료만 남긴다.

## 절차

1. 102차 checkpoint와 범위 내 입력·보존 자료를 새로 검증한다.
2. runq 선택·등록·제거, idle 전달, stack 확보·swapin과 machine 전환의 원본 본문/C를 대조한다.
3. 목록·상태의 자체 검사와 caller 전제를 구분하고 실제 인자/반환 register를 연결한다.
4. 주소·offset·priority index·descriptor flags·stack slot 계산을 Python으로 검증한다.
5. 지정 직접 호출과 literal global write를 manifest와 일치하는 기존 ASM 모집단에서 조사한다.
6. 신규 보고서·증거를 저장한 후 원본 보존과 산출물을 새로 검증한다.

Ghidra 스킬의 대조 절차를 기존 export/raw에 적용한다. live DB는 변경하지 않는다.
계산은 모두 Python이며 새 검증기 파일·에뮬레이터·구현 소스는 만들지 않는다.
복원·실행·빌드·포팅은 하지 않는다. 신규 독립 Codex 계획 검토를 받지 않았고,
이전 검토 실패를 통과로 표시하거나 우회하지 않는다.

## 분모와 한계

일반 본문 23개와 분석 fragment 5개, 총 28개 본문의 명령 1,719개/5,446바이트다.
직접 분기 236개, 직접 CALL 75개, 간접 전이 6개, 핵심 명령 211개를 대조한다.
invoke wakeup table 15항목, register-only spin 21개, C warning 24행을 기록한다.
fragment는 panic 뒤 stack adjustment와 fallthrough이며 독립 정상 반환 함수가 아니다.

일반 본문은 thread_select, run_queue_enqueue, thread_setrun, set_pri, rem_runq,
choose_thread/choose_pset_thread, idle_thread_continue, stack_attach/detach/handoff,
switch_context/__switch_tss/__stack_attach, stack_alloc_try/alloc/free,
thread_continue/swapin, swapin_thread_continue, call_continuation/__call_with_stack,
thread_invoke다. 정확한 주소·body 범위·명령은 JSON에 보존한다.

입력 91개와 기존 보존 경로 915개를 검사한다.
full-pass5 ASM 5,253개를 각각 기존 manifest와 대조했고 모집단 SHA-256은
742617851f014a94309d47296900fc5e27b5ad5a862f588590559fe5f334471d다.
지정 직접 호출 22개와 active thread/stack 및 runq 관련 literal write 8개만 재디코드했다.
함수 밖·alias·bulk·간접 호출·모든 caller 의미의 완전성 검증은 아니다.

priority 예시 260개, descriptor flag 항등식 4,096개, stack slot과 크기/마스크 산식은
정적 검증이다. 전체 입력 도달성·allocation backing·동시성·native 문맥 전환/종료 증명이 아니다.
선택 본문 밖 update_priority, allocStack/freeStack, initial load_context 등은 하위 계약으로 남긴다.

[결과](README.md) · [증거](object-lifetime-evidence.json) · [미완료](OPEN_ITEMS.md)

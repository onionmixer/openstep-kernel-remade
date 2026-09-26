# 98차 범위와 계획

97차 OPEN_ITEMS의 LDT setter/descriptor 전파를 우선 분석한다.
현재 목표는 OPENSTEP 원본 분석뿐이며 외부 소스 비교·복원·구현으로 전환하지 않는다.

## 증거 순서

1. 원본 해시와 97차 체크포인트/입력/보존 파일을 다시 확인한다.
2. task_locate_ldt/task_default_ldt와 PCldt caller를 전체 ASM/C로 대조한다.
3. 직접 호출하는 task/thread hold-wait-release/reference를 확인하고,
   descriptor 변경이 정지·참조·해제와 어떤 순서로 이어지는지 구분한다.
4. 기존 full-pass5 ASM에서 LLDT 및 두 setter의 직접 CALL을 조사한다.
   발견한 LLDT 본문을 선택하여 원본 byte mapping과 descriptor write 폭/제어 조건을 재검증한다.
5. Python으로 limit/flags/주소 wrap, selector, table·크기·개수·해시를 계산한다.
   원본 명령의 산식과 가상의 반례 계산을 실제 kernel 실행과 구분한다.
6. 새 보고서/증거/누락 목록을 저장하고 원본 재디코드와 전체 입력/체크포인트 검사를 반복한다.

Ghidra 스킬의 본문·호출·제어 이전 대조 절차를 기존 export에 적용한다.
LLDT/LTR의 C 상수 표현은 실제 memory operand 및 원본 WORD와 함께 확인한다.
새 독립 계획 교차검토는 수신하지 않았으며 자체 검증을 그 대체 통과로 표시하지 않는다.
이번 작업은 분석 문서와 증거의 추가이며 커널 코딩 계획/구현은 아니다.

## 선택 본문과 제한

task_locate_ldt `0x18d930`, task_default_ldt `0x18dac8`, PCldt `0x1a10d8`,
task_hold/dowait/release `0x166094/0x16610c/0x1661cc`, thread_reference `0x167238`,
thread_hold/dowait/release `0x1679a8/0x1679ec/0x167b2c`, panic fallthrough `0x167a11`,
stack_handoff `0x18d250`, switch_context `0x18d37c`,
thread_bootstrap_return `0x18dce0`, start_initial_context `0x18e0e4`, ldt_init `0x18cbcc`이다.

추가 사용 자료는 같은 원본의 file-backed pointer/selector/table bytes,
function metadata와 full-analysis artifact manifest, 이전 binary-only 보고서다.
ASM survey의 분모는 기존 function .asm export population이며 전체 executable bytes가 아니다.
원본 함수 밖 instruction/미식별 entry, 간접 caller, alias/bulk/runtime writer의 완전성을
이 survey의 일치 결과로 대신하지 않는다.

task/thread lock과 wait의 지역 명령은 확인하지만 lock_write/read/done,
run queue/sleep/AST/thread 종료 등 선택 밖 callee의 전체 동작을 이름으로 보장하지 않는다.
K(task machine state)와 M(PC shared state)은 별개이며 K의 writer 확인으로
M+0x30/0x34/0x38/0x3c의 전제가 증명되었다고 처리하지 않는다.

원본·DB·export·기존 확정 보고서는 변경하지 않는다.
01_resources/07_kernel·다른 코드·외부 사이트는 열람하지 않는다.
모든 계산은 Python이며 새 Python 파일/커널 구현/빌드/포팅/동적 실행은 없다.

자료: [결과](README.md), [증거](object-lifetime-evidence.json),
[누락 목록](DECOMPILER_ISSUES.md), [남은 분석](OPEN_ITEMS.md).

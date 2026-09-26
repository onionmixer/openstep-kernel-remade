# ObjC module 등록·해제의 정적 순서 검토

report51의 selector caller 주변 명령에서 module 등록·해제 본문 전체와 직접 lifecycle helper로 범위를 확장한다. 본문을 모두 읽었다는 사실과 모든 callee·입력·실행 의미가 검증되었다는 판정은 구분한다.

Ghidra 스킬의 읽기 전용 절차로 ASM/C·원본 바이트·로컬 구조체 선언을 비교한다. stack에 남는 callback 인자, 섹션/record stride, selector 변경 위치, lifecycle 순서와 사전 검사 인자를 별도 근거로 남긴다. 계산은 모두 Python이다.

원본·reference·DB/export·이전 보고서를 보존한다. 독립 계획 검토 미수신 조건을 유지하며 신규 실행 프로그램·복원 코드·GCC 빌드는 진행하지 않는다. 진단 JSON과 정적 산술은 독립 교차검토·native 실행 결과가 아니다.

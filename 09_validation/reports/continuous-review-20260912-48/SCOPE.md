# NXHash 초기화·확장·정리의 정적 검토

report47에서 남긴 NXHash prototype cache bootstrap, capacity helper, growth, iterator와 empty/reset/free 경로를 읽는다. 구현이나 동적 시험으로 전환하지 않는다.

Ghidra 스킬의 읽기 전용 흐름으로 보존 ASM/C/metadata를 원본 바이트와 대조한다. 주소·크기·해시·집계·경계 산술은 Python으로만 수행한다. 생성하는 JSON은 진단 증거이며 새 emulator나 복원 코드가 아니다.

코딩 전 독립 계획 검토 미수신 상태는 그대로이며 이번에 우회 요청이나 신규 실행 프로그램을 작성하지 않는다. ABI 관련 디컴파일 누락은 원본 레지스터·caller·로컬 선언으로 구분하고, GCC 2.7 실검증과 동일시하지 않는다.

원본·reference·DB/export·이전 보고서는 보존한다. caller 도달성, 할당 실패, callback 재진입/동시성, 전역 cache의 전체 수명과 native 실행은 미완료로 유지한다.

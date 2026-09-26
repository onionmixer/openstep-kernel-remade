# NXMap prototype 조회·재사용의 정적 검토

report46에서 남긴 prototype 동일성 판단과 조회·삽입 경로를 원본 명령에 연결한다. NXMap용 prototype cache와 그것을 구현하는 NXHash의 API·bucket 표현을 구분한다.

Ghidra 스킬의 읽기 전용 흐름으로 보존 ASM/C/metadata를 사용한다. 원본 바이트는 보존된 decoder로 다시 읽고 계산·주소·해시·집계는 Python으로만 처리한다. JSON은 진단 증거이며 새 emulator나 kernel 구현이 아니다.

코딩 전 독립 계획 검토 미수신 상태를 유지한다. 이번 단계는 새 검토 요청이나 우회 요청을 하지 않으며 신규 실행 시험 프로그램·복원 소스·GCC 빌드를 작성/수행하지 않는다. 정적 판독을 독립 검토 또는 동적 검증 통과로 표현하지 않는다.

원본·reference·DB/export 및 이전 보고서를 수정하지 않는다. bootstrap, growth, teardown 전체 계약과 동시성·실패·GCC 2.7 ABI는 미완료로 남긴다.

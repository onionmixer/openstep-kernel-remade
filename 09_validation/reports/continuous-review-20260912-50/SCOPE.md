# 문자열 atom·복사 경로의 정적 검토

report49에서 연결한 NXUniqueStringNoCopy와 관련 unique-string, buffer-copy, string hash/equality 및 직접 strcmp/strcpy 의존 본문을 검토한다.

Ghidra 스킬의 읽기 전용 절차로 보존 ASM/C/metadata를 원본 바이트에 대조한다. 계산·주소·크기·해시·집계는 모두 Python이며 산술 표본은 원본 실행이나 emulator 시험으로 표현하지 않는다.

원본의 EAX 반환과 로컬 선언을 디컴파일 타입과 구분한다. 길이 경계·NULL/빈 문자열·pool 잠금과 수명은 전제와 미검증 범위를 명시한다. 코딩 전 독립 계획 검토 미수신 상태를 유지하며 신규 실행 프로그램·복원 소스·GCC 빌드 및 우회 요청은 하지 않는다.

원본·reference·DB/export·이전 보고서는 보존하고 새로운 정적 보고서/JSON만 추가한다. allocator/물리 보호/동시성/전체 caller와 실제 GCC 2.7 ABI 완료는 주장하지 않는다.

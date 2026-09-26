# 문자열 공유의 selector caller 연결

report50의 문자열 API 직접 참조를 현재 metadata와 원본 call로 확인하고, 실제 caller인 sel_registerName에서 selector 조회·내부 등록·초기화·unload까지 정적으로 연결한다. WithLength/NoCopy의 직접 caller가 보이지 않는다는 사실을 간접 사용 부재로 확대하지 않는다.

Ghidra 스킬의 읽기 전용 흐름을 사용한다. 원본·ASM/C·헤더·caller 주변 명령을 구분하고 모든 주소/크기/경계/해시/집계를 Python으로 계산한다. JSON은 원본 실행이 아닌 정적 진단 근거다.

원본·reference·DB/export·이전 보고서를 보존한다. 신규 실행/검증 코드·복원 구현은 독립 계획 검토 미수신 조건으로 보류하며 이번에 우회 요청하지 않는다. module 전체·동시성·수명·GCC 2.7 ABI 완료는 주장하지 않는다.

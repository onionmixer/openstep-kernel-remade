# IPC splay 분할·병합·경계 조회의 상태 계약

보고서 61의 후속으로 split/join/bounds, lookup/init의 보존된 전체 ASM·Ghidra C·함수 범위를 원본 Mach-O 바이트와 대조한다. cached name과 실제 root key, child-slot 포인터, 빈 tree와 inclusive bounds, 소비형 병합 및 unsigned 상수 분기를 구분한다.

Ghidra 스킬은 보존 export 읽기 전용 비교에 적용한다. 모든 계산은 Python으로 수행하고 문서와 정적 증거만 추가한다. 신규 독립 계획 검토 미확보 상태이며 새 실행 검증 프로그램·동적 실행·커널 구현·GCC 2.7 빌드는 수행하지 않는다. 이전 독립 검토 실패의 우회·재요청도 하지 않는다.

올바른 입력 tree에 대한 정적 계약을 기록하는 범위다. 모든 생산자의 불변조건, alias/동시성 안전성, 모든 tree 형태의 실행 결과, 경고 전수 해결, 전체 분석 완료를 의미하지 않는다. 원본·참고 소스·DB·기존 export/보고서·07_kernel은 보존한다.

# NXHash 삭제·조건부 삽입·복사·비교 정적 검토

report48의 후속 의무 중 NXHashRemove, NXHashInsertIfAbsent, NXCopyHashTable, NXHashMember, NXCountHashTable 및 비교 entry들을 원본 ASM/C에 연결한다. Get/Insert 및 pointer callback은 필요한 비교 근거로 재확인한다.

Ghidra 스킬의 읽기 전용 흐름으로 기존 export와 원본 바이트를 대조한다. 주소·크기·hash·배열 이동 및 집계 계산은 모두 Python이다. JSON은 정적 진단 증거이며 원본 실행이나 새 emulator 결과가 아니다.

독립 계획 검토 미수신 상태를 유지하고 이번에 신규 실행/검증 프로그램·복원 소스·GCC 빌드를 작성/수행하지 않는다. metadata·디컴파일러·산술을 독립 교차검토 통과 또는 native 실행 증거로 간주하지 않는다.

원본·reference·DB/export·기존 보고서를 보존한다. NULL data의 분기 결과와 이동 범위 계산은 전제를 명시하고, 실제 caller 도달성·할당 실패·callback 동시성 및 소유권은 별도 미완료로 둔다.

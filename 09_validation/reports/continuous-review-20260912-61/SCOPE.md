# IPC entry와 reverse hash 제거·tree node 해제

원본 entry dealloc, hash insert/delete dispatcher와 local/global 구현, splay pick/delete를 읽고 실제 저장·노드 free·미사용 ABI 인자·실패 전제를 연결한다. splay 삭제의 Ghidra unreachable 경고와 원본 unsigned 상수 분기도 대조한다.

split/join/bounds의 전체 구현, table grow, hash lookup의 전이적 완결 및 pset/mqueue는 이 단계에서 검증 완료로 판정하지 않는다. 원본에 있는 모든 byte를 C 표현에 포함시켰다는 의미도 아니다.

Ghidra 스킬을 보존 export에 읽기 전용으로 적용한다. 계산은 모두 Python이다. 신규 독립 계획 검토 미확보 상태를 유지하며 새 검증 프로그램·동적 실행·DB/원본/07_kernel 수정·GCC 2.7 실빌드 또는 실패한 독립 검토의 재요청/우회는 하지 않는다.

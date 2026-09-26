# IPC entry 생산자와 reverse lookup

보고서 62 이후 tree insert, entry get/alloc/alloc_name/grow_table 및 reverse hash lookup dispatcher/local/global을 원본 전체 본문과 참고 소스에 대조한다. 성공/오류별 lock 반환, 재할당 후 이름 재검사, table/hash/tree 이동 순서와 ABI 차이를 분리한다.

계산은 모두 Python으로 수행한다. Ghidra 스킬을 보존 export 읽기 전용 분석에 적용하며 문서와 정적 증거만 추가한다. 원본·참고 소스·DB·export·기존 확정 보고서·07_kernel은 수정하지 않는다. 신규 독립 계획 검토 미확보 상태이며 새 실행 검증 프로그램·동적 실행·구현·GCC 2.7 빌드, 이전 실패 검토의 우회/재요청을 하지 않는다.

traverse 및 table allocator의 전이적 구현, space 생성/파괴, wait/wakeup/runtime 경합, table 크기 원장/overflow 도달성, 모든 caller의 권한 초기화는 완료 판정에서 제외한다. 전체 원본 분석 목표는 그대로 유지한다.

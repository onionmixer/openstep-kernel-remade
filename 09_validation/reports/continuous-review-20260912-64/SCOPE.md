# IPC 순회 삭제와 table 크기·메모리 관리

보고서 63 후속으로 splay traverse start/next/finish, table fill/init/alloc/realloc/free를 원본 전체 본문과 참조 소스에 대조한다. realloc의 실제 object 공유를 확인하기 위해 kmem_realloc을 포함하고 page-size 설정은 원본 store window와 vm_set_page_size를 구분하여 확인한다.

Ghidra 스킬은 보존 export 읽기 전용 비교에 적용한다. 계산은 모두 Python으로 수행하며 문서·정적 증거만 추가한다. 크기 수열을 계산하는 경우 원본 명령어의 정수식에 대한 조건부 산술로 표시하고 실제 초기화 실행/부팅 검증으로 취급하지 않는다.

신규 독립 계획 검토 미확보 상태이며 새 실행 검증 프로그램·동적 실행·구현·GCC 2.7 빌드·이전 실패 검토의 우회/재요청은 하지 않는다. 원본·참조 소스·DB·export·기존 확정 보고서·07_kernel은 보존한다. 전이적 allocator/VM/pageable helper, space 생성/파괴와 모든 traversal caller·중도 종료·동시성은 완료 판정에서 제외한다.

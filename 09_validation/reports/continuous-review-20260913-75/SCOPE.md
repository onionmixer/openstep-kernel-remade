# 75차 — 원본 부팅의 페이지 크기·예약 영역·clearing 연결

74차는 실제 진행이었으며 원본 zone backing의 직접 경로를 검증했다. 이번에는 그때
남긴 초기 상태를 원본 entry/caller와 연결한다. 외부 소스·복원 코드는 참고하지 않는다.

선택 대상: `_start`, `_i386_init`, `_setup_main`, `_vm_mem_init`, `_vm_set_page_size`,
`_vm_page_startup`, `_vm_alloc_from_regions`, `_bzero`, `_memset`,
`FUN_0016af6c`의 보존 본문. Ghidra 스킬로 원본 listing과 decompile을 대조하며
Python으로 원본 Mach-O 매핑·심볼·재디코딩·직접/간접 분기 table·유한 산술을 확인한다.

page_size 설정, zdata 예약·clearing, zone bootstrap의 호출 순서가 주요 판단 대상이다.
선택한 상위 함수의 모든 하위 callee·실제 CPU 부팅·fault/인터럽트·전체 메모리 지도까지
자동으로 검증한 것으로 취급하지 않는다. 각 결과에 성립 전제와 미완료 경계를 적는다.

원본·DB·보존 export와 이전 보고서는 수정하지 않는다. 새 커널 코드·복원·빌드·포팅·
실행 검증 프로그램·동적 실행은 없고, 새 독립 계획 검토도 받지 않았다.

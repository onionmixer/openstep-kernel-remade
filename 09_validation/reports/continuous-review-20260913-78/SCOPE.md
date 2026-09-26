# 78차 — 원본 PTE/PV 제거와 page free queue 반환

77차에서 남긴 실제 매핑 제거·페이지 반환 경계를 계속 분석한다. 대상은 원본의
pmap_remove_all(0x18fb0c), FUN_0018f7f8, vm_page_free(0x17b540),
FUN_00190f90, vm_page_addfree(0x17b5f8), vm_phys_to_vm_page(0x178894) 본문이다.

다른 프로젝트 소스나 복원 코드는 참고하지 않는다. 원본 kernel bytes와 보존 Ghidra
asm/C/메타데이터 및 원본 nlist/문자열만 의미 판단의 근거로 쓴다. Ghidra 스킬은
기존 export 읽기·원본 대조에 한정한다. 모든 주소·폭·분기·크기·해시는 Python으로 계산한다.

특히 첫 PTE와 sibling 처리 차이, PV 목록과 PTE 변경 순서, 함수별 lock 보유/소비,
분기의 존재와 산술적 도달 가능성, hash/object/active/inactive/free 목록 반환 경계를 검토한다.
선택 본문 검토를 전체 물리 메모리 수명·native TLB·동시성·모든 caller 완료로 승격하지 않는다.

원본·DB·보존 export·이전 보고서는 수정하지 않는다. 구현·빌드·포팅·새 실행 검증 프로그램,
동적 실행·새 독립 계획 검토는 수행하지 않는다.

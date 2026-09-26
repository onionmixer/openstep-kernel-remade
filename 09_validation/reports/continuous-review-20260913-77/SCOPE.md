# 77차 — 원본 VM entry 삭제·객체 참조·pmap 정리 경계

76차의 VM 반환 wrapper 다음인 vm_map_delete를 이어서 분석한다. 현재 목표는 OPENSTEP
원본 커널 분석뿐이며 외부 프로젝트 소스·복원 코드는 사용하지 않는다.

대상 보존 본문은 vm_map_delete(0x176164), vm_object_page_remove(0x179bbc),
vm_object_pmap_remove(0x179350), vm_fault_unwire(0x1735f4), vm_object_reference(0x178c30),
vm_object_deallocate(0x178c64), pmap_remove(0x18fa44), pmap_destroy(0x18f69c)다.

Ghidra 스킬의 원본 asm/C 대조를 적용하고 Python으로 원본 Mach-O mapping·nlist·재디코딩,
entry 분할·참조 카운터 폭·구간 및 비트 산술·해시를 확인한다. 특히 빈 구간에서의 앞쪽
분할, 제거 전 next 저장, lock 소비, C에서 생략된 control-register 동작을 검토한다.

선택한 함수 본문의 검토가 모든 하위 페이지/PV/객체 종료·native fault/TLB/동시성 완료를
뜻하지는 않는다. 원본·DB·보존 export·이전 보고서는 수정하지 않는다.
구현·빌드·포팅·새 실행 검증 프로그램·동적 실행·새 독립 계획 검토는 없다.

# 79차 — 원본 object 종료·cache trim·pager 해제 경계

78차의 page free 경로를 object 수명과 연결한다. 원본 vm_object_terminate,
vm_object_remove, vm_object_deactivate_pages, vm_object_cache_trim, vm_object_lookup,
vm_object_cache_object, vm_page_deactivate, vm_pager_deallocate, thread_sleep,
device_dealloc, vnode_dealloc, vm_page_remove, lock_write의 보존 본문을 검토한다.
lock_write는 vnode 경로의 보존 레지스터·대기/반환 계약을 원본에서 확인하기 위해 포함했다.

Ghidra 스킬의 원본 asm/C 대조를 적용한다. 다른 프로젝트 코드·01_resources·07_kernel을
참고하지 않는다. 원본 바이너리, 원본 nlist·문자열과 보존 export/분석 메타데이터만 사용한다.
주소·분기·폭·해시·유한 산술은 Python으로 확인한다. 새 실행 검증 프로그램, 구현·빌드·포팅,
동적 실행·새 독립 계획 검토는 없다. 원본·DB·기존 export·이전 보고서는 수정하지 않는다.

object lock 소비, sleep 등록과 전달 lock 해제, cache 재참조, page 목록 제거와 반환의
차이, pager 분기와 vnode bitmap/집계·간접 VFS 호출 경계를 구분한다. 선택 본문 전체를
읽어도 모든 하위 callee·writer·간접 target·native fault/동시성이 완료된 것으로 보지 않는다.

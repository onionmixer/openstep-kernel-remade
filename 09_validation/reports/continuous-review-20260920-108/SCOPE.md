# 범위와 방법

OPENSTEP x86 원본 `mach_kernel`과 그 full-pass5 export만 사용했다. 실행, 에뮬레이션,
재구성 코드 및 외부 커널 소스는 사용하지 않았다.

대상은 `_i386_init`, `_vm_set_page_size`, `_vm_mem_init`, `_vm_page_startup`,
`_vm_page_init`, `_vm_object_init`, `_vm_map_init`, `_vm_map_create`, `_vm_map_insert`,
`_vm_map_pageable`, `_vm_map_entry_delete`, `_vm_map_delete`, `_pmap_bootstrap`,
`_pmap_init`이다. 구조체 field명·자료형은 원본 명령만으로 확정하지 않았다.

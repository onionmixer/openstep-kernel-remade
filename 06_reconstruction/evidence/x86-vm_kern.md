# x86 `src/vm/vm_kern.c` (plan 243 (S5-P228), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 243 (S5-P228). Final run `s5p228-it6`; 07 file SHA-256 `01f5d05a9dea4661430105556707d807b74f85a78d4ffac3c3a894abee4a6077`; diff `x86-vm_kern.diff`.

- Object [0x173ad4, 0x174600) 2860 B, 14 functions (_kmem_alloc, _kmem_realloc, _kmem_alloc_wired, _kmem_alloc_pageable, _kmem_free, (static kmem_alloc_pages), _kmem_suballoc, _kmem_init, _copyinmap, _copyoutmap, _kmem_alloc_zone, _kmem_mb_alloc, _kmem_alloc_wait, _kmem_free_wakeup). Front `ec 5d c3 00`, back `55 89 e5 68`, next symbol 0x174600.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p228-it6-l1-vm_kern-F-20261002.json`). Grade **A**.

Object extent [0x173ad4, 0x174600) 2860 B (front 0x173ad3 00 after vm_mem_init of the confirmed vm_init object; the end seam to _vm_map_init has no padding, boundary inferred), 13 symbols plus the static page helper at 0x173ebc. __DATA,__data [0x1e09fc, 0x1e0a73) 119 B: kmem_realloc (twice), kmem_suballoc 1/2/3, You fool!, mb_map abused even more than usual -- verified by L1. The codex review of plan 243 found two corrections (adopted): kmem_mb_alloc compares max_protection with VM_PROT_ALL (0x174371) and protection with VM_PROT_DEFAULT, and kmem_realloc has no remap of the old pages. Scratch builds s5p228-it1..it4 (07 untouched; companion staging for kern/thread.h): it3 matched all but kmem_alloc/kmem_alloc_wired/kmem_alloc_zone, where the original reads vm_map_min before rounding size; it4 OBJECT_MATCH. 07 builds it5 (relcheck 0) and it6 (after adding the Mach4 notice) OBJECT_MATCH.

## plan 400 고침(2026-10-08)
- plan 400: file-scope vm_map_t kernel_map added (Mach4 kernel/vm/vm_kern.c:55); the extern inside kmem_init kept
- 공통 기호 정의만 늘어 `__text`·`__data` 바이트는 바뀌지 않았습니다: plan 400 재빌드(s6l2-*, 402 객체)에서 이 객체의 L1 이 plan 398 결과와 같습니다. 07 파일 SHA-256 `d2fd61b3bb00cbe00d4f533cc912ec2eac7f1f761bbfaf1ad311208947d5ea20`.
- diff `06_reconstruction/evidence/x86-vm_kern.diff` 를 다시 만들었습니다.

## plan 404 고침(2026-10-08, D061)
- notice added: line marked plan 400 (Mach4): CMU and Utah notice in file (07_kernel/LICENSES/CMU-UTAH-MACH4.txt). 주석만 바뀌었습니다(07 파일 SHA-256 `93b00d970ac543b52c5bf3def8b8ebea810c077a3b3738a04cfa16af0173a99d`); diff 를 다시 만들었습니다.

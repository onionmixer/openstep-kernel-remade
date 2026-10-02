# x86 `kern/syscall_subr.c` (S5-P111..S5-P112, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 137.2, 138, 138.1.
Runs `s5p111-diag-7`, `s5p112-build-1` (failed: NeXTMach `sys/kern_return.h` needs `machine/kern_return.h`),
`s5p112-build-2` (final). 07_kernel file SHA-256 `d6a7fba569eb7cbb29ed1aa11c7ae157857b4d47bca5491306dd7441c3823099`; diff `x86-syscall_subr.diff`.

- Object [0x165380, 0x165949) 1481 B, 10 functions: the 9 Darwin functions `_swtch_continue` .. `_thread_depress_abort`
  (1028 B, same order) and `_map_fd` 0x165784 (453 B).
  - Front 3 x `00`: confirmed `x86-sched_prim` ends at 0x16537d.
  - Back 3 x `00`: confirmed `x86-syscall_sw` at 0x16594c.
- `_map_fd`: the original call sequence (`_getf`, `_vm_allocate`, `_copyout`, `_vm_deallocate`, `_copyin`,
  `_vm_map_check_protection`, `_vnode_pager_setup`, `_pmap_create`, `_vm_map_create`, `_vm_allocate_with_pager`,
  `_vm_map_copy`, `_vm_deallocate`, `_vm_map_deallocate`, then `_active_u`) is NeXTMach `mk-108.1/kern/syscall_subr.c:637`
  `map_fd`; the tail reads `vm_info->cred` at +0x30 (NeXTMach `kern/mfs.h` `struct vm_info`) and increments the
  16-bit `cr_ref` (`crhold`). Darwin's `map_fd` is in `bsd/kern/kern_mman.c` instead.
- 07 file = Darwin text + appended NeXTMach notice, `#import <sys/user.h>`, `#import <kern/mfs.h>` and the NeXTMach
  block :620-741; two NeXTMach-only include names replaced (`sys/kern_return.h` -> `mach/kern_return.h`,
  `vm/vm_param.h` -> `mach/vm_param.h`). NeXTMach `kern/mfs.h` adopted verbatim. BSD headers (vnode, file, user,
  ucred) are the SDK set (D021).
- Final build `s5p112-build-2`: final flags OBJECT_MATCH 10/10 (`09_validation/reconstruction/s5p112-l1-syscall_subr-F-20261002.json`);
  the `-fno-common` variant matches all 10 functions but leaves `__data`/`__common` unplaced (`-N-`).
- Grade **A**; 10 functions high (9 Darwin, 1 NeXTMach).

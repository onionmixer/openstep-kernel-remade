# x86 `vm/vm_init.c` — `_vm_mem_init` (S5-P15, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Source: Darwin 0.1 `kernel/vm/vm_init.c` with one restoration edit (diff `x86-vm_init.diff`, edited file
SHA-256 `ee34f01b8d7c9bbbf97e07cb3e7273eac21a64422c061c392bc352221dca11c9`). The added line `vm_pager_init();` is taken from NeXTMach
(https://github.com/johnsonjh/NeXTMach.git f6bdb9c3268f0eadc545d41bcc0564453b17001e, `mk-108.1/vm/vm_init.c:91`). Plan 39, 39.1, 39.2.

- Original object: `__text` 0x173a68–0x173ad3 (107 B), no data. Front gap 0 (`_vm_fault_wire_fast` ends at
  0x173a68), back gap 0x173ad3 `00`; next `_kmem_alloc` 0x173ad4 (vm_kern.c).
- Darwin lacks only the `vm_pager_init()` call at 0x173ac5 (between `_kalloc_init` 0x173ac0 and `_vm_user_init`
  0x173aca); NeXTMach has it in the same place but uses `kallocinit()`; Mach4 differs in structure.
- New option `MACH_XP` = 0 (generated `07_kernel/generated/mach_xp.h`). Regression `s5p15-regress-2`: 24/24
  confirmed objects rebuilt from 07_kernel with identical SHA-256 (`09_validation/reconstruction/s5p15-regress-20261001.json`;
  `s5p15-regress-1` failed only because the memcmp command from S5-P1 used an old staging path).
- Diagnostic `s5p15-pre-1` (unedited Darwin): 51 files read, 50 already in 07_kernel, `vm/vm_init.c` adopted;
  undefined in conditionals only the undetermined VM options and `MACH_LDEBUG`. Control object `__text` 102 B
  (17 relocations) = edited minus one 5-byte call.
- Build `s5p15-build-1`: `-O2` = `-O3` = `-O4`, object SHA-256 `05b9a172f34cc66a0ce37e12194a81155e84945ee19db7c04f8cdb0ccddfe4fa`, `__text` 107 B, 18 relocations.
  Prediction (plan 39 design 4) said 11 calls / 19 relocations — miscount; the function makes 10 calls (18 relocations, Python).
- L1 (`09_validation/reconstruction/s5p15-l1-O3-20261001.json`): OBJECT_MATCH, MATCH, 0 byte differences, 18 references equal.
- Boundary certificate: alignment 2^2, front 0 (aligned), back 1 x `00` (minimum fill) → grade **A**.
- Option: `MACH_XP` = 0 confirmed by bytes (`#if MACH_XP` branch is empty; the original calls `vm_user_init`).

# x86 `vm/vm_fault.c` (S5-P65..S5-P68, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 91.2, 93, 93.1, 93.2, 94, 94.1. Run IDs `s5p65-pre-vm_fault`, `s5p67-probe-1`,
`s5p68-build-1`. 07_kernel file SHA-256 `3b261e54b3bdad4209f092775684a644a1e4745b68f973e0865574449c936fa6`; diff `x86-vm_fault.diff` (probe diff `x86-vm_fault-probe1.diff`).

- Original `__text` [0x172038, 0x173a68) 6704 B, 5 functions: `_vm_fault`, `_vm_fault_wire`, `_vm_fault_unwire`
  0x1735f4, `_vm_fault_copy_entry`, `_vm_fault_wire_fast`.
  - Front 0 B: `ret` at 0x172037 ends Ghidra `FUN_00171f6c` (no original symbol); 0x172038 is 4-aligned.
  - Back 0 B: confirmed `x86-vm_init` starts at 0x173a68.
- Darwin as is: 6688 B. `_vm_fault_unwire` 152/168: Darwin `continue`s where the original panics with
  "unwire: page not in pmap" (string 0x1e09c1; NeXTMach `vm_fault.c:1251-1253`). One restoration edit (variant 1).
- Final build `s5p68-build-1`: `-O3` = common variant `9148cba6…` (= probe; no common), `-O2` differs; both `.i`
  identical. `__text` 6704 B, 275 relocations; `__data` 282 B.
- L1 OBJECT_MATCH 5/5 (`09_validation/reconstruction/s5p68-build-l1-vm_fault-O3-20261002.json`). `__text` placed by symbols; `__data` inferred at 0x1e08e2 and verified by L1d
  (precedent `x86-PCemulateREAL`).
- Grade **A**; 5 functions high. All 90 files named in `vm_fault.i` exist in 07_kernel.

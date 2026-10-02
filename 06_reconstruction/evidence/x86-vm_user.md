# x86 `vm/vm_user.c` (S5-P37, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/vm/vm_user.c` with `vm_reallocate` and `vm_wire` removed (restoration edit, D014 R2). Diff against Darwin:
`x86-vm_user.diff`. Plan 63, 63.1, 63.2. Run IDs `s5p38-*`.

- Original `__text` [0x17c4e0, 0x17c942) 1122 B, 11 functions; `__data` 26 B at 0x1e0e3d; commons `_vm_alloc_lock`
  (0x1f64c0, gap 12) and `_vm_stat` (0x1f64f0, gap 52). Gaps: front 0 B (`ret` at 0x17c4df), back 2 x `00`
  (`_vnode_pager_vput` 0x17c944).
- Diagnostic `s5p38-pre-1` (Darwin verbatim): all 11 original spans equal; extra `_vm_reallocate`, `_vm_wire`
  (1292 B); neither is in the original symbol table.
- Probe 2 = final source body. Final 07_kernel build `s5p38-build-1`: `-fno-common` `-O3`
  `a56055a30108c892…` (bytes and references 0 differences, `__common` 64 B ambiguous), common variant
  `7b9ce4fe1e81bc2a…` OBJECT_MATCH 11/11 (52 relocations, `__data` L1d); both preprocessed files identical;
  `-O2` differs. Plan 36.1 checks: relocation positions/widths/pcrel/types equal; bytes outside relocations equal;
  shape differences are 6 scattered VANILLA (`__common` target) -> extern and 5 local -> extern (precedent plan
  56.1); common sizes <= gaps (upper-bound consistency only). Grade **A**.
- Every `src/` file named in the line markers of `vm_user.i` exists in 07_kernel.
- Obligations: MIG routines `vm_wire` (`mach/mach_host.defs:427`) and `vm_reallocate`
  (`mach_debug/mach_debug.defs:217`) when server stubs are reconstructed.

# x86 `kern/ipc_tt.c` (S5-P34, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/kern/ipc_tt.c` with `retrieve_task_self` and `retrieve_thread_self` removed (restoration edit, D014 R2).
Diff against Darwin: `x86-ipc_tt.diff`. `kern/ipc_tt.h` adopted verbatim. Plan 60, 60.1, 60.2. Run IDs `s5p35-*`.

- Original `__text` [0x1593e4, 0x15a39c) 4024 B, 32 functions; `__data` 60 B at 0x1decc4. Gaps: front 3 x `00`
  (after confirmed `ipc_sched`, end 0x1593e1), back 0 bytes (`_space_deallocate` ends with `ret` at 0x15a39b,
  `_host_priv_self` starts at 0x15a39c).
- Diagnostic `s5p34-pre-1` (Darwin verbatim): all 32 original functions have the original spans; the build has two
  extra functions `_retrieve_task_self`, `_retrieve_thread_self` (4176 B). The original inventory has only the
  `_fast` variants (`symbols.tsv`: `_retrieve_task_self_fast` 0x1598a0, `_retrieve_thread_self_fast` 0x159900).
  This shows the named functions are absent, not that no equivalent unnamed code exists elsewhere.
- Both reference candidates (Darwin, Mach4 `kernel/kern/ipc_tt.c:401`, `:428`) contain the two functions; NeXTMach
  has a different IPC structure. Other users: declarations `kern/ipc_tt.h:68`, `:74` (kept) and ppc
  `machdep/ppc/PseudoKernel.c:105` (not in the x86 build); no MIG `.defs` use.
- Probe 1 (Darwin lines 418-471 removed): OBJECT_MATCH 32/32. Final 07_kernel build `s5p35-build-1`: `-O3` =
  variant (`d2731dfd97349b9e6211496622896dc7eae5fb4db3c956c0ac53107934111476`) = probe 1, `__text` 4024 B,
  83 relocations, `__data` 60 B byte-equal (L1d), undefined symbols equal to probe 1 (no non-fast `retrieve_*`);
  `-O2` differs (`8e28b8c3…`). Grade **A**.
- Every `src/` file named in the line markers of `ipc_tt.i` exists in 07_kernel (Python check).

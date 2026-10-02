# x86 `struct task` layout restoration and `kern/ipc_host.c` (S4-B3, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plan 50, 50.1, 50.2.

## struct task (header restoration edits)
- Evidence table `06_reconstruction/struct_layouts/task.tsv`: probe `s4b-task-1` (staging copy only) — Darwin layout
  sizeof 0x84, hypothesis sizeof 0x8c; all 27 fields with original accesses + sizeof match, 0 mismatches
  (`pset_tasks` has no original access found: unverified).
- Edits: `kern/task.h` adds `struct utask *u_address;` before `proc` (name from NeXTMach mk-108.1/kern/task.h:178);
  `mach/mach_param.h` `TASK_PORT_REGISTER_MAX` 3 -> 4 (original `_mach_ports_register`/`_mach_ports_lookup`).
  Diffs `x86-task_h.diff`, `x86-mach_param_h.diff`.
- Regression `s4b-task-regress-1`: 40 confirmed + 2 partial objects identical
  (`09_validation/reconstruction/s4b-task-regress-20261001.json`).
- Known task.c differences left for later: `u_task_zone` allocation + `utask_zero` in `task_create`; `proc` is cleared
  inside `_utask_zero` (0x106dfd), not in `task_create`.

## kern/ipc_host.c (Darwin verbatim)
- Before the edits `_mach_host_self`/`_host_self` read `itk_space` at +0x80 (original +0x88); after: OBJECT_MATCH.
- Original [0x157c40, 0x1581a7) 1383 B, 19 functions, `__data` 75 B at 0x1deba0 (L1d). Builds `s4b-task-ipchost-1`
  (staged) and `s4b-task-ipchost-2` (07_kernel) identical; `-O2` = `-O3` (SHA-256 `692c543a206c53e689b0d6421e49ca2b726728bff726471a666049ea96efc673`).
- Gaps: front 0 (host.o ends at 0x157c40 including its trailing `90 90`), back 1 x `00`, next `_ipc_kobject_server`
  0x1581a8. Grade **A**.

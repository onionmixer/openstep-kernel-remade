# x86 `ipc/mach_port.c` + `mach/port.h` + `MACH_OLD_VM_COPY` (S5-P32, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/ipc/mach_port.c` with restoration edits and Mach4
(https://github.com/openmach/mach4.git 69fa77870f20d854c875135e116ebc80b118e7ff) `old_mach_port_get_receive_status`
(`kernel/ipc/mach_port.c:738-777`); `mach/port.h` with the Mach4 typedef (`include/mach/port.h:146-156`) and
`PORT_BACKLOG_MAX 16`. Diffs against Darwin: `x86-mach_port.diff`, `x86-port_h.diff`. Plan 58, 58.1, 58.2.
Run IDs of this section are `s5p33-*`.

- Original `__text` [0x154b28, 0x156693) 7019 B, 40 functions (Ghidra ranges); `__data` 72 B at 0x1deada.
  Gaps: front 0 bytes (`_msg_receive_continue` ends with `ret` at 0x154b27), back 1 x `00` (next `_ast_init` 0x156694).
- Probes (staging only): 1 Mach4 verbatim — no `old_mach_port_status_t` in Darwin `port.h`; 2 + typedef —
  `mach_port_names` -12, `port_names` -128, `port_set_backlog` +4; 3 Darwin + `MACH_OLD_VM_COPY 1` — `port_names`
  matches, `mach_port_names` +16, `get_set_status` +24, `old_mach_port_get_receive_status` missing, backlog +4;
  4 + `vm_move(..., vm_size_used, ...)` at Darwin :380, :386, :1151 — the original passes the `round_page` result
  (register `esi`); 5 + Mach4 function + `PORT_BACKLOG_MAX 16` — OBJECT_MATCH 40/40.
- `port_set_backlog`: identical source in both references; Darwin's `PORT_BACKLOG_MAX` is
  `((mach_port_msgcount_t) 16)` (unsigned compare), the original's `lea eax,[edi-1]; cmp eax,0xf; jbe` is the folded
  signed range test of int `16` (NeXTMach `sys/port.h:143`, Mach4 `include/mach/mach_param.h:49`).
- `MACH_OLD_VM_COPY = 1` (confirmed): undefined symbols `_vm_move`, `_vm_map_pageable`, `_ipc_soft_map` belong to
  the `MACH_OLD_VM_COPY` branches (`#else` uses `vm_map_wire`/`vm_map_unwire`/`vm_map_copyin`); L1 requires equal
  references. Other users (`ipc_kmsg.c`, `ipc_init.c`, `mach_debug.c`, `zalloc.c`, `bsd/kern/init_main.c`) are not
  yet verified with it.
- Final 07_kernel build `s5p33-build-1`: `-O3` = variant
  (`5e1ff61388469df398d8b273ca6565365889b3022fa01c3777f9746afc534717`), equal to probe 5 (added notice and comment
  lines do not change bytes); 164 relocations; `__data` byte-equal (L1d); no common/zero-fill storage. `-O2`
  (`9aed1e21…`, 6059 B) differs. L1 reports `09_validation/reconstruction/s5p33-build-l1-mach_port-O3-20261001.json`,
  `-O3c-`. Grade **A**.
- Regression `s5p33-regress-1` (port.h and meta_features.h changed): 47 confirmed + 3 partial objects rebuilt,
  50/50 SHA-256 equal to the baseline (`08_build/runs/tools/s5p33-regress-baseline.json`: `s5p30-regress-1`,
  `s5p30-build-1` ipc_notify, `s5p32-build-1` ipc_right).
- Licensing: Darwin APSL header and CMU notice kept; Mach4 notice (CMU + University of Utah/CSL, Mach4 lines 1-28)
  added for the inserted function, supporting copy `07_kernel/LICENSES/CMU-UTAH-MACH4.txt`.

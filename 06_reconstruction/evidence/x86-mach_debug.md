# x86 `ipc/mach_debug.c` (S5-P33, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/ipc/mach_debug.c` with one Mach4 line (https://github.com/openmach/mach4.git
69fa77870f20d854c875135e116ebc80b118e7ff `kernel/ipc/mach_debug.c:195`) and three authored initialisers (D016,
plan 48 W1-W6). Diff against Darwin: `x86-mach_debug.diff`. Plan 59, 59.1, 59.2. Run IDs `s5p34-*`.

- Original `__text` [0x151cbc, 0x1525a7) 2283 B, 6 functions; no object-owned data (external `_page_mask`,
  `_ipc_kernel_map`, `_ipc_soft_map`). Gaps: front 3 x `00` (after confirmed `ipc_thread`, end 0x151cb9), back
  1 x `00` (next `_mach_msg_send` 0x1525a8).
- Diagnostic `s5p34-pre-1` (Darwin verbatim): only `mach_port_space_info` 12 B short.
- Probe 1 (`table_size = 0`, `tree_size = 0`): `mach_port_space_info` matches; `host_ipc_hash_info` and
  `host_ipc_marequest_info` differ in 17 B each (no `xor edi,edi`). Probe 2 (+ `size = 0` in both): OBJECT_MATCH
  6/6. Neither probe had a written prediction (W6 deviation, recorded in plan 59.1); reasons were the original
  instructions below.
- Evidence for the initialisers: `mov [ebp-0x1c],0` 0x151f69 (`table_size`, stored at 0x15207e and passed to
  `kmem_alloc`), `mov [ebp-0x28],0` 0x151f70 (`tree_size`, 0x152112), `xor edi,edi` 0x151d0d and 0x151e39 (`size`,
  passed to `kmem_free`/`kmem_alloc_pageable`).
- W1: Darwin has none of the four; Mach4 has only the `host_ipc_marequest_info` one (used verbatim, with its
  comment) and lacks the `MACH_OLD_VM_COPY` code; NeXTMach has no `mach_debug.c`. The other three are authored and
  marked in the file; they are not claimed to be the historical text.
- Final 07_kernel build `s5p34-build-1`: `-O3` = variant = `-O2`
  (`7c7da496a90c089c049e92f46a8affa505193982199e77577eee06301f4b0cbc`), equal to probe 2; 71 relocations;
  no common/zero-fill storage. OBJECT_MATCH 6/6 (`09_validation/reconstruction/s5p34-build-l1-mach_debug-O3-20261001.json`).
  Grade **A**. `-O2` giving the same bytes means this object says nothing about the optimisation level.
- No header or generated change: the 136 other staged inputs of probe 2 have the same SHA-256 as the current
  sources (after `s5p33-regress-1`), so no regression was run.
- Correction (plan 60.1): `mach_debug/ipc_info.h`, which appears in `mach_debug.i`, had been left out of 07_kernel
  in this round. It was adopted verbatim afterwards; the rebuild `s5p35-build-1` from 07_kernel gives the same
  SHA-256 `7c7da496…` for `-O3`, the variant and `-O2`.

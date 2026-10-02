# x86 IPC `ipc_space.c`, `ipc_hash.c`, `ipc_pset.c` (+ `ipc_object.h`) (S5-P22, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plan 47, 47.1, 47.2.

| object | original `__text` | source | -O3 object SHA-256 (-fno-common / variant) | L1 | gaps | grade |
|---|---|---|---|---|---|---|
| ipc_space | [0x1506b0, 0x150a05) 853 B, 5 functions | Darwin verbatim | `e6472b30ca9d7bc82a8ada3dedc8f21bf4cfcd476fe361144f0eb60091221fdb` / `77b874a085271527fa30ccd88ff442ae7289444b1450f556f7849a8d44de65d2` | variant OBJECT_MATCH, -fno-common 0 byte diff (`__common` order unverified) | 1 x 00 / 3 x 00 | A |
| ipc_hash | [0x146908, 0x146dbe) 1206 B, 11 functions | Darwin + `ipc_hash_lookup` body from Mach4 | `ff34dbaba400624173597d0420414ae1e2bb48a9556a95a65ac641d9900ec3e8` / `d377d6ca2b31191911213b1338cb9e8d109b69372e3988544454fabf86c38cc7` | variant OBJECT_MATCH, -fno-common 0 byte diff | 2 x 00 / 2 x 00 | A |
| ipc_pset | [0x14d61c, 0x14db06) 1258 B, 6 functions | Darwin verbatim with `ipc_object.h` edit | `ff5990b418672413217b0145d7b39741961a91848e6435432fc9297827a2a444` (both) | OBJECT_MATCH | 2 x 00 / 2 x 00 | A |

- Diagnostic (Darwin verbatim, `s5p22-pre-1`): ipc_hash 1190 B (`_ipc_hash_lookup` 64 B vs 80 B), ipc_pset 1280 B
  (volatile `_refs` spilled in move/destroy). Probe in a staging copy (`s5p22-probe-1`) with the two edits matched;
  07_kernel build `s5p22-build-1` gives the same objects as the probe.
- Common symbols (variant): ipc_space `_ipc_space_kernel`/`_reply`/`_zone` 4 B each, ipc_hash
  `_ipc_hash_global_mask`/`_size`/`_table` 4 B each = original gaps; relocation addresses equal (23, 28), bytes
  outside relocation fields equal.
- Header edit regression `s5p22-regress-1`: 33 confirmed + 2 partial objects identical
  (`09_validation/reconstruction/s5p22-regress-20261001.json`).
- `kern/ipc_sched.c` (seq 160) not adopted: `_thread_handoff` additionally calls `switch_unix_context(new)` before
  `stack_handoff` (original 0x159343 -> 0x106e0c); no reference tree has that function (pending user decision on new code).
- 07_kernel: 113 files read, 103 present, 10 adopted.

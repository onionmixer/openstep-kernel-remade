# x86 `ipc/ipc_right.c` (S5-P31, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Mach4
(https://github.com/openmach/mach4.git 69fa77870f20d854c875135e116ebc80b118e7ff) `kernel/ipc/ipc_right.c` plus four Darwin 0.1 lines (ipc_right.c:2422-2425) and the Darwin APSL header
(diff against Mach4: `x86-ipc_right.diff`). Plan 57, 57.1, 57.2.

- Original `__text` [0x14db08, 0x1506af) 11175 B, 19 functions; `__data` 312 B at [0x1de95a, 0x1dea92). Gaps: front
  2 x `00` (after `_ipc_pset_destroy`), back 1 x `00` (next `_ipc_space_reference` 0x1506b0).
- Probes (staging only): 1 Darwin (one-argument dngrow) 11147 B — `clean`/`destroy`/`dealloc`/`delta` short
  (Mach4 has `mscount = 0` at five sites and earlier range checks); 2 Mach4 verbatim — all but
  `ipc_right_copyin_compat` match, that one 12 B short; 3 Mach4 + Darwin `ipc_hash_delete` — OBJECT_MATCH 19/19.
- Final 07_kernel build `s5p32-build-1`: `-O3` = variant (`a21183582047d7beba6c84c01331797809682733e55a7ead214fb94c7d2e8aeb`), equal to probe 3; 228 relocations, `__data`
  byte-equal; no common/zero-fill storage. `-O2` differs. Grade **A**.
- Licensing: CMU notice (Mach4) and APSL header (Darwin lines inserted) both kept in the file (APSL 1.0 2.1(c)).

# x86 `kern/host.c` — 5 functions (S5-P13, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Source: Darwin 0.1 `kernel/kern/host.c`, verbatim (file SHA-256 `255327c3a6e0a646de7b4fb2a194310ae75bd42059b95874e1491eef8a539830`). Plan 37, 37.1, 37.2.

- Original object: `__text` 0x157958–0x157c40 (744 B, including the trailing `90 90` after the last
  `ret` at 0x157c3d), `__data` 0x1deb90 (16 B, string `"host_processors"`), `__common` `_realhost`
  0x1e97b0 (8 B; next symbol `_log_open` 8 B later).
- Functions: `_host_processors` 0x157958, `_host_info` 0x157a28, `_host_kernel_version` 0x157b7c,
  `_host_processor_sets` 0x157bac (the `#else MACH_HOST` branch, `:341-375`), `_host_processor_set_priv` 0x157c0c.
- Environment: `stage_headers.py --prefer-07` (63 files). Diagnostic preprocessing `s5p13-pre-1`: 46 files
  read, 45 already in 07_kernel, 1 adopted (`kern/host.c`); only `MACH_LDEBUG` undefined (inside
  `MACH_SLOCKS`, already true through `DRIVERKIT=1`). The 07_kernel `.i` (`s5p13-build-1`) equals the diagnostic `.i`.
- Build `s5p13-build-1`: `-O3` = `-O4` (object SHA-256 `ee45757971de3b116e192402ad6030cf4505abb446660708137475e8c2969f22`), `-O2` differs (`__text` 734 B).
- L1 `-O3` (`09_validation/reconstruction/s5p13-l1-O3-20261001.json`): OBJECT_MATCH, 5/5 MATCH,
  `__text` 744 B 0 byte differences, 27 references equal; `__data` placed at 0x1deb90 and equal;
  `__common` placed by symbol `_realhost`. `-O2`: NOT_MATCH (unplaced).
- Common-symbol variant `s5p13-common-1` (no `-fno-common`): `_realhost` becomes a common symbol of
  size 8 (= original gap to the next symbol); `__text` identical outside relocation fields, the same 27
  relocation addresses, no relocation from `__text` targets `__common`; L1 OBJECT_MATCH
  (`s5p13-l1-O3common-20261001.json`).
- Boundary certificate: alignment 2^2, front `00 00` (2 B = minimum fill after `_exception_raise_continue_fast`
  end 0x157956), back 0 (next object `_ipc_host_init` at 0x157c40) → grade **A**. The trailing
  `90 90` is produced by the compiler inside host.o, consistent with "intra-object fill is 90".
- Option consequence: `MACH_HOST` = 0 confirmed by bytes (the MACH_HOST branch iterates `all_psets`; the
  original takes the single default-pset branch).

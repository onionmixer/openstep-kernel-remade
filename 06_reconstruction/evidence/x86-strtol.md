# x86 `bsd/libkern/strtol.c` — first BSD-side object (S5-P52, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/bsd/libkern/strtol.c`, unchanged (notices: APSL, 1995 NeXT, UC Regents four-clause), staged with
`--nextdev` (D018). Plan 78, 78.1, 78.2. Run IDs `s5p51-*`.

- BSD batch diagnostic `s5p51-pre-1` (29 Darwin BSD sources): 17 compile, 12 fail (missing option/generated
  headers such as `quota.h`, `cputypes.h`, `uxpr.h`, `bpfilter.h`, `rev_endian_fs.h`, `kdebug.h`, `kernobjc.h`,
  `loop.h`, `xpr_debug.h`, driverkit private headers; `tcp_output` on undeclared `DBG_*`). Only strtol matched;
  most others differ in size or bytes (candidate build differs — version, configuration or headers).
  Open question: 13 Darwin BSD files test `#if NEXT`/`#ifdef NEXT`, while the builds define only `NeXT`.
- Original `__text` [0x1beb58, 0x1bee8b) 819 B, `_strtol`, `_strtoul`; no relocations, no data. Gaps: front
  2 x `00` (`ret` 0x1beb55), back 1 x `00` (`_Event_server` 0x1bee8c — the rest of objects.tsv seq 344's upper
  bound is Event/audio code, not strtol).
- Final 07_kernel build `s5p51-build-1`: `-O3` = `-O2` = variant = `4392f8a9da471e71…` (= diagnostic); both `.i`
  identical; OBJECT_MATCH 2/2. Grade **A**.
- Adopted verbatim: Darwin `bsd/include/{limits,stdlib,string}.h`; real-machine `nextdev/objc/objc.h`,
  `nextdev/objc/objc-api.h` (SHA equal to the pinned list; license TBD, D017).

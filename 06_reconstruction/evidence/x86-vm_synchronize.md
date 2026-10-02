# x86 `vm/vm_synchronize.c` — first object using OPENSTEP 4.2 headers (D018) (S5-P48, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/vm/vm_synchronize.c`, unchanged. Plan 73, 73.1, 73.2, 74, 74.1, 74.2. Run IDs `s5p47-*`.

- Blocked before by `bsd/sys/param.h:106` `<machine/limits.h>` (plan 40). With `stage_headers.py --nextdev`
  (NeXT roots after all Darwin roots) it resolves to the real-machine headers `nextdev/ansi/machine/limits.h`
  -> `nextdev/architecture/ARCH_INCLUDE.h` -> `nextdev/ansi/i386/limits.h`, all equal to the pinned real-machine
  SHA-256 list `09_validation/reconstruction/s4c-nextdev-headers-20261002.json`; adopted as
  `07_kernel/nextdev/...` (license TBD, D017).
- Build: the usual command plus `-Isrc/nextdev -Isrc/nextdev/bsd -Isrc/nextdev/ansi` at the end of the `-I` list.
  Final build `s5p47-build-1`: `-O3` = `-O2` = variant = `a97565b47d7410a6…` (= probe `s5p47-probe-1`); both `.i`
  identical; every `src/` line marker exists in 07_kernel.
- Original `__text` [0x17b9e0, 0x17bd28) 840 B, 4 functions: `_vm_synchronize` (public) and static
  `map_push_range`, `vm_pageout_page`, `object_push` (no original symbols). OBJECT_MATCH 4/4 with ranges keyed by
  the object symbol names (`ranges-vm_synchronize-objsyms.json`), so the static boundaries are checked too.
  Gaps: front 3 x `00` (`ret` 0x17b9dc), back 0 (`_useracc` 0x17bd28). Grade **A**.
- Also adopted verbatim (Darwin): `bsd/machine/{param,signal}.h`, `bsd/sys/{param,resource,signal,syslimits,time,
  ucred,uio}.h` (APSL; UC notices in the `sys` headers; NeXT notices where present). None of the 64 regression
  sources reads them.
- Limitation found (plan 74.1): earlier L1 runs used Ghidra `FUN_*` range keys, so boundary checks of static
  functions were skipped there; whole-section byte/reference comparison was still done.

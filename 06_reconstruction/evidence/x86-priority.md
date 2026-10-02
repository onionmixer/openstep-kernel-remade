# x86 `kern/priority.c` — `_thread_quantum_update` (S5-P14, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Source: Darwin 0.1 `kernel/kern/priority.c` with one restoration edit (diff `x86-priority.diff`,
edited file SHA-256 `268a566a6ac09db7dadbcaf79c25fb82719cde498f81422fe44fc00b55af4eab`). Plan 38, 38.1, 38.2.

- Original object: `__text` 0x160e84–0x161132 (686 B), no data. Front gap 0x160e81–0x160e84 `00 00 00`,
  back gap 0x161132–0x161134 `00 00`; next `_pset_sys_bootstrap` 0x161134.
- Neither reference text is the original: Darwin guards both `update_priority(thread)` calls with
  `#if NCPUS > 1`, so a uniprocessor build has no call, while the original calls `_update_priority` at
  0x160ef7 and 0x161037; Mach4 calls it unconditionally but tests `policy == POLICY_TIMESHARE`, while the
  original compares with 2 (`!= POLICY_FIXEDPRI`) at 0x160f04, 0x160fe6, 0x161044. NeXTMach has no
  `thread_quantum_update`. Restoration edit: remove the two guard pairs from Darwin.
- Environment: `stage_headers.py --prefer-07` (122 files). Diagnostic `s5p14-pre-1` (unedited Darwin):
  93 files read, 88 already in 07_kernel, 5 adopted verbatim. Undefined in conditionals: `MACH_LDEBUG`,
  `MACH_PAGEMAP`, `MACH_VM_DEBUG`, `NEW_VM_CODE`, `NORMA_VM`, `VM_OBJECT_DEBUG` (VM headers, undetermined
  options, not used by this function), `PRI_SHIFT_2` (only inside `#ifdef PRI_SHIFT_2`). Unedited control
  object: `__text` 662 B, L1 BOUNDARY with 459 differing bytes.
- Build `s5p14-build-1` (edited, before the comment) and `s5p14-build-2` (final file): `-O2` = `-O3` = `-O4`,
  object SHA-256 `955d3c6f4d13b2f7b3386a39b50c8bc4506b8048780b5d6c907a97fa115b9276` in both. The `.i` differs from the diagnostic one only by the two calls.
- L1 (`09_validation/reconstruction/s5p14-l1-O3-20261001.json`): OBJECT_MATCH, MATCH, 0 byte differences,
  18 references equal.
- Boundary certificate: alignment 2^2, front 3 x `00`, back 2 x `00` (both minimum fill) → grade **A**.
- Options: NCPUS = 1 and MACH_FIXPRI = 1 confirmed by bytes; STAT_TIME supported (threshold constant).

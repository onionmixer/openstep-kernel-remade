# x86 `kern/mach_factor.c` — `_compute_mach_factor` (S5-P11, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Source: Darwin 0.1 `kernel/kern/mach_factor.c`, verbatim. Plan 34, 34.1, 34.2.

- Original object: `__text` 0x15c100–0x15c2fc (508 B), `__data` 0x1dee68–0x1dee8c: `avenrun`
  {0,0,0}, `mach_factor` {0,0,0}, static `fract` {800, 966, 983}. The unnamed function before it
  (`FUN_0015c0ac`) belongs to mach_clock.c (`90` fill after `_mach_clock_bootstrap`).
- Environment: `stage_headers.py --prefer-07` (45 files), preprocessing `s5p11-pre-1`: 32 files read,
  31 already in 07_kernel, 1 adopted; only `MACH_LDEBUG` undefined (inside `MACH_SLOCKS`, already true
  through `DRIVERKIT=1`). The 07_kernel `.i` equals the diagnostic `.i`.
- Build `s5p11-build-1`: `-O2` = `-O3` = `-O4`. `__text` 508 B with 12 relocations, `__data` 36 B,
  undefined `_all_psets`, `_all_psets_lock`, `_default_pset` — as predicted.
- L1: MATCH, OBJECT_MATCH with `__text` at 0x15c100 and `__data` at 0x1dee68 (12 references equal).
  This also confirms by bytes the Darwin layout of `struct processor_set` (fields at 264–376 used here)
  and the `processors` link of `struct processor` (+0x134) under the current options.
- Boundary certificate: alignment 2^2, front `00`×1 (minimum fill), back 0 (next object at 0x15c2fc)
  → grade **A**.

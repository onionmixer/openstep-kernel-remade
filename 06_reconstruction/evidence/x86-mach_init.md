# x86 `kern/mach_init.c` (S5-P76, S5-P84, S5-P85, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 102.2, 110-111 (110.1-110.3, 111.1). Run IDs `s5p76-pre-mach_init`,
`s5p84-probe-1/2`, `s5p85-regress-1`, `s5p85-build-1`. 07_kernel file SHA-256 `e7e37884bbd6cf67ccfccbc1a52dd850c0bf9459787cbe158cbe75f1d740ea41`; diff `x86-mach_init.diff`.

- Original `__text` [0x15c828, 0x15c945) 285 B, one function `_setup_main`.
  - Front 1 x `00` (confirmed `x86-mach_header` ends at 0x15c827).
  - Back 3 x `00` (minimal fill; `_fatfile_getarch` at 0x15c948).
- Original calls, in order: `clock_timer_init`, `rqinit`, `sched_init`, `vm_mem_init`, `mach_clock_bootstrap`,
  `init_timers`, `init_timeout`, `startup`; no `printf`; then `mach_net_init` after `cpu_up`.
- Changes against Darwin:
  - Authored `clock_timer_init()` / `mach_clock_bootstrap()` (original symbol names; called without
    declarations because no reference gives their types, and their results are unused).
  - `rqinit()` from NeXTMach `mach_init.c:64`.
  - `printf` removed.
- Options:
  - `MACH_NET` = 1 (config hypothesis; the original calls `_mach_net_init`).
  - The kernel version constants 4/0 come from the real-machine SDK `bsd/sys/version.h`; Darwin's version.h
    has 5/3. Chosen by original bytes (D020); the header is placed at `07_kernel/src/bsd/sys/version.h`.
- Probe 2 (staged meta_features with `mach_net.h`) matched except the 2 version bytes; the final build with the
  SDK version.h gives OBJECT_MATCH.
- Final build `s5p85-build-1`: `-O3` = `-O2` `1b122afc…`, common variant `13617c29…`; both `.i` identical.
  - L1 OBJECT_MATCH 1/1 for both variants (43 references).
  - Sections: `__text` 285 B (align 4, 43 relocations), `__data` 0 B; O3 `__common` 4 B = `_first_thread` (4/4,
    placed by symbol).
- Regression after `MACH_NET`: `s5p85-regress-1`, 80 objects / 86 commands byte-identical to their final builds.
- Grade **A**; `_setup_main` high (authored lines marked). All 110 files named in `mach_init.i` exist in 07_kernel.

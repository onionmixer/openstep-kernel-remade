# x86 `kern/timer.c` (S5-P49, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/kern/timer.c`, unchanged; staged with `stage_headers.py --prefer-07 --nextdev` (D018; previously blocked
by `<machine/limits.h>`). Plan 75, 75.1, 75.2. Run IDs `s5p48-*`.

- Original `__text` [0x16a198, 0x16a35e) 454 B, 6 functions (all with original symbols). Gaps: front 2 x `00`
  (confirmed `time_stamp` ends at 0x16a196), back 2 x `00` (0x16a360 starts unnamed code, attributed — not
  proven — to zalloc's static `zone_free_space_lookup`, called from `_zget_space` at 0x16ae29).
- Final 07_kernel build `s5p48-build-1`: `-O3` = `-O2` = `ae4e93edbb36c642…` (= diagnostic), common variant
  `2561c7734af204a1…`; both `.i` identical; OBJECT_MATCH 6/6 for both (object-symbol range keys).
- Plan 36.1: commons `_current_timer` 4 B (gap 4), `_kernel_timer` 16 B (gap 16); 3 relocations with equal
  positions/width/pcrel/type (2 local -> extern, 1 same kind); bytes outside relocations equal. Grade **A**.
- Adopted verbatim: `bsd/machine/cpu.h`, `bsd/sys/kernel.h`.

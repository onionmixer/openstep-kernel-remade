# x86 machdep/i386 `intr.c` (S5-P21, 2026-10-01) — grade P

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/machdep/i386/intr.c`, verbatim. Plan 46, 46.1, 46.2, 46.3.

- Original object `__text` [0x18b514, 0x18c9da) 5318 B, 33 functions in Darwin order (static inline helpers
  `send_eoi`, `set_elcr`, `set_irq_mask`, `set_masked_ipl`, `set_ipl`, `lower_masked_ipl`, `lower_ipl` are inlined;
  `spl*` from `DEFINE_SPL`/`DEFINE_SPLNOP`). Front 2 x `00` after `_in_cksum` (0x18b512), back 2 x `00`.
- Builds `s5p21-pre-1` (Darwin) and `s5p21-build-1` (07_kernel) identical. `-O3` = `-O4` (SHA-256 `edc64519b753c972708fde99e44a5d94c0607f3173f093088d7a89e2d66573cc`),
  `-O2` differs (2930 B). Variant without `-fno-common`: `b7ece2d517b786d3ccb0c05b36f7a59fb9ce0328b3a9d2c3baaec7a3da7176e8`.
- L1 `-O3` (`09_validation/reconstruction/s5p21-l1-O3-20261001.json`): all 33 functions 0 byte and 0 reference
  differences; 3 MATCH (`_intr_disbl`, `_intr_enbl`, `_ipltospl`), 30 MATCH_UNVERIFIED whose only unverified
  dependency is `__bss`. `__data` 86 B at 0x1e2208 verified (L1d); `__common` `_intr_cnt` placed by symbol.
- `__bss` 266 B (static tables and variables, no symbols): `zerofill_check.py` -> reference-inferred at
  [0x1e7618, 0x1e7722): 341 references, 9 base offsets, 25 target offsets, one Delta 0x1e60f4, aligned, inside the
  original zero-fill `__bss`, no image symbol inside, no overlap with confirmed objects' zero-fill (all in `__common`),
  negative check detected. Circumstantial, not proof of ownership (a coherent shift would pass the same checks).
- `__TEXT,__const` 4 B `18 00 20 00`: no relocation of any kind targets it (349 relocations); it holds the memory
  operands `TSS_SEL`/`LDT_SEL` of the unused inline `ltr()`/`lldt()` (cpu_inline.h:126-140). The same 4 bytes occur
  at 9 places in the original `__TEXT,__const` (0x1d14e4 is a plausible link-order candidate, not unique) -> unplaced.
- Grade **P** (`objects_partial.tsv`). Function rows: 3 `compared/high`, 30 `compared/medium` (README).
- 07_kernel: 114 files read, 105 present, 9 adopted.

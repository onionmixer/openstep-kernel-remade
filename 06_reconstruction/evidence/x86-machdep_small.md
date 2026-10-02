# x86 machdep/i386 `bios.c`, `checksum_16.c`, `ldt.c` (S5-P16, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Sources: Darwin 0.1 `kernel/machdep/i386/{bios,checksum_16,ldt}.c`, verbatim. Plan 41, 41.1, 41.2.
Diagnostic `s5p16-pre-2` (Darwin) and `s5p16-build-1` (07_kernel): identical `.i` and objects; 115 files read,
105 already in 07_kernel, 10 adopted verbatim. `-O2` = `-O3` = `-O4` for each file.

| file | original `__text` | object SHA-256 (-O3) | L1 | gaps (front/back) | result |
|---|---|---|---|---|---|
| bios.c | `_bios32` 0x1871d4–0x1871e6 (18 B) | `63f78ff26e757dfcde1504031f3afbcb5b2f00c1763f6b8a744eef76a9b000a2` | `__text` MATCH, 0 diff, 1 ref; `__bss` 16 B unplaced | 3 x 00 / 2 x 00 | function compared/high; **object not confirmed** |
| checksum_16.c | `_checksum_16` 0x1877f8–0x187842 (74 B) | `ab54682d7dc3e9ecb9c65467304c51bc41c39d9cc515428645b842c431b85266` | OBJECT_MATCH, 0 diff, 0 refs | 3 x 00 / 2 x 00 | grade **A** |
| ldt.c | `_ldt_init` 0x18cbcc–0x18cc25 (89 B) | `064a9990104771000a184b7fbbf492b902c38b88d5ebedd90118d03ad1896a1f` | OBJECT_MATCH, 0 diff, 2 refs; `__data` 28 B at 0x1e2260 equal (24 B `ldt_store` zeros, `ldt` = 0x1e2260) | 2 x 00 / 3 x 00 | grade **A** |

- bios.c: with `NOTYET` undefined, the four function-static variables (bios.c:56–59) are unused but GCC (NeXT cc,
  measured) still emits them as 16 B `__bss` without symbols or references. The original image keeps only external
  symbols, so where (or whether) those 16 B lie in the original `__bss` cannot be shown by L1. Left for S6 (final link layout).
- L1 results: `09_validation/reconstruction/s5p16-l1-<file>-<opt>-20261001.json`.

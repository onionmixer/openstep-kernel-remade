# x86 `kern/kalloc.c` (S5-P58, 2026-10-02; deferred at S5-P35)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 61, 61.1, 61.2, 84,
84.1, 84.2. Run IDs `s5p36-*` (probes), `s5p58-build-1` (final). 07_kernel file SHA-256 `ec69a2e2c40c5ce90a735076fb1fbbdaf0e586da7c2d107e4bf9b0bdc79a1f94`;
diff against Darwin in `x86-kalloc.diff` (probe-4 diff kept as `x86-kalloc-probe4.diff`).

- Original object [0x15a67c, 0x15ab9b) 1311 B, 10 functions: `_kalloc_init` 0x15a67c, `_kalloc_noblock`
  0x15a6ec, `_kalloc` 0x15a75c, `_kget` 0x15a7cc, `_kfree` 0x15a824, `_malloc` 0x15a880, `_calloc` 0x15a910,
  `_realloc` 0x15a9a8, `_free` 0x15ab30, `_malloc_good_size` 0x15ab94 (`55 89 e5 89 ec 5d c3`). Front 0 B (`ret`
  0x15a67b of `_task_secure`, 0x15a67c 4-aligned), back 1 x `00` (`_initKernelStacks` 0x15ab9c; minimal fill to
  2^2).
- Source: Darwin 0.1 `kern/kalloc.c`; `kalloc_zone` (Darwin :261-281, absent from the original) replaced by
  NeXTMach (https://github.com/johnsonjh/NeXTMach.git f6bdb9c3268f0eadc545d41bcc0564453b17001e)
  `mk-108.1/kern/kalloc.c:332-376` with its 1987 CMU / 1985 Avadis Tevanian notice; three authored changes (D016,
  W3 markers on each changed group): realloc NULL -> `malloc(size)` (0x15a9b7), copy length `size` or `*sizep`
  through two `bcopy` calls (0x15aab8-0x15aad1), free NULL test before `sizep` (0x15ab38-0x15ab3c). Variants:
  realloc 2, free 2 (plan 61). Removing the added comments gives the probe-4 staging text byte for byte (checked
  with Python before writing).
- Build `s5p58-build-1` (meta_features.h now with 7 more option imports than at S5-P35): `-O3` `d87a52ac…`,
  common variant `126e1a24…` = probe 4, `-O2` `f48edfd4…` differs; both `.i` identical (`dfee0966…`). Sizes
  `__text` 1311 B / 95 relocations, `__data` 79 B, O3 `__common` 72 B, `__bss` 256 B, 14 undefined symbols — as
  predicted (plan 84.1).
- L1 (ranges keyed by object symbol names, `08_build/runs/s5p58-build-1/ranges-kalloc.json`): common variant 9
  MATCH + `_kalloc_init` MATCH_UNVERIFIED (only `__bss`); 0 byte and 0 reference differences; no BOUNDARY.
  Per-function data dependencies: `_kalloc_init` {__data ok, __bss unverified}, the next eight {__data ok},
  `_malloc_good_size` none. `-O3`: 42 references unverified (`__common`).
- Plan 36.1 correspondence (-O3 vs common variant): 95 relocations at the same addresses with the same width,
  pc-rel and type; 53 same form, 42 local -> extern; bytes outside relocations equal in `__text` and `__data`.
  Commons `_k_zone` 64 / gap 64, `_k_zone_maxsize` 4 / 16, `_kalloc_map` 4 / 16.
- `__DATA,__bss` 256 B (`static char k_zone_name[16][16]`, no original symbol): `zerofill_check.py` (sha256
  `b7276c758a2988a3…`, known `zerofill-known-s5p55-20261002.json`) one plain absolute reference at `__text`+21, delta
  0x1e5529, candidate [0x1e5a98, 0x1e5b98), all checks pass, negative check undetectable with one reference ->
  **reference-inferred-single** (D019; `09_validation/reconstruction/s5p58-zerofill-check-kalloc-20261002.json`).
  Added to `zerofill-known-s5p58-20261002.json` (16 ranges).
- Grade **P** (single reference); functions: 9 high, `_kalloc_init` medium. To be re-judged if the neighbouring
  zero-fill becomes independently fixed (D019).
- All 51 files named in `kalloc.i` already exist in 07_kernel; no header adopted.

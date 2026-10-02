# x86 machdep/i386 `dma_buf.c`, `dbl_fault.c` (S5-P18, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Sources: Darwin 0.1
`kernel/machdep/i386/dma_buf.c` and `dbl_fault.c`, verbatim. Plan 43, 43.1, 43.2.

| file | original `__text` | functions | `__common` (original) | object SHA-256 (-O3; -fno-common / variant) | grade |
|---|---|---|---|---|---|
| dma_buf.c | 0x189748–0x18991c (468 B) | `_dma_buf_initialize`, `_dma_buf_alloc`, `_dma_buf_free`, static `dma_buf_sm_create` (0x1898bc), static `dma_buf_lg_create` (0x1898ec) | `_dma_buf_lg` 0x1f7510, `_dma_buf_sm` 0x1f7520 (16 B each) | `d7e15754ebd01ef9a8224657c61667ff94e415a96412b214d97f26ef9d49b321` / `3d84b6ece7da6c173afb550d1c972500dd0dc0614d5a6daf06028fd64ef94bad` | A |
| dbl_fault.c | 0x18991c–0x189a5c (320 B incl. trailing `90 90`) | `_dbf_init`, `_dbf_handler` | `_dbf_stack` 0x1f7530 (1024), `_dbf_state` 0x1f7930 (92; gap 96), `_dbf_tss` 0x1f7990 (104) | `1bf5845bf9e656d8761ffce283946916d84afcd7494f6aced197da554bb74235` / `95f5400d2e0a5b4284109a8faf10b033999a932fdde024c08b897fb0e807aee5` | A |

- Builds `s5p18-pre-1` (Darwin) and `s5p18-build-1` (07_kernel) are identical (`.i` and all objects); `-O2` = `-O3` = `-O4`.
- `-fno-common` objects: `__text` 0 byte differences; references into `__common` unverified because the section
  cannot be placed by one offset (original `__common` is name-ordered). Variant without `-fno-common`: OBJECT_MATCH,
  same 24 / 23 relocation addresses, identical bytes outside relocation fields, common sizes <= original gaps.
- Tool limitation seen: in the `-fno-common` dbl_fault object the empty `__data` section shares its address with
  `__common`, so scattered relocations were attributed to `__data` and `_dbf_init` was labelled DIFF with 0 byte
  and 0 reference differences.
- Boundaries: dma_buf front 3 x `00` after `_get_dma_count` (0x189745), back 0; dbl_fault front 0, back 0 (its
  `__text` contains the trailing `90 90`); next `_copyin` 0x189a5c.
- Prediction error: plan 43 said `_dbf_state` 96 B from the original gap; the type is 92 B.
- 07_kernel: 115 files read, 110 already present, 5 adopted (two `.c`, `dma_buf_internal.h`, `dma_exported.h`, `trap.h`).

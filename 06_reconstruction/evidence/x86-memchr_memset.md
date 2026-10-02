# x86 libc `memchr.c` and `memset.c` (S5-P8, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Plan: `02_plan/RECONSTRUCTION_PLAN.md` 31, 31.1, 31.2.

- `memchr.c`: Darwin 0.1 verbatim. `_memchr` 0x1012d0 is the start of `__TEXT,__text`; object 41 B,
  no relocations; followed by `00`×3 (minimum 2^2 fill) and the memcmp object.
- `memset.c`: Darwin 0.1 with lines 249–338 removed (restoration edit, `x86-memset.diff`). The removed
  part (`set_recover`, `clear_recover`, `safe_bzero`, `safe_memset` and two imports used only by them)
  has no symbols in the original, the memset object ends after `_memset`, and the original
  `_mfs_trunc` (0x15e79f) clears with plain `_bzero` where Darwin `kern/mapfs.c:696` calls
  `safe_bzero` (Darwin `mapfs.c:43–45` records the 1997 mfs→mapfs rename).
- Build `s5p8-build-1`: per file `-O4` = `-O3` = `-O4 -funroll-all-loops`. memset `__text` 958 B,
  `_bzero` 0, `_blkclr` 0x18, `_memset` 0x30, 96 relocations = 91 jump-table entries (three tables in
  `__text` at 0x101670/0x1017c0/0x101900 with 31/31/29 entries) + 3 table bases + 2 calls (Python).
- L1: four functions MATCH, both objects OBJECT_MATCH (`09_validation/reconstruction/s5p8-l1-*-20261001.json`).
- Boundary certificates (alignment 2^2): memchr starts the section, back `00`×3; memset front `00`×2,
  back `00`×2 → both grade **A**.

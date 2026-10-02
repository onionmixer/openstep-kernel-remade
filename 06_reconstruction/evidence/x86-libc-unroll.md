# x86 libc "unroll" group: strchr strrchr strlen strcpy strncpy strcat strncat strcmp strncmp index ffs (S5-P9, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Sources: Darwin 0.1 `kernel/machdep/i386/libc/<name>.c`, all verbatim (11 files, no includes).
Plan: `02_plan/RECONSTRUCTION_PLAN.md` 32, 32.1, 32.2.

- Darwin `conf/Makefile.i386:84–91` compiles exactly these files with `-O4 -funroll-all-loops` and
  links them right after the six `LIBC_SRC` objects (`:68`); the original has them in that order at
  0x101a10–0x1020ac.
- Build `s5p9-build-1` (one compilation each with `-O4 -funroll-all-loops`, `-O4`, `-O3`, plus `-E`):
  all exit 0; `ffs.c:40` warns "conflicting types for built-in function `ffs'" (warning only).
  `__text` sizes equal the original function sizes (41, 187, 77, 117, 248, 181, 265, 127, 197, 41, 188 B),
  no relocations, no external symbols (`09_validation/reconstruction/s5p9-summary-20261001.json`).
- L1: with `-O4 -funroll-all-loops` all eleven objects OBJECT_MATCH. With `-O4` or `-O3` nine differ
  (only `strchr` and `index`, which have no loop to unroll, are option-independent) → the unroll
  option is confirmed by bytes (also seen in S1-C for `strcpy`/`strcmp`).
- `_index` and `_strchr` are byte-identical in the original (41 B each).
- Boundary certificates: every gap is `00` with the minimum 2^2 fill (first gap after `_page_copy`
  0x101a0e, last object ends at 0x1020ac where `_rpause` starts) → eleven objects grade **A**.

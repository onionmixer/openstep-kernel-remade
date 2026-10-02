# x86 `kern/mach_header.c` (S5-P76, S5-P81..S5-P83, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 102.2, 107, 107.1, 107.2, 108-108.4, 109, 109.1. Run IDs
`s5p76-pre-mach_header`, `s5p81-probe-1`, `s5p83-build-1`. 07_kernel file SHA-256 `5af6b6298365aa8f1ab93a824cc3a10012cc6fa4f795dd7b392fa091474557bb`; diff
`x86-mach_header.diff`.

- Object [0x15c2fc, 0x15c827) 1323 B: 14 original symbols plus the static `getsizeofmacho` at 0x15c7a4 (Ghidra
  FUN_0015c7a4; called by `_getfakefvmseg`). objects.tsv seq 172 ends at 0x15c7a2, which is too short: the object
  continues after the `90 90` with `getsizeofmacho`.
  - Front 0 B: confirmed `x86-mach_factor` ends at 0x15c2fc.
  - Back 1 x `00` (minimal fill); original `_setup_main` at 0x15c828.
- One restoration edit: `getsegdatafromheader` removed (not in the original).
- 16 references to `__mh_execute_header` are verified against the original ABS symbol (0x100000 = `__TEXT`
  vmaddr, fileoff 0); `l1_compare.py` resolves nonzero ABS symbols for external relocations (plan 108.3,
  `test_l1_abs.py`).
- Final build `s5p83-build-1`: `-O3` and common variant byte-identical to probe `s5p81-probe-1`; both `.i`
  identical.
  - L1 OBJECT_MATCH 15/15 (49 references).
  - `__data` 131 B inferred at 0x1dee8c and verified by L1d; common `_fvm_seg` 4/4 by symbol.
- Grade **A**; 15 functions high. Adopted with this object:
  - Darwin `kern/mach_header.h` (verbatim).
  - Real-machine SDK `mach-o/loader.h` (verbatim, SHA matches the real-machine list; license TBD, D017).

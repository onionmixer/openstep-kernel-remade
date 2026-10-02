# x86 libc `memcpy.c` and `memmove.c` (S5-P7, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Plan: `02_plan/RECONSTRUCTION_PLAN.md` 30, 30.1, 30.2.

- Original layout: `_bcopy` 0x1013cc → `_memcpy` 0x1013e4 → `90` → `_bcopy16` 0x101488 → `_ovbcopy`
  0x1014ec → `_memmove` 0x101504 → end 0x1015fe. `_bcopy` calls `_memcpy(dst, src, len)` (0x1013db),
  `_ovbcopy` calls `_memmove` (0x1014fb). Darwin 0.1 keeps `bcopy` in `memmove.c` and calls `memmove`.
- Restoration edit (D014): `bcopy` moved to `memcpy.c` after the `memcpy` prototype and calling
  `memcpy` (`x86-memcpy_memmove.diff`). Neither file includes headers.
- Build `s5p7-build-1` (`-O4`, `-O3`, `-O4 -funroll-all-loops` identical per file):
  memcpy `__text` 288 B, `_bcopy` 0, `_memcpy` 0x18, `_bcopy16` 0xbc; memmove 274 B, `_ovbcopy` 0,
  `_memmove` 0x18 — all as predicted. One relocation each (the call).
- L1: five functions MATCH, both OBJECT_MATCH (`09_validation/reconstruction/s5p7-l1-{memcpy,memmove}-*-20261001.json`).
  The `90` at 0x101487 is inside the compiled memcpy object, so `bcopy16` belongs to the same object
  as `memcpy` (two objects, not three; plan 30.1). The register difference between `_bcopy` (EAX) and
  `_ovbcopy` (EDX) is reproduced by the compiler without further change.
- Boundary certificates (alignment 2^2): memcpy front `00`×1, back 0 (0x1014ec aligned); memmove
  front 0, back `00`×2 → both grade **A**.

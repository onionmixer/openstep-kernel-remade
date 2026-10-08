# x86 `src/driverkit/memcpy.c` (plan 284 (S5-P274), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 284 (S5-P274). Final run `s5p274-it1`; 07 file SHA-256 `7c4dcb18998da5173ac1c0ef28bacfb095267fe319d04d7bef6086b4ccb8a6b3`; diff `x86-memcpy.diff`.

- Object [0x1a5618, 0x1a5711) 249 B, 1 functions (__IOCopyMemory). Front `c3 00 00 00`, back `00 00 00 55`, next symbol 0x1a758c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p274-it1-l1-memcpy-F-20261002.json`). Grade **A**.

Object extent [0x1a5618, 0x1a5711) 249 B + 00 00 00; front generalFuncs.m, next IODisk.m 0x1a5714. No data. References by file name: Darwin 0.1 driverkit-1/libDriver/i386/memcpy.c (structure), libDriver/ppc/memcpy.c (_IOCopyMemory with a byte loop, unused), Libc and kernel/machdep libc memcpy.c (other functions, unused); no NeXTMach or Mach4 file. D029 does not apply (not a Darwin kernel/machdep file); D027 authoring. Scratch s5p274-w1 OBJECT_MATCH. The codex review of plan 284 confirmed the bytes and asked for the uncapped alignment copy, the arithmetic shifts and the ppc file to be stated (verified, fixed). it1 (s5p274-it1) from 07 OBJECT_MATCH, relcheck 0.

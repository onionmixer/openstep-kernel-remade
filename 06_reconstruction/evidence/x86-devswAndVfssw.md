# x86 `src/driverkit/libDriver/Kernel/devswAndVfssw.m` (plan 375 (S5-P356), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 375 (S5-P356). Final run `s5p375-it1`; 07 file SHA-256 `eb24870273afd8589081414af9ec711f4691b05ae73a60c993c11c2d4c6d2a61`; diff `x86-devswAndVfssw.diff`.

- Object [0x1a9ad4, 0x1a9f19) 1093 B, 9 functions (_IOAddToBdevswAt, _IOAddToBdevsw, _IORemoveFromBdevsw, _IOAddToCdevswAt, _IOAddToCdevsw, _IORemoveFromCdevsw, _IOAddToVfsswAt, _IOAddToVfssw, _IORemoveFromVfssw). Front `ec 5d c3 00`, back `00 00 00 55`, next object IOEthernet 0x1a9f1c (its first method).
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p375-it1-l1-devswAndVfssw-F-20261002.json`). Grade **A**.

Kernel bdevsw/cdevsw/vfssw registration (driverkit). __text [0x1a9ad4, 0x1a9f19) 1093 B + 00 x 3 (IOEthernet 0x1a9f1c); 9 functions (IOAddToBdevswAt, IOAddToBdevsw, IORemoveFromBdevsw, IOAddToCdevswAt, IOAddToCdevsw, IORemoveFromCdevsw, IOAddToVfsswAt, IOAddToVfssw, IORemoveFromVfssw); __DATA,__data [0x1e5100, 0x1e5144) 68 B (static no_cdev 44 B, no_bdev 24 B; memcmp inlined as repz cmpsb against 0x1e512c) verified by L1d. <bsd/sys/buf.h> adds 10 commons (496 B: bfreelist 272, bufhash 192, eight 4 B) found by name in the original. Diagnostics s5p364-ddevsw1/2 (Darwin text vs SDK headers), s5p375-dv0 (seltrue undeclared), s5p375-dv1/dv2 OBJECT_MATCH. Codex review of plan 375 (gpt-6.1-sol) verified (module-name wording and buf.h commons noted). Final s5p375-it1 from 07: OBJECT_MATCH (9 MATCH), relcheck 0.

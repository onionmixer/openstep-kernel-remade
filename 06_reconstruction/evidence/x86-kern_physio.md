# x86 `src/bsd/kern/kern_physio.c` (plan 228 (S5-P208), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 228 (S5-P208). Final run `s5p208-it1`; 07 file SHA-256 `afb0c106bf06a02131cf6f2f265cc194331443b6e022b97938244f15c169ddfa`; diff `x86-kern_physio.diff`.

- Object [0x11eb50, 0x11ed57) 519 B, 2 functions (_physio, _physstrat). Front `89 ec 5d c3`, back `00 55 89 e5`, next symbol 0x11ed58.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p208-it1-l1-kern_physio-F-20261002.json`). Grade **A**.

Object extent [0x11eb50, 0x11ed58): _physio (448 B with 2 nop bytes of alignment) and _physstrat (72 B with one 0x00 byte); the nop fill between them places both in one object, the 0x00 after physstrat is linker fill before _null_init. The previous object vfs_xxx ends at 0x11eb50. objects.tsv lists the two as separate name-based candidates (seq 62, 63, confidence C). Diagnosis s5p208-d1 (NeXTMach vm_swp.c with physstrat and two-argument btodb, staging copy only): physstrat matches, physio differs only by the 7-byte store of 0 into a (0x11eb64). The codex review of plan 228 was checked; its doubt that the range is one object was rejected on the nop fill. Build s5p208-it1: OBJECT_MATCH, relcheck 0.

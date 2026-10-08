# x86 `src/machdep/i386/ev.c` (plan 283 (S5-P273), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 283 (S5-P273). Final run `s5p273-it1`; 07 file SHA-256 `5024c89b0757bbf0f80ec627318c38fb87bea5262ac37034efb37d918a7b1542`; diff `x86-ev.diff`.

- Object [0x19554c, 0x195758) 524 B, 3 functions (_defaultEventSources, _createEventShmem, _destroyEventShmem). Front `89 ec 5d c3`, back `55 89 e5 53`, next symbol 0x195758.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p273-it1-l1-ev-F-20261002.json`). Grade **A**.

Object extent [0x19554c, 0x195758) 524 B (no padding after the object; 0x1956af nop between the two shared-memory functions); front rtc.c (plan 277), next kmDevice.m. __DATA,__data [0x1e36dc, 0x1e3795) 185 B: table {Pointer, Keyboard, NULL}, then the strings Keyboard, Pointer and the three IOLog messages. References by file name: Darwin 0.1 bsd/dev/ev.c (structure), NeXTMach nextdev/ev.c (same driver area, m68k, no counterpart functions; evopen/evmmap path), no Mach4 file. D029 does not apply (Darwin's file is not in kernel/machdep); D027 authoring as for APM_i386.c. Scratch s5p273-w3 OBJECT_MATCH (headers staged with COMPANION). The codex review of plan 283 confirmed the bytes and data; its claim that D029 requires a Darwin-based file was rejected on the wording of D029 (verified), the other points were taken. it1 (s5p273-it1) from 07 OBJECT_MATCH, relcheck 0.

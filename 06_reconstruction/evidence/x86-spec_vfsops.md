# x86 `src/bsd/specfs/spec_vfsops.c` (plan 222 (S5-P202), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 222 (S5-P202). Final run `s5p202-it1`; 07 file SHA-256 `0a9e5c969f5d0bb2ece6fd2060c3a63c07aa2f844e23127c7811e51c4a18fc43`; diff `x86-spec_vfsops.diff`.

- Object [0x139b14, 0x139ba8) 148 B, 3 functions (_spec_badop, (static spec_sync), (static spec_mountroot)). Front `ec 5d c3 00`, back `55 89 e5 83`, next symbol 0x13a27c.
- Final L1 `09_validation/reconstruction/s5p202-it1-l1-spec_vfsops-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Object extent [0x139b14, 0x139ba8) is a reconstruction choice: the inventory range labelled spec_vnodeops starts with the three functions of the _spec_vfsops table (0x1dd6a8: spec_badop x4, spec_sync 0x139b28, spec_badop, spec_mountroot 0x139b9c), which NeXTMach keeps in specfs/spec_vfsops.c; linker 0x00 fill before 0x139b14, no fill at 0x139ba8 (ret then the next function, aligned). The codex review of plan 222 confirmed the table and the functions. Build s5p202-it1 of the unedited NeXTMach file: all 3 functions match, extern relocation names match (relcheck 0); the static spec_lock in __DATA,__bss is reference-inferred (zerofill_check).

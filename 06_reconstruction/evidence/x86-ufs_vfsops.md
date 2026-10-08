# x86 `src/bsd/ufs/ufs_vfsops.c` (plan 216 (S5-P194), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 216 (S5-P194). Final run `s5p194-it3`; 07 file SHA-256 `c31c7bd04c1e1f58097db5b7d7fac10880b159b762eea6704854a52f50142407`; diff `x86-ufs_vfsops.diff`.

- Object [0x143024, 0x143c80) 3164 B, 11 functions ((static ufs_mount), (static ufs_mountroot), (static mountfs), (static ufs_unmount), (static unmount1), (static ufs_root), (static ufs_statfs), (static ufs_sync), _sbupdate, (static getmdev), (static ufs_vget)). Front `c3 00 00 00`, back `55 89 e5 8b`, next symbol 0x14527c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p194-it3-l1-ufs_vfsops-F-20261002.json`). Grade **A**.

Object extent [0x143024, 0x143c80): linker 0x00 fill before 0x143024; ufs_vfsops table entries and function starts match the NeXTMach order of 11 functions; 0x143c80 is the vnodeops vn_devblocksize entry (ufs_vnodeops). Diagnosis 13 failed on nextdev/voldev.h; diagnosis build s5p194-d1 (NeXTMach text without voldev.h, not 07) matched 8 functions. The codex review of plan 216 corrected the function count (11) and was checked; its claim that SBLOCK / devbsize is wrong was rejected (the SDK fs.h NeXT branch defines SBLOCK in bytes). Iterations: it1 only mountfs differs (frame 0x40 larger: variants s5p194-v1, an unused 64-byte local, h1 chosen); it2 sbupdate register (variants s5p194-v2 declarations without effect, s5p194-v3 m1: the block size is held in size); it3 all 11 functions match, extern relocation names match (relcheck 0).

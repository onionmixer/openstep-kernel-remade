# x86 `src/bsd/kern/vfs.c` (plan 164 (S5-P138), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 164 (S5-P138). Final run `s5p138-it4`; 07 file SHA-256 `7afe6b73f9ca3d4c4c52c908e9525d3da29f0c8fe39ab41f6b6f80c012287980`; diff `x86-vfs.diff`.

- Object [0x118d54, 0x119b89) 3637 B, 20 functions (_smount, _sync, _statfs, _fstatfs, _cstatfs, _unmount, _dounmount, _vfssw_lookup, _vfs_mountroot, _vfs_add, _vfs_remove, _vfs_lock, _vfs_unlock, _getvfs, _vafsidtovfs, _vfs_getmajor, _vfs_fixedmajor, _vfs_putmajor, _vfs_getnum, _vfs_putnum). Front `5d c3 00 00`, back `00 00 00 55`, next symbol 0x119b8c.
- Final L1 `09_validation/reconstruction/s5p138-it4-l1-vfs-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE. Iterations: it1 vm/vm_param.h not staged; it2 vfs_mountroot matching, smount 1280/1344; it3 strncpy + AppleShare block, smount 1336/1344; it4 saved_flag = 0 -> __text 3637 B and __data 0 byte differences, 20 functions MATCH (2 MATCH_UNVERIFIED through the __bss reference). Grade P: __bss 16 B reference-inferred.

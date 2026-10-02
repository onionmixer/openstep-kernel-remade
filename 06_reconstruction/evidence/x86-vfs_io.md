# x86 `src/bsd/kern/vfs_io.c` (plan 160 (S5-P134), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 160 (S5-P134). Final run `s5p134-it3`; 07 file SHA-256 `3b3f5207df2bfa686583c0ca69a40273d8667b739066b7d3c5ed258209767f22`; diff `x86-vfs_io.diff`.

- Object [0x11b984, 0x11c0f5) 1905 B, 8 functions (_vno_rw, _vno_ioctl, _vno_select, _vno_stat, _vno_close, _vno_lockrelease, _vno_bsd_lock, _vno_bsd_unlock). Front `5d c3 00 00`, back `00 00 00 55`, next symbol 0x11c0f8.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p134-it3-l1-vfs_io-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE. Iterations: it1 compile error (bool_t before nfs/nfs.h); it2 7 MATCH + vno_bsd_lock DIFF (priority increment through memory in the original); variants on staged copies: v1 set_label (alias of setjmp at 0x186f88) rejected, v2 volatile priority OBJECT_MATCH; it3 OBJECT_MATCH 8/8, 1905 B. Offsets (Python from SDK headers): vnode v_op 0x1c, v_data 0x30; inode ic_gen 0xd0; rnode r_fh 0x40, svcfh fh_len 0x48 -> ufid ino 0x4c, gen 0x50. The new headers add the commons inode_list and iuniqtime (original __common 0x1e978c, 0x1e9790). 0x11c0f5-0x11c0f7 are 00 inter-object padding.

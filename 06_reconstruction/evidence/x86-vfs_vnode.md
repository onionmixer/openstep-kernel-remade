# x86 `src/bsd/kern/vfs_vnode.c` (plan 159 (S5-P133), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 159 (S5-P133). Final run `s5p133-it3`; 07 file SHA-256 `52353f5948a15e22ca54d828e9a6647217b66603b13a9e918df07877e32f21aa`; diff `x86-vfs_vnode.diff`.

- Object [0x11de7c, 0x11eaa2) 3110 B, 10 functions (_vn_rdwr, _vn_rele, _vn_open, _vn_create, _vn_close, _vn_link, _vn_rename, _vn_remove, _isrofile, _vattr_null). Front `89 ec 5d c3`, back `00 00 55 89`, next symbol 0x11eaa4.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p133-it3-l1-vfs_vnode-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE. Iterations: it1 vn_rdwr fixed, vn_open 612/616 (plan 159's 'padding only' reading was wrong); it2 vn_open fixed, vn_create one branch displacement; it3 OBJECT_MATCH 10/10, 3110 B. 0x11eaa2-0x11eaa3 are 00 inter-object padding.

# x86 `src/bsd/kern/vfs_syscalls.c` (plan 179 (S5-P152), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 179 (S5-P152). Final run `s5p152-it4`; 07 file SHA-256 `f3d943fb828e54a3dfd93822867f565e7ffafa2b1381f49b7cfeee944f3a2e3d`; diff `x86-vfs_syscalls.diff`.

- Object [0x11cba8, 0x11de7c) 4820 B, 36 functions (_chdir, _chroot, _chdirec, _open, _creat, _copen, _mknod, _mkdir, _link, _rename, _symlink, _unlink, _rmdir, _getdirentries, _getfakedirentries, _lseek, _access, _stat, _lstat, _stat1, _readlink, _chmod, _fchmod, _chown, _fchown, _utimes, __utime, _truncate, _ftruncate, _namesetattr, _fdsetattr, _fsync, _umask, _vhangup, _forceclose, _getvnodefp). Front `c3 00 00 00`, back `55 89 e5 83`, next symbol 0x11de7c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p152-it4-l1-vfs_syscalls-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE. off_t is u_long in KERNEL, so the negative-offset tests use (long) casts (js/jge in the original). Iterations: it1 lseek checks folded away (unsigned); it2 _utime 240/236; staged variant u1 (field-wise chained time assignment) 0 differences; it3 open sar/shr and lseek return placement; variants o1/o2 (unsigned shift or O_NOCTTY test) both 0 differences, o2 taken; l1 (EINVAL return in each case) 0 differences; it4 OBJECT_MATCH 36/36. sysent (0x1da034, 8-byte entries): slot 174 nosys, 180 __utime with 2 args - noted for init_sysent.c. Diagnostic compile without POSIX_KERN exit 0.

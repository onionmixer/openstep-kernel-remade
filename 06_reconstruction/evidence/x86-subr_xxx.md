# x86 `src/bsd/kern/subr_xxx.c` (plan 148, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 148. Final run `s5p122-adopt-2`; 07 file SHA-256 `27a5fdbf39c5d3d0bdf28d1db4ffa049fc994ae13132d14a9080fc51ad6f13d9`; diff `x86-subr_xxx.diff`.

- Object [0x10cca4, 0x10cd53) 175 B, 9 functions (_nodev, _nulldev, _errsys, _nullsys, _nosys, _imin, _imax, _min, _max). Front `89 ec 5d c3`, back `00 55 89 e5`, next symbol 0x10cd54.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p122-adopt-2-l1-subr_xxx-F-20261002.json`). Grade **A**.

First attempt s5p122-adopt-1 failed (NeXTMach sys/ux_exception.h needs Mach 2.5 sys/port.h); after the authored 07_kernel/nextdev_private/bsd/sys/ux_exception.h, s5p122-adopt-2 OBJECT_MATCH 9/9.

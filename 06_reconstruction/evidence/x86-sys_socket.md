# x86 `src/bsd/kern/sys_socket.c` (plan 155 (S5-P129), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 155 (S5-P129). Final run `s5p129-it1`; 07 file SHA-256 `4469148566e2de51c46d6ce530d6e97504916a8aa4c266f9e0f0a9b2b675d985`; diff `x86-sys_socket.diff`.

- Object [0x10d850, 0x10daf0) 672 B, 5 functions (_soo_rw, _soo_ioctl, _soo_select, _soo_stat, _soo_close). Front `ec 5d c3 00`, back `55 89 e5 83`, next symbol 0x10daf0.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p129-it1-l1-sys_socket-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE (plan 155.1). Original soo_rw tests byte 0x16 bit 0x02 of the proc (SDK proc.h `p_posix` bit-field) and f_flag 0x2000 (SDK file.h:85 FPOSIX_PIPE, only under POSIX_KERN) and stores f_flag into uio_fmode (+0x10). First build s5p129-it1 OBJECT_MATCH 5/5, 672 B (object ends exactly at the next symbol).

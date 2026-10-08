# x86 `src/bsd/kern/uipc_socket.c` (plan 209 (S5-P182), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 209 (S5-P182). Final run `s5p182-it2`; 07 file SHA-256 `a3d47d4f66f3cb12018a2df043ee2a68752e00be41be14d8c7226c16efd374f5`; diff `x86-uipc_socket.diff`.

- Object [0x114bd4, 0x11611e) 5450 B, 17 functions (_socreate, _sobind, _solisten, _sofree, _soclose, _soabort, _soaccept, _soconnect, _soconnect2, _sodisconnect, _sosend, _soreceive, _soshutdown, _sorflush, _sosetopt, _sogetopt, _sohasoutofband). Front `89 ec 5d c3`, back `00 00 55 89`, next symbol 0x116120.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p182-it2-l1-uipc_socket-F-20261002.json`). Grade **A**.

Object extent [0x114bd4, 0x116120) (17 functions; 2 bytes padding). Diagnosis 13 failed on the NeXTMach sys/exception.h; a diagnosis build with the SDK mach/exception.h (s5p182-d2, not 07) left three functions different. The codex review of plan 209 found the exception_from_kernel call (missed by the shape comparison). it1 15/17 (load/store order of the EAGAIN test); variants s5p182-v1 v1/v2/v3 all 0 differences -> v3 (if/else, as fifo_vnodeops); it2 OBJECT_MATCH 17/17 including __data. Diagnostic compile without POSIX_KERN exit 0.

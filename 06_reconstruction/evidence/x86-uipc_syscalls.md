# x86 `src/bsd/kern/uipc_syscalls.c` (plan 180 (S5-P153), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 180 (S5-P153). Final run `s5p153-it1`; 07 file SHA-256 `064ab0bd7c38ac8ab7a95d7a0ba8a029da9f6910422ac31ed7ca79c8729891b2`; diff `x86-uipc_syscalls.diff`.

- Object [0x116db4, 0x118116) 4962 B, 22 functions (_socket, _bind, _listen, _accept, _connect, _socketpair, _sendto, _send, _sendmsg, _sendit, _recvfrom, _recv, _recvmsg, _recvit, _shutdown, _setsockopt, _getsockopt, _pipe, _getsockname, _getpeername, _sockargs, _getsock). Front `c3 00 00 00`, back `00 00 55 89`, next symbol 0x118118.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p153-it1-l1-uipc_syscalls-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE. it1 OBJECT_MATCH 22/22 (getsock 46 B + 2 padding). Diagnostic compile without POSIX_KERN exit 0.

# x86 `src/bsd/kern/uipc_socket2.c` (plan 187 (S5-P160), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 187 (S5-P160). Final run `s5p160-it3`; 07 file SHA-256 `53056c7524c1baf58fa89b5f3d0c71af2d2d7165aa2a456b20228a85ab33406c`; diff `x86-uipc_socket2.diff`.

- Object [0x116120, 0x116db1) 3217 B, 24 functions (_soisconnecting, _soisconnected, _soisdisconnecting, _soisdisconnected, _sonewconn, _soqinsque, _soqremque, _socantsendmore, _socantrcvmore, _sbselqueue, _sbwait, _sbwakeup, _sowakeup, _soreserve, _sbreserve, _sbrelease, _sbappend, _sbappendrecord, _sbappendaddr, _sbappendrights, _sbcompress, _sbflush, _sbdrop, _sbdroprecord). Front `5d c3 00 00`, back `00 00 00 55`, next symbol 0x116db4.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p160-it3-l1-uipc_socket2-F-20261002.json`). Grade **A**.

NeXTMach failed to compile in diagnosis 13 (thread_t in sbselqueue). Iterations: it1 soqinsque 56/92 (the original walks to the tail); it2 loop form; it3 `prev = head` once before the branch -> OBJECT_MATCH 24/24 (3217 B). sbrelease's selthreadclear was found by the codex review of plan 187 and verified at 0x1165e6-0x116603.

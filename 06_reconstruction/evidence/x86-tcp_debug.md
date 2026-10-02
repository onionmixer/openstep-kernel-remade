# x86 `src/bsd/netinet/tcp_debug.c` (plan 152 (S5-P126), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 152 (S5-P126). Final run `s5p126-it1`; 07 file SHA-256 `34c706d903818f9c0512f160c6a619721c485651c8e13a9f102ba03bf05eb0ef`; diff `x86-tcp_debug.diff`.

- Object [0x1284c0, 0x128579) 185 B, 1 functions (_tcp_trace). Front `ec 5d c3 00`, back `00 00 00 55`, next symbol 0x12857c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p126-it1-l1-tcp_debug-F-20261002.json`). Grade **A**.

Original `_tcp_trace` [0x1284c0, 0x128579) only records (164-byte entries, TCP_NDEBUG 100 from SDK tcp_debug.h:63, 108/40-byte copies or bzero, 16-bit td_req); no `_tanames`/`_tcpstates`/`_prurequests`/`_tcptimers`/`_tcpconsdebug` among the 3751 non-debug symbols. `_tcp_debug` 0x1ead50 / `_tcp_debx` 0x1eed60 (gap 0x4010 = 100 x 164) in `__common`; definitions come from the SDK header (staging manifest). The diag-13 OBJECT_MATCH of the unedited NeXTMach file was vacuous (0-byte text with DEBUG undefined). Implicit int return kept (bytes cannot decide; Darwin declares void). Bytes 0x128579-0x12857b are 00 inter-object padding.

# x86 `src/bsd/netinet/tcp_input.c` (plan 368 (S5-P352), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 368 (S5-P352). Final run `s5p368-r1tcp`; 07 file SHA-256 `85a1c68a0e344e8a0314dfb23350ccf7290e30af81616ef433cf69127549f581`; diff `x86-tcp_input.diff`.

- Object [0x12857c, 0x129d8a) 6158 B, 6 functions (_tcp_reass, _tcp_input, _tcp_dooptions, _tcp_pulloutofband, _tcp_xmit_timer, _tcp_mss). Front `c3 00 00 00`, back `00 00 55 89`, next symbol 0x129d8c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p368-r1tcp-l1-tcp_input-F-20261002.json`). Grade **A**.

TCP input (4.2 = 4.3BSD-Net/2 functions with a few 4.3-Reno forms). __text [0x12857c, 0x129d8a) 6158 B + 00 x 2 (_tcp_output 0x129d8c); tcp_reass 448, tcp_input 4944, tcp_dooptions 148, tcp_pulloutofband 112, tcp_xmit_timer 208, tcp_mss 298. tcp_mssdflt is defined in tcp_subr.c (plan 165). Diagnostics s5p353 (plan 353 drafts), s5p368-tn3..tn10 (tn10 OBJECT_MATCH = this file without the NeXTMach notice block). Codex review of plan 368 (gpt-6.1-sol) verified (sizes 6158 + 2, NeXTMach provenance). Final s5p368-r1tcp from 07: OBJECT_MATCH, relcheck 0.

# x86 `src/bsd/netinet/tcp_timer.c` (plan 151 (S5-P125), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 151 (S5-P125). Final run `s5p125-it1`; 07 file SHA-256 `e08b1c6f99d03582af73a108dbeedeb0b775def7b126981a5741ce78b4a53480`; diff `x86-tcp_timer.diff`.

- Object [0x12a8cc, 0x12ac0b) 831 B, 4 functions (_tcp_fasttimo, _tcp_slowtimo, _tcp_canceltimers, _tcp_timers). Front `c3 00 00 00`, back `00 55 89 e5`, next symbol 0x12ac0c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p125-it1-l1-tcp_timer-F-20261002.json`). Grade **A**.

Edits (plan 151, verified against `objdump -D -b binary -mi386 --start-address=0x2a9fc --stop-address=0x2ac0c`): `sar $0x3` + t_rttvar x tcp_backoff (SDK tcp_var.h:149 TCP_REXMTVAL); lower bound `0x64(%ebx)` = t_rttmin (SDK :108); `movw $0x0,0x16(%ebx)` = t_dupacks (SDK :56); keepalive tcp_respond pushes six arguments with 0 in the third slot. Kept as NeXTMach: losing-block `t_srtt >> 2` (`sar $0x2`), TCPT_PERSIST without the 4.4 idle drop. The final byte 0x12ac0b is 00 inter-object padding.

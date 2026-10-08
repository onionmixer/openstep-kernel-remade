# x86 `src/kern/mach_net.c` (plan 261 (S5-P247), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 261 (S5-P247). Final run `s5p247-it1`; 07 file SHA-256 `601b3df6b2416cbd8b565b0cc4d0ca50daded1690b39f7f1cd8c1fdf7e330cc9`; diff `x86-mach_net.diff`.

- Object [0x15d6b8, 0x15de68) 1968 B, 8 functions ((static mach_net_output), _netipc_msg_send, _netipc_listen, _netipc_ignore, _find_listener, _mach_net_init, _netipc_msg_release, _receive_ip_datagram). Front `c3 00 00 00`, back `55 89 e5 57`, next symbol 0x15de68.
- Final L1 `09_validation/reconstruction/s5p247-it1-l1-mach_net-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred. Grade **P**.

Object extent [0x15d6b8, 0x15de68) 1968 B (front 00 x3 after mach_loader; back joins xxx_host_info without padding): static mach_net_output and seven named functions; the object starts before _netipc_msg_send because that function calls the static at 0x15d6b8. __DATA,__data [0x1def10, 0x1def4d) 61 B (static cached_route, "mget", two zone names) -- placement inferred, verified by L1d. A diagnosis build of the NeXTMach text (s5p245-d1) failed on old-IPC headers. Scratch builds (07 untouched) s5p247-w1..w3 settled the draft: w2 differed by 4 B (MCLBYTES), w3 with CLBYTES matched. The codex review of plan 261 corrected two field names (m_cltype, msgh_seqno) and added signedness details and the ignored ip_output result (verified). it1 (s5p247-it1) from 07: __text 0 and __data 0 differences, relcheck 0, __bss reference-inferred.

# x86 `src/mach_debug/mach_debug_server.c` (plan 349 (S5-P338), 2026-10-06)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 349 (S5-P338). Final run `s5p349-it1`; 07 file SHA-256 `840bbed9f137e44cca839feb4868979476918a7feb5f398436c8771a952007f5`; diff `x86-mach_debug_server.diff`.

- Object [0x171248, 0x171cb1) 2665 B, 11 functions ((static _Xhost_zone_info), (static _Xhost_zone_free_space_info), (static _Xmach_port_space_info), _mach_debug_server, _mach_debug_server_routine, (static _Xmach_port_get_srights), (static _Xhost_ipc_hash_info), (static _Xhost_ipc_marequest_info), (static _Xmach_port_dnrequest_info), (static _Xhost_stack_usage), (static _Xprocessor_set_stack_usage)). Front `89 ec 5d c3`, back `00 00 00 55`, next symbol 0x171e30.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p349-it1-l1-mach_debug_server-F-20261002.json`). Grade **A**.

MIG server of mach_debug.defs (msg ids 3000..3021; original table 0x1e07d0, slots 5-11 and 14-15). Mach4 basis per D022; slot 6 host_zone_free_space_info and the free-space types/structures authored (structure as Darwin 0.1); slots 16-21 skips. Diagnostics s5p349-migd1..4, s5p349-md1/md2 (Darwin basis, superseded), s5p349-md4 (Mach4 basis, OBJECT_MATCH). Codex reviews of plan 349 (gpt-6.1-sol, two rounds) verified. s5p349-it1 from 07: OBJECT_MATCH, relcheck 0.

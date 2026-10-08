# x86 `src/mach/mach_port_server.c` (plan 348 (S5-P337), 2026-10-06)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 348 (S5-P337). Final run `s5p348-mp1`; 07 file SHA-256 `f96d54feda2ae817322429ba0122d0e53080e1a8341344bcae055299fab89a42`; diff `x86-mach_port_server.diff`.

- Object [0x16efc8, 0x16f950) 2440 B, 21 functions (_mach_port_server, _mach_port_server_routine, (static _Xmach_port_names), (static _Xmach_port_type), (static _Xmach_port_rename), (static _Xmach_port_allocate_name), (static _Xmach_port_allocate), (static _Xmach_port_destroy), (static _Xmach_port_deallocate), (static _Xmach_port_get_refs), (static _Xmach_port_mod_refs), (static _Xold_mach_port_get_receive_status), (static _Xmach_port_set_qlimit), (static _Xmach_port_set_mscount), (static _Xmach_port_get_set_status), (static _Xmach_port_move_member), (static _Xmach_port_request_notification), (static _Xmach_port_insert_right), (static _Xmach_port_extract_right), (static _Xmach_port_get_receive_status), (static _Xmach_port_set_seqno)). Front `89 ec 5d c3`, back `55 89 e5 56`, next symbol 0x16f950.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p348-mp1-l1-mach_port_server-F-20261002.json`). Grade **A**.

MIG server of the 4.2 SDK mach/mach_port.defs. Diagnostics s5p348-migd1/2 and builds s5p348-exc1/excb1/machhost1/machport1/mach1. Codex review of plan 348 (gpt-6.1-sol) verified (mach_port -untyped and KernelServer conditions corrected). s5p348-mp1 from 07: OBJECT_MATCH, relcheck 0.

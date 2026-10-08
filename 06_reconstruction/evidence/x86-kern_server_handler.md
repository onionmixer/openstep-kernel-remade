# x86 `src/kernserv/kern_server_handler.c` (plan 351 (S5-P340), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 351 (S5-P340). Final run `s5p351-it1`; 07 file SHA-256 `24ade2b4c1bffb3ea36a43f3b9fcd83daa9e35aed92068b06f64a74bffc2ae25`; diff `x86-kern_server_handler.diff`.

- Object [0x16d650, 0x16dca8) 1624 B, 14 functions (_kern_serv_handler, (static _Xinstance_loc), (static _Xboot_port), (static _Xwire_range), (static _Xunwire_range), (static _Xport_proc), (static _Xport_death_proc), (static _Xcall_proc), (static _Xshutdown), (static _Xlog_level), (static _Xget_log), (static _Xport_serv), (static _Xversion), (static _Xload_objc)). Front `c3 00 00 00`, back `55 89 e5 81`, next symbol 0x16dca8.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p351-it1-l1-kern_server_handler-F-20261002.json`). Grade **A**.

MIG handler of the 4.2 SDK kernserv/kern_server.defs: global kern_serv_handler at 0x16d650 followed by 13 static _X routines (instance_loc, boot_port, wire_range, unwire_range, port_proc, port_death_proc, call_proc, shutdown, log_level, get_log, port_serv, version, load_objc); __TEXT,__const 132 B at 0x1d12c0 (L1d); 3 x 00 before (after kern_notify, 0x16d64d). Generated kern_server.h equals the SDK file. Diagnostics s5p351-migd1/migd2, s5p351-h1x3 (OBJECT_MATCH). Codex review of plan 351 (gpt-6.1-sol) verified (coverage wording, verified header copy, SDK reply header). s5p351-it1 from 07: OBJECT_MATCH, relcheck 0.

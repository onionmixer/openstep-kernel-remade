# x86 `src/kernserv/kern_server_reply_user.c` (plan 351 (S5-P340), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 351 (S5-P340). Final run `s5p351-it2`; 07 file SHA-256 `802d7d2e71f252484025c64d5ee7aa3e9faa9dd9674fdc14de5e317100c746f3`; diff `x86-kern_server_reply_user.diff`.

- Object [0x16dca8, 0x16df2e) 646 B, 3 functions (_kern_serv_panic, _kern_serv_section_by_name, _kern_serv_log_data). Front `89 ec 5d c3`, back `00 00 55 89`, next symbol 0x16df30.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p351-it2-l1-kern_server_reply_user-F-20261002.json`). Grade **A**.

MIG user stubs of the 4.2 SDK kernserv/kern_server_reply.defs: kern_serv_panic 0x16dca8, kern_serv_section_by_name 0x16ddb0, kern_serv_log_data 0x16dec0; __text 646 B plus 2 x 00 to 0x16df30 (coverage 648 B); __TEXT,__const 48 B at 0x1d1344 (L1d). Diagnostics s5p351-migd1, s5p351-r1x2 (OBJECT_MATCH). Codex review of plan 351 (gpt-6.1-sol) verified. s5p351-it2 from 07: OBJECT_MATCH, relcheck 0.

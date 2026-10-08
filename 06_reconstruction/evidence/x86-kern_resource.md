# x86 `src/bsd/kern/kern_resource.c` (plan 201 (S5-P174), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 201 (S5-P174). Final run `s5p174-it1`; 07 file SHA-256 `6385ce88e4cb60159b0d5857b392b283062f3b117bc19bb117a33b6c3617af1a`; diff `x86-kern_resource.diff`.

- Object [0x1085dc, 0x108b81) 1445 B, 7 functions (_getpriority, _setpriority, _donice, _setrlimit, _getrlimit, _getrusage, _ruadd). Front `5d c3 00 00`, back `00 00 00 55`, next symbol 0x108b84.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p174-it1-l1-kern_resource-F-20261002.json`). Grade **A**.

Object extent [0x1085dc, 0x108b84) (getpriority .. ruadd; 3 bytes padding). A diagnosis build of a patched staged copy (s5p174-d1, not 07) matched every non-relocation byte. The codex review of plan 201 confirmed user_stack at proc+0x84 and the relocation targets. it1 OBJECT_MATCH 7/7.

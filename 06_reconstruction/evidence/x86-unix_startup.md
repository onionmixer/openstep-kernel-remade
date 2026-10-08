# x86 `src/machdep/i386/unix_startup.c` (plan 259 (S5-P244), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 259 (S5-P244). Final run `s5p244-it2`; 07 file SHA-256 `7077a7a87a2c02918ad3078133369dabd9026e8039e7c3237c1c0dccc8c41a57`; diff `x86-unix_startup.diff`.

- Object [0x193a98, 0x193e56) 958 B, 2 functions (_startup_early, _startup). Front `89 ec 5d c3`, back `00 00 55 89`, next symbol 0x193e58.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p244-it2-l1-unix_startup-F-20261002.json`). Grade **A**.

Object extent [0x193a98, 0x193e58) 960 B (958 B text + 00 00; front joins unix_signal; back before pagemove): startup_early, startup. __DATA,__data [0x1e289c, 0x1e294a) 174 B (four ints, three messages) -- given by symbol (_nbuf). The codex review of plan 259 found no wrong claim and added the signedness of each division and comparison (verified). it1 (s5p244-it1): startup differed only in a spill of the rounded buffer end; variant s5p244-v1 A (v = round_page(v); size = v - buffers) matched; it2 (s5p244-it2) OBJECT_MATCH, relcheck 0.

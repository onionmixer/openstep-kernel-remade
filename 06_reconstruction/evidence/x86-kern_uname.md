# x86 `src/bsd/kern/kern_uname.c` (plan 237 (S5-P222), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 237 (S5-P222). Final run `s5p222-it2`; 07 file SHA-256 `d3f3abf0a1e67ab96e7b787e84ba5258f74eadb69cbd4e4784c4140aa02ab84a`; diff `x86-kern_uname.diff`.

- Object [0x10b464, 0x10b600) 412 B, 1 functions (_uname). Front `ec 5d c3 00`, back `55 89 e5 a1`, next symbol 0x10b600.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p222-it2-l1-kern_uname-F-20261002.json`). Grade **A**.

Object extent [0x10b464, 0x10b600): _uname only; 0x00 fill before (after the confirmed kern_time), no fill before the confirmed kern_xxx (_gethostid 0x10b600), so the object end is inferred. __DATA,__data holds the strings NEXTSTEP, %d, %d and the five machine names plus Unknown AT (verified by L1). No reference source has a kernel uname (Darwin Libc gen.subproj/uname.c is a user-level function). The codex review of plan 237 confirmed the facts and corrected two statements (the last copyoutstr result is stored without a check; the Darwin user-level uname exists); both adopted. it1 failed (hostname undeclared); it2 (s5p222-it2): OBJECT_MATCH, relcheck 0.

# x86 `src/bsd/kern/kern_synch.c` (plan 205 (S5-P178), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 205 (S5-P178). Final run `s5p178-it1`; 07 file SHA-256 `5b4c91da8e3d0844d1a6e855db551856a6ae353ed04fb54ec689fcb02e377742`; diff `x86-kern_synch.diff`.

- Object [0x10a588, 0x10abae) 1574 B, 8 functions (_sleep, _sleep_with_continuation, _sleep_with_continuation_and_deadline, _rpsleep, _rpcont, _wakeup, _wakeup_one, _rqinit). Front `ec 5d c3 00`, back `00 00 55 89`, next symbol 0x10abb0.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p178-it1-l1-kern_synch-F-20261002.json`). Grade **A**.

Object extent [0x10a588, 0x10abb0) (8 functions; 2 bytes padding). Diagnosis 13 failed on duplicate machine/time_value definitions; a diagnosis build without those imports (s5p178-d1, not 07) showed the sleep changes. The three sleep entry points use the same two message addresses, consistent with one inlined helper (a reconstruction choice). The codex review of plan 205 corrected the end call (spln, a distinct function, not a header alias of splx). it1 OBJECT_MATCH 8/8 including __data.

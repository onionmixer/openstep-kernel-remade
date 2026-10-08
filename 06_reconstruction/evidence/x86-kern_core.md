# x86 `src/bsd/kern/kern_core.c` (plan 230 (S5-P214), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 230 (S5-P214). Final run `s5p214-it3`; 07 file SHA-256 `42bc60b5844c0f2b128782c5477d81d936afc8004260c0383639a63cf0b56a7a`; diff `x86-kern_core.diff`.

- Object [0x103824, 0x103e3b) 1559 B, 1 functions (_core). Front `5d c3 00 00`, back `00 55 89 e5`, next symbol 0x103e3c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p214-it3-l1-kern_core-F-20261002.json`). Grade **A**.

Object extent [0x103824, 0x103e3c) 1560 B: _core only, 0x00 fill before (after add_profil) and after; next symbol _getdtablesize 0x103e3c. objects.tsv seq 17 names it kern_sig.c (name-based candidate); the kern_sig signal functions are at 0x109128. Diagnosis s5p214-d2 (NeXTMach core in a staging copy) failed on the m68k NeXT_THREAD_STATE_* names. The codex review of plan 230 was checked: its correction of the next symbol was right (plan fixed); its doubt about the 32-byte core_name was settled by variants s5p214-cv1 (20, 24 and 28 bytes differ, 32 matches). it1 failed (map->nentries); it2 differed only in two swapped spill slots (tstate_size/hoffset); it3 (s5p214-it3): OBJECT_MATCH, relcheck 0.

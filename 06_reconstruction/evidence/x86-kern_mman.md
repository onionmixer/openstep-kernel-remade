# x86 `src/bsd/kern/kern_mman.c` (plan 200 (S5-P173), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 200 (S5-P173). Final run `s5p173-it1`; 07 file SHA-256 `6a9724ee9efec867b367d8c42b45f52cbd06427148a69f11f71366e7ce2c993f`; diff `x86-kern_mman.diff`.

- Object [0x106e30, 0x107303) 1235 B, 12 functions (_sbrk, _sstk, _getpagesize, _smmap, _mremap, _munmap, _munmapfd, _mprotect, _madvise, _mincore, _obreak, _ovadvise). Front `c3 00 00 00`, back `00 55 89 e5`, next symbol 0x107304.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p173-it1-l1-kern_mman-F-20261002.json`). Grade **A**.

Object extent [0x106e30, 0x107304) (sbrk .. ovadvise; 1 byte padding). Diagnosis builds of staged copies only (s5p173-d1, d2) found the four changes; d2 matched every non-relocation byte. The codex review of plan 200 confirmed the relocations and the 29-byte __data string. it1 OBJECT_MATCH 12/12 including __data.

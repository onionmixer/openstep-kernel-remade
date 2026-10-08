# x86 `src/machdep/i386/mem.c` (plan 246 (S5-P231), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 246 (S5-P231). Final run `s5p231-it2`; 07 file SHA-256 `cd6e6c4e5dcf5e0b65a45230123a47d541fce11ed84e5fc2858bb6a89aeee947`; diff `x86-mem.diff`.

- Object [0x194bf4, 0x194dfc) 520 B, 3 functions (_mmread, _mmwrite, _mmrw). Front `5d c3 00 00`, back `55 89 e5 57`, next symbol 0x194dfc.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p231-it2-l1-mem-F-20261002.json`). Grade **A**.

Object extent [0x194bf4, 0x194dfc) 520 B (front 0x194bf2-f3 00 00 after cnputc; the end seam to _kd_slmwd has no padding, boundary inferred): mmread 24, mmwrite 24, mmrw 472. __DATA,__data [0x1e36a0, 0x1e36a5) "mmrw" -- verified by L1. The codex review of plan 246 added two details (no default case, so an invalid minor updates uio with an unset count; PAGE_SIZE is the page_size variable and min() compares unsigned), adopted. it1 failed (sys/errno.h), it2 (s5p231-it2) OBJECT_MATCH, relcheck 0.

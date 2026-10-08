# x86 `src/bsd/ufs/ufs_bmap.c` (plan 178 (S5-P151), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 178 (S5-P151). Final run `s5p151-it1`; 07 file SHA-256 `015d532b05e9adade8058081ef4275aa80958702608fd169b3e291aa1ae84417`; diff `x86-ufs_bmap.diff`.

- Object [0x13d830, 0x13de14) 1508 B, 1 functions (_bmap). Front `89 ec 5d c3`, back `55 89 e5 53`, next symbol 0x13de14.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p151-it1-l1-ufs_bmap-F-20261002.json`). Grade **A**.

Range [0x13d830, 0x13de14): _brelse_and_swap (0x13de14, 32 B) follows with no caller in the image (no rel32 call/jmp, only its symbol-table value at 0x1f9c4c) and cannot be assigned to ufs_bmap.c or ufs_dir.c from the bytes; it is left unassigned. The original blkpref (ufs_alloc.c) also swaps indirect entries (0x13c0dc, 0x13c235) - noted for that object. Built with the final template; it1 OBJECT_MATCH 1/1 (1508 B); rablock/rasize are commons.

2026-10-07 (plan 370): `_brelse_and_swap` (0x13de14, 32 B) is now recorded with `ufs_dir.c` (x86-ufs_dir.md) as a reconstruction choice; its original translation unit remains unproven by the bytes.

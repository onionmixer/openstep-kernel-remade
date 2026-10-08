# x86 `src/bsd/ufs/ufs_inode.c` (plan 215 (S5-P191), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 215 (S5-P191). Final run `s5p191-it2`; 07 file SHA-256 `0744e814647a4f775db498dabe0322bb9b7167690068152266203de966a81906`; diff `x86-ufs_inode.diff`.

- Object [0x1405ec, 0x142008) 6684 B, 15 functions (_new_inode, _inode_cache_clear, _ihinit, _iget, _iput, _irele, _idrop, _iinactive, _iupdat, _itrunc, _indirtrunc, _iflush, _ilock, _iunlock, _iaccess). Front `ec 5d c3 00`, back `55 89 e5 57`, next symbol 0x142008.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p191-it2-l1-ufs_inode-F-20261002.json`). Grade **A**.

Object extent [0x1405ec, 0x142008): linker 0x00 fill before 0x1405ec. Diagnosis 13 failed on the one-argument btodb; diagnosis build s5p191-d1 (NeXTMach text with a temporary btodb, not 07) matched 10 functions. The codex review of plan 215 (a slow first reply and a narrower second one, both checked) found no wrong fact; it corrected fact 4 (all three itrunc divisions use ITOV(oip)) and completed fact 1 (inode_cache_clear leaves ifreet untouched). Iterations: it1 iget, iupdat, indirtrunc match; itrunc order of the MACH_NBC block fixed (original 0x141034); inode_cache_clear variants s5p191-v1, v2 (g1 chosen: one variable for the free-list successor and the list successor, `prev = inode_list = ip->inode_list`); it2 all 15 functions match, extern relocation names match (relcheck 0).

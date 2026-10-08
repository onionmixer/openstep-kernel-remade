# x86 `src/bsd/ufs/ufs_dir.c` (plan 370 (S5-P353), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 370 (S5-P353). Final run `s5p370-r1ud`; 07 file SHA-256 `8a40358922dfd4dc179ffc7b0a47c24d7a7bb86785a4ad6175c5acbf6bd1752a`; diff `x86-ufs_dir.diff`.

- Object [0x13de14, 0x13f90b) 6903 B, 17 functions (_brelse_and_swap, _dirlook, _direnter, (static dircheckforname), (static dirrename), (static dirfixdotdot), _diraddentry, (static dirprepareentry), (static dirmakeinode), (static dirmakedirect), _dirremove, _blkatoff, (static dirmangled), (static dirbad), (static dirbadname), (static dirempty), (static dircheckpath)). Front `89 ec 5d c3`, back `00 55 89 e5`, next symbol 0x13f90c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p370-r1ud-l1-ufs_dir-F-20261002.json`). Grade **A**.

ufs_dir [0x13de14, 0x13f90b) 6903 B + 00 x 1, 17 functions (6 global), __data 368 B. Register residue of plan 355 (dircheckpath, bp in %ebx) explained by GCC dumps (s5p371-uddg): implicit-int byte_swap_dir_block_in call (call_value) made the bp pseudo conflict with %eax. Diagnostics s5p355-* (plan 355), s5p371-udv1..v3 (declarations inside the disabled #if QUOTA block - my mistake), udw1..w5, udf. Codex review of plan 370 (gpt-6.1-sol) verified. brelse_and_swap (0x13de14) was left unassigned in x86-ufs_bmap.md; it is now recorded here as a reconstruction choice. Final s5p370-r1ud from 07: OBJECT_MATCH, relcheck 0.

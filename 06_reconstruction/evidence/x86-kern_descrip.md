# x86 `src/bsd/kern/kern_descrip.c` (plan 204 (S5-P177), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 204 (S5-P177). Final run `s5p177-it2`; 07 file SHA-256 `ec3bfbbf7518208c92458de3b1ee25805479bd6db16134abd4147e2520ea84f7`; diff `x86-kern_descrip.diff`.

- Object [0x103e3c, 0x104c2b) 3567 B, 23 functions (_getdtablesize, _getdopt, _setdopt, _dup, _dup2, _dupit, _fcntl, _fset, _fgetown, _fsetown, _fioctl, _close, _fstat, _ufalloc, _ufavail, _file_init, _falloc, _getf, _closef, _free_file, _rewhence, _flock, _expand_fdlist). Front `ec 5d c3 00`, back `00 55 89 e5`, next symbol 0x104c2c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p177-it2-l1-kern_descrip-F-20261002.json`). Grade **A**.

Object extent [0x103e3c, 0x104c2c) (23 functions; 1 byte padding). Diagnosis 13 failed on current_task()->u_address; a diagnosis build with only the kern/thread.h import (s5p177-d1, not 07) showed 14 functions equal and the differences above. The codex review of plan 204 corrected the getf FPINPROGRESS return (the leftover uthread pointer of a value-less return). it1 22/23 (expand_fdlist register choice); variants s5p177-v1 a/b/c -> b (test the fresh count, then re-read it into old_cnt); it2 OBJECT_MATCH 23/23 including __data. Diagnostic compile without POSIX_KERN exit 0.

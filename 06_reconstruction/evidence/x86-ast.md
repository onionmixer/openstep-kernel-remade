# x86 `src/kern/ast.c` (plan 198 (S5-P171), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 198 (S5-P171). Final run `s5p171-it2`; 07 file SHA-256 `fa45923d94e98711eab723f3e2bf70403bf317c9647837630ba306dd0c3e793c`; diff `x86-ast.diff`.

- Object [0x156694, 0x1568d8) 580 B, 2 functions (_ast_init, _ast_check). Front `ec 5d c3 00`, back `55 89 e5 83`, next symbol 0x1568d8.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p171-it2-l1-ast-F-20261002.json`). Grade **A**.

Object extent [0x156694, 0x1568d8) (ast_init 28 B, ast_check 552 B; the kernel has no ast_taken, like NeXTMach). The codex review of plan 198 identified the policy-sensitive csw_needed (NeXTMach kern/sched.h:141-200), now added under #if NeXT to 07 kern/sched.h; probes s5p171-p1..p3 (sched_prim, thread, host) stayed OBJECT_MATCH with no _csw_needed symbol. Iterations: it1 ast_check 560 vs 552 (hint read); it2 q = rq->runq + *(volatile int *)&rq->high -> OBJECT_MATCH 2/2 including __data.

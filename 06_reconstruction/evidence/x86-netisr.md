# x86 `src/bsd/net/netisr.c` (plan 154 (S5-P128), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 154 (S5-P128). Final run `s5p128-it2`; 07 file SHA-256 `36b585f394677e656784b70904ad366621f15e3d5ca0b84359ed6c47ca859674`; diff `x86-netisr.diff`.

- Object [0x121274, 0x1212fe) 138 B, 2 functions (_netisr_thread_continue, _netisr_thread). Front `c3 00 00 00`, back `00 00 55 89`, next symbol 0x121300.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p128-it2-l1-netisr-F-20261002.json`). Grade **A**.

it1 (local prototypes for stack_privilege/thread_bind): netisr_thread_continue MATCH, netisr_thread 45/46 B (master_processor loaded into %eax instead of %edx). it2 without the local prototypes (implicit int declarations): OBJECT_MATCH 2/2, 138 B. `netisr` kept non-volatile (SDK net/netisr.h:65); one load per bit test in the original. Bytes 0x1212fe-0x1212ff are 00 inter-object padding.

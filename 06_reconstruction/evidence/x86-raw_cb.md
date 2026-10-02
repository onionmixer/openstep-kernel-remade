# x86 `src/bsd/net/raw_cb.c` (plan 150, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 150. Final run `s5p124-it2`; 07 file SHA-256 `a910edf7e520b81b67aa46660f3b4a9e0dfe7ebeee1b03faa2e429d3417606e5`; diff `x86-raw_cb.diff`.

- Object [0x121300, 0x121554) 596 B, 5 functions (_raw_attach, _raw_detach, _raw_disconnect, _raw_bind, _raw_connaddr). Front `5d c3 00 00`, back `55 89 e5 c7`, next symbol 0x121554.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p124-it2-l1-raw_cb-F-20261002.json`). Grade **A**.

Built with -DMULTICAST (plan 150). Iterations: it1 4 MATCH + raw_attach 1 byte (0x810 vs 0x824), it2 OBJECT_MATCH 5/5.

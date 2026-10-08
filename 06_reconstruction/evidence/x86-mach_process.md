# x86 `src/bsd/kern/mach_process.c` (plan 197 (S5-P170), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 197 (S5-P170). Final run `s5p170-it1`; 07 file SHA-256 `a176c5d44c5feb386cecbc9e31e34eebb6020ba2a1202680ad7b0bb808b8b0ed`; diff `x86-mach_process.diff`.

- Object [0x10b7cc, 0x10b9e7) 539 B, 1 functions (_ptrace). Front `89 ec 5d c3`, back `00 55 89 e5`, next symbol 0x10b9e8.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p170-it1-l1-mach_process-F-20261002.json`). Grade **A**.

Object extent [0x10b7cc, 0x10b9e8) (_ptrace 539 B + 1 byte padding). Diagnosis builds on staged copies only (s5p170-d1..d3) found the two import paths and the three u_address uses; d3 matched every non-relocation byte. The codex review of plan 197 confirmed the request paths, offsets and error values. it1 OBJECT_MATCH 1/1.

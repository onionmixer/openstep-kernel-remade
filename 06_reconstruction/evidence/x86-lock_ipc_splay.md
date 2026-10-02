# x86 `kern/lock.c`, `ipc/ipc_splay.c` (S5-P24, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Sources: Darwin 0.1, verbatim. Plan 49, 49.1.

| object | original `__text` | functions | data | -O3 object SHA-256 | gaps | grade |
|---|---|---|---|---|---|---|
| lock.c | [0x15b504, 0x15bc2d) 1833 B | 16 | `__data` 81 B at 0x1deddc (`lock_wait_time` 0 + two panic strings), byte-equal | `52840f7d17901688c3dc676ddba0dd26260aa4506145571443624a5fca49edae` (= -O2) | 0 / 3 x 00 | A |
| ipc_splay.c | [0x150a08, 0x151932) 3882 B | 11 | none | `d669a08260eab69be25ee211cc4eb9e19e4cc31e7e8eafe1dec52a24376f1b1b` (-O2 differs, 2150 B) | 3 x 00 / 2 x 00 | A |

- Batch diagnostic `s5p24-pre-2` (Darwin verbatim) and 07_kernel build `s5p24-build-1` identical (`.i`, all objects).
- L1: all functions MATCH, relocations 29/29 (lock) and 14/14 (ipc_splay); no zero-fill or common storage.
- lock front gap 0: `_stack_statistics` (kernel_stack.c, strongly attributed) ends at 0x15b504; a zero gap alone does
  not independently prove separate objects — recorded as a limitation, grade by the current A convention.
- ipc_splay gaps agree with the confirmed neighbours ipc_space (back 3 x 00) and ipc_table (front 2 x 00).

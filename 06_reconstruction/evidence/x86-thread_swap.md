# x86 `kern/thread_swap.c` (S5-P20, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/kern/thread_swap.c` with one restoration edit (diff `x86-thread_swap.diff`, edited file SHA-256 `0cff1a8ea3512d8df0da72f6759db93c5f3896f1a0ed7a1b5acf6dc4e35ac777`).
Plan 45, 45.1, 45.2.

- Original object `__text` [0x168ed4, 0x169124) 592 B: `_swapper_init`, `_thread_swapin`, `_thread_doswapin`,
  `_swapin_thread_continue` (inlines thread_doswapin), `_swapin_thread`; `__data` `"thread_swapin"` at 0x1dfcac
  (14 B); `__common` `_swapin_queue` 0x1f6d90 (8 B), `_swapper_lock_data` 0x1f6d98 (4 B). Gaps 0 / 0.
- Unedited Darwin (`s5p20-pre-1`): 604 B, `_swapin_thread` differs by the `vm_privilege` store (12 B); other four
  functions MATCH. Mach4 lacks that line but uses `thread_block()` instead of `thread_block_with_continuation()`.
- Edited (`s5p20-build-1`): `-O3` = `-O4` (SHA-256 `d2458d8de84171d19f7cbc33bb0de77752f294b7107348278008a1362bb5d15a`), `-O2` differs (504 B). L1: OBJECT_MATCH, 5/5 MATCH,
  0 byte differences; `-fno-common` object and the common-symbol variant (`64280f6169c6f86cfa3cffe61000fce4b77e05be7b5473031512b835c9fc895e`) both OBJECT_MATCH; 46 relocation
  addresses equal, identical bytes outside relocation fields; common sizes 8/4 = original gaps 8/4.
- `counter(c_swapin_thread_block++)` is empty (`MACH_COUNTERS` undefined, counters.h:66), as in the original.
- Grade **A**. 07_kernel: 97 files read, 94 present, 3 adopted (`counters.h`, `thread_swap.c`, `thread_swap.h`).

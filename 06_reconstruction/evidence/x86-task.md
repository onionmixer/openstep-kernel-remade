# x86 `kern/task.c` (S5-P76, S5-P79, S5-P80, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 102.2, 105, 105.1, 105.2, 105.3, 106, 106.1. Run IDs `s5p76-pre-task`,
`s5p79-probe-1/2`, `s5p80-build-1`. 07_kernel file SHA-256 `97e64fcec33d0e6017fcb6628139da038267be582d17e7bbb53914a42ab3f9fa`; diff `x86-task.diff`.

- Original `__text` [0x165964, 0x166a5a) 4342 B, 21 functions. Front 0 B (confirmed `x86-syscall_sw` ends at
  0x165964), back 2 x `00` (minimal fill; original `_stack_privilege` at 0x166a5c).
- The original keeps NeXT's u-area:
  - `task_create` does `zalloc(_u_task_zone)` into `task+0x38` (`u_address`) and calls `_utask_zero`.
  - `task_deallocate` (also inlined in `task_terminate`) calls `_utask_free(task->u_address)` before freeing the
    task.
  - These lines are taken from NeXTMach `kern/task.c:204,206,301`.
- Darwin later additions removed: the `task->proc` check in `task_terminate` and `new_task->proc = 0`.
- Probes: probe 1 (u-area and proc check) gives 20/21 equal spacing; probe 2 (+ `proc = 0` removed) gives
  OBJECT_MATCH 21/21.
- Final build `s5p80-build-1`: `-O3` `c7eabd7a…`, common variant `5af05a12…` (= probe 2), `-O2` differs; both
  `.i` identical. L1 OBJECT_MATCH 21/21 (124 references) with `__text`, `__data`, `__common` placed by symbols.
- Grade **A**; 21 functions high. All 102 files named in `task.i` exist in 07_kernel.

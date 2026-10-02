# x86 `kern/sched_prim.c` (S5-P76, S5-P86, S5-P89..S5-P99, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 112, 115-125. Run IDs `s5p89-pre-sched-prim`, `s5p90..s5p96-probe*-sched-prim`,
`s5p97-ctl-1`, `s5p98-gregress-1`, `s5p98-probe-1`, `s5p99-build-1`. 07_kernel file SHA-256 `be16b5d92d88911604d8672fef4cdd60c8022f409954b1302f8002682937d98b`; diff
`x86-sched_prim.diff` (probe diffs `x86-sched_prim-probe1..4.diff`).

- Original `__text` [0x162d80, 0x16537d) 9725 B, 35 functions; `__data` 521 B. Front 2 x `00` after `_kdp_reset`
  (`ret` 0x162d7d), back 3 x `00` (`_swtch_continue` 0x165380).
- Darwin's scheduler differs from the original in several places. Mach4 text matches:
  - timer-based `recompute_priorities` with `recompute_priorities_timer`;
  - `min_quantum = hz/10`;
  - `sleep_time` removed;
  - run-queue tests;
  - `thread_select` structure;
  - `sched_thread_continue` loop;
  - `thread_invoke` order.
- Authored lines: `init_timeout_element` declaration and calls, `switch_unix_context` calls (original calls).
- Removed: `default_preemption_rate` (no original symbol; its 4 bytes are absent from `__data`).
- Options: `SIMPLE_CLOCK` 0, `HW_FOOTPRINT` 0.
- Build flags: only with `-g` (RELEASE `gdb` configuration) does GCC 2.7 keep `clear_wait` out of line in
  `recompute_priorities`, as in the original (`s5p97-ctl-1`).
  - Rebuilding all 83 confirmed/partial objects with `-g ... -fno-omit-frame-pointer` left their non-debug content
    identical (`s5p98-gregress-1`, `09_validation/reconstruction/s5p98-gregress-compare-20261002.json`).
  - Final builds now use that flag set (template `08_build/runs/tools/s5p99-build.cmd`).
- Final build `s5p99-build-1`:
  - L1 common variant OBJECT_MATCH 35/35 (487 references).
  - Plan 36.1 for `-O3`: 487 relocations correspond, bytes outside equal; 7 commons <= gaps.
- Grade **A**; 35 functions high (authored lines marked).
- Adopted verbatim with this object: `kern/power.h`, `mach/error.h` (named in `sched_prim.i`; headers only, no
  other object reads them in the regression set).

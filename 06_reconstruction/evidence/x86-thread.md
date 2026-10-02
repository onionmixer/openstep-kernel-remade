# x86 `kern/thread.c` (S5-P76, S5-P86, S5-P89..S5-P93, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 102.2, 112, 115-119 (115.1, 115.2, 116.1, 116.2, 117.1, 117.2, 118.1, 118.2, 119.1).
Run IDs `s5p76-pre-thread`, `s5p86-pre-thread-*`, `s5p89-pre-thread`, `s5p90-probe-thread`, `s5p91-probe-a/b-thread`,
`s5p92-probe-thread`, `s5p93-ctl-thread-ks0`, `s5p93-regress-1`, `s5p93-build-1`. 07_kernel file SHA-256 `f2106958fb2adf3174a648c602ba5a2382005ba135ebc5c62e954261f1ee8e45`;
diff `x86-thread.diff` (probe diffs `x86-thread-probe1.diff`, `x86-thread-probe2a/2b.diff`, `x86-thread_c-probe3.diff`).

- Original `__text` [0x166a5c, 0x168ed4) 9336 B, 42 functions. Front 0 B (after confirmed `x86-task` and its
  2-byte fill), back 0 B (`_swapper_init` 0x168ed4).
- Options:
  - `MACH_DEBUG` 1 (stack usage functions at the file end).
  - `KERNEL_STACK` 1 (control: 0 adds five stack functions that the original keeps in kernel_stack).
  - `HW_FOOTPRINT` 0 (`_thread_create` has no `last_processor` store).
  - `SIMPLE_CLOCK` 0 (`_thread_info` has no drift compensation; no `_sched_usec` in the original; config
    hypothesis changed from 1, counter-evidence recorded).
  - `KERNOBJC` 1 (RELEASE prior; value unused by this file).
- The original `struct thread` has no `sleep_time` (07 thread.h).
- Changes against Darwin, each matched against original bytes:
  - Template `tmp_address`/`tmp_object` (NeXTMach :590-591).
  - `uarea_zero`/`uarea_init` un-commented.
  - `thread_deallocate` tmp cleanup (NeXTMach :923-926).
  - `reaper_thread` without `vm_privilege`.
  - `thread_info` sleep_time from `sched_stamp` and `POLICY_INTERACTIVE` (NeXTMach :1847-1851).
  - `thread_halt` continuation block (Mach4 :1071-1089), with the `mach_msg_continue` declaration added to
    `ipc/mach_msg.h` (Mach4 :56-57).
- Probe history: probe 1 had 36/42 equal spacings; 2a/2b separated the effect of the option; one wrong edit (T6,
  `depress_priority = -1`) was reverted after a closer look at constants hidden by normalisation; probe 3 gave
  OBJECT_MATCH 42/42.
- Final build `s5p93-build-1`: common variant byte-identical to probe 3; both `.i` identical.
  - L1 common variant OBJECT_MATCH 42/42 (458 references).
  - Plan 36.1 for `-O3`: 458 relocations correspond, bytes outside equal; 8 commons <= gaps.
- Regression after the option changes: `s5p93-regress-1` 82 objects / 90 commands identical.
- Grade **A**; 42 functions high. All 110 files named in `thread.i` exist in 07_kernel.

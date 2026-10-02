# x86 `kern/kernel_stack.c` (S5-P76, S5-P86..S5-P88, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 102.2, 112-114 (112.1, 112.2, 113.1, 113.2, 114.1). Run IDs `s5p76-pre-kernel_stack`,
`s5p86-pre-kernel-stack-hw0`, `s5p87-probe-1`, `s5p88-regress-1`, `s5p88-build-1`. Source: Darwin 0.1
`kernel/kern/kernel_stack.c`, unchanged (07_kernel SHA-256 `6331ebafdd27b6d2b7d84eb73c8b71c58c9172f59d8075c9e5348c19e3d8f2d0`).

- Original `__text` [0x15ab9c, 0x15b504) 2408 B, 13 functions. Front 0 B (`x86-kalloc`'s fill `00` at 0x15ab9b),
  back 0 B (`_simple_lock_alloc` 0x15b504).
- Needs `MACH_DEBUG` 1 (missing `mach_debug.h` stopped the Darwin build; `stack_statistics` 0x15b49c is in the
  `#if MACH_DEBUG` block; config hypothesis, plan 112.1/114).
- The kernel stack is one page: `KERNSTACK_SIZE` in `mach/i386/vm_param.h` restored to `(I386_PGBYTES)`.
  Evidence: `_initKernelStacks` 0x1000 / `>> 12`, and pcb `0xff4` at 0x18d21c and 0x18d3d1.
- Final build `s5p88-build-1`: common variant `ae61855d…` (= probe `s5p87-probe-1`), `-O3` `5a453501…`, `-O2`
  differs; both `.i` identical.
  - L1 common variant: 3 MATCH, 10 MATCH_UNVERIFIED (only `__bss`), 0 byte/reference differences.
  - `__data` 113 B L1d at 0x1ded68.
  - Plan 36.1: 211 relocations correspond, bytes outside equal; commons `_stackStats` 20/32,
    `_stack_queue_lock` 12/16.
- `__bss` 16 B: `zerofill_check.py` 83 references, one delta, candidate [0x1e5b98, 0x1e5ba8), negative check
  detected -> reference-inferred (`09_validation/reconstruction/s5p88-zerofill-check-kernel_stack-20261002.json`).
  - It starts exactly where kalloc's single-reference `k_zone_name` range ends (0x1e5b98), matching the `__text`
    order kalloc -> kernel_stack.
  - kalloc is not re-judged (its start is still unsupported).
- Regression after the option and header changes: `s5p88-regress-1` 81 objects / 88 commands identical.
- Grade **P**; 3 functions high, 10 medium. All 90 files named in `kernel_stack.i` exist in 07_kernel.

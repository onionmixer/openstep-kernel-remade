# x86 `kern/syscall_sw.c` (S5-P76..S5-P78, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 102.2, 103, 103.1, 103.2, 104, 104.1. Run IDs `s5p76-pre-syscall_sw`,
`s5p77-probe-1`, `s5p78-build-1`. 07_kernel file SHA-256 `db6d512a946de51a594236dd7b4e5f1689a2a30fce1e06e547e5b2aee080d3a1`; diff `x86-syscall_sw.diff`.

- Original `__text` [0x16594c, 0x165964) 24 B: `_null_port` (`xor eax,eax`), 3 x `90`, `_kern_invalid`
  (`mov eax,4`).
  - Front: `ret` at 0x165948 ends the body of `_map_fd` (original symbol 0x165784; Ghidra body end 0x165948),
    then 3 x `00` = minimal fill to 2^2.
  - Back: 0 B; original `_task_init` at 0x165964.
- `__data` 1124 B at 0x1df72c: `_mach_trap_table` (70 entries x 16 B `{arg_count, function, stack, 0}`, with
  `boolean_t` stack, `kern/syscall_sw.h:63`) and `_mach_trap_count`.
- Darwin as is differs in 6 data bytes (traps 20, 24, 32, 36) and has 3 references to functions absent from the
  original. Restoration edits:
  - Trap 20 uses `MACH_TRAP`.
  - Traps 24, 32 and 36 use `kern_invalid`.
  - `MACH_IPC_COMPAT` is 1, so the edited branch is compiled.
- Final build `s5p78-build-1`: `-O2` = `-O3` = common variant `d99442d4…`; both `.i` identical. L1
  OBJECT_MATCH 2/2, `__data` byte-equal, 70 references verified.
- Grade **A**; 2 functions high. Adopted verbatim with this object: `kern/syscall_subr.h`, `kern/syscall_sw.h`,
  `mach/mach_traps.h` (named in `syscall_sw.i`).

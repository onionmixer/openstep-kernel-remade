# x86 `kern/time_stamp.c` — `_kern_timestamp` (S5-P23, 2026-10-01) — authored lines (D016)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Base: Darwin 0.1
`kernel/kern/time_stamp.c`; authored lines per plan 48 rules W1–W6 (diff `x86-time_stamp.diff`, final file
SHA-256 `ba0ad972c2c0f97232156fa602fab383ce0d1dc99a15eea9221117a9068c5291`). Plan 48, 48.1, 48.2, 48.3.

- Original [0x16a158, 0x16a196) 62 B: `push 1; call _clock_value` (64-bit result) -> `lea ebx,[ebp-8]; push ebx;
  push edx; push eax; call _ns_time_to_tsval` -> `copyout(&ts, tsp, 8)` -> 0/1. Front gap 0, back 2 x `00`, next
  `_init_timers` 0x16a198. References checked: Darwin (`clock_get_counter` + usec arithmetic), Mach4 (`time`),
  NeXTMach (`event_set_ts`) — none produce these bytes; `clock_value`/`ns_time_to_tsval` exist in no reference tree.
- Attempts (all kept in `09_validation/reconstruction/s5p23-attempts/`): unedited Darwin 143 B; variant 1
  (`ns_time_to_tsval(clock_value(System), &ts)`) 66 B, DIFF — arguments evaluated right to left (`&ts` first,
  `add esp,4` after the inner call); variant 2 (result first stored in local `now`, then the call) 62 B, OBJECT_MATCH.
- Build `s5p23-build-2`: `-O2` = `-O3` = `-O4` (SHA-256 `64b31cf7e858d5ee49aec2cdb343e600899d72098f69c93fbd75e521da8eceb2`). L1: MATCH, 0 byte differences, 3 references. Grade **A**.
- Declarations are authored too: the 64-bit return type of `clock_value` is required by the bytes; `void` for
  `ns_time_to_tsval` and the parameter names are not evidenced. `System` = 1 (kern/clock.h:77-80).
- 07_kernel adopted: `kern/clock.h`, `kern/time_stamp.c`, `machdep/i386/mach_param.h`, `machdep/machine/mach_param.h`.

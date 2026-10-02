# x86 `kern/ipc_sched.c` (S5-P23, 2026-10-01) — one authored line (D016)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Base: Darwin 0.1
`kernel/kern/ipc_sched.c`; one authored line (diff `x86-ipc_sched.diff`, file SHA-256 `f25a98737e07b221fbc72964cbd852fabce6a6f6e757db4f6328b7826fc3b7e7`). Plan 47, 48, 48.1–48.3.

- Original [0x159000, 0x1593e1) 993 B: `_thread_go`, `_thread_go_and_switch`, `_thread_will_wait`,
  `_thread_will_wait_with_timeout`, `_thread_handoff`; `__data` 15 B (`"thread_handoff"`) at 0x1decb5. Front 1 x `00`,
  back 3 x `00`, next `_ipc_task_init` 0x1593e4.
- Unedited Darwin (`s5p22-pre-1`): 985 B, only `_thread_handoff` differs — the original calls `_switch_unix_context`
  (0x106e0c) with `new` (ebx) at 0x159342–0x159348 before `stack_handoff`.
- Authored: `switch_unix_context(new);` before `stack_handoff(old, new);` (no declaration added).
  Build `s5p23-build-1`: `-O2` = `-O3` = `-O4` 993 B (SHA-256 `959e66854d6648d36bc6f87ceffc8256d9b5338be3ca33b6cfcec3363bb877e0`), OBJECT_MATCH, 5/5 MATCH, `__data` verified (L1d).
  Grade **A**. 07_kernel adopted: `kern/ipc_sched.c`, `kern/ipc_sched.h`.

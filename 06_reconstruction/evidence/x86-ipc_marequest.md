# x86 `ipc/ipc_marequest.c` (S5-P26, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/ipc/ipc_marequest.c` with one restoration edit (line from Mach4 :437; diff `x86-ipc_marequest.diff`). Plan 52, 52.1.

- Original `__text` [0x14a0d8, 0x14a631) 1369 B, 6 functions; `__data` [0x1de710, 0x1de72e) 30 B
  (`ipc_marequest_max` 0x400 + `"ipc msg-accepted requests"`); next data `"ipc_mqueue_receive: strange ith_state"`
  belongs to ipc_mqueue. Gaps: front 2 x `00`, back 3 x `00` (next `_ipc_mqueue_init` 0x14a634).
- Unedited Darwin: `_ipc_marequest_destroy` calls `panic("ipc_marequest_destroy")` where the original calls
  `_ipc_notify_msg_accepted(soright, name)` (0x14a5a8–0x14a5ad); `__data` 52 B (+22 B panic string).
- Build `s5p26-build-1` (07_kernel): `-O3` `__text` 1369 B, `__data` 30 B (SHA-256 `13ffe414764d0e41f2509a3ef91b36c722168d5fe58d56c18a856b6a3cf67957`); variant without
  `-fno-common` (`e25f0176512129c9c6795b7406bd965eac75db9070a9867a3d07d458f0b283ce`) OBJECT_MATCH, 6/6 MATCH; `-fno-common` object 0 byte / 0 reference differences, common refs
  unverified (order); 54 relocation addresses and shapes equal, bytes outside relocation fields equal; commons
  mask/size/table/zone 4 B each <= original gaps 4/4/4/8. `-O2` differs (1325 B). Grade **A**.
- Darwin's `zinit(..., FALSE, ...)` + `zchange` kept (original calls `_zchange` at 0x14a1a0), not Mach4's zone type.

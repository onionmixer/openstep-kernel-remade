# x86 `kern/ipc_xxx.c` (S5-P36, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/kern/ipc_xxx.c` with restoration edits (D014; deletions, one simplification, call-target name).
Diff against Darwin: `x86-ipc_xxx.diff`. Plan 62, 62.1, 62.2. Run IDs `s5p37-*`.

- Original `__text` [0x15a39c, 0x15a628) 652 B, 8 functions; `__data` 23 B at 0x1ded00 (`_ev_port_list` and
  `"object_copyout"`); common `_lookupd_port` 0x1f6358 (4 B, gap to `_k_zone` 8). Gaps: front 0 B (confirmed
  `ipc_tt` ends at 0x15a39c), back 0 B (`ret` at 0x15a627, `_ds_notify` at 0x15a628).
- Diagnostic (Darwin verbatim): `host_priv_self`/`device_master_self` +4, `_lookupd_port` +32,
  `_event_port_by_tag` +8, extra `_lookupd_port1`, `send_notification`.
- Original evidence: no `IP_DEAD` test after `_ipc_port_copy_send` (0x15a3cb -> `_ipc_object_copyout` 0x15a3db);
  privilege test is `call _suser` (0x108310) without arguments (the original `_suser` reads no arguments and
  returns 0/1); the image has no `_is_suser`, `_lookupd_port_priv`, `__lookupd_port1`; `_send_notification` is at
  0x15a63c, outside this object.
- Probe 1 (deletions + simplification): bytes equal, 4 references `_is_suser` vs `_suser`. Probe 2 (+ `suser()`):
  OBJECT_MATCH 8/8 for `-fno-common` and the common variant.
- Final 07_kernel build `s5p37-build-1`: `-O3` = `-O2` = `2c9bccd5…`, common variant `369dcdf9…` (= probe 2);
  652 B, 32 relocations; both preprocessed files identical; undefined symbols equal to probe 2. Plan 36.1 checks:
  relocation positions/widths/pcrel/types equal, bytes outside relocations equal, 4 local references become
  external `_lookupd_port`, common size 4 <= gap 8. Grade **A**.
- Behaviour note: for a dead port the restored code passes `IP_DEAD` to `ipc_object_copyout` (Darwin returns
  `PORT_NULL`); this is the original's behaviour as shown by the bytes, not a claim of equivalence.
- Follow-up obligations: `send_notification` (called by `kernserv/kern_server.c:1149`) belongs to the object at
  0x15a63c; `_lookupd_port1` is referenced by Darwin `kern/syscall_sw.c:156`, `mach/mach_traps.h:70`,
  `mach/syscall_sw.h:79` and does not exist in the original; Darwin's `suser(cred, acflag)`
  (`bsd/kern/kern_prot.c:532`) differs from the original zero-argument `_suser`.

## Plan 392 (D056, 2026-10-08) — supersedes the boundary, "outside this object" and follow-up statements above

- User decision D056: the last unassigned non-zero interval [0x15a628, 0x15a67c) 84 B (`_ds_notify` 0x15a628, `_vm_object_pager_wakeup` 0x15a634, `_send_notification` 0x15a63c, `_task_secure` 0x15a670) is placed at the end of this file (Darwin 0.1 `kern/ipc_xxx.c` has `send_notification` right after `port_release`). The bytes do not decide the original file: the `90` fill between these functions is the in-object alignment fill, which supports but does not prove one object; a separate-file draft (`s5p395-nt0`) is also OBJECT_MATCH.
- Object now [0x15a39c, 0x15a67c) 736 B (652 + 84), 12 functions; front 0 B (ipc_tt ends at 0x15a39c), back 0 B (`ret` at 0x15a67b, `_kalloc_init` 0x15a67c); `__data` 23 B at 0x1ded00 and common `_lookupd_port` unchanged.
- 07 file SHA-256 `f6830c24811124f269ac96cfbc47f3fe4d9842b82a7c955c221af6341ad21cbe`. `ds_notify` (`xor eax,eax`: returns FALSE), `vm_object_pager_wakeup` (empty body) and `task_secure` (`mov eax,1`: returns TRUE) are authored from the original bytes (D024, marked plan 392); `send_notification` is the Darwin text restored unchanged (removed in plan 62) and validated against the original bytes; `#import <ipc/ipc_notify.h>` added so the `ipc_notify_msg_accepted_compat` prototype is visible (real-machine `cc -E` shows the `extern void` declaration; bytes unchanged, diagnostics `s5p395-x1` = `s5p395-x2` section contents). Callers in 07: `kern/ipc_kobject.c:315` (vm_object_pager_wakeup), `:375` (ds_notify), `bsd/kern/kern_exec.c:175` (task_secure), `kernserv/kern_server.c:1118` (send_notification; the `:1149` above is stale).
- Final 07 build `s5p395-it1` (kernel C form `-g -O3 -fno-omit-frame-pointer`, `08_build/runs/tools/s5p395-it1.cmd`): **OBJECT_MATCH**, 12 functions MATCH, `__text` 0 byte and 0 reference differences (34 references), `__data` 0 differences (`09_validation/reconstruction/s5p395-it1-l1-ipc_xxx-F-20261002.json`); object SHA-256 `01a1b884b132251df46ac5afb14721ca364b9fbb2661a471e8438e2739e71074`; relcheck 0; real-machine `cc -M` `s5p395-dep1`: 103 headers, all from 07, object identical. Grade **A** (unchanged), boundaries as above.

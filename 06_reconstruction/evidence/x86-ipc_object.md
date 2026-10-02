# x86 `ipc/ipc_object.c` (S5-P27, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/ipc/ipc_object.c` with restoration edits (diff `x86-ipc_object.diff`) and one-argument prototypes in
`ipc_entry.h`/`ipc_port.h` (diffs `x86-ipc_entry_h.diff`, `x86-ipc_port_h.diff`). Plan 53, 53.1, 53.2.

- Original `__text` [0x14b844, 0x14c454) 3088 B, 20 functions; `__data` 172 B at 0x1de8ae; `__common`
  `_ipc_object_zones` 8 B at 0x1f6230. Gaps: front 2 x `00` (after `_ipc_notify_port_destroyed_compat` 0x14b842),
  back 0 (next `_ipc_port_timestamp` 0x14c454).
- All nine original calls of `_ipc_entry_grow_table`/`_ipc_port_dngrow` pass one argument; the callees never read a
  second one. Darwin passes `ITS_SIZE_NONE` as a second argument.
- Attempts (staging copies only): unedited 3098 B; probe 1 (prototypes, calls, mscount, destroy) 3088 B 18 MATCH;
  probe 2 A (+`return 0`) 19 MATCH, B (no mscount init) unplaceable; probe 3 C (`name = MACH_PORT_NULL`) and D (C plus
  removal of the branch assignment) OBJECT_MATCH — C chosen (smaller). C is the smallest tested matching edit,
  not proven historical spelling.
- Final 07_kernel build `s5p27-build-1`: `-O3` = probe C (SHA-256 `e4ed2cac246c6f29c9377b9dd9524fbaf03dcc5aac03cbb7b80490a40c4b1f60`); `-O2` identical result (OBJECT_MATCH);
  variant without `-fno-common` (`c9df6e6600e3ab930751edb68c0673177731cab701af697eee0a5ca96cc9ef36`) OBJECT_MATCH; 116 relocation addresses/shapes equal, bytes outside relocation
  fields equal; `_ipc_object_zones` 8 B = original gap. Grade **A**.
- Regression after the prototype edits `s5p27-regress-1`: 45/45 objects identical.
- Not yet adopted callers/callees that must follow the one-argument API: Darwin `ipc_entry.c`, `ipc_port.c`,
  `ipc_kmsg.c`, `ipc_right.c`.

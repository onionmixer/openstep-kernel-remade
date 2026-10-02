# x86 `kernserv/kern_notify.c` (S5-P25, 2026-10-01) — grade P

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/kernserv/kern_notify.c`, verbatim, built with the restored `kern/task.h` (plan 50). Plan 51, 51.1, 51.2.

- Original `__text` [0x16d20c, 0x16d64d) 1089 B, 7 functions (static `pn_panic`, `pn_register`, `pn_notify`;
  external `notify_server_loop`, `port_request_notification`, `pnotify_start`, `get_kern_port`). Front 2 x `00`,
  back 3 x `00` (next `_kern_serv_handler` 0x16d650).
- Before the task.h restoration `_notify_server_loop` differed only in task offsets (+0x4c/+0x80 vs +0x50/+0x88).
- Builds `s5p25-pre-1` and `s5p25-build-1` (07_kernel) identical; `-O3` SHA-256 `ad35eb6f1415ab55dc316d3a166c8d46a9f016e13d5d3e91ef292bdfd52d975d`; `-O2` differs.
- L1 `-O3`: 7 functions 0 byte / 0 reference differences (91 references); `__data` 485 B at 0x1dff0c byte-equal;
  `__common` `_pn_register_port_k` placed by symbol (0x1f6e30); `__bss` 20 B (four `static` variables, local symbols
  only) reference-inferred at [0x1e726c, 0x1e7280): 27 references, one Delta 0x1e6c3c, target offsets 0-16,
  aligned, inside the original `__bss`, no image symbol inside, no overlap with known zero-fill placements, negative
  check detected (`09_validation/reconstruction/s5p25-zerofill-check-kern_notify-20261001.json`).
- Grade **P** (`objects_partial.tsv`). Functions: 4 `compared/high`, 3 `compared/medium`.
- 07_kernel: 110 files read, 100 present, 5 adopted.

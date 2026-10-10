# m68k overlay headers and configuration (plan 433)

Files: `07_kernel/v183.34/m68k/` (D068). They are used only by the m68k build
(`10_tools/reconstruction/stage_m68k.py`); the x86 build never reads them.

| file | value or content | original-byte evidence | measured in |
|---|---|---|---|
| `generated/driverkit.h` | `DRIVERKIT 0` | original `_simple_lock`/`_simple_unlock`/`_simple_lock_init` are one empty-routine alias with 2 callers; `struct utask` fields 4 B earlier; 34 -> 40 OBJECT_MATCH | plan 425, `09_validation/reconstruction/m3-m68k-config-driverkit-20261009.json` |
| `generated/iplmeas.h` | `NIPLMEAS 0` | needed by the SDK `bsd/m68k/spl.h` inline spl (plan 426) | plan 426, `m3-m68k-spl-20261009.json` |
| `generated/gdb.h` | `GDB 1` | `_IFCONTROL_SETIPADDRESS` in the original `__const` (the `#if GDB` block of `if_venip.c`); NeXTMach `optional gdb` functions present | plan 427, `m3-m68k-gdb-20261009.json` |
| `generated/simple_clock.h` | `SIMPLE_CLOCK 1` | `_sched_usec` uses in `_thread_info`, `_sched_init`, `_recompute_priorities` | plan 432, `m3-m68k-ast-20261009.json` |
| `src/machdep/m68k/mach_param.h` | `HZ 64` | original `_hz` = 64, `_tick` = 15625 | plan 430, `m3-m68k-machdep-20261009.json` |
| `src/machdep/m68k/thread.h` | pcb +0x48/+0x4c (USER_REGS), +0x54 32-bit flags | `_init_task`; aston/astoff blocks | plans 430, 432 |
| `src/machdep/m68k/ast.h` | mask 0x10000000 on pcb+0x54 | `bset #4,aN@(0x54:w)` / `bclr #4,aN@(0x54:w)` blocks of the original (plan 431 signatures) | plans 431, 432 (u_char negative control did not match) |
| `src/machdep/m68k/pmap.h` | resident count at pmap+0x10 | `_task_info` | plan 430 |
| `src/machdep/m68k/machspl.h` | `spl_t` + SDK inline spl | original has no `_spl*` symbol | plan 426 |
| `src/machdep/m68k/xpr.h`, `eventc.h`, `time_stamp.h` | XPR timestamp via `event_get()` | original has no `_event_get` symbol (inline) | plan 430 |
| `src/machdep/machine/*.h` | one `#include "machdep/m68k/<name>.h"` | dispatch only | plan 430 |

Reproduction: plan 433 (`09_validation/reconstruction/m3-m68k-overlay-20261009.json`).
`eventc.h`: NeXTMach mk-108.1 `next/eventc.h` with three import lines mapped
(`06_reconstruction/evidence/m68k-eventc.diff`).

Plan 437: `src/bsd/kern/subr_prf.c` (m68k copy, 5 marked lines; diff `m68k-subr_prf.diff`) and `src/mon/global.h` (partial `struct mon_global`) for the ROM Monitor line of the original m68k `_panic` (0x400bc66: `movel _mon_global,a3`; `movew a3@(0x30c)`, `a3@(0x30a)`, `a3@(0x312)`; string 0x40a62ad "NeXT ROM Monitor %d.%d v%d\n"). Result: `09_validation/reconstruction/m3-m68k-panic-20261009.json`.

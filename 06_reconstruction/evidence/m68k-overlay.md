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
| `src/machdep/m68k/thread.h` | pcb +0x48/+0x4c (USER_REGS), +0x54 32-bit flags; from plan 622 the whole 1997 `struct pcb` (416 B, below) | `_init_task`; aston/astoff blocks; plan 620 survey | plans 430, 432, 620-622 |
| `src/machdep/m68k/ast.h` | mask 0x10000000 on pcb+0x54 | `bset #4,aN@(0x54:w)` / `bclr #4,aN@(0x54:w)` blocks of the original (plan 431 signatures) | plans 431, 432 (u_char negative control did not match) |
| `src/machdep/m68k/pmap.h` | resident count at pmap+0x10 | `_task_info` | plan 430 |
| `src/machdep/m68k/machspl.h` | `spl_t` + SDK inline spl | original has no `_spl*` symbol | plan 426 |
| `src/machdep/m68k/xpr.h`, `eventc.h`, `time_stamp.h` | XPR timestamp via `event_get()` | original has no `_event_get` symbol (inline) | plan 430 |
| `src/machdep/machine/*.h` | one `#include "machdep/m68k/<name>.h"` | dispatch only | plan 430 |

Reproduction: plan 433 (`09_validation/reconstruction/m3-m68k-overlay-20261009.json`).
`eventc.h`: NeXTMach mk-108.1 `next/eventc.h` with three import lines mapped
(`06_reconstruction/evidence/m68k-eventc.diff`).

Plan 437: `src/bsd/kern/subr_prf.c` (m68k copy, 5 marked lines; diff `m68k-subr_prf.diff`) and `src/mon/global.h` (partial `struct mon_global`) for the ROM Monitor line of the original m68k `_panic` (0x400bc66: `movel _mon_global,a3`; `movew a3@(0x30c)`, `a3@(0x30a)`, `a3@(0x312)`; string 0x40a62ad "NeXT ROM Monitor %d.%d v%d\n"). Result: `09_validation/reconstruction/m3-m68k-panic-20261009.json`.

Plan 622 (D142, 2026-10-31): `src/machdep/m68k/thread.h` now holds the whole 1997 m68k `struct pcb`
(416 B; SHA-256 `9c2b3e04273da33930b0996825e76bc0dc01b1771e0420744f1577b80f00ae3a`, 92 lines).
Layout from the original bytes (plan 620, record `09_validation/reconstruction/m68k-pcb-survey-p620-20261030.json`):
`pcb_r` (SDK `struct regs`, 0x48) at 0, `saved_regs` 0x48, `pcb_save_area` 0x4c (new field, authored name),
`thread_user_reg` 0x50, `pcb_flags` 0x54 (32-bit, plan 432), `mmu_tt1` 0x58, `pcb_fpc_i` 0x5c (216 B),
`pcb_fpc_e` 0x134 (108 B) — field names from NeXTMach mk-108.1 `next/pcb.h:23-33`, `struct fpc_internal`
from `next/fpc.h:34-42`, `struct fpc_external` from `next/fpc.h:21-27,32` without `u_char state` (28-31),
with the `fpc.h:1` notice line. The compiler-emitted STABS (`pcb:T…=s416`) give the same offsets.
Regression (plans 621-622): M5 205 objects (run `m3p622-cc1` vs `m3p618-cc1`) and the 40 accepted M4
objects (run `m4p622-r1`, merged spec of the 35 accepted records, refs = the stored objects) all keep
equal section bytes and relocations (`canon`) and equal non-STABS header/section/symbol data; only the
STABS counts change (M5 92, M4 17 objects that carry the pcb definition); stderr unchanged; the new
dependencies are `bsd/m68k/reg.h` and `bsd/m68k/mmu.h`. x86 inputs unchanged (`m4-x86-inputs-p622-20261031.json`,
`--plan 622 x86gate`). The status table is unchanged (the tool checks the stored objects).

## Plan 779 (D178, 2026-11-09)

Plan 779 (D178, 2026-11-09): the M7 link (plans 778.8-778.19) needs the original `__common` names declared where the original objects first mention them; the forms were byte-checked in scratch runs (plan 778.15 P3b, 778.19 P5) and written to 07 with the same lines (only comments changed; diff `m68k-p779.diff`). Stage `08_build/runs/tools/m4p779-base-stage` differs from the plan 777 stage in 4 new and 9 changed paths only; `--plan 779 x86gate` seven the same, `m4-x86-inputs-p779-20261109.json` `ok`. Regression (`m4-m68k-p779-r1-20261109.json`): M5 205 (run `m3p779-cc1`) and the 76 accepted M4 objects (run `m4p779-r1`) rebuilt from that stage keep equal `canon` (section bytes, relocations by name) and equal header/sections; the only symbol change is added COMMONs (`_pv_head_table`/`_pv_list_zone` in the `pmap.h` includers, the planned names in the changed sources); stderr unchanged; `m3-m68k-p779-compare-20261109.json` summary equal to plan 764. Byte equality is not a proof of the original source.

- `src/bsd/kern/subr_prf.c`: two lines at the end, `#import <mon/tftp.h>` (D133 kept: `mon/global.h` unchanged; `mon/tftp.h` and `mon/bootp.h` staged again from `M4HEADERS[779]`) and `#import <m68k/bmap.h>`, marker `plan 779 (m68k)`. `src/bsd/kern/kern_exit.c`: `#import <m68k/scr.h>` at the end (new `07_kernel/nextmach/next/scr.h` = NeXTMach `next/scr.h` without `scr1`). New overlay `src/bsd/dev/vol.c` (`OVLFROM` 779): the 07 main file plus three marked lines (`u_short dma_chip; int slot_id;`); the 07 main file stays the x86 file (x86 stage g1a SHA-256 `657799a7…`). `src/machdep/m68k/pmap.h`: `pv_head_table`, `pv_list_zone` under `#ifdef KERNEL` before the last `#endif` (NeXTMach `next/pmap.h:186` form without `pv_lock_table`). The M5 objects `subr_prf`, `cmu_syscalls`, `kern_exit`, `vol` rebuilt in `m3p779-cc1` are byte-identical to the P3b test objects.

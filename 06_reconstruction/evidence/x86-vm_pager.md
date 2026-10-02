# x86 `vm_pager.c` — six functions 0x17a240–0x17a336 (S5-P5, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Source: Darwin 0.1 `kernel/vm/vm_pager.c` with a restoration edit (D014) that brings in the NeXTMach
structure (`vm_pager_init` text from NeXTMach `mk-108.1/vm/vm_pager.c:84`, commit `f6bdb9c3`, D013):
see `x86-vm_pager.diff` and `07_kernel/MODIFICATIONS.md`. Plan: `02_plan/RECONSTRUCTION_PLAN.md` 28, 28.1, 28.2.

## Why an intermediate version
- Original `_vm_pager_get` takes three arguments and calls `vnode_pagein(m, error)` (Darwin signature),
  while `get`/`put`/`deallocate` branch to `device_pagein`/`device_pageout`/`device_dealloc` and
  `_vm_pager_init` exists (NeXTMach structure). The Darwin panic strings `"vm_pager_get device"` etc.
  and NeXTMach's `DUMMY(pager_data_provided …)` functions are absent from the original.
- `panic` is called with code following it (0x17a29d, 0x17a2d5, 0x17a322): it was not declared
  non-returning. In this file's include closure `bsd/sys/systm.h` (`volatile void panic`) is not read;
  the preprocessed source has no `panic` declaration.

## Environment
- Staging `s5p4`-style: `08_build/runs/tools/s5p5-stage-1` (72 files), diagnostic preprocessing
  `s5p5-pre-1`: 48 files read, 2 adopted (`vm/vm_pager.c`, `vm/vnode_pager.h`, both APSL + CMU),
  list in `x86-vm_pager.files.json`. Undefined conditionals (transitive): only the undetermined options
  (`MACH_LDEBUG`, `MACH_PAGEMAP`, `MACH_VM_DEBUG`, `NORMA_VM`) and `VM_OBJECT_DEBUG`, in
  `vm_object.h`/`vm_page.h`/`kern/lock.h`; this file uses none of those structures' fields.
- The `.i` from the 07_kernel snapshot differs from the staged diagnostic `.i` only by the intended
  edits (`vm_object.h` short counts, S4-B; this file's restoration edit).

## Build and comparison (`s5p5-build-1`)
- `-O3` and `-O4` give one object; `-O2` differs. Predictions (plan 28 design 3) all held for `-O3`:
  `__text` 246 B, function offsets 0/0x8/0x44/0x80/0xb8/0xc8, ten external references, three strings in
  `__data` (75 B).
- L1: `-O3`/`-O4` all six functions MATCH, OBJECT_MATCH, `__text` at 0x17a240 (15 references equal),
  `__data` inferred at 0x1e0cbc and verified by L1d (0 differences). `-O2`: `_vm_pager_get` (13 bytes,
  2 references) and `_vm_pager_put` (1 byte, 2 references) differ. **First evidence that the original
  was compiled with `-O3` or higher** (Darwin `conf/MASTER.i386:82` `CCONFIGFLAGS = "-O3"`).
- Boundary: after 0x17a336–0x17a338 `00`×2 = minimum 2^2 fill. Before 0x17a23e–0x17a240 is `90 90`:
  the length equals the minimum fill but the value is `90`, not the `00` seen between other objects;
  it follows the final `jmp` of `_vm_pageout` (0x17a23c). Not explained yet → object grade **A\***
  (bytes and references confirmed, front boundary not proven).
- Re-judged 2026-10-02 (plan 101.1): the `90 90` at 0x17a23e-0x17a240 is the compiler alignment at the end of
  the `x86-vm_pageout` object (`__text` [0x179d44, 0x17a240), byte-equal in its build), so the front boundary is
  0 bytes after a confirmed object -> grade **A**.

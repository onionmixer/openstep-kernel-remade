# x86 `ipc/ipc_thread.c` — `_ipc_thread_enqueue`, `_ipc_thread_dequeue`, `_ipc_thread_rmqueue` (S5-P6, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Source: Darwin 0.1 `kernel/ipc/ipc_thread.c`, verbatim (only candidate: NeXTMach has no `ipc/`),
`07_kernel/src/ipc/ipc_thread.c` (SHA-256 `630228d07f99e72ae59f1c50b31f62aefbb62335e13b8897ae7fdf5a70f02f1b`).
Plan: `02_plan/RECONSTRUCTION_PLAN.md` 29, 29.1, 29.2.

- Header environment: first file staged with `stage_headers.py --prefer-07` (restored `kern/thread.h`,
  `vm/vm_object.h` used). Diagnostic preprocessing `s5p6-pre-1`: 90 files read, 89 already in
  07_kernel and identical, 1 adopted (this file). The `.i` from the 07_kernel snapshot (`s5p6-build-1`)
  is byte-identical to the diagnostic one. Transitive undefined conditionals: only undetermined options
  and `VM_OBJECT_DEBUG` (this file uses `ith_next`/`ith_prev` only).
- Build `s5p6-build-1`: `-O2`, `-O3`, `-O4` give one object. Predictions held: `__text` 209 B,
  offsets 0/0x3c/0x88, no relocations, no external symbols, no `__data`.
- L1: three functions MATCH, OBJECT_MATCH at 0x151be8 (`09_validation/reconstruction/s5p6-l1-{O2,O3,O4}-20261001.json`).
  `ith_next` +0x90 and `ith_prev` +0x94 come from the restored `struct thread` (S4-B2).
- Boundary certificate: alignment 2^2, gap before 0x151be6–0x151be8 `00`×2, after 0x151cb9–0x151cbc
  `00`×3, both minimum fills → object grade **A**.

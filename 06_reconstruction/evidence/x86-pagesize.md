# x86 `pagesize.c` — `_page_set`, `_page_copy` (S5-P4, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Source: Darwin 0.1 `kernel/machdep/i386/libc/pagesize.c`, verbatim (no restoration edit),
`07_kernel/src/machdep/i386/libc/pagesize.c`.

## Environment
- Staging `08_build/runs/tools/s5p4-stage-1` by `10_tools/reconstruction/stage_headers.py`
  (self-test: reproduces the S5-P2 staging set of 28 files exactly). 128 files, 11 unresolved
  includes, all on branches inactive under the S4-A1 option values, `!KERNEL_BUILD` or ppc.
- Diagnostic preprocessing `s5p4-pre-1` (common S4-A1 command): no errors, 105 files read
  (`09_validation/reconstruction/s5p4-preprocess-20261001.json`). Read files adopted byte for byte:
  81 new (76 `src/…`, 5 `components/architecture/…`), others already present or generated;
  list with SHA-256 and notices in `x86-pagesize.files.json` (all APSL; 59 with CMU notice,
  4 with UC Berkeley notice — kept verbatim).
- Undefined identifiers used in conditionals of the read files include 9 configuration options
  (`MACH_HOST`, `MACH_IPC_COMPAT`, `MACH_IPC_DEBUG`, `MACH_PAGEMAP`, `MACH_VM_DEBUG`,
  `NEW_VM_CODE`, `OLD_VM_CODE`, `NORMA_TASK`, `NORMA_VM`). `pagesize.c` code uses only
  `vm_offset_t`/`vm_size_t` and inline asm, and the object matches; the options are S4-A2 scope.

## Build and comparison
- `s5p4-build-2` (input `07_kernel` snapshot): isolated re-preprocess `.i` identical to
  `s5p4-pre-1`; `-O4`, `-O2`, `-O4 -funroll-all-loops`, `-O3` give one object
  (SHA-256 `0885a9166f590077e05383ae2a9c512b5f9f07e1b11ec426bf0f9264e1aabf0c`).
- Predictions (plan 20 step 5) all held: `__text` 78 B, `_page_copy` at 48, no relocations,
  no undefined symbols, inline helpers not emitted, no other sections.
- L1 (`--place-from-image`, Ghidra bodies): both functions MATCH (0 byte differences, no references),
  OBJECT_MATCH at 0x1019c0 (`09_validation/reconstruction/s5p4-l1-{O4,O2,O4u,O3}-20261001.json`).
  This also confirms that NeXT `as` keeps the explicit `0x00(%reg)` displacement (`89 42 00`)
  that the source's `jne .-30` relies on (plan 20.1).
- Boundary certificate: `__text` alignment 2^2, end 0x101a0e; gap before 0x1019be–0x1019c0 `00`×2,
  after 0x101a0e–0x101a10 `00`×2, both the minimum alignment fill (Python) → object grade **A**.

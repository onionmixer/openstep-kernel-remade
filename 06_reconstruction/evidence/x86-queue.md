# x86 `kern/queue.c` (S5-P111..S5-P112, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 137, 137.1, 137.2, 138, 138.1.
Runs `s5p111-diag-7` (candidates), `s5p112-build-2` (final). 07_kernel file SHA-256 `6c379c6f643b9779ebbed544ca082fa232ef427f4c554b93aecddbea345cd4b9` (Darwin verbatim).

- Object [0x161e5c, 0x161f4b) 239 B, 7 functions: `_enqueue_head`, `_enqueue_tail`, `_dequeue_head`, `_dequeue_tail`,
  `_remqueue`, `_insque`, `_remque` (objects.tsv seq 187).
  - Front 2 x `00`: confirmed `x86-processor` ends at 0x161e5a.
  - Back 1 x `00` (alignment 2^2); `_kdp_packet` at 0x161f4c.
- Source: Darwin `kern/queue.c` is `#define _KERN_QUEUE_FUNCTION_SCOPE_` plus `#include <kern/queue.h>`; the function
  bodies are in the already adopted 07 `kern/queue.h` (Darwin verbatim).
- Candidates (D022, Mach4 first): Mach4 `kernel/kern/queue.c` defines the same functions out of line and fails with
  "redefinition of enqueue_head" against 07 `kern/queue.h`; NeXTMach `kern/queue.c` compiles to an empty `__text`
  (m68k inline form). Darwin compiles to 239 B (`s5p111-diag-7`).
- Final build `s5p112-build-2` (template `s5p107-build.cmd`, staging `--bsd-set nextos --mach-set sdk`): final
  flags and the `-fno-common` variant both OBJECT_MATCH 7/7, no data sections
  (`09_validation/reconstruction/s5p112-l1-queue-F-20261002.json`, `-N-`).
- Grade **A**; 7 functions high.

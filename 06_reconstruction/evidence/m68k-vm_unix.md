# m68k `src/vm/vm_unix.c` (plans 498-500, 2026-10-24)

Original `03_original/m68k/binaries/mach_kernel`. 07 file `07_kernel/src/vm/vm_unix.c` unchanged (SHA-256 `69ee5717ad60c57bc26fa35e8126dd289f745fc14bb4b2f47f49b0774af79594`; origin and x86 edits: `07_kernel/PROVENANCE.tsv`, `x86-vm_unix.md`).

- The x86 object `x86-vm_unix` is one contiguous object on x86 ([0x17bd28, 0x17c4e0)), but its symbols fall into two m68k runs in the plan 415 map (class split), so it was not in the M5 set (plan 429).
- Plan 495 rows `m68k-204` (file `vm/vm_unix.c`, 1942 B) and `m68k-205` (unassigned, 136 B, `_gc_init`, `_gc_control`): together [0x4061b0e, 0x406232c), 2078 B.
- Compile line: its own x86 line of `08_build/runs/tools/s6l4-g1a.cmd` with the plan 429 replacements; stage `m0p497-a1-stage`.
- Plan 499 probe `m4p499-p1`: OBJECT_MATCH; all 24 functions equal to the original in the operand-masked listing (`09_validation/reconstruction/m4-m68k-funcs-p499-20261024.json`).
- Plan 500 final run `m4p500-a1` (`09_validation/reconstruction/m4-m68k-p500-final-20261024.json`): OBJECT_MATCH, `__TEXT,__text` 2078 B placed at the range start, external text symbols equal to the original names of both rows, no undefined symbol missing from the original, no i386 header; object equal to the plan 499 object (canon, obj_sig). Object SHA-256 `daf0470dfbaf16be8ce67e5e61db58f0aee69e6fbdb8681fe4b0da05e1bfc4eb`.
- The compile prints one warning (`vm_unix.c:627`, `kfree` argument in `device_dealloc`); the x86 build s6ll prints the same two stderr lines (`s6ll-g1a` log 319). It was accepted as a registered known warning (plan 500).
- Attribution: one reconstructed object covers both rows exactly, so `m68k-205` is attributed to this object. An originally separate file emitting the same text is not excluded by the bytes.

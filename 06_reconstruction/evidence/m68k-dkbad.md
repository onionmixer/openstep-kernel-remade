# m68k `src/machdep/m68k/dkbad.c` (plans 495-497, D103, 2026-10-24)

Original `03_original/m68k/binaries/mach_kernel`. 07 file `07_kernel/src/machdep/m68k/dkbad.c`, SHA-256 `b2fe57db68e7440703a4c146716e41d43843b0bb59af14cf40f73db178c7eb35`: NeXTMach mk-108.1 `next/dkbad.c` (https://github.com/johnsonjh/NeXTMach.git f6bdb9c3268f0eadc545d41bcc0564453b17001e) byte for byte. The NeXT notice of the NeXTMach file is kept as it is.

- Object `m68k-271` of `06_reconstruction/m68k-m4-inventory.tsv` (plan 495): [0x4092778, 0x40927d4), 92 B, exact bounds; function `_isbad` (`next/dkbad.c:33`).
- Compile line: the x86 line of `machdep/i386/dkbad.c` in `08_build/runs/tools/s6l4-g1a.cmd` with the plan 429 replacements (`-arch m68k`, `-g -O2`, no `-fwritable-strings`), source `src/src/machdep/m68k/dkbad.c`.
- Plan 496 probe `m4p496-p1` (`09_validation/reconstruction/m4-m68k-probe-p496-20261024.json`): the NeXTMach text gave OBJECT_MATCH.
- Plan 497 final run `m4p497-a1` from stage `m0p497-a1-stage` (`09_validation/reconstruction/m4-m68k-p497-final-20261024.json`): OBJECT_MATCH, `__TEXT,__text` 92 B equal to the original range, external text symbols `_isbad` equal to the original names, no undefined symbol missing from the original, no warning, no i386 header in the dependency listing; object equal to the plan 496 object (canon, obj_sig). Object SHA-256 `f5009d25b24e578d9ee0c4f30ca0cc7c74024f79a62e3876ee60fb2cbc99dba1`.
- The source SHA-256 is the same from the plan 496 input through NeXTMach, 07, the stage and the run copy.
- Placement in the 07 main tree is the user's decision D103; the original bytes do not name a source path.

# m68k `src/machdep/m68k/checksum_16.c` (plans 495-497, D103, 2026-10-24)

Original `03_original/m68k/binaries/mach_kernel`. 07 file `07_kernel/src/machdep/m68k/checksum_16.c`, SHA-256 `dbc35e13e0242f890742187d645be1cb8f285bb50892f2c48b77a46ac18c4259`: NeXTMach mk-108.1 `next/checksum_16.c` (https://github.com/johnsonjh/NeXTMach.git f6bdb9c3268f0eadc545d41bcc0564453b17001e) byte for byte. The NeXTMach file has no copyright notice; none was added.

- Object `m68k-265` of `06_reconstruction/m68k-m4-inventory.tsv` (plan 495): [0x4091080, 0x40910d6), 86 B, exact bounds; function `_checksum_16` (`next/checksum_16.c:6`).
- Compile line: the x86 line of `machdep/i386/checksum_16.c` in `08_build/runs/tools/s6l4-g1a.cmd` with the plan 429 replacements (`-arch m68k`, `-g -O2`, no `-fwritable-strings`), source `src/src/machdep/m68k/checksum_16.c`.
- Plan 496 probe `m4p496-p1` (`09_validation/reconstruction/m4-m68k-probe-p496-20261024.json`): the NeXTMach text gave OBJECT_MATCH.
- Plan 497 final run `m4p497-a1` from stage `m0p497-a1-stage` (`09_validation/reconstruction/m4-m68k-p497-final-20261024.json`): OBJECT_MATCH, `__TEXT,__text` 86 B equal to the original range, external text symbols `_checksum_16` equal to the original names, no undefined symbol missing from the original, no warning, no i386 header in the dependency listing; object equal to the plan 496 object (canon, obj_sig). Object SHA-256 `809b66146de4dd58d64f57749a1100523992e1665a3f5e53df99716f4a6e4f4c`.
- The source SHA-256 is the same from the plan 496 input through NeXTMach, 07, the stage and the run copy.
- Placement in the 07 main tree is the user's decision D103; the original bytes do not name a source path.

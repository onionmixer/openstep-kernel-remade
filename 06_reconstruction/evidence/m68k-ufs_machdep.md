# m68k `src/machdep/m68k/ufs_machdep.c` (plans 495-497, D103, 2026-10-24)

Original `03_original/m68k/binaries/mach_kernel`. 07 file `07_kernel/src/machdep/m68k/ufs_machdep.c`, SHA-256 `d0558fcb6cf811cb09180a225bbf599bc0961b3638611e3c70fac7ad39637e1f`: NeXTMach mk-108.1 `next/ufs_machdep.c` (https://github.com/johnsonjh/NeXTMach.git f6bdb9c3268f0eadc545d41bcc0564453b17001e) byte for byte. The notices of the NeXTMach file are kept as they are.

- Object `m68k-321` of `06_reconstruction/m68k-m4-inventory.tsv` (plan 495): [0x409a8ba, 0x409aa2e), 372 B, exact bounds; function `_allocbuf` (`next/ufs_machdep.c:35`), `_bfree` (`next/ufs_machdep.c:102`).
- Compile line: the x86 line of `machdep/i386/ufs_machdep.c` in `08_build/runs/tools/s6l4-g1a.cmd` with the plan 429 replacements (`-arch m68k`, `-g -O2`, no `-fwritable-strings`), source `src/src/machdep/m68k/ufs_machdep.c`.
- Plan 496 probe `m4p496-p1` (`09_validation/reconstruction/m4-m68k-probe-p496-20261024.json`): the NeXTMach text gave OBJECT_MATCH.
- Plan 497 final run `m4p497-a1` from stage `m0p497-a1-stage` (`09_validation/reconstruction/m4-m68k-p497-final-20261024.json`): OBJECT_MATCH, `__TEXT,__text` 372 B equal to the original range, external text symbols `_allocbuf`, `_bfree` equal to the original names, no undefined symbol missing from the original, no warning, no i386 header in the dependency listing; object equal to the plan 496 object (canon, obj_sig). Object SHA-256 `8ba80dca2b3d47bc8936356f60644b9d570c19e5f638dd83e5ae8ad6152ea9c1`.
- The source SHA-256 is the same from the plan 496 input through NeXTMach, 07, the stage and the run copy.
- Placement in the 07 main tree is the user's decision D103; the original bytes do not name a source path.

# x86 `src/bsd/kern/vfs_lookup.c` (plan 177 (S5-P150), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 177 (S5-P150). Final run `s5p150-it3`; 07 file SHA-256 `69c5aa7b845eb83a523aabb4ea98ef07e6616d70f01fb878944fadae61791883`; diff `x86-vfs_lookup.diff`.

- Object [0x11c0f8, 0x11c97c) 2180 B, 3 functions (_lookupname, _lookuppn, (static getsymlink)). Front `c3 00 00 00`, back `55 89 e5 53`, next symbol 0x11c97c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p150-it3-l1-vfs_lookup-F-20261002.json`). Grade **A**.

Object extent: the static getsymlink follows lookuppn at 0x11c760 without a symbol and ends at 0x11c97c (objects.tsv seq 57 text_end 0x11c75d is lookuppn's end). p_posix is the NeXT bit-field at struct proc offset 0x16, bit 1 (SDK sys/proc.h; offset computed with Python). Built with -DPOSIX_KERN -D_POSIX_SOURCE. Iterations: it1 struct proc incomplete (import sys/proc.h); it2 lookuppn 1596/1572 (frame 0x124, register choice) - staged variants on the cp declaration and lookup_flags made no difference; a register-folded diff showed the mount-point loop before the symbolic-link block in the original (0x11c4ac / 0x11c510); it3 with that order OBJECT_MATCH 3/3. Diagnostic compile without POSIX_KERN exit 0.

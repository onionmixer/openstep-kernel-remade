F00CAD5C: 9de3bf98                 save    %sp, -0x68, %sp
F00CAD60: 073c04718610e3ac         set     _bdevsw, %g3
F00CAD68: 852e2001                 sll     %i0, 1, %g2
F00CAD6C: 84008018                 add     %g2, %i0, %g2
F00CAD70: 313c04bb                 sethi   %hi(off_F012EC9C), %i0
F00CAD74: f206209c                 ld      [%i0+%lo(off_F012EC9C)], %i1
F00CAD78: 8528a003                 sll     %g2, 3, %g2
F00CAD7C: f2208003                 st      %i1, [%g2+%g3]
F00CAD80: b016209c                 bset    %lo(off_F012EC9C), %i0
F00CAD84: f2062004                 ld      [%i0+4], %i1
F00CAD88: 84008003                 add     %g2, %g3, %g2
F00CAD8C: f220a004                 st      %i1, [%g2+4]
F00CAD90: c6062008                 ld      [%i0+8], %g3
F00CAD94: c620a008                 st      %g3, [%g2+8]
F00CAD98: c606200c                 ld      [%i0+0xC], %g3
F00CAD9C: c620a00c                 st      %g3, [%g2+0xC]
F00CADA0: c6062010                 ld      [%i0+0x10], %g3
F00CADA4: c620a010                 st      %g3, [%g2+0x10]
F00CADA8: c6062014                 ld      [%i0+0x14], %g3
F00CADAC: c620a014                 st      %g3, [%g2+0x14]
F00CADB0: 81c7e008                 ret
F00CADB4: 81e80000                 restore

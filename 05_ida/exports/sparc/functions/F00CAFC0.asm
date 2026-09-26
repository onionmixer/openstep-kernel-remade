F00CAFC0: 9de3bf98                 save    %sp, -0x68, %sp
F00CAFC4: 333c0472b21661f0         set     _cdevsw, %i1
F00CAFCC: 852e2001                 sll     %i0, 1, %g2
F00CAFD0: 84008018                 add     %g2, %i0, %g2
F00CAFD4: 8528a002                 sll     %g2, 2, %g2
F00CAFD8: 84208018                 sub     %g2, %i0, %g2
F00CAFDC: 313c04bb                 sethi   %hi(off_F012EC70), %i0
F00CAFE0: c6062070                 ld      [%i0+%lo(off_F012EC70)], %g3
F00CAFE4: 8528a002                 sll     %g2, 2, %g2
F00CAFE8: c6208019                 st      %g3, [%g2+%i1]
F00CAFEC: b0162070                 bset    %lo(off_F012EC70), %i0
F00CAFF0: c6062004                 ld      [%i0+4], %g3
F00CAFF4: 84008019                 add     %g2, %i1, %g2
F00CAFF8: c620a004                 st      %g3, [%g2+4]
F00CAFFC: c6062008                 ld      [%i0+8], %g3
F00CB000: c620a008                 st      %g3, [%g2+8]
F00CB004: c606200c                 ld      [%i0+0xC], %g3
F00CB008: c620a00c                 st      %g3, [%g2+0xC]
F00CB00C: c6062010                 ld      [%i0+0x10], %g3
F00CB010: c620a010                 st      %g3, [%g2+0x10]
F00CB014: c6062014                 ld      [%i0+0x14], %g3
F00CB018: c620a014                 st      %g3, [%g2+0x14]
F00CB01C: c6062018                 ld      [%i0+0x18], %g3
F00CB020: c620a018                 st      %g3, [%g2+0x18]
F00CB024: c606201c                 ld      [%i0+0x1C], %g3
F00CB028: c620a01c                 st      %g3, [%g2+0x1C]
F00CB02C: c6062020                 ld      [%i0+0x20], %g3
F00CB030: c620a020                 st      %g3, [%g2+0x20]
F00CB034: c6062024                 ld      [%i0+0x24], %g3
F00CB038: c620a024                 st      %g3, [%g2+0x24]
F00CB03C: c6062028                 ld      [%i0+0x28], %g3
F00CB040: c620a028                 st      %g3, [%g2+0x28]
F00CB044: 81c7e008                 ret
F00CB048: 81e80000                 restore

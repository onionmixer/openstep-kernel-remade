F00B908C: 9de3bf98                 save    %sp, -0x68, %sp
F00B9090: c4066004                 ld      [%i1+4], %g2
F00B9094: c4262004                 st      %g2, [%i0+4]
F00B9098: c4066008                 ld      [%i1+8], %g2
F00B909C: c4262008                 st      %g2, [%i0+8]
F00B90A0: c4062020                 ld      [%i0+0x20], %g2
F00B90A4: f4262014                 st      %i2, [%i0+0x14]
F00B90A8: f6288000                 stb     %i3, [%g2]
F00B90AC: c40e200a                 ldub    [%i0+0xA], %g2
F00B90B0: 07003800                 sethi   0xE00000, %g3
F00B90B4: f4062020                 ld      [%i0+0x20], %i2
F00B90B8: 8408a007                 and     %g2, 7, %g2
F00B90BC: f2068000                 ld      [%i2], %i1
F00B90C0: 8528a015                 sll     %g2, 21, %g2
F00B90C4: 862e4003                 andn    %i1, %g3, %g3
F00B90C8: 8610c002                 bset    %g2, %g3
F00B90CC: c6268000                 st      %g3, [%i2]
F00B90D0: c6062020                 ld      [%i0+0x20], %g3
F00B90D4: 853f2010                 sra     %i4, 16, %g2
F00B90D8: c428e002                 stb     %g2, [%g3+2]
F00B90DC: c6062020                 ld      [%i0+0x20], %g3
F00B90E0: 853f2008                 sra     %i4, 8, %g2
F00B90E4: c428e003                 stb     %g2, [%g3+3]
F00B90E8: c4062020                 ld      [%i0+0x20], %g2
F00B90EC: ba0f601f                 and     %i5, 0x1F, %i5
F00B90F0: f828a004                 stb     %i4, [%g2+4]
F00B90F4: f0062020                 ld      [%i0+0x20], %i0
F00B90F8: bb2f6010                 sll     %i5, 16, %i5
F00B90FC: c6060000                 ld      [%i0], %g3
F00B9100: 050007c0                 sethi   0x1F0000, %g2
F00B9104: 8428c002                 andn    %g3, %g2, %g2
F00B9108: 8410801d                 bset    %i5, %g2
F00B910C: c4260000                 st      %g2, [%i0]
F00B9110: 81c7e008                 ret
F00B9114: 81e80000                 restore

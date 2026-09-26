F00B91A4: 9de3bf98                 save    %sp, -0x68, %sp
F00B91A8: c4066004                 ld      [%i1+4], %g2
F00B91AC: c4262004                 st      %g2, [%i0+4]
F00B91B0: c4066008                 ld      [%i1+8], %g2
F00B91B4: c4262008                 st      %g2, [%i0+8]
F00B91B8: c4062020                 ld      [%i0+0x20], %g2
F00B91BC: f4262014                 st      %i2, [%i0+0x14]
F00B91C0: f6288000                 stb     %i3, [%g2]
F00B91C4: c40e200a                 ldub    [%i0+0xA], %g2
F00B91C8: 07003800                 sethi   0xE00000, %g3
F00B91CC: f4062020                 ld      [%i0+0x20], %i2
F00B91D0: 8408a007                 and     %g2, 7, %g2
F00B91D4: f2068000                 ld      [%i2], %i1
F00B91D8: 8528a015                 sll     %g2, 21, %g2
F00B91DC: 862e4003                 andn    %i1, %g3, %g3
F00B91E0: 8610c002                 bset    %g2, %g3
F00B91E4: c6268000                 st      %g3, [%i2]
F00B91E8: c6062020                 ld      [%i0+0x20], %g3
F00B91EC: 853f2018                 sra     %i4, 24, %g2
F00B91F0: c428e002                 stb     %g2, [%g3+2]
F00B91F4: c6062020                 ld      [%i0+0x20], %g3
F00B91F8: 853f2010                 sra     %i4, 16, %g2
F00B91FC: c428e003                 stb     %g2, [%g3+3]
F00B9200: c6062020                 ld      [%i0+0x20], %g3
F00B9204: 853f2008                 sra     %i4, 8, %g2
F00B9208: c428e004                 stb     %g2, [%g3+4]
F00B920C: c4062020                 ld      [%i0+0x20], %g2
F00B9210: f828a005                 stb     %i4, [%g2+5]
F00B9214: c6062020                 ld      [%i0+0x20], %g3
F00B9218: 853f6008                 sra     %i5, 8, %g2
F00B921C: c428e009                 stb     %g2, [%g3+9]
F00B9220: c4062020                 ld      [%i0+0x20], %g2
F00B9224: fa28a00a                 stb     %i5, [%g2+0xA]
F00B9228: 81c7e008                 ret
F00B922C: 81e80000                 restore

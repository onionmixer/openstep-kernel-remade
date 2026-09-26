F00AC9A4: 9de3bf88                 save    %sp, -0x78, %sp
F00AC9A8: a0100018                 mov     %i0, %l0
F00AC9AC: 90100019                 mov     %i1, %o0
F00AC9B0: 9207bff4                 add     %fp, var_C, %o1
F00AC9B4: d6072080                 ld      [%i4+0x80], %o3
F00AC9B8: 94100010                 mov     %l0, %o2
F00AC9BC: d627bff0                 st      %o3, [%fp+var_10]
F00AC9C0: f8242010                 st      %i4, [%l0+0x10]
F00AC9C4: 173c02b99612e3a0         set     __fp_read_vfreg, %o3
F00AC9CC: d6242014                 st      %o3, [%l0+0x14]
F00AC9D0: 173c02b99612e3bc         set     __fp_write_vfreg, %o3
F00AC9D8: d6242018                 st      %o3, [%l0+0x18]
F00AC9DC: 40000890                 call    __fp_read_word
F00AC9E0: d0242020                 st      %o0, [%l0+0x20]
F00AC9E4: b0920000                 orcc    %o0, %g0, %i0
F00AC9E8: 12800054                 bne     locret_F00ACB38
F00AC9EC: d407bff4                 ld      [%fp+var_C], %o2
F00AC9F0: 11300000                 sethi   -0x40000000, %o0
F00AC9F4: 13200000                 sethi   0x80000000, %o1
F00AC9F8: 900a8008                 and     %o2, %o0, %o0
F00AC9FC: 80a20009                 cmp     %o0, %o1
F00ACA00: 1280000b                 bne     loc_F00ACA2C
F00ACA04: 90100010                 mov     %l0, %o0
F00ACA08: 11007e00                 sethi   0x1F80000, %o0
F00ACA0C: 920a8008                 and     %o2, %o0, %o1
F00ACA10: 11006800                 sethi   0x1A00000, %o0
F00ACA14: 80a24008                 cmp     %o1, %o0
F00ACA18: 02800022                 be      loc_F00ACAA0
F00ACA1C: 11006a00                 sethi   0x1A80000, %o0
F00ACA20: 80a24008                 cmp     %o1, %o0
F00ACA24: 0280001f                 be      loc_F00ACAA0
F00ACA28: 90100010                 mov     %l0, %o0
F00ACA2C: 9207bfec                 add     %fp, var_14, %o1
F00ACA30: 9410001a                 mov     %i2, %o2
F00ACA34: 9610001b                 mov     %i3, %o3
F00ACA38: da07bff4                 ld      [%fp+var_C], %o5
F00ACA3C: 9810001c                 mov     %i4, %o4
F00ACA40: 10800038                 ba      loc_F00ACB20
F00ACA44: da27bfec                 st      %o5, [%fp+var_14]
F00ACA48: 9207bff4                 add     %fp, var_C, %o1
F00ACA4C: 94100010                 mov     %l0, %o2
F00ACA50: 40000873                 call    __fp_read_word
F00ACA54: d0242020                 st      %o0, [%l0+0x20]
F00ACA58: b0920000                 orcc    %o0, %g0, %i0
F00ACA5C: 12800037                 bne     locret_F00ACB38
F00ACA60: d407bff4                 ld      [%fp+var_C], %o2
F00ACA64: 11300000                 sethi   -0x40000000, %o0
F00ACA68: 13200000                 sethi   0x80000000, %o1
F00ACA6C: 900a8008                 and     %o2, %o0, %o0
F00ACA70: 80a20009                 cmp     %o0, %o1
F00ACA74: 12800019                 bne     loc_F00ACAD8
F00ACA78: 11307000                 sethi   -0x3E400000, %o0
F00ACA7C: 11007e00                 sethi   0x1F80000, %o0
F00ACA80: 920a8008                 and     %o2, %o0, %o1
F00ACA84: 11006800                 sethi   0x1A00000, %o0
F00ACA88: 80a24008                 cmp     %o1, %o0
F00ACA8C: 02800005                 be      loc_F00ACAA0
F00ACA90: 11006a00                 sethi   0x1A80000, %o0
F00ACA94: 80a24008                 cmp     %o1, %o0
F00ACA98: 12800010                 bne     loc_F00ACAD8
F00ACA9C: 11307000                 sethi   -0x3E400000, %o0
F00ACAA0: d427bfec                 st      %o2, [%fp+var_14]
F00ACAA4: 90100010                 mov     %l0, %o0
F00ACAA8: 9207bfec                 add     %fp, var_14, %o1
F00ACAAC: 7ffffe1b                 call    sub_F00AC318
F00ACAB0: 9407bff0                 add     %fp, var_10, %o2
F00ACAB4: d207bff0                 ld      [%fp+var_10], %o1
F00ACAB8: d2272080                 st      %o1, [%i4+0x80]
F00ACABC: d206a008                 ld      [%i2+8], %o1
F00ACAC0: b0100008                 mov     %o0, %i0
F00ACAC4: d006a008                 ld      [%i2+8], %o0
F00ACAC8: d226a004                 st      %o1, [%i2+4]
F00ACACC: 90022004                 inc     4, %o0
F00ACAD0: 10800017                 ba      loc_F00ACB2C
F00ACAD4: d026a008                 st      %o0, [%i2+8]
F00ACAD8: 13304000                 sethi   -0x3F000000, %o1
F00ACADC: 900a8008                 and     %o2, %o0, %o0
F00ACAE0: 80a20009                 cmp     %o0, %o1
F00ACAE4: 02800009                 be      loc_F00ACB08
F00ACAE8: 11300000                 sethi   -0x40000000, %o0
F00ACAEC: 808a8008                 btst    %o0, %o2
F00ACAF0: 12800012                 bne     locret_F00ACB38
F00ACAF4: 913aa015                 sra     %o2, 21, %o0
F00ACAF8: 900a2007                 and     %o0, 7, %o0
F00ACAFC: 80a22006                 cmp     %o0, 6
F00ACB00: 1280000e                 bne     locret_F00ACB38
F00ACB04: 01000000                 nop
F00ACB08: d427bfec                 st      %o2, [%fp+var_14]
F00ACB0C: 90100010                 mov     %l0, %o0
F00ACB10: 9207bfec                 add     %fp, var_14, %o1
F00ACB14: 9410001a                 mov     %i2, %o2
F00ACB18: 9610001b                 mov     %i3, %o3
F00ACB1C: 9810001c                 mov     %i4, %o4
F00ACB20: 4000012b                 call    __fp_iu_simulator
F00ACB24: 01000000                 nop
F00ACB28: b0100008                 mov     %o0, %i0
F00ACB2C: 80a62000                 cmp     %i0, 0
F00ACB30: 22bfffc6                 be,a    loc_F00ACA48
F00ACB34: d006a004                 ld      [%i2+4], %o0
F00ACB38: 81c7e008                 ret
F00ACB3C: 81e80000                 restore

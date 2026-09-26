F001A910: 9de3bf98                 save    %sp, -0x68, %sp
F001A914: 9e100018                 mov     %i0, %o7
F001A918: fa03c000                 ld      [%o7], %i5
F001A91C: b6102000                 mov     0, %i3
F001A920: c6064000                 ld      [%i1], %g3
F001A924: b4102000                 mov     0, %i2
F001A928: f806600c                 ld      [%i1+0xC], %i4
F001A92C: 05000008                 sethi   0x2000, %g2
F001A930: f0066004                 ld      [%i1+4], %i0
F001A934: 8410a3e2                 bset    0x3E2, %g2
F001A938: 8088c002                 btst    %g2, %g3
F001A93C: 12800010                 bne     loc_F001A97C
F001A940: c2066008                 ld      [%i1+8], %g1
F001A944: 808e2001                 btst    1, %i0
F001A948: 1280000e                 bne     loc_F001A980
F001A94C: 8088e002                 btst    2, %g3
F001A950: 808f20e0                 btst    0xE0, %i4
F001A954: 1280000b                 bne     loc_F001A980
F001A958: 8088e002                 btst    2, %g3
F001A95C: 050000048410a300         set     0x1300, %g2
F001A964: 84084002                 and     %g1, %g2, %g2
F001A968: 80a0a300                 cmp     %g2, 0x300
F001A96C: 12800005                 bne     loc_F001A980
F001A970: 8088e002                 btst    2, %g3
F001A974: 10800054                 ba      loc_F001AAC4
F001A978: b6102020                 mov     0x20, %i3 ! ' '
F001A97C: 8088e002                 btst    2, %g3
F001A980: 02800003                 be      loc_F001A98C
F001A984: 05000100                 sethi   0x40000, %g2
F001A988: b4168002                 bset    %g2, %i2
F001A98C: 8088e020                 btst    0x20, %g3 ! ' '
F001A990: 02800003                 be      loc_F001A99C
F001A994: 05001000                 sethi   0x400000, %g2
F001A998: b4168002                 bset    %g2, %i2
F001A99C: 8088e040                 btst    0x40, %g3 ! '@'
F001A9A0: 02800003                 be      loc_F001A9AC
F001A9A4: 05002000                 sethi   0x800000, %g2
F001A9A8: b4168002                 bset    %g2, %i2
F001A9AC: 8088e080                 btst    0x80, %g3
F001A9B0: 02800003                 be      loc_F001A9BC
F001A9B4: 05004000                 sethi   0x1000000, %g2
F001A9B8: b4168002                 bset    %g2, %i2
F001A9BC: 8088e200                 btst    0x200, %g3
F001A9C0: 02800003                 be      loc_F001A9CC
F001A9C4: 05010000                 sethi   0x4000000, %g2
F001A9C8: b4168002                 bset    %g2, %i2
F001A9CC: 05000008                 sethi   0x2000, %g2
F001A9D0: 8088c002                 btst    %g2, %g3
F001A9D4: 02800003                 be      loc_F001A9E0
F001A9D8: 05020000                 sethi   0x8000000, %g2
F001A9DC: b4168002                 bset    %g2, %i2
F001A9E0: 808e2001                 btst    1, %i0
F001A9E4: 02800003                 be      loc_F001A9F0
F001A9E8: 05040000                 sethi   0x10000000, %g2
F001A9EC: b4168002                 bset    %g2, %i2
F001A9F0: 808e2002                 btst    2, %i0
F001A9F4: 02800006                 be      loc_F001AA0C
F001A9F8: 8088e100                 btst    0x100, %g3
F001A9FC: 02800005                 be      loc_F001AA10
F001AA00: 808e2002                 btst    2, %i0
F001AA04: 1080000a                 ba      loc_F001AA2C
F001AA08: b616e010                 bset    0x10, %i3
F001AA0C: 808e2002                 btst    2, %i0
F001AA10: 02800003                 be      loc_F001AA1C
F001AA14: 05080000                 sethi   0x20000000, %g2
F001AA18: b4168002                 bset    %g2, %i2
F001AA1C: 8088e100                 btst    0x100, %g3
F001AA20: 02800003                 be      loc_F001AA2C
F001AA24: 05008000                 sethi   0x2000000, %g2
F001AA28: b4168002                 bset    %g2, %i2
F001AA2C: 808f2020                 btst    0x20, %i4 ! ' '
F001AA30: 22800002                 be,a    loc_F001AA38
F001AA34: b616e002                 bset    2, %i3
F001AA38: 808f2040                 btst    0x40, %i4 ! '@'
F001AA3C: 32800002                 bne,a   loc_F001AA44
F001AA40: b416a008                 bset    8, %i2
F001AA44: 808f2080                 btst    0x80, %i4
F001AA48: 32800002                 bne,a   loc_F001AA50
F001AA4C: b416a010                 bset    0x10, %i2
F001AA50: 05000004                 sethi   0x1000, %g2
F001AA54: 88884002                 andcc   %g1, %g2, %g4
F001AA58: 32800002                 bne,a   loc_F001AA60
F001AA5C: b4168002                 bset    %g2, %i2
F001AA60: 84086300                 and     %g1, 0x300, %g2
F001AA64: 80a0a100                 cmp     %g2, 0x100
F001AA68: 22800017                 be,a    loc_F001AAC4
F001AA6C: b416a100                 bset    0x100, %i2
F001AA70: 08800015                 bleu    loc_F001AAC4
F001AA74: 80a0a200                 cmp     %g2, 0x200
F001AA78: 02800006                 be      loc_F001AA90
F001AA7C: 80a0a300                 cmp     %g2, 0x300
F001AA80: 02800006                 be      loc_F001AA98
F001AA84: 80a12000                 cmp     %g4, 0
F001AA88: 10800010                 ba      loc_F001AAC8
F001AA8C: 05000008                 sethi   0x2000, %g2
F001AA90: 1080000d                 ba      loc_F001AAC4
F001AA94: b416a200                 bset    0x200, %i2
F001AA98: 1280000b                 bne     loc_F001AAC4
F001AA9C: b416a300                 bset    0x300, %i2
F001AAA0: 808e2001                 btst    1, %i0
F001AAA4: 02800003                 be      loc_F001AAB0
F001AAA8: 05000800                 sethi   0x200000, %g2
F001AAAC: 05008000                 sethi   0x2000000, %g2
F001AAB0: 8088e020                 btst    0x20, %g3 ! ' '
F001AAB4: 12800004                 bne     loc_F001AAC4
F001AAB8: b616c002                 bset    %g2, %i3
F001AABC: 05020000                 sethi   0x8000000, %g2
F001AAC0: b616c002                 bset    %g2, %i3
F001AAC4: 05000008                 sethi   0x2000, %g2
F001AAC8: 80884002                 btst    %g2, %g1
F001AACC: 02800004                 be      loc_F001AADC
F001AAD0: 808f2080                 btst    0x80, %i4
F001AAD4: 1080000d                 ba      loc_F001AB08
F001AAD8: b616e040                 bset    0x40, %i3 ! '@'
F001AADC: 0280000a                 be      loc_F001AB04
F001AAE0: 05000100                 sethi   0x40000, %g2
F001AAE4: 80884002                 btst    %g2, %g1
F001AAE8: 02800004                 be      loc_F001AAF8
F001AAEC: 05000080                 sethi   0x20000, %g2
F001AAF0: 10800006                 ba      loc_F001AB08
F001AAF4: b616e0c0                 bset    0xC0, %i3
F001AAF8: 80884002                 btst    %g2, %g1
F001AAFC: 12800004                 bne     loc_F001AB0C
F001AB00: 80886400                 btst    0x400, %g1
F001AB04: b616e080                 bset    0x80, %i3
F001AB08: 80886400                 btst    0x400, %g1
F001AB0C: 32800002                 bne,a   loc_F001AB14
F001AB10: b416a400                 bset    0x400, %i2
F001AB14: 80886800                 btst    0x800, %g1
F001AB18: 32800002                 bne,a   loc_F001AB20
F001AB1C: b416a800                 bset    0x800, %i2
F001AB20: 05000010                 sethi   0x4000, %g2
F001AB24: 80884002                 btst    %g2, %g1
F001AB28: 12800005                 bne     loc_F001AB3C
F001AB2C: 05000020                 sethi   0x8000, %g2
F001AB30: 05004000                 sethi   0x1000000, %g2
F001AB34: b616c002                 bset    %g2, %i3
F001AB38: 05000020                 sethi   0x8000, %g2
F001AB3C: 80884002                 btst    %g2, %g1
F001AB40: 32800002                 bne,a   loc_F001AB48
F001AB44: b4168002                 bset    %g2, %i2
F001AB48: 09000040                 sethi   0x10000, %g4
F001AB4C: 80884004                 btst    %g4, %g1
F001AB50: 32800002                 bne,a   loc_F001AB58
F001AB54: b4168004                 bset    %g4, %i2
F001AB58: 8088e001                 btst    1, %g3
F001AB5C: 02800003                 be      loc_F001AB68
F001AB60: 05000080                 sethi   0x20000, %g2
F001AB64: b4168002                 bset    %g2, %i2
F001AB68: 8088e004                 btst    4, %g3
F001AB6C: 02800003                 be      loc_F001AB78
F001AB70: 05000200                 sethi   0x80000, %g2
F001AB74: b4168002                 bset    %g2, %i2
F001AB78: 8088e008                 btst    8, %g3
F001AB7C: 02800003                 be      loc_F001AB88
F001AB80: 05000400                 sethi   0x100000, %g2
F001AB84: b4168002                 bset    %g2, %i2
F001AB88: 8088e010                 btst    0x10, %g3
F001AB8C: 02800003                 be      loc_F001AB98
F001AB90: 05000800                 sethi   0x200000, %g2
F001AB94: b4168002                 bset    %g2, %i2
F001AB98: 8088e400                 btst    0x400, %g3
F001AB9C: 32800002                 bne,a   loc_F001ABA4
F001ABA0: b616e001                 bset    1, %i3
F001ABA4: 8088e800                 btst    0x800, %g3
F001ABA8: 12800005                 bne     loc_F001ABBC
F001ABAC: 0500003f                 sethi   0xFC00, %g2
F001ABB0: 05100000                 sethi   0x40000000, %g2
F001ABB4: b616c002                 bset    %g2, %i3
F001ABB8: 0500003f                 sethi   0xFC00, %g2
F001ABBC: 8410a300                 bset    0x300, %g2
F001ABC0: 840e0002                 and     %i0, %g2, %g2
F001ABC4: 808f2002                 btst    2, %i4
F001ABC8: 02800003                 be      loc_F001ABD4
F001ABCC: b616c002                 bset    %g2, %i3
F001ABD0: b616c004                 bset    %g4, %i3
F001ABD4: 808f2004                 btst    4, %i4
F001ABD8: 32800002                 bne,a   loc_F001ABE0
F001ABDC: b416a004                 bset    4, %i2
F001ABE0: 808f2001                 btst    1, %i4
F001ABE4: 02800003                 be      loc_F001ABF0
F001ABE8: 05010000                 sethi   0x4000000, %g2
F001ABEC: b616c002                 bset    %g2, %i3
F001ABF0: 808f2100                 btst    0x100, %i4
F001ABF4: 02800003                 be      loc_F001AC00
F001ABF8: 05000100                 sethi   0x40000, %g2
F001ABFC: b616c002                 bset    %g2, %i3
F001AC00: 808f2200                 btst    0x200, %i4
F001AC04: 02800003                 be      loc_F001AC10
F001AC08: 05000080                 sethi   0x20000, %g2
F001AC0C: b616c002                 bset    %g2, %i3
F001AC10: 808f2400                 btst    0x400, %i4
F001AC14: 02800003                 be      loc_F001AC20
F001AC18: 05040000                 sethi   0x10000000, %g2
F001AC1C: b616c002                 bset    %g2, %i3
F001AC20: 808f2010                 btst    0x10, %i4
F001AC24: 32800002                 bne,a   loc_F001AC2C
F001AC28: b416a002                 bset    2, %i2
F001AC2C: 808f2800                 btst    0x800, %i4
F001AC30: 32800002                 bne,a   loc_F001AC38
F001AC34: b416a020                 bset    0x20, %i2 ! ' '
F001AC38: 05010000                 sethi   0x4000000, %g2
F001AC3C: 808f0002                 btst    %g2, %i4
F001AC40: 32800002                 bne,a   loc_F001AC48
F001AC44: b616e004                 bset    4, %i3
F001AC48: 05020000                 sethi   0x8000000, %g2
F001AC4C: 808f0002                 btst    %g2, %i4
F001AC50: 02800003                 be      loc_F001AC5C
F001AC54: 05000200                 sethi   0x80000, %g2
F001AC58: b616c002                 bset    %g2, %i3
F001AC5C: 052014008410a008         set     -0x7FAFFFF8, %g2
F001AC64: 840f0002                 and     %i4, %g2, %g2
F001AC68: c603c000                 ld      [%o7], %g3
F001AC6C: b616c002                 bset    %g2, %i3
F001AC70: f620e03c                 st      %i3, [%g3+0x3C]
F001AC74: f423e010                 st      %i2, [%o7+0x10]
F001AC78: c40e6021                 ldub    [%i1+0x21], %g2
F001AC7C: c42f6049                 stb     %g2, [%i5+0x49]
F001AC80: c40e6022                 ldub    [%i1+0x22], %g2
F001AC84: c42f604a                 stb     %g2, [%i5+0x4A]
F001AC88: c40e6012                 ldub    [%i1+0x12], %g2
F001AC8C: c42f604d                 stb     %g2, [%i5+0x4D]
F001AC90: c40e6013                 ldub    [%i1+0x13], %g2
F001AC94: c42f604e                 stb     %g2, [%i5+0x4E]
F001AC98: c40e6014                 ldub    [%i1+0x14], %g2
F001AC9C: c42f604f                 stb     %g2, [%i5+0x4F]
F001ACA0: c40e6015                 ldub    [%i1+0x15], %g2
F001ACA4: c42f6050                 stb     %g2, [%i5+0x50]
F001ACA8: c40e6017                 ldub    [%i1+0x17], %g2
F001ACAC: c42f6051                 stb     %g2, [%i5+0x51]
F001ACB0: c40e6018                 ldub    [%i1+0x18], %g2
F001ACB4: c42f6052                 stb     %g2, [%i5+0x52]
F001ACB8: c40e6010                 ldub    [%i1+0x10], %g2
F001ACBC: c42f6053                 stb     %g2, [%i5+0x53]
F001ACC0: c40e6011                 ldub    [%i1+0x11], %g2
F001ACC4: c42f6054                 stb     %g2, [%i5+0x54]
F001ACC8: c40e6016                 ldub    [%i1+0x16], %g2
F001ACCC: c42f6055                 stb     %g2, [%i5+0x55]
F001ACD0: c40e601f                 ldub    [%i1+0x1F], %g2
F001ACD4: c42f6056                 stb     %g2, [%i5+0x56]
F001ACD8: c40e601c                 ldub    [%i1+0x1C], %g2
F001ACDC: c42f6057                 stb     %g2, [%i5+0x57]
F001ACE0: c40e601e                 ldub    [%i1+0x1E], %g2
F001ACE4: c42f6058                 stb     %g2, [%i5+0x58]
F001ACE8: c40e601b                 ldub    [%i1+0x1B], %g2
F001ACEC: c42f6059                 stb     %g2, [%i5+0x59]
F001ACF0: c40e601d                 ldub    [%i1+0x1D], %g2
F001ACF4: c42f605a                 stb     %g2, [%i5+0x5A]
F001ACF8: c40e6019                 ldub    [%i1+0x19], %g2
F001ACFC: c42be015                 stb     %g2, [%o7+0x15]
F001AD00: c40e601a                 ldub    [%i1+0x1A], %g2
F001AD04: c42be016                 stb     %g2, [%o7+0x16]
F001AD08: c40e6020                 ldub    [%i1+0x20], %g2
F001AD0C: c42be014                 stb     %g2, [%o7+0x14]
F001AD10: 81c7e008                 ret
F001AD14: 81e80000                 restore

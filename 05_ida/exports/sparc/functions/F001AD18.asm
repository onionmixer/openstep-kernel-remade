F001AD18: 9de3bf98                 save    %sp, -0x68, %sp
F001AD1C: 9e100018                 mov     %i0, %o7
F001AD20: 86102000                 mov     0, %g3
F001AD24: 88102000                 mov     0, %g4
F001AD28: c203c000                 ld      [%o7], %g1
F001AD2C: b4102000                 mov     0, %i2
F001AD30: fa00603c                 ld      [%g1+0x3C], %i5
F001AD34: b6102000                 mov     0, %i3
F001AD38: 808f6020                 btst    0x20, %i5 ! ' '
F001AD3C: 02800004                 be      loc_F001AD4C
F001AD40: f803e010                 ld      [%o7+0x10], %i4
F001AD44: 10800054                 ba      loc_F001AE94
F001AD48: b6102300                 mov     0x300, %i3
F001AD4C: 05000100                 sethi   0x40000, %g2
F001AD50: 808f0002                 btst    %g2, %i4
F001AD54: 32800002                 bne,a   loc_F001AD5C
F001AD58: 86102002                 mov     2, %g3
F001AD5C: 05001000                 sethi   0x400000, %g2
F001AD60: 808f0002                 btst    %g2, %i4
F001AD64: 32800002                 bne,a   loc_F001AD6C
F001AD68: 8610e020                 bset    0x20, %g3 ! ' '
F001AD6C: 05002000                 sethi   0x800000, %g2
F001AD70: 808f0002                 btst    %g2, %i4
F001AD74: 32800002                 bne,a   loc_F001AD7C
F001AD78: 8610e040                 bset    0x40, %g3 ! '@'
F001AD7C: 05004000                 sethi   0x1000000, %g2
F001AD80: 808f0002                 btst    %g2, %i4
F001AD84: 32800002                 bne,a   loc_F001AD8C
F001AD88: 8610e080                 bset    0x80, %g3
F001AD8C: 05010000                 sethi   0x4000000, %g2
F001AD90: 808f0002                 btst    %g2, %i4
F001AD94: 32800002                 bne,a   loc_F001AD9C
F001AD98: 8610e200                 bset    0x200, %g3
F001AD9C: 05020000                 sethi   0x8000000, %g2
F001ADA0: 808f0002                 btst    %g2, %i4
F001ADA4: 02800003                 be      loc_F001ADB0
F001ADA8: 05000008                 sethi   0x2000, %g2
F001ADAC: 8610c002                 bset    %g2, %g3
F001ADB0: 05040000                 sethi   0x10000000, %g2
F001ADB4: 808f0002                 btst    %g2, %i4
F001ADB8: 32800002                 bne,a   loc_F001ADC0
F001ADBC: 88102001                 mov     1, %g4
F001ADC0: 808f6010                 btst    0x10, %i5
F001ADC4: 02800004                 be      loc_F001ADD4
F001ADC8: 05008000                 sethi   0x2000000, %g2
F001ADCC: 10800009                 ba      loc_F001ADF0
F001ADD0: 8610e100                 bset    0x100, %g3
F001ADD4: 808f0002                 btst    %g2, %i4
F001ADD8: 32800002                 bne,a   loc_F001ADE0
F001ADDC: 8610e100                 bset    0x100, %g3
F001ADE0: 05080000                 sethi   0x20000000, %g2
F001ADE4: 808f0002                 btst    %g2, %i4
F001ADE8: 02800004                 be      loc_F001ADF8
F001ADEC: 808f6002                 btst    2, %i5
F001ADF0: 88112002                 bset    2, %g4
F001ADF4: 808f6002                 btst    2, %i5
F001ADF8: 22800002                 be,a    loc_F001AE00
F001ADFC: b416a020                 bset    0x20, %i2 ! ' '
F001AE00: 808f2008                 btst    8, %i4
F001AE04: 32800002                 bne,a   loc_F001AE0C
F001AE08: b416a040                 bset    0x40, %i2 ! '@'
F001AE0C: 808f2010                 btst    0x10, %i4
F001AE10: 32800002                 bne,a   loc_F001AE18
F001AE14: b416a080                 bset    0x80, %i2
F001AE18: 05028800                 sethi   0xA200000, %g2
F001AE1C: 808f4002                 btst    %g2, %i5
F001AE20: 0280000c                 be      loc_F001AE50
F001AE24: 05020000                 sethi   0x8000000, %g2
F001AE28: 808f4002                 btst    %g2, %i5
F001AE2C: 02800003                 be      loc_F001AE38
F001AE30: b616e300                 bset    0x300, %i3
F001AE34: 8608ffdf                 and     %g3, -0x21, %g3
F001AE38: 05000800                 sethi   0x200000, %g2
F001AE3C: 808f4002                 btst    %g2, %i5
F001AE40: 32800015                 bne,a   loc_F001AE94
F001AE44: 88093ffe                 and     %g4, -2, %g4
F001AE48: 10800014                 ba      loc_F001AE98
F001AE4C: 840f60c0                 and     %i5, 0xC0, %g2
F001AE50: 05000004                 sethi   0x1000, %g2
F001AE54: 808f0002                 btst    %g2, %i4
F001AE58: 32800002                 bne,a   loc_F001AE60
F001AE5C: b616c002                 bset    %g2, %i3
F001AE60: 840f2300                 and     %i4, 0x300, %g2
F001AE64: 80a0a100                 cmp     %g2, 0x100
F001AE68: 2280000b                 be,a    loc_F001AE94
F001AE6C: b616e100                 bset    0x100, %i3
F001AE70: 04800009                 ble     loc_F001AE94
F001AE74: 80a0a200                 cmp     %g2, 0x200
F001AE78: 02800006                 be      loc_F001AE90
F001AE7C: 80a0a300                 cmp     %g2, 0x300
F001AE80: 22800005                 be,a    loc_F001AE94
F001AE84: b616e300                 bset    0x300, %i3
F001AE88: 10800004                 ba      loc_F001AE98
F001AE8C: 840f60c0                 and     %i5, 0xC0, %g2
F001AE90: b616e200                 bset    0x200, %i3
F001AE94: 840f60c0                 and     %i5, 0xC0, %g2
F001AE98: 80a0a040                 cmp     %g2, 0x40 ! '@'
F001AE9C: 2280000f                 be,a    loc_F001AED8
F001AEA0: 05000008                 sethi   0x2000, %g2
F001AEA4: 14800007                 bg      loc_F001AEC0
F001AEA8: 80a0a080                 cmp     %g2, 0x80
F001AEAC: 80a0a000                 cmp     %g2, 0
F001AEB0: 0280000a                 be      loc_F001AED8
F001AEB4: 05000080                 sethi   0x20000, %g2
F001AEB8: 1080000a                 ba      loc_F001AEE0
F001AEBC: 808f2400                 btst    0x400, %i4
F001AEC0: 02800007                 be      loc_F001AEDC
F001AEC4: 80a0a0c0                 cmp     %g2, 0xC0
F001AEC8: 02800004                 be      loc_F001AED8
F001AECC: 05000100                 sethi   0x40000, %g2
F001AED0: 10800004                 ba      loc_F001AEE0
F001AED4: 808f2400                 btst    0x400, %i4
F001AED8: b616c002                 bset    %g2, %i3
F001AEDC: 808f2400                 btst    0x400, %i4
F001AEE0: 32800002                 bne,a   loc_F001AEE8
F001AEE4: b616e400                 bset    0x400, %i3
F001AEE8: 808f2800                 btst    0x800, %i4
F001AEEC: 32800002                 bne,a   loc_F001AEF4
F001AEF0: b616e800                 bset    0x800, %i3
F001AEF4: 05004000                 sethi   0x1000000, %g2
F001AEF8: 808f4002                 btst    %g2, %i5
F001AEFC: 12800005                 bne     loc_F001AF10
F001AF00: 05000020                 sethi   0x8000, %g2
F001AF04: 05000010                 sethi   0x4000, %g2
F001AF08: b616c002                 bset    %g2, %i3
F001AF0C: 05000020                 sethi   0x8000, %g2
F001AF10: 808f0002                 btst    %g2, %i4
F001AF14: 32800002                 bne,a   loc_F001AF1C
F001AF18: b616c002                 bset    %g2, %i3
F001AF1C: 31000040                 sethi   0x10000, %i0
F001AF20: 808f0018                 btst    %i0, %i4
F001AF24: 32800002                 bne,a   loc_F001AF2C
F001AF28: b616c018                 bset    %i0, %i3
F001AF2C: 05000080                 sethi   0x20000, %g2
F001AF30: 808f0002                 btst    %g2, %i4
F001AF34: 32800002                 bne,a   loc_F001AF3C
F001AF38: 8610e001                 bset    1, %g3
F001AF3C: 05000200                 sethi   0x80000, %g2
F001AF40: 808f0002                 btst    %g2, %i4
F001AF44: 32800002                 bne,a   loc_F001AF4C
F001AF48: 8610e004                 bset    4, %g3
F001AF4C: 05000400                 sethi   0x100000, %g2
F001AF50: 808f0002                 btst    %g2, %i4
F001AF54: 32800002                 bne,a   loc_F001AF5C
F001AF58: 8610e008                 bset    8, %g3
F001AF5C: 05000800                 sethi   0x200000, %g2
F001AF60: 808f0002                 btst    %g2, %i4
F001AF64: 32800002                 bne,a   loc_F001AF6C
F001AF68: 8610e010                 bset    0x10, %g3
F001AF6C: 808f6001                 btst    1, %i5
F001AF70: 32800002                 bne,a   loc_F001AF78
F001AF74: 8610e400                 bset    0x400, %g3
F001AF78: 05100000                 sethi   0x40000000, %g2
F001AF7C: 808f4002                 btst    %g2, %i5
F001AF80: 22800002                 be,a    loc_F001AF88
F001AF84: 8610e800                 bset    0x800, %g3
F001AF88: 0500003f8410a300         set     0xFF00, %g2
F001AF90: 840f4002                 and     %i5, %g2, %g2
F001AF94: 808f4018                 btst    %i0, %i5
F001AF98: 02800003                 be      loc_F001AFA4
F001AF9C: 88110002                 bset    %g2, %g4
F001AFA0: b416a002                 bset    2, %i2
F001AFA4: 808f2004                 btst    4, %i4
F001AFA8: 32800002                 bne,a   loc_F001AFB0
F001AFAC: b416a004                 bset    4, %i2
F001AFB0: 31010000                 sethi   0x4000000, %i0
F001AFB4: 808f4018                 btst    %i0, %i5
F001AFB8: 32800002                 bne,a   loc_F001AFC0
F001AFBC: b416a001                 bset    1, %i2
F001AFC0: 05000100                 sethi   0x40000, %g2
F001AFC4: 808f4002                 btst    %g2, %i5
F001AFC8: 32800002                 bne,a   loc_F001AFD0
F001AFCC: b416a100                 bset    0x100, %i2
F001AFD0: 05000080                 sethi   0x20000, %g2
F001AFD4: 808f4002                 btst    %g2, %i5
F001AFD8: 32800002                 bne,a   loc_F001AFE0
F001AFDC: b416a200                 bset    0x200, %i2
F001AFE0: 05040000                 sethi   0x10000000, %g2
F001AFE4: 808f4002                 btst    %g2, %i5
F001AFE8: 32800002                 bne,a   loc_F001AFF0
F001AFEC: b416a400                 bset    0x400, %i2
F001AFF0: 808f2002                 btst    2, %i4
F001AFF4: 32800002                 bne,a   loc_F001AFFC
F001AFF8: b416a010                 bset    0x10, %i2
F001AFFC: 808f2020                 btst    0x20, %i4 ! ' '
F001B000: 32800002                 bne,a   loc_F001B008
F001B004: b416a800                 bset    0x800, %i2
F001B008: 808f6004                 btst    4, %i5
F001B00C: 32800002                 bne,a   loc_F001B014
F001B010: b4168018                 bset    %i0, %i2
F001B014: 05000200                 sethi   0x80000, %g2
F001B018: 808f4002                 btst    %g2, %i5
F001B01C: 02800003                 be      loc_F001B028
F001B020: 05020000                 sethi   0x8000000, %g2
F001B024: b4168002                 bset    %g2, %i2
F001B028: 052014008410a008         set     -0x7FAFFFF8, %g2
F001B030: 840f4002                 and     %i5, %g2, %g2
F001B034: b4168002                 bset    %g2, %i2
F001B038: c6264000                 st      %g3, [%i1]
F001B03C: c8266004                 st      %g4, [%i1+4]
F001B040: f426600c                 st      %i2, [%i1+0xC]
F001B044: f6266008                 st      %i3, [%i1+8]
F001B048: c4086049                 ldub    [%g1+0x49], %g2
F001B04C: c42e6021                 stb     %g2, [%i1+0x21]
F001B050: c408604a                 ldub    [%g1+0x4A], %g2
F001B054: c42e6022                 stb     %g2, [%i1+0x22]
F001B058: c408604d                 ldub    [%g1+0x4D], %g2
F001B05C: c42e6012                 stb     %g2, [%i1+0x12]
F001B060: c408604e                 ldub    [%g1+0x4E], %g2
F001B064: c42e6013                 stb     %g2, [%i1+0x13]
F001B068: c408604f                 ldub    [%g1+0x4F], %g2
F001B06C: c42e6014                 stb     %g2, [%i1+0x14]
F001B070: c4086050                 ldub    [%g1+0x50], %g2
F001B074: c42e6015                 stb     %g2, [%i1+0x15]
F001B078: c4086051                 ldub    [%g1+0x51], %g2
F001B07C: c42e6017                 stb     %g2, [%i1+0x17]
F001B080: c4086052                 ldub    [%g1+0x52], %g2
F001B084: c42e6018                 stb     %g2, [%i1+0x18]
F001B088: c4086053                 ldub    [%g1+0x53], %g2
F001B08C: c42e6010                 stb     %g2, [%i1+0x10]
F001B090: c4086054                 ldub    [%g1+0x54], %g2
F001B094: c42e6011                 stb     %g2, [%i1+0x11]
F001B098: c4086055                 ldub    [%g1+0x55], %g2
F001B09C: c42e6016                 stb     %g2, [%i1+0x16]
F001B0A0: c4086056                 ldub    [%g1+0x56], %g2
F001B0A4: c42e601f                 stb     %g2, [%i1+0x1F]
F001B0A8: c4086057                 ldub    [%g1+0x57], %g2
F001B0AC: c42e601c                 stb     %g2, [%i1+0x1C]
F001B0B0: c4086058                 ldub    [%g1+0x58], %g2
F001B0B4: c42e601e                 stb     %g2, [%i1+0x1E]
F001B0B8: c4086059                 ldub    [%g1+0x59], %g2
F001B0BC: c42e601b                 stb     %g2, [%i1+0x1B]
F001B0C0: c408605a                 ldub    [%g1+0x5A], %g2
F001B0C4: c42e601d                 stb     %g2, [%i1+0x1D]
F001B0C8: c40be015                 ldub    [%o7+0x15], %g2
F001B0CC: c42e6019                 stb     %g2, [%i1+0x19]
F001B0D0: c40be016                 ldub    [%o7+0x16], %g2
F001B0D4: c42e601a                 stb     %g2, [%i1+0x1A]
F001B0D8: c40be014                 ldub    [%o7+0x14], %g2
F001B0DC: c42e6020                 stb     %g2, [%i1+0x20]
F001B0E0: 81c7e008                 ret
F001B0E4: 81e80000                 restore

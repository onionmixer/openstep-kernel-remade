F00E136C: 9de3bf98                 save    %sp, -0x68, %sp
F00E1370: c6060000                 ld      [%i0], %g3
F00E1374: 051399568410a054         set     0x4E655854, %g2
F00E137C: 80a0c002                 cmp     %g3, %g2
F00E1380: 02800006                 be      loc_F00E1398
F00E1384: 05191b15                 sethi   0x646C5400, %g2
F00E1388: 8410a232                 bset    0x232, %g2
F00E138C: 80a0c002                 cmp     %g3, %g2
F00E1390: 12800008                 bne     loc_F00E13B0
F00E1394: 05191b15                 sethi   0x646C5400, %g2
F00E1398: 050000078610a048         set     0x1C48, %g3
F00E13A0: 050000078410a046         set     0x1C46, %g2
F00E13A8: 1080000a                 ba      loc_F00E13D0
F00E13AC: b8060002                 add     %i0, %g2, %i4
F00E13B0: 8410a233                 bset    0x233, %g2
F00E13B4: 80a0c002                 cmp     %g3, %g2
F00E13B8: 02800005                 be      loc_F00E13CC
F00E13BC: 86102230                 mov     0x230, %g3
F00E13C0: 313c03f2                 sethi   %hi(aBadDiskLabelMa), %i0! "Bad disk label magic number"
F00E13C4: 1080002b                 ba      locret_F00E1470
F00E13C8: b0162188                 bset    %lo(aBadDiskLabelMa), %i0! "Bad disk label magic number"
F00E13CC: b806222e                 add     %i0, 0x22E, %i4
F00E13D0: c4062004                 ld      [%i0+4], %g2
F00E13D4: 80a08019                 cmp     %g2, %i1
F00E13D8: 22800005                 be,a    loc_F00E13EC
F00E13DC: c0262004                 clr     [%i0+4]
F00E13E0: 313c03f2                 sethi   %hi(aLabelInWrongLo), %i0! "Label in wrong location"
F00E13E4: 10800023                 ba      locret_F00E1470
F00E13E8: b01621a8                 bset    %lo(aLabelInWrongLo), %i0! "Label in wrong location"
F00E13EC: b4100018                 mov     %i0, %i2
F00E13F0: 8528e010                 sll     %g3, 16, %g2
F00E13F4: 8730a011                 srl     %g2, 17, %g3
F00E13F8: b6102000                 mov     0, %i3
F00E13FC: 8600ffff                 inc     -1, %g3
F00E1400: fa170000                 lduh    [%i4], %i5
F00E1404: 80a0ffff                 cmp     %g3, -1
F00E1408: 02800008                 be      loc_F00E1428
F00E140C: c0370000                 clrh    [%i4]
F00E1410: 8600ffff                 inc     -1, %g3
F00E1414: c4168000                 lduh    [%i2], %g2
F00E1418: 80a0ffff                 cmp     %g3, -1
F00E141C: b606c002                 add     %i3, %g2, %i3
F00E1420: 12bffffc                 bne     loc_F00E1410
F00E1424: b406a002                 inc     2, %i2
F00E1428: 8536e010                 srl     %i3, 16, %g2
F00E142C: 0700003fb410e3ff         set     0xFFFF, %i2
F00E1434: 860ec01a                 and     %i3, %i2, %g3
F00E1438: 84008003                 add     %g2, %g3, %g2
F00E143C: 80a0801a                 cmp     %g2, %i2
F00E1440: 34800002                 bg,a    loc_F00E1448
F00E1444: 8420801a                 sub     %g2, %i2, %g2
F00E1448: 8528a010                 sll     %g2, 16, %g2
F00E144C: 8530a010                 srl     %g2, 16, %g2
F00E1450: 80a0801d                 cmp     %g2, %i5
F00E1454: 32800006                 bne,a   loc_F00E146C
F00E1458: 313c03f2                 sethi   -0xFF03800, %i0
F00E145C: f2262004                 st      %i1, [%i0+4]
F00E1460: fa370000                 sth     %i5, [%i4]
F00E1464: 10800003                 ba      locret_F00E1470
F00E1468: b0102000                 mov     0, %i0
F00E146C: b01621c0                 bset    0x1C0, %i0
F00E1470: 81c7e008                 ret
F00E1474: 81e80000                 restore

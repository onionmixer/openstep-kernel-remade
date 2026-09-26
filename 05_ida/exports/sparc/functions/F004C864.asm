F004C864: 9de3bf78                 save    %sp, -0x88, %sp
F004C868: 7ffeeaf4                 call    _strlen
F004C86C: 90100019                 mov     %i1, %o0
F004C870: a2920000                 orcc    %o0, %g0, %l1
F004C874: 32800006                 bne,a   loc_F004C88C
F004C878: d04e4000                 ldsb    [%i1], %o0
F004C87C: 113c043a                 sethi   %hi(aDirremove), %o0! "dirremove"
F004C880: 7fff223c                 call    _panic
F004C884: 90122308                 bset    %lo(aDirremove), %o0! "dirremove"
F004C888: d04e4000                 ldsb    [%i1], %o0
F004C88C: 80a2202e                 cmp     %o0, 0x2E ! '.'
F004C890: 3280000f                 bne,a   loc_F004C8CC
F004C894: c027bfec                 clr     [%fp+var_14]
F004C898: 80a46001                 cmp     %l1, 1
F004C89C: 12800004                 bne     loc_F004C8AC
F004C8A0: 80a46002                 cmp     %l1, 2
F004C8A4: 108000cf                 ba      locret_F004CBE0
F004C8A8: b0102016                 mov     0x16, %i0
F004C8AC: 32800008                 bne,a   loc_F004C8CC
F004C8B0: c027bfec                 clr     [%fp+var_14]
F004C8B4: d04e6001                 ldsb    [%i1+1], %o0
F004C8B8: 80a2202e                 cmp     %o0, 0x2E ! '.'
F004C8BC: 32800004                 bne,a   loc_F004C8CC
F004C8C0: c027bfec                 clr     [%fp+var_14]
F004C8C4: 108000c7                 ba      locret_F004CBE0
F004C8C8: b0102042                 mov     0x42, %i0 ! 'B'
F004C8CC: d0162044                 lduh    [%i0+0x44], %o0
F004C8D0: 808a2001                 btst    1, %o0
F004C8D4: 0280000b                 be      loc_F004C900
F004C8D8: c027bfdc                 clr     [%fp+var_24]
F004C8DC: 90122010                 bset    0x10, %o0
F004C8E0: d0362044                 sth     %o0, [%i0+0x44]
F004C8E4: 90100018                 mov     %i0, %o0! unsigned int
F004C8E8: 7fff1764                 call    _sleep
F004C8EC: 9210200a                 mov     0xA, %o1
F004C8F0: d0162044                 lduh    [%i0+0x44], %o0
F004C8F4: 808a2001                 btst    1, %o0
F004C8F8: 12bffffa                 bne     loc_F004C8E0
F004C8FC: 90122010                 bset    0x10, %o0
F004C900: d0162044                 lduh    [%i0+0x44], %o0
F004C904: 90122001                 bset    1, %o0
F004C908: d0362044                 sth     %o0, [%i0+0x44]
F004C90C: d0162064                 lduh    [%i0+0x64], %o0
F004C910: 1300003c                 sethi   0xF000, %o1
F004C914: 900a0009                 and     %o0, %o1, %o0
F004C918: 13000010                 sethi   0x4000, %o1
F004C91C: 80a20009                 cmp     %o0, %o1
F004C920: 1280008f                 bne     loc_F004CB5C
F004C924: a0102014                 mov     0x14, %l0
F004C928: 90100018                 mov     %i0, %o0
F004C92C: 400009f7                 call    _iaccess
F004C930: 921020c0                 mov     0xC0, %o1
F004C934: a0920000                 orcc    %o0, %g0, %l0
F004C938: 1280008a                 bne     loc_F004CB60
F004C93C: d007bfdc                 ld      [%fp+var_24], %o0
F004C940: 90102002                 mov     2, %o0
F004C944: d027bfe0                 st      %o0, [%fp+var_20]
F004C948: 90100018                 mov     %i0, %o0
F004C94C: 92100019                 mov     %i1, %o1
F004C950: 94100011                 mov     %l1, %o2
F004C954: 9607bfe0                 add     %fp, var_20, %o3
F004C958: 7ffffc44                 call    sub_F004BA68
F004C95C: 9807bfdc                 add     %fp, var_24, %o4
F004C960: a0920000                 orcc    %o0, %g0, %l0
F004C964: 1280007f                 bne     loc_F004CB60
F004C968: d007bfdc                 ld      [%fp+var_24], %o0
F004C96C: 80a22000                 cmp     %o0, 0
F004C970: 02800006                 be      loc_F004C988
F004C974: 80a6a000                 cmp     %i2, 0
F004C978: 02800006                 be      loc_F004C990
F004C97C: 80a68008                 cmp     %i2, %o0
F004C980: 22800005                 be,a    loc_F004C994
F004C984: d0162064                 lduh    [%i0+0x64], %o0
F004C988: 10800075                 ba      loc_F004CB5C
F004C98C: a0102002                 mov     2, %l0
F004C990: d0162064                 lduh    [%i0+0x64], %o0
F004C994: 808a2200                 btst    0x200, %o0
F004C998: 02800012                 be      loc_F004C9E0
F004C99C: 113c04cf                 sethi   %hi(_active_u), %o0
F004C9A0: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F004C9A4: d002201c                 ld      [%o0+0x1C], %o0
F004C9A8: d2522002                 ldsh    [%o0+2], %o1
F004C9AC: 80a26000                 cmp     %o1, 0
F004C9B0: 0280000d                 be      loc_F004C9E4
F004C9B4: d407bfdc                 ld      [%fp+var_24], %o2
F004C9B8: d0562068                 ldsh    [%i0+0x68], %o0
F004C9BC: 80a24008                 cmp     %o1, %o0
F004C9C0: 02800009                 be      loc_F004C9E4
F004C9C4: d007bfdc                 ld      [%fp+var_24], %o0
F004C9C8: d0522068                 ldsh    [%o0+0x68], %o0
F004C9CC: 80a20009                 cmp     %o0, %o1
F004C9D0: 22800006                 be,a    loc_F004C9E8
F004C9D4: d002a018                 ld      [%o2+0x18], %o0
F004C9D8: 10800061                 ba      loc_F004CB5C
F004C9DC: a0102001                 mov     1, %l0
F004C9E0: d407bfdc                 ld      [%fp+var_24], %o2
F004C9E4: d002a018                 ld      [%o2+0x18], %o0
F004C9E8: 80a22000                 cmp     %o0, 0
F004C9EC: 02800004                 be      loc_F004C9FC
F004C9F0: 80a6e000                 cmp     %i3, 0
F004C9F4: 1080005a                 ba      loc_F004CB5C
F004C9F8: a0102010                 mov     0x10, %l0
F004C9FC: 02800014                 be      loc_F004CA4C
F004CA00: 1300003c                 sethi   0xF000, %o1
F004CA04: d012a064                 lduh    [%o2+0x64], %o0
F004CA08: 900a0009                 and     %o0, %o1, %o0
F004CA0C: 13000010                 sethi   0x4000, %o1
F004CA10: 80a20009                 cmp     %o0, %o1
F004CA14: 1280000f                 bne     loc_F004CA50
F004CA18: 9006200c                 add     %i0, 0xC, %o0
F004CA1C: d052a066                 ldsh    [%o2+0x66], %o0
F004CA20: 80a22002                 cmp     %o0, 2
F004CA24: 3280004e                 bne,a   loc_F004CB5C
F004CA28: a0102042                 mov     0x42, %l0 ! 'B'
F004CA2C: d2062048                 ld      [%i0+0x48], %o1
F004CA30: 400000e5                 call    sub_F004CDC4
F004CA34: 9010000a                 mov     %o2, %o0
F004CA38: 80a22000                 cmp     %o0, 0
F004CA3C: 12800005                 bne     loc_F004CA50
F004CA40: 9006200c                 add     %i0, 0xC, %o0
F004CA44: 10800046                 ba      loc_F004CB5C
F004CA48: a0102042                 mov     0x42, %l0 ! 'B'
F004CA4C: 9006200c                 add     %i0, 0xC, %o0
F004CA50: 7fff6476                 call    _dnlc_remove
F004CA54: 92100019                 mov     %i1, %o1
F004CA58: d007bfe4                 ld      [%fp+var_1C], %o0
F004CA5C: 808a23ff                 btst    0x3FF, %o0
F004CA60: 12800004                 bne     loc_F004CA70
F004CA64: d407bff0                 ld      [%fp+var_10], %o2
F004CA68: 10800008                 ba      loc_F004CA88
F004CA6C: c0228000                 clr     [%o2]
F004CA70: d007bfe8                 ld      [%fp+var_18], %o0
F004CA74: 90228008                 sub     %o2, %o0, %o0
F004CA78: d2122004                 lduh    [%o0+4], %o1
F004CA7C: d412a004                 lduh    [%o2+4], %o2
F004CA80: 9202400a                 add     %o1, %o2, %o1
F004CA84: d2322004                 sth     %o1, [%o0+4]
F004CA88: 7fff5f38                 call    _bwrite
F004CA8C: d007bfec                 ld      [%fp+var_14], %o0
F004CA90: c027bfec                 clr     [%fp+var_14]
F004CA94: d0162044                 lduh    [%i0+0x44], %o0
F004CA98: d407bfdc                 ld      [%fp+var_24], %o2
F004CA9C: 90122042                 bset    0x42, %o0 ! 'B'
F004CAA0: d0362044                 sth     %o0, [%i0+0x44]
F004CAA4: d012a044                 lduh    [%o2+0x44], %o0
F004CAA8: 90122040                 bset    0x40, %o0 ! '@'
F004CAAC: d032a044                 sth     %o0, [%o2+0x44]
F004CAB0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F004CAB4: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F004CAB8: d04a2038                 ldsb    [%o0+0x38], %o0
F004CABC: 80a22000                 cmp     %o0, 0
F004CAC0: 22800004                 be,a    loc_F004CAD0
F004CAC4: d052a066                 ldsh    [%o2+0x66], %o0
F004CAC8: 10800025                 ba      loc_F004CB5C
F004CACC: a0100008                 mov     %o0, %l0
F004CAD0: 80a22000                 cmp     %o0, 0
F004CAD4: 04800022                 ble     loc_F004CB5C
F004CAD8: 96100008                 mov     %o0, %o3
F004CADC: 80a6e000                 cmp     %i3, 0
F004CAE0: 0280001b                 be      loc_F004CB4C
F004CAE4: 1300003c                 sethi   0xF000, %o1
F004CAE8: d012a064                 lduh    [%o2+0x64], %o0
F004CAEC: 900a0009                 and     %o0, %o1, %o0
F004CAF0: 13000010                 sethi   0x4000, %o1
F004CAF4: 80a20009                 cmp     %o0, %o1
F004CAF8: 12800016                 bne     loc_F004CB50
F004CAFC: d207bfdc                 ld      [%fp+var_24], %o1
F004CB00: 9002fffe                 add     %o3, -2, %o0
F004CB04: d032a066                 sth     %o0, [%o2+0x66]
F004CB08: 9002a00c                 add     %o2, 0xC, %o0
F004CB0C: 133c043a                 sethi   %hi(asc_F010EB18), %o1! "."
F004CB10: d4162066                 lduh    [%i0+0x66], %o2
F004CB14: 92126318                 bset    %lo(asc_F010EB18), %o1! "."
F004CB18: 9402bfff                 inc     -1, %o2
F004CB1C: 7fff6443                 call    _dnlc_remove
F004CB20: d4362066                 sth     %o2, [%i0+0x66]
F004CB24: 133c043a                 sethi   %hi(asc_F010EB20), %o1! ".."
F004CB28: d007bfdc                 ld      [%fp+var_24], %o0
F004CB2C: 92126320                 bset    %lo(asc_F010EB20), %o1! ".."
F004CB30: 7fff643e                 call    _dnlc_remove
F004CB34: 9002200c                 inc     0xC, %o0
F004CB38: d007bfdc                 ld      [%fp+var_24], %o0
F004CB3C: 400006f0                 call    _itrunc
F004CB40: 92102000                 mov     0, %o1
F004CB44: 10800007                 ba      loc_F004CB60
F004CB48: d007bfdc                 ld      [%fp+var_24], %o0
F004CB4C: d207bfdc                 ld      [%fp+var_24], %o1
F004CB50: d0126066                 lduh    [%o1+0x66], %o0
F004CB54: 90023fff                 inc     -1, %o0
F004CB58: d0326066                 sth     %o0, [%o1+0x66]
F004CB5C: d007bfdc                 ld      [%fp+var_24], %o0
F004CB60: 80a22000                 cmp     %o0, 0
F004CB64: 2280000c                 be,a    loc_F004CB94
F004CB68: d007bfec                 ld      [%fp+var_14], %o0
F004CB6C: 4000058b                 call    _iput
F004CB70: 01000000                 nop
F004CB74: d207bfdc                 ld      [%fp+var_24], %o1
F004CB78: d0526066                 ldsh    [%o1+0x66], %o0
F004CB7C: 80a22000                 cmp     %o0, 0
F004CB80: 12800005                 bne     loc_F004CB94
F004CB84: d007bfec                 ld      [%fp+var_14], %o0
F004CB88: 4000fd8e                 call    _vnode_uncache
F004CB8C: 9002600c                 add     %o1, 0xC, %o0
F004CB90: d007bfec                 ld      [%fp+var_14], %o0
F004CB94: 80a22000                 cmp     %o0, 0
F004CB98: 22800005                 be,a    loc_F004CBAC
F004CB9C: d2162044                 lduh    [%i0+0x44], %o1
F004CBA0: 7fff5f32                 call    _brelse
F004CBA4: 01000000                 nop
F004CBA8: d2162044                 lduh    [%i0+0x44], %o1
F004CBAC: 1100003f901223fe         set     0xFFFE, %o0
F004CBB4: 920a4008                 and     %o1, %o0, %o1
F004CBB8: 808a6010                 btst    0x10, %o1
F004CBBC: 02800008                 be      loc_F004CBDC
F004CBC0: d2362044                 sth     %o1, [%i0+0x44]
F004CBC4: 1100003f901223ef         set     0xFFEF, %o0
F004CBCC: 900a4008                 and     %o1, %o0, %o0
F004CBD0: d0362044                 sth     %o0, [%i0+0x44]
F004CBD4: 7fff1885                 call    _wakeup
F004CBD8: 90100018                 mov     %i0, %o0
F004CBDC: b0100010                 mov     %l0, %i0
F004CBE0: 81c7e008                 ret
F004CBE4: 81e80000                 restore

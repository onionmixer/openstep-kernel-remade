F004CEAC: 9de3bf90                 save    %sp, -0x70, %sp
F004CEB0: a6100018                 mov     %i0, %l3
F004CEB4: 133c043a                 sethi   %hi(unk_F010EB7D), %o1
F004CEB8: d00a637d                 ldub    [%o1+%lo(unk_F010EB7D)], %o0
F004CEBC: 808a2001                 btst    1, %o0
F004CEC0: 0280000d                 be      loc_F004CEF4
F004CEC4: b0102000                 mov     0, %i0
F004CEC8: a0100009                 mov     %o1, %l0
F004CECC: 9014237d                 or      %l0, 0x37D, %o0! unsigned int
F004CED0: d40c237d                 ldub    [%l0+0x37D], %o2
F004CED4: 9210200a                 mov     0xA, %o1
F004CED8: 9412a002                 bset    2, %o2
F004CEDC: 7fff15e7                 call    _sleep
F004CEE0: d42c237d                 stb     %o2, [%l0+0x37D]
F004CEE4: d00c237d                 ldub    [%l0+0x37D], %o0
F004CEE8: 808a2001                 btst    1, %o0
F004CEEC: 12bffff9                 bne     loc_F004CED0
F004CEF0: 9014237d                 or      %l0, 0x37D, %o0
F004CEF4: 113c043a                 sethi   %hi(unk_F010EB7D), %o0
F004CEF8: 92102001                 mov     1, %o1
F004CEFC: d4066048                 ld      [%i1+0x48], %o2
F004CF00: d22a237d                 stb     %o1, [%o0+%lo(unk_F010EB7D)]
F004CF04: d004e048                 ld      [%l3+0x48], %o0
F004CF08: 80a28008                 cmp     %o2, %o0
F004CF0C: 12800006                 bne     loc_F004CF24
F004CF10: a0100019                 mov     %i1, %l0
F004CF14: 1080005e                 ba      loc_F004D08C
F004CF18: b0102016                 mov     0x16, %i0
F004CF1C: 10800057                 ba      loc_F004D078
F004CF20: b0102016                 mov     0x16, %i0
F004CF24: 80a2a002                 cmp     %o2, 2
F004CF28: 0280005a                 be      loc_F004D090
F004CF2C: 233c043a                 sethi   -0xFEF1800, %l1
F004CF30: a4102000                 mov     0, %l2
F004CF34: 1100003faa1223fe         set     0xFFFE, %l5
F004CF3C: 1100003fa81223ef         set     0xFFEF, %l4
F004CF44: d0142064                 lduh    [%l0+0x64], %o0
F004CF48: 1300003c                 sethi   0xF000, %o1
F004CF4C: 900a0009                 and     %o0, %o1, %o0
F004CF50: 13000010                 sethi   0x4000, %o1
F004CF54: 80a20009                 cmp     %o0, %o1
F004CF58: 1280000a                 bne     loc_F004CF80
F004CF5C: 90100010                 mov     %l0, %o0
F004CF60: d0542066                 ldsh    [%l0+0x66], %o0
F004CF64: 80a22000                 cmp     %o0, 0
F004CF68: 02800006                 be      loc_F004CF80
F004CF6C: 90100010                 mov     %l0, %o0
F004CF70: d0042070                 ld      [%l0+0x70], %o0
F004CF74: 80a22017                 cmp     %o0, 0x17
F004CF78: 18800005                 bgu     loc_F004CF8C
F004CF7C: 90100010                 mov     %l0, %o0
F004CF80: 133c043a                 sethi   %hi(aBadSizeUnlinke), %o1! "bad size, unlinked or not dir"
F004CF84: 10800016                 ba      loc_F004CFDC
F004CF88: 92126380                 bset    %lo(aBadSizeUnlinke), %o1! "bad size, unlinked or not dir"
F004CF8C: 92102000                 mov     0, %o1
F004CF90: 7fffff16                 call    _blkatoff
F004CF94: 9407bff4                 add     %fp, var_C, %o2
F004CF98: a4920000                 orcc    %o0, %g0, %l2
F004CF9C: 02800035                 be      loc_F004D070
F004CFA0: 113c04cf                 sethi   -0xFECC400, %o0
F004CFA4: d407bff4                 ld      [%fp+var_C], %o2
F004CFA8: d052a012                 ldsh    [%o2+0x12], %o0
F004CFAC: 80a22002                 cmp     %o0, 2
F004CFB0: 12800009                 bne     loc_F004CFD4
F004CFB4: 90100010                 mov     %l0, %o0
F004CFB8: d002a014                 ld      [%o2+0x14], %o0
F004CFBC: 133fffc0                 sethi   -0x10000, %o1
F004CFC0: 900a0009                 and     %o0, %o1, %o0
F004CFC4: 130b8b80                 sethi   0x2E2E0000, %o1
F004CFC8: 80a20009                 cmp     %o0, %o1
F004CFCC: 02800008                 be      loc_F004CFEC
F004CFD0: 90100010                 mov     %l0, %o0
F004CFD4: 133c043a921263a0         set     aMangledEntry_1, %o1! "mangled .. entry"
F004CFDC: 7fffff6c                 call    sub_F004CD8C
F004CFE0: 94102000                 mov     0, %o2
F004CFE4: 10800025                 ba      loc_F004D078
F004CFE8: b0102014                 mov     0x14, %i0
F004CFEC: e202a00c                 ld      [%o2+0xC], %l1
F004CFF0: d004e048                 ld      [%l3+0x48], %o0
F004CFF4: 80a44008                 cmp     %l1, %o0
F004CFF8: 02bfffc9                 be      loc_F004CF1C
F004CFFC: 80a46002                 cmp     %l1, 2
F004D000: 0280001f                 be      loc_F004D07C
F004D004: 80a4a000                 cmp     %l2, 0
F004D008: 7fff5e18                 call    _brelse
F004D00C: 90100012                 mov     %l2, %o0
F004D010: 80a40019                 cmp     %l0, %i1
F004D014: 02800006                 be      loc_F004D02C
F004D018: a4102000                 mov     0, %l2
F004D01C: 4000045f                 call    _iput
F004D020: 90100010                 mov     %l0, %o0
F004D024: 1080000c                 ba      loc_F004D054
F004D028: d0542046                 ldsh    [%l0+0x46], %o0
F004D02C: d0166044                 lduh    [%i1+0x44], %o0
F004D030: 900a0015                 and     %o0, %l5, %o0
F004D034: 808a2010                 btst    0x10, %o0
F004D038: 02800006                 be      loc_F004D050
F004D03C: d0366044                 sth     %o0, [%i1+0x44]
F004D040: 900a0014                 and     %o0, %l4, %o0
F004D044: d0366044                 sth     %o0, [%i1+0x44]
F004D048: 7fff1768                 call    _wakeup
F004D04C: 90100019                 mov     %i1, %o0
F004D050: d0542046                 ldsh    [%l0+0x46], %o0
F004D054: d2042050                 ld      [%l0+0x50], %o1
F004D058: 40000320                 call    _iget
F004D05C: 94100011                 mov     %l1, %o2
F004D060: a0920000                 orcc    %o0, %g0, %l0
F004D064: 32bfffb9                 bne,a   loc_F004CF48
F004D068: d0142064                 lduh    [%l0+0x64], %o0
F004D06C: 113c04cf                 sethi   -0xFECC400, %o0
F004D070: d00221dc                 ld      [%o0+0x1DC], %o0
F004D074: f04a2038                 ldsb    [%o0+0x38], %i0
F004D078: 80a4a000                 cmp     %l2, 0
F004D07C: 02800005                 be      loc_F004D090
F004D080: 233c043a                 sethi   -0xFEF1800, %l1
F004D084: 7fff5df9                 call    _brelse
F004D088: 90100012                 mov     %l2, %o0
F004D08C: 233c043a                 sethi   -0xFEF1800, %l1
F004D090: d00c637d                 ldub    [%l1+0x37D], %o0
F004D094: 808a2002                 btst    2, %o0
F004D098: 02800004                 be      loc_F004D0A8
F004D09C: 9014637d                 or      %l1, 0x37D, %o0
F004D0A0: 7fff1752                 call    _wakeup
F004D0A4: 01000000                 nop
F004D0A8: 80a42000                 cmp     %l0, 0
F004D0AC: 0280001a                 be      locret_F004D114
F004D0B0: c02c637d                 clrb    [%l1+0x37D]
F004D0B4: 80a40019                 cmp     %l0, %i1
F004D0B8: 02800017                 be      locret_F004D114
F004D0BC: 01000000                 nop
F004D0C0: 40000436                 call    _iput
F004D0C4: 90100010                 mov     %l0, %o0
F004D0C8: 10800007                 ba      loc_F004D0E4
F004D0CC: d0166044                 lduh    [%i1+0x44], %o0
F004D0D0: d0366044                 sth     %o0, [%i1+0x44]
F004D0D4: 90100019                 mov     %i1, %o0! unsigned int
F004D0D8: 7fff1568                 call    _sleep
F004D0DC: 9210200a                 mov     0xA, %o1
F004D0E0: d0166044                 lduh    [%i1+0x44], %o0
F004D0E4: 808a2001                 btst    1, %o0
F004D0E8: 12bffffa                 bne     loc_F004D0D0
F004D0EC: 90122010                 bset    0x10, %o0
F004D0F0: d0166044                 lduh    [%i1+0x44], %o0
F004D0F4: 80a62000                 cmp     %i0, 0
F004D0F8: 90122001                 bset    1, %o0
F004D0FC: 12800006                 bne     locret_F004D114
F004D100: d0366044                 sth     %o0, [%i1+0x44]
F004D104: d0566066                 ldsh    [%i1+0x66], %o0
F004D108: 80a22000                 cmp     %o0, 0
F004D10C: 22800002                 be,a    locret_F004D114
F004D110: b0102002                 mov     2, %i0
F004D114: 81c7e008                 ret
F004D118: 81e80000                 restore

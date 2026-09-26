F002CE7C: 9de3bf80                 save    %sp, -0x80, %sp
F002CE80: 7ffff2e4                 call    _ifa_ifwithnet
F002CE84: 90100019                 mov     %i1, %o0
F002CE88: 80a22000                 cmp     %o0, 0
F002CE8C: 32800007                 bne,a   loc_F002CEA8
F002CE90: d0160000                 lduh    [%i0], %o0
F002CE94: 133c04d4                 sethi   %hi(_rtstat), %o1
F002CE98: d0126280                 lduh    [%o1+%lo(_rtstat)], %o0
F002CE9C: 90022001                 inc     %o0
F002CEA0: 1080007d                 ba      locret_F002D094
F002CEA4: d0326280                 sth     %o0, [%o1+%lo(_rtstat)]
F002CEA8: d037bfe4                 sth     %o0, [%fp+var_1C]
F002CEAC: d0162002                 lduh    [%i0+2], %o0
F002CEB0: d037bfe6                 sth     %o0, [%fp+var_1A]
F002CEB4: d0162004                 lduh    [%i0+4], %o0
F002CEB8: d037bfe8                 sth     %o0, [%fp+var_18]
F002CEBC: d0162006                 lduh    [%i0+6], %o0
F002CEC0: d037bfea                 sth     %o0, [%fp+var_16]
F002CEC4: d0162008                 lduh    [%i0+8], %o0
F002CEC8: d037bfec                 sth     %o0, [%fp+var_14]
F002CECC: d016200a                 lduh    [%i0+0xA], %o0
F002CED0: d037bfee                 sth     %o0, [%fp+var_12]
F002CED4: d016200c                 lduh    [%i0+0xC], %o0
F002CED8: d037bff0                 sth     %o0, [%fp+var_10]
F002CEDC: d216200e                 lduh    [%i0+0xE], %o1
F002CEE0: 9007bfe0                 add     %fp, var_20, %o0
F002CEE4: d237bff2                 sth     %o1, [%fp+var_E]
F002CEE8: 7fffff5c                 call    _rtalloc
F002CEEC: c027bfe0                 clr     [%fp+var_20]
F002CEF0: e007bfe0                 ld      [%fp+var_20], %l0
F002CEF4: 80a42000                 cmp     %l0, 0
F002CEF8: 02800008                 be      loc_F002CF18
F002CEFC: 9010001b                 mov     %i3, %o0! void *
F002CF00: 92042014                 add     %l0, 0x14, %o1! void *
F002CF04: 7fff6416                 call    _bcmp
F002CF08: 94102010                 mov     0x10, %o2
F002CF0C: 80a22000                 cmp     %o0, 0
F002CF10: 12800007                 bne     loc_F002CF2C
F002CF14: 133c04d4                 sethi   -0xFECB000, %o1
F002CF18: 7ffff26c                 call    _ifa_ifwithaddr
F002CF1C: 90100019                 mov     %i1, %o0
F002CF20: 80a22000                 cmp     %o0, 0
F002CF24: 02800008                 be      loc_F002CF44
F002CF28: 133c04d4                 sethi   -0xFECB000, %o1
F002CF2C: d0126280                 lduh    [%o1+0x280], %o0
F002CF30: 80a42000                 cmp     %l0, 0
F002CF34: 90022001                 inc     %o0
F002CF38: 02800057                 be      locret_F002D094
F002CF3C: d0326280                 sth     %o0, [%o1+0x280]
F002CF40: 30800053                 ba,a    loc_F002D08C
F002CF44: 80a42000                 cmp     %l0, 0
F002CF48: 02800012                 be      loc_F002CF90
F002CF4C: 133c0430                 sethi   %hi(_afswitch), %o1
F002CF50: 113c04d990122060         set     _wildcard, %o0
F002CF58: d4160000                 lduh    [%i0], %o2
F002CF5C: 92126150                 bset    %lo(_afswitch), %o1
F002CF60: 952aa003                 sll     %o2, 3, %o2
F002CF64: 94028009                 add     %o2, %o1, %o2
F002CF68: d402a004                 ld      [%o2+4], %o2
F002CF6C: 9fc28000                 call    %o2
F002CF70: 92042004                 add     %l0, 4, %o1
F002CF74: 80a22000                 cmp     %o0, 0
F002CF78: 02800006                 be      loc_F002CF90
F002CF7C: 80a42000                 cmp     %l0, 0
F002CF80: 7fffffa9                 call    _rtfree
F002CF84: 90100010                 mov     %l0, %o0
F002CF88: a0102000                 mov     0, %l0
F002CF8C: 80a42000                 cmp     %l0, 0
F002CF90: 3280000f                 bne,a   loc_F002CFCC
F002CF94: d0142024                 lduh    [%l0+0x24], %o0
F002CF98: 90100018                 mov     %i0, %o0
F002CF9C: 92100019                 mov     %i1, %o1
F002CFA0: 15200c1c9412a20a         set     -0x7FCF8DF6, %o2
F002CFA8: 960ea004                 and     %i2, 4, %o3
F002CFAC: 4000011d                 call    _rtinit
F002CFB0: 9612e012                 bset    0x12, %o3
F002CFB4: 133c04d492126280         set     _rtstat, %o1
F002CFBC: d0126002                 lduh    [%o1+2], %o0
F002CFC0: 90022001                 inc     %o0
F002CFC4: 10800034                 ba      locret_F002D094
F002CFC8: d0326002                 sth     %o0, [%o1+2]
F002CFCC: 808a2002                 btst    2, %o0
F002CFD0: 0280002b                 be      loc_F002D07C
F002CFD4: 808a2004                 btst    4, %o0
F002CFD8: 32800011                 bne,a   loc_F002D01C
F002CFDC: d0164000                 lduh    [%i1], %o0
F002CFE0: 808ea004                 btst    4, %i2
F002CFE4: 0280000d                 be      loc_F002D018
F002CFE8: 90100018                 mov     %i0, %o0
F002CFEC: 92100019                 mov     %i1, %o1
F002CFF0: 15200c1c9412a20a         set     -0x7FCF8DF6, %o2
F002CFF8: 4000010a                 call    _rtinit
F002CFFC: 9616a010                 or      %i2, 0x10, %o3
F002D000: 133c04d492126280         set     _rtstat, %o1
F002D008: d0126002                 lduh    [%o1+2], %o0
F002D00C: 90022001                 inc     %o0
F002D010: 1080001f                 ba      loc_F002D08C
F002D014: d0326002                 sth     %o0, [%o1+2]
F002D018: d0164000                 lduh    [%i1], %o0
F002D01C: d0342014                 sth     %o0, [%l0+0x14]
F002D020: d0166002                 lduh    [%i1+2], %o0
F002D024: d0342016                 sth     %o0, [%l0+0x16]
F002D028: d0166004                 lduh    [%i1+4], %o0
F002D02C: d0342018                 sth     %o0, [%l0+0x18]
F002D030: d0166006                 lduh    [%i1+6], %o0
F002D034: d034201a                 sth     %o0, [%l0+0x1A]
F002D038: d0166008                 lduh    [%i1+8], %o0
F002D03C: d034201c                 sth     %o0, [%l0+0x1C]
F002D040: d016600a                 lduh    [%i1+0xA], %o0
F002D044: d034201e                 sth     %o0, [%l0+0x1E]
F002D048: d016600c                 lduh    [%i1+0xC], %o0
F002D04C: d0342020                 sth     %o0, [%l0+0x20]
F002D050: d216600e                 lduh    [%i1+0xE], %o1
F002D054: d0142024                 lduh    [%l0+0x24], %o0
F002D058: d2342022                 sth     %o1, [%l0+0x22]
F002D05C: 90122020                 bset    0x20, %o0 ! ' '
F002D060: d0342024                 sth     %o0, [%l0+0x24]
F002D064: 133c04d492126280         set     _rtstat, %o1
F002D06C: d0126004                 lduh    [%o1+4], %o0
F002D070: 90022001                 inc     %o0
F002D074: 10800006                 ba      loc_F002D08C
F002D078: d0326004                 sth     %o0, [%o1+4]
F002D07C: 133c04d4                 sethi   %hi(_rtstat), %o1
F002D080: d0126280                 lduh    [%o1+%lo(_rtstat)], %o0
F002D084: 90022001                 inc     %o0
F002D088: d0326280                 sth     %o0, [%o1+%lo(_rtstat)]
F002D08C: 7fffff66                 call    _rtfree
F002D090: 90100010                 mov     %l0, %o0
F002D094: 81c7e008                 ret
F002D098: 81e80000                 restore

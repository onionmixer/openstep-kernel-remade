F00D0AA4: 9de3bf18                 save    %sp, -0xE8, %sp
F00D0AA8: 9410201c                 mov     0x1C, %o2
F00D0AAC: 9607bf7c                 add     %fp, var_84, %o3
F00D0AB0: 9807bf78                 add     %fp, var_88, %o4
F00D0AB4: 133c0504                 sethi   %hi(paAllocatebuffer), %o1
F00D0AB8: d0062128                 ld      [%i0+0x128], %o0! id
F00D0ABC: a007bf90                 add     %fp, var_70, %l0
F00D0AC0: d2026184                 ld      [%o1+%lo(paAllocatebuffer)], %o1! SEL
F00D0AC4: 4000836b                 call    _objc_msgSend
F00D0AC8: a207bf94                 add     %fp, var_6C, %l1
F00D0ACC: a6100008                 mov     %o0, %l3
F00D0AD0: 90100010                 mov     %l0, %o0! void *
F00D0AD4: 7fff10e1                 call    _bzero
F00D0AD8: 92102060                 mov     0x60, %o1 ! '`'
F00D0ADC: d0062128                 ld      [%i0+0x128], %o0! id
F00D0AE0: 133c0504                 sethi   %hi(paGetdmaalignmen), %o1
F00D0AE4: d2026180                 ld      [%o1+%lo(paGetdmaalignmen)], %o1! SEL
F00D0AE8: 40008362                 call    _objc_msgSend
F00D0AEC: 9407bf80                 add     %fp, var_80, %o2
F00D0AF0: d01e2108                 ldd     [%i0+0x108], %o0
F00D0AF4: d407bf88                 ld      [%fp+var_78], %o2
F00D0AF8: d22fbf90                 stb     %o1, [%fp+var_70]
F00D0AFC: d01e2110                 ldd     [%i0+0x110], %o0
F00D0B00: 80a2a001                 cmp     %o2, 1
F00D0B04: d22fbf91                 stb     %o1, [%fp+var_6F]
F00D0B08: 90102001                 mov     1, %o0
F00D0B0C: 08800006                 bleu    loc_F00D0B24
F00D0B10: d02fbfa0                 stb     %o0, [%fp+var_60]
F00D0B14: 9002a01b                 add     %o2, 0x1B, %o0
F00D0B18: 9220000a                 neg     %o2, %o1
F00D0B1C: 10800003                 ba      loc_F00D0B28
F00D0B20: 900a0009                 and     %o0, %o1, %o0
F00D0B24: 9010201c                 mov     0x1C, %o0
F00D0B28: d027bfa4                 st      %o0, [%fp+var_5C]
F00D0B2C: 9010200a                 mov     0xA, %o0
F00D0B30: d027bfa8                 st      %o0, [%fp+var_58]
F00D0B34: d207bfac                 ld      [%fp+var_54], %o1
F00D0B38: 11200000                 sethi   0x80000000, %o0
F00D0B3C: 902a4008                 andn    %o1, %o0, %o0
F00D0B40: d027bfac                 st      %o0, [%fp+var_54]
F00D0B44: 90102003                 mov     3, %o0
F00D0B48: d02c4000                 stb     %o0, [%l1]
F00D0B4C: d0044000                 ld      [%l1], %o0
F00D0B50: 13003800                 sethi   0xE00000, %o1
F00D0B54: d41e2110                 ldd     [%i0+0x110], %o2
F00D0B58: 922a0009                 andn    %o0, %o1, %o1
F00D0B5C: 900ae007                 and     %o3, 7, %o0
F00D0B60: 912a2015                 sll     %o0, 21, %o0
F00D0B64: 92124008                 bset    %o0, %o1
F00D0B68: d2244000                 st      %o1, [%l1]
F00D0B6C: 9010201c                 mov     0x1C, %o0
F00D0B70: d02c6004                 stb     %o0, [%l1+4]
F00D0B74: e4062128                 ld      [%i0+0x128], %l2
F00D0B78: 113c0505                 sethi   %hi(paExecuterequest_0), %o0
F00D0B7C: e00223b0                 ld      [%o0+%lo(paExecuterequest_0)], %l0
F00D0B80: 7fffe5b0                 call    _IOVmTaskSelf
F00D0B84: a207bf90                 add     %fp, var_70, %l1
F00D0B88: 98100008                 mov     %o0, %o4
F00D0B8C: 90100012                 mov     %l2, %o0! id
F00D0B90: 92100010                 mov     %l0, %o1! SEL
F00D0B94: 94100011                 mov     %l1, %o2
F00D0B98: 40008336                 call    _objc_msgSend
F00D0B9C: 96100013                 mov     %l3, %o3
F00D0BA0: b0920000                 orcc    %o0, %g0, %i0
F00D0BA4: 12800011                 bne     loc_F00D0BE8
F00D0BA8: d007bf7c                 ld      [%fp+var_84], %o0
F00D0BAC: d004c000                 ld      [%l3], %o0
F00D0BB0: d0268000                 st      %o0, [%i2]
F00D0BB4: d004e004                 ld      [%l3+4], %o0
F00D0BB8: d026a004                 st      %o0, [%i2+4]
F00D0BBC: d004e008                 ld      [%l3+8], %o0
F00D0BC0: d026a008                 st      %o0, [%i2+8]
F00D0BC4: d004e00c                 ld      [%l3+0xC], %o0
F00D0BC8: d026a00c                 st      %o0, [%i2+0xC]
F00D0BCC: d004e010                 ld      [%l3+0x10], %o0
F00D0BD0: d026a010                 st      %o0, [%i2+0x10]
F00D0BD4: d004e014                 ld      [%l3+0x14], %o0
F00D0BD8: d026a014                 st      %o0, [%i2+0x14]
F00D0BDC: d004e018                 ld      [%l3+0x18], %o0
F00D0BE0: d026a018                 st      %o0, [%i2+0x18]
F00D0BE4: d007bf7c                 ld      [%fp+var_84], %o0
F00D0BE8: 7fffd4d7                 call    _IOFree
F00D0BEC: d207bf78                 ld      [%fp+var_88], %o1
F00D0BF0: 81c7e008                 ret
F00D0BF4: 81e80000                 restore

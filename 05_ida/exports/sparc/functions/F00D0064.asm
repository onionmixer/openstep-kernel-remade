F00D0064: 9de3bf18                 save    %sp, -0xE8, %sp
F00D0068: 9410201c                 mov     0x1C, %o2
F00D006C: 9607bf7c                 add     %fp, var_84, %o3
F00D0070: 9807bf78                 add     %fp, var_88, %o4
F00D0074: d0062184                 ld      [%i0+0x184], %o0! id
F00D0078: 133c0504                 sethi   %hi(paAllocatebuffer), %o1
F00D007C: d2026184                 ld      [%o1+%lo(paAllocatebuffer)], %o1! SEL
F00D0080: 400085fc                 call    _objc_msgSend
F00D0084: a007bf90                 add     %fp, var_70, %l0
F00D0088: a6100008                 mov     %o0, %l3
F00D008C: 90100010                 mov     %l0, %o0! void *
F00D0090: 7fff1372                 call    _bzero
F00D0094: 92102060                 mov     0x60, %o1 ! '`'
F00D0098: 90102003                 mov     3, %o0
F00D009C: d02fbf94                 stb     %o0, [%fp+var_6C]
F00D00A0: d407bf94                 ld      [%fp+var_6C], %o2
F00D00A4: 13003800                 sethi   0xE00000, %o1
F00D00A8: d00e2189                 ldub    [%i0+0x189], %o0
F00D00AC: 922a8009                 andn    %o2, %o1, %o1
F00D00B0: 900a2007                 and     %o0, 7, %o0
F00D00B4: 912a2015                 sll     %o0, 21, %o0
F00D00B8: 92124008                 bset    %o0, %o1
F00D00BC: d227bf94                 st      %o1, [%fp+var_6C]
F00D00C0: 9010201c                 mov     0x1C, %o0
F00D00C4: d02fbf98                 stb     %o0, [%fp+var_68]
F00D00C8: d00e2188                 ldub    [%i0+0x188], %o0
F00D00CC: d02fbf90                 stb     %o0, [%fp+var_70]
F00D00D0: d40e2189                 ldub    [%i0+0x189], %o2
F00D00D4: 113c0504                 sethi   %hi(paGetdmaalignmen), %o0
F00D00D8: d2022180                 ld      [%o0+%lo(paGetdmaalignmen)], %o1! SEL
F00D00DC: d42fbf91                 stb     %o2, [%fp+var_6F]
F00D00E0: 90102001                 mov     1, %o0
F00D00E4: d02fbfa0                 stb     %o0, [%fp+var_60]
F00D00E8: d0062184                 ld      [%i0+0x184], %o0! id
F00D00EC: 400085e1                 call    _objc_msgSend
F00D00F0: 9407bf80                 add     %fp, var_80, %o2
F00D00F4: d207bf88                 ld      [%fp+var_78], %o1
F00D00F8: 80a26001                 cmp     %o1, 1
F00D00FC: 08800005                 bleu    loc_F00D0110
F00D0100: 9002601b                 add     %o1, 0x1B, %o0
F00D0104: 92200009                 neg     %o1
F00D0108: 10800003                 ba      loc_F00D0114
F00D010C: 900a0009                 and     %o0, %o1, %o0
F00D0110: 9010201c                 mov     0x1C, %o0
F00D0114: d027bfa4                 st      %o0, [%fp+var_5C]
F00D0118: 90102014                 mov     0x14, %o0
F00D011C: d027bfa8                 st      %o0, [%fp+var_58]
F00D0120: d007bfac                 ld      [%fp+var_54], %o0
F00D0124: 13200000                 sethi   0x80000000, %o1
F00D0128: 90120009                 bset    %o1, %o0
F00D012C: d027bfac                 st      %o0, [%fp+var_54]
F00D0130: e4062184                 ld      [%i0+0x184], %l2
F00D0134: 113c0505                 sethi   %hi(paExecuterequest_0), %o0
F00D0138: e00223b0                 ld      [%o0+%lo(paExecuterequest_0)], %l0
F00D013C: 7fffe841                 call    _IOVmTaskSelf
F00D0140: a207bf90                 add     %fp, var_70, %l1
F00D0144: 98100008                 mov     %o0, %o4
F00D0148: 90100012                 mov     %l2, %o0! id
F00D014C: 92100010                 mov     %l0, %o1! SEL
F00D0150: 94100011                 mov     %l1, %o2
F00D0154: 400085c7                 call    _objc_msgSend
F00D0158: 96100013                 mov     %l3, %o3
F00D015C: d204c000                 ld      [%l3], %o1
F00D0160: d2268000                 st      %o1, [%i2]
F00D0164: d204e004                 ld      [%l3+4], %o1
F00D0168: d226a004                 st      %o1, [%i2+4]
F00D016C: d204e008                 ld      [%l3+8], %o1
F00D0170: d226a008                 st      %o1, [%i2+8]
F00D0174: d204e00c                 ld      [%l3+0xC], %o1
F00D0178: d226a00c                 st      %o1, [%i2+0xC]
F00D017C: d204e010                 ld      [%l3+0x10], %o1
F00D0180: d226a010                 st      %o1, [%i2+0x10]
F00D0184: d204e014                 ld      [%l3+0x14], %o1
F00D0188: b0100008                 mov     %o0, %i0
F00D018C: d007bf7c                 ld      [%fp+var_84], %o0
F00D0190: d226a014                 st      %o1, [%i2+0x14]
F00D0194: d404e018                 ld      [%l3+0x18], %o2
F00D0198: d207bf78                 ld      [%fp+var_88], %o1
F00D019C: 7fffd76a                 call    _IOFree
F00D01A0: d426a018                 st      %o2, [%i2+0x18]
F00D01A4: 81c7e008                 ret
F00D01A8: 81e80000                 restore

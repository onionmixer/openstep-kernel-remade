F00CE9F4: 9de3bf18                 save    %sp, -0xE8, %sp
F00CE9F8: a2100018                 mov     %i0, %l1
F00CE9FC: 94102008                 mov     8, %o2
F00CEA00: 133c0504                 sethi   %hi(paAllocatebuffer), %o1
F00CEA04: a007bf90                 add     %fp, var_70, %l0
F00CEA08: b007bf94                 add     %fp, var_6C, %i0
F00CEA0C: d0046184                 ld      [%l1+0x184], %o0! id
F00CEA10: 9607bf7c                 add     %fp, var_84, %o3
F00CEA14: d2026184                 ld      [%o1+%lo(paAllocatebuffer)], %o1! SEL
F00CEA18: 40008b96                 call    _objc_msgSend
F00CEA1C: 9807bf78                 add     %fp, var_88, %o4
F00CEA20: a4100008                 mov     %o0, %l2
F00CEA24: 90100010                 mov     %l0, %o0! void *
F00CEA28: 7fff190c                 call    _bzero
F00CEA2C: 92102060                 mov     0x60, %o1 ! '`'
F00CEA30: d00c6188                 ldub    [%l1+0x188], %o0
F00CEA34: d02fbf90                 stb     %o0, [%fp+var_70]
F00CEA38: d40c6189                 ldub    [%l1+0x189], %o2
F00CEA3C: 113c0504                 sethi   %hi(paGetdmaalignmen), %o0
F00CEA40: d2022180                 ld      [%o0+%lo(paGetdmaalignmen)], %o1! SEL
F00CEA44: d42fbf91                 stb     %o2, [%fp+var_6F]
F00CEA48: 90102001                 mov     1, %o0
F00CEA4C: d02fbfa0                 stb     %o0, [%fp+var_60]
F00CEA50: d0046184                 ld      [%l1+0x184], %o0! id
F00CEA54: 40008b87                 call    _objc_msgSend
F00CEA58: 9407bf80                 add     %fp, var_80, %o2
F00CEA5C: d207bf88                 ld      [%fp+var_78], %o1
F00CEA60: 80a26001                 cmp     %o1, 1
F00CEA64: 08800005                 bleu    loc_F00CEA78
F00CEA68: 90026007                 add     %o1, 7, %o0
F00CEA6C: 92200009                 neg     %o1
F00CEA70: 10800003                 ba      loc_F00CEA7C
F00CEA74: 900a0009                 and     %o0, %o1, %o0
F00CEA78: 90102008                 mov     8, %o0
F00CEA7C: d027bfa4                 st      %o0, [%fp+var_5C]
F00CEA80: 90102014                 mov     0x14, %o0
F00CEA84: d027bfa8                 st      %o0, [%fp+var_58]
F00CEA88: 90100011                 mov     %l1, %o0! id
F00CEA8C: 133c0505                 sethi   %hi(paAllocsdbuf), %o1
F00CEA90: 94102000                 mov     0, %o2
F00CEA94: d607bfac                 ld      [%fp+var_54], %o3
F00CEA98: 19200000                 sethi   0x80000000, %o4
F00CEA9C: d20263d4                 ld      [%o1+%lo(paAllocsdbuf)], %o1! SEL
F00CEAA0: 9612c00c                 bset    %o4, %o3
F00CEAA4: 40008b73                 call    _objc_msgSend
F00CEAA8: d627bfac                 st      %o3, [%fp+var_54]
F00CEAAC: a0100008                 mov     %o0, %l0
F00CEAB0: 90102002                 mov     2, %o0
F00CEAB4: d0240000                 st      %o0, [%l0]
F00CEAB8: 9007bf90                 add     %fp, var_70, %o0
F00CEABC: d0242014                 st      %o0, [%l0+0x14]
F00CEAC0: 7fffede0                 call    _IOVmTaskSelf
F00CEAC4: e424200c                 st      %l2, [%l0+0xC]
F00CEAC8: d0242010                 st      %o0, [%l0+0x10]
F00CEACC: 90102025                 mov     0x25, %o0 ! '%'
F00CEAD0: d02e0000                 stb     %o0, [%i0]
F00CEAD4: 113c0505                 sethi   %hi(paEnqueuesdbuf), %o0
F00CEAD8: d20223d0                 ld      [%o0+%lo(paEnqueuesdbuf)], %o1! SEL
F00CEADC: d80c6189                 ldub    [%l1+0x189], %o4
F00CEAE0: 94100010                 mov     %l0, %o2
F00CEAE4: d60e2001                 ldub    [%i0+1], %o3
F00CEAE8: 90100011                 mov     %l1, %o0! id
F00CEAEC: 992b2005                 sll     %o4, 5, %o4
F00CEAF0: 960ae01f                 and     %o3, 0x1F, %o3
F00CEAF4: 9612c00c                 bset    %o4, %o3
F00CEAF8: d62e2001                 stb     %o3, [%i0+1]
F00CEAFC: d802a020                 ld      [%o2+0x20], %o4
F00CEB00: 17200000                 sethi   0x80000000, %o3
F00CEB04: 962b000b                 andn    %o4, %o3, %o3
F00CEB08: 40008b5a                 call    _objc_msgSend
F00CEB0C: d622a020                 st      %o3, [%o2+0x20]
F00CEB10: f007bfb0                 ld      [%fp+var_50], %i0
F00CEB14: 80a62000                 cmp     %i0, 0
F00CEB18: 12800018                 bne     loc_F00CEB78
F00CEB1C: d007bf7c                 ld      [%fp+var_84], %o0
F00CEB20: d007bfb8                 ld      [%fp+var_48], %o0
F00CEB24: 80a22008                 cmp     %o0, 8
F00CEB28: 0280000e                 be      loc_F00CEB60
F00CEB2C: 90100011                 mov     %l1, %o0! id
F00CEB30: b0102016                 mov     0x16, %i0
F00CEB34: 133c0504                 sethi   %hi(paName), %o1
F00CEB38: 213c03ec                 sethi   %hi(aSBadDmaTransfe_0), %l0! "%s: bad DMA Transfer count (%d) on Read"...
F00CEB3C: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00CEB40: 40008b4c                 call    _objc_msgSend
F00CEB44: a01423d0                 bset    %lo(aSBadDmaTransfe_0), %l0! "%s: bad DMA Transfer count (%d) on Read"...
F00CEB48: 92100008                 mov     %o0, %o1
F00CEB4C: d407bfb8                 ld      [%fp+var_48], %o2
F00CEB50: 7fffdd69                 call    _IOLog
F00CEB54: 90100010                 mov     %l0, %o0
F00CEB58: 10800008                 ba      loc_F00CEB78
F00CEB5C: d007bf7c                 ld      [%fp+var_84], %o0
F00CEB60: d0048000                 ld      [%l2], %o0
F00CEB64: d0268000                 st      %o0, [%i2]
F00CEB68: d004a004                 ld      [%l2+4], %o0
F00CEB6C: d026a004                 st      %o0, [%i2+4]
F00CEB70: f007bfb0                 ld      [%fp+var_50], %i0
F00CEB74: d007bf7c                 ld      [%fp+var_84], %o0
F00CEB78: 7fffdcf3                 call    _IOFree
F00CEB7C: d207bf78                 ld      [%fp+var_88], %o1
F00CEB80: 81c7e008                 ret
F00CEB84: 81e80000                 restore

F00CE828: 9de3bf18                 save    %sp, -0xE8, %sp
F00CE82C: a2100018                 mov     %i0, %l1
F00CE830: 94102041                 mov     0x41, %o2 ! 'A'
F00CE834: 133c0504                 sethi   %hi(paAllocatebuffer), %o1
F00CE838: a007bf90                 add     %fp, var_70, %l0
F00CE83C: b007bf94                 add     %fp, var_6C, %i0
F00CE840: d0046184                 ld      [%l1+0x184], %o0! id
F00CE844: 9607bf7c                 add     %fp, var_84, %o3
F00CE848: d2026184                 ld      [%o1+%lo(paAllocatebuffer)], %o1! SEL
F00CE84C: 40008c09                 call    _objc_msgSend
F00CE850: 9807bf78                 add     %fp, var_88, %o4
F00CE854: a4100008                 mov     %o0, %l2
F00CE858: 7fff1980                 call    _bzero
F00CE85C: 92102041                 mov     0x41, %o1 ! 'A'! size_t
F00CE860: 90100010                 mov     %l0, %o0! void *
F00CE864: 7fff197d                 call    _bzero
F00CE868: 92102060                 mov     0x60, %o1 ! '`'
F00CE86C: d00c6188                 ldub    [%l1+0x188], %o0
F00CE870: d02fbf90                 stb     %o0, [%fp+var_70]
F00CE874: d40c6189                 ldub    [%l1+0x189], %o2
F00CE878: 113c0504                 sethi   %hi(paGetdmaalignmen), %o0
F00CE87C: d2022180                 ld      [%o0+%lo(paGetdmaalignmen)], %o1! SEL
F00CE880: d42fbf91                 stb     %o2, [%fp+var_6F]
F00CE884: 90102001                 mov     1, %o0
F00CE888: d02fbfa0                 stb     %o0, [%fp+var_60]
F00CE88C: d0046184                 ld      [%l1+0x184], %o0! id
F00CE890: 40008bf8                 call    _objc_msgSend
F00CE894: 9407bf80                 add     %fp, var_80, %o2
F00CE898: d207bf88                 ld      [%fp+var_78], %o1
F00CE89C: 80a26001                 cmp     %o1, 1
F00CE8A0: 08800005                 bleu    loc_F00CE8B4
F00CE8A4: 90026040                 add     %o1, 0x40, %o0 ! '@'
F00CE8A8: 92200009                 neg     %o1
F00CE8AC: 10800003                 ba      loc_F00CE8B8
F00CE8B0: 900a0009                 and     %o0, %o1, %o0
F00CE8B4: 90102041                 mov     0x41, %o0 ! 'A'
F00CE8B8: d027bfa4                 st      %o0, [%fp+var_5C]
F00CE8BC: 90102014                 mov     0x14, %o0
F00CE8C0: d027bfa8                 st      %o0, [%fp+var_58]
F00CE8C4: 90100011                 mov     %l1, %o0! id
F00CE8C8: 133c0505                 sethi   %hi(paAllocsdbuf), %o1
F00CE8CC: 94102000                 mov     0, %o2
F00CE8D0: d607bfac                 ld      [%fp+var_54], %o3
F00CE8D4: 19200000                 sethi   0x80000000, %o4
F00CE8D8: d20263d4                 ld      [%o1+%lo(paAllocsdbuf)], %o1! SEL
F00CE8DC: 9612c00c                 bset    %o4, %o3
F00CE8E0: 40008be4                 call    _objc_msgSend
F00CE8E4: d627bfac                 st      %o3, [%fp+var_54]
F00CE8E8: a0100008                 mov     %o0, %l0
F00CE8EC: 90102002                 mov     2, %o0
F00CE8F0: d0240000                 st      %o0, [%l0]
F00CE8F4: 9007bf90                 add     %fp, var_70, %o0
F00CE8F8: d0242014                 st      %o0, [%l0+0x14]
F00CE8FC: 7fffee51                 call    _IOVmTaskSelf
F00CE900: e424200c                 st      %l2, [%l0+0xC]
F00CE904: d0242010                 st      %o0, [%l0+0x10]
F00CE908: 90102012                 mov     0x12, %o0
F00CE90C: d02e0000                 stb     %o0, [%i0]
F00CE910: 90100011                 mov     %l1, %o0! id
F00CE914: 133c0505                 sethi   %hi(paEnqueuesdbuf), %o1
F00CE918: d20263d0                 ld      [%o1+%lo(paEnqueuesdbuf)], %o1! SEL
F00CE91C: 94100010                 mov     %l0, %o2
F00CE920: da060000                 ld      [%i0], %o5
F00CE924: 19003800                 sethi   0xE00000, %o4
F00CE928: d60c6189                 ldub    [%l1+0x189], %o3
F00CE92C: 982b400c                 andn    %o5, %o4, %o4
F00CE930: 960ae007                 and     %o3, 7, %o3
F00CE934: 972ae015                 sll     %o3, 21, %o3
F00CE938: 9813000b                 bset    %o3, %o4
F00CE93C: d8260000                 st      %o4, [%i0]
F00CE940: 96102041                 mov     0x41, %o3 ! 'A'
F00CE944: d62e2004                 stb     %o3, [%i0+4]
F00CE948: d802a020                 ld      [%o2+0x20], %o4
F00CE94C: 17200000                 sethi   0x80000000, %o3
F00CE950: 962b000b                 andn    %o4, %o3, %o3
F00CE954: 19100000                 sethi   0x40000000, %o4
F00CE958: 9612c00c                 bset    %o4, %o3
F00CE95C: 40008bc5                 call    _objc_msgSend
F00CE960: d622a020                 st      %o3, [%o2+0x20]
F00CE964: f007bfb0                 ld      [%fp+var_50], %i0
F00CE968: 80a62000                 cmp     %i0, 0
F00CE96C: 1280001e                 bne     loc_F00CE9E4
F00CE970: d007bf7c                 ld      [%fp+var_84], %o0
F00CE974: d407bfb8                 ld      [%fp+__n], %o2
F00CE978: 80a2a005                 cmp     %o2, 5
F00CE97C: 1a80000e                 bcc     loc_F00CE9B4
F00CE980: 90100011                 mov     %l1, %o0! id
F00CE984: b0102016                 mov     0x16, %i0
F00CE988: 133c0504                 sethi   %hi(paName), %o1
F00CE98C: 213c03ec                 sethi   %hi(aSBadDmaTransfe), %l0! "%s: bad DMA Transfer count (%d) on Inqu"...
F00CE990: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00CE994: 40008bb7                 call    _objc_msgSend
F00CE998: a01423a0                 bset    %lo(aSBadDmaTransfe), %l0! "%s: bad DMA Transfer count (%d) on Inqu"...
F00CE99C: 92100008                 mov     %o0, %o1
F00CE9A0: d407bfb8                 ld      [%fp+__n], %o2! __n
F00CE9A4: 7fffddd4                 call    _IOLog
F00CE9A8: 90100010                 mov     %l0, %o0
F00CE9AC: 1080000e                 ba      loc_F00CE9E4
F00CE9B0: d007bf7c                 ld      [%fp+var_84], %o0
F00CE9B4: 90102041                 mov     0x41, %o0 ! 'A'
F00CE9B8: 92a2000a                 subcc   %o0, %o2, %o1! size_t
F00CE9BC: 02800005                 be      loc_F00CE9D0
F00CE9C0: 9010001a                 mov     %i2, %o0! void *
F00CE9C4: 7fff1925                 call    _bzero
F00CE9C8: 9004800a                 add     %l2, %o2, %o0
F00CE9CC: 9010001a                 mov     %i2, %o0! __dst
F00CE9D0: 92100012                 mov     %l2, %o1! __src
F00CE9D4: 7ffce233                 call    _memcpy
F00CE9D8: 94102041                 mov     0x41, %o2 ! 'A'
F00CE9DC: f007bfb0                 ld      [%fp+var_50], %i0
F00CE9E0: d007bf7c                 ld      [%fp+var_84], %o0
F00CE9E4: 7fffdd58                 call    _IOFree
F00CE9E8: d207bf78                 ld      [%fp+var_88], %o1
F00CE9EC: 81c7e008                 ret
F00CE9F0: 81e80000                 restore

F00487C0: 9de3bf98                 save    %sp, -0x68, %sp
F00487C4: e2062050                 ld      [%i0+0x50], %l1
F00487C8: d4046030                 ld      [%l1+0x30], %o2
F00487CC: 80a6800a                 cmp     %i2, %o2
F00487D0: 18800006                 bgu     loc_F00487E8
F00487D4: 113c0439                 sethi   -0xFEF1C00, %o0
F00487D8: d004604c                 ld      [%l1+0x4C], %o0
F00487DC: 80ae8008                 andncc  %i2, %o0, %g0
F00487E0: 0280000a                 be      loc_F0048808
F00487E4: 113c0439                 sethi   -0xFEF1C00, %o0
F00487E8: 901220c8                 bset    0xC8, %o0! char *
F00487EC: d2562046                 ldsh    [%i0+0x46], %o1
F00487F0: 9610001a                 mov     %i2, %o3
F00487F4: 7fff2f99                 call    _printf
F00487F8: 980460d4                 add     %l1, 0xD4, %o4
F00487FC: 113c0439                 sethi   %hi(aAllocBadSize), %o0! "alloc: bad size"
F0048800: 7fff325c                 call    _panic
F0048804: 901220f8                 bset    %lo(aAllocBadSize), %o0! "alloc: bad size"
F0048808: d0046030                 ld      [%l1+0x30], %o0
F004880C: 80a68008                 cmp     %i2, %o0
F0048810: 12800006                 bne     loc_F0048828
F0048814: 113c04cf                 sethi   -0xFECC400, %o0
F0048818: d00460c4                 ld      [%l1+0xC4], %o0
F004881C: 80a22000                 cmp     %o0, 0
F0048820: 02800046                 be      loc_F0048938
F0048824: 113c04cf                 sethi   -0xFECC400, %o0
F0048828: d00221d8                 ld      [%o0+0x1D8], %o0
F004882C: d002201c                 ld      [%o0+0x1C], %o0
F0048830: d0522002                 ldsh    [%o0+2], %o0
F0048834: 80a22000                 cmp     %o0, 0
F0048838: 22800011                 be,a    loc_F004887C
F004883C: d0046024                 ld      [%l1+0x24], %o0
F0048840: d204603c                 ld      [%l1+0x3C], %o1! int
F0048844: e00460c4                 ld      [%l1+0xC4], %l0
F0048848: d0046028                 ld      [%l1+0x28], %o0! int
F004884C: d6046060                 ld      [%l1+0x60], %o3
F0048850: d40460cc                 ld      [%l1+0xCC], %o2
F0048854: a12c000b                 sll     %l0, %o3, %l0
F0048858: 7ffef72a                 call    _umul
F004885C: a004000a                 add     %l0, %o2, %l0
F0048860: 7ffef76a                 call    _div
F0048864: 92102064                 mov     0x64, %o1 ! 'd'
F0048868: a0240008                 sub     %l0, %o0, %l0
F004886C: 80a42000                 cmp     %l0, 0
F0048870: 04800033                 ble     loc_F004893C
F0048874: 90100011                 mov     %l1, %o0
F0048878: d0046024                 ld      [%l1+0x24], %o0
F004887C: 80a64008                 cmp     %i1, %o0
F0048880: 36800002                 bge,a   loc_F0048888
F0048884: b2102000                 mov     0, %i1
F0048888: 80a66000                 cmp     %i1, 0
F004888C: 32800007                 bne,a   loc_F00488A8
F0048890: d20460bc                 ld      [%l1+0xBC], %o1
F0048894: d0062048                 ld      [%i0+0x48], %o0! int
F0048898: 7ffef75a                 call    _udiv
F004889C: d20460b8                 ld      [%l1+0xB8], %o1
F00488A0: 10800005                 ba      loc_F00488B4
F00488A4: 92100008                 mov     %o0, %o1! int
F00488A8: 7ffef758                 call    _div
F00488AC: 90100019                 mov     %i1, %o0
F00488B0: 92100008                 mov     %o0, %o1
F00488B4: 90100018                 mov     %i0, %o0
F00488B8: 94100019                 mov     %i1, %o2
F00488BC: 9610001a                 mov     %i2, %o3
F00488C0: 193c0125                 sethi   %hi(_alloccg), %o4
F00488C4: 400002b2                 call    _hashalloc
F00488C8: 98132348                 bset    %lo(_alloccg), %o4
F00488CC: a0920000                 orcc    %o0, %g0, %l0
F00488D0: 0480001b                 ble     loc_F004893C
F00488D4: 90100011                 mov     %l1, %o0
F00488D8: d0062028                 ld      [%i0+0x28], %o0
F00488DC: d2022080                 ld      [%o0+0x80], %o1
F00488E0: 9fc24000                 call    %o1
F00488E4: 9006200c                 add     %i0, 0xC, %o0! int
F00488E8: 92100008                 mov     %o0, %o1! int
F00488EC: 7ffef747                 call    _div
F00488F0: 9010001a                 mov     %i2, %o0
F00488F4: d20620cc                 ld      [%i0+0xCC], %o1
F00488F8: 92024008                 add     %o1, %o0, %o1
F00488FC: d0162044                 lduh    [%i0+0x44], %o0
F0048900: d22620cc                 st      %o1, [%i0+0xCC]
F0048904: 90122042                 bset    0x42, %o0 ! 'B'
F0048908: d0362044                 sth     %o0, [%i0+0x44]
F004890C: d2046064                 ld      [%l1+0x64], %o1
F0048910: 9410001a                 mov     %i2, %o2
F0048914: d0062040                 ld      [%i0+0x40], %o0
F0048918: 7fff7054                 call    _getblk
F004891C: 932c0009                 sll     %l0, %o1, %o1! size_t
F0048920: b0100008                 mov     %o0, %i0
F0048924: d0062020                 ld      [%i0+0x20], %o0! void *
F0048928: 4001314c                 call    _bzero
F004892C: d2062014                 ld      [%i0+0x14], %o1
F0048930: 10800006                 ba      locret_F0048948
F0048934: c0262028                 clr     [%i0+0x28]
F0048938: 90100011                 mov     %l1, %o0
F004893C: 40000005                 call    _fsfull
F0048940: 92102001                 mov     1, %o1
F0048944: b0102000                 mov     0, %i0
F0048948: 81c7e008                 ret
F004894C: 81e80000                 restore

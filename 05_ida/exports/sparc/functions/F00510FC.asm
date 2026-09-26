F00510FC: 9de3bf98                 save    %sp, -0x68, %sp
F0051100: d0062008                 ld      [%i0+8], %o0
F0051104: d206200c                 ld      [%i0+0xC], %o1
F0051108: d402201c                 ld      [%o0+0x1C], %o2
F005110C: e6026020                 ld      [%o1+0x20], %l3
F0051110: d202a080                 ld      [%o2+0x80], %o1! int
F0051114: 9fc24000                 call    %o1
F0051118: 01000000                 nop
F005111C: a2920000                 orcc    %o0, %g0, %l1
F0051120: 06800040                 bl      locret_F0051220
F0051124: 11000008                 sethi   0x2000, %o0! int
F0051128: 7ffed538                 call    _div
F005112C: 92100011                 mov     %l1, %o1
F0051130: 92100008                 mov     %o0, %o1
F0051134: d0062008                 ld      [%i0+8], %o0! void *
F0051138: 7fff4e4c                 call    _getblk
F005113C: d404e068                 ld      [%l3+0x68], %o2
F0051140: a0100008                 mov     %o0, %l0
F0051144: d2042020                 ld      [%l0+0x20], %o1! void *
F0051148: d404e068                 ld      [%l3+0x68], %o2! size_t
F005114C: 40010e71                 call    _bcopy
F0051150: 90100013                 mov     %l3, %o0
F0051154: d0042020                 ld      [%l0+0x20], %o0
F0051158: c022208c                 clr     [%o0+0x8C]
F005115C: d0042020                 ld      [%l0+0x20], %o0
F0051160: c0222088                 clr     [%o0+0x88]
F0051164: d0042020                 ld      [%l0+0x20], %o0
F0051168: c0222094                 clr     [%o0+0x94]
F005116C: d0042020                 ld      [%l0+0x20], %o0
F0051170: c0222090                 clr     [%o0+0x90]
F0051174: d2042020                 ld      [%l0+0x20], %o1
F0051178: 90100010                 mov     %l0, %o0
F005117C: 7fff4d7b                 call    _bwrite
F0051180: c02a60d3                 clrb    [%o1+0xD3]
F0051184: ea04e2d8                 ld      [%l3+0x2D8], %l5
F0051188: d004e09c                 ld      [%l3+0x9C], %o0
F005118C: a4102000                 mov     0, %l2
F0051190: d204e034                 ld      [%l3+0x34], %o1! int
F0051194: 90023fff                 inc     -1, %o0! int
F0051198: 7ffed51c                 call    _div
F005119C: 90020009                 add     %o0, %o1, %o0
F00511A0: a8100008                 mov     %o0, %l4
F00511A4: 80a48014                 cmp     %l2, %l4
F00511A8: 1680001e                 bge     locret_F0051220
F00511AC: 01000000                 nop
F00511B0: d004e038                 ld      [%l3+0x38], %o0
F00511B4: 90048008                 add     %l2, %o0, %o0
F00511B8: 80a20014                 cmp     %o0, %l4
F00511BC: 04800006                 ble     loc_F00511D4
F00511C0: e204e030                 ld      [%l3+0x30], %l1
F00511C4: d204e034                 ld      [%l3+0x34], %o1
F00511C8: 7ffed4ce                 call    _umul
F00511CC: 90250012                 sub     %l4, %l2, %o0
F00511D0: a2100008                 mov     %o0, %l1
F00511D4: d0062008                 ld      [%i0+8], %o0
F00511D8: d204e098                 ld      [%l3+0x98], %o1
F00511DC: 94100011                 mov     %l1, %o2! size_t
F00511E0: d604e064                 ld      [%l3+0x64], %o3
F00511E4: 92024012                 add     %o1, %l2, %o1
F00511E8: 7fff4e20                 call    _getblk
F00511EC: 932a400b                 sll     %o1, %o3, %o1
F00511F0: a0100008                 mov     %o0, %l0
F00511F4: 90100015                 mov     %l5, %o0! void *
F00511F8: d2042020                 ld      [%l0+0x20], %o1! void *
F00511FC: 40010e45                 call    _bcopy
F0051200: 94100011                 mov     %l1, %o2
F0051204: 7fff4d59                 call    _bwrite
F0051208: 90100010                 mov     %l0, %o0
F005120C: d004e038                 ld      [%l3+0x38], %o0
F0051210: a4048008                 add     %l2, %o0, %l2
F0051214: 80a48014                 cmp     %l2, %l4
F0051218: 06bfffe7                 bl      loc_F00511B4
F005121C: aa054011                 add     %l5, %l1, %l5
F0051220: 81c7e008                 ret
F0051224: 81e80000                 restore

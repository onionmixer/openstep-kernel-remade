F00DA1DC: 9de3bf90                 save    %sp, -0x70, %sp
F00DA1E0: d006202c                 ld      [%i0+0x2C], %o0
F00DA1E4: 9206202c                 add     %i0, 0x2C, %o1 ! ','
F00DA1E8: 80a24008                 cmp     %o1, %o0
F00DA1EC: 2280001a                 be,a    loc_F00DA254
F00DA1F0: d006204c                 ld      [%i0+0x4C], %o0
F00DA1F4: a0100009                 mov     %o1, %l0
F00DA1F8: d206202c                 ld      [%i0+0x2C], %o1
F00DA1FC: d6026008                 ld      [%o1+8], %o3
F00DA200: 80a4000b                 cmp     %l0, %o3
F00DA204: 12800004                 bne     loc_F00DA214
F00DA208: d402600c                 ld      [%o1+0xC], %o2
F00DA20C: 10800003                 ba      loc_F00DA218
F00DA210: 90100010                 mov     %l0, %o0
F00DA214: 9002e008                 add     %o3, 8, %o0
F00DA218: 80a4000a                 cmp     %l0, %o2
F00DA21C: 12800004                 bne     loc_F00DA22C
F00DA220: d4222004                 st      %o2, [%o0+4]
F00DA224: 10800003                 ba      loc_F00DA230
F00DA228: 90100010                 mov     %l0, %o0
F00DA22C: 9002a008                 add     %o2, 8, %o0
F00DA230: d6220000                 st      %o3, [%o0]
F00DA234: 90100009                 mov     %o1, %o0
F00DA238: 7fffaf43                 call    _IOFree
F00DA23C: 92102010                 mov     0x10, %o1
F00DA240: d006202c                 ld      [%i0+0x2C], %o0
F00DA244: 80a40008                 cmp     %l0, %o0
F00DA248: 32bfffed                 bne,a   loc_F00DA1FC
F00DA24C: d206202c                 ld      [%i0+0x2C], %o1! size_t
F00DA250: d006204c                 ld      [%i0+0x4C], %o0! void *
F00DA254: 7ffeeb01                 call    _bzero
F00DA258: d2062038                 ld      [%i0+0x38], %o1
F00DA25C: d006203c                 ld      [%i0+0x3C], %o0
F00DA260: a2102000                 mov     0, %l1
F00DA264: 80a44008                 cmp     %l1, %o0
F00DA268: 1a80001c                 bcc     locret_F00DA2D8
F00DA26C: e406204c                 ld      [%i0+0x4C], %l2
F00DA270: a006202c                 add     %i0, 0x2C, %l0 ! ','
F00DA274: 7fffaf2f                 call    _IOMalloc
F00DA278: 90102010                 mov     0x10, %o0
F00DA27C: 92100008                 mov     %o0, %o1
F00DA280: c0224000                 clr     [%o1]
F00DA284: e4226004                 st      %l2, [%o1+4]
F00DA288: d0062040                 ld      [%i0+0x40], %o0
F00DA28C: a4048008                 add     %l2, %o0, %l2
F00DA290: d006202c                 ld      [%i0+0x2C], %o0
F00DA294: 80a40008                 cmp     %l0, %o0
F00DA298: 32800007                 bne,a   loc_F00DA2B4
F00DA29C: d0062030                 ld      [%i0+0x30], %o0
F00DA2A0: d226202c                 st      %o1, [%i0+0x2C]
F00DA2A4: d2262030                 st      %o1, [%i0+0x30]
F00DA2A8: e0226008                 st      %l0, [%o1+8]
F00DA2AC: 10800006                 ba      loc_F00DA2C4
F00DA2B0: e022600c                 st      %l0, [%o1+0xC]
F00DA2B4: d022600c                 st      %o0, [%o1+0xC]
F00DA2B8: e0226008                 st      %l0, [%o1+8]
F00DA2BC: d2262030                 st      %o1, [%i0+0x30]
F00DA2C0: d2222008                 st      %o1, [%o0+8]
F00DA2C4: d006203c                 ld      [%i0+0x3C], %o0
F00DA2C8: a2046001                 inc     %l1
F00DA2CC: 80a44008                 cmp     %l1, %o0
F00DA2D0: 0abfffe9                 bcs     loc_F00DA274
F00DA2D4: 01000000                 nop
F00DA2D8: 81c7e008                 ret
F00DA2DC: 81e80000                 restore

F0011394: 9de3bf98                 save    %sp, -0x68, %sp
F0011398: 80a6a000                 cmp     %i2, 0
F001139C: 1280000e                 bne     loc_F00113D4
F00113A0: a4102000                 mov     0, %l2
F00113A4: 80a66000                 cmp     %i1, 0
F00113A8: 1280000c                 bne     loc_F00113D8
F00113AC: 113c04d3                 sethi   -0xFECB400, %o0
F00113B0: 113c04cf                 sethi   %hi(_active_u), %o0
F00113B4: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00113B8: d0020000                 ld      [%o0], %o0
F00113BC: f252202e                 ldsh    [%o0+0x2E], %i1
F00113C0: 80a66000                 cmp     %i1, 0
F00113C4: 12800005                 bne     loc_F00113D8
F00113C8: 113c04d3                 sethi   -0xFECB400, %o0
F00113CC: 10800042                 ba      locret_F00114D4
F00113D0: b0102003                 mov     3, %i0
F00113D4: 113c04d3                 sethi   -0xFECB400, %o0
F00113D8: e0022278                 ld      [%o0+0x278], %l0
F00113DC: 80a42000                 cmp     %l0, 0
F00113E0: 02800038                 be      loc_F00114C0
F00113E4: a2102000                 mov     0, %l1
F00113E8: 273c04cf                 sethi   -0xFECC400, %l3
F00113EC: d054202e                 ldsh    [%l0+0x2E], %o0
F00113F0: 80a20019                 cmp     %o0, %i1
F00113F4: 02800004                 be      loc_F0011404
F00113F8: 80a6a000                 cmp     %i2, 0
F00113FC: 2280002e                 be,a    loc_F00114B4
F0011400: e0042008                 ld      [%l0+8], %l0
F0011404: d0542032                 ldsh    [%l0+0x32], %o0
F0011408: 80a22000                 cmp     %o0, 0
F001140C: 2280002a                 be,a    loc_F00114B4
F0011410: e0042008                 ld      [%l0+8], %l0
F0011414: d0042028                 ld      [%l0+0x28], %o0
F0011418: 808a2002                 btst    2, %o0
F001141C: 32800026                 bne,a   loc_F00114B4
F0011420: e0042008                 ld      [%l0+8], %l0
F0011424: 80a6a000                 cmp     %i2, 0
F0011428: 02800006                 be      loc_F0011440
F001142C: d004e1d8                 ld      [%l3+0x1D8], %o0
F0011430: d0020000                 ld      [%o0], %o0
F0011434: 80a40008                 cmp     %l0, %o0
F0011438: 2280001f                 be,a    loc_F00114B4
F001143C: e0042008                 ld      [%l0+8], %l0
F0011440: d004e1d8                 ld      [%l3+0x1D8], %o0
F0011444: d002201c                 ld      [%o0+0x1C], %o0
F0011448: d2522002                 ldsh    [%o0+2], %o1! char *
F001144C: 80a26000                 cmp     %o1, 0
F0011450: 02800013                 be      loc_F001149C
F0011454: 80a62000                 cmp     %i0, 0
F0011458: d054202c                 ldsh    [%l0+0x2C], %o0
F001145C: 80a24008                 cmp     %o1, %o0
F0011460: 0280000e                 be      loc_F0011498
F0011464: 80a62013                 cmp     %i0, 0x13
F0011468: 12800008                 bne     loc_F0011488
F001146C: 80a6a000                 cmp     %i2, 0
F0011470: 7ffff400                 call    _inferior
F0011474: 90100010                 mov     %l0, %o0
F0011478: 80a22000                 cmp     %o0, 0
F001147C: 12800008                 bne     loc_F001149C
F0011480: 80a62000                 cmp     %i0, 0
F0011484: 80a6a000                 cmp     %i2, 0
F0011488: 2280000a                 be,a    loc_F00114B0
F001148C: a4102001                 mov     1, %l2
F0011490: 10800009                 ba      loc_F00114B4
F0011494: e0042008                 ld      [%l0+8], %l0
F0011498: 80a62000                 cmp     %i0, 0
F001149C: 02800005                 be      loc_F00114B0
F00114A0: a2046001                 inc     %l1
F00114A4: 90100010                 mov     %l0, %o0! unsigned int
F00114A8: 40000033                 call    _psignal
F00114AC: 92100018                 mov     %i0, %o1
F00114B0: e0042008                 ld      [%l0+8], %l0
F00114B4: 80a42000                 cmp     %l0, 0
F00114B8: 32bfffce                 bne,a   loc_F00113F0
F00114BC: d054202e                 ldsh    [%l0+0x2E], %o0
F00114C0: b0948000                 orcc    %l2, %g0, %i0
F00114C4: 12800004                 bne     locret_F00114D4
F00114C8: 80a00011                 cmp     %g0, %l1
F00114CC: 90403fff                 addc    %g0, -1, %o0
F00114D0: b00a2003                 and     %o0, 3, %i0
F00114D4: 81c7e008                 ret
F00114D8: 81e80000                 restore

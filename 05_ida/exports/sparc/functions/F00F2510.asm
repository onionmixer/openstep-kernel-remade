F00F2510: 9de3bf98                 save    %sp, -0x68, %sp
F00F2514: 7fffffa0                 call    sub_F00F2394
F00F2518: 90100019                 mov     %i1, %o0
F00F251C: a0100008                 mov     %o0, %l0
F00F2520: 7fffff9d                 call    sub_F00F2394
F00F2524: 9010001a                 mov     %i2, %o0
F00F2528: a2100008                 mov     %o0, %l1
F00F252C: 7fffffd4                 call    __nameForHeader
F00F2530: d0040000                 ld      [%l0], %o0
F00F2534: b4100008                 mov     %o0, %i2
F00F2538: 7fffffd1                 call    __nameForHeader
F00F253C: d0044000                 ld      [%l1], %o0
F00F2540: a0100008                 mov     %o0, %l0
F00F2544: 113c03f4901223a8         set     aBothSAndSHaveI, %o0! "Both %s and %s have implementations of "...
F00F254C: 9210001a                 mov     %i2, %o1! data
F00F2550: 94100010                 mov     %l0, %o2
F00F2554: 7ffff937                 call    __objc_inform
F00F2558: d6066008                 ld      [%i1+8], %o3
F00F255C: d0044000                 ld      [%l1], %o0
F00F2560: d002200c                 ld      [%o0+0xC], %o0
F00F2564: 80a22003                 cmp     %o0, 3
F00F2568: 12800009                 bne     loc_F00F258C
F00F256C: 113c03f4                 sethi   -0xFF03000, %o0
F00F2570: 90100018                 mov     %i0, %o0! table
F00F2574: 7fffecc1                 call    _NXHashInsert
F00F2578: 92100019                 mov     %i1, %o1
F00F257C: 113c03f4901223e0         set     aUsingImplement, %o0! "Using implementation from %s."
F00F2584: 10800004                 ba      loc_F00F2594
F00F2588: 9210001a                 mov     %i2, %o1
F00F258C: 901223e0                 bset    0x3E0, %o0
F00F2590: 92100010                 mov     %l0, %o1
F00F2594: 7ffff927                 call    __objc_inform
F00F2598: 01000000                 nop
F00F259C: 81c7e008                 ret
F00F25A0: 81e80000                 restore

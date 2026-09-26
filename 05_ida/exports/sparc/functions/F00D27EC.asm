F00D27EC: 9de3bf90                 save    %sp, -0x70, %sp
F00D27F0: d0062110                 ld      [%i0+0x110], %o0! id
F00D27F4: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D27F8: 40007c1e                 call    _objc_msgSend
F00D27FC: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D2800: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D2804: 80a22000                 cmp     %o0, 0
F00D2808: 02800032                 be      loc_F00D28D0
F00D280C: b406bf00                 inc     -0x100, %i2
F00D2810: 80a6a000                 cmp     %i2, 0
F00D2814: 26800030                 bl,a    loc_F00D28D4
F00D2818: d0062110                 ld      [%i0+0x110], %o0
F00D281C: d0062188                 ld      [%i0+0x188], %o0
F00D2820: 80a68008                 cmp     %i2, %o0
F00D2824: 06800004                 bl      loc_F00D2834
F00D2828: 113c0505                 sethi   -0xFEBEC00, %o0
F00D282C: 1080002a                 ba      loc_F00D28D4
F00D2830: d0062110                 ld      [%i0+0x110], %o0! id
F00D2834: d202234c                 ld      [%o0+0x34C], %o1! SEL
F00D2838: 40007c0e                 call    _objc_msgSend
F00D283C: 90100018                 mov     %i0, %o0
F00D2840: 912ea002                 sll     %i2, 2, %o0
F00D2844: 9002001a                 add     %o0, %i2, %o0
F00D2848: d2062180                 ld      [%i0+0x180], %o1
F00D284C: 912a2002                 sll     %o0, 2, %o0
F00D2850: c0224008                 clr     [%o1+%o0]
F00D2854: d006218c                 ld      [%i0+0x18C], %o0
F00D2858: 80a2001a                 cmp     %o0, %i2
F00D285C: 3280001a                 bne,a   loc_F00D28C4
F00D2860: 113c0505                 sethi   -0xFEBEC00, %o0
F00D2864: d2062188                 ld      [%i0+0x188], %o1
F00D2868: 92027fff                 inc     -1, %o1
F00D286C: 80a27fff                 cmp     %o1, -1
F00D2870: 0280000d                 be      loc_F00D28A4
F00D2874: 912a6002                 sll     %o1, 2, %o0
F00D2878: d6062180                 ld      [%i0+0x180], %o3
F00D287C: 90020009                 add     %o0, %o1, %o0
F00D2880: 952a2002                 sll     %o0, 2, %o2
F00D2884: d002800b                 ld      [%o2+%o3], %o0
F00D2888: 80a22000                 cmp     %o0, 0
F00D288C: 32800006                 bne,a   loc_F00D28A4
F00D2890: d226218c                 st      %o1, [%i0+0x18C]
F00D2894: 92027fff                 inc     -1, %o1
F00D2898: 80a27fff                 cmp     %o1, -1
F00D289C: 12bffffa                 bne     loc_F00D2884
F00D28A0: 9402bfec                 inc     -0x14, %o2
F00D28A4: 90100018                 mov     %i0, %o0! id
F00D28A8: d4062168                 ld      [%i0+0x168], %o2
F00D28AC: 133c0505                 sethi   %hi(paSetcursorposit), %o1
F00D28B0: d202632c                 ld      [%o1+%lo(paSetcursorposit)], %o1! SEL
F00D28B4: 40007bef                 call    _objc_msgSend
F00D28B8: 9402a018                 inc     0x18, %o2
F00D28BC: 10800006                 ba      loc_F00D28D4
F00D28C0: d0062110                 ld      [%i0+0x110], %o0! id
F00D28C4: d2022310                 ld      [%o0+0x310], %o1! SEL
F00D28C8: 40007bea                 call    _objc_msgSend
F00D28CC: 90100018                 mov     %i0, %o0
F00D28D0: d0062110                 ld      [%i0+0x110], %o0! id
F00D28D4: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D28D8: 40007be6                 call    _objc_msgSend
F00D28DC: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D28E0: 81c7e008                 ret
F00D28E4: 81e80000                 restore

F00D7668: 9de3bf90                 save    %sp, -0x70, %sp
F00D766C: a0102000                 mov     0, %l0
F00D7670: 233c04bb                 sethi   -0xFED1400, %l1
F00D7674: 2d3c0504                 sethi   -0xFEBF000, %l6
F00D7678: 2b3c0504                 sethi   -0xFEBF000, %l5
F00D767C: 293c0505                 sethi   -0xFEBEC00, %l4
F00D7680: 273c0505                 sethi   -0xFEBEC00, %l3
F00D7684: 253c0505                 sethi   -0xFEBEC00, %l2
F00D7688: d004630c                 ld      [%l1+0x30C], %o0! id
F00D768C: 40006879                 call    _objc_msgSend
F00D7690: d205a0b8                 ld      [%l6+0xB8], %o1
F00D7694: 80a40008                 cmp     %l0, %o0
F00D7698: 1a800015                 bcc     loc_F00D76EC
F00D769C: d004630c                 ld      [%l1+0x30C], %o0! id
F00D76A0: d20560c8                 ld      [%l5+0xC8], %o1! SEL
F00D76A4: 40006873                 call    _objc_msgSend
F00D76A8: 94100010                 mov     %l0, %o2
F00D76AC: b0100008                 mov     %o0, %i0
F00D76B0: 40006870                 call    _objc_msgSend
F00D76B4: d2052224                 ld      [%l4+0x224], %o1! SEL
F00D76B8: 4000686e                 call    _objc_msgSend
F00D76BC: d204e220                 ld      [%l3+0x220], %o1
F00D76C0: 80a60008                 cmp     %i0, %o0
F00D76C4: 32bffff1                 bne,a   loc_F00D7688
F00D76C8: a0042001                 inc     %l0
F00D76CC: d204a21c                 ld      [%l2+0x21C], %o1! SEL
F00D76D0: 40006868                 call    _objc_msgSend
F00D76D4: 90100018                 mov     %i0, %o0
F00D76D8: 80a2001a                 cmp     %o0, %i2
F00D76DC: 02800005                 be      locret_F00D76F0
F00D76E0: a0042001                 inc     %l0
F00D76E4: 10bfffea                 ba      loc_F00D768C
F00D76E8: d004630c                 ld      [%l1+0x30C], %o0
F00D76EC: b0102000                 mov     0, %i0
F00D76F0: 81c7e008                 ret
F00D76F4: 81e80000                 restore

F00D76F8: 9de3bf90                 save    %sp, -0x70, %sp
F00D76FC: a0102000                 mov     0, %l0
F00D7700: 233c04bb                 sethi   -0xFED1400, %l1
F00D7704: 2d3c0504                 sethi   -0xFEBF000, %l6
F00D7708: 2b3c0504                 sethi   -0xFEBF000, %l5
F00D770C: 293c0505                 sethi   -0xFEBEC00, %l4
F00D7710: 273c0505                 sethi   -0xFEBEC00, %l3
F00D7714: 253c0505                 sethi   -0xFEBEC00, %l2
F00D7718: d004630c                 ld      [%l1+0x30C], %o0! id
F00D771C: 40006855                 call    _objc_msgSend
F00D7720: d205a0b8                 ld      [%l6+0xB8], %o1
F00D7724: 80a40008                 cmp     %l0, %o0
F00D7728: 1a800015                 bcc     loc_F00D777C
F00D772C: d004630c                 ld      [%l1+0x30C], %o0! id
F00D7730: d20560c8                 ld      [%l5+0xC8], %o1! SEL
F00D7734: 4000684f                 call    _objc_msgSend
F00D7738: 94100010                 mov     %l0, %o2
F00D773C: b0100008                 mov     %o0, %i0
F00D7740: 4000684c                 call    _objc_msgSend
F00D7744: d2052224                 ld      [%l4+0x224], %o1! SEL
F00D7748: 4000684a                 call    _objc_msgSend
F00D774C: d204e218                 ld      [%l3+0x218], %o1
F00D7750: 80a60008                 cmp     %i0, %o0
F00D7754: 32bffff1                 bne,a   loc_F00D7718
F00D7758: a0042001                 inc     %l0
F00D775C: d204a21c                 ld      [%l2+0x21C], %o1! SEL
F00D7760: 40006844                 call    _objc_msgSend
F00D7764: 90100018                 mov     %i0, %o0
F00D7768: 80a2001a                 cmp     %o0, %i2
F00D776C: 02800005                 be      locret_F00D7780
F00D7770: a0042001                 inc     %l0
F00D7774: 10bfffea                 ba      loc_F00D771C
F00D7778: d004630c                 ld      [%l1+0x30C], %o0
F00D777C: b0102000                 mov     0, %i0
F00D7780: 81c7e008                 ret
F00D7784: 81e80000                 restore

F00DA794: 9de3bf90                 save    %sp, -0x70, %sp
F00DA798: a2102000                 mov     0, %l1
F00DA79C: 2b3c0504                 sethi   -0xFEBF000, %l5
F00DA7A0: 293c0504                 sethi   -0xFEBF000, %l4
F00DA7A4: 253c0505                 sethi   -0xFEBEC00, %l2
F00DA7A8: 273c0505                 sethi   -0xFEBEC00, %l3
F00DA7AC: d006200c                 ld      [%i0+0xC], %o0! id
F00DA7B0: 40005c30                 call    _objc_msgSend
F00DA7B4: d20560b8                 ld      [%l5+0xB8], %o1
F00DA7B8: 80a44008                 cmp     %l1, %o0
F00DA7BC: 1a800010                 bcc     loc_F00DA7FC
F00DA7C0: d20520c8                 ld      [%l4+0xC8], %o1! SEL
F00DA7C4: d006200c                 ld      [%i0+0xC], %o0! id
F00DA7C8: 40005c2a                 call    _objc_msgSend
F00DA7CC: 94100011                 mov     %l1, %o2
F00DA7D0: a0100008                 mov     %o0, %l0
F00DA7D4: 40005c27                 call    _objc_msgSend
F00DA7D8: d204a0b0                 ld      [%l2+0xB0], %o1
F00DA7DC: 80a2001a                 cmp     %o0, %i2
F00DA7E0: 12bffff3                 bne     loc_F00DA7AC
F00DA7E4: a2046001                 inc     %l1
F00DA7E8: d204e0b4                 ld      [%l3+0xB4], %o1! SEL
F00DA7EC: 40005c21                 call    _objc_msgSend
F00DA7F0: 90100010                 mov     %l0, %o0
F00DA7F4: 10800003                 ba      locret_F00DA800
F00DA7F8: b0100008                 mov     %o0, %i0
F00DA7FC: b0102000                 mov     0, %i0
F00DA800: 81c7e008                 ret
F00DA804: 81e80000                 restore

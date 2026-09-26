F00DECFC: 9de3bf98                 save    %sp, -0x68, %sp
F00DED00: 80a62000                 cmp     %i0, 0
F00DED04: 02800024                 be      locret_F00DED94
F00DED08: 2d3c0506                 sethi   %hi(paIoaudio), %l6
F00DED0C: 2b3c0504                 sethi   -0xFEBF000, %l5
F00DED10: 293c0505                 sethi   -0xFEBEC00, %l4
F00DED14: 273c0506                 sethi   -0xFEBE800, %l3
F00DED18: 253c0504                 sethi   -0xFEBF000, %l2
F00DED1C: d005a2d4                 ld      [%l6+%lo(paIoaudio)], %o0! id
F00DED20: a2102000                 mov     0, %l1
F00DED24: d20563f0                 ld      [%l5+0x3F0], %o1! SEL
F00DED28: 40004ad2                 call    _objc_msgSend
F00DED2C: 94100018                 mov     %i0, %o2
F00DED30: 80a22000                 cmp     %o0, 0
F00DED34: 02800005                 be      loc_F00DED48
F00DED38: d205201c                 ld      [%l4+0x1C], %o1
F00DED3C: 94102000                 mov     0, %o2
F00DED40: 10800010                 ba      loc_F00DED80
F00DED44: a2102001                 mov     1, %l1
F00DED48: d004e2d0                 ld      [%l3+0x2D0], %o0! id
F00DED4C: d204a3ec                 ld      [%l2+0x3EC], %o1! SEL
F00DED50: 40004ac8                 call    _objc_msgSend
F00DED54: 94100018                 mov     %i0, %o2
F00DED58: a0920000                 orcc    %o0, %g0, %l0
F00DED5C: 0280000c                 be      loc_F00DED8C
F00DED60: 80a46000                 cmp     %l1, 0
F00DED64: 133c0505                 sethi   %hi(paChannel), %o1
F00DED68: d2026058                 ld      [%o1+%lo(paChannel)], %o1! SEL
F00DED6C: 40004ac1                 call    _objc_msgSend
F00DED70: a2102001                 mov     1, %l1
F00DED74: 133c0505                 sethi   %hi(paRemovestream), %o1
F00DED78: d2026094                 ld      [%o1+%lo(paRemovestream)], %o1! SEL
F00DED7C: 94100010                 mov     %l0, %o2
F00DED80: 40004abc                 call    _objc_msgSend
F00DED84: 01000000                 nop
F00DED88: 80a46000                 cmp     %l1, 0
F00DED8C: 12bfffe5                 bne     loc_F00DED20
F00DED90: d005a2d4                 ld      [%l6+0x2D4], %o0
F00DED94: 81c7e008                 ret
F00DED98: 81e80000                 restore

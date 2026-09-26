F0029B40: 9de3bf98                 save    %sp, -0x68, %sp
F0029B44: 4001b454                 call    _splnet
F0029B48: 01000000                 nop
F0029B4C: 133c04d0                 sethi   %hi(_ifnet), %o1
F0029B50: e00260b8                 ld      [%o1+%lo(_ifnet)], %l0
F0029B54: 80a42000                 cmp     %l0, 0
F0029B58: 02800008                 be      loc_F0029B78
F0029B5C: a2100008                 mov     %o0, %l1
F0029B60: 7fffffd9                 call    _if_down
F0029B64: 90100010                 mov     %l0, %o0
F0029B68: e004205c                 ld      [%l0+0x5C], %l0
F0029B6C: 80a42000                 cmp     %l0, 0
F0029B70: 12bffffc                 bne     loc_F0029B60
F0029B74: 01000000                 nop
F0029B78: 4001b46b                 call    _splx
F0029B7C: 90100011                 mov     %l1, %o0
F0029B80: 81c7e008                 ret
F0029B84: 81e80000                 restore

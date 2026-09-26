F00A3B6C: 9de3bf98                 save    %sp, -0x68, %sp
F00A3B70: d04e0000                 ldsb    [%i0], %o0
F00A3B74: 80a2203d                 cmp     %o0, 0x3D ! '='
F00A3B78: 12800051                 bne     loc_F00A3CBC
F00A3B7C: a6102001                 mov     1, %l3
F00A3B80: b0062001                 inc     %i0
F00A3B84: d04e0000                 ldsb    [%i0], %o0
F00A3B88: 80a2202d                 cmp     %o0, 0x2D ! '-'
F00A3B8C: 12800005                 bne     loc_F00A3BA0
F00A3B90: a410200a                 mov     0xA, %l2
F00A3B94: a6103fff                 mov     -1, %l3
F00A3B98: b0062001                 inc     %i0
F00A3B9C: d04e0000                 ldsb    [%i0], %o0
F00A3BA0: a2823fd0                 addcc   %o0, -0x30, %l1
F00A3BA4: 1280001b                 bne     loc_F00A3C10
F00A3BA8: b0062001                 inc     %i0
F00A3BAC: d04e0000                 ldsb    [%i0], %o0
F00A3BB0: 80a22030                 cmp     %o0, 0x30 ! '0'
F00A3BB4: 06800012                 bl      loc_F00A3BFC
F00A3BB8: 80a22037                 cmp     %o0, 0x37 ! '7'
F00A3BBC: 0480000c                 ble     loc_F00A3BEC
F00A3BC0: 80a22062                 cmp     %o0, 0x62 ! 'b'
F00A3BC4: 02800007                 be      loc_F00A3BE0
F00A3BC8: 80a22078                 cmp     %o0, 0x78 ! 'x'
F00A3BCC: 1280000c                 bne     loc_F00A3BFC
F00A3BD0: 01000000                 nop
F00A3BD4: a4102010                 mov     0x10, %l2
F00A3BD8: 1080000e                 ba      loc_F00A3C10
F00A3BDC: b0062001                 inc     %i0
F00A3BE0: a4102002                 mov     2, %l2
F00A3BE4: 1080000b                 ba      loc_F00A3C10
F00A3BE8: b0062001                 inc     %i0
F00A3BEC: a2023fd0                 add     %o0, -0x30, %l1
F00A3BF0: b0062001                 inc     %i0
F00A3BF4: 10800007                 ba      loc_F00A3C10
F00A3BF8: a4102008                 mov     8, %l2
F00A3BFC: 7fffffbe                 call    _isargsep
F00A3C00: d04e0000                 ldsb    [%i0], %o0
F00A3C04: 80a22000                 cmp     %o0, 0
F00A3C08: 2280002f                 be,a    locret_F00A3CC4
F00A3C0C: b0102001                 mov     1, %i0
F00A3C10: d20e0000                 ldub    [%i0], %o1
F00A3C14: 900a60ff                 and     %o1, 0xFF, %o0
F00A3C18: 80a2202f                 cmp     %o0, 0x2F ! '/'
F00A3C1C: 08800007                 bleu    loc_F00A3C38
F00A3C20: b0062001                 inc     %i0
F00A3C24: 80a22039                 cmp     %o0, 0x39 ! '9'
F00A3C28: 18800005                 bgu     loc_F00A3C3C
F00A3C2C: 90027f9f                 add     %o1, -0x61, %o0
F00A3C30: 10800014                 ba      loc_F00A3C80
F00A3C34: 92027fd0                 inc     -0x30, %o1
F00A3C38: 90027f9f                 add     %o1, -0x61, %o0
F00A3C3C: 900a20ff                 and     %o0, 0xFF, %o0
F00A3C40: 80a22005                 cmp     %o0, 5
F00A3C44: 18800004                 bgu     loc_F00A3C54
F00A3C48: 90027fbf                 add     %o1, -0x41, %o0
F00A3C4C: 1080000d                 ba      loc_F00A3C80
F00A3C50: 92027fa9                 inc     -0x57, %o1
F00A3C54: 900a20ff                 and     %o0, 0xFF, %o0
F00A3C58: 80a22005                 cmp     %o0, 5
F00A3C5C: 28800009                 bleu,a  loc_F00A3C80
F00A3C60: 92027fc9                 inc     -0x37, %o1
F00A3C64: 7fffffa4                 call    _isargsep
F00A3C68: 900a60ff                 and     %o1, 0xFF, %o0
F00A3C6C: 80a22000                 cmp     %o0, 0
F00A3C70: 1280000d                 bne     loc_F00A3CA4
F00A3C74: 90100011                 mov     %l1, %o0
F00A3C78: 10800013                 ba      locret_F00A3CC4
F00A3C7C: b0102001                 mov     1, %i0
F00A3C80: a00a60ff                 and     %o1, 0xFF, %l0
F00A3C84: 80a40012                 cmp     %l0, %l2
F00A3C88: 1a80000b                 bcc     loc_F00A3CB4
F00A3C8C: 90100011                 mov     %l1, %o0
F00A3C90: 7ffd8a1c                 call    _umul
F00A3C94: 92100012                 mov     %l2, %o1
F00A3C98: a2100008                 mov     %o0, %l1
F00A3C9C: 10bfffdd                 ba      loc_F00A3C10
F00A3CA0: a2044010                 add     %l1, %l0, %l1
F00A3CA4: 7ffd8a17                 call    _umul
F00A3CA8: 92100013                 mov     %l3, %o1
F00A3CAC: 10800005                 ba      loc_F00A3CC0
F00A3CB0: d0264000                 st      %o0, [%i1]
F00A3CB4: 10800004                 ba      locret_F00A3CC4
F00A3CB8: b0102001                 mov     1, %i0
F00A3CBC: e6264000                 st      %l3, [%i1]
F00A3CC0: b0102000                 mov     0, %i0
F00A3CC4: 81c7e008                 ret
F00A3CC8: 81e80000                 restore

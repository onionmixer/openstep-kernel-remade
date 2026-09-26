F00E2B28: 9de3bf98                 save    %sp, -0x68, %sp
F00E2B2C: ac100018                 mov     %i0, %l6
F00E2B30: a2100016                 mov     %l6, %l1
F00E2B34: aa102000                 mov     0, %l5
F00E2B38: e04c4000                 ldsb    [%l1], %l0
F00E2B3C: 94102000                 mov     0, %o2
F00E2B40: 92100010                 mov     %l0, %o1
F00E2B44: 80a26020                 cmp     %o1, 0x20 ! ' '
F00E2B48: 02800009                 be      loc_F00E2B6C
F00E2B4C: a2046001                 inc     %l1
F00E2B50: 90043ff7                 add     %l0, -9, %o0
F00E2B54: 900a20ff                 and     %o0, 0xFF, %o0
F00E2B58: 80a22001                 cmp     %o0, 1
F00E2B5C: 08800004                 bleu    loc_F00E2B6C
F00E2B60: 80a2600a                 cmp     %o1, 0xA
F00E2B64: 12800004                 bne     loc_F00E2B74
F00E2B68: 80a2a000                 cmp     %o2, 0
F00E2B6C: 94102001                 mov     1, %o2
F00E2B70: 80a2a000                 cmp     %o2, 0
F00E2B74: 32bffff2                 bne,a   loc_F00E2B3C
F00E2B78: e04c4000                 ldsb    [%l1], %l0
F00E2B7C: 80a4202d                 cmp     %l0, 0x2D ! '-'
F00E2B80: 12800005                 bne     loc_F00E2B94
F00E2B84: 80a4202b                 cmp     %l0, 0x2B ! '+'
F00E2B88: e04c4000                 ldsb    [%l1], %l0
F00E2B8C: 10800005                 ba      loc_F00E2BA0
F00E2B90: aa102001                 mov     1, %l5
F00E2B94: 12800005                 bne     loc_F00E2BA8
F00E2B98: 80a6a000                 cmp     %i2, 0
F00E2B9C: e04c4000                 ldsb    [%l1], %l0
F00E2BA0: a2046001                 inc     %l1
F00E2BA4: 80a6a000                 cmp     %i2, 0
F00E2BA8: 02800004                 be      loc_F00E2BB8
F00E2BAC: 80a6a010                 cmp     %i2, 0x10
F00E2BB0: 1280000e                 bne     loc_F00E2BE8
F00E2BB4: 80a6a000                 cmp     %i2, 0
F00E2BB8: 80a42030                 cmp     %l0, 0x30 ! '0'
F00E2BBC: 1280000b                 bne     loc_F00E2BE8
F00E2BC0: 80a6a000                 cmp     %i2, 0
F00E2BC4: d04c4000                 ldsb    [%l1], %o0
F00E2BC8: 80a22078                 cmp     %o0, 0x78 ! 'x'
F00E2BCC: 02800004                 be      loc_F00E2BDC
F00E2BD0: 80a22058                 cmp     %o0, 0x58 ! 'X'
F00E2BD4: 12800005                 bne     loc_F00E2BE8
F00E2BD8: 80a6a000                 cmp     %i2, 0
F00E2BDC: e04c6001                 ldsb    [%l1+1], %l0
F00E2BE0: 10800011                 ba      loc_F00E2C24
F00E2BE4: b4102010                 mov     0x10, %i2
F00E2BE8: 02800004                 be      loc_F00E2BF8
F00E2BEC: 80a6a002                 cmp     %i2, 2
F00E2BF0: 1280000f                 bne     loc_F00E2C2C
F00E2BF4: 80a6a000                 cmp     %i2, 0
F00E2BF8: 80a42030                 cmp     %l0, 0x30 ! '0'
F00E2BFC: 1280000c                 bne     loc_F00E2C2C
F00E2C00: 80a6a000                 cmp     %i2, 0
F00E2C04: d04c4000                 ldsb    [%l1], %o0
F00E2C08: 80a22062                 cmp     %o0, 0x62 ! 'b'
F00E2C0C: 02800004                 be      loc_F00E2C1C
F00E2C10: 80a22042                 cmp     %o0, 0x42 ! 'B'
F00E2C14: 12800006                 bne     loc_F00E2C2C
F00E2C18: 80a6a000                 cmp     %i2, 0
F00E2C1C: e04c6001                 ldsb    [%l1+1], %l0
F00E2C20: b4102002                 mov     2, %i2
F00E2C24: a2046002                 inc     2, %l1
F00E2C28: 80a6a000                 cmp     %i2, 0
F00E2C2C: 32800007                 bne,a   loc_F00E2C48
F00E2C30: 90103fff                 mov     -1, %o0
F00E2C34: 80a42030                 cmp     %l0, 0x30 ! '0'
F00E2C38: 12800003                 bne     loc_F00E2C44
F00E2C3C: b410200a                 mov     0xA, %i2
F00E2C40: b4102008                 mov     8, %i2
F00E2C44: 90103fff                 mov     -1, %o0
F00E2C48: 7ffc8e6e                 call    _udiv
F00E2C4C: 9210001a                 mov     %i2, %o1
F00E2C50: a6100008                 mov     %o0, %l3
F00E2C54: 90103fff                 mov     -1, %o0
F00E2C58: 7ffc8f12                 call    _urem
F00E2C5C: 9210001a                 mov     %i2, %o1
F00E2C60: a8100008                 mov     %o0, %l4
F00E2C64: b0102000                 mov     0, %i0
F00E2C68: a4102000                 mov     0, %l2
F00E2C6C: 92043fd0                 add     %l0, -0x30, %o1
F00E2C70: 900a60ff                 and     %o1, 0xFF, %o0
F00E2C74: 80a22009                 cmp     %o0, 9
F00E2C78: 18800004                 bgu     loc_F00E2C88
F00E2C7C: 90043fbf                 add     %l0, -0x41, %o0
F00E2C80: 10800015                 ba      loc_F00E2CD4
F00E2C84: a0100009                 mov     %o1, %l0
F00E2C88: 900a20ff                 and     %o0, 0xFF, %o0
F00E2C8C: 80a22019                 cmp     %o0, 0x19
F00E2C90: 08800007                 bleu    loc_F00E2CAC
F00E2C94: 92102000                 mov     0, %o1
F00E2C98: 90043f9f                 add     %l0, -0x61, %o0
F00E2C9C: 900a20ff                 and     %o0, 0xFF, %o0
F00E2CA0: 80a22019                 cmp     %o0, 0x19
F00E2CA4: 18800004                 bgu     loc_F00E2CB4
F00E2CA8: 80a26000                 cmp     %o1, 0
F00E2CAC: 92102001                 mov     1, %o1
F00E2CB0: 80a26000                 cmp     %o1, 0
F00E2CB4: 0280001e                 be      loc_F00E2D2C
F00E2CB8: 90043fbf                 add     %l0, -0x41, %o0
F00E2CBC: 900a20ff                 and     %o0, 0xFF, %o0
F00E2CC0: 80a22019                 cmp     %o0, 0x19
F00E2CC4: 08800003                 bleu    loc_F00E2CD0
F00E2CC8: 90043fc9                 add     %l0, -0x37, %o0
F00E2CCC: 90043fa9                 add     %l0, -0x57, %o0
F00E2CD0: a0100008                 mov     %o0, %l0
F00E2CD4: 80a4001a                 cmp     %l0, %i2
F00E2CD8: 16800015                 bge     loc_F00E2D2C
F00E2CDC: 80a4a000                 cmp     %l2, 0
F00E2CE0: 06800009                 bl      loc_F00E2D04
F00E2CE4: 80a60013                 cmp     %i0, %l3
F00E2CE8: 3880000e                 bgu,a   loc_F00E2D20
F00E2CEC: a4103fff                 mov     -1, %l2
F00E2CF0: 12800007                 bne     loc_F00E2D0C
F00E2CF4: a4102001                 mov     1, %l2
F00E2CF8: 80a40014                 cmp     %l0, %l4
F00E2CFC: 04800005                 ble     loc_F00E2D10
F00E2D00: 90100018                 mov     %i0, %o0
F00E2D04: 10800007                 ba      loc_F00E2D20
F00E2D08: a4103fff                 mov     -1, %l2
F00E2D0C: 90100018                 mov     %i0, %o0
F00E2D10: 7ffc8dfc                 call    _umul
F00E2D14: 9210001a                 mov     %i2, %o1
F00E2D18: b0100008                 mov     %o0, %i0
F00E2D1C: b0060010                 add     %i0, %l0, %i0
F00E2D20: e04c4000                 ldsb    [%l1], %l0
F00E2D24: 10bfffd2                 ba      loc_F00E2C6C
F00E2D28: a2046001                 inc     %l1
F00E2D2C: 80a4a000                 cmp     %l2, 0
F00E2D30: 16800004                 bge     loc_F00E2D40
F00E2D34: 80a56000                 cmp     %l5, 0
F00E2D38: 10800004                 ba      loc_F00E2D48
F00E2D3C: b0103fff                 mov     -1, %i0
F00E2D40: 32800002                 bne,a   loc_F00E2D48
F00E2D44: b0200018                 neg     %i0
F00E2D48: 80a66000                 cmp     %i1, 0
F00E2D4C: 02800006                 be      locret_F00E2D64
F00E2D50: 80a4a000                 cmp     %l2, 0
F00E2D54: 02800003                 be      loc_F00E2D60
F00E2D58: 90100016                 mov     %l6, %o0
F00E2D5C: 90047fff                 add     %l1, -1, %o0
F00E2D60: d0264000                 st      %o0, [%i1]
F00E2D64: 81c7e008                 ret
F00E2D68: 81e80000                 restore

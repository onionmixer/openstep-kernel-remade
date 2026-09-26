F008FA58: 9de3bf98                 save    %sp, -0x68, %sp
F008FA5C: a2100018                 mov     %i0, %l1
F008FA60: ac102000                 mov     0, %l6
F008FA64: a6102000                 mov     0, %l3
F008FA68: e04c4000                 ldsb    [%l1], %l0
F008FA6C: 94102000                 mov     0, %o2
F008FA70: 92100010                 mov     %l0, %o1
F008FA74: 80a26020                 cmp     %o1, 0x20 ! ' '
F008FA78: 02800009                 be      loc_F008FA9C
F008FA7C: a2046001                 inc     %l1
F008FA80: 90043ff7                 add     %l0, -9, %o0
F008FA84: 900a20ff                 and     %o0, 0xFF, %o0
F008FA88: 80a22001                 cmp     %o0, 1
F008FA8C: 08800004                 bleu    loc_F008FA9C
F008FA90: 80a2600a                 cmp     %o1, 0xA
F008FA94: 12800004                 bne     loc_F008FAA4
F008FA98: 80a2a000                 cmp     %o2, 0
F008FA9C: 94102001                 mov     1, %o2
F008FAA0: 80a2a000                 cmp     %o2, 0
F008FAA4: 32bffff2                 bne,a   loc_F008FA6C
F008FAA8: e04c4000                 ldsb    [%l1], %l0
F008FAAC: 80a4202d                 cmp     %l0, 0x2D ! '-'
F008FAB0: 12800005                 bne     loc_F008FAC4
F008FAB4: 80a4202b                 cmp     %l0, 0x2B ! '+'
F008FAB8: e04c4000                 ldsb    [%l1], %l0
F008FABC: 10800005                 ba      loc_F008FAD0
F008FAC0: ac102001                 mov     1, %l6
F008FAC4: 12800005                 bne     loc_F008FAD8
F008FAC8: 80a42030                 cmp     %l0, 0x30 ! '0'
F008FACC: e04c4000                 ldsb    [%l1], %l0
F008FAD0: a2046001                 inc     %l1
F008FAD4: 80a42030                 cmp     %l0, 0x30 ! '0'
F008FAD8: 1280000c                 bne     loc_F008FB08
F008FADC: 80a4e000                 cmp     %l3, 0
F008FAE0: d04c4000                 ldsb    [%l1], %o0
F008FAE4: 80a22078                 cmp     %o0, 0x78 ! 'x'
F008FAE8: 02800004                 be      loc_F008FAF8
F008FAEC: 80a22058                 cmp     %o0, 0x58 ! 'X'
F008FAF0: 12800006                 bne     loc_F008FB08
F008FAF4: 80a4e000                 cmp     %l3, 0
F008FAF8: e04c6001                 ldsb    [%l1+1], %l0
F008FAFC: a6102010                 mov     0x10, %l3
F008FB00: a2046002                 inc     2, %l1
F008FB04: 80a4e000                 cmp     %l3, 0
F008FB08: 32800007                 bne,a   loc_F008FB24
F008FB0C: 90103fff                 mov     -1, %o0
F008FB10: 80a42030                 cmp     %l0, 0x30 ! '0'
F008FB14: 12800003                 bne     loc_F008FB20
F008FB18: a610200a                 mov     0xA, %l3
F008FB1C: a6102008                 mov     8, %l3
F008FB20: 90103fff                 mov     -1, %o0
F008FB24: 7ffddab7                 call    _udiv
F008FB28: 92100013                 mov     %l3, %o1
F008FB2C: a8100008                 mov     %o0, %l4
F008FB30: 90103fff                 mov     -1, %o0
F008FB34: 7ffddb5b                 call    _urem
F008FB38: 92100013                 mov     %l3, %o1
F008FB3C: aa100008                 mov     %o0, %l5
F008FB40: 94102000                 mov     0, %o2
F008FB44: a4102000                 mov     0, %l2
F008FB48: 92043fd0                 add     %l0, -0x30, %o1
F008FB4C: 900a60ff                 and     %o1, 0xFF, %o0
F008FB50: 80a22009                 cmp     %o0, 9
F008FB54: 18800004                 bgu     loc_F008FB64
F008FB58: 90043fbf                 add     %l0, -0x41, %o0
F008FB5C: 10800015                 ba      loc_F008FBB0
F008FB60: a0100009                 mov     %o1, %l0
F008FB64: 900a20ff                 and     %o0, 0xFF, %o0
F008FB68: 80a22019                 cmp     %o0, 0x19
F008FB6C: 08800007                 bleu    loc_F008FB88
F008FB70: 92102000                 mov     0, %o1
F008FB74: 90043f9f                 add     %l0, -0x61, %o0
F008FB78: 900a20ff                 and     %o0, 0xFF, %o0
F008FB7C: 80a22019                 cmp     %o0, 0x19
F008FB80: 18800004                 bgu     loc_F008FB90
F008FB84: 80a26000                 cmp     %o1, 0
F008FB88: 92102001                 mov     1, %o1
F008FB8C: 80a26000                 cmp     %o1, 0
F008FB90: 0280001e                 be      loc_F008FC08
F008FB94: 90043fbf                 add     %l0, -0x41, %o0
F008FB98: 900a20ff                 and     %o0, 0xFF, %o0
F008FB9C: 80a22019                 cmp     %o0, 0x19
F008FBA0: 08800003                 bleu    loc_F008FBAC
F008FBA4: 90043fc9                 add     %l0, -0x37, %o0
F008FBA8: 90043fa9                 add     %l0, -0x57, %o0
F008FBAC: a0100008                 mov     %o0, %l0
F008FBB0: 80a40013                 cmp     %l0, %l3
F008FBB4: 16800015                 bge     loc_F008FC08
F008FBB8: 80a4a000                 cmp     %l2, 0
F008FBBC: 06800009                 bl      loc_F008FBE0
F008FBC0: 80a28014                 cmp     %o2, %l4
F008FBC4: 3880000e                 bgu,a   loc_F008FBFC
F008FBC8: a4103fff                 mov     -1, %l2
F008FBCC: 12800007                 bne     loc_F008FBE8
F008FBD0: a4102001                 mov     1, %l2
F008FBD4: 80a40015                 cmp     %l0, %l5
F008FBD8: 04800005                 ble     loc_F008FBEC
F008FBDC: 9010000a                 mov     %o2, %o0
F008FBE0: 10800007                 ba      loc_F008FBFC
F008FBE4: a4103fff                 mov     -1, %l2
F008FBE8: 9010000a                 mov     %o2, %o0
F008FBEC: 7ffdda45                 call    _umul
F008FBF0: 92100013                 mov     %l3, %o1
F008FBF4: 94100008                 mov     %o0, %o2
F008FBF8: 94028010                 add     %o2, %l0, %o2
F008FBFC: e04c4000                 ldsb    [%l1], %l0
F008FC00: 10bfffd2                 ba      loc_F008FB48
F008FC04: a2046001                 inc     %l1
F008FC08: 80a4a000                 cmp     %l2, 0
F008FC0C: 16800004                 bge     loc_F008FC1C
F008FC10: 80a5a000                 cmp     %l6, 0
F008FC14: 10800004                 ba      loc_F008FC24
F008FC18: 94103fff                 mov     -1, %o2
F008FC1C: 32800002                 bne,a   loc_F008FC24
F008FC20: 9420000a                 neg     %o2
F008FC24: 80a66000                 cmp     %i1, 0
F008FC28: 02800005                 be      loc_F008FC3C
F008FC2C: 80a4a000                 cmp     %l2, 0
F008FC30: 32800002                 bne,a   loc_F008FC38
F008FC34: b0047fff                 add     %l1, -1, %i0
F008FC38: f0264000                 st      %i0, [%i1]
F008FC3C: 80a6a000                 cmp     %i2, 0
F008FC40: 32800002                 bne,a   loc_F008FC48
F008FC44: d4268000                 st      %o2, [%i2]
F008FC48: 80a4a000                 cmp     %l2, 0
F008FC4C: 34800003                 bg,a    locret_F008FC58
F008FC50: b0102001                 mov     1, %i0
F008FC54: b0102000                 mov     0, %i0
F008FC58: 81c7e008                 ret
F008FC5C: 81e80000                 restore

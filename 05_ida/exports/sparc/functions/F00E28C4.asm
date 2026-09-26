F00E28C4: 9de3bf98                 save    %sp, -0x68, %sp
F00E28C8: ac100018                 mov     %i0, %l6
F00E28CC: a2100016                 mov     %l6, %l1
F00E28D0: a8102000                 mov     0, %l4
F00E28D4: e04c4000                 ldsb    [%l1], %l0
F00E28D8: 94102000                 mov     0, %o2
F00E28DC: 92100010                 mov     %l0, %o1
F00E28E0: 80a26020                 cmp     %o1, 0x20 ! ' '
F00E28E4: 02800009                 be      loc_F00E2908
F00E28E8: a2046001                 inc     %l1
F00E28EC: 90043ff7                 add     %l0, -9, %o0
F00E28F0: 900a20ff                 and     %o0, 0xFF, %o0
F00E28F4: 80a22001                 cmp     %o0, 1
F00E28F8: 08800004                 bleu    loc_F00E2908
F00E28FC: 80a2600a                 cmp     %o1, 0xA
F00E2900: 12800004                 bne     loc_F00E2910
F00E2904: 80a2a000                 cmp     %o2, 0
F00E2908: 94102001                 mov     1, %o2
F00E290C: 80a2a000                 cmp     %o2, 0
F00E2910: 32bffff2                 bne,a   loc_F00E28D8
F00E2914: e04c4000                 ldsb    [%l1], %l0
F00E2918: 80a4202d                 cmp     %l0, 0x2D ! '-'
F00E291C: 12800005                 bne     loc_F00E2930
F00E2920: 80a4202b                 cmp     %l0, 0x2B ! '+'
F00E2924: e04c4000                 ldsb    [%l1], %l0
F00E2928: 10800005                 ba      loc_F00E293C
F00E292C: a8102001                 mov     1, %l4
F00E2930: 12800005                 bne     loc_F00E2944
F00E2934: 80a6a000                 cmp     %i2, 0
F00E2938: e04c4000                 ldsb    [%l1], %l0
F00E293C: a2046001                 inc     %l1
F00E2940: 80a6a000                 cmp     %i2, 0
F00E2944: 02800004                 be      loc_F00E2954
F00E2948: 80a6a010                 cmp     %i2, 0x10
F00E294C: 1280000e                 bne     loc_F00E2984
F00E2950: 80a6a000                 cmp     %i2, 0
F00E2954: 80a42030                 cmp     %l0, 0x30 ! '0'
F00E2958: 1280000b                 bne     loc_F00E2984
F00E295C: 80a6a000                 cmp     %i2, 0
F00E2960: d04c4000                 ldsb    [%l1], %o0
F00E2964: 80a22078                 cmp     %o0, 0x78 ! 'x'
F00E2968: 02800004                 be      loc_F00E2978
F00E296C: 80a22058                 cmp     %o0, 0x58 ! 'X'
F00E2970: 12800005                 bne     loc_F00E2984
F00E2974: 80a6a000                 cmp     %i2, 0
F00E2978: e04c6001                 ldsb    [%l1+1], %l0
F00E297C: 10800011                 ba      loc_F00E29C0
F00E2980: b4102010                 mov     0x10, %i2
F00E2984: 02800004                 be      loc_F00E2994
F00E2988: 80a6a002                 cmp     %i2, 2
F00E298C: 1280000f                 bne     loc_F00E29C8
F00E2990: 80a6a000                 cmp     %i2, 0
F00E2994: 80a42030                 cmp     %l0, 0x30 ! '0'
F00E2998: 1280000c                 bne     loc_F00E29C8
F00E299C: 80a6a000                 cmp     %i2, 0
F00E29A0: d04c4000                 ldsb    [%l1], %o0
F00E29A4: 80a22062                 cmp     %o0, 0x62 ! 'b'
F00E29A8: 02800004                 be      loc_F00E29B8
F00E29AC: 80a22042                 cmp     %o0, 0x42 ! 'B'
F00E29B0: 12800006                 bne     loc_F00E29C8
F00E29B4: 80a6a000                 cmp     %i2, 0
F00E29B8: e04c6001                 ldsb    [%l1+1], %l0
F00E29BC: b4102002                 mov     2, %i2
F00E29C0: a2046002                 inc     2, %l1
F00E29C4: 80a6a000                 cmp     %i2, 0
F00E29C8: 12800007                 bne     loc_F00E29E4
F00E29CC: 80a52000                 cmp     %l4, 0
F00E29D0: 80a42030                 cmp     %l0, 0x30 ! '0'
F00E29D4: 12800003                 bne     loc_F00E29E0
F00E29D8: b410200a                 mov     0xA, %i2
F00E29DC: b4102008                 mov     8, %i2
F00E29E0: 80a52000                 cmp     %l4, 0
F00E29E4: 12800004                 bne     loc_F00E29F4
F00E29E8: 27200000                 sethi   0x80000000, %l3
F00E29EC: 111fffffa61223ff         set     0x7FFFFFFF, %l3
F00E29F4: 90100013                 mov     %l3, %o0
F00E29F8: 7ffc8faa                 call    _urem
F00E29FC: 9210001a                 mov     %i2, %o1
F00E2A00: aa100008                 mov     %o0, %l5
F00E2A04: 90100013                 mov     %l3, %o0
F00E2A08: 7ffc8efe                 call    _udiv
F00E2A0C: 9210001a                 mov     %i2, %o1
F00E2A10: a6100008                 mov     %o0, %l3
F00E2A14: b0102000                 mov     0, %i0
F00E2A18: a4102000                 mov     0, %l2
F00E2A1C: 92043fd0                 add     %l0, -0x30, %o1
F00E2A20: 900a60ff                 and     %o1, 0xFF, %o0
F00E2A24: 80a22009                 cmp     %o0, 9
F00E2A28: 18800004                 bgu     loc_F00E2A38
F00E2A2C: 90043fbf                 add     %l0, -0x41, %o0
F00E2A30: 10800015                 ba      loc_F00E2A84
F00E2A34: a0100009                 mov     %o1, %l0
F00E2A38: 900a20ff                 and     %o0, 0xFF, %o0
F00E2A3C: 80a22019                 cmp     %o0, 0x19
F00E2A40: 08800007                 bleu    loc_F00E2A5C
F00E2A44: 92102000                 mov     0, %o1
F00E2A48: 90043f9f                 add     %l0, -0x61, %o0
F00E2A4C: 900a20ff                 and     %o0, 0xFF, %o0
F00E2A50: 80a22019                 cmp     %o0, 0x19
F00E2A54: 18800004                 bgu     loc_F00E2A64
F00E2A58: 80a26000                 cmp     %o1, 0
F00E2A5C: 92102001                 mov     1, %o1
F00E2A60: 80a26000                 cmp     %o1, 0
F00E2A64: 0280001e                 be      loc_F00E2ADC
F00E2A68: 90043fbf                 add     %l0, -0x41, %o0
F00E2A6C: 900a20ff                 and     %o0, 0xFF, %o0
F00E2A70: 80a22019                 cmp     %o0, 0x19
F00E2A74: 08800003                 bleu    loc_F00E2A80
F00E2A78: 90043fc9                 add     %l0, -0x37, %o0
F00E2A7C: 90043fa9                 add     %l0, -0x57, %o0
F00E2A80: a0100008                 mov     %o0, %l0
F00E2A84: 80a4001a                 cmp     %l0, %i2
F00E2A88: 16800015                 bge     loc_F00E2ADC
F00E2A8C: 80a4a000                 cmp     %l2, 0
F00E2A90: 06800009                 bl      loc_F00E2AB4
F00E2A94: 80a60013                 cmp     %i0, %l3
F00E2A98: 3880000e                 bgu,a   loc_F00E2AD0
F00E2A9C: a4103fff                 mov     -1, %l2
F00E2AA0: 12800007                 bne     loc_F00E2ABC
F00E2AA4: a4102001                 mov     1, %l2
F00E2AA8: 80a40015                 cmp     %l0, %l5
F00E2AAC: 04800005                 ble     loc_F00E2AC0
F00E2AB0: 90100018                 mov     %i0, %o0
F00E2AB4: 10800007                 ba      loc_F00E2AD0
F00E2AB8: a4103fff                 mov     -1, %l2
F00E2ABC: 90100018                 mov     %i0, %o0
F00E2AC0: 7ffc8e90                 call    _umul
F00E2AC4: 9210001a                 mov     %i2, %o1
F00E2AC8: b0100008                 mov     %o0, %i0
F00E2ACC: b0060010                 add     %i0, %l0, %i0
F00E2AD0: e04c4000                 ldsb    [%l1], %l0
F00E2AD4: 10bfffd2                 ba      loc_F00E2A1C
F00E2AD8: a2046001                 inc     %l1
F00E2ADC: 80a4a000                 cmp     %l2, 0
F00E2AE0: 16800007                 bge     loc_F00E2AFC
F00E2AE4: 80a52000                 cmp     %l4, 0
F00E2AE8: 12800007                 bne     loc_F00E2B04
F00E2AEC: 31200000                 sethi   0x80000000, %i0
F00E2AF0: 111fffff                 sethi   0x7FFFFC00, %o0
F00E2AF4: 10800004                 ba      loc_F00E2B04
F00E2AF8: b01223ff                 or      %o0, 0x3FF, %i0
F00E2AFC: 32800002                 bne,a   loc_F00E2B04
F00E2B00: b0200018                 neg     %i0
F00E2B04: 80a66000                 cmp     %i1, 0
F00E2B08: 02800006                 be      locret_F00E2B20
F00E2B0C: 80a4a000                 cmp     %l2, 0
F00E2B10: 02800003                 be      loc_F00E2B1C
F00E2B14: 90100016                 mov     %l6, %o0
F00E2B18: 90047fff                 add     %l1, -1, %o0
F00E2B1C: d0264000                 st      %o0, [%i1]
F00E2B20: 81c7e008                 ret
F00E2B24: 81e80000                 restore

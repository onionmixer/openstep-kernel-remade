F008D2CC: 9de3bf90                 save    %sp, -0x70, %sp
F008D2D0: 113c0504                 sethi   %hi(paIskindof), %o0! id
F008D2D4: d2022040                 ld      [%o0+%lo(paIskindof)], %o1! SEL
F008D2D8: a2062018                 add     %i0, 0x18, %l1
F008D2DC: d4062010                 ld      [%i0+0x10], %o2
F008D2E0: 40019164                 call    _objc_msgSend
F008D2E4: 9010001a                 mov     %i2, %o0
F008D2E8: 912a2018                 sll     %o0, 24, %o0
F008D2EC: 80a22000                 cmp     %o0, 0
F008D2F0: 2280001f                 be,a    locret_F008D36C
F008D2F4: b0102000                 mov     0, %i0
F008D2F8: e0062018                 ld      [%i0+0x18], %l0
F008D2FC: 80a42000                 cmp     %l0, 0
F008D300: 2280001b                 be,a    locret_F008D36C
F008D304: b0102000                 mov     0, %i0
F008D308: 133c0504                 sethi   %hi(paResourceinacti), %o1! SEL
F008D30C: 253c0504                 sethi   -0xFEBF000, %l2
F008D310: 80a4001a                 cmp     %l0, %i2
F008D314: 32800011                 bne,a   loc_F008D358
F008D318: a2042004                 add     %l0, 4, %l1
F008D31C: d0042004                 ld      [%l0+4], %o0
F008D320: d0244000                 st      %o0, [%l1]
F008D324: d0062014                 ld      [%i0+0x14], %o0
F008D328: 90023fff                 inc     -1, %o0
F008D32C: 80a22000                 cmp     %o0, 0
F008D330: 12800005                 bne     loc_F008D344
F008D334: d0262014                 st      %o0, [%i0+0x14]
F008D338: d0062004                 ld      [%i0+4], %o0! id
F008D33C: 4001914d                 call    _objc_msgSend
F008D340: d2026044                 ld      [%o1+%lo(paResourceinacti)], %o1
F008D344: d204a048                 ld      [%l2+0x48], %o1! SEL
F008D348: 4001914a                 call    _objc_msgSend
F008D34C: 90100010                 mov     %l0, %o0
F008D350: 10800007                 ba      locret_F008D36C
F008D354: b0100008                 mov     %o0, %i0
F008D358: e0042004                 ld      [%l0+4], %l0
F008D35C: 80a42000                 cmp     %l0, 0
F008D360: 12bfffed                 bne     loc_F008D314
F008D364: 80a4001a                 cmp     %l0, %i2
F008D368: b0102000                 mov     0, %i0
F008D36C: 81c7e008                 ret
F008D370: 81e80000                 restore

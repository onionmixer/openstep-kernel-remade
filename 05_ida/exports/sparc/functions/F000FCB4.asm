F000FCB4: 9de3bf98                 save    %sp, -0x68, %sp
F000FCB8: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F000FCBC: d00261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o0
F000FCC0: d4022024                 ld      [%o0+0x24], %o2
F000FCC4: a0102015                 mov     0x15, %l0
F000FCC8: d0028000                 ld      [%o2], %o0
F000FCCC: 80a22001                 cmp     %o0, 1
F000FCD0: 0280001c                 be      loc_F000FD40
F000FCD4: 921261dc                 bset    %lo(dword_F0133DDC), %o1
F000FCD8: 80a22001                 cmp     %o0, 1
F000FCDC: 14800007                 bg      loc_F000FCF8
F000FCE0: 80a22002                 cmp     %o0, 2
F000FCE4: 80a22000                 cmp     %o0, 0
F000FCE8: 22800008                 be,a    loc_F000FD08
F000FCEC: d002a004                 ld      [%o2+4], %o0
F000FCF0: 1080004b                 ba      loc_F000FE1C
F000FCF4: 113c04cf                 sethi   -0xFECC400, %o0
F000FCF8: 2280002e                 be,a    loc_F000FDB0
F000FCFC: d002a004                 ld      [%o2+4], %o0
F000FD00: 10800047                 ba      loc_F000FE1C
F000FD04: 113c04cf                 sethi   -0xFECC400, %o0
F000FD08: 80a22000                 cmp     %o0, 0
F000FD0C: 12800005                 bne     loc_F000FD20
F000FD10: 01000000                 nop
F000FD14: d0027ffc                 ld      [%o1-4], %o0
F000FD18: 10800005                 ba      loc_F000FD2C
F000FD1C: d2020000                 ld      [%o0], %o1
F000FD20: 7ffff9e8                 call    _pfind
F000FD24: 01000000                 nop
F000FD28: 92100008                 mov     %o0, %o1
F000FD2C: 80a26000                 cmp     %o1, 0
F000FD30: 3280003f                 bne,a   loc_F000FE2C
F000FD34: e04a6015                 ldsb    [%o1+0x15], %l0
F000FD38: 1080003e                 ba      loc_F000FE30
F000FD3C: 80a42015                 cmp     %l0, 0x15
F000FD40: d002a004                 ld      [%o2+4], %o0
F000FD44: 80a22000                 cmp     %o0, 0
F000FD48: 12800007                 bne     loc_F000FD64
F000FD4C: 113c04d3                 sethi   -0xFECB400, %o0
F000FD50: d0027ffc                 ld      [%o1-4], %o0
F000FD54: d0020000                 ld      [%o0], %o0
F000FD58: d052202e                 ldsh    [%o0+0x2E], %o0
F000FD5C: d022a004                 st      %o0, [%o2+4]
F000FD60: 113c04d3                 sethi   -0xFECB400, %o0
F000FD64: d2022278                 ld      [%o0+0x278], %o1
F000FD68: 80a26000                 cmp     %o1, 0
F000FD6C: 02800031                 be      loc_F000FE30
F000FD70: 80a42015                 cmp     %l0, 0x15
F000FD74: d402a004                 ld      [%o2+4], %o2
F000FD78: d052602e                 ldsh    [%o1+0x2E], %o0
F000FD7C: 80a2000a                 cmp     %o0, %o2
F000FD80: 32800007                 bne,a   loc_F000FD9C
F000FD84: d2026008                 ld      [%o1+8], %o1
F000FD88: d04a6015                 ldsb    [%o1+0x15], %o0
F000FD8C: 80a20010                 cmp     %o0, %l0
F000FD90: 26800002                 bl,a    loc_F000FD98
F000FD94: a0100008                 mov     %o0, %l0
F000FD98: d2026008                 ld      [%o1+8], %o1
F000FD9C: 80a26000                 cmp     %o1, 0
F000FDA0: 32bffff7                 bne,a   loc_F000FD7C
F000FDA4: d052602e                 ldsh    [%o1+0x2E], %o0
F000FDA8: 10800022                 ba      loc_F000FE30
F000FDAC: 80a42015                 cmp     %l0, 0x15
F000FDB0: 80a22000                 cmp     %o0, 0
F000FDB4: 12800007                 bne     loc_F000FDD0
F000FDB8: 113c04d3                 sethi   -0xFECB400, %o0
F000FDBC: d0027ffc                 ld      [%o1-4], %o0
F000FDC0: d002201c                 ld      [%o0+0x1C], %o0
F000FDC4: d0522002                 ldsh    [%o0+2], %o0
F000FDC8: d022a004                 st      %o0, [%o2+4]
F000FDCC: 113c04d3                 sethi   -0xFECB400, %o0
F000FDD0: d2022278                 ld      [%o0+0x278], %o1
F000FDD4: 80a26000                 cmp     %o1, 0
F000FDD8: 02800016                 be      loc_F000FE30
F000FDDC: 80a42015                 cmp     %l0, 0x15
F000FDE0: d402a004                 ld      [%o2+4], %o2
F000FDE4: d052602c                 ldsh    [%o1+0x2C], %o0
F000FDE8: 80a2000a                 cmp     %o0, %o2
F000FDEC: 32800007                 bne,a   loc_F000FE08
F000FDF0: d2026008                 ld      [%o1+8], %o1
F000FDF4: d04a6015                 ldsb    [%o1+0x15], %o0
F000FDF8: 80a20010                 cmp     %o0, %l0
F000FDFC: 26800002                 bl,a    loc_F000FE04
F000FE00: a0100008                 mov     %o0, %l0
F000FE04: d2026008                 ld      [%o1+8], %o1
F000FE08: 80a26000                 cmp     %o1, 0
F000FE0C: 32bffff7                 bne,a   loc_F000FDE8
F000FE10: d052602c                 ldsh    [%o1+0x2C], %o0
F000FE14: 10800007                 ba      loc_F000FE30
F000FE18: 80a42015                 cmp     %l0, 0x15
F000FE1C: d20221dc                 ld      [%o0+0x1DC], %o1
F000FE20: 90102016                 mov     0x16, %o0
F000FE24: 1080000b                 ba      locret_F000FE50
F000FE28: d02a6038                 stb     %o0, [%o1+0x38]
F000FE2C: 80a42015                 cmp     %l0, 0x15
F000FE30: 12800006                 bne     loc_F000FE48
F000FE34: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000FE38: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F000FE3C: 90102003                 mov     3, %o0
F000FE40: 10800004                 ba      locret_F000FE50
F000FE44: d02a6038                 stb     %o0, [%o1+0x38]
F000FE48: d00221dc                 ld      [%o0+0x1DC], %o0
F000FE4C: e0222030                 st      %l0, [%o0+0x30]
F000FE50: 81c7e008                 ret
F000FE54: 81e80000                 restore

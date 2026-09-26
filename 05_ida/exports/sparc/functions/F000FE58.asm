F000FE58: 9de3bf98                 save    %sp, -0x68, %sp
F000FE5C: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F000FE60: d00261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o0
F000FE64: e2022024                 ld      [%o0+0x24], %l1
F000FE68: a4102000                 mov     0, %l2
F000FE6C: d0044000                 ld      [%l1], %o0
F000FE70: 80a22001                 cmp     %o0, 1
F000FE74: 0280001f                 be      loc_F000FEF0
F000FE78: 921261dc                 bset    %lo(dword_F0133DDC), %o1
F000FE7C: 80a22001                 cmp     %o0, 1
F000FE80: 14800007                 bg      loc_F000FE9C
F000FE84: 80a22002                 cmp     %o0, 2
F000FE88: 80a22000                 cmp     %o0, 0
F000FE8C: 22800008                 be,a    loc_F000FEAC
F000FE90: d0046004                 ld      [%l1+4], %o0
F000FE94: 1080004e                 ba      loc_F000FFCC
F000FE98: 113c04cf                 sethi   -0xFECC400, %o0
F000FE9C: 22800031                 be,a    loc_F000FF60
F000FEA0: d0046004                 ld      [%l1+4], %o0
F000FEA4: 1080004a                 ba      loc_F000FFCC
F000FEA8: 113c04cf                 sethi   -0xFECC400, %o0
F000FEAC: 80a22000                 cmp     %o0, 0
F000FEB0: 12800005                 bne     loc_F000FEC4
F000FEB4: 01000000                 nop
F000FEB8: d0027ffc                 ld      [%o1-4], %o0
F000FEBC: 10800005                 ba      loc_F000FED0
F000FEC0: e0020000                 ld      [%o0], %l0
F000FEC4: 7ffff97f                 call    _pfind
F000FEC8: 01000000                 nop
F000FECC: a0100008                 mov     %o0, %l0
F000FED0: 80a42000                 cmp     %l0, 0
F000FED4: 02800041                 be      loc_F000FFD8
F000FED8: 90100010                 mov     %l0, %o0
F000FEDC: d2046008                 ld      [%l1+8], %o1
F000FEE0: 40000046                 call    _donice
F000FEE4: a404a001                 inc     %l2
F000FEE8: 1080003d                 ba      loc_F000FFDC
F000FEEC: 80a4a000                 cmp     %l2, 0
F000FEF0: d0046004                 ld      [%l1+4], %o0
F000FEF4: 80a22000                 cmp     %o0, 0
F000FEF8: 12800007                 bne     loc_F000FF14
F000FEFC: 113c04d3                 sethi   -0xFECB400, %o0
F000FF00: d0027ffc                 ld      [%o1-4], %o0
F000FF04: d0020000                 ld      [%o0], %o0
F000FF08: d052202e                 ldsh    [%o0+0x2E], %o0
F000FF0C: d0246004                 st      %o0, [%l1+4]
F000FF10: 113c04d3                 sethi   -0xFECB400, %o0
F000FF14: e0022278                 ld      [%o0+0x278], %l0
F000FF18: 80a42000                 cmp     %l0, 0
F000FF1C: 02800030                 be      loc_F000FFDC
F000FF20: 80a4a000                 cmp     %l2, 0
F000FF24: d254202e                 ldsh    [%l0+0x2E], %o1
F000FF28: d0046004                 ld      [%l1+4], %o0
F000FF2C: 80a24008                 cmp     %o1, %o0
F000FF30: 32800007                 bne,a   loc_F000FF4C
F000FF34: e0042008                 ld      [%l0+8], %l0
F000FF38: 90100010                 mov     %l0, %o0
F000FF3C: d2046008                 ld      [%l1+8], %o1
F000FF40: 4000002e                 call    _donice
F000FF44: a404a001                 inc     %l2
F000FF48: e0042008                 ld      [%l0+8], %l0
F000FF4C: 80a42000                 cmp     %l0, 0
F000FF50: 32bffff6                 bne,a   loc_F000FF28
F000FF54: d254202e                 ldsh    [%l0+0x2E], %o1
F000FF58: 10800021                 ba      loc_F000FFDC
F000FF5C: 80a4a000                 cmp     %l2, 0
F000FF60: 80a22000                 cmp     %o0, 0
F000FF64: 12800007                 bne     loc_F000FF80
F000FF68: 113c04d3                 sethi   -0xFECB400, %o0
F000FF6C: d0027ffc                 ld      [%o1-4], %o0
F000FF70: d002201c                 ld      [%o0+0x1C], %o0
F000FF74: d0522002                 ldsh    [%o0+2], %o0
F000FF78: d0246004                 st      %o0, [%l1+4]
F000FF7C: 113c04d3                 sethi   -0xFECB400, %o0
F000FF80: e0022278                 ld      [%o0+0x278], %l0
F000FF84: 80a42000                 cmp     %l0, 0
F000FF88: 02800015                 be      loc_F000FFDC
F000FF8C: 80a4a000                 cmp     %l2, 0
F000FF90: d254202c                 ldsh    [%l0+0x2C], %o1
F000FF94: d0046004                 ld      [%l1+4], %o0
F000FF98: 80a24008                 cmp     %o1, %o0
F000FF9C: 32800007                 bne,a   loc_F000FFB8
F000FFA0: e0042008                 ld      [%l0+8], %l0
F000FFA4: 90100010                 mov     %l0, %o0
F000FFA8: d2046008                 ld      [%l1+8], %o1
F000FFAC: 40000013                 call    _donice
F000FFB0: a404a001                 inc     %l2
F000FFB4: e0042008                 ld      [%l0+8], %l0
F000FFB8: 80a42000                 cmp     %l0, 0
F000FFBC: 32bffff6                 bne,a   loc_F000FF94
F000FFC0: d254202c                 ldsh    [%l0+0x2C], %o1
F000FFC4: 10800006                 ba      loc_F000FFDC
F000FFC8: 80a4a000                 cmp     %l2, 0
F000FFCC: d20221dc                 ld      [%o0+0x1DC], %o1
F000FFD0: 10800007                 ba      loc_F000FFEC
F000FFD4: 90102016                 mov     0x16, %o0
F000FFD8: 80a4a000                 cmp     %l2, 0
F000FFDC: 12800005                 bne     locret_F000FFF0
F000FFE0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000FFE4: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F000FFE8: 90102003                 mov     3, %o0
F000FFEC: d02a6038                 stb     %o0, [%o1+0x38]
F000FFF0: 81c7e008                 ret
F000FFF4: 81e80000                 restore

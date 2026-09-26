F001CE9C: 9de3bf98                 save    %sp, -0x68, %sp
F001CEA0: 4001e746                 call    _spltty
F001CEA4: 01000000                 nop
F001CEA8: d2060000                 ld      [%i0], %o1
F001CEAC: 80a26000                 cmp     %o1, 0
F001CEB0: 14800004                 bg      loc_F001CEC0
F001CEB4: 9a100008                 mov     %o0, %o5
F001CEB8: 10800044                 ba      loc_F001CFC8
F001CEBC: a0103fff                 mov     -1, %l0
F001CEC0: d2062008                 ld      [%i0+8], %o1
F001CEC4: 90027fff                 add     %o1, -1, %o0
F001CEC8: d0262008                 st      %o0, [%i0+8]
F001CECC: 940a203f                 and     %o0, 0x3F, %o2
F001CED0: 9610000a                 mov     %o2, %o3
F001CED4: e04a7fff                 ldsb    [%o1-1], %l0
F001CED8: 80a2a000                 cmp     %o2, 0
F001CEDC: 16800003                 bge     loc_F001CEE8
F001CEE0: 920a3fc0                 and     %o0, -0x40, %o1
F001CEE4: 9602a007                 add     %o2, 7, %o3
F001CEE8: 913ae003                 sra     %o3, 3, %o0
F001CEEC: 92020009                 add     %o0, %o1, %o1
F001CEF0: d24a6004                 ldsb    [%o1+4], %o1
F001CEF4: 912a2003                 sll     %o0, 3, %o0
F001CEF8: 90228008                 sub     %o2, %o0, %o0
F001CEFC: 933a4008                 sra     %o1, %o0, %o1
F001CF00: 808a6001                 btst    1, %o1
F001CF04: 32800002                 bne,a   loc_F001CF0C
F001CF08: a0142100                 bset    0x100, %l0
F001CF0C: d0060000                 ld      [%i0], %o0
F001CF10: 90023fff                 inc     -1, %o0
F001CF14: 80a22000                 cmp     %o0, 0
F001CF18: 1480000d                 bg      loc_F001CF4C
F001CF1C: d0260000                 st      %o0, [%i0]
F001CF20: c0262004                 clr     [%i0+4]
F001CF24: 153c043c                 sethi   %hi(_cfreelist), %o2
F001CF28: d8062008                 ld      [%i0+8], %o4
F001CF2C: 133c043c                 sethi   %hi(_cfreecount), %o1
F001CF30: d002a38c                 ld      [%o2+%lo(_cfreelist)], %o0
F001CF34: 980b3fc0                 and     %o4, -0x40, %o4
F001CF38: c0262008                 clr     [%i0+8]
F001CF3C: d0230000                 st      %o0, [%o4]
F001CF40: d0026390                 ld      [%o1+%lo(_cfreecount)], %o0
F001CF44: 1080001f                 ba      loc_F001CFC0
F001CF48: d822a38c                 st      %o4, [%o2+%lo(_cfreelist)]
F001CF4C: d2062008                 ld      [%i0+8], %o1
F001CF50: 940a7fc0                 and     %o1, -0x40, %o2
F001CF54: 9002a00c                 add     %o2, 0xC, %o0
F001CF58: 80a24008                 cmp     %o1, %o0
F001CF5C: 1280001b                 bne     loc_F001CFC8
F001CF60: 01000000                 nop
F001CF64: d8062004                 ld      [%i0+4], %o4
F001CF68: d4262008                 st      %o2, [%i0+8]
F001CF6C: 980b3fc0                 and     %o4, -0x40, %o4
F001CF70: d0030000                 ld      [%o4], %o0
F001CF74: 80a2000a                 cmp     %o0, %o2
F001CF78: 02800007                 be      loc_F001CF94
F001CF7C: 9210000a                 mov     %o2, %o1
F001CF80: d8030000                 ld      [%o4], %o4
F001CF84: d0030000                 ld      [%o4], %o0
F001CF88: 80a20009                 cmp     %o0, %o1
F001CF8C: 32bffffe                 bne,a   loc_F001CF84
F001CF90: d8030000                 ld      [%o4], %o4
F001CF94: 90032040                 add     %o4, 0x40, %o0 ! '@'
F001CF98: d0262008                 st      %o0, [%i0+8]
F001CF9C: 9610000c                 mov     %o4, %o3
F001CFA0: d8030000                 ld      [%o4], %o4
F001CFA4: 153c043c                 sethi   %hi(_cfreelist), %o2
F001CFA8: d002a38c                 ld      [%o2+%lo(_cfreelist)], %o0
F001CFAC: 133c043c                 sethi   %hi(_cfreecount), %o1
F001CFB0: d0230000                 st      %o0, [%o4]
F001CFB4: d822a38c                 st      %o4, [%o2+%lo(_cfreelist)]
F001CFB8: d0026390                 ld      [%o1+%lo(_cfreecount)], %o0
F001CFBC: c022c000                 clr     [%o3]
F001CFC0: 90022034                 inc     0x34, %o0 ! '4'
F001CFC4: d0226390                 st      %o0, [%o1+0x390]
F001CFC8: 4001e757                 call    _splx
F001CFCC: 9010000d                 mov     %o5, %o0
F001CFD0: 81c7e008                 ret
F001CFD4: 91e80010                 restore %g0, %l0, %o0

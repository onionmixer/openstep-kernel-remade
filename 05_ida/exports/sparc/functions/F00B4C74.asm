F00B4C74: 9de3bf98                 save    %sp, -0x68, %sp
F00B4C78: 133c0478                 sethi   %hi(_esp_softc), %o1
F00B4C7C: d00261a8                 ld      [%o1+%lo(_esp_softc)], %o0
F00B4C80: 80a22000                 cmp     %o0, 0
F00B4C84: 0280003d                 be      locret_F00B4D78
F00B4C88: b0102000                 mov     0, %i0
F00B4C8C: a8100009                 mov     %o1, %l4
F00B4C90: a6102001                 mov     1, %l3
F00B4C94: e00521a8                 ld      [%l4+0x1A8], %l0
F00B4C98: 80a42000                 cmp     %l0, 0
F00B4C9C: 02800026                 be      loc_F00B4D34
F00B4CA0: a4102000                 mov     0, %l2
F00B4CA4: d0042004                 ld      [%l0+4], %o0
F00B4CA8: 80a22000                 cmp     %o0, 0
F00B4CAC: 2280001f                 be,a    loc_F00B4D28
F00B4CB0: e0042028                 ld      [%l0+0x28], %l0
F00B4CB4: 7fff8814                 call    _splr
F00B4CB8: d0040000                 ld      [%l0], %o0
F00B4CBC: d2040000                 ld      [%l0], %o1
F00B4CC0: a2100008                 mov     %o0, %l1
F00B4CC4: 80a44009                 cmp     %l1, %o1
F00B4CC8: 3480000b                 bg,a    loc_F00B4CF4
F00B4CCC: d00420a0                 ld      [%l0+0xA0], %o0
F00B4CD0: d0042080                 ld      [%l0+0x80], %o0
F00B4CD4: 80a22000                 cmp     %o0, 0
F00B4CD8: 32800007                 bne,a   loc_F00B4CF4
F00B4CDC: d00420a0                 ld      [%l0+0xA0], %o0
F00B4CE0: d00420b4                 ld      [%l0+0xB4], %o0
F00B4CE4: 80a44008                 cmp     %l1, %o0
F00B4CE8: 1280000d                 bne     loc_F00B4D1C
F00B4CEC: 01000000                 nop
F00B4CF0: d00420a0                 ld      [%l0+0xA0], %o0
F00B4CF4: d0020000                 ld      [%o0], %o0
F00B4CF8: 808a2003                 btst    3, %o0
F00B4CFC: 02800008                 be      loc_F00B4D1C
F00B4D00: 01000000                 nop
F00B4D04: 4000001f                 call    _espsvc
F00B4D08: 90100010                 mov     %l0, %o0
F00B4D0C: d00c2030                 ldub    [%l0+0x30], %o0
F00B4D10: a4102001                 mov     1, %l2
F00B4D14: 912cc008                 sll     %l3, %o0, %o0
F00B4D18: b0160008                 bset    %o0, %i0
F00B4D1C: 7fff8802                 call    _splx
F00B4D20: 90100011                 mov     %l1, %o0
F00B4D24: e0042028                 ld      [%l0+0x28], %l0
F00B4D28: 80a42000                 cmp     %l0, 0
F00B4D2C: 32bfffdf                 bne,a   loc_F00B4CA8
F00B4D30: d0042004                 ld      [%l0+4], %o0
F00B4D34: 80a4a001                 cmp     %l2, 1
F00B4D38: 22bfffd8                 be,a    loc_F00B4C98
F00B4D3C: e00521a8                 ld      [%l4+0x1A8], %l0
F00B4D40: 80a62000                 cmp     %i0, 0
F00B4D44: 0280000d                 be      locret_F00B4D78
F00B4D48: 90063fff                 add     %i0, -1, %o0
F00B4D4C: 808e0008                 btst    %o0, %i0
F00B4D50: 02800005                 be      loc_F00B4D64
F00B4D54: 133c04fc                 sethi   %hi(_esp_nmultsvc), %o1
F00B4D58: d0026090                 ld      [%o1+%lo(_esp_nmultsvc)], %o0
F00B4D5C: 90022001                 inc     %o0
F00B4D60: d0226090                 st      %o0, [%o1+%lo(_esp_nmultsvc)]
F00B4D64: 133c04fc                 sethi   %hi(_esp_nhardints), %o1
F00B4D68: d0026088                 ld      [%o1+%lo(_esp_nhardints)], %o0
F00B4D6C: b0102001                 mov     1, %i0
F00B4D70: 90022001                 inc     %o0
F00B4D74: d0226088                 st      %o0, [%o1+%lo(_esp_nhardints)]
F00B4D78: 81c7e008                 ret
F00B4D7C: 81e80000                 restore

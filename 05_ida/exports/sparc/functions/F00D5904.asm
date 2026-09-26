F00D5904: 9de3bf80                 save    %sp, -0x80, %sp
F00D5908: a0103fff                 mov     -1, %l0
F00D590C: 9010001c                 mov     %i4, %o0! void *
F00D5910: 7ffefd52                 call    _bzero
F00D5914: 921024f0                 mov     0x4F0, %o1
F00D5918: e0272084                 st      %l0, [%i4+0x84]
F00D591C: e02720c8                 st      %l0, [%i4+0xC8]
F00D5920: e02722cc                 st      %l0, [%i4+0x2CC]
F00D5924: 9006801b                 add     %i2, %i3, %o0
F00D5928: d027bfe4                 st      %o0, [%fp+var_1C]
F00D592C: f427bfe0                 st      %i2, [%fp+var_20]
F00D5930: 90102001                 mov     1, %o0
F00D5934: d027bfe8                 st      %o0, [%fp+var_18]
F00D5938: f42724e8                 st      %i2, [%i4+0x4E8]
F00D593C: f62724ec                 st      %i3, [%i4+0x4EC]
F00D5940: d207bfe0                 ld      [%fp+var_20], %o1
F00D5944: d007bfe4                 ld      [%fp+var_1C], %o0
F00D5948: 80a24008                 cmp     %o1, %o0
F00D594C: 1a80000c                 bcc     loc_F00D597C
F00D5950: 90102000                 mov     0, %o0
F00D5954: d007bfe8                 ld      [%fp+var_18], %o0
F00D5958: 80a22000                 cmp     %o0, 0
F00D595C: 02800005                 be      loc_F00D5970
F00D5960: 90026002                 add     %o1, 2, %o0
F00D5964: d027bfe0                 st      %o0, [%fp+var_20]
F00D5968: 10800005                 ba      loc_F00D597C
F00D596C: d0124000                 lduh    [%o1], %o0
F00D5970: 90026001                 add     %o1, 1, %o0
F00D5974: d027bfe0                 st      %o0, [%fp+var_20]
F00D5978: d00a4000                 ldub    [%o1], %o0
F00D597C: d027bfe8                 st      %o0, [%fp+var_18]
F00D5980: d0370000                 sth     %o0, [%i4]
F00D5984: d207bfe0                 ld      [%fp+var_20], %o1
F00D5988: d007bfe4                 ld      [%fp+var_1C], %o0
F00D598C: 80a24008                 cmp     %o1, %o0
F00D5990: 1a80000c                 bcc     loc_F00D59C0
F00D5994: 9a102000                 mov     0, %o5
F00D5998: d007bfe8                 ld      [%fp+var_18], %o0
F00D599C: 80a22000                 cmp     %o0, 0
F00D59A0: 02800005                 be      loc_F00D59B4
F00D59A4: 90026002                 add     %o1, 2, %o0
F00D59A8: d027bfe0                 st      %o0, [%fp+var_20]
F00D59AC: 10800005                 ba      loc_F00D59C0
F00D59B0: da124000                 lduh    [%o1], %o5
F00D59B4: 90026001                 add     %o1, 1, %o0
F00D59B8: d027bfe0                 st      %o0, [%fp+var_20]
F00D59BC: da0a4000                 ldub    [%o1], %o5
F00D59C0: 84102000                 mov     0, %g2
F00D59C4: 80a0800d                 cmp     %g2, %o5
F00D59C8: 16800050                 bge     loc_F00D5B08
F00D59CC: d207bfe0                 ld      [%fp+var_20], %o1
F00D59D0: d007bfe4                 ld      [%fp+var_1C], %o0
F00D59D4: 80a24008                 cmp     %o1, %o0
F00D59D8: 1a80000c                 bcc     loc_F00D5A08
F00D59DC: 96102000                 mov     0, %o3
F00D59E0: d007bfe8                 ld      [%fp+var_18], %o0
F00D59E4: 80a22000                 cmp     %o0, 0
F00D59E8: 02800005                 be      loc_F00D59FC
F00D59EC: 90026002                 add     %o1, 2, %o0
F00D59F0: d027bfe0                 st      %o0, [%fp+var_20]
F00D59F4: 10800005                 ba      loc_F00D5A08
F00D59F8: d6124000                 lduh    [%o1], %o3
F00D59FC: 90026001                 add     %o1, 1, %o0
F00D5A00: d027bfe0                 st      %o0, [%fp+var_20]
F00D5A04: d60a4000                 ldub    [%o1], %o3
F00D5A08: 80a2e00f                 cmp     %o3, 0xF
F00D5A0C: 3480015c                 bg,a    locret_F00D5F7C
F00D5A10: b0102000                 mov     0, %i0
F00D5A14: d0072084                 ld      [%i4+0x84], %o0
F00D5A18: 80a2c008                 cmp     %o3, %o0
F00D5A1C: 34800002                 bg,a    loc_F00D5A24
F00D5A20: d6272084                 st      %o3, [%i4+0x84]
F00D5A24: 912ae002                 sll     %o3, 2, %o0
F00D5A28: d207bfe0                 ld      [%fp+var_20], %o1
F00D5A2C: 9002001c                 add     %o0, %i4, %o0
F00D5A30: d2222088                 st      %o1, [%o0+0x88]
F00D5A34: d207bfe0                 ld      [%fp+var_20], %o1
F00D5A38: d007bfe4                 ld      [%fp+var_1C], %o0
F00D5A3C: 80a24008                 cmp     %o1, %o0
F00D5A40: 0a800004                 bcs     loc_F00D5A50
F00D5A44: 98102000                 mov     0, %o4
F00D5A48: 1080000c                 ba      loc_F00D5A78
F00D5A4C: b4102000                 mov     0, %i2
F00D5A50: d007bfe8                 ld      [%fp+var_18], %o0
F00D5A54: 80a22000                 cmp     %o0, 0
F00D5A58: 02800005                 be      loc_F00D5A6C
F00D5A5C: 90026002                 add     %o1, 2, %o0
F00D5A60: d027bfe0                 st      %o0, [%fp+var_20]
F00D5A64: 10800005                 ba      loc_F00D5A78
F00D5A68: f4124000                 lduh    [%o1], %i2
F00D5A6C: 90026001                 add     %o1, 1, %o0
F00D5A70: d027bfe0                 st      %o0, [%fp+var_20]
F00D5A74: f40a4000                 ldub    [%o1], %i2
F00D5A78: 80a3001a                 cmp     %o4, %i2
F00D5A7C: 36800020                 bge,a   loc_F00D5AFC
F00D5A80: 8400a001                 inc     %g2
F00D5A84: 900ae00f                 and     %o3, 0xF, %o0
F00D5A88: 94122010                 or      %o0, 0x10, %o2
F00D5A8C: d207bfe0                 ld      [%fp+var_20], %o1
F00D5A90: d007bfe4                 ld      [%fp+var_1C], %o0
F00D5A94: 80a24008                 cmp     %o1, %o0
F00D5A98: 0a800004                 bcs     loc_F00D5AA8
F00D5A9C: d007bfe8                 ld      [%fp+var_18], %o0
F00D5AA0: 1080000b                 ba      loc_F00D5ACC
F00D5AA4: 92102000                 mov     0, %o1
F00D5AA8: 80a22000                 cmp     %o0, 0
F00D5AAC: 02800005                 be      loc_F00D5AC0
F00D5AB0: 90026002                 add     %o1, 2, %o0
F00D5AB4: d027bfe0                 st      %o0, [%fp+var_20]
F00D5AB8: 10800005                 ba      loc_F00D5ACC
F00D5ABC: d2124000                 lduh    [%o1], %o1
F00D5AC0: 90026001                 add     %o1, 1, %o0
F00D5AC4: d027bfe0                 st      %o0, [%fp+var_20]
F00D5AC8: d20a4000                 ldub    [%o1], %o1
F00D5ACC: 80a2607f                 cmp     %o1, 0x7F
F00D5AD0: 1480011b                 bg      loc_F00D5F3C
F00D5AD4: 92070009                 add     %i4, %o1, %o1
F00D5AD8: d00a6002                 ldub    [%o1+2], %o0
F00D5ADC: 808a2010                 btst    0x10, %o0
F00D5AE0: 12800117                 bne     loc_F00D5F3C
F00D5AE4: 9012000a                 bset    %o2, %o0
F00D5AE8: 98032001                 inc     %o4
F00D5AEC: 80a3001a                 cmp     %o4, %i2
F00D5AF0: 06bfffe7                 bl      loc_F00D5A8C
F00D5AF4: d02a6002                 stb     %o0, [%o1+2]
F00D5AF8: 8400a001                 inc     %g2
F00D5AFC: 80a0800d                 cmp     %g2, %o5
F00D5B00: 06bfffb4                 bl      loc_F00D59D0
F00D5B04: d207bfe0                 ld      [%fp+var_20], %o1
F00D5B08: d007bfe4                 ld      [%fp+var_1C], %o0
F00D5B0C: 80a24008                 cmp     %o1, %o0
F00D5B10: 1a80000c                 bcc     loc_F00D5B40
F00D5B14: 90102000                 mov     0, %o0
F00D5B18: d007bfe8                 ld      [%fp+var_18], %o0
F00D5B1C: 80a22000                 cmp     %o0, 0
F00D5B20: 02800005                 be      loc_F00D5B34
F00D5B24: 90026002                 add     %o1, 2, %o0
F00D5B28: d027bfe0                 st      %o0, [%fp+var_20]
F00D5B2C: 10800005                 ba      loc_F00D5B40
F00D5B30: d0124000                 lduh    [%o1], %o0
F00D5B34: 90026001                 add     %o1, 1, %o0
F00D5B38: d027bfe0                 st      %o0, [%fp+var_20]
F00D5B3C: d00a4000                 ldub    [%o1], %o0
F00D5B40: d02720c8                 st      %o0, [%i4+0xC8]
F00D5B44: b4100008                 mov     %o0, %i2
F00D5B48: 84102000                 mov     0, %g2
F00D5B4C: 1100003fb61223ff         set     0xFFFF, %i3
F00D5B54: 9e10001c                 mov     %i4, %o7
F00D5B58: 80a0801a                 cmp     %g2, %i2
F00D5B5C: 36800062                 bge,a   loc_F00D5CE4
F00D5B60: c023e0cc                 clr     [%o7+0xCC]
F00D5B64: d007bfe0                 ld      [%fp+var_20], %o0
F00D5B68: d023e0cc                 st      %o0, [%o7+0xCC]
F00D5B6C: d207bfe0                 ld      [%fp+var_20], %o1
F00D5B70: d007bfe4                 ld      [%fp+var_1C], %o0
F00D5B74: 80a24008                 cmp     %o1, %o0
F00D5B78: 1a80000c                 bcc     loc_F00D5BA8
F00D5B7C: 94102000                 mov     0, %o2
F00D5B80: d007bfe8                 ld      [%fp+var_18], %o0
F00D5B84: 80a22000                 cmp     %o0, 0
F00D5B88: 02800005                 be      loc_F00D5B9C
F00D5B8C: 90026002                 add     %o1, 2, %o0
F00D5B90: d027bfe0                 st      %o0, [%fp+var_20]
F00D5B94: 10800005                 ba      loc_F00D5BA8
F00D5B98: d4124000                 lduh    [%o1], %o2
F00D5B9C: 90026001                 add     %o1, 1, %o0
F00D5BA0: d027bfe0                 st      %o0, [%fp+var_20]
F00D5BA4: d40a4000                 ldub    [%o1], %o2
F00D5BA8: d007bfe8                 ld      [%fp+var_18], %o0
F00D5BAC: 80a22000                 cmp     %o0, 0
F00D5BB0: 02800006                 be      loc_F00D5BC8
F00D5BB4: 80a2801b                 cmp     %o2, %i3
F00D5BB8: 12800007                 bne     loc_F00D5BD4
F00D5BBC: 92070002                 add     %i4, %g2, %o1
F00D5BC0: 10800049                 ba      loc_F00D5CE4
F00D5BC4: c023e0cc                 clr     [%o7+0xCC]
F00D5BC8: 80a2a0ff                 cmp     %o2, 0xFF
F00D5BCC: 02800045                 be      loc_F00D5CE0
F00D5BD0: 92070002                 add     %i4, %g2, %o1
F00D5BD4: d00a6002                 ldub    [%o1+2], %o0
F00D5BD8: 96102000                 mov     0, %o3
F00D5BDC: 90122020                 bset    0x20, %o0 ! ' '
F00D5BE0: d02a6002                 stb     %o0, [%o1+2]
F00D5BE4: d0072084                 ld      [%i4+0x84], %o0
F00D5BE8: 80a2c008                 cmp     %o3, %o0
F00D5BEC: 1480000a                 bg      loc_F00D5C14
F00D5BF0: 98102001                 mov     1, %o4
F00D5BF4: 808aa001                 btst    1, %o2
F00D5BF8: 32800002                 bne,a   loc_F00D5C00
F00D5BFC: 992b2001                 sll     %o4, 1, %o4
F00D5C00: 9602e001                 inc     %o3
F00D5C04: 80a2c008                 cmp     %o3, %o0
F00D5C08: 04bffffb                 ble     loc_F00D5BF4
F00D5C0C: 953aa001                 sra     %o2, 1, %o2
F00D5C10: 96102000                 mov     0, %o3
F00D5C14: 80a2c00c                 cmp     %o3, %o4
F00D5C18: 36800034                 bge,a   loc_F00D5CE8
F00D5C1C: 8400a001                 inc     %g2
F00D5C20: c607bfe4                 ld      [%fp+var_1C], %g3
F00D5C24: da07bfe8                 ld      [%fp+var_18], %o5
F00D5C28: d207bfe0                 ld      [%fp+var_20], %o1
F00D5C2C: 80a24003                 cmp     %o1, %g3
F00D5C30: 1a80000b                 bcc     loc_F00D5C5C
F00D5C34: 94102000                 mov     0, %o2
F00D5C38: 80a36000                 cmp     %o5, 0
F00D5C3C: 02800005                 be      loc_F00D5C50
F00D5C40: 90026002                 add     %o1, 2, %o0
F00D5C44: d027bfe0                 st      %o0, [%fp+var_20]
F00D5C48: 10800005                 ba      loc_F00D5C5C
F00D5C4C: d4124000                 lduh    [%o1], %o2
F00D5C50: 90026001                 add     %o1, 1, %o0
F00D5C54: d027bfe0                 st      %o0, [%fp+var_20]
F00D5C58: d40a4000                 ldub    [%o1], %o2
F00D5C5C: d207bfe0                 ld      [%fp+var_20], %o1
F00D5C60: 80a24003                 cmp     %o1, %g3
F00D5C64: 0a800004                 bcs     loc_F00D5C74
F00D5C68: 80a36000                 cmp     %o5, 0
F00D5C6C: 1080000b                 ba      loc_F00D5C98
F00D5C70: 92102000                 mov     0, %o1
F00D5C74: 02800005                 be      loc_F00D5C88
F00D5C78: 90026002                 add     %o1, 2, %o0
F00D5C7C: d027bfe0                 st      %o0, [%fp+var_20]
F00D5C80: 10800005                 ba      loc_F00D5C94
F00D5C84: d2124000                 lduh    [%o1], %o1
F00D5C88: 90026001                 add     %o1, 1, %o0
F00D5C8C: d027bfe0                 st      %o0, [%fp+var_20]
F00D5C90: d20a4000                 ldub    [%o1], %o1
F00D5C94: 80a36000                 cmp     %o5, 0
F00D5C98: 02800006                 be      loc_F00D5CB0
F00D5C9C: 80a2801b                 cmp     %o2, %i3
F00D5CA0: 02800008                 be      loc_F00D5CC0
F00D5CA4: 80a24010                 cmp     %o1, %l0
F00D5CA8: 10800009                 ba      loc_F00D5CCC
F00D5CAC: 9602e001                 inc     %o3
F00D5CB0: 80a2a0ff                 cmp     %o2, 0xFF
F00D5CB4: 32800006                 bne,a   loc_F00D5CCC
F00D5CB8: 9602e001                 inc     %o3
F00D5CBC: 80a24010                 cmp     %o1, %l0
F00D5CC0: 34800002                 bg,a    loc_F00D5CC8
F00D5CC4: a0100009                 mov     %o1, %l0
F00D5CC8: 9602e001                 inc     %o3
F00D5CCC: 80a2c00c                 cmp     %o3, %o4
F00D5CD0: 06bfffd7                 bl      loc_F00D5C2C
F00D5CD4: d207bfe0                 ld      [%fp+var_20], %o1
F00D5CD8: 10800004                 ba      loc_F00D5CE8
F00D5CDC: 8400a001                 inc     %g2
F00D5CE0: c023e0cc                 clr     [%o7+0xCC]
F00D5CE4: 8400a001                 inc     %g2
F00D5CE8: 80a0a07f                 cmp     %g2, 0x7F
F00D5CEC: 04bfff9b                 ble     loc_F00D5B58
F00D5CF0: 9e03e004                 inc     4, %o7
F00D5CF4: d207bfe0                 ld      [%fp+var_20], %o1
F00D5CF8: d007bfe4                 ld      [%fp+var_1C], %o0
F00D5CFC: 80a24008                 cmp     %o1, %o0
F00D5D00: 1a80000c                 bcc     loc_F00D5D30
F00D5D04: 90102000                 mov     0, %o0
F00D5D08: d007bfe8                 ld      [%fp+var_18], %o0
F00D5D0C: 80a22000                 cmp     %o0, 0
F00D5D10: 02800005                 be      loc_F00D5D24
F00D5D14: 90026002                 add     %o1, 2, %o0
F00D5D18: d027bfe0                 st      %o0, [%fp+var_20]
F00D5D1C: 10800005                 ba      loc_F00D5D30
F00D5D20: d0124000                 lduh    [%o1], %o0
F00D5D24: 90026001                 add     %o1, 1, %o0
F00D5D28: d027bfe0                 st      %o0, [%fp+var_20]
F00D5D2C: d00a4000                 ldub    [%o1], %o0
F00D5D30: 80a20010                 cmp     %o0, %l0
F00D5D34: 04800082                 ble     loc_F00D5F3C
F00D5D38: d02722cc                 st      %o0, [%i4+0x2CC]
F00D5D3C: 84102000                 mov     0, %g2
F00D5D40: 80a08008                 cmp     %g2, %o0
F00D5D44: 16800036                 bge     loc_F00D5E1C
F00D5D48: d207bfe0                 ld      [%fp+var_20], %o1
F00D5D4C: 9a10001c                 mov     %i4, %o5
F00D5D50: d007bfe0                 ld      [%fp+var_20], %o0
F00D5D54: d02362d0                 st      %o0, [%o5+0x2D0]
F00D5D58: d207bfe0                 ld      [%fp+var_20], %o1
F00D5D5C: d007bfe4                 ld      [%fp+var_1C], %o0
F00D5D60: 80a24008                 cmp     %o1, %o0
F00D5D64: 0a800004                 bcs     loc_F00D5D74
F00D5D68: 96102000                 mov     0, %o3
F00D5D6C: 1080000c                 ba      loc_F00D5D9C
F00D5D70: 92102000                 mov     0, %o1
F00D5D74: d007bfe8                 ld      [%fp+var_18], %o0
F00D5D78: 80a22000                 cmp     %o0, 0
F00D5D7C: 02800005                 be      loc_F00D5D90
F00D5D80: 90026002                 add     %o1, 2, %o0
F00D5D84: d027bfe0                 st      %o0, [%fp+var_20]
F00D5D88: 10800005                 ba      loc_F00D5D9C
F00D5D8C: d2124000                 lduh    [%o1], %o1
F00D5D90: 90026001                 add     %o1, 1, %o0
F00D5D94: d027bfe0                 st      %o0, [%fp+var_20]
F00D5D98: d20a4000                 ldub    [%o1], %o1
F00D5D9C: 80a2c009                 cmp     %o3, %o1
F00D5DA0: 3680001a                 bge,a   loc_F00D5E08
F00D5DA4: d00722cc                 ld      [%i4+0x2CC], %o0
F00D5DA8: d807bfe4                 ld      [%fp+var_1C], %o4
F00D5DAC: d407bfe8                 ld      [%fp+var_18], %o2
F00D5DB0: d007bfe0                 ld      [%fp+var_20], %o0
F00D5DB4: 80a2000c                 cmp     %o0, %o4
F00D5DB8: 1a800006                 bcc     loc_F00D5DD0
F00D5DBC: 80a2a000                 cmp     %o2, 0
F00D5DC0: 22800003                 be,a    loc_F00D5DCC
F00D5DC4: 90022001                 inc     %o0
F00D5DC8: 90022002                 inc     2, %o0
F00D5DCC: d027bfe0                 st      %o0, [%fp+var_20]
F00D5DD0: d007bfe0                 ld      [%fp+var_20], %o0
F00D5DD4: 80a2000c                 cmp     %o0, %o4
F00D5DD8: 3a800008                 bcc,a   loc_F00D5DF8
F00D5DDC: 9602e001                 inc     %o3
F00D5DE0: 80a2a000                 cmp     %o2, 0
F00D5DE4: 22800003                 be,a    loc_F00D5DF0
F00D5DE8: 90022001                 inc     %o0
F00D5DEC: 90022002                 inc     2, %o0
F00D5DF0: d027bfe0                 st      %o0, [%fp+var_20]
F00D5DF4: 9602e001                 inc     %o3
F00D5DF8: 80a2c009                 cmp     %o3, %o1
F00D5DFC: 06bfffee                 bl      loc_F00D5DB4
F00D5E00: d007bfe0                 ld      [%fp+var_20], %o0
F00D5E04: d00722cc                 ld      [%i4+0x2CC], %o0
F00D5E08: 8400a001                 inc     %g2
F00D5E0C: 80a08008                 cmp     %g2, %o0
F00D5E10: 06bfffd0                 bl      loc_F00D5D50
F00D5E14: 9a036004                 inc     4, %o5
F00D5E18: d207bfe0                 ld      [%fp+var_20], %o1
F00D5E1C: d007bfe4                 ld      [%fp+var_1C], %o0
F00D5E20: 80a24008                 cmp     %o1, %o0
F00D5E24: 1a80000c                 bcc     loc_F00D5E54
F00D5E28: 9a102000                 mov     0, %o5
F00D5E2C: d007bfe8                 ld      [%fp+var_18], %o0
F00D5E30: 80a22000                 cmp     %o0, 0
F00D5E34: 02800005                 be      loc_F00D5E48
F00D5E38: 90026002                 add     %o1, 2, %o0
F00D5E3C: d027bfe0                 st      %o0, [%fp+var_20]
F00D5E40: 10800005                 ba      loc_F00D5E54
F00D5E44: da124000                 lduh    [%o1], %o5
F00D5E48: 90026001                 add     %o1, 1, %o0
F00D5E4C: d027bfe0                 st      %o0, [%fp+var_20]
F00D5E50: da0a4000                 ldub    [%o1], %o5
F00D5E54: 80a36009                 cmp     %o5, 9
F00D5E58: 34800049                 bg,a    locret_F00D5F7C
F00D5E5C: b0102000                 mov     0, %i0
F00D5E60: 80a36000                 cmp     %o5, 0
F00D5E64: 02800036                 be      loc_F00D5F3C
F00D5E68: 94103fff                 mov     -1, %o2
F00D5E6C: 90072010                 add     %i4, 0x10, %o0
F00D5E70: 9210001c                 mov     %i4, %o1
F00D5E74: d43224d4                 sth     %o2, [%o0+0x4D4]
F00D5E78: 90023ffe                 inc     -2, %o0
F00D5E7C: 80a20009                 cmp     %o0, %o1
F00D5E80: 36bffffe                 bge,a   loc_F00D5E78
F00D5E84: d43224d4                 sth     %o2, [%o0+0x4D4]
F00D5E88: 84102000                 mov     0, %g2
F00D5E8C: 80a0800d                 cmp     %g2, %o5
F00D5E90: 1680002e                 bge     loc_F00D5F48
F00D5E94: 1100003f                 sethi   0xFC00, %o0
F00D5E98: d207bfe0                 ld      [%fp+var_20], %o1
F00D5E9C: d007bfe4                 ld      [%fp+var_1C], %o0
F00D5EA0: 80a24008                 cmp     %o1, %o0
F00D5EA4: 1a80000f                 bcc     loc_F00D5EE0
F00D5EA8: 96102000                 mov     0, %o3
F00D5EAC: d007bfe8                 ld      [%fp+var_18], %o0
F00D5EB0: 80a22000                 cmp     %o0, 0
F00D5EB4: 02800005                 be      loc_F00D5EC8
F00D5EB8: 90026002                 add     %o1, 2, %o0
F00D5EBC: d027bfe0                 st      %o0, [%fp+var_20]
F00D5EC0: 10800005                 ba      loc_F00D5ED4
F00D5EC4: d6124000                 lduh    [%o1], %o3
F00D5EC8: 90026001                 add     %o1, 1, %o0
F00D5ECC: d027bfe0                 st      %o0, [%fp+var_20]
F00D5ED0: d60a4000                 ldub    [%o1], %o3
F00D5ED4: d207bfe0                 ld      [%fp+var_20], %o1
F00D5ED8: d007bfe4                 ld      [%fp+var_1C], %o0
F00D5EDC: 80a24008                 cmp     %o1, %o0
F00D5EE0: 0a800004                 bcs     loc_F00D5EF0
F00D5EE4: d007bfe8                 ld      [%fp+var_18], %o0
F00D5EE8: 1080000b                 ba      loc_F00D5F14
F00D5EEC: 92102000                 mov     0, %o1
F00D5EF0: 80a22000                 cmp     %o0, 0
F00D5EF4: 02800005                 be      loc_F00D5F08
F00D5EF8: 90026002                 add     %o1, 2, %o0
F00D5EFC: d027bfe0                 st      %o0, [%fp+var_20]
F00D5F00: 10800005                 ba      loc_F00D5F14
F00D5F04: d2124000                 lduh    [%o1], %o1
F00D5F08: 90026001                 add     %o1, 1, %o0
F00D5F0C: d027bfe0                 st      %o0, [%fp+var_20]
F00D5F10: d20a4000                 ldub    [%o1], %o1
F00D5F14: 80a2e008                 cmp     %o3, 8
F00D5F18: 14800009                 bg      loc_F00D5F3C
F00D5F1C: 912ae001                 sll     %o3, 1, %o0
F00D5F20: 9002001c                 add     %o0, %i4, %o0
F00D5F24: 8400a001                 inc     %g2
F00D5F28: 80a0800d                 cmp     %g2, %o5
F00D5F2C: 06bfffdb                 bl      loc_F00D5E98
F00D5F30: d23224d4                 sth     %o1, [%o0+0x4D4]
F00D5F34: 10800004                 ba      loc_F00D5F44
F00D5F38: 84102000                 mov     0, %g2
F00D5F3C: 10800010                 ba      locret_F00D5F7C
F00D5F40: b0102000                 mov     0, %i0
F00D5F44: 1100003f                 sethi   0xFC00, %o0
F00D5F48: 961223ff                 or      %o0, 0x3FF, %o3
F00D5F4C: 9410001c                 mov     %i4, %o2
F00D5F50: d012a4d4                 lduh    [%o2+0x4D4], %o0
F00D5F54: 80a2000b                 cmp     %o0, %o3
F00D5F58: 02800006                 be      loc_F00D5F70
F00D5F5C: 8400a001                 inc     %g2
F00D5F60: 92070008                 add     %i4, %o0, %o1
F00D5F64: d00a6002                 ldub    [%o1+2], %o0
F00D5F68: 90122060                 bset    0x60, %o0 ! '`'
F00D5F6C: d02a6002                 stb     %o0, [%o1+2]
F00D5F70: 80a0a006                 cmp     %g2, 6
F00D5F74: 04bffff7                 ble     loc_F00D5F50
F00D5F78: 9402a002                 inc     2, %o2
F00D5F7C: 81c7e008                 ret
F00D5F80: 81e80000                 restore

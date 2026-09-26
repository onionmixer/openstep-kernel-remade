F0031AC0: 9de3bf88                 save    %sp, -0x78, %sp
F0031AC4: d016200c                 lduh    [%i0+0xC], %o0
F0031AC8: 808a2001                 btst    1, %o0
F0031ACC: 02800005                 be      loc_F0031AE0
F0031AD0: a4102000                 mov     0, %l2
F0031AD4: 808a2008                 btst    8, %o0
F0031AD8: 02800004                 be      loc_F0031AE8
F0031ADC: 01000000                 nop
F0031AE0: 10800083                 ba      locret_F0031CEC
F0031AE4: b0102000                 mov     0, %i0
F0031AE8: 7fffffb0                 call    _ifptoia
F0031AEC: 90100018                 mov     %i0, %o0
F0031AF0: a6920000                 orcc    %o0, %g0, %l3
F0031AF4: 12800004                 bne     loc_F0031B04
F0031AF8: 90102001                 mov     1, %o0
F0031AFC: 10800077                 ba      loc_F0031CD8
F0031B00: b0102033                 mov     0x33, %i0 ! '3'
F0031B04: 7fffaf96                 call    _m_get
F0031B08: 92102002                 mov     2, %o1
F0031B0C: a4920000                 orcc    %o0, %g0, %l2
F0031B10: 12800004                 bne     loc_F0031B20
F0031B14: 90102020                 mov     0x20, %o0 ! ' '
F0031B18: 10800071                 ba      loc_F0031CDC
F0031B1C: b0102037                 mov     0x37, %i0 ! '7'
F0031B20: d034a008                 sth     %o0, [%l2+8]
F0031B24: 9010205c                 mov     0x5C, %o0! void *
F0031B28: d024a004                 st      %o0, [%l2+4]
F0031B2C: d254a008                 ldsh    [%l2+8], %o1! size_t
F0031B30: 40018cca                 call    _bzero
F0031B34: 9004a05c                 add     %l2, 0x5C, %o0 ! '\'
F0031B38: 920e60ff                 and     %i1, 0xFF, %o1
F0031B3C: d014a008                 lduh    [%l2+8], %o0
F0031B40: 80a26012                 cmp     %o1, 0x12
F0031B44: d204a004                 ld      [%l2+4], %o1
F0031B48: 90023fec                 inc     -0x14, %o0
F0031B4C: d034a008                 sth     %o0, [%l2+8]
F0031B50: 92026014                 inc     0x14, %o1
F0031B54: d224a004                 st      %o1, [%l2+4]
F0031B58: 1280000a                 bne     loc_F0031B80
F0031B5C: a0048009                 add     %l2, %o1, %l0
F0031B60: 90102012                 mov     0x12, %o0
F0031B64: d02c8009                 stb     %o0, [%l2+%o1]
F0031B68: d004e034                 ld      [%l3+0x34], %o0
F0031B6C: 80a22000                 cmp     %o0, 0
F0031B70: 12800006                 bne     loc_F0031B88
F0031B74: d0242008                 st      %o0, [%l0+8]
F0031B78: 10800058                 ba      loc_F0031CD8
F0031B7C: b0102016                 mov     0x16, %i0
F0031B80: 90102011                 mov     0x11, %o0
F0031B84: d02c8009                 stb     %o0, [%l2+%o1]
F0031B88: c02c2001                 clrb    [%l0+1]
F0031B8C: c0342002                 clrh    [%l0+2]
F0031B90: c0242004                 clr     [%l0+4]
F0031B94: 90100012                 mov     %l2, %o0
F0031B98: 40019cbc                 call    _in_cksum
F0031B9C: 9210200c                 mov     0xC, %o1
F0031BA0: d0342002                 sth     %o0, [%l0+2]
F0031BA4: 90100012                 mov     %l2, %o0
F0031BA8: d204a004                 ld      [%l2+4], %o1
F0031BAC: 173c04d9                 sethi   %hi(_ip_id), %o3
F0031BB0: d414a008                 lduh    [%l2+8], %o2
F0031BB4: a2103fff                 mov     -1, %l1
F0031BB8: d812e0a0                 lduh    [%o3+%lo(_ip_id)], %o4
F0031BBC: 92027fec                 inc     -0x14, %o1
F0031BC0: d224a004                 st      %o1, [%l2+4]
F0031BC4: 9402a014                 inc     0x14, %o2
F0031BC8: d434a008                 sth     %o2, [%l2+8]
F0031BCC: 92032001                 add     %o4, 1, %o1
F0031BD0: e004a004                 ld      [%l2+4], %l0
F0031BD4: d232e0a0                 sth     %o1, [%o3+%lo(_ip_id)]
F0031BD8: d2048010                 ld      [%l2+%l0], %o1
F0031BDC: 153c0000                 sethi   -0x10000000, %o2
F0031BE0: 942a400a                 andn    %o1, %o2, %o2
F0031BE4: 13100000                 sethi   0x40000000, %o1
F0031BE8: 94128009                 bset    %o1, %o2
F0031BEC: 1303c000                 sethi   0xF000000, %o1
F0031BF0: 922a8009                 andn    %o2, %o1, %o1
F0031BF4: 15014000                 sethi   0x5000000, %o2
F0031BF8: 9212400a                 bset    %o2, %o1
F0031BFC: d2248010                 st      %o1, [%l2+%l0]
F0031C00: a0048010                 add     %l2, %l0, %l0
F0031C04: d8342004                 sth     %o4, [%l0+4]
F0031C08: 921020ff                 mov     0xFF, %o1
F0031C0C: d22c2008                 stb     %o1, [%l0+8]
F0031C10: 92102001                 mov     1, %o1
F0031C14: d22c2009                 stb     %o1, [%l0+9]
F0031C18: d404e004                 ld      [%l3+4], %o2
F0031C1C: 92102014                 mov     0x14, %o1
F0031C20: d424200c                 st      %o2, [%l0+0xC]
F0031C24: e2242010                 st      %l1, [%l0+0x10]
F0031C28: 94102020                 mov     0x20, %o2 ! ' '
F0031C2C: d4342002                 sth     %o2, [%l0+2]
F0031C30: 40019c96                 call    _in_cksum
F0031C34: c034200a                 clrh    [%l0+0xA]
F0031C38: d034200a                 sth     %o0, [%l0+0xA]
F0031C3C: 90102002                 mov     2, %o0
F0031C40: d037bfe8                 sth     %o0, [%fp+var_18]
F0031C44: c037bfea                 clrh    [%fp+var_16]
F0031C48: 80a6a000                 cmp     %i2, 0
F0031C4C: 04800010                 ble     loc_F0031C8C
F0031C50: e227bfec                 st      %l1, [%fp+var_14]
F0031C54: 9010001a                 mov     %i2, %o0
F0031C58: 133c043e                 sethi   %hi(_hz), %o1
F0031C5C: d20263e0                 ld      [%o1+%lo(_hz)], %o1
F0031C60: 213c004b                 sethi   %hi(_wakeup), %l0
F0031C64: 7fff5227                 call    _umul
F0031C68: a01421e8                 bset    %lo(_wakeup), %l0
F0031C6C: 94100008                 mov     %o0, %o2
F0031C70: 90100010                 mov     %l0, %o0! int
F0031C74: a004e034                 add     %l3, 0x34, %l0 ! '4'
F0031C78: 7fff60ec                 call    _timeout
F0031C7C: 92100010                 mov     %l0, %o1
F0031C80: 90100010                 mov     %l0, %o0! unsigned int
F0031C84: 7fff827d                 call    _sleep
F0031C88: 92102019                 mov     0x19, %o1
F0031C8C: 90100018                 mov     %i0, %o0
F0031C90: 92100012                 mov     %l2, %o1
F0031C94: 7fffe98d                 call    _if_output_mbuf
F0031C98: 9407bfe8                 add     %fp, var_18, %o2
F0031C9C: b0100008                 mov     %o0, %i0
F0031CA0: 900e60ff                 and     %i1, 0xFF, %o0
F0031CA4: 80a22011                 cmp     %o0, 0x11
F0031CA8: 1280000c                 bne     loc_F0031CD8
F0031CAC: a4102000                 mov     0, %l2
F0031CB0: 113c004b901221e8         set     _wakeup, %o0! int
F0031CB8: 133c043e                 sethi   %hi(_hz), %o1
F0031CBC: d40263e0                 ld      [%o1+%lo(_hz)], %o2
F0031CC0: a004e034                 add     %l3, 0x34, %l0 ! '4'
F0031CC4: 7fff60d9                 call    _timeout
F0031CC8: 92100010                 mov     %l0, %o1
F0031CCC: 90100010                 mov     %l0, %o0! unsigned int
F0031CD0: 7fff826a                 call    _sleep
F0031CD4: 92102019                 mov     0x19, %o1
F0031CD8: 80a4a000                 cmp     %l2, 0
F0031CDC: 02800004                 be      locret_F0031CEC
F0031CE0: 01000000                 nop
F0031CE4: 7fffafe0                 call    _m_freem
F0031CE8: 90100012                 mov     %l2, %o0
F0031CEC: 81c7e008                 ret
F0031CF0: 81e80000                 restore

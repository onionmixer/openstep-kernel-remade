F0099A4C: 9de3bf98                 save    %sp, -0x68, %sp
F0099A50: 7ffff44e                 call    _splusclock
F0099A54: 01000000                 nop
F0099A58: 133c045c                 sethi   %hi(dword_F011708C), %o1
F0099A5C: d202608c                 ld      [%o1+%lo(dword_F011708C)], %o1
F0099A60: 80a26000                 cmp     %o1, 0
F0099A64: 02800013                 be      loc_F0099AB0
F0099A68: a4100008                 mov     %o0, %l2
F0099A6C: 113c04f6a0122330         set     _softcalls, %l0
F0099A74: 90042258                 add     %l0, 0x258, %o0
F0099A78: 80a40008                 cmp     %l0, %o0
F0099A7C: 3a80000c                 bcc,a   loc_F0099AAC
F0099A80: 113c045c                 sethi   -0xFEE9000, %o0
F0099A84: 133c04f7                 sethi   %hi(_softfree), %o1
F0099A88: 94100008                 mov     %o0, %o2
F0099A8C: d0026188                 ld      [%o1+%lo(_softfree)], %o0
F0099A90: d0242008                 st      %o0, [%l0+8]
F0099A94: e0226188                 st      %l0, [%o1+0x188]
F0099A98: a004200c                 inc     0xC, %l0
F0099A9C: 80a4000a                 cmp     %l0, %o2
F0099AA0: 0abffffc                 bcs     loc_F0099A90
F0099AA4: d0026188                 ld      [%o1+0x188], %o0
F0099AA8: 113c045c                 sethi   -0xFEE9000, %o0
F0099AAC: c022208c                 clr     [%o0+0x8C]
F0099AB0: 113c04f7                 sethi   %hi(_softhead), %o0
F0099AB4: e0022190                 ld      [%o0+%lo(_softhead)], %l0
F0099AB8: 80a42000                 cmp     %l0, 0
F0099ABC: 0280000f                 be      loc_F0099AF8
F0099AC0: 233c04f7                 sethi   -0xFEC2400, %l1
F0099AC4: d0040000                 ld      [%l0], %o0
F0099AC8: 80a20018                 cmp     %o0, %i0
F0099ACC: 32800007                 bne,a   loc_F0099AE8
F0099AD0: e0042008                 ld      [%l0+8], %l0
F0099AD4: d0042004                 ld      [%l0+4], %o0
F0099AD8: 80a20019                 cmp     %o0, %i1
F0099ADC: 02800021                 be      loc_F0099B60
F0099AE0: 113c045c                 sethi   -0xFEE9000, %o0
F0099AE4: e0042008                 ld      [%l0+8], %l0
F0099AE8: 80a42000                 cmp     %l0, 0
F0099AEC: 32bffff7                 bne,a   loc_F0099AC8
F0099AF0: d0040000                 ld      [%l0], %o0
F0099AF4: 233c04f7                 sethi   -0xFEC2400, %l1
F0099AF8: e0046188                 ld      [%l1+0x188], %l0
F0099AFC: 80a42000                 cmp     %l0, 0
F0099B00: 32800006                 bne,a   loc_F0099B18
F0099B04: f0240000                 st      %i0, [%l0]
F0099B08: 113c045c                 sethi   %hi(aTooManySoftcal), %o0! "too many softcalls"
F0099B0C: 7ffded99                 call    _panic
F0099B10: 90122090                 bset    %lo(aTooManySoftcal), %o0! "too many softcalls"
F0099B14: f0240000                 st      %i0, [%l0]
F0099B18: f2242004                 st      %i1, [%l0+4]
F0099B1C: d0042008                 ld      [%l0+8], %o0
F0099B20: 133c04f7                 sethi   %hi(_softhead), %o1
F0099B24: d0246188                 st      %o0, [%l1+0x188]
F0099B28: d0026190                 ld      [%o1+%lo(_softhead)], %o0
F0099B2C: 80a22000                 cmp     %o0, 0
F0099B30: 02800007                 be      loc_F0099B4C
F0099B34: c0242008                 clr     [%l0+8]
F0099B38: 133c04f7                 sethi   %hi(_softtail), %o1
F0099B3C: d0026198                 ld      [%o1+%lo(_softtail)], %o0
F0099B40: e0222008                 st      %l0, [%o0+8]
F0099B44: 10800006                 ba      loc_F0099B5C
F0099B48: e0226198                 st      %l0, [%o1+%lo(_softtail)]
F0099B4C: 113c04f7                 sethi   %hi(_softtail), %o0
F0099B50: e0222198                 st      %l0, [%o0+%lo(_softtail)]
F0099B54: 7ffff4c2                 call    _siron
F0099B58: e0226190                 st      %l0, [%o1+0x190]
F0099B5C: 113c045c                 sethi   -0xFEE9000, %o0
F0099B60: d0022088                 ld      [%o0+0x88], %o0
F0099B64: 80a22000                 cmp     %o0, 0
F0099B68: 02800004                 be      loc_F0099B78
F0099B6C: 01000000                 nop
F0099B70: 7ffff4bb                 call    _siron
F0099B74: 01000000                 nop
F0099B78: 7ffff46b                 call    _splx
F0099B7C: 90100012                 mov     %l2, %o0
F0099B80: 81c7e008                 ret
F0099B84: 81e80000                 restore

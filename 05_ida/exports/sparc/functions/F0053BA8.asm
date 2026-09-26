F0053BA8: 9de3bf98                 save    %sp, -0x68, %sp
F0053BAC: a5366008                 srl     %i1, 8, %l2
F0053BB0: ab2e6018                 sll     %i1, 24, %l5
F0053BB4: a2102000                 mov     0, %l1
F0053BB8: a0062008                 add     %i0, 8, %l0
F0053BBC: d0040000                 ld      [%l0], %o0
F0053BC0: 80a22000                 cmp     %o0, 0
F0053BC4: 12bffffe                 bne     loc_F0053BBC
F0053BC8: 01000000                 nop
F0053BCC: 40010cb7                 call    _simple_lock_try
F0053BD0: 90100010                 mov     %l0, %o0
F0053BD4: 80a22000                 cmp     %o0, 0
F0053BD8: 02bffff9                 be      loc_F0053BBC
F0053BDC: 293c04ef                 sethi   -0xFEC4400, %l4
F0053BE0: a72ca004                 sll     %l2, 4, %l3
F0053BE4: d006200c                 ld      [%i0+0xC], %o0
F0053BE8: 80a22000                 cmp     %o0, 0
F0053BEC: 1280000a                 bne     loc_F0053C14
F0053BF0: 80a4a000                 cmp     %l2, 0
F0053BF4: c0262008                 clr     [%i0+8]
F0053BF8: 80a46000                 cmp     %l1, 0
F0053BFC: 02800004                 be      loc_F0053C0C
F0053C00: d00522d8                 ld      [%l4+0x2D8], %o0
F0053C04: 40009573                 call    _zfree
F0053C08: 92100011                 mov     %l1, %o1
F0053C0C: 10800099                 ba      locret_F0053E70
F0053C10: b0102010                 mov     0x10, %i0
F0053C14: 22800034                 be,a    loc_F0053CE4
F0053C18: d0062038                 ld      [%i0+0x38], %o0
F0053C1C: d0062018                 ld      [%i0+0x18], %o0
F0053C20: 80a48008                 cmp     %l2, %o0
F0053C24: 1a80002f                 bcc     loc_F0053CE0
F0053C28: 110007c0                 sethi   0x1F0000, %o0
F0053C2C: d6062014                 ld      [%i0+0x14], %o3
F0053C30: d202c013                 ld      [%o3+%l3], %o1
F0053C34: 808a4008                 btst    %o0, %o1
F0053C38: 0280000f                 be      loc_F0053C74
F0053C3C: 9802c013                 add     %o3, %l3, %o4
F0053C40: 113fc000                 sethi   -0x1000000, %o0
F0053C44: 900a4008                 and     %o1, %o0, %o0
F0053C48: 80a20015                 cmp     %o0, %l5
F0053C4C: 32800026                 bne,a   loc_F0053CE4
F0053C50: d0062038                 ld      [%i0+0x38], %o0
F0053C54: 80a46000                 cmp     %l1, 0
F0053C58: 02800071                 be      loc_F0053E1C
F0053C5C: d8268000                 st      %o4, [%i2]
F0053C60: d00522d8                 ld      [%l4+0x2D8], %o0
F0053C64: 4000955b                 call    _zfree
F0053C68: 92100011                 mov     %l1, %o1
F0053C6C: 10800081                 ba      locret_F0053E70
F0053C70: b0102000                 mov     0, %i0
F0053C74: d202e008                 ld      [%o3+8], %o1
F0053C78: 80a24012                 cmp     %o1, %l2
F0053C7C: 02800009                 be      loc_F0053CA0
F0053C80: 94102000                 mov     0, %o2
F0053C84: 94100009                 mov     %o1, %o2
F0053C88: 912aa004                 sll     %o2, 4, %o0
F0053C8C: 9002c008                 add     %o3, %o0, %o0
F0053C90: d2022008                 ld      [%o0+8], %o1
F0053C94: 80a24012                 cmp     %o1, %l2
F0053C98: 32bffffc                 bne,a   loc_F0053C88
F0053C9C: 94100009                 mov     %o1, %o2
F0053CA0: 80a46000                 cmp     %l1, 0
F0053CA4: 912aa004                 sll     %o2, 4, %o0
F0053CA8: 932a6004                 sll     %o1, 4, %o1
F0053CAC: 9202c009                 add     %o3, %o1, %o1
F0053CB0: d2026008                 ld      [%o1+8], %o1
F0053CB4: 9002c008                 add     %o3, %o0, %o0
F0053CB8: d2222008                 st      %o1, [%o0+8]
F0053CBC: ea230000                 st      %l5, [%o4]
F0053CC0: c0232008                 clr     [%o4+8]
F0053CC4: 02800056                 be      loc_F0053E1C
F0053CC8: d8268000                 st      %o4, [%i2]
F0053CCC: d00522d8                 ld      [%l4+0x2D8], %o0
F0053CD0: 40009540                 call    _zfree
F0053CD4: 92100011                 mov     %l1, %o1
F0053CD8: 10800066                 ba      locret_F0053E70
F0053CDC: b0102000                 mov     0, %i0
F0053CE0: d0062038                 ld      [%i0+0x38], %o0
F0053CE4: 80a22000                 cmp     %o0, 0
F0053CE8: 0280000e                 be      loc_F0053D20
F0053CEC: 90062020                 add     %i0, 0x20, %o0 ! ' '
F0053CF0: 40002990                 call    _ipc_splay_tree_lookup
F0053CF4: 92100019                 mov     %i1, %o1
F0053CF8: 80a22000                 cmp     %o0, 0
F0053CFC: 02800009                 be      loc_F0053D20
F0053D00: 80a46000                 cmp     %l1, 0
F0053D04: 02800046                 be      loc_F0053E1C
F0053D08: d0268000                 st      %o0, [%i2]
F0053D0C: d00522d8                 ld      [%l4+0x2D8], %o0
F0053D10: 40009530                 call    _zfree
F0053D14: 92100011                 mov     %l1, %o1
F0053D18: 10800056                 ba      locret_F0053E70
F0053D1C: b0102000                 mov     0, %i0
F0053D20: d0062018                 ld      [%i0+0x18], %o0
F0053D24: 80a20012                 cmp     %o0, %l2
F0053D28: 18800019                 bgu     loc_F0053D8C
F0053D2C: d406201c                 ld      [%i0+0x1C], %o2
F0053D30: d2028000                 ld      [%o2], %o1
F0053D34: 80a48009                 cmp     %l2, %o1
F0053D38: 1a800015                 bcc     loc_F0053D8C
F0053D3C: 92224008                 sub     %o1, %o0, %o1
F0053D40: d006203c                 ld      [%i0+0x3C], %o0
F0053D44: 932a6004                 sll     %o1, 4, %o1
F0053D48: 90022001                 inc     %o0
F0053D4C: 912a2005                 sll     %o0, 5, %o0
F0053D50: 80a24008                 cmp     %o1, %o0
F0053D54: 1a80000f                 bcc     loc_F0053D90
F0053D58: 80a46000                 cmp     %l1, 0
F0053D5C: 400000c1                 call    _ipc_entry_grow_table
F0053D60: 90100018                 mov     %i0, %o0
F0053D64: a0920000                 orcc    %o0, %g0, %l0
F0053D68: 22bfffa0                 be,a    loc_F0053BE8
F0053D6C: d006200c                 ld      [%i0+0xC], %o0
F0053D70: 80a46000                 cmp     %l1, 0
F0053D74: 02800004                 be      loc_F0053D84
F0053D78: d00522d8                 ld      [%l4+0x2D8], %o0
F0053D7C: 40009515                 call    _zfree
F0053D80: 92100011                 mov     %l1, %o1
F0053D84: 1080003b                 ba      locret_F0053E70
F0053D88: b0100010                 mov     %l0, %i0
F0053D8C: 80a46000                 cmp     %l1, 0
F0053D90: 02800025                 be      loc_F0053E24
F0053D94: d00522d8                 ld      [%l4+0x2D8], %o0
F0053D98: d0062038                 ld      [%i0+0x38], %o0
F0053D9C: d2062018                 ld      [%i0+0x18], %o1
F0053DA0: 90022001                 inc     %o0
F0053DA4: 80a48009                 cmp     %l2, %o1
F0053DA8: 1a800008                 bcc     loc_F0053DC8
F0053DAC: d0262038                 st      %o0, [%i0+0x38]
F0053DB0: d0062014                 ld      [%i0+0x14], %o0
F0053DB4: d2020013                 ld      [%o0+%l3], %o1
F0053DB8: 15002000                 sethi   0x800000, %o2
F0053DBC: 9212400a                 bset    %o2, %o1
F0053DC0: 1080000e                 ba      loc_F0053DF8
F0053DC4: d2220013                 st      %o1, [%o0+%l3]
F0053DC8: d0028000                 ld      [%o2], %o0
F0053DCC: 80a48008                 cmp     %l2, %o0
F0053DD0: 1a80000a                 bcc     loc_F0053DF8
F0053DD4: 90100018                 mov     %i0, %o0
F0053DD8: 7fffff01                 call    _ipc_entry_tree_collision
F0053DDC: 92100019                 mov     %i1, %o1
F0053DE0: 80a22000                 cmp     %o0, 0
F0053DE4: 12800006                 bne     loc_F0053DFC
F0053DE8: 90062020                 add     %i0, 0x20, %o0 ! ' '
F0053DEC: d006203c                 ld      [%i0+0x3C], %o0
F0053DF0: 90022001                 inc     %o0
F0053DF4: d026203c                 st      %o0, [%i0+0x3C]
F0053DF8: 90062020                 add     %i0, 0x20, %o0 ! ' '
F0053DFC: 92100019                 mov     %i1, %o1
F0053E00: 40002970                 call    _ipc_splay_tree_insert
F0053E04: 94100011                 mov     %l1, %o2
F0053E08: c0244000                 clr     [%l1]
F0053E0C: c0246004                 clr     [%l1+4]
F0053E10: c0246008                 clr     [%l1+8]
F0053E14: f0246014                 st      %i0, [%l1+0x14]
F0053E18: e2268000                 st      %l1, [%i2]
F0053E1C: 10800015                 ba      locret_F0053E70
F0053E20: b0102000                 mov     0, %i0
F0053E24: c0262008                 clr     [%i0+8]
F0053E28: 400094a9                 call    _zalloc
F0053E2C: a0062008                 add     %i0, 8, %l0
F0053E30: a2920000                 orcc    %o0, %g0, %l1
F0053E34: 12800004                 bne     loc_F0053E44
F0053E38: 01000000                 nop
F0053E3C: 1080000d                 ba      locret_F0053E70
F0053E40: b0102006                 mov     6, %i0
F0053E44: d0040000                 ld      [%l0], %o0
F0053E48: 80a22000                 cmp     %o0, 0
F0053E4C: 12bffffe                 bne     loc_F0053E44
F0053E50: 01000000                 nop
F0053E54: 40010c15                 call    _simple_lock_try
F0053E58: 90100010                 mov     %l0, %o0
F0053E5C: 80a22000                 cmp     %o0, 0
F0053E60: 02bffff9                 be      loc_F0053E44
F0053E64: 01000000                 nop
F0053E68: 10bfff60                 ba      loc_F0053BE8
F0053E6C: d006200c                 ld      [%i0+0xC], %o0
F0053E70: 81c7e008                 ret
F0053E74: 81e80000                 restore

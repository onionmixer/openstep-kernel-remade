F006B9AC: 9de3bf98                 save    %sp, -0x68, %sp
F006B9B0: 80a66000                 cmp     %i1, 0
F006B9B4: 12800004                 bne     loc_F006B9C4
F006B9B8: b0102005                 mov     5, %i0
F006B9BC: 10800041                 ba      locret_F006BAC0
F006B9C0: b0102004                 mov     4, %i0
F006B9C4: 113c04f0a4122120         set     _listeners, %l2
F006B9CC: 9004a080                 add     %l2, 0x80, %o0
F006B9D0: 80a48008                 cmp     %l2, %o0
F006B9D4: 1a80003b                 bcc     locret_F006BAC0
F006B9D8: 2b3c04f0                 sethi   -0xFEC4000, %l5
F006B9DC: ac100008                 mov     %o0, %l6
F006B9E0: a604a004                 add     %l2, 4, %l3
F006B9E4: 4000acac                 call    _splnet
F006B9E8: 01000000                 nop
F006B9EC: a8100008                 mov     %o0, %l4
F006B9F0: d0048000                 ld      [%l2], %o0
F006B9F4: 80a22000                 cmp     %o0, 0
F006B9F8: 12bffffe                 bne     loc_F006B9F0
F006B9FC: 01000000                 nop
F006BA00: 4000ad2a                 call    _simple_lock_try
F006BA04: 90100012                 mov     %l2, %o0
F006BA08: 80a22000                 cmp     %o0, 0
F006BA0C: 02bffff9                 be      loc_F006B9F0
F006BA10: 01000000                 nop
F006BA14: e004c000                 ld      [%l3], %l0
F006BA18: 80a42000                 cmp     %l0, 0
F006BA1C: 02800022                 be      loc_F006BAA4
F006BA20: a2100010                 mov     %l0, %l1
F006BA24: d0042010                 ld      [%l0+0x10], %o0
F006BA28: 80a20019                 cmp     %o0, %i1
F006BA2C: 3280001a                 bne,a   loc_F006BA94
F006BA30: a2100010                 mov     %l0, %l1
F006BA34: d004c000                 ld      [%l3], %o0
F006BA38: 80a40008                 cmp     %l0, %o0
F006BA3C: 1280000c                 bne     loc_F006BA6C
F006BA40: b0102000                 mov     0, %i0
F006BA44: d4040000                 ld      [%l0], %o2
F006BA48: 92100010                 mov     %l0, %o1
F006BA4C: d0056118                 ld      [%l5+0x118], %o0
F006BA50: 400035e0                 call    _zfree
F006BA54: d424c000                 st      %o2, [%l3]
F006BA58: e004c000                 ld      [%l3], %l0
F006BA5C: 80a42000                 cmp     %l0, 0
F006BA60: 02800011                 be      loc_F006BAA4
F006BA64: a2100010                 mov     %l0, %l1
F006BA68: 30800007                 ba,a    loc_F006BA84
F006BA6C: d4040000                 ld      [%l0], %o2
F006BA70: 92100010                 mov     %l0, %o1
F006BA74: d0056118                 ld      [%l5+0x118], %o0
F006BA78: 400035d6                 call    _zfree
F006BA7C: d4244000                 st      %o2, [%l1]
F006BA80: a0100011                 mov     %l1, %l0
F006BA84: 7fffb6fb                 call    _ipc_object_release
F006BA88: 90100019                 mov     %i1, %o0
F006BA8C: 10800003                 ba      loc_F006BA98
F006BA90: e0040000                 ld      [%l0], %l0
F006BA94: e0040000                 ld      [%l0], %l0
F006BA98: 80a42000                 cmp     %l0, 0
F006BA9C: 32bfffe3                 bne,a   loc_F006BA28
F006BAA0: d0042010                 ld      [%l0+0x10], %o0
F006BAA4: c0248000                 clr     [%l2]
F006BAA8: 4000ac9f                 call    _splx
F006BAAC: 90100014                 mov     %l4, %o0
F006BAB0: a404a008                 inc     8, %l2
F006BAB4: 80a48016                 cmp     %l2, %l6
F006BAB8: 0abfffcb                 bcs     loc_F006B9E4
F006BABC: a604e008                 inc     8, %l3
F006BAC0: 81c7e008                 ret
F006BAC4: 81e80000                 restore

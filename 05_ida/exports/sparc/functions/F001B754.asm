F001B754: 9de3bf98                 save    %sp, -0x68, %sp
F001B758: 113c04bc                 sethi   %hi(unk_F012F204), %o0
F001B75C: d4162038                 lduh    [%i0+0x38], %o2
F001B760: 90122204                 bset    %lo(unk_F012F204), %o0
F001B764: 920aa0ff                 and     %o2, 0xFF, %o1
F001B768: 932a6004                 sll     %o1, 4, %o1
F001B76C: 92024008                 add     %o1, %o0, %o1
F001B770: 80a2a000                 cmp     %o2, 0
F001B774: 0280002e                 be      locret_F001B82C
F001B778: e002600c                 ld      [%o1+0xC], %l0
F001B77C: 808e6001                 btst    1, %i1
F001B780: 02800016                 be      loc_F001B7D8
F001B784: 808e6002                 btst    2, %i1
F001B788: 4001ed0c                 call    _spltty
F001B78C: 01000000                 nop
F001B790: d4042004                 ld      [%l0+4], %o2
F001B794: 80a2a000                 cmp     %o2, 0
F001B798: 0280000b                 be      loc_F001B7C4
F001B79C: a2100008                 mov     %o0, %l1
F001B7A0: d2040000                 ld      [%l0], %o1
F001B7A4: 9010000a                 mov     %o2, %o0
F001B7A8: 7fffea5b                 call    _selwakeup
F001B7AC: 920a6001                 and     %o1, 1, %o1
F001B7B0: 7fffea49                 call    _selthreadclear
F001B7B4: 90042004                 add     %l0, 4, %o0
F001B7B8: d0040000                 ld      [%l0], %o0
F001B7BC: 900a3ffe                 and     %o0, -2, %o0
F001B7C0: d0240000                 st      %o0, [%l0]
F001B7C4: 4001ed58                 call    _splx
F001B7C8: 90100011                 mov     %l1, %o0
F001B7CC: 7fffdd87                 call    _wakeup
F001B7D0: 9006201c                 add     %i0, 0x1C, %o0
F001B7D4: 808e6002                 btst    2, %i1
F001B7D8: 02800015                 be      locret_F001B82C
F001B7DC: 01000000                 nop
F001B7E0: 4001ecf6                 call    _spltty
F001B7E4: 01000000                 nop
F001B7E8: d4042008                 ld      [%l0+8], %o2
F001B7EC: 80a2a000                 cmp     %o2, 0
F001B7F0: 0280000b                 be      loc_F001B81C
F001B7F4: a2100008                 mov     %o0, %l1
F001B7F8: d2040000                 ld      [%l0], %o1
F001B7FC: 9010000a                 mov     %o2, %o0
F001B800: 7fffea45                 call    _selwakeup
F001B804: 920a6002                 and     %o1, 2, %o1
F001B808: 7fffea33                 call    _selthreadclear
F001B80C: 90042008                 add     %l0, 8, %o0
F001B810: d0040000                 ld      [%l0], %o0
F001B814: 900a3ffd                 and     %o0, -3, %o0
F001B818: d0240000                 st      %o0, [%l0]
F001B81C: 4001ed42                 call    _splx
F001B820: 90100011                 mov     %l1, %o0
F001B824: 7fffdd71                 call    _wakeup
F001B828: 90062004                 add     %i0, 4, %o0
F001B82C: 81c7e008                 ret
F001B830: 81e80000                 restore

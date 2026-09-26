F004D7C8: 9de3bf98                 save    %sp, -0x68, %sp
F004D7CC: a0100018                 mov     %i0, %l0
F004D7D0: 7ffffe53                 call    sub_F004D11C
F004D7D4: 90100010                 mov     %l0, %o0
F004D7D8: d004200c                 ld      [%l0+0xC], %o0
F004D7DC: 80a22000                 cmp     %o0, 0
F004D7E0: 16800007                 bge     loc_F004D7FC
F004D7E4: 113c04eb                 sethi   %hi(dword_F013AD8C), %o0
F004D7E8: d202218c                 ld      [%o0+%lo(dword_F013AD8C)], %o1
F004D7EC: 9fc24000                 call    %o1
F004D7F0: 90100010                 mov     %l0, %o0
F004D7F4: 1080001a                 ba      locret_F004D85C
F004D7F8: b0100008                 mov     %o0, %i0
F004D7FC: 400124ef                 call    _spltty
F004D800: b0042024                 add     %l0, 0x24, %i0 ! '$'
F004D804: a2100008                 mov     %o0, %l1
F004D808: d0060000                 ld      [%i0], %o0
F004D80C: 80a22000                 cmp     %o0, 0
F004D810: 12bffffe                 bne     loc_F004D808
F004D814: 01000000                 nop
F004D818: 400125a4                 call    _simple_lock_try
F004D81C: 90100018                 mov     %i0, %o0
F004D820: 80a22000                 cmp     %o0, 0
F004D824: 02bffff9                 be      loc_F004D808
F004D828: 90042010                 add     %l0, 0x10, %o0
F004D82C: f0042010                 ld      [%l0+0x10], %i0
F004D830: 80a20018                 cmp     %o0, %i0
F004D834: 02800006                 be      loc_F004D84C
F004D838: 90100011                 mov     %l1, %o0
F004D83C: f0060000                 ld      [%i0], %i0
F004D840: c0242024                 clr     [%l0+0x24]
F004D844: 40012538                 call    _splx
F004D848: 9e03e010                 inc     0x10, %o7
F004D84C: c0242024                 clr     [%l0+0x24]
F004D850: 40012535                 call    _splx
F004D854: 90100011                 mov     %l1, %o0
F004D858: b0102000                 mov     0, %i0
F004D85C: 81c7e008                 ret
F004D860: 81e80000                 restore

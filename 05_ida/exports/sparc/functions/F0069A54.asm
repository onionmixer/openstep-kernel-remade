F0069A54: 9de3bf98                 save    %sp, -0x68, %sp
F0069A58: 4000b44c                 call    _splusclock
F0069A5C: 01000000                 nop
F0069A60: a2100008                 mov     %o0, %l1
F0069A64: 113c04bda0122280         set     dword_F012F680, %l0
F0069A6C: d0040000                 ld      [%l0], %o0
F0069A70: 80a22000                 cmp     %o0, 0
F0069A74: 12bffffe                 bne     loc_F0069A6C
F0069A78: 01000000                 nop
F0069A7C: 4000b50b                 call    _simple_lock_try
F0069A80: 90100010                 mov     %l0, %o0
F0069A84: 80a22000                 cmp     %o0, 0
F0069A88: 02bffff9                 be      loc_F0069A6C
F0069A8C: 01000000                 nop
F0069A90: d0062034                 ld      [%i0+0x34], %o0
F0069A94: 80a22000                 cmp     %o0, 0
F0069A98: 12800008                 bne     loc_F0069AB8
F0069A9C: 01000000                 nop
F0069AA0: 113c04bd                 sethi   %hi(dword_F012F680), %o0
F0069AA4: c0222280                 clr     [%o0+%lo(dword_F012F680)]
F0069AA8: 4000b49f                 call    _splx
F0069AAC: 90100011                 mov     %l1, %o0
F0069AB0: 1080000a                 ba      locret_F0069AD8
F0069AB4: b0102000                 mov     0, %i0
F0069AB8: 400035fa                 call    _calloutEntryRemove
F0069ABC: 90100018                 mov     %i0, %o0
F0069AC0: c0262034                 clr     [%i0+0x34]
F0069AC4: 113c04bd                 sethi   %hi(dword_F012F680), %o0
F0069AC8: c0222280                 clr     [%o0+%lo(dword_F012F680)]
F0069ACC: 4000b496                 call    _splx
F0069AD0: 90100011                 mov     %l1, %o0
F0069AD4: b0102001                 mov     1, %i0
F0069AD8: 81c7e008                 ret
F0069ADC: 81e80000                 restore

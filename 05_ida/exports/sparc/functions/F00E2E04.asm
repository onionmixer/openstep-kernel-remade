F00E2E04: 9de3bf98                 save    %sp, -0x68, %sp
F00E2E08: d2062004                 ld      [%i0+4], %o1
F00E2E0C: 80a26020                 cmp     %o1, 0x20 ! ' '
F00E2E10: 12800005                 bne     loc_F00E2E24
F00E2E14: d00e2003                 ldub    [%i0+3], %o0
F00E2E18: 80a22000                 cmp     %o0, 0
F00E2E1C: 22800005                 be,a    loc_F00E2E30
F00E2E20: d0062018                 ld      [%i0+0x18], %o0
F00E2E24: 90103ed0                 mov     -0x130, %o0
F00E2E28: 10800012                 ba      locret_F00E2E70
F00E2E2C: d026601c                 st      %o0, [%i1+0x1C]
F00E2E30: 133c03e6                 sethi   %hi(dword_F00F99C4), %o1
F00E2E34: d20261c4                 ld      [%o1+%lo(dword_F00F99C4)], %o1
F00E2E38: 80a20009                 cmp     %o0, %o1
F00E2E3C: 12800005                 bne     loc_F00E2E50
F00E2E40: 90103ed0                 mov     -0x130, %o0
F00E2E44: d006200c                 ld      [%i0+0xC], %o0
F00E2E48: 7fffc9aa                 call    _EvOpen
F00E2E4C: d206201c                 ld      [%i0+0x1C], %o1
F00E2E50: d026601c                 st      %o0, [%i1+0x1C]
F00E2E54: d006601c                 ld      [%i1+0x1C], %o0
F00E2E58: 80a22000                 cmp     %o0, 0
F00E2E5C: 12800005                 bne     locret_F00E2E70
F00E2E60: 92102020                 mov     0x20, %o1 ! ' '
F00E2E64: 90102001                 mov     1, %o0
F00E2E68: d02e6003                 stb     %o0, [%i1+3]
F00E2E6C: d2266004                 st      %o1, [%i1+4]
F00E2E70: 81c7e008                 ret
F00E2E74: 81e80000                 restore

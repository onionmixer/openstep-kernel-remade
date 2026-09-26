F00E2E78: 9de3bf98                 save    %sp, -0x68, %sp
F00E2E7C: d2062004                 ld      [%i0+4], %o1
F00E2E80: 80a26020                 cmp     %o1, 0x20 ! ' '
F00E2E84: 12800005                 bne     loc_F00E2E98
F00E2E88: d00e2003                 ldub    [%i0+3], %o0
F00E2E8C: 80a22000                 cmp     %o0, 0
F00E2E90: 22800005                 be,a    loc_F00E2EA4
F00E2E94: d0062018                 ld      [%i0+0x18], %o0
F00E2E98: 90103ed0                 mov     -0x130, %o0
F00E2E9C: 10800012                 ba      locret_F00E2EE4
F00E2EA0: d026601c                 st      %o0, [%i1+0x1C]
F00E2EA4: 133c03e6                 sethi   %hi(dword_F00F99C8), %o1
F00E2EA8: d20261c8                 ld      [%o1+%lo(dword_F00F99C8)], %o1
F00E2EAC: 80a20009                 cmp     %o0, %o1
F00E2EB0: 12800005                 bne     loc_F00E2EC4
F00E2EB4: 90103ed0                 mov     -0x130, %o0
F00E2EB8: d006200c                 ld      [%i0+0xC], %o0
F00E2EBC: 7fffc99a                 call    _EvClose
F00E2EC0: d206201c                 ld      [%i0+0x1C], %o1
F00E2EC4: d026601c                 st      %o0, [%i1+0x1C]
F00E2EC8: d006601c                 ld      [%i1+0x1C], %o0
F00E2ECC: 80a22000                 cmp     %o0, 0
F00E2ED0: 12800005                 bne     locret_F00E2EE4
F00E2ED4: 92102020                 mov     0x20, %o1 ! ' '
F00E2ED8: 90102001                 mov     1, %o0
F00E2EDC: d02e6003                 stb     %o0, [%i1+3]
F00E2EE0: d2266004                 st      %o1, [%i1+4]
F00E2EE4: 81c7e008                 ret
F00E2EE8: 81e80000                 restore

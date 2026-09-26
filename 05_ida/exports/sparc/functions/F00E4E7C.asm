F00E4E7C: 9de3bf98                 save    %sp, -0x68, %sp
F00E4E80: 313c04bb                 sethi   %hi(_sparcfbs), %i0
F00E4E84: d0062364                 ld      [%i0+%lo(_sparcfbs)], %o0
F00E4E88: 80a22000                 cmp     %o0, 0
F00E4E8C: 3280000c                 bne,a   loc_F00E4EBC
F00E4E90: 113c03f2                 sethi   -0xFF03800, %o0
F00E4E94: 113c04fd901223b0         set     _fakeshmem, %o0! void *
F00E4E9C: d0262364                 st      %o0, [%i0+%lo(_sparcfbs)]
F00E4EA0: 7ffebfee                 call    _bzero
F00E4EA4: 92102448                 mov     0x448, %o1
F00E4EA8: d2062364                 ld      [%i0+%lo(_sparcfbs)], %o1! tree *
F00E4EAC: 112aeeaa901223ba         set     -0x54455446, %o0
F00E4EB4: d0224000                 st      %o0, [%o1]
F00E4EB8: 113c03f2                 sethi   -0xFF03800, %o0! char *
F00E4EBC: 40000021                 call    _find_node
F00E4EC0: 90122290                 bset    0x290, %o0
F00E4EC4: 92920000                 orcc    %o0, %g0, %o1! tree *
F00E4EC8: 02800007                 be      loc_F00E4EE4
F00E4ECC: 113c03f2                 sethi   -0xFF03800, %o0
F00E4ED0: 40000041                 call    _cg14ConfigDisplay
F00E4ED4: 90102000                 mov     0, %o0
F00E4ED8: 80a22000                 cmp     %o0, 0
F00E4EDC: 02800016                 be      loc_F00E4F34
F00E4EE0: 113c03f2                 sethi   -0xFF03800, %o0! char *
F00E4EE4: 40000017                 call    _find_node
F00E4EE8: 901222a0                 bset    0x2A0, %o0
F00E4EEC: 92920000                 orcc    %o0, %g0, %o1! tree *
F00E4EF0: 02800007                 be      loc_F00E4F0C
F00E4EF4: 113c03f2                 sethi   -0xFF03800, %o0
F00E4EF8: 40000133                 call    _cg6ConfigDisplay
F00E4EFC: 90102000                 mov     0, %o0
F00E4F00: 80a22000                 cmp     %o0, 0
F00E4F04: 0280000c                 be      loc_F00E4F34
F00E4F08: 113c03f2                 sethi   -0xFF03800, %o0! char *
F00E4F0C: 4000000d                 call    _find_node
F00E4F10: 901222a8                 bset    0x2A8, %o0
F00E4F14: 92920000                 orcc    %o0, %g0, %o1
F00E4F18: 02800008                 be      locret_F00E4F38
F00E4F1C: b0103d40                 mov     -0x2C0, %i0
F00E4F20: 40000091                 call    _s24ConfigDisplay
F00E4F24: 90102000                 mov     0, %o0
F00E4F28: 80a22000                 cmp     %o0, 0
F00E4F2C: 12800003                 bne     locret_F00E4F38
F00E4F30: b0103d40                 mov     -0x2C0, %i0
F00E4F34: b0102000                 mov     0, %i0
F00E4F38: 81c7e008                 ret
F00E4F3C: 81e80000                 restore

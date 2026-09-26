F005DF84: 9de3bf98                 save    %sp, -0x68, %sp
F005DF88: 113c04ef                 sethi   %hi(_ipc_space_zone), %o0
F005DF8C: 40006c50                 call    _zalloc
F005DF90: d0022340                 ld      [%o0+%lo(_ipc_space_zone)], %o0
F005DF94: 92920000                 orcc    %o0, %g0, %o1
F005DF98: 22800009                 be,a    locret_F005DFBC
F005DF9C: b0102006                 mov     6, %i0
F005DFA0: c0224000                 clr     [%o1]
F005DFA4: 90102001                 mov     1, %o0
F005DFA8: d0226004                 st      %o0, [%o1+4]
F005DFAC: c0226008                 clr     [%o1+8]
F005DFB0: c022600c                 clr     [%o1+0xC]
F005DFB4: d2260000                 st      %o1, [%i0]
F005DFB8: b0102000                 mov     0, %i0
F005DFBC: 81c7e008                 ret
F005DFC0: 81e80000                 restore

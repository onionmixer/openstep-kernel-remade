F00223D0: 9de3bf98                 save    %sp, -0x68, %sp
F00223D4: 7fffa42c                 call    _getf
F00223D8: 90100018                 mov     %i0, %o0
F00223DC: b0920000                 orcc    %o0, %g0, %i0
F00223E0: 32800004                 bne,a   loc_F00223F0
F00223E4: d056200c                 ldsh    [%i0+0xC], %o0
F00223E8: 10800009                 ba      locret_F002240C
F00223EC: b0102000                 mov     0, %i0
F00223F0: 80a22002                 cmp     %o0, 2
F00223F4: 02800006                 be      locret_F002240C
F00223F8: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00223FC: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F0022400: b0102000                 mov     0, %i0
F0022404: 90102026                 mov     0x26, %o0 ! '&'
F0022408: d02a6038                 stb     %o0, [%o1+0x38]
F002240C: 81c7e008                 ret
F0022410: 81e80000                 restore

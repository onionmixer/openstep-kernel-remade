F000AF70: 9de3bf98                 save    %sp, -0x68, %sp
F000AF74: d056200c                 ldsh    [%i0+0xC], %o0
F000AF78: 80a22002                 cmp     %o0, 2
F000AF7C: 0280000b                 be      loc_F000AFA8
F000AF80: 90100018                 mov     %i0, %o0
F000AF84: 1310011d92126077         set     0x40047477, %o1
F000AF8C: 4000002a                 call    _fioctl
F000AF90: 94100019                 mov     %i1, %o2
F000AF94: d2064000                 ld      [%i1], %o1
F000AF98: b0100008                 mov     %o0, %i0
F000AF9C: 92200009                 neg     %o1
F000AFA0: 10800006                 ba      locret_F000AFB8
F000AFA4: d2264000                 st      %o1, [%i1]
F000AFA8: d0062018                 ld      [%i0+0x18], %o0
F000AFAC: d052205a                 ldsh    [%o0+0x5A], %o0
F000AFB0: b0102000                 mov     0, %i0
F000AFB4: d0264000                 st      %o0, [%i1]
F000AFB8: 81c7e008                 ret
F000AFBC: 81e80000                 restore

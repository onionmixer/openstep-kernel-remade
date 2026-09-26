F0014414: 9de3bf98                 save    %sp, -0x68, %sp
F0014418: 400209dc                 call    _splusclock
F001441C: 01000000                 nop
F0014420: 80a66001                 cmp     %i1, 1
F0014424: 1280000f                 bne     loc_F0014460
F0014428: b0100008                 mov     %o0, %i0
F001442C: 113c042d                 sethi   %hi(_pmsgbuf), %o0
F0014430: d002208c                 ld      [%o0+%lo(_pmsgbuf)], %o0
F0014434: d2022008                 ld      [%o0+8], %o1
F0014438: d0022004                 ld      [%o0+4], %o0
F001443C: 80a24008                 cmp     %o1, %o0
F0014440: 02800006                 be      loc_F0014458
F0014444: 113c04d4                 sethi   -0xFECB000, %o0
F0014448: 40020a37                 call    _splx
F001444C: 90100018                 mov     %i0, %o0
F0014450: 10800007                 ba      locret_F001446C
F0014454: b0102001                 mov     1, %i0
F0014458: 400006fa                 call    _selthreadcache
F001445C: 90122184                 bset    0x184, %o0
F0014460: 40020a31                 call    _splx
F0014464: 90100018                 mov     %i0, %o0
F0014468: b0102000                 mov     0, %i0
F001446C: 81c7e008                 ret
F0014470: 81e80000                 restore

F00C14F0: 9de3bf98                 save    %sp, -0x68, %sp
F00C14F4: f027a044                 st      %i0, [%fp+arg_44]
F00C14F8: 7ffffe7f                 call    sub_F00C0EF4
F00C14FC: 9007a044                 add     %fp, arg_44, %o0
F00C1500: b0920000                 orcc    %o0, %g0, %i0
F00C1504: 0280000f                 be      locret_F00C1540
F00C1508: 01000000                 nop
F00C150C: 7fff55ab                 call    _spltty
F00C1510: 01000000                 nop
F00C1514: d20e2003                 ldub    [%i0+3], %o1
F00C1518: a0100008                 mov     %o0, %l0
F00C151C: d007a044                 ld      [%fp+arg_44], %o0
F00C1520: 4000004d                 call    _kbdkeyreleased
F00C1524: 920a607f                 and     %o1, 0x7F, %o1
F00C1528: d007a044                 ld      [%fp+arg_44], %o0
F00C152C: d20e2003                 ldub    [%i0+3], %o1
F00C1530: 7ffffe45                 call    _kbduse
F00C1534: 94100018                 mov     %i0, %o2
F00C1538: 7fff55fb                 call    _splx
F00C153C: 90100010                 mov     %l0, %o0
F00C1540: 81c7e008                 ret
F00C1544: 81e80000                 restore

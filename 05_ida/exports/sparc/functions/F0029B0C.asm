F0029B0C: 9de3bf98                 save    %sp, -0x68, %sp
F0029B10: 10800004                 ba      loc_F0029B20
F0029B14: e0060000                 ld      [%i0], %l0
F0029B18: 7fffd053                 call    _m_freem
F0029B1C: e002207c                 ld      [%o0+0x7C], %l0
F0029B20: 90940000                 orcc    %l0, %g0, %o0
F0029B24: 12bffffd                 bne     loc_F0029B18
F0029B28: 01000000                 nop
F0029B2C: c0260000                 clr     [%i0]
F0029B30: c0262004                 clr     [%i0+4]
F0029B34: c0262008                 clr     [%i0+8]
F0029B38: 81c7e008                 ret
F0029B3C: 81e80000                 restore

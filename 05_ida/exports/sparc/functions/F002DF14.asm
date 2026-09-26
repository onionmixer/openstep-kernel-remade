F002DF14: 9de3bf98                 save    %sp, -0x68, %sp
F002DF18: 4001a328                 call    _spltty
F002DF1C: 01000000                 nop
F002DF20: d206200c                 ld      [%i0+0xC], %o1
F002DF24: 80a26000                 cmp     %o1, 0
F002DF28: 02800004                 be      loc_F002DF38
F002DF2C: a0100008                 mov     %o0, %l0
F002DF30: 7fffbf4d                 call    _m_freem
F002DF34: 90100009                 mov     %o1, %o0
F002DF38: c026200c                 clr     [%i0+0xC]
F002DF3C: c02e200b                 clrb    [%i0+0xB]
F002DF40: c02e200a                 clrb    [%i0+0xA]
F002DF44: c0260000                 clr     [%i0]
F002DF48: 4001a377                 call    _splx
F002DF4C: 90100010                 mov     %l0, %o0
F002DF50: 81c7e008                 ret
F002DF54: 81e80000                 restore

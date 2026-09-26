F004FCA4: 9de3bf98                 save    %sp, -0x68, %sp
F004FCA8: e0062018                 ld      [%i0+0x18], %l0
F004FCAC: 80a42000                 cmp     %l0, 0
F004FCB0: 0280000a                 be      locret_F004FCD8
F004FCB4: c0262018                 clr     [%i0+0x18]
F004FCB8: 90100010                 mov     %l0, %o0
F004FCBC: e0042018                 ld      [%l0+0x18], %l0
F004FCC0: c0222018                 clr     [%o0+0x18]
F004FCC4: 7fff0c49                 call    _wakeup
F004FCC8: c0222014                 clr     [%o0+0x14]
F004FCCC: 80a42000                 cmp     %l0, 0
F004FCD0: 12bffffb                 bne     loc_F004FCBC
F004FCD4: 90100010                 mov     %l0, %o0
F004FCD8: 81c7e008                 ret
F004FCDC: 81e80000                 restore

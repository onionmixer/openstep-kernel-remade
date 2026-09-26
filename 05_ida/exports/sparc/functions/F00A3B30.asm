F00A3B30: 9de3bf98                 save    %sp, -0x68, %sp
F00A3B34: a0102000                 mov     0, %l0
F00A3B38: 7fffffef                 call    _isargsep
F00A3B3C: d04e0000                 ldsb    [%i0], %o0
F00A3B40: 80a22000                 cmp     %o0, 0
F00A3B44: 32800008                 bne,a   locret_F00A3B64
F00A3B48: c02e4000                 clrb    [%i1]
F00A3B4C: d00e0000                 ldub    [%i0], %o0
F00A3B50: a0042001                 inc     %l0
F00A3B54: d02e4000                 stb     %o0, [%i1]
F00A3B58: b0062001                 inc     %i0
F00A3B5C: 10bffff7                 ba      loc_F00A3B38
F00A3B60: b2066001                 inc     %i1
F00A3B64: 81c7e008                 ret
F00A3B68: 91e80010                 restore %g0, %l0, %o0

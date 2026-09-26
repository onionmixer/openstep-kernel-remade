F003AF38: 9de3bf98                 save    %sp, -0x68, %sp
F003AF3C: 80a62000                 cmp     %i0, 0
F003AF40: 0280000b                 be      locret_F003AF6C
F003AF44: 01000000                 nop
F003AF48: c4062004                 ld      [%i0+4], %g2
F003AF4C: 84060002                 add     %i0, %g2, %g2
F003AF50: c4264000                 st      %g2, [%i1]
F003AF54: c4562008                 ldsh    [%i0+8], %g2
F003AF58: c4266004                 st      %g2, [%i1+4]
F003AF5C: f0060000                 ld      [%i0], %i0
F003AF60: 80a62000                 cmp     %i0, 0
F003AF64: 12bffff9                 bne     loc_F003AF48
F003AF68: b2066008                 inc     8, %i1
F003AF6C: 81c7e008                 ret
F003AF70: 81e80000                 restore

F009BC90: 9de3bf98                 save    %sp, -0x68, %sp
F009BC94: c4064000                 ld      [%i1], %g2
F009BC98: 80a0a003                 cmp     %g2, 3
F009BC9C: 0880000d                 bleu    loc_F009BCD0
F009BCA0: 84102001                 mov     1, %g2
F009BCA4: c4260000                 st      %g2, [%i0]
F009BCA8: 84102013                 mov     0x13, %g2
F009BCAC: c4262004                 st      %g2, [%i0+4]
F009BCB0: 84102002                 mov     2, %g2
F009BCB4: c4262008                 st      %g2, [%i0+8]
F009BCB8: 84102044                 mov     0x44, %g2 ! 'D'
F009BCBC: c426200c                 st      %g2, [%i0+0xC]
F009BCC0: 84102004                 mov     4, %g2
F009BCC4: c4264000                 st      %g2, [%i1]
F009BCC8: 10800003                 ba      locret_F009BCD4
F009BCCC: b0102000                 mov     0, %i0
F009BCD0: b0102004                 mov     4, %i0
F009BCD4: 81c7e008                 ret
F009BCD8: 81e80000                 restore

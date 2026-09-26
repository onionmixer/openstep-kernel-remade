F009BCDC: 9de3bf98                 save    %sp, -0x68, %sp
F009BCE0: c4070000                 ld      [%i4], %g2
F009BCE4: 80a0a000                 cmp     %g2, 0
F009BCE8: 12800004                 bne     loc_F009BCF8
F009BCEC: 80a66001                 cmp     %i1, 1
F009BCF0: 053c0000                 sethi   -0x10000000, %g2
F009BCF4: c4270000                 st      %g2, [%i4]
F009BCF8: 1280000c                 bne     locret_F009BD28
F009BCFC: b0102000                 mov     0, %i0
F009BD00: 80a6e012                 cmp     %i3, 0x12
F009BD04: 08800009                 bleu    locret_F009BD28
F009BD08: b0102004                 mov     4, %i0
F009BD0C: f406a044                 ld      [%i2+0x44], %i2
F009BD10: 80a6a000                 cmp     %i2, 0
F009BD14: 02800003                 be      loc_F009BD20
F009BD18: 053c0000                 sethi   -0x10000000, %g2
F009BD1C: 8410001a                 mov     %i2, %g2
F009BD20: c4270000                 st      %g2, [%i4]
F009BD24: b0102000                 mov     0, %i0
F009BD28: 81c7e008                 ret
F009BD2C: 81e80000                 restore

F006DC24: 9de3bf98                 save    %sp, -0x68, %sp
F006DC28: 10800014                 ba      loc_F006DC78
F006DC2C: c44e0000                 ldsb    [%i0], %g2
F006DC30: 80a0e020                 cmp     %g3, 0x20 ! ' '
F006DC34: 02800014                 be      loc_F006DC84
F006DC38: 84100003                 mov     %g3, %g2
F006DC3C: 8400bff7                 inc     -9, %g2
F006DC40: 8408a0ff                 and     %g2, 0xFF, %g2
F006DC44: 80a0a001                 cmp     %g2, 1
F006DC48: 0880000f                 bleu    loc_F006DC84
F006DC4C: 80a0e000                 cmp     %g3, 0
F006DC50: 2280000e                 be,a    locret_F006DC88
F006DC54: b0102000                 mov     0, %i0
F006DC58: c44e0000                 ldsb    [%i0], %g2
F006DC5C: b2066001                 inc     %i1
F006DC60: 80a08003                 cmp     %g2, %g3
F006DC64: 02800004                 be      loc_F006DC74
F006DC68: b0062001                 inc     %i0
F006DC6C: 10800007                 ba      locret_F006DC88
F006DC70: b0102001                 mov     1, %i0
F006DC74: c44e0000                 ldsb    [%i0], %g2
F006DC78: 80a0a000                 cmp     %g2, 0
F006DC7C: 32bfffed                 bne,a   loc_F006DC30
F006DC80: c64e4000                 ldsb    [%i1], %g3
F006DC84: b0102000                 mov     0, %i0
F006DC88: 81c7e008                 ret
F006DC8C: 81e80000                 restore

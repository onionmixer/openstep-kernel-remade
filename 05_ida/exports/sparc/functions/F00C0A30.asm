F00C0A30: 9de3bf98                 save    %sp, -0x68, %sp
F00C0A34: b4102000                 mov     0, %i2
F00C0A38: b6102000                 mov     0, %i3
F00C0A3C: c44e0000                 ldsb    [%i0], %g2
F00C0A40: 80a0a02b                 cmp     %g2, 0x2B ! '+'
F00C0A44: 22800012                 be,a    loc_F00C0A8C
F00C0A48: b0062001                 inc     %i0
F00C0A4C: 14800009                 bg      loc_F00C0A70
F00C0A50: 80a0a02d                 cmp     %g2, 0x2D ! '-'
F00C0A54: 80a0a009                 cmp     %g2, 9
F00C0A58: 0280000b                 be      loc_F00C0A84
F00C0A5C: 80a0a020                 cmp     %g2, 0x20 ! ' '
F00C0A60: 22bffff7                 be,a    loc_F00C0A3C
F00C0A64: b0062001                 inc     %i0
F00C0A68: 10800013                 ba      loc_F00C0AB4
F00C0A6C: f20e0000                 ldub    [%i0], %i1
F00C0A70: 32800011                 bne,a   loc_F00C0AB4
F00C0A74: f20e0000                 ldub    [%i0], %i1
F00C0A78: b606e001                 inc     %i3
F00C0A7C: 10800004                 ba      loc_F00C0A8C
F00C0A80: b0062001                 inc     %i0
F00C0A84: 10bfffee                 ba      loc_F00C0A3C
F00C0A88: b0062001                 inc     %i0
F00C0A8C: 1080000a                 ba      loc_F00C0AB4
F00C0A90: f20e0000                 ldub    [%i0], %i1
F00C0A94: 852e6018                 sll     %i1, 24, %g2
F00C0A98: f20e0000                 ldub    [%i0], %i1
F00C0A9C: 872ea002                 sll     %i2, 2, %g3
F00C0AA0: 8600c01a                 add     %g3, %i2, %g3
F00C0AA4: 8728e001                 sll     %g3, 1, %g3
F00C0AA8: 8538a018                 sra     %g2, 24, %g2
F00C0AAC: 8600c002                 add     %g3, %g2, %g3
F00C0AB0: b400ffd0                 add     %g3, -0x30, %i2
F00C0AB4: 84067fd0                 add     %i1, -0x30, %g2
F00C0AB8: 8408a0ff                 and     %g2, 0xFF, %g2
F00C0ABC: 80a0a009                 cmp     %g2, 9
F00C0AC0: 28bffff5                 bleu,a  loc_F00C0A94
F00C0AC4: b0062001                 inc     %i0
F00C0AC8: 80a6e000                 cmp     %i3, 0
F00C0ACC: 02800003                 be      locret_F00C0AD8
F00C0AD0: b010001a                 mov     %i2, %i0
F00C0AD4: b0200018                 neg     %i0
F00C0AD8: 81c7e008                 ret
F00C0ADC: 81e80000                 restore

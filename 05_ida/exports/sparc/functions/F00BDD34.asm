F00BDD34: 9de3bf98                 save    %sp, -0x68, %sp
F00BDD38: c60e0000                 ldub    [%i0], %g3
F00BDD3C: b4102000                 mov     0, %i2
F00BDD40: 10800008                 ba      loc_F00BDD60
F00BDD44: b6100018                 mov     %i0, %i3
F00BDD48: 8400801a                 add     %g2, %i2, %g2
F00BDD4C: 8528a001                 sll     %g2, 1, %g2
F00BDD50: 8400bfd0                 inc     -0x30, %g2
F00BDD54: b400c002                 add     %g3, %g2, %i2
F00BDD58: b0062001                 inc     %i0
F00BDD5C: c60e0000                 ldub    [%i0], %g3
F00BDD60: 8400ffd0                 add     %g3, -0x30, %g2
F00BDD64: 8408a0ff                 and     %g2, 0xFF, %g2
F00BDD68: 80a0a009                 cmp     %g2, 9
F00BDD6C: 28bffff7                 bleu,a  loc_F00BDD48
F00BDD70: 852ea002                 sll     %i2, 2, %g2
F00BDD74: 80a6c018                 cmp     %i3, %i0
F00BDD78: 32800004                 bne,a   loc_F00BDD88
F00BDD7C: f4264000                 st      %i2, [%i1]
F00BDD80: 84103fff                 mov     -1, %g2
F00BDD84: c4264000                 st      %g2, [%i1]
F00BDD88: b026001b                 sub     %i0, %i3, %i0
F00BDD8C: 81c7e008                 ret
F00BDD90: 81e80000                 restore

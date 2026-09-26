F00D2F68: 9de3bf90                 save    %sp, -0x70, %sp
F00D2F6C: 80a6a006                 cmp     %i2, 6
F00D2F70: 08800004                 bleu    loc_F00D2F80
F00D2F74: 852ea002                 sll     %i2, 2, %g2
F00D2F78: 10800004                 ba      locret_F00D2F88
F00D2F7C: b0102000                 mov     0, %i0
F00D2F80: 84008018                 add     %g2, %i0, %g2
F00D2F84: f000a118                 ld      [%g2+0x118], %i0
F00D2F88: 81c7e008                 ret
F00D2F8C: 81e80000                 restore

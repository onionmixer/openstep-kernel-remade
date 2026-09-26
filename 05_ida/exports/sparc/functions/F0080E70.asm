F0080E70: 9de3bf98                 save    %sp, -0x68, %sp
F0080E74: c4062014                 ld      [%i0+0x14], %g2
F0080E78: 8600b448                 add     %g2, -0xBB8, %g3
F0080E7C: 80a0e015                 cmp     %g3, 0x15
F0080E80: 18800006                 bgu     loc_F0080E98
F0080E84: 053c0445                 sethi   %hi(unk_F0111738), %g2
F0080E88: 8410a338                 bset    %lo(unk_F0111738), %g2
F0080E8C: 8728e002                 sll     %g3, 2, %g3
F0080E90: 10800003                 ba      locret_F0080E9C
F0080E94: f000c002                 ld      [%g3+%g2], %i0
F0080E98: b0102000                 mov     0, %i0
F0080E9C: 81c7e008                 ret
F0080EA0: 81e80000                 restore

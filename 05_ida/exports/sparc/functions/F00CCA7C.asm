F00CCA7C: 9de3bf90                 save    %sp, -0x70, %sp
F00CCA80: c6062128                 ld      [%i0+0x128], %g3
F00CCA84: 05200000                 sethi   0x80000000, %g2
F00CCA88: b52ea01f                 sll     %i2, 31, %i2
F00CCA8C: 8428c002                 andn    %g3, %g2, %g2
F00CCA90: 8410801a                 bset    %i2, %g2
F00CCA94: c4262128                 st      %g2, [%i0+0x128]
F00CCA98: 81c7e008                 ret
F00CCA9C: 81e80000                 restore

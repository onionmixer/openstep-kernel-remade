F00C6744: 9de3bf90                 save    %sp, -0x70, %sp
F00C6748: c4062108                 ld      [%i0+0x108], %g2
F00C674C: 80a0a000                 cmp     %g2, 0
F00C6750: 22800002                 be,a    locret_F00C6758
F00C6754: f4262108                 st      %i2, [%i0+0x108]
F00C6758: 81c7e008                 ret
F00C675C: 81e80000                 restore

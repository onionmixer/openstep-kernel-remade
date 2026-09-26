F006DBE0: 9de3bf98                 save    %sp, -0x68, %sp
F006DBE4: f0060000                 ld      [%i0], %i0
F006DBE8: 07080000                 sethi   0x20000000, %g3
F006DBEC: c4062038                 ld      [%i0+0x38], %g2
F006DBF0: 80a00019                 cmp     %g0, %i1
F006DBF4: 86288003                 andn    %g2, %g3, %g3
F006DBF8: 84402000                 addc    %g0, 0, %g2
F006DBFC: 8528a01d                 sll     %g2, 29, %g2
F006DC00: 8610c002                 bset    %g2, %g3
F006DC04: c6262038                 st      %g3, [%i0+0x38]
F006DC08: 81c7e008                 ret
F006DC0C: 81e80000                 restore

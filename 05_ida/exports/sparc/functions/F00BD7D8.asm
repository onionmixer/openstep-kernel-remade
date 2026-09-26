F00BD7D8: 9de3bf90                 save    %sp, -0x70, %sp
F00BD7DC: 073c04c8                 sethi   %hi(dword_F0132064), %g3
F00BD7E0: c400e064                 ld      [%g3+%lo(dword_F0132064)], %g2
F00BD7E4: 80a0a000                 cmp     %g2, 0
F00BD7E8: 22800002                 be,a    locret_F00BD7F0
F00BD7EC: f420e064                 st      %i2, [%g3+%lo(dword_F0132064)]
F00BD7F0: 81c7e008                 ret
F00BD7F4: 81e80000                 restore

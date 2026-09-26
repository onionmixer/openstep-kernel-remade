F00BD7F8: 9de3bf90                 save    %sp, -0x70, %sp
F00BD7FC: 073c04c8                 sethi   %hi(dword_F0132064), %g3
F00BD800: c400e064                 ld      [%g3+%lo(dword_F0132064)], %g2
F00BD804: 80a0801a                 cmp     %g2, %i2
F00BD808: 22800002                 be,a    locret_F00BD810
F00BD80C: c020e064                 clr     [%g3+%lo(dword_F0132064)]
F00BD810: 81c7e008                 ret
F00BD814: 81e80000                 restore

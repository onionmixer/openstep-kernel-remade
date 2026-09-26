F00AD5B0: 9de3bf98                 save    %sp, -0x68, %sp
F00AD5B4: c4062004                 ld      [%i0+4], %g2
F00AD5B8: 80a0a001                 cmp     %g2, 1
F00AD5BC: 2280000d                 be,a    locret_F00AD5F0
F00AD5C0: 86102000                 mov     0, %g3
F00AD5C4: 0a800007                 bcs     loc_F00AD5E0
F00AD5C8: 80a0a002                 cmp     %g2, 2
F00AD5CC: 02800007                 be      loc_F00AD5E8
F00AD5D0: 80a0a003                 cmp     %g2, 3
F00AD5D4: 22800007                 be,a    locret_F00AD5F0
F00AD5D8: 86100019                 mov     %i1, %g3
F00AD5DC: 30800005                 ba,a    locret_F00AD5F0
F00AD5E0: 10800004                 ba      locret_F00AD5F0
F00AD5E4: 86102001                 mov     1, %g3
F00AD5E8: 80a00019                 cmp     %g0, %i1
F00AD5EC: 86603fff                 subc    %g0, -1, %g3
F00AD5F0: 81c7e008                 ret
F00AD5F4: 91e80003                 restore %g0, %g3, %o0

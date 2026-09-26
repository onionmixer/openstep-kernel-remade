F002BB8C: 9de3bf98                 save    %sp, -0x68, %sp
F002BB90: c4162008                 lduh    [%i0+8], %g2
F002BB94: c6062004                 ld      [%i0+4], %g3
F002BB98: 84008019                 add     %g2, %i1, %g2
F002BB9C: c4362008                 sth     %g2, [%i0+8]
F002BBA0: 8620c019                 sub     %g3, %i1, %g3
F002BBA4: c6262004                 st      %g3, [%i0+4]
F002BBA8: 81c7e008                 ret
F002BBAC: 91e82000                 restore %g0, 0, %o0

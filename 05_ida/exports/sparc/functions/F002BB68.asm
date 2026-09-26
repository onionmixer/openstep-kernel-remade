F002BB68: 9de3bf98                 save    %sp, -0x68, %sp
F002BB6C: c4162008                 lduh    [%i0+8], %g2
F002BB70: c6062004                 ld      [%i0+4], %g3
F002BB74: 84208019                 sub     %g2, %i1, %g2
F002BB78: c4362008                 sth     %g2, [%i0+8]
F002BB7C: 8600c019                 add     %g3, %i1, %g3
F002BB80: c6262004                 st      %g3, [%i0+4]
F002BB84: 81c7e008                 ret
F002BB88: 91e82000                 restore %g0, 0, %o0

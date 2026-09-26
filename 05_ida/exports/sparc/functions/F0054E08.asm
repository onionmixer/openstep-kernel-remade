F0054E08: 9de3bf98                 save    %sp, -0x68, %sp
F0054E0C: f2064000                 ld      [%i1], %i1
F0054E10: c4060000                 ld      [%i0], %g2
F0054E14: 80a08019                 cmp     %g2, %i1
F0054E18: 22800002                 be,a    locret_F0054E20
F0054E1C: b2102000                 mov     0, %i1
F0054E20: 81c7e008                 ret
F0054E24: 91e80019                 restore %g0, %i1, %o0

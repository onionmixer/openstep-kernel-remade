F002E680: 9de3bf90                 save    %sp, -0x70, %sp
F002E684: d2062004                 ld      [%i0+4], %o1
F002E688: 9007bff4                 add     %fp, var_C, %o0
F002E68C: 40000032                 call    _in_netof
F002E690: d227bff4                 st      %o1, [%fp+var_C]
F002E694: a0100008                 mov     %o0, %l0
F002E698: d2066004                 ld      [%i1+4], %o1
F002E69C: 9007bff0                 add     %fp, var_10, %o0
F002E6A0: 4000002d                 call    _in_netof
F002E6A4: d227bff0                 st      %o1, [%fp+var_10]
F002E6A8: a01c0008                 btog    %o0, %l0
F002E6AC: 80a00010                 cmp     %g0, %l0
F002E6B0: b0603fff                 subc    %g0, -1, %i0
F002E6B4: 81c7e008                 ret
F002E6B8: 81e80000                 restore

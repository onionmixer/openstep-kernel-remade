F00052C8: 9de3bf98                 save    %sp, -0x68, %sp
F00052CC: 86102000                 mov     0, %g3
F00052D0: b32e6018                 sll     %i1, 24, %i1
F00052D4: b33e6018                 sra     %i1, 24, %i1
F00052D8: c44e0000                 ldsb    [%i0], %g2
F00052DC: 80a08019                 cmp     %g2, %i1
F00052E0: 22800002                 be,a    loc_F00052E8
F00052E4: 86100018                 mov     %i0, %g3
F00052E8: 80a0a000                 cmp     %g2, 0
F00052EC: 12bffffb                 bne     loc_F00052D8
F00052F0: b0062001                 inc     %i0
F00052F4: 81c7e008                 ret
F00052F8: 91e80003                 restore %g0, %g3, %o0

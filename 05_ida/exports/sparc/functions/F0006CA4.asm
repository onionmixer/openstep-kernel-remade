F0006CA4: 80924000                 tst     %o1
F0006CA8: 32800003                 bne,a   loc_F0006CB4
F0006CAC: 9de3bfa0                 save    %sp, -0x60, %sp
F0006CB0: 30800075                 ba,a    locret_F0006E84
F0006CB4: 90100018                 mov     %i0, %o0
F0006CB8: d206c000                 ld      [%i3], %o1
F0006CBC: 40000074                 call    sub_F0006E8C
F0006CC0: 94100019                 mov     %i1, %o2
F0006CC4: 80924000                 tst     %o1
F0006CC8: 22800029                 be,a    loc_F0006D6C
F0006CCC: b2100009                 mov     %o1, %i1
F0006CD0: 90100000                 clr     %o0
F0006CD4: 903a0000                 not     %o0
F0006CD8: 10800025                 ba      loc_F0006D6C
F0006CDC: b2100009                 mov     %o1, %i1

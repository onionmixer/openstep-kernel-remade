F00BB8F8: 9de3bf98                 save    %sp, -0x68, %sp
F00BB8FC: 113c04d4                 sethi   %hi(_cons_tp), %o0
F00BB900: d0022290                 ld      [%o0+%lo(_cons_tp)], %o0
F00BB904: d44a2047                 ldsb    [%o0+0x47], %o2
F00BB908: 932aa001                 sll     %o2, 1, %o1
F00BB90C: 9202400a                 add     %o1, %o2, %o1
F00BB910: 932a6004                 sll     %o1, 4, %o1
F00BB914: 153c042e9412a0cc         set     _linesw, %o2
F00BB91C: 9202400a                 add     %o1, %o2, %o1
F00BB920: d4026008                 ld      [%o1+8], %o2
F00BB924: 9fc28000                 call    %o2
F00BB928: 92100019                 mov     %i1, %o1
F00BB92C: 81c7e008                 ret
F00BB930: 91e80008                 restore %g0, %o0, %o0

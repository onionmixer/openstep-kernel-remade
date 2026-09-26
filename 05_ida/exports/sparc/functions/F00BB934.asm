F00BB934: 9de3bf98                 save    %sp, -0x68, %sp
F00BB938: 113c04d4                 sethi   %hi(_cons_tp), %o0
F00BB93C: d0022290                 ld      [%o0+%lo(_cons_tp)], %o0
F00BB940: d44a2047                 ldsb    [%o0+0x47], %o2
F00BB944: 932aa001                 sll     %o2, 1, %o1
F00BB948: 9202400a                 add     %o1, %o2, %o1
F00BB94C: 932a6004                 sll     %o1, 4, %o1
F00BB950: 153c042e9412a0cc         set     _linesw, %o2
F00BB958: 9202400a                 add     %o1, %o2, %o1
F00BB95C: d402600c                 ld      [%o1+0xC], %o2
F00BB960: 9fc28000                 call    %o2
F00BB964: 92100019                 mov     %i1, %o1
F00BB968: 81c7e008                 ret
F00BB96C: 91e80008                 restore %g0, %o0, %o0

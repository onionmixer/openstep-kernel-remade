F00BBC34: 9de3bf98                 save    %sp, -0x68, %sp
F00BBC38: 113c04d4                 sethi   %hi(_cons_tp), %o0
F00BBC3C: d0022290                 ld      [%o0+%lo(_cons_tp)], %o0
F00BBC40: d44a2047                 ldsb    [%o0+0x47], %o2
F00BBC44: 932aa001                 sll     %o2, 1, %o1
F00BBC48: 9202400a                 add     %o1, %o2, %o1
F00BBC4C: 932a6004                 sll     %o1, 4, %o1
F00BBC50: 153c042e9412a0cc         set     _linesw, %o2
F00BBC58: 9202400a                 add     %o1, %o2, %o1
F00BBC5C: d4026028                 ld      [%o1+0x28], %o2
F00BBC60: 9fc28000                 call    %o2
F00BBC64: 92100019                 mov     %i1, %o1
F00BBC68: 81c7e008                 ret
F00BBC6C: 91e80008                 restore %g0, %o0, %o0

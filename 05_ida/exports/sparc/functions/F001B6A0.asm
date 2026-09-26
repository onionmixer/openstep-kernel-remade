F001B6A0: 9de3bf98                 save    %sp, -0x68, %sp
F001B6A4: b00e20ff                 and     %i0, 0xFF, %i0
F001B6A8: b12e2004                 sll     %i0, 4, %i0
F001B6AC: 113c04bc90122204         set     unk_F012F204, %o0
F001B6B4: b0060008                 add     %i0, %o0, %i0
F001B6B8: d0062008                 ld      [%i0+8], %o0
F001B6BC: d44a2047                 ldsb    [%o0+0x47], %o2
F001B6C0: 932aa001                 sll     %o2, 1, %o1
F001B6C4: 9202400a                 add     %o1, %o2, %o1
F001B6C8: 932a6004                 sll     %o1, 4, %o1
F001B6CC: 153c042e9412a0cc         set     _linesw, %o2
F001B6D4: 9202400a                 add     %o1, %o2, %o1
F001B6D8: d4026028                 ld      [%o1+0x28], %o2
F001B6DC: 9fc28000                 call    %o2
F001B6E0: 92100019                 mov     %i1, %o1
F001B6E4: 81c7e008                 ret
F001B6E8: 91e80008                 restore %g0, %o0, %o0

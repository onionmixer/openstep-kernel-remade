F001B384: 9de3bf98                 save    %sp, -0x68, %sp
F001B388: b00e20ff                 and     %i0, 0xFF, %i0
F001B38C: b12e2004                 sll     %i0, 4, %i0
F001B390: 113c04bc90122204         set     unk_F012F204, %o0
F001B398: b0060008                 add     %i0, %o0, %i0
F001B39C: d0062004                 ld      [%i0+4], %o0
F001B3A0: 808a2001                 btst    1, %o0
F001B3A4: 0280000f                 be      loc_F001B3E0
F001B3A8: e0062008                 ld      [%i0+8], %l0
F001B3AC: d24c2047                 ldsb    [%l0+0x47], %o1
F001B3B0: 912a6001                 sll     %o1, 1, %o0
F001B3B4: 90020009                 add     %o0, %o1, %o0
F001B3B8: 912a2004                 sll     %o0, 4, %o0
F001B3BC: 133c042e921260cc         set     _linesw, %o1
F001B3C4: 90020009                 add     %o0, %o1, %o0
F001B3C8: d2022004                 ld      [%o0+4], %o1
F001B3CC: 9fc24000                 call    %o1
F001B3D0: 90100010                 mov     %l0, %o0
F001B3D4: 7ffff272                 call    _ttyclose
F001B3D8: 90100010                 mov     %l0, %o0
F001B3DC: c0262004                 clr     [%i0+4]
F001B3E0: 90100010                 mov     %l0, %o0
F001B3E4: 400000dc                 call    _ptcwakeup
F001B3E8: 92102003                 mov     3, %o1
F001B3EC: 81c7e008                 ret
F001B3F0: 81e80000                 restore

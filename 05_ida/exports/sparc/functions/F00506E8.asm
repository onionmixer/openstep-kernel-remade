F00506E8: 9de3bf88                 save    %sp, -0x78, %sp! int
F00506EC: a0100018                 mov     %i0, %l0
F00506F0: 9010001a                 mov     %i2, %o0! int
F00506F4: 9207bff4                 add     %fp, var_C, %o1! int
F00506F8: 40011e58                 call    _copyin
F00506FC: 94102004                 mov     4, %o2
F0050700: b0920000                 orcc    %o0, %g0, %i0
F0050704: 12800021                 bne     locret_F0050788
F0050708: d007bff4                 ld      [%fp+var_C], %o0
F005070C: 400002c7                 call    sub_F0051228
F0050710: 9207bff2                 add     %fp, var_E, %o1
F0050714: b0920000                 orcc    %o0, %g0, %i0
F0050718: 1280001c                 bne     locret_F0050788
F005071C: 01000000                 nop
F0050720: 7fffdaf1                 call    _bdevvp
F0050724: d057bff2                 ldsh    [%fp+var_E], %o0
F0050728: d417bff2                 lduh    [%fp+var_E], %o2
F005072C: 9532a008                 srl     %o2, 8, %o2
F0050730: 932aa001                 sll     %o2, 1, %o1
F0050734: 9202400a                 add     %o1, %o2, %o1
F0050738: 932a6003                 sll     %o1, 3, %o1
F005073C: 153c04719412a3ac         set     _bdevsw, %o2
F0050744: 9202400a                 add     %o1, %o2, %o1
F0050748: d2026014                 ld      [%o1+0x14], %o1
F005074C: 808a6400                 btst    0x400, %o1
F0050750: 02800005                 be      loc_F0050764
F0050754: d027bfec                 st      %o0, [%fp+var_14]
F0050758: d004200c                 ld      [%l0+0xC], %o0
F005075C: 90122001                 bset    1, %o0
F0050760: d024200c                 st      %o0, [%l0+0xC]
F0050764: 9007bfec                 add     %fp, var_14, %o0
F0050768: 92100019                 mov     %i1, %o1
F005076C: 40000042                 call    sub_F0050874
F0050770: 94100010                 mov     %l0, %o2
F0050774: b0920000                 orcc    %o0, %g0, %i0
F0050778: 02800004                 be      locret_F0050788
F005077C: 01000000                 nop
F0050780: 7fff60f9                 call    _vn_rele
F0050784: d007bfec                 ld      [%fp+var_14], %o0
F0050788: 81c7e008                 ret
F005078C: 81e80000                 restore

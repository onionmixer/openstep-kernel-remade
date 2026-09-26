F001A8C0: 9de3bf98                 save    %sp, -0x68, %sp
F001A8C4: 4001f0bd                 call    _spltty
F001A8C8: 01000000                 nop
F001A8CC: d4062028                 ld      [%i0+0x28], %o2
F001A8D0: 80a2a000                 cmp     %o2, 0
F001A8D4: 0280000b                 be      loc_F001A900
F001A8D8: a0100008                 mov     %o0, %l0
F001A8DC: d2062040                 ld      [%i0+0x40], %o1
F001A8E0: 9010000a                 mov     %o2, %o0
F001A8E4: 7fffee0c                 call    _selwakeup
F001A8E8: 920a6800                 and     %o1, 0x800, %o1
F001A8EC: d2062040                 ld      [%i0+0x40], %o1
F001A8F0: 90062028                 add     %i0, 0x28, %o0 ! '('
F001A8F4: 920a77ff                 and     %o1, -0x801, %o1
F001A8F8: 7fffedf7                 call    _selthreadclear
F001A8FC: d2262040                 st      %o1, [%i0+0x40]
F001A900: 4001f109                 call    _splx
F001A904: 90100010                 mov     %l0, %o0
F001A908: 81c7e008                 ret
F001A90C: 81e80000                 restore

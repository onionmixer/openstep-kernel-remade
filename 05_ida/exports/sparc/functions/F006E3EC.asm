F006E3EC: 9de3bf90                 save    %sp, -0x70, %sp
F006E3F0: 4000a546                 call    _clock_value
F006E3F4: 90102000                 mov     0, %o0
F006E3F8: a4100008                 mov     %o0, %l2
F006E3FC: a6100009                 mov     %o1, %l3
F006E400: 110ee6b2a2122200         set     0x3B9ACA00, %l1
F006E408: a0102000                 mov     0, %l0
F006E40C: 90100012                 mov     %l2, %o0
F006E410: 92100013                 mov     %l3, %o1
F006E414: 94100010                 mov     %l0, %o2
F006E418: 96100011                 mov     %l1, %o3
F006E41C: 7ffe5e75                 call    __udivdi3
F006E420: e43fbff0                 std     %l2, [%fp+var_10]
F006E424: d03fbff0                 std     %o0, [%fp+var_10]
F006E428: 90100012                 mov     %l2, %o0
F006E42C: 92100013                 mov     %l3, %o1
F006E430: 94100010                 mov     %l0, %o2
F006E434: 96100011                 mov     %l1, %o3
F006E438: 7ffe5e64                 call    __umoddi3
F006E43C: 01000000                 nop
F006E440: d2262004                 st      %o1, [%i0+4]
F006E444: d41fbff0                 ldd     [%fp+var_10], %o2
F006E448: 921023e8                 mov     0x3E8, %o1! int
F006E44C: d0062004                 ld      [%i0+4], %o0! int
F006E450: 7ffe606e                 call    _div
F006E454: d6260000                 st      %o3, [%i0]
F006E458: d0262004                 st      %o0, [%i0+4]
F006E45C: 81c7e008                 ret
F006E460: 81e80000                 restore

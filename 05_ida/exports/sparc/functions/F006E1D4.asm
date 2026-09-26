F006E1D4: 9de3bf90                 save    %sp, -0x70, %sp
F006E1D8: 110ee6b2a2122200         set     0x3B9ACA00, %l1
F006E1E0: a0102000                 mov     0, %l0
F006E1E4: 90100018                 mov     %i0, %o0
F006E1E8: 92100019                 mov     %i1, %o1
F006E1EC: 94100010                 mov     %l0, %o2
F006E1F0: 96100011                 mov     %l1, %o3
F006E1F4: 7ffe5eff                 call    __udivdi3
F006E1F8: f03fbff0                 std     %i0, [%fp+var_10]
F006E1FC: d03fbff0                 std     %o0, [%fp+var_10]
F006E200: 90100018                 mov     %i0, %o0
F006E204: 92100019                 mov     %i1, %o1
F006E208: 94100010                 mov     %l0, %o2
F006E20C: 96100011                 mov     %l1, %o3
F006E210: 7ffe5eee                 call    __umoddi3
F006E214: 01000000                 nop
F006E218: d226a004                 st      %o1, [%i2+4]
F006E21C: d41fbff0                 ldd     [%fp+var_10], %o2
F006E220: 921023e8                 mov     0x3E8, %o1! int
F006E224: d006a004                 ld      [%i2+4], %o0! int
F006E228: 7ffe60f8                 call    _div
F006E22C: d6268000                 st      %o3, [%i2]
F006E230: d026a004                 st      %o0, [%i2+4]
F006E234: 81c7e008                 ret
F006E238: 81e80000                 restore

F0005D40: 9de3bf90                 save    %sp, -0x70, %sp
F0005D44: 80a62000                 cmp     %i0, 0
F0005D48: 16800008                 bge     loc_F0005D68
F0005D4C: a0102000                 mov     0, %l0
F0005D50: 90100018                 mov     %i0, %o0
F0005D54: 92100019                 mov     %i1, %o1
F0005D58: 7ffffd75                 call    __negdi2
F0005D5C: a0103fff                 mov     -1, %l0
F0005D60: b0100008                 mov     %o0, %i0
F0005D64: b2100009                 mov     %o1, %i1
F0005D68: 80a6a000                 cmp     %i2, 0
F0005D6C: 16800008                 bge     loc_F0005D8C
F0005D70: 01000000                 nop
F0005D74: 9010001a                 mov     %i2, %o0
F0005D78: 9210001b                 mov     %i3, %o1
F0005D7C: 7ffffd6c                 call    __negdi2
F0005D80: 01000000                 nop
F0005D84: b4100008                 mov     %o0, %i2
F0005D88: b6100009                 mov     %o1, %i3
F0005D8C: 90100018                 mov     %i0, %o0
F0005D90: 92100019                 mov     %i1, %o1
F0005D94: 9410001a                 mov     %i2, %o2
F0005D98: 9610001b                 mov     %i3, %o3
F0005D9C: 7ffffdff                 call    __udivmoddi4
F0005DA0: 9807bff0                 add     %fp, var_10, %o4
F0005DA4: 80a42000                 cmp     %l0, 0
F0005DA8: 02800006                 be      locret_F0005DC0
F0005DAC: f01fbff0                 ldd     [%fp+var_10], %i0
F0005DB0: 7ffffd5f                 call    __negdi2
F0005DB4: d01fbff0                 ldd     [%fp+var_10], %o0
F0005DB8: d03fbff0                 std     %o0, [%fp+var_10]
F0005DBC: f01fbff0                 ldd     [%fp+var_10], %i0
F0005DC0: 81c7e008                 ret
F0005DC4: 81e80000                 restore

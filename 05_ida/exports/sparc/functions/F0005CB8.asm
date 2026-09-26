F0005CB8: 9de3bf98                 save    %sp, -0x68, %sp
F0005CBC: 80a62000                 cmp     %i0, 0
F0005CC0: 16800008                 bge     loc_F0005CE0
F0005CC4: a0102000                 mov     0, %l0
F0005CC8: 90100018                 mov     %i0, %o0
F0005CCC: 92100019                 mov     %i1, %o1
F0005CD0: 7ffffd97                 call    __negdi2
F0005CD4: a0103fff                 mov     -1, %l0
F0005CD8: b0100008                 mov     %o0, %i0
F0005CDC: b2100009                 mov     %o1, %i1
F0005CE0: 80a6a000                 cmp     %i2, 0
F0005CE4: 16800008                 bge     loc_F0005D04
F0005CE8: 01000000                 nop
F0005CEC: 9010001a                 mov     %i2, %o0
F0005CF0: 9210001b                 mov     %i3, %o1
F0005CF4: 7ffffd8e                 call    __negdi2
F0005CF8: a0380010                 xnor    %g0, %l0, %l0
F0005CFC: b4100008                 mov     %o0, %i2
F0005D00: b6100009                 mov     %o1, %i3
F0005D04: 90100018                 mov     %i0, %o0
F0005D08: 92100019                 mov     %i1, %o1
F0005D0C: 9410001a                 mov     %i2, %o2
F0005D10: 9610001b                 mov     %i3, %o3
F0005D14: 7ffffe21                 call    __udivmoddi4
F0005D18: 98102000                 mov     0, %o4
F0005D1C: 80a42000                 cmp     %l0, 0
F0005D20: 02800004                 be      loc_F0005D30
F0005D24: 01000000                 nop
F0005D28: 7ffffd81                 call    __negdi2
F0005D2C: 01000000                 nop
F0005D30: b0100008                 mov     %o0, %i0
F0005D34: b2100009                 mov     %o1, %i1
F0005D38: 81c7e008                 ret
F0005D3C: 81e80000                 restore

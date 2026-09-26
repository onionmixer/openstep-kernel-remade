F0098C28: 9de3bf98                 save    %sp, -0x68, %sp
F0098C2C: 9210001a                 mov     %i2, %o1
F0098C30: 113c04f6                 sethi   %hi(_fptraprp), %o0
F0098C34: f40221d0                 ld      [%o0+%lo(_fptraprp)], %i2
F0098C38: 80a6a000                 cmp     %i2, 0
F0098C3C: 02800004                 be      loc_F0098C4C
F0098C40: 80a66003                 cmp     %i1, 3
F0098C44: 9210001a                 mov     %i2, %o1
F0098C48: c02221d0                 clr     [%o0+%lo(_fptraprp)]
F0098C4C: 0280001b                 be      loc_F0098CB8
F0098C50: 80a66003                 cmp     %i1, 3
F0098C54: 18800006                 bgu     loc_F0098C6C
F0098C58: 80a66001                 cmp     %i1, 1
F0098C5C: 2280000b                 be,a    loc_F0098C88
F0098C60: d4062020                 ld      [%i0+0x20], %o2
F0098C64: 1080001c                 ba      loc_F0098CD4
F0098C68: 113c044d                 sethi   -0xFEECC00, %o0
F0098C6C: 80a66005                 cmp     %i1, 5
F0098C70: 02800010                 be      loc_F0098CB0
F0098C74: 80a66006                 cmp     %i1, 6
F0098C78: 22800007                 be,a    loc_F0098C94
F0098C7C: d4062020                 ld      [%i0+0x20], %o2
F0098C80: 10800015                 ba      loc_F0098CD4
F0098C84: 113c044d                 sethi   -0xFEECC00, %o0
F0098C88: 90102008                 mov     8, %o0
F0098C8C: 1080000e                 ba      loc_F0098CC4
F0098C90: d606201c                 ld      [%i0+0x1C], %o3
F0098C94: 113c046e                 sethi   %hi(_beval), %o0
F0098C98: d6022024                 ld      [%o0+%lo(_beval)], %o3
F0098C9C: d8062028                 ld      [%i0+0x28], %o4
F0098CA0: 40003f1c                 call    _trap
F0098CA4: 90102009                 mov     9, %o0
F0098CA8: 1080000e                 ba      loc_F0098CE0
F0098CAC: 113c04f6                 sethi   -0xFEC2800, %o0
F0098CB0: 10800003                 ba      loc_F0098CBC
F0098CB4: 90102007                 mov     7, %o0
F0098CB8: 90102002                 mov     2, %o0
F0098CBC: d4062020                 ld      [%i0+0x20], %o2
F0098CC0: 96102000                 mov     0, %o3
F0098CC4: 40003f13                 call    _trap
F0098CC8: 98102000                 mov     0, %o4
F0098CCC: 10800005                 ba      loc_F0098CE0
F0098CD0: 113c04f6                 sethi   -0xFEC2800, %o0! char *
F0098CD4: 7ffdf127                 call    _panic
F0098CD8: 901220a8                 bset    0xA8, %o0
F0098CDC: 113c04f6                 sethi   -0xFEC2800, %o0
F0098CE0: f42221d0                 st      %i2, [%o0+0x1D0]
F0098CE4: 81c7e008                 ret
F0098CE8: 81e80000                 restore

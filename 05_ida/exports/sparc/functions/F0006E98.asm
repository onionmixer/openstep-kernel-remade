F0006E98: 9de3bf00                 save    %sp, -0x100, %sp
F0006E9C: 80968019                 orcc    %i2, %i1, %g0
F0006EA0: 1680000a                 bge     loc_F0006EC8
F0006EA4: a61e8019                 xor     %i2, %i1, %l3
F0006EA8: 80968000                 tst     %i2
F0006EAC: 16800004                 bge     loc_F0006EBC
F0006EB0: 80964000                 tst     %i1
F0006EB4: 16800005                 bge     loc_F0006EC8
F0006EB8: b420001a                 neg     %i2
F0006EBC: b0a00018                 subcc   %g0, %i0, %i0
F0006EC0: 10800002                 ba      loc_F0006EC8
F0006EC4: b2600019                 subc    %g0, %i1, %i1
F0006EC8: 80a68019                 cmp     %i2, %i1
F0006ECC: 3880000a                 bgu,a   loc_F0006EF4
F0006ED0: a2102000                 mov     0, %l1
F0006ED4: 90100019                 mov     %i1, %o0
F0006ED8: 7ffffdca                 call    _udiv
F0006EDC: 9210001a                 mov     %i2, %o1
F0006EE0: a2100008                 mov     %o0, %l1
F0006EE4: 8092c000                 tst     %o3
F0006EE8: 36800003                 bge,a   loc_F0006EF4
F0006EEC: b210000b                 mov     %o3, %i1
F0006EF0: b202c01a                 add     %o3, %i2, %i1
F0006EF4: 80964000                 tst     %i1
F0006EF8: 3280000c                 bne,a   loc_F0006F28
F0006EFC: a0102000                 mov     0, %l0
F0006F00: 90100018                 mov     %i0, %o0
F0006F04: 7ffffdbf                 call    _udiv
F0006F08: 9210001a                 mov     %i2, %o1
F0006F0C: b0100008                 mov     %o0, %i0
F0006F10: 8092c000                 tst     %o3
F0006F14: 36800003                 bge,a   loc_F0006F20
F0006F18: b410000b                 mov     %o3, %i2
F0006F1C: b402c01a                 add     %o3, %i2, %i2
F0006F20: 10800012                 ba      loc_F0006F68
F0006F24: b2100011                 mov     %l1, %i1
F0006F28: a8102020                 mov     0x20, %l4 ! ' '
F0006F2C: b0860018                 addcc   %i0, %i0, %i0
F0006F30: b2c64019                 addccc  %i1, %i1, %i1
F0006F34: 0a800005                 bcs     loc_F0006F48
F0006F38: a0040010                 add     %l0, %l0, %l0
F0006F3C: 80a6401a                 cmp     %i1, %i2
F0006F40: 2a800005                 bcs,a   loc_F0006F54
F0006F44: a8a52001                 deccc   %l4
F0006F48: b226401a                 sub     %i1, %i2, %i1
F0006F4C: a0042001                 inc     %l0
F0006F50: a8a52001                 deccc   %l4
F0006F54: 34bffff7                 bg,a    loc_F0006F30
F0006F58: b0860018                 addcc   %i0, %i0, %i0
F0006F5C: b4100019                 mov     %i1, %i2
F0006F60: b2100011                 mov     %l1, %i1
F0006F64: b0100010                 mov     %l0, %i0
F0006F68: 8094c000                 tst     %l3
F0006F6C: 16800005                 bge     locret_F0006F80
F0006F70: 01000000                 nop
F0006F74: b420001a                 neg     %i2
F0006F78: b0a00018                 subcc   %g0, %i0, %i0
F0006F7C: b2600019                 subc    %g0, %i1, %i1
F0006F80: 81c7e008                 ret
F0006F84: 81e80000                 restore

F004CDC4: 9de3bf70                 save    %sp, -0x90, %sp
F004CDC8: d0062070                 ld      [%i0+0x70], %o0
F004CDCC: a2102000                 mov     0, %l1
F004CDD0: 80a44008                 cmp     %l1, %o0
F004CDD4: 1a800033                 bcc     loc_F004CEA0
F004CDD8: a007bfe0                 add     %fp, var_20, %l0
F004CDDC: a407bfdc                 add     %fp, var_24, %l2
F004CDE0: e423a05c                 st      %l2, [%sp+0x90+var_34]
F004CDE4: 90102000                 mov     0, %o0
F004CDE8: 92100018                 mov     %i0, %o1
F004CDEC: 94100010                 mov     %l0, %o2
F004CDF0: 9610200c                 mov     0xC, %o3
F004CDF4: 98100011                 mov     %l1, %o4
F004CDF8: 40001881                 call    _rdwri
F004CDFC: 9a102001                 mov     1, %o5
F004CE00: 80a22000                 cmp     %o0, 0
F004CE04: 32800028                 bne,a   locret_F004CEA4
F004CE08: b0102000                 mov     0, %i0
F004CE0C: d007bfdc                 ld      [%fp+var_24], %o0
F004CE10: 80a22000                 cmp     %o0, 0
F004CE14: 32800024                 bne,a   locret_F004CEA4
F004CE18: b0102000                 mov     0, %i0
F004CE1C: d0142004                 lduh    [%l0+4], %o0
F004CE20: 80a22000                 cmp     %o0, 0
F004CE24: 22800020                 be,a    locret_F004CEA4
F004CE28: b0102000                 mov     0, %i0
F004CE2C: d4040000                 ld      [%l0], %o2
F004CE30: 80a2a000                 cmp     %o2, 0
F004CE34: 22800017                 be,a    loc_F004CE90
F004CE38: d2062070                 ld      [%i0+0x70], %o1
F004CE3C: d2142006                 lduh    [%l0+6], %o1
F004CE40: 80a26002                 cmp     %o1, 2
F004CE44: 38800018                 bgu,a   locret_F004CEA4
F004CE48: b0102000                 mov     0, %i0
F004CE4C: d04c2008                 ldsb    [%l0+8], %o0
F004CE50: 80a2202e                 cmp     %o0, 0x2E ! '.'
F004CE54: 32800014                 bne,a   locret_F004CEA4
F004CE58: b0102000                 mov     0, %i0
F004CE5C: 80a26001                 cmp     %o1, 1
F004CE60: 2280000b                 be,a    loc_F004CE8C
F004CE64: d0142004                 lduh    [%l0+4], %o0
F004CE68: d04c2009                 ldsb    [%l0+9], %o0
F004CE6C: 80a2202e                 cmp     %o0, 0x2E ! '.'
F004CE70: 3280000d                 bne,a   locret_F004CEA4
F004CE74: b0102000                 mov     0, %i0
F004CE78: 80a28019                 cmp     %o2, %i1
F004CE7C: 22800004                 be,a    loc_F004CE8C
F004CE80: d0142004                 lduh    [%l0+4], %o0
F004CE84: 10800008                 ba      locret_F004CEA4
F004CE88: b0102000                 mov     0, %i0
F004CE8C: d2062070                 ld      [%i0+0x70], %o1
F004CE90: a2044008                 add     %l1, %o0, %l1
F004CE94: 80a44009                 cmp     %l1, %o1
F004CE98: 2abfffd3                 bcs,a   loc_F004CDE4
F004CE9C: e423a05c                 st      %l2, [%sp+0x90+var_34]
F004CEA0: b0102001                 mov     1, %i0
F004CEA4: 81c7e008                 ret
F004CEA8: 81e80000                 restore

F0006B40: d607e008                 ld      [%i7+8], %o3
F0006B44: 980a6fff                 and     %o1, 0xFFF, %o4
F0006B48: 1b0000009a13000d         set     0, %o5
F0006B50: 80a3400b                 cmp     %o5, %o3
F0006B54: 22800004                 be,a    loc_F0006B64
F0006B58: f007a040                 ld      [%fp+arg_40], %i0
F0006B5C: 81c7e008                 ret
F0006B60: 81e80000                 restore
F0006B64: 92a26004                 deccc   4, %o1
F0006B68: d8020009                 ld      [%o0+%o1], %o4
F0006B6C: 14bffffe                 bg      loc_F0006B64
F0006B70: d8260009                 st      %o4, [%i0+%o1]
F0006B74: be07e004                 inc     4, %i7
F0006B78: 81c7e008                 ret
F0006B7C: 81e80000                 restore

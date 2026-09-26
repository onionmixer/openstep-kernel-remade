F0006B80: d607e008                 ld      [%i7+8], %o3
F0006B84: 980a6fff                 and     %o1, 0xFFF, %o4
F0006B88: 1b0000009a13000d         set     0, %o5
F0006B90: 80a3400b                 cmp     %o5, %o3
F0006B94: 22800004                 be,a    loc_F0006BA4
F0006B98: f007a040                 ld      [%fp+arg_40], %i0
F0006B9C: 81c7e008                 ret
F0006BA0: 81e80000                 restore
F0006BA4: 92a26002                 deccc   2, %o1
F0006BA8: d8120009                 lduh    [%o0+%o1], %o4
F0006BAC: 14bffffe                 bg      loc_F0006BA4
F0006BB0: d8360009                 sth     %o4, [%i0+%o1]
F0006BB4: be07e004                 inc     4, %i7
F0006BB8: 81c7e008                 ret
F0006BBC: 81e80000                 restore

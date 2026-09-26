F008AE10: 9de3bf98                 save    %sp, -0x68, %sp
F008AE14: 80a62000                 cmp     %i0, 0
F008AE18: 12800014                 bne     loc_F008AE68
F008AE1C: a0100018                 mov     %i0, %l0
F008AE20: 113c04c3                 sethi   %hi(dword_F0130F64), %o0
F008AE24: f0022364                 ld      [%o0+%lo(dword_F0130F64)], %i0
F008AE28: 90122364                 bset    %lo(dword_F0130F64), %o0
F008AE2C: 80a60008                 cmp     %i0, %o0
F008AE30: 1280000e                 bne     loc_F008AE68
F008AE34: a0100018                 mov     %i0, %l0
F008AE38: 1080001b                 ba      locret_F008AEA4
F008AE3C: b0102005                 mov     5, %i0
F008AE40: d0042030                 ld      [%l0+0x30], %o0
F008AE44: b0102000                 mov     0, %i0
F008AE48: d02e4000                 stb     %o0, [%i1]
F008AE4C: d2064000                 ld      [%i1], %o1
F008AE50: 113fc000                 sethi   -0x1000000, %o0
F008AE54: 920a4008                 and     %o1, %o0, %o1
F008AE58: 902a8008                 andn    %o2, %o0, %o0
F008AE5C: 92124008                 bset    %o0, %o1
F008AE60: 10800011                 ba      locret_F008AEA4
F008AE64: d2264000                 st      %o1, [%i1]
F008AE68: 233c04c3a4146364         set     dword_F0130F64, %l2
F008AE70: 7fffff95                 call    _vnode_pager_allocpage
F008AE74: 90100010                 mov     %l0, %o0
F008AE78: 94100008                 mov     %o0, %o2
F008AE7C: 80a2bfff                 cmp     %o2, -1
F008AE80: 12bffff0                 bne     loc_F008AE40
F008AE84: 80a40012                 cmp     %l0, %l2
F008AE88: 32800003                 bne,a   loc_F008AE94
F008AE8C: e0040000                 ld      [%l0], %l0
F008AE90: e0046364                 ld      [%l1+0x364], %l0
F008AE94: 80a60010                 cmp     %i0, %l0
F008AE98: 12bffff6                 bne     loc_F008AE70
F008AE9C: 01000000                 nop
F008AEA0: b0102005                 mov     5, %i0
F008AEA4: 81c7e008                 ret
F008AEA8: 81e80000                 restore

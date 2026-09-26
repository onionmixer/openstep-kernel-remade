F001DF48: 9de3bf98                 save    %sp, -0x68, %sp
F001DF4C: 10800003                 ba      loc_F001DF58
F001DF50: d0060000                 ld      [%i0], %o0
F001DF54: d0060000                 ld      [%i0], %o0
F001DF58: 80a22000                 cmp     %o0, 0
F001DF5C: 32bffffe                 bne,a   loc_F001DF54
F001DF60: f0060000                 ld      [%i0], %i0
F001DF64: 80a66000                 cmp     %i1, 0
F001DF68: 0280001c                 be      locret_F001DFD8
F001DF6C: 01000000                 nop
F001DF70: d2062004                 ld      [%i0+4], %o1
F001DF74: 80a2607b                 cmp     %o1, 0x7B ! '{'
F001DF78: 38800018                 bgu,a   locret_F001DFD8
F001DF7C: f2260000                 st      %i1, [%i0]
F001DF80: d6562008                 ldsh    [%i0+8], %o3
F001DF84: d4566008                 ldsh    [%i1+8], %o2! size_t
F001DF88: 9002400b                 add     %o1, %o3, %o0
F001DF8C: 9002000a                 add     %o0, %o2, %o0
F001DF90: 80a2207c                 cmp     %o0, 0x7C ! '|'
F001DF94: 08800004                 bleu    loc_F001DFA4
F001DF98: 92060009                 add     %i0, %o1, %o1
F001DF9C: 1080000f                 ba      locret_F001DFD8
F001DFA0: f2260000                 st      %i1, [%i0]
F001DFA4: d0066004                 ld      [%i1+4], %o0! void *
F001DFA8: 9202400b                 add     %o1, %o3, %o1! void *
F001DFAC: 4001dad9                 call    _bcopy
F001DFB0: 90064008                 add     %i1, %o0, %o0
F001DFB4: d2162008                 lduh    [%i0+8], %o1
F001DFB8: d4166008                 lduh    [%i1+8], %o2
F001DFBC: 90100019                 mov     %i1, %o0
F001DFC0: 9202400a                 add     %o1, %o2, %o1
F001DFC4: 7ffffebc                 call    _m_free
F001DFC8: d2362008                 sth     %o1, [%i0+8]
F001DFCC: b2920000                 orcc    %o0, %g0, %i1
F001DFD0: 32bfffe9                 bne,a   loc_F001DF74
F001DFD4: d2062004                 ld      [%i0+4], %o1
F001DFD8: 81c7e008                 ret
F001DFDC: 81e80000                 restore

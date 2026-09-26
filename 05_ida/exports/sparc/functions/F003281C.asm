F003281C: 9de3bf98                 save    %sp, -0x68, %sp
F0032820: e206200c                 ld      [%i0+0xC], %l1
F0032824: 80a44018                 cmp     %l1, %i0
F0032828: 2280000c                 be,a    loc_F0032858
F003282C: d2060000                 ld      [%i0], %o1
F0032830: e004600c                 ld      [%l1+0xC], %l0
F0032834: 4000001b                 call    _ip_deq
F0032838: 90100011                 mov     %l1, %o0
F003283C: 7fffad0a                 call    _m_freem
F0032840: 900c7f80                 and     %l1, -0x80, %o0
F0032844: a2100010                 mov     %l0, %l1
F0032848: 80a44018                 cmp     %l1, %i0
F003284C: 32bffffa                 bne,a   loc_F0032834
F0032850: e004600c                 ld      [%l1+0xC], %l0
F0032854: d2060000                 ld      [%i0], %o1
F0032858: d0062004                 ld      [%i0+4], %o0
F003285C: d0226004                 st      %o0, [%o1+4]
F0032860: d4062004                 ld      [%i0+4], %o2
F0032864: d2060000                 ld      [%i0], %o1
F0032868: 900e3f80                 and     %i0, -0x80, %o0
F003286C: 7fffac92                 call    _m_free
F0032870: d2228000                 st      %o1, [%o2]
F0032874: 81c7e008                 ret
F0032878: 81e80000                 restore

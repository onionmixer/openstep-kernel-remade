F000B778: 9de3bf98                 save    %sp, -0x68, %sp
F000B77C: e2062158                 ld      [%i0+0x158], %l1
F000B780: 80a64011                 cmp     %i1, %l1
F000B784: 0680002f                 bl      locret_F000B840
F000B788: a6066001                 add     %i1, 1, %l3
F000B78C: a12ce002                 sll     %l3, 2, %l0
F000B790: 40017238                 call    _kalloc
F000B794: 90100010                 mov     %l0, %o0
F000B798: a4100008                 mov     %o0, %l2
F000B79C: 40017235                 call    _kalloc
F000B7A0: 90100013                 mov     %l3, %o0
F000B7A4: d2062158                 ld      [%i0+0x158], %o1
F000B7A8: 80a64009                 cmp     %i1, %o1
F000B7AC: 16800009                 bge     loc_F000B7D0
F000B7B0: b2100008                 mov     %o0, %i1
F000B7B4: 90100012                 mov     %l2, %o0
F000B7B8: 4001727a                 call    _kfree
F000B7BC: 92100010                 mov     %l0, %o1
F000B7C0: 90100019                 mov     %i1, %o0
F000B7C4: 40017277                 call    _kfree
F000B7C8: 92100013                 mov     %l3, %o1! size_t
F000B7CC: 3080001d                 ba,a    locret_F000B840
F000B7D0: a2100009                 mov     %o1, %l1
F000B7D4: 90100012                 mov     %l2, %o0! void *
F000B7D8: 400225a0                 call    _bzero
F000B7DC: 92100010                 mov     %l0, %o1! size_t
F000B7E0: 90100019                 mov     %i1, %o0! void *
F000B7E4: 4002259d                 call    _bzero
F000B7E8: 92100013                 mov     %l3, %o1
F000B7EC: 80a46000                 cmp     %l1, 0
F000B7F0: 22800012                 be,a    loc_F000B838
F000B7F4: e426214c                 st      %l2, [%i0+0x14C]
F000B7F8: 92100012                 mov     %l2, %o1! void *
F000B7FC: a12c6002                 sll     %l1, 2, %l0
F000B800: d006214c                 ld      [%i0+0x14C], %o0! void *
F000B804: 400224c3                 call    _bcopy
F000B808: 94100010                 mov     %l0, %o2! size_t
F000B80C: 92100019                 mov     %i1, %o1! void *
F000B810: d0062150                 ld      [%i0+0x150], %o0! void *
F000B814: 400224bf                 call    _bcopy
F000B818: 94100011                 mov     %l1, %o2
F000B81C: d006214c                 ld      [%i0+0x14C], %o0
F000B820: 40017260                 call    _kfree
F000B824: 92100010                 mov     %l0, %o1
F000B828: d0062150                 ld      [%i0+0x150], %o0
F000B82C: 4001725d                 call    _kfree
F000B830: 92100011                 mov     %l1, %o1
F000B834: e426214c                 st      %l2, [%i0+0x14C]
F000B838: f2262150                 st      %i1, [%i0+0x150]
F000B83C: e6262158                 st      %l3, [%i0+0x158]
F000B840: 81c7e008                 ret
F000B844: 81e80000                 restore

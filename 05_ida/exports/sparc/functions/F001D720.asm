F001D720: 9de3bf98                 save    %sp, -0x68, %sp
F001D724: a2100018                 mov     %i0, %l1
F001D728: 213c0447                 sethi   %hi(_page_size), %l0
F001D72C: d204213c                 ld      [%l0+%lo(_page_size)], %o1
F001D730: 7fffa374                 call    _umul
F001D734: 90100011                 mov     %l1, %o0
F001D738: 92100008                 mov     %o0, %o1
F001D73C: 113c04d0                 sethi   %hi(_page_mask), %o0
F001D740: d40220d8                 ld      [%o0+%lo(_page_mask)], %o2
F001D744: 113c04d1                 sethi   %hi(_mb_map), %o0
F001D748: 9202400a                 add     %o1, %o2, %o1
F001D74C: d0022380                 ld      [%o0+%lo(_mb_map)], %o0
F001D750: 40019926                 call    _kmem_mb_alloc
F001D754: 922a400a                 bclr    %o2, %o1
F001D758: b0920000                 orcc    %o0, %g0, %i0
F001D75C: 12800004                 bne     loc_F001D76C
F001D760: 80a66001                 cmp     %i1, 1
F001D764: 10800047                 ba      locret_F001D880
F001D768: b0102000                 mov     0, %i0
F001D76C: 0280000b                 be      loc_F001D798
F001D770: 80a66001                 cmp     %i1, 1
F001D774: 14800006                 bg      loc_F001D78C
F001D778: 80a66002                 cmp     %i1, 2
F001D77C: 80a66000                 cmp     %i1, 0
F001D780: 02800022                 be      loc_F001D808
F001D784: d204213c                 ld      [%l0+0x13C], %o1
F001D788: 3080003e                 ba,a    locret_F001D880
F001D78C: 02800039                 be      loc_F001D870
F001D790: 133c04d2                 sethi   -0xFECB800, %o1
F001D794: 3080003b                 ba,a    locret_F001D880
F001D798: d204213c                 ld      [%l0+0x13C], %o1
F001D79C: 90100011                 mov     %l1, %o0
F001D7A0: 7fffa358                 call    _umul
F001D7A4: a0102000                 mov     0, %l0
F001D7A8: a332200a                 srl     %o0, 10, %l1
F001D7AC: 80a40011                 cmp     %l0, %l1
F001D7B0: 16800011                 bge     loc_F001D7F4
F001D7B4: 133c04d2                 sethi   -0xFECB800, %o1
F001D7B8: 153c04d2                 sethi   -0xFECB800, %o2
F001D7BC: 113c04d2921222f0         set     _mbstat, %o1
F001D7C4: c0262004                 clr     [%i0+4]
F001D7C8: a0042001                 inc     %l0
F001D7CC: d002a358                 ld      [%o2+0x358], %o0
F001D7D0: 80a40011                 cmp     %l0, %l1
F001D7D4: d0260000                 st      %o0, [%i0]
F001D7D8: f022a358                 st      %i0, [%o2+0x358]
F001D7DC: d002600c                 ld      [%o1+0xC], %o0
F001D7E0: b0062400                 inc     0x400, %i0
F001D7E4: 90022001                 inc     %o0
F001D7E8: 06bffff7                 bl      loc_F001D7C4
F001D7EC: d022600c                 st      %o0, [%o1+0xC]
F001D7F0: 133c04d2                 sethi   -0xFECB800, %o1
F001D7F4: 921262f0                 bset    0x2F0, %o1
F001D7F8: d0026004                 ld      [%o1+4], %o0
F001D7FC: 90020011                 add     %o0, %l1, %o0
F001D800: 10800020                 ba      locret_F001D880
F001D804: d0226004                 st      %o0, [%o1+4]
F001D808: 7fffa33e                 call    _umul
F001D80C: 90100011                 mov     %l1, %o0
F001D810: a1322007                 srl     %o0, 7, %l0
F001D814: 80a42000                 cmp     %l0, 0
F001D818: 0480001a                 ble     locret_F001D880
F001D81C: a6102001                 mov     1, %l3
F001D820: 233c04d2a41462f0         set     _mbstat, %l2
F001D828: b206200a                 add     %i0, 0xA, %i1
F001D82C: c0267ffa                 clr     [%i1-6]
F001D830: e6364000                 sth     %l3, [%i1]
F001D834: 90100018                 mov     %i0, %o0
F001D838: b2066080                 inc     0x80, %i1
F001D83C: b0062080                 inc     0x80, %i0
F001D840: d414a01e                 lduh    [%l2+0x1E], %o2
F001D844: a0043fff                 inc     -1, %l0
F001D848: d20462f0                 ld      [%l1+0x2F0], %o1
F001D84C: 9402a001                 inc     %o2
F001D850: d434a01e                 sth     %o2, [%l2+0x1E]
F001D854: 92026001                 inc     %o1
F001D858: 40000097                 call    _m_free
F001D85C: d22462f0                 st      %o1, [%l1+0x2F0]
F001D860: 80a42000                 cmp     %l0, 0
F001D864: 34bffff3                 bg,a    loc_F001D830
F001D868: c0267ffa                 clr     [%i1-6]
F001D86C: 30800005                 ba,a    locret_F001D880
F001D870: 921262f0                 bset    0x2F0, %o1
F001D874: d0026008                 ld      [%o1+8], %o0
F001D878: 90020011                 add     %o0, %l1, %o0
F001D87C: d0226008                 st      %o0, [%o1+8]
F001D880: 81c7e008                 ret
F001D884: 81e80000                 restore

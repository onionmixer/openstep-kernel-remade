F001E71C: 9de3bf98                 save    %sp, -0x68, %sp
F001E720: 4001e15d                 call    _splnet
F001E724: 01000000                 nop
F001E728: a2100008                 mov     %o0, %l1
F001E72C: 90100018                 mov     %i0, %o0
F001E730: 92102003                 mov     3, %o1
F001E734: d806200c                 ld      [%i0+0xC], %o4
F001E738: 94102000                 mov     0, %o2
F001E73C: da03201c                 ld      [%o4+0x1C], %o5
F001E740: 96102000                 mov     0, %o3
F001E744: 9fc34000                 call    %o5
F001E748: 98102000                 mov     0, %o4
F001E74C: a0920000                 orcc    %o0, %g0, %l0
F001E750: 22800006                 be,a    loc_F001E768
F001E754: d006201c                 ld      [%i0+0x1C], %o0
F001E758: 4001e173                 call    _splx
F001E75C: 90100011                 mov     %l1, %o0
F001E760: 10800013                 ba      locret_F001E7AC
F001E764: b0100010                 mov     %l0, %i0
F001E768: 80a22000                 cmp     %o0, 0
F001E76C: 12800007                 bne     loc_F001E788
F001E770: 80a66000                 cmp     %i1, 0
F001E774: f026201c                 st      %i0, [%i0+0x1C]
F001E778: d0162002                 lduh    [%i0+2], %o0
F001E77C: f0262014                 st      %i0, [%i0+0x14]
F001E780: 90122002                 bset    2, %o0
F001E784: d0362002                 sth     %o0, [%i0+2]
F001E788: 26800002                 bl,a    loc_F001E790
F001E78C: b2102000                 mov     0, %i1
F001E790: 80a66080                 cmp     %i1, 0x80
F001E794: 34800002                 bg,a    loc_F001E79C
F001E798: b2102080                 mov     0x80, %i1
F001E79C: f2362022                 sth     %i1, [%i0+0x22]
F001E7A0: 4001e161                 call    _splx
F001E7A4: 90100011                 mov     %l1, %o0
F001E7A8: b0102000                 mov     0, %i0
F001E7AC: 81c7e008                 ret
F001E7B0: 81e80000                 restore

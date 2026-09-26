F00ED6BC: 9de3bf98                 save    %sp, -0x68, %sp
F00ED6C0: a2100018                 mov     %i0, %l1
F00ED6C4: d0044000                 ld      [%l1], %o0
F00ED6C8: d4020000                 ld      [%o0], %o2
F00ED6CC: d0046010                 ld      [%l1+0x10], %o0
F00ED6D0: 9fc28000                 call    %o2
F00ED6D4: 92100019                 mov     %i1, %o1
F00ED6D8: 7ffc6472                 call    _urem
F00ED6DC: d2046008                 ld      [%l1+8], %o1
F00ED6E0: 912a2003                 sll     %o0, 3, %o0
F00ED6E4: d204600c                 ld      [%l1+0xC], %o1
F00ED6E8: e0020009                 ld      [%o0+%o1], %l0
F00ED6EC: 80a42000                 cmp     %l0, 0
F00ED6F0: 02800024                 be      loc_F00ED780
F00ED6F4: b0020009                 add     %o0, %o1, %i0
F00ED6F8: 80a42001                 cmp     %l0, 1
F00ED6FC: 3280001d                 bne,a   loc_F00ED770
F00ED700: f0062004                 ld      [%i0+4], %i0
F00ED704: d4062004                 ld      [%i0+4], %o2
F00ED708: 80a6400a                 cmp     %i1, %o2
F00ED70C: 2280001e                 be,a    locret_F00ED784
F00ED710: f0062004                 ld      [%i0+4], %i0
F00ED714: d0044000                 ld      [%l1], %o0
F00ED718: d6022004                 ld      [%o0+4], %o3
F00ED71C: d0046010                 ld      [%l1+0x10], %o0
F00ED720: 9fc2c000                 call    %o3
F00ED724: 92100019                 mov     %i1, %o1
F00ED728: 80a22000                 cmp     %o0, 0
F00ED72C: 22800016                 be,a    locret_F00ED784
F00ED730: b0102000                 mov     0, %i0
F00ED734: 10800014                 ba      locret_F00ED784
F00ED738: f0062004                 ld      [%i0+4], %i0
F00ED73C: 80a6400a                 cmp     %i1, %o2
F00ED740: 22800011                 be,a    locret_F00ED784
F00ED744: f0060000                 ld      [%i0], %i0
F00ED748: d0044000                 ld      [%l1], %o0
F00ED74C: d6022004                 ld      [%o0+4], %o3
F00ED750: d0046010                 ld      [%l1+0x10], %o0
F00ED754: 9fc2c000                 call    %o3
F00ED758: 92100019                 mov     %i1, %o1
F00ED75C: 80a22000                 cmp     %o0, 0
F00ED760: 22800004                 be,a    loc_F00ED770
F00ED764: b0062004                 inc     4, %i0
F00ED768: 10800007                 ba      locret_F00ED784
F00ED76C: f0060000                 ld      [%i0], %i0
F00ED770: a0043fff                 inc     -1, %l0
F00ED774: 80a43fff                 cmp     %l0, -1
F00ED778: 32bffff1                 bne,a   loc_F00ED73C
F00ED77C: d4060000                 ld      [%i0], %o2
F00ED780: b0102000                 mov     0, %i0
F00ED784: 81c7e008                 ret
F00ED788: 81e80000                 restore

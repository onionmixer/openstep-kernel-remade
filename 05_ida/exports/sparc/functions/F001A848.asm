F001A848: 9de3bf98                 save    %sp, -0x68, %sp
F001A84C: 4001f0db                 call    _spltty
F001A850: 01000000                 nop
F001A854: 80a66001                 cmp     %i1, 1
F001A858: 02800006                 be      loc_F001A870
F001A85C: a0100008                 mov     %o0, %l0
F001A860: 80a66002                 cmp     %i1, 2
F001A864: 0280000b                 be      loc_F001A890
F001A868: 01000000                 nop
F001A86C: 30800011                 ba,a    loc_F001A8B0
F001A870: 7fffedf4                 call    _selthreadcache
F001A874: 90062028                 add     %i0, 0x28, %o0 ! '('
F001A878: 80a22000                 cmp     %o0, 0
F001A87C: 0280000d                 be      loc_F001A8B0
F001A880: 01000000                 nop
F001A884: d0062040                 ld      [%i0+0x40], %o0
F001A888: 10800009                 ba      loc_F001A8AC
F001A88C: 90122800                 bset    0x800, %o0
F001A890: 7fffedec                 call    _selthreadcache
F001A894: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F001A898: 80a22000                 cmp     %o0, 0
F001A89C: 02800005                 be      loc_F001A8B0
F001A8A0: 13000004                 sethi   0x1000, %o1
F001A8A4: d0062040                 ld      [%i0+0x40], %o0
F001A8A8: 90120009                 bset    %o1, %o0
F001A8AC: d0262040                 st      %o0, [%i0+0x40]
F001A8B0: 4001f11d                 call    _splx
F001A8B4: 90100010                 mov     %l0, %o0
F001A8B8: 81c7e008                 ret
F001A8BC: 81e80000                 restore

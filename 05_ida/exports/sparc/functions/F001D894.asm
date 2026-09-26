F001D894: 9de3bf98                 save    %sp, -0x68, %sp
F001D898: a4102000                 mov     0, %l2
F001D89C: 293c04d4                 sethi   -0xFECB000, %l4
F001D8A0: 113c04d2a61222f0         set     _mbstat, %l3
F001D8A8: 90102001                 mov     1, %o0
F001D8AC: 92102000                 mov     0, %o1
F001D8B0: 7fffff9c                 call    _m_clalloc
F001D8B4: 94100018                 mov     %i0, %o2
F001D8B8: 80a22000                 cmp     %o0, 0
F001D8BC: 02800004                 be      loc_F001D8CC
F001D8C0: 80a62000                 cmp     %i0, 0
F001D8C4: 10800024                 ba      locret_F001D954
F001D8C8: b0102001                 mov     1, %i0
F001D8CC: 02800005                 be      loc_F001D8E0
F001D8D0: a404a001                 inc     %l2
F001D8D4: 80a4a001                 cmp     %l2, 1
F001D8D8: 02800004                 be      loc_F001D8E8
F001D8DC: e20522b8                 ld      [%l4+0x2B8], %l1
F001D8E0: 1080001d                 ba      locret_F001D954
F001D8E4: b0102000                 mov     0, %i0
F001D8E8: 80a46000                 cmp     %l1, 0
F001D8EC: 22800017                 be,a    loc_F001D948
F001D8F0: d004e018                 ld      [%l3+0x18], %o0
F001D8F4: e0046014                 ld      [%l1+0x14], %l0
F001D8F8: d0046018                 ld      [%l1+0x18], %o0
F001D8FC: 80a40008                 cmp     %l0, %o0
F001D900: 3a80000e                 bcc,a   loc_F001D938
F001D904: e204601c                 ld      [%l1+0x1C], %l1
F001D908: d004202c                 ld      [%l0+0x2C], %o0
F001D90C: 80a22000                 cmp     %o0, 0
F001D910: 22800005                 be,a    loc_F001D924
F001D914: d0046018                 ld      [%l1+0x18], %o0
F001D918: 9fc20000                 call    %o0
F001D91C: 01000000                 nop
F001D920: d0046018                 ld      [%l1+0x18], %o0
F001D924: a0042030                 inc     0x30, %l0 ! '0'
F001D928: 80a40008                 cmp     %l0, %o0
F001D92C: 2abffff8                 bcs,a   loc_F001D90C
F001D930: d004202c                 ld      [%l0+0x2C], %o0
F001D934: e204601c                 ld      [%l1+0x1C], %l1
F001D938: 80a46000                 cmp     %l1, 0
F001D93C: 32bfffef                 bne,a   loc_F001D8F8
F001D940: e0046014                 ld      [%l1+0x14], %l0
F001D944: d004e018                 ld      [%l3+0x18], %o0
F001D948: 90022001                 inc     %o0
F001D94C: 10bfffd7                 ba      loc_F001D8A8
F001D950: d024e018                 st      %o0, [%l3+0x18]
F001D954: 81c7e008                 ret
F001D958: 81e80000                 restore

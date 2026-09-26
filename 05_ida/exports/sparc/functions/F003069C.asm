F003069C: 9de3bf98                 save    %sp, -0x68, %sp
F00306A0: a2100018                 mov     %i0, %l1
F00306A4: 4000de73                 call    _kalloc
F00306A8: 90102040                 mov     0x40, %o0! void *
F00306AC: a0920000                 orcc    %o0, %g0, %l0
F00306B0: 0280000e                 be      locret_F00306E8
F00306B4: b0102037                 mov     0x37, %i0 ! '7'
F00306B8: 400191e8                 call    _bzero
F00306BC: 92102040                 mov     0x40, %o1 ! '@'
F00306C0: f2242008                 st      %i1, [%l0+8]
F00306C4: e224201c                 st      %l1, [%l0+0x1C]
F00306C8: d0064000                 ld      [%i1], %o0
F00306CC: d0240000                 st      %o0, [%l0]
F00306D0: f2242004                 st      %i1, [%l0+4]
F00306D4: d0064000                 ld      [%i1], %o0
F00306D8: b0102000                 mov     0, %i0
F00306DC: e0222004                 st      %l0, [%o0+4]
F00306E0: e0264000                 st      %l0, [%i1]
F00306E4: e0246008                 st      %l0, [%l1+8]
F00306E8: 81c7e008                 ret
F00306EC: 81e80000                 restore

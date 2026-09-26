F00DD414: 9de3bf80                 save    %sp, -0x80, %sp
F00DD418: d006208c                 ld      [%i0+0x8C], %o0
F00DD41C: 9206208c                 add     %i0, 0x8C, %o1
F00DD420: 80a24008                 cmp     %o1, %o0
F00DD424: 02800013                 be      loc_F00DD470
F00DD428: 96100008                 mov     %o0, %o3
F00DD42C: d002c000                 ld      [%o3], %o0
F00DD430: 80a6c008                 cmp     %i3, %o0
F00DD434: 3280000c                 bne,a   loc_F00DD464
F00DD438: d602e014                 ld      [%o3+0x14], %o3
F00DD43C: d402e004                 ld      [%o3+4], %o2
F00DD440: d002e008                 ld      [%o3+8], %o0
F00DD444: d202e00c                 ld      [%o3+0xC], %o1
F00DD448: c022e004                 clr     [%o3+4]
F00DD44C: d027bfec                 st      %o0, [%fp+var_14]
F00DD450: d227bfe8                 st      %o1, [%fp+var_18]
F00DD454: d002e010                 ld      [%o3+0x10], %o0
F00DD458: 9810000a                 mov     %o2, %o4
F00DD45C: 10800006                 ba      loc_F00DD474
F00DD460: d027bfe4                 st      %o0, [%fp+var_1C]
F00DD464: 80a2400b                 cmp     %o1, %o3
F00DD468: 32bffff2                 bne,a   loc_F00DD430
F00DD46C: d002c000                 ld      [%o3], %o0
F00DD470: 98102000                 mov     0, %o4
F00DD474: d0062004                 ld      [%i0+4], %o0! id
F00DD478: 133c0505                 sethi   %hi(paIncrementclipc), %o1
F00DD47C: d2026030                 ld      [%o1+%lo(paIncrementclipc)], %o1! SEL
F00DD480: d6062020                 ld      [%i0+0x20], %o3
F00DD484: d407bfe4                 ld      [%fp+var_1C], %o2
F00DD488: 9602c00c                 add     %o3, %o4, %o3
F00DD48C: 400050f9                 call    _objc_msgSend
F00DD490: d6262020                 st      %o3, [%i0+0x20]
F00DD494: d04e2094                 ldsb    [%i0+0x94], %o0
F00DD498: 80a22000                 cmp     %o0, 0
F00DD49C: 0280000c                 be      locret_F00DD4CC
F00DD4A0: d207bfec                 ld      [%fp+var_14], %o1
F00DD4A4: d006209c                 ld      [%i0+0x9C], %o0
F00DD4A8: a00620a4                 add     %i0, 0xA4, %l0
F00DD4AC: d6062098                 ld      [%i0+0x98], %o3
F00DD4B0: 4000147c                 call    _audio_add_peak
F00DD4B4: 94100010                 mov     %l0, %o2
F00DD4B8: d00620a0                 ld      [%i0+0xA0], %o0
F00DD4BC: d207bfe8                 ld      [%fp+var_18], %o1
F00DD4C0: d6062098                 ld      [%i0+0x98], %o3
F00DD4C4: 40001477                 call    _audio_add_peak
F00DD4C8: 94100010                 mov     %l0, %o2
F00DD4CC: 81c7e008                 ret
F00DD4D0: 81e80000                 restore

F004F334: 9de3bf98                 save    %sp, -0x68, %sp
F004F338: a0100018                 mov     %i0, %l0
F004F33C: 900c203f                 and     %l0, 0x3F, %o0
F004F340: 912a2002                 sll     %o0, 2, %o0
F004F344: 133c04ef921261c0         set     _lf_svnode_hash, %o1
F004F34C: b0020009                 add     %o0, %o1, %i0
F004F350: d0020009                 ld      [%o0+%o1], %o0
F004F354: 80a22000                 cmp     %o0, 0
F004F358: 02800013                 be      loc_F004F3A4
F004F35C: 94100018                 mov     %i0, %o2
F004F360: d2028000                 ld      [%o2], %o1
F004F364: d0024000                 ld      [%o1], %o0
F004F368: 80a40008                 cmp     %l0, %o0
F004F36C: 3280000b                 bne,a   loc_F004F398
F004F370: d002600c                 ld      [%o1+0xC], %o0
F004F374: 80a28018                 cmp     %o2, %i0
F004F378: 22800017                 be,a    locret_F004F3D4
F004F37C: f0060000                 ld      [%i0], %i0
F004F380: d002600c                 ld      [%o1+0xC], %o0
F004F384: d0228000                 st      %o0, [%o2]
F004F388: d0060000                 ld      [%i0], %o0
F004F38C: d022600c                 st      %o0, [%o1+0xC]
F004F390: 10800010                 ba      loc_F004F3D0
F004F394: d2260000                 st      %o1, [%i0]
F004F398: 80a22000                 cmp     %o0, 0
F004F39C: 12bffff1                 bne     loc_F004F360
F004F3A0: 9402600c                 add     %o1, 0xC, %o2
F004F3A4: 40006333                 call    _kalloc
F004F3A8: 90102010                 mov     0x10, %o0
F004F3AC: e0220000                 st      %l0, [%o0]
F004F3B0: c0222004                 clr     [%o0+4]
F004F3B4: c0222008                 clr     [%o0+8]
F004F3B8: d2142006                 lduh    [%l0+6], %o1
F004F3BC: 92026001                 inc     %o1
F004F3C0: d2342006                 sth     %o1, [%l0+6]
F004F3C4: d2060000                 ld      [%i0], %o1
F004F3C8: d222200c                 st      %o1, [%o0+0xC]
F004F3CC: d0260000                 st      %o0, [%i0]
F004F3D0: f0060000                 ld      [%i0], %i0
F004F3D4: 81c7e008                 ret
F004F3D8: 81e80000                 restore

F00A26BC: 9de3bf98                 save    %sp, -0x68, %sp
F00A26C0: a6100018                 mov     %i0, %l3
F00A26C4: 133c04f792126270         set     _pmap_info, %o1
F00A26CC: d00260ec                 ld      [%o1+0xEC], %o0
F00A26D0: 173c04f7                 sethi   %hi(dword_F013DE48), %o3
F00A26D4: d402e248                 ld      [%o3+%lo(dword_F013DE48)], %o2
F00A26D8: 90022001                 inc     %o0
F00A26DC: d02260ec                 st      %o0, [%o1+0xEC]
F00A26E0: 80a2a000                 cmp     %o2, 0
F00A26E4: 02800037                 be      loc_F00A27C0
F00A26E8: 9012e248                 or      %o3, %lo(dword_F013DE48), %o0
F00A26EC: 7ffffb47                 call    _del_first_pool
F00A26F0: 90023ff8                 inc     -8, %o0
F00A26F4: a2920000                 orcc    %o0, %g0, %l1
F00A26F8: 02800007                 be      loc_F00A2714
F00A26FC: 113c0464                 sethi   -0xFEE7000, %o0
F00A2700: d014601e                 lduh    [%l1+0x1E], %o0
F00A2704: 80a22000                 cmp     %o0, 0
F00A2708: 32800006                 bne,a   loc_F00A2720
F00A270C: f0046018                 ld      [%l1+0x18], %i0
F00A2710: 113c0464                 sethi   -0xFEE7000, %o0! char *
F00A2714: 7ffdca97                 call    _panic
F00A2718: 90122018                 bset    0x18, %o0
F00A271C: f0046018                 ld      [%l1+0x18], %i0
F00A2720: d014601e                 lduh    [%l1+0x1E], %o0
F00A2724: d214601c                 lduh    [%l1+0x1C], %o1
F00A2728: 90023fff                 inc     -1, %o0
F00A272C: 92027fff                 inc     -1, %o1
F00A2730: 80a27fff                 cmp     %o1, -1
F00A2734: 02800023                 be      loc_F00A27C0
F00A2738: d034601e                 sth     %o0, [%l1+0x1E]
F00A273C: 173c04f7                 sethi   -0xFEC2400, %o3
F00A2740: 153c04f7                 sethi   -0xFEC2400, %o2
F00A2744: 113c04f7a4122270         set     _pmap_info, %l2
F00A274C: a006200d                 add     %i0, 0xD, %l0
F00A2750: d0043ffb                 ld      [%l0-5], %o0
F00A2754: 80a22000                 cmp     %o0, 0
F00A2758: 32800016                 bne,a   loc_F00A27B0
F00A275C: a0042028                 inc     0x28, %l0 ! '('
F00A2760: e6243ffb                 st      %l3, [%l0-5]
F00A2764: c02c2002                 clrb    [%l0+2]
F00A2768: c0242003                 clr     [%l0+3]
F00A276C: c0242007                 clr     [%l0+7]
F00A2770: c024200b                 clr     [%l0+0xB]
F00A2774: c024200f                 clr     [%l0+0xF]
F00A2778: c0242013                 clr     [%l0+0x13]
F00A277C: f2242017                 st      %i1, [%l0+0x17]
F00A2780: d014601e                 lduh    [%l1+0x1E], %o0
F00A2784: 80a22000                 cmp     %o0, 0
F00A2788: 12800003                 bne     loc_F00A2794
F00A278C: 9012a240                 or      %o2, 0x240, %o0
F00A2790: 9012e230                 or      %o3, 0x230, %o0
F00A2794: 7ffffb0a                 call    _add_pool
F00A2798: 92100011                 mov     %l1, %o1
F00A279C: f42c0000                 stb     %i2, [%l0]
F00A27A0: d004a014                 ld      [%l2+0x14], %o0
F00A27A4: 90022001                 inc     %o0
F00A27A8: 10800009                 ba      locret_F00A27CC
F00A27AC: d024a014                 st      %o0, [%l2+0x14]
F00A27B0: 92027fff                 inc     -1, %o1
F00A27B4: 80a27fff                 cmp     %o1, -1
F00A27B8: 12bfffe6                 bne     loc_F00A2750
F00A27BC: b0062028                 inc     0x28, %i0 ! '('
F00A27C0: 113c0464                 sethi   %hi(aPmapAllocKsegE_1), %o0! "pmap_alloc_kseg_entry: zero kseg_semi_a"...
F00A27C4: 7ffdca6b                 call    _panic
F00A27C8: 90122050                 bset    %lo(aPmapAllocKsegE_1), %o0! "pmap_alloc_kseg_entry: zero kseg_semi_a"...
F00A27CC: 81c7e008                 ret
F00A27D0: 81e80000                 restore

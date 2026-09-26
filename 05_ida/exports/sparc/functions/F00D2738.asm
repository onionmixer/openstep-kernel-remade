F00D2738: 9de3bf90                 save    %sp, -0x70, %sp
F00D273C: a0100018                 mov     %i0, %l0
F00D2740: d04c21d2                 ldsb    [%l0+0x1D2], %o0
F00D2744: 80a22000                 cmp     %o0, 0
F00D2748: 32800006                 bne,a   loc_F00D2760
F00D274C: d0042184                 ld      [%l0+0x184], %o0
F00D2750: c0270000                 clr     [%i4]
F00D2754: c0274000                 clr     [%i5]
F00D2758: 10800023                 ba      locret_F00D27E4
F00D275C: b0103fff                 mov     -1, %i0
F00D2760: 80a22000                 cmp     %o0, 0
F00D2764: 32800005                 bne,a   loc_F00D2778
F00D2768: d2042188                 ld      [%l0+0x188], %o1
F00D276C: d0042164                 ld      [%l0+0x164], %o0
F00D2770: d0242184                 st      %o0, [%l0+0x184]
F00D2774: d2042188                 ld      [%l0+0x188], %o1
F00D2778: 912a6002                 sll     %o1, 2, %o0
F00D277C: 90020009                 add     %o0, %o1, %o0
F00D2780: d2042180                 ld      [%l0+0x180], %o1
F00D2784: 912a2002                 sll     %o0, 2, %o0
F00D2788: f4224008                 st      %i2, [%o1+%o0]
F00D278C: 94024008                 add     %o1, %o0, %o2! size_t
F00D2790: d002a008                 ld      [%o2+8], %o0
F00D2794: 80a22000                 cmp     %o0, 0
F00D2798: 02800004                 be      loc_F00D27A8
F00D279C: d0042184                 ld      [%l0+0x184], %o0
F00D27A0: d022a004                 st      %o0, [%o2+4]
F00D27A4: d0042184                 ld      [%l0+0x184], %o0
F00D27A8: d202a008                 ld      [%o2+8], %o1
F00D27AC: 90020009                 add     %o0, %o1, %o0
F00D27B0: d0242184                 st      %o0, [%l0+0x184]
F00D27B4: d002a004                 ld      [%o2+4], %o0
F00D27B8: d0270000                 st      %o0, [%i4]
F00D27BC: d202a008                 ld      [%o2+8], %o1
F00D27C0: 9002a00c                 add     %o2, 0xC, %o0! void *
F00D27C4: d2274000                 st      %o1, [%i5]
F00D27C8: 9210001b                 mov     %i3, %o1! void *
F00D27CC: 7fff08d1                 call    _bcopy
F00D27D0: 94102008                 mov     8, %o2
F00D27D4: f0042188                 ld      [%l0+0x188], %i0
F00D27D8: 90062001                 add     %i0, 1, %o0
F00D27DC: d0242188                 st      %o0, [%l0+0x188]
F00D27E0: b0062100                 inc     0x100, %i0
F00D27E4: 81c7e008                 ret
F00D27E8: 81e80000                 restore

F00E26DC: 9de3b798                 save    %sp, -0x868, %sp
F00E26E0: 213c04bb                 sethi   %hi(dword_F012EF60), %l0
F00E26E4: d0042360                 ld      [%l0+%lo(dword_F012EF60)], %o0
F00E26E8: 80a22000                 cmp     %o0, 0
F00E26EC: 12800039                 bne     locret_F00E27D0
F00E26F0: 01000000                 nop
F00E26F4: 7fff8e0f                 call    _IOMalloc
F00E26F8: 11000010                 sethi   0x4000, %o0
F00E26FC: d0242360                 st      %o0, [%l0+%lo(dword_F012EF60)]
F00E2700: 98102000                 mov     0, %o4
F00E2704: 113c03e59a1223c4         set     _audio_muLaw, %o5
F00E270C: 96102000                 mov     0, %o3
F00E2710: 9207b7f8                 add     %fp, var_808, %o1
F00E2714: 9407bff8                 add     %fp, var_8, %o2
F00E2718: d222bc00                 st      %o1, [%o2-0x400]
F00E271C: d8324000                 sth     %o4, [%o1]
F00E2720: 9402a004                 inc     4, %o2
F00E2724: 98032001                 inc     %o4
F00E2728: d012c00d                 lduh    [%o3+%o5], %o0
F00E272C: 80a320ff                 cmp     %o4, 0xFF
F00E2730: 912a2010                 sll     %o0, 16, %o0
F00E2734: 913a2012                 sra     %o0, 18, %o0
F00E2738: d0326002                 sth     %o0, [%o1+2]
F00E273C: 9602e002                 inc     2, %o3
F00E2740: 04bffff6                 ble     loc_F00E2718
F00E2744: 92026004                 inc     4, %o1
F00E2748: 9007bbf8                 add     %fp, var_408, %o0! __base
F00E274C: 173c038a                 sethi   %hi(sub_F00E2890), %o3! __compar
F00E2750: 92102100                 mov     0x100, %o1! __nel
F00E2754: 94102004                 mov     4, %o2! __width
F00E2758: 7ffcc5a0                 call    _qsort
F00E275C: 9612e090                 bset    %lo(sub_F00E2890), %o3
F00E2760: 98102000                 mov     0, %o4
F00E2764: 1b3ffff8                 sethi   -0x2000, %o5
F00E2768: 1f3c04bb                 sethi   -0xFED1400, %o7
F00E276C: 1100000f861223ff         set     0x3FFF, %g3
F00E2774: 9607bff8                 add     %fp, var_8, %o3
F00E2778: 8407a3f0                 add     %fp, arg_3F0, %g2
F00E277C: 80a2c002                 cmp     %o3, %g2
F00E2780: 1480000d                 bg      loc_F00E27B4
F00E2784: d002fc00                 ld      [%o3-0x400], %o0
F00E2788: d0522002                 ldsh    [%o0+2], %o0
F00E278C: d202fc04                 ld      [%o3-0x3FC], %o1
F00E2790: 94234008                 sub     %o5, %o0, %o2
F00E2794: d0526002                 ldsh    [%o1+2], %o0
F00E2798: 80a2a000                 cmp     %o2, 0
F00E279C: 04800005                 ble     loc_F00E27B0
F00E27A0: 9022000d                 sub     %o0, %o5, %o0
F00E27A4: 80a28008                 cmp     %o2, %o0
F00E27A8: 34800002                 bg,a    loc_F00E27B0
F00E27AC: 9602e004                 inc     4, %o3
F00E27B0: d002fc00                 ld      [%o3-0x400], %o0
F00E27B4: d203e360                 ld      [%o7+0x360], %o1
F00E27B8: d0120000                 lduh    [%o0], %o0
F00E27BC: d02a400c                 stb     %o0, [%o1+%o4]
F00E27C0: 98032001                 inc     %o4
F00E27C4: 80a30003                 cmp     %o4, %g3
F00E27C8: 04bfffed                 ble     loc_F00E277C
F00E27CC: 9a036001                 inc     %o5
F00E27D0: 81c7e008                 ret
F00E27D4: 81e80000                 restore

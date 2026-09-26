F00D250C: 9de3bf90                 save    %sp, -0x70, %sp
F00D2510: a2100018                 mov     %i0, %l1
F00D2514: d0046170                 ld      [%l1+0x170], %o0! id
F00D2518: 133c0504                 sethi   %hi(paLock), %o1
F00D251C: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D2520: 40007cd4                 call    _objc_msgSend
F00D2524: b0103d3e                 mov     -0x2C2, %i0
F00D2528: e0046174                 ld      [%l1+0x174], %l0
F00D252C: 90046174                 add     %l1, 0x174, %o0
F00D2530: 80a20010                 cmp     %o0, %l0
F00D2534: 22800012                 be,a    loc_F00D257C
F00D2538: d0046170                 ld      [%l1+0x170], %o0
F00D253C: 273c0504                 sethi   %hi(paSetcharvaluesF_0), %l3
F00D2540: a4100008                 mov     %o0, %l2
F00D2544: d204e2d8                 ld      [%l3+%lo(paSetcharvaluesF_0)], %o1! SEL
F00D2548: 9410001a                 mov     %i2, %o2
F00D254C: d0040000                 ld      [%l0], %o0! id
F00D2550: 9610001b                 mov     %i3, %o3
F00D2554: e0042004                 ld      [%l0+4], %l0
F00D2558: 40007cc6                 call    _objc_msgSend
F00D255C: 9810001c                 mov     %i4, %o4
F00D2560: 80a23d3e                 cmp     %o0, -0x2C2
F00D2564: 32800002                 bne,a   loc_F00D256C
F00D2568: b0100008                 mov     %o0, %i0
F00D256C: 80a48010                 cmp     %l2, %l0
F00D2570: 32bffff6                 bne,a   loc_F00D2548
F00D2574: d204e2d8                 ld      [%l3+0x2D8], %o1
F00D2578: d0046170                 ld      [%l1+0x170], %o0! id
F00D257C: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D2580: 40007cbc                 call    _objc_msgSend
F00D2584: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D2588: 80a63d3e                 cmp     %i0, -0x2C2
F00D258C: 1280000d                 bne     locret_F00D25C0
F00D2590: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D2594: e227bff0                 st      %l1, [%fp+var_10]
F00D2598: 9410001a                 mov     %i2, %o2
F00D259C: 9610001b                 mov     %i3, %o3
F00D25A0: 133c0508                 sethi   %hi(stru_F01421DC.super_class), %o1
F00D25A4: da0261e0                 ld      [%o1+%lo(stru_F01421DC.super_class)], %o5
F00D25A8: 9810001c                 mov     %i4, %o4
F00D25AC: 133c0504                 sethi   %hi(paSetcharvaluesF_0), %o1
F00D25B0: d20262d8                 ld      [%o1+%lo(paSetcharvaluesF_0)], %o1! SEL
F00D25B4: 40007cf2                 call    _objc_msgSendSuper
F00D25B8: da27bff4                 st      %o5, [%fp+var_C]
F00D25BC: b0100008                 mov     %o0, %i0
F00D25C0: 81c7e008                 ret
F00D25C4: 81e80000                 restore

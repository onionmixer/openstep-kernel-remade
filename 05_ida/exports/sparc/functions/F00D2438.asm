F00D2438: 9de3bf88                 save    %sp, -0x78, %sp
F00D243C: a2103d3e                 mov     -0x2C2, %l1
F00D2440: d0062170                 ld      [%i0+0x170], %o0! id
F00D2444: c027bfec                 clr     [%fp+var_14]
F00D2448: d4070000                 ld      [%i4], %o2
F00D244C: 133c0504                 sethi   %hi(paLock), %o1
F00D2450: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D2454: 40007d07                 call    _objc_msgSend
F00D2458: d427bfec                 st      %o2, [%fp+var_14]
F00D245C: e0062174                 ld      [%i0+0x174], %l0
F00D2460: 90062174                 add     %i0, 0x174, %o0
F00D2464: 80a20010                 cmp     %o0, %l0
F00D2468: 22800013                 be,a    loc_F00D24B4
F00D246C: d0062170                 ld      [%i0+0x170], %o0
F00D2470: 273c0504                 sethi   %hi(paGetcharvaluesF_0), %l3
F00D2474: a4100008                 mov     %o0, %l2
F00D2478: d204e2d0                 ld      [%l3+%lo(paGetcharvaluesF_0)], %o1! SEL
F00D247C: 9410001a                 mov     %i2, %o2
F00D2480: d0040000                 ld      [%l0], %o0! id
F00D2484: 9610001b                 mov     %i3, %o3
F00D2488: e0042004                 ld      [%l0+4], %l0
F00D248C: 40007cf9                 call    _objc_msgSend
F00D2490: 9807bfec                 add     %fp, var_14, %o4
F00D2494: 80a23d3e                 cmp     %o0, -0x2C2
F00D2498: 02800004                 be      loc_F00D24A8
F00D249C: 80a48010                 cmp     %l2, %l0
F00D24A0: 10800004                 ba      loc_F00D24B0
F00D24A4: a2100008                 mov     %o0, %l1
F00D24A8: 32bffff5                 bne,a   loc_F00D247C
F00D24AC: d204e2d0                 ld      [%l3+0x2D0], %o1
F00D24B0: d0062170                 ld      [%i0+0x170], %o0! id
F00D24B4: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D24B8: 40007cee                 call    _objc_msgSend
F00D24BC: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D24C0: 80a47d3e                 cmp     %l1, -0x2C2
F00D24C4: 1280000f                 bne     loc_F00D2500
F00D24C8: d007bfec                 ld      [%fp+var_14], %o0
F00D24CC: f027bff0                 st      %i0, [%fp+var_10]
F00D24D0: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D24D4: 9410001a                 mov     %i2, %o2
F00D24D8: 9610001b                 mov     %i3, %o3
F00D24DC: 133c0508                 sethi   %hi(stru_F01421DC.super_class), %o1
F00D24E0: da0261e0                 ld      [%o1+%lo(stru_F01421DC.super_class)], %o5
F00D24E4: 9807bfec                 add     %fp, var_14, %o4
F00D24E8: 133c0504                 sethi   %hi(paGetcharvaluesF_0), %o1
F00D24EC: d20262d0                 ld      [%o1+%lo(paGetcharvaluesF_0)], %o1! SEL
F00D24F0: 40007d23                 call    _objc_msgSendSuper
F00D24F4: da27bff4                 st      %o5, [%fp+var_C]
F00D24F8: a2100008                 mov     %o0, %l1
F00D24FC: d007bfec                 ld      [%fp+var_14], %o0
F00D2500: d0270000                 st      %o0, [%i4]
F00D2504: 81c7e008                 ret
F00D2508: 91e80011                 restore %g0, %l1, %o0

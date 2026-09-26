F00A7380: 9de3bef0                 save    %sp, -0x110, %sp
F00A7384: 113c0506                 sethi   %hi(paScsidisk_0), %o0
F00A7388: d002229c                 ld      [%o0+%lo(paScsidisk_0)], %o0! id
F00A738C: 133c0504                 sethi   %hi(paRequiredprotoc), %o1! SEL
F00A7390: 40012938                 call    _objc_msgSend
F00A7394: d2026204                 ld      [%o1+%lo(paRequiredprotoc)], %o1
F00A7398: a4920000                 orcc    %o0, %g0, %l2
F00A739C: 02800033                 be      locret_F00A7468
F00A73A0: b0102001                 mov     1, %i0
F00A73A4: d0048000                 ld      [%l2], %o0
F00A73A8: 80a22000                 cmp     %o0, 0
F00A73AC: 0280002f                 be      locret_F00A7468
F00A73B0: a2102000                 mov     0, %l1
F00A73B4: 2b3c0506                 sethi   -0xFEBE800, %l5
F00A73B8: a607bfa8                 add     %fp, var_58, %l3
F00A73BC: 293c0504                 sethi   -0xFEBF000, %l4
F00A73C0: 94100011                 mov     %l1, %o2
F00A73C4: 133c0504                 sethi   %hi(paLookupbyobject_0), %o1
F00A73C8: d0056270                 ld      [%l5+0x270], %o0! id
F00A73CC: 9607bf58                 add     %fp, var_A8, %o3
F00A73D0: d2026140                 ld      [%o1+%lo(paLookupbyobject_0)], %o1! SEL
F00A73D4: 40012927                 call    _objc_msgSend
F00A73D8: 98100013                 mov     %l3, %o4
F00A73DC: 80a22000                 cmp     %o0, 0
F00A73E0: 02800004                 be      loc_F00A73F0
F00A73E4: 80a23d29                 cmp     %o0, -0x2D7
F00A73E8: 12800020                 bne     locret_F00A7468
F00A73EC: b0102000                 mov     0, %i0
F00A73F0: 90100013                 mov     %l3, %o0
F00A73F4: 4000748b                 call    _IOGetObjectForDeviceName
F00A73F8: 9207bf54                 add     %fp, var_AC, %o1
F00A73FC: 80a22000                 cmp     %o0, 0
F00A7400: 32bffff0                 bne,a   loc_F00A73C0
F00A7404: a2046001                 inc     %l1
F00A7408: d0048000                 ld      [%l2], %o0
F00A740C: 80a22000                 cmp     %o0, 0
F00A7410: 0280000f                 be      loc_F00A744C
F00A7414: a0102001                 mov     1, %l0
F00A7418: b0100012                 mov     %l2, %i0
F00A741C: d007bf54                 ld      [%fp+var_AC], %o0! id
F00A7420: d2052018                 ld      [%l4+0x18], %o1! SEL
F00A7424: 40012913                 call    _objc_msgSend
F00A7428: d4060000                 ld      [%i0], %o2
F00A742C: 912a2018                 sll     %o0, 24, %o0
F00A7430: 80a22000                 cmp     %o0, 0
F00A7434: 0280000b                 be      loc_F00A7460
F00A7438: b0062004                 inc     4, %i0
F00A743C: d0060000                 ld      [%i0], %o0
F00A7440: 80a22000                 cmp     %o0, 0
F00A7444: 12bffff7                 bne     loc_F00A7420
F00A7448: d007bf54                 ld      [%fp+var_AC], %o0
F00A744C: 80a42000                 cmp     %l0, 0
F00A7450: 02bfffdc                 be      loc_F00A73C0
F00A7454: a2046001                 inc     %l1
F00A7458: 10800004                 ba      locret_F00A7468
F00A745C: b0102001                 mov     1, %i0
F00A7460: 10bffffb                 ba      loc_F00A744C
F00A7464: a0102000                 mov     0, %l0
F00A7468: 81c7e008                 ret
F00A746C: 81e80000                 restore

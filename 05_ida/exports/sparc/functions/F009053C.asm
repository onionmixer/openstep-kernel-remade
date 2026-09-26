F009053C: 9de3bf90                 save    %sp, -0x70, %sp
F0090540: ec07a05c                 ld      [%fp+arg_5C], %l6
F0090544: 80a62000                 cmp     %i0, 0
F0090548: 12800004                 bne     loc_F0090558
F009054C: ee07a064                 ld      [%fp+arg_64], %l7
F0090550: 1080009c                 ba      locret_F00907C0
F0090554: b0103d3f                 mov     -0x2C1, %i0
F0090558: 113c0504                 sethi   %hi(paDevicedescript_1), %o0! id
F009055C: d2022158                 ld      [%o0+%lo(paDevicedescript_1)], %o1! SEL
F0090560: 400184c4                 call    _objc_msgSend
F0090564: 90100018                 mov     %i0, %o0! id
F0090568: aa100008                 mov     %o0, %l5
F009056C: 133c0504                 sethi   %hi(paResourcesforke), %o1
F0090570: 153c0448                 sethi   %hi(aIrqLevels_1), %o2! "IRQ Levels"
F0090574: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F0090578: 400184be                 call    _objc_msgSend
F009057C: 9412a160                 bset    %lo(aIrqLevels_1), %o2! "IRQ Levels"
F0090580: a4100008                 mov     %o0, %l2
F0090584: 113c0504                 sethi   %hi(paCount_0), %o0! id
F0090588: d20220b8                 ld      [%o0+%lo(paCount_0)], %o1! SEL
F009058C: 400184b9                 call    _objc_msgSend
F0090590: 90100012                 mov     %l2, %o0
F0090594: a0100008                 mov     %o0, %l0
F0090598: 80a42007                 cmp     %l0, 7
F009059C: 34800002                 bg,a    loc_F00905A4
F00905A0: a0102007                 mov     7, %l0
F00905A4: b0102000                 mov     0, %i0
F00905A8: 80a60010                 cmp     %i0, %l0
F00905AC: 36800011                 bge,a   loc_F00905F0
F00905B0: e0268000                 st      %l0, [%i2]
F00905B4: 293c0504                 sethi   -0xFEBF000, %l4
F00905B8: 273c0504                 sethi   -0xFEBF000, %l3
F00905BC: a2102000                 mov     0, %l1
F00905C0: 90100012                 mov     %l2, %o0! id
F00905C4: d20520c8                 ld      [%l4+0xC8], %o1! SEL
F00905C8: 400184aa                 call    _objc_msgSend
F00905CC: 94100018                 mov     %i0, %o2
F00905D0: d204e11c                 ld      [%l3+0x11C], %o1! SEL
F00905D4: 400184a7                 call    _objc_msgSend
F00905D8: b0062001                 inc     %i0
F00905DC: d0244019                 st      %o0, [%l1+%i1]
F00905E0: 80a60010                 cmp     %i0, %l0
F00905E4: 06bffff7                 bl      loc_F00905C0
F00905E8: a2046004                 inc     4, %l1
F00905EC: e0268000                 st      %l0, [%i2]
F00905F0: 90100015                 mov     %l5, %o0! id
F00905F4: 133c0504                 sethi   %hi(paResourcesforke), %o1
F00905F8: 153c0448                 sethi   %hi(aDmaChannels), %o2! "DMA Channels"
F00905FC: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F0090600: 4001849c                 call    _objc_msgSend
F0090604: 9412a170                 bset    %lo(aDmaChannels), %o2! "DMA Channels"
F0090608: a4100008                 mov     %o0, %l2
F009060C: 113c0504                 sethi   %hi(paCount_0), %o0! id
F0090610: d20220b8                 ld      [%o0+%lo(paCount_0)], %o1! SEL
F0090614: 40018497                 call    _objc_msgSend
F0090618: 90100012                 mov     %l2, %o0
F009061C: a0100008                 mov     %o0, %l0
F0090620: 80a42004                 cmp     %l0, 4
F0090624: 34800002                 bg,a    loc_F009062C
F0090628: a0102004                 mov     4, %l0
F009062C: b0102000                 mov     0, %i0
F0090630: 80a60010                 cmp     %i0, %l0
F0090634: 36800011                 bge,a   loc_F0090678
F0090638: e0270000                 st      %l0, [%i4]
F009063C: 273c0504                 sethi   -0xFEBF000, %l3
F0090640: 233c0504                 sethi   -0xFEBF000, %l1
F0090644: b2102000                 mov     0, %i1
F0090648: 90100012                 mov     %l2, %o0! id
F009064C: d204e0c8                 ld      [%l3+0xC8], %o1! SEL
F0090650: 40018488                 call    _objc_msgSend
F0090654: 94100018                 mov     %i0, %o2
F0090658: d204611c                 ld      [%l1+0x11C], %o1! SEL
F009065C: 40018485                 call    _objc_msgSend
F0090660: b0062001                 inc     %i0
F0090664: d026401b                 st      %o0, [%i1+%i3]
F0090668: 80a60010                 cmp     %i0, %l0
F009066C: 06bffff7                 bl      loc_F0090648
F0090670: b2066004                 inc     4, %i1
F0090674: e0270000                 st      %l0, [%i4]
F0090678: 90100015                 mov     %l5, %o0! id
F009067C: 133c0504                 sethi   %hi(paResourcesforke), %o1
F0090680: 153c0448                 sethi   %hi(aIOPorts), %o2! "I/O Ports"
F0090684: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F0090688: 4001847a                 call    _objc_msgSend
F009068C: 9412a180                 bset    %lo(aIOPorts), %o2! "I/O Ports"
F0090690: a4100008                 mov     %o0, %l2
F0090694: 113c0504                 sethi   %hi(paCount_0), %o0! id
F0090698: d20220b8                 ld      [%o0+%lo(paCount_0)], %o1! SEL
F009069C: 40018475                 call    _objc_msgSend
F00906A0: 90100012                 mov     %l2, %o0
F00906A4: a0100008                 mov     %o0, %l0
F00906A8: 80a42014                 cmp     %l0, 0x14
F00906AC: 34800002                 bg,a    loc_F00906B4
F00906B0: a0102014                 mov     0x14, %l0
F00906B4: b0102000                 mov     0, %i0
F00906B8: 80a60010                 cmp     %i0, %l0
F00906BC: 36800017                 bge,a   loc_F0090718
F00906C0: e0258000                 st      %l0, [%l6]
F00906C4: 293c0504                 sethi   -0xFEBF000, %l4
F00906C8: 273c0504                 sethi   -0xFEBF000, %l3
F00906CC: a207bff0                 add     %fp, var_10, %l1
F00906D0: 90100012                 mov     %l2, %o0! id
F00906D4: d20520c8                 ld      [%l4+0xC8], %o1! SEL
F00906D8: 40018466                 call    _objc_msgSend
F00906DC: 94100018                 mov     %i0, %o2
F00906E0: d204e058                 ld      [%l3+0x58], %o1! SEL
F00906E4: e223a040                 st      %l1, [%sp+0x70+var_30]
F00906E8: 40018462                 call    _objc_msgSend
F00906EC: 01000000                 nop
F00906F0: 00000008                 illtrap
F00906F4: d007bff0                 ld      [%fp+var_10], %o0
F00906F8: b0062001                 inc     %i0
F00906FC: d0274000                 st      %o0, [%i5]
F0090700: d007bff4                 ld      [%fp+var_C], %o0
F0090704: 80a60010                 cmp     %i0, %l0
F0090708: d0276004                 st      %o0, [%i5+4]
F009070C: 06bffff1                 bl      loc_F00906D0
F0090710: ba076008                 inc     8, %i5
F0090714: e0258000                 st      %l0, [%l6]
F0090718: 90100015                 mov     %l5, %o0! id
F009071C: 133c0504                 sethi   %hi(paResourcesforke), %o1
F0090720: 153c0448                 sethi   %hi(aMemoryMaps_0), %o2! "Memory Maps"
F0090724: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F0090728: 40018452                 call    _objc_msgSend
F009072C: 9412a190                 bset    %lo(aMemoryMaps_0), %o2! "Memory Maps"
F0090730: a4100008                 mov     %o0, %l2
F0090734: 113c0504                 sethi   %hi(paCount_0), %o0! id
F0090738: d20220b8                 ld      [%o0+%lo(paCount_0)], %o1! SEL
F009073C: 4001844d                 call    _objc_msgSend
F0090740: 90100012                 mov     %l2, %o0
F0090744: a0100008                 mov     %o0, %l0
F0090748: 80a42009                 cmp     %l0, 9
F009074C: 34800002                 bg,a    loc_F0090754
F0090750: a0102009                 mov     9, %l0
F0090754: b0102000                 mov     0, %i0
F0090758: 80a60010                 cmp     %i0, %l0
F009075C: 36800019                 bge,a   locret_F00907C0
F0090760: e025c000                 st      %l0, [%l7]
F0090764: 293c0504                 sethi   -0xFEBF000, %l4
F0090768: 273c0504                 sethi   -0xFEBF000, %l3
F009076C: a207bff0                 add     %fp, var_10, %l1
F0090770: f207a060                 ld      [%fp+arg_60], %i1
F0090774: 90100012                 mov     %l2, %o0! id
F0090778: d20520c8                 ld      [%l4+0xC8], %o1! SEL
F009077C: 4001843d                 call    _objc_msgSend
F0090780: 94100018                 mov     %i0, %o2
F0090784: d204e058                 ld      [%l3+0x58], %o1! SEL
F0090788: e223a040                 st      %l1, [%sp+0x70+var_30]
F009078C: 40018439                 call    _objc_msgSend
F0090790: 01000000                 nop
F0090794: 00000008                 illtrap
F0090798: d007bff0                 ld      [%fp+var_10], %o0
F009079C: b0062001                 inc     %i0
F00907A0: d0264000                 st      %o0, [%i1]
F00907A4: d007bff4                 ld      [%fp+var_C], %o0
F00907A8: 80a60010                 cmp     %i0, %l0
F00907AC: d0266004                 st      %o0, [%i1+4]
F00907B0: 06bffff1                 bl      loc_F0090774
F00907B4: b2066008                 inc     8, %i1
F00907B8: e025c000                 st      %l0, [%l7]
F00907BC: b0102000                 mov     0, %i0
F00907C0: 81c7e008                 ret
F00907C4: 81e80000                 restore

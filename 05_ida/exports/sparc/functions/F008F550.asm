F008F550: 9de3bf90                 save    %sp, -0x70, %sp
F008F554: 90100018                 mov     %i0, %o0! id
F008F558: 133c0504                 sethi   %hi(paIsshared), %o1
F008F55C: d2026120                 ld      [%o1+%lo(paIsshared)], %o1! SEL
F008F560: 400188c4                 call    _objc_msgSend
F008F564: 9410001c                 mov     %i4, %o2
F008F568: ac100008                 mov     %o0, %l6
F008F56C: 90100018                 mov     %i0, %o0! id
F008F570: 133c0504                 sethi   %hi(paResourcesforke), %o1
F008F574: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F008F578: 400188be                 call    _objc_msgSend
F008F57C: 9410001c                 mov     %i4, %o2
F008F580: aa100008                 mov     %o0, %l5
F008F584: 113c0506                 sethi   %hi(paList), %o0
F008F588: e4022288                 ld      [%o0+%lo(paList)], %l2
F008F58C: 113c0503                 sethi   %hi(paAlloc), %o0
F008F590: e20223f0                 ld      [%o0+%lo(paAlloc)], %l1
F008F594: 90100012                 mov     %l2, %o0! id
F008F598: 400188b6                 call    _objc_msgSend
F008F59C: 92100011                 mov     %l1, %o1
F008F5A0: 133c0504                 sethi   %hi(paInit), %o1! SEL
F008F5A4: e002602c                 ld      [%o1+%lo(paInit)], %l0
F008F5A8: a6102000                 mov     0, %l3
F008F5AC: 400188b1                 call    _objc_msgSend
F008F5B0: 92100010                 mov     %l0, %o1! SEL
F008F5B4: a8100008                 mov     %o0, %l4
F008F5B8: 90100012                 mov     %l2, %o0! id
F008F5BC: 400188ad                 call    _objc_msgSend
F008F5C0: 92100011                 mov     %l1, %o1! SEL
F008F5C4: 400188ab                 call    _objc_msgSend
F008F5C8: 92100010                 mov     %l0, %o1
F008F5CC: 80a4c01b                 cmp     %l3, %i3
F008F5D0: 1a80002e                 bcc     loc_F008F688
F008F5D4: a4100008                 mov     %o0, %l2
F008F5D8: 912da018                 sll     %l6, 24, %o0
F008F5DC: af3a2018                 sra     %o0, 24, %l7
F008F5E0: 2d3c0504                 sethi   %hi(paAddobject), %l6
F008F5E4: e205a0a4                 ld      [%l6+%lo(paAddobject)], %l1
F008F5E8: d2068000                 ld      [%i2], %o1
F008F5EC: 7fffffbf                 call    sub_F008F4E8
F008F5F0: 90100015                 mov     %l5, %o0
F008F5F4: a0920000                 orcc    %o0, %g0, %l0
F008F5F8: 02800004                 be      loc_F008F608
F008F5FC: 90100014                 mov     %l4, %o0
F008F600: 1080001c                 ba      loc_F008F670
F008F604: d205a0a4                 ld      [%l6+0xA4], %o1
F008F608: d006201c                 ld      [%i0+0x1C], %o0! id
F008F60C: 133c0504                 sethi   %hi(paLookupresource), %o1
F008F610: d2026128                 ld      [%o1+%lo(paLookupresource)], %o1! SEL
F008F614: 40018897                 call    _objc_msgSend
F008F618: 9410001c                 mov     %i4, %o2
F008F61C: 96920000                 orcc    %o0, %g0, %o3
F008F620: 02800044                 be      loc_F008F730
F008F624: 80a5e000                 cmp     %l7, 0
F008F628: 02800005                 be      loc_F008F63C
F008F62C: 113c0504                 sethi   -0xFEBF000, %o0
F008F630: 113c0504                 sethi   %hi(paShareitem), %o0! id
F008F634: 10800003                 ba      loc_F008F640
F008F638: d202212c                 ld      [%o0+%lo(paShareitem)], %o1
F008F63C: d2022130                 ld      [%o0+0x130], %o1! SEL
F008F640: d4068000                 ld      [%i2], %o2
F008F644: 4001888b                 call    _objc_msgSend
F008F648: 9010000b                 mov     %o3, %o0
F008F64C: a0920000                 orcc    %o0, %g0, %l0
F008F650: 02800039                 be      loc_F008F734
F008F654: 113c0504                 sethi   -0xFEBF000, %o0
F008F658: 90100012                 mov     %l2, %o0! id
F008F65C: 92100011                 mov     %l1, %o1! SEL
F008F660: 40018884                 call    _objc_msgSend
F008F664: 94100010                 mov     %l0, %o2
F008F668: 90100014                 mov     %l4, %o0! id
F008F66C: 92100011                 mov     %l1, %o1! SEL
F008F670: 40018880                 call    _objc_msgSend
F008F674: 94100010                 mov     %l0, %o2
F008F678: a604e001                 inc     %l3
F008F67C: 80a4c01b                 cmp     %l3, %i3
F008F680: 0abfffda                 bcs     loc_F008F5E8
F008F684: b406a004                 inc     4, %i2
F008F688: a6102000                 mov     0, %l3
F008F68C: 373c0504                 sethi   -0xFEBF000, %i3
F008F690: 353c0504                 sethi   -0xFEBF000, %i2
F008F694: 2d3c0504                 sethi   -0xFEBF000, %l6
F008F698: 233c0503                 sethi   -0xFEBF400, %l1
F008F69C: d206e0b8                 ld      [%i3+0xB8], %o1! SEL
F008F6A0: 40018874                 call    _objc_msgSend
F008F6A4: 90100015                 mov     %l5, %o0
F008F6A8: 80a4c008                 cmp     %l3, %o0
F008F6AC: 1a800012                 bcc     loc_F008F6F4
F008F6B0: 90100015                 mov     %l5, %o0! id
F008F6B4: d206a0c8                 ld      [%i2+0xC8], %o1! SEL
F008F6B8: 4001886e                 call    _objc_msgSend
F008F6BC: 94100013                 mov     %l3, %o2
F008F6C0: a0100008                 mov     %o0, %l0
F008F6C4: 90100014                 mov     %l4, %o0! id
F008F6C8: d205a0a0                 ld      [%l6+0xA0], %o1! SEL
F008F6CC: 40018869                 call    _objc_msgSend
F008F6D0: 94100010                 mov     %l0, %o2
F008F6D4: 80a23fff                 cmp     %o0, -1
F008F6D8: 32bffff1                 bne,a   loc_F008F69C
F008F6DC: a604e001                 inc     %l3
F008F6E0: d20463fc                 ld      [%l1+0x3FC], %o1! SEL
F008F6E4: 40018863                 call    _objc_msgSend
F008F6E8: 90100010                 mov     %l0, %o0
F008F6EC: 10bfffec                 ba      loc_F008F69C
F008F6F0: a604e001                 inc     %l3
F008F6F4: 113c0504                 sethi   %hi(paEmpty), %o0! id
F008F6F8: d20220fc                 ld      [%o0+%lo(paEmpty)], %o1! SEL
F008F6FC: 4001885d                 call    _objc_msgSend
F008F700: 90100015                 mov     %l5, %o0
F008F704: 90100018                 mov     %i0, %o0! id
F008F708: 94100014                 mov     %l4, %o2
F008F70C: 133c0504                 sethi   %hi(paSetresourcesFo), %o1
F008F710: d2026118                 ld      [%o1+%lo(paSetresourcesFo)], %o1! SEL
F008F714: 40018857                 call    _objc_msgSend
F008F718: 9610001c                 mov     %i4, %o3
F008F71C: 113c0503                 sethi   %hi(paFree), %o0! id
F008F720: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F008F724: 40018853                 call    _objc_msgSend
F008F728: 90100012                 mov     %l2, %o0
F008F72C: 3080000d                 ba,a    locret_F008F760
F008F730: 113c0504                 sethi   -0xFEBF000, %o0! id
F008F734: d20220cc                 ld      [%o0+0xCC], %o1! SEL
F008F738: 4001884e                 call    _objc_msgSend
F008F73C: 90100012                 mov     %l2, %o0! id
F008F740: 133c0503                 sethi   %hi(paFree), %o1! SEL
F008F744: e00263fc                 ld      [%o1+%lo(paFree)], %l0
F008F748: 4001884a                 call    _objc_msgSend
F008F74C: 92100010                 mov     %l0, %o1! SEL
F008F750: 90100014                 mov     %l4, %o0! id
F008F754: 40018847                 call    _objc_msgSend
F008F758: 92100010                 mov     %l0, %o1
F008F75C: b0102000                 mov     0, %i0
F008F760: 81c7e008                 ret
F008F764: 81e80000                 restore

F00DA2EC: 9de3bf80                 save    %sp, -0x80, %sp
F00DA2F0: a0100018                 mov     %i0, %l0
F00DA2F4: d0042010                 ld      [%l0+0x10], %o0! id
F00DA2F8: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00DA2FC: 40005d5d                 call    _objc_msgSend
F00DA300: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00DA304: d004200c                 ld      [%l0+0xC], %o0! id
F00DA308: 133c0504                 sethi   %hi(paCount_0), %o1
F00DA30C: d20260b8                 ld      [%o1+%lo(paCount_0)], %o1! SEL
F00DA310: 40005d58                 call    _objc_msgSend
F00DA314: a4102000                 mov     0, %l2
F00DA318: a6920000                 orcc    %o0, %g0, %l3
F00DA31C: 02800006                 be      loc_F00DA334
F00DA320: 9604202c                 add     %l0, 0x2C, %o3 ! ','
F00DA324: d004202c                 ld      [%l0+0x2C], %o0
F00DA328: 80a2c008                 cmp     %o3, %o0
F00DA32C: 1280000c                 bne     loc_F00DA35C
F00DA330: b0100008                 mov     %o0, %i0
F00DA334: d0042010                 ld      [%l0+0x10], %o0! id
F00DA338: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DA33C: 40005d4d                 call    _objc_msgSend
F00DA340: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DA344: 10800056                 ba      locret_F00DA49C
F00DA348: b0102000                 mov     0, %i0
F00DA34C: f0242030                 st      %i0, [%l0+0x30]
F00DA350: d2262008                 st      %o1, [%i0+8]
F00DA354: 10bffffc                 ba      loc_F00DA344
F00DA358: d226200c                 st      %o1, [%i0+0xC]
F00DA35C: d4062008                 ld      [%i0+8], %o2
F00DA360: 80a2c00a                 cmp     %o3, %o2
F00DA364: 12800004                 bne     loc_F00DA374
F00DA368: d206200c                 ld      [%i0+0xC], %o1
F00DA36C: 10800003                 ba      loc_F00DA378
F00DA370: 9010000a                 mov     %o2, %o0
F00DA374: 9002a008                 add     %o2, 8, %o0
F00DA378: d2222004                 st      %o1, [%o0+4]
F00DA37C: 9004202c                 add     %l0, 0x2C, %o0 ! ','
F00DA380: 80a20009                 cmp     %o0, %o1
F00DA384: 12800003                 bne     loc_F00DA390
F00DA388: 90026008                 add     %o1, 8, %o0
F00DA38C: 90100009                 mov     %o1, %o0
F00DA390: a2102000                 mov     0, %l1
F00DA394: 80a44013                 cmp     %l1, %l3
F00DA398: 1a80001b                 bcc     loc_F00DA404
F00DA39C: d4220000                 st      %o2, [%o0]
F00DA3A0: 2b3c0504                 sethi   -0xFEBF000, %l5
F00DA3A4: 293c0505                 sethi   -0xFEBEC00, %l4
F00DA3A8: d004200c                 ld      [%l0+0xC], %o0! id
F00DA3AC: d20560c8                 ld      [%l5+0xC8], %o1! SEL
F00DA3B0: 40005d30                 call    _objc_msgSend
F00DA3B4: 94100011                 mov     %l1, %o2
F00DA3B8: 80a00012                 cmp     %g0, %l2
F00DA3BC: d4062004                 ld      [%i0+4], %o2
F00DA3C0: 98603fff                 subc    %g0, -1, %o4
F00DA3C4: d6042040                 ld      [%l0+0x40], %o3
F00DA3C8: 9a10001b                 mov     %i3, %o5
F00DA3CC: d20520a0                 ld      [%l4+0xA0], %o1! SEL
F00DA3D0: f823a05c                 st      %i4, [%sp+0x80+var_24]
F00DA3D4: f023a060                 st      %i0, [%sp+0x80+var_20]
F00DA3D8: d823a064                 st      %o4, [%sp+0x80+var_1C]
F00DA3DC: e623a068                 st      %l3, [%sp+0x80+var_18]
F00DA3E0: 40005d24                 call    _objc_msgSend
F00DA3E4: 9810001a                 mov     %i2, %o4
F00DA3E8: 80a20012                 cmp     %o0, %l2
F00DA3EC: 38800002                 bgu,a   loc_F00DA3F4
F00DA3F0: a4100008                 mov     %o0, %l2
F00DA3F4: a2046001                 inc     %l1
F00DA3F8: 80a44013                 cmp     %l1, %l3
F00DA3FC: 2abfffec                 bcs,a   loc_F00DA3AC
F00DA400: d004200c                 ld      [%l0+0xC], %o0
F00DA404: d0042010                 ld      [%l0+0x10], %o0! id
F00DA408: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DA40C: 40005d19                 call    _objc_msgSend
F00DA410: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DA414: 80a4a000                 cmp     %l2, 0
F00DA418: 32800010                 bne,a   loc_F00DA458
F00DA41C: e4260000                 st      %l2, [%i0]
F00DA420: d204202c                 ld      [%l0+0x2C], %o1
F00DA424: 9004202c                 add     %l0, 0x2C, %o0 ! ','
F00DA428: 80a20009                 cmp     %o0, %o1
F00DA42C: 22bfffc8                 be,a    loc_F00DA34C
F00DA430: f024202c                 st      %i0, [%l0+0x2C]
F00DA434: d026200c                 st      %o0, [%i0+0xC]
F00DA438: d2262008                 st      %o1, [%i0+8]
F00DA43C: f024202c                 st      %i0, [%l0+0x2C]
F00DA440: 10bfffc1                 ba      loc_F00DA344
F00DA444: f022600c                 st      %i0, [%o1+0xC]
F00DA448: f0242028                 st      %i0, [%l0+0x28]
F00DA44C: d2262008                 st      %o1, [%i0+8]
F00DA450: 1080000f                 ba      loc_F00DA48C
F00DA454: d226200c                 st      %o1, [%i0+0xC]
F00DA458: d0062004                 ld      [%i0+4], %o0
F00DA45C: 7ffeed53                 call    _vac_flush
F00DA460: 92100012                 mov     %l2, %o1
F00DA464: 92042024                 add     %l0, 0x24, %o1 ! '$'
F00DA468: d0042024                 ld      [%l0+0x24], %o0
F00DA46C: 80a24008                 cmp     %o1, %o0
F00DA470: 22bffff6                 be,a    loc_F00DA448
F00DA474: f0242024                 st      %i0, [%l0+0x24]
F00DA478: d0042028                 ld      [%l0+0x28], %o0
F00DA47C: d026200c                 st      %o0, [%i0+0xC]
F00DA480: d2262008                 st      %o1, [%i0+8]
F00DA484: f0242028                 st      %i0, [%l0+0x28]
F00DA488: f0222008                 st      %i0, [%o0+8]
F00DA48C: d0042034                 ld      [%l0+0x34], %o0
F00DA490: b0102001                 mov     1, %i0
F00DA494: 90022001                 inc     %o0
F00DA498: d0242034                 st      %o0, [%l0+0x34]
F00DA49C: 81c7e008                 ret
F00DA4A0: 81e80000                 restore

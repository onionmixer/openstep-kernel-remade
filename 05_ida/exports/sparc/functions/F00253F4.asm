F00253F4: 9de3bf98                 save    %sp, -0x68, %sp
F00253F8: 4001c5e4                 call    _splusclock
F00253FC: 01000000                 nop
F0025400: 133c04cf941261e0         set     _bfreelist, %o2
F0025408: 9202a0cc                 add     %o2, 0xCC, %o1
F002540C: 80a28009                 cmp     %o2, %o1
F0025410: 1a800037                 bcc     loc_F00254EC
F0025414: a2100008                 mov     %o0, %l1
F0025418: 113c0094981223d8         set     _brelvp_wakeup, %o4
F0025420: 1100080096122100         set     0x200100, %o3
F0025428: 13000040                 sethi   0x10000, %o1
F002542C: e002a00c                 ld      [%o2+0xC], %l0
F0025430: 80a4000a                 cmp     %l0, %o2
F0025434: 22800029                 be,a    loc_F00254D8
F0025438: 9402a044                 inc     0x44, %o2 ! 'D'
F002543C: d0042040                 ld      [%l0+0x40], %o0
F0025440: 80a60008                 cmp     %i0, %o0
F0025444: 02800004                 be      loc_F0025454
F0025448: 80a62000                 cmp     %i0, 0
F002544C: 3280001f                 bne,a   loc_F00254C8
F0025450: e004200c                 ld      [%l0+0xC], %l0
F0025454: d0040000                 ld      [%l0], %o0
F0025458: 808a2200                 btst    0x200, %o0
F002545C: 22800015                 be,a    loc_F00254B0
F0025460: 90120009                 bset    %o1, %o0
F0025464: d8242030                 st      %o4, [%l0+0x30]
F0025468: 9012000b                 bset    %o3, %o0
F002546C: 4001c5d3                 call    _spltty
F0025470: d0240000                 st      %o0, [%l0]
F0025474: d4042010                 ld      [%l0+0x10], %o2
F0025478: d204200c                 ld      [%l0+0xC], %o1
F002547C: d222a00c                 st      %o1, [%o2+0xC]
F0025480: d404200c                 ld      [%l0+0xC], %o2
F0025484: d2042010                 ld      [%l0+0x10], %o1
F0025488: d222a010                 st      %o1, [%o2+0x10]
F002548C: d2040000                 ld      [%l0], %o1
F0025490: 92126008                 bset    8, %o1
F0025494: 4001c624                 call    _splx
F0025498: d2240000                 st      %o1, [%l0]
F002549C: 4001c622                 call    _splx
F00254A0: 90100011                 mov     %l1, %o0
F00254A4: 7ffffcb1                 call    _bwrite
F00254A8: 90100010                 mov     %l0, %o0
F00254AC: 30bfffd3                 ba,a    loc_F00253F8
F00254B0: d0240000                 st      %o0, [%l0]
F00254B4: 40000077                 call    sub_F0025690
F00254B8: 90100010                 mov     %l0, %o0
F00254BC: 4001c61a                 call    _splx
F00254C0: 90100011                 mov     %l1, %o0
F00254C4: 30bfffcd                 ba,a    loc_F00253F8
F00254C8: 80a4000a                 cmp     %l0, %o2
F00254CC: 32bfffdd                 bne,a   loc_F0025440
F00254D0: d0042040                 ld      [%l0+0x40], %o0
F00254D4: 9402a044                 inc     0x44, %o2 ! 'D'
F00254D8: 113c04cf901222ac         set     unk_F0133EAC, %o0
F00254E0: 80a28008                 cmp     %o2, %o0
F00254E4: 2abfffd3                 bcs,a   loc_F0025430
F00254E8: e002a00c                 ld      [%o2+0xC], %l0
F00254EC: 4001c60e                 call    _splx
F00254F0: 90100011                 mov     %l1, %o0
F00254F4: 81c7e008                 ret
F00254F8: 81e80000                 restore

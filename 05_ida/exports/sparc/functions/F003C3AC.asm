F003C3AC: 9de3bf98                 save    %sp, -0x68, %sp
F003C3B0: a2100018                 mov     %i0, %l1
F003C3B4: d0046014                 ld      [%l1+0x14], %o0
F003C3B8: 13240000                 sethi   -0x70000000, %o1
F003C3BC: 900a0009                 and     %o0, %o1, %o0
F003C3C0: 13040000                 sethi   0x10000000, %o1
F003C3C4: 80a20009                 cmp     %o0, %o1
F003C3C8: 32800003                 bne,a   loc_F003C3D4
F003C3CC: d8046030                 ld      [%l1+0x30], %o4
F003C3D0: 98102001                 mov     1, %o4
F003C3D4: 153c04ea9412a1b0         set     _clstat, %o2
F003C3DC: 113c04eaa0122160         set     _chtable, %l0
F003C3E4: d202a004                 ld      [%o2+4], %o1
F003C3E8: 113c0433                 sethi   %hi(_MAXCLIENTS), %o0
F003C3EC: d6022180                 ld      [%o0+%lo(_MAXCLIENTS)], %o3
F003C3F0: 92026001                 inc     %o1
F003C3F4: 912ae001                 sll     %o3, 1, %o0
F003C3F8: 9002000b                 add     %o0, %o3, %o0
F003C3FC: 912a2002                 sll     %o0, 2, %o0
F003C400: 90020010                 add     %o0, %l0, %o0
F003C404: 80a40008                 cmp     %l0, %o0
F003C408: 1a80004b                 bcc     loc_F003C534
F003C40C: d222a004                 st      %o1, [%o2+4]
F003C410: 25280000                 sethi   -0x60000000, %l2
F003C414: 94100010                 mov     %l0, %o2
F003C418: b0042008                 add     %l0, 8, %i0
F003C41C: d0063ffc                 ld      [%i0-4], %o0
F003C420: 80a22000                 cmp     %o0, 0
F003C424: 1280003b                 bne     loc_F003C510
F003C428: 113c0433                 sethi   -0xFEF3400, %o0
F003C42C: 90102001                 mov     1, %o0
F003C430: d2060000                 ld      [%i0], %o1
F003C434: 80a26000                 cmp     %o1, 0
F003C438: 12800017                 bne     loc_F003C494
F003C43C: d0263ffc                 st      %o0, [%i0-4]
F003C440: 90100011                 mov     %l1, %o0
F003C444: 13000061921262a3         set     0x186A3, %o1
F003C44C: 94102002                 mov     2, %o2
F003C450: 9610000c                 mov     %o4, %o3
F003C454: 40001963                 call    _clntkudp_create
F003C458: 98100019                 mov     %i1, %o4
F003C45C: 80a22000                 cmp     %o0, 0
F003C460: 12800005                 bne     loc_F003C474
F003C464: d0260000                 st      %o0, [%i0]
F003C468: 113c0433                 sethi   %hi(aClgetNullClien), %o0! "clget: null client"
F003C46C: 7fff6341                 call    _panic
F003C470: 901221d0                 bset    %lo(aClgetNullClien), %o0! "clget: null client"
F003C474: d0060000                 ld      [%i0], %o0
F003C478: d0020000                 ld      [%o0], %o0
F003C47C: d2022020                 ld      [%o0+0x20], %o1
F003C480: d2026010                 ld      [%o1+0x10], %o1
F003C484: 9fc24000                 call    %o1
F003C488: 01000000                 nop
F003C48C: 10800008                 ba      loc_F003C4AC
F003C490: 90100011                 mov     %l1, %o0
F003C494: 90100009                 mov     %o1, %o0
F003C498: 92100011                 mov     %l1, %o1
F003C49C: 9410000c                 mov     %o4, %o2
F003C4A0: 400019be                 call    _clntkudp_init
F003C4A4: 96100019                 mov     %i1, %o3
F003C4A8: 90100011                 mov     %l1, %o0
F003C4AC: 7fffff6b                 call    sub_F003C258
F003C4B0: 92100019                 mov     %i1, %o1
F003C4B4: d2060000                 ld      [%i0], %o1
F003C4B8: d0224000                 st      %o0, [%o1]
F003C4BC: d0060000                 ld      [%i0], %o0
F003C4C0: d0020000                 ld      [%o0], %o0
F003C4C4: 80a22000                 cmp     %o0, 0
F003C4C8: 32800006                 bne,a   loc_F003C4E0
F003C4CC: d0040000                 ld      [%l0], %o0
F003C4D0: 113c0433                 sethi   %hi(aClgetNullAuth), %o0! "clget: null auth"
F003C4D4: 7fff6327                 call    _panic
F003C4D8: 901221e8                 bset    %lo(aClgetNullAuth), %o0! "clget: null auth"
F003C4DC: d0040000                 ld      [%l0], %o0
F003C4E0: 90022001                 inc     %o0
F003C4E4: d0240000                 st      %o0, [%l0]
F003C4E8: d0046014                 ld      [%l1+0x14], %o0
F003C4EC: 900a0012                 and     %o0, %l2, %o0
F003C4F0: 80a20012                 cmp     %o0, %l2
F003C4F4: 32800037                 bne,a   locret_F003C5D0
F003C4F8: f0060000                 ld      [%i0], %i0
F003C4FC: d0060000                 ld      [%i0], %o0
F003C500: 40001910                 call    _clntkudp_interruptable
F003C504: 92102001                 mov     1, %o1
F003C508: 10800032                 ba      locret_F003C5D0
F003C50C: f0060000                 ld      [%i0], %i0
F003C510: d2022180                 ld      [%o0+0x180], %o1
F003C514: a004200c                 inc     0xC, %l0
F003C518: 912a6001                 sll     %o1, 1, %o0
F003C51C: 90020009                 add     %o0, %o1, %o0
F003C520: 912a2002                 sll     %o0, 2, %o0
F003C524: 9002000a                 add     %o0, %o2, %o0
F003C528: 80a40008                 cmp     %l0, %o0
F003C52C: 0abfffbc                 bcs     loc_F003C41C
F003C530: b006200c                 inc     0xC, %i0
F003C534: 90100011                 mov     %l1, %o0
F003C538: 13000061921262a3         set     0x186A3, %o1
F003C540: 94102002                 mov     2, %o2
F003C544: 9610000c                 mov     %o4, %o3
F003C548: 053c0433                 sethi   %hi(_cltoomany), %g2
F003C54C: da00a17c                 ld      [%g2+%lo(_cltoomany)], %o5
F003C550: 98100019                 mov     %i1, %o4
F003C554: 9a036001                 inc     %o5
F003C558: 40001922                 call    _clntkudp_create
F003C55C: da20a17c                 st      %o5, [%g2+%lo(_cltoomany)]
F003C560: b0920000                 orcc    %o0, %g0, %i0
F003C564: 32800006                 bne,a   loc_F003C57C
F003C568: d0060000                 ld      [%i0], %o0
F003C56C: 113c0433                 sethi   %hi(aClgetNullClien_0), %o0! "clget: null client"
F003C570: 7fff6300                 call    _panic
F003C574: 90122200                 bset    %lo(aClgetNullClien_0), %o0! "clget: null client"
F003C578: d0060000                 ld      [%i0], %o0
F003C57C: d2022020                 ld      [%o0+0x20], %o1
F003C580: d2026010                 ld      [%o1+0x10], %o1
F003C584: 9fc24000                 call    %o1
F003C588: 01000000                 nop
F003C58C: 90100011                 mov     %l1, %o0
F003C590: 7fffff32                 call    sub_F003C258
F003C594: 92100019                 mov     %i1, %o1
F003C598: 80a22000                 cmp     %o0, 0
F003C59C: 12800005                 bne     loc_F003C5B0
F003C5A0: d0260000                 st      %o0, [%i0]
F003C5A4: 113c0433                 sethi   %hi(aClgetNullAuth_0), %o0! "clget: null auth"
F003C5A8: 7fff62f2                 call    _panic
F003C5AC: 90122218                 bset    %lo(aClgetNullAuth_0), %o0! "clget: null auth"
F003C5B0: d0046014                 ld      [%l1+0x14], %o0
F003C5B4: 13280000                 sethi   -0x60000000, %o1
F003C5B8: 900a0009                 and     %o0, %o1, %o0
F003C5BC: 80a20009                 cmp     %o0, %o1
F003C5C0: 12800004                 bne     locret_F003C5D0
F003C5C4: 90100018                 mov     %i0, %o0
F003C5C8: 400018de                 call    _clntkudp_interruptable
F003C5CC: 92102001                 mov     1, %o1
F003C5D0: 81c7e008                 ret
F003C5D4: 81e80000                 restore

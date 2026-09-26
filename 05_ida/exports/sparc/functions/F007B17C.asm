F007B17C: 9de3bf98                 save    %sp, -0x68, %sp
F007B180: d2062014                 ld      [%i0+0x14], %o1
F007B184: 80a26041                 cmp     %o1, 0x41 ! 'A'
F007B188: 02800006                 be      loc_F007B1A0
F007B18C: a6102000                 mov     0, %l3
F007B190: 113c0443                 sethi   %hi(aPnNotifyMsgIdD), %o0! "pn_notify: msg_id = %d, unrecognized\n"
F007B194: 7ffe6531                 call    _printf
F007B198: 901223b8                 bset    %lo(aPnNotifyMsgIdD), %o0! "pn_notify: msg_id = %d, unrecognized\n"
F007B19C: 30800044                 ba,a    locret_F007B2AC
F007B1A0: 113c04c3                 sethi   %hi(dword_F0130F54), %o0
F007B1A4: e0022354                 ld      [%o0+%lo(dword_F0130F54)], %l0
F007B1A8: 92122354                 or      %o0, %lo(dword_F0130F54), %o1
F007B1AC: 80a40009                 cmp     %l0, %o1
F007B1B0: 0280003b                 be      loc_F007B29C
F007B1B4: 80a4e000                 cmp     %l3, 0
F007B1B8: a4100009                 mov     %o1, %l2
F007B1BC: a8100008                 mov     %o0, %l4
F007B1C0: d206201c                 ld      [%i0+0x1C], %o1
F007B1C4: d404200c                 ld      [%l0+0xC], %o2
F007B1C8: 80a2400a                 cmp     %o1, %o2
F007B1CC: 12800008                 bne     loc_F007B1EC
F007B1D0: e2040000                 ld      [%l0], %l1
F007B1D4: 80a44012                 cmp     %l1, %l2
F007B1D8: d0042004                 ld      [%l0+4], %o0
F007B1DC: 02800020                 be      loc_F007B25C
F007B1E0: 92100011                 mov     %l1, %o1
F007B1E4: 10800021                 ba      loc_F007B268
F007B1E8: d0246004                 st      %o0, [%l1+4]
F007B1EC: d0042008                 ld      [%l0+8], %o0
F007B1F0: 80a24008                 cmp     %o1, %o0
F007B1F4: 32800026                 bne,a   loc_F007B28C
F007B1F8: a0100011                 mov     %l1, %l0
F007B1FC: d4262010                 st      %o2, [%i0+0x10]
F007B200: c026200c                 clr     [%i0+0xC]
F007B204: 90102001                 mov     1, %o0
F007B208: d02e2003                 stb     %o0, [%i0+3]
F007B20C: 90102002                 mov     2, %o0
F007B210: d02e2018                 stb     %o0, [%i0+0x18]
F007B214: 90102020                 mov     0x20, %o0 ! ' '
F007B218: d02e2019                 stb     %o0, [%i0+0x19]
F007B21C: 90100018                 mov     %i0, %o0
F007B220: d4042010                 ld      [%l0+0x10], %o2
F007B224: 92102001                 mov     1, %o1
F007B228: d426201c                 st      %o2, [%i0+0x1C]
F007B22C: 7fffaaaa                 call    _msg_send
F007B230: 94102000                 mov     0, %o2
F007B234: 92920000                 orcc    %o0, %g0, %o1
F007B238: 22800006                 be,a    loc_F007B250
F007B23C: d2040000                 ld      [%l0], %o1
F007B240: 113c0443                 sethi   %hi(aPnNotifyMsgSen), %o0! "pn_notify: msg_send returned %d\n"
F007B244: 7ffe6505                 call    _printf
F007B248: 901223e0                 bset    %lo(aPnNotifyMsgSen), %o0! "pn_notify: msg_send returned %d\n"
F007B24C: d2040000                 ld      [%l0], %o1
F007B250: 80a24012                 cmp     %o1, %l2
F007B254: 12800004                 bne     loc_F007B264
F007B258: d0042004                 ld      [%l0+4], %o0
F007B25C: 10800003                 ba      loc_F007B268
F007B260: d024a004                 st      %o0, [%l2+4]
F007B264: d0226004                 st      %o0, [%o1+4]
F007B268: 80a20012                 cmp     %o0, %l2
F007B26C: 22800003                 be,a    loc_F007B278
F007B270: d2252354                 st      %o1, [%l4+0x354]
F007B274: d2220000                 st      %o1, [%o0]
F007B278: 90100010                 mov     %l0, %o0
F007B27C: 7fffb3c9                 call    _kfree
F007B280: 92102014                 mov     0x14, %o1
F007B284: a604e001                 inc     %l3
F007B288: a0100011                 mov     %l1, %l0
F007B28C: 80a40012                 cmp     %l0, %l2
F007B290: 32bfffcd                 bne,a   loc_F007B1C4
F007B294: d206201c                 ld      [%i0+0x1C], %o1
F007B298: 80a4e000                 cmp     %l3, 0
F007B29C: 12800004                 bne     locret_F007B2AC
F007B2A0: 113c0444                 sethi   %hi(aPnNotifyPortNo), %o0! "pn_notify: PORT NOT FOUND\n"
F007B2A4: 7ffe64ed                 call    _printf
F007B2A8: 90122008                 bset    %lo(aPnNotifyPortNo), %o0! "pn_notify: PORT NOT FOUND\n"
F007B2AC: 81c7e008                 ret
F007B2B0: 81e80000                 restore

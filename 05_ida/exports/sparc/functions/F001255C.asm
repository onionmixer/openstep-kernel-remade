F001255C: 9de3bf98                 save    %sp, -0x68, %sp
F0012560: a2100018                 mov     %i0, %l1
F0012564: d0046014                 ld      [%l1+0x14], %o0
F0012568: 80a22000                 cmp     %o0, 0
F001256C: 04800041                 ble     locret_F0012670
F0012570: b0103fff                 mov     -1, %i0
F0012574: d0046004                 ld      [%l1+4], %o0
F0012578: 80a22000                 cmp     %o0, 0
F001257C: 34800006                 bg,a    loc_F0012594
F0012580: e0044000                 ld      [%l1], %l0
F0012584: 113c042c                 sethi   %hi(aUwritec), %o0! "uwritec"
F0012588: 40000afa                 call    _panic
F001258C: 901222c8                 bset    %lo(aUwritec), %o0! "uwritec"
F0012590: e0044000                 ld      [%l1], %l0
F0012594: d0042004                 ld      [%l0+4], %o0
F0012598: 80a22000                 cmp     %o0, 0
F001259C: 3280000b                 bne,a   loc_F00125C8
F00125A0: d004600c                 ld      [%l1+0xC], %o0
F00125A4: 92042008                 add     %l0, 8, %o1
F00125A8: d0046004                 ld      [%l1+4], %o0
F00125AC: d2244000                 st      %o1, [%l1]
F00125B0: 90023fff                 inc     -1, %o0
F00125B4: 80a22000                 cmp     %o0, 0
F00125B8: 12bfffef                 bne     loc_F0012574
F00125BC: d0246004                 st      %o0, [%l1+4]
F00125C0: 1080002c                 ba      locret_F0012670
F00125C4: b0103fff                 mov     -1, %i0
F00125C8: 80a22001                 cmp     %o0, 1
F00125CC: 2280000f                 be,a    loc_F0012608
F00125D0: d0040000                 ld      [%l0], %o0
F00125D4: 14800006                 bg      loc_F00125EC
F00125D8: 80a22002                 cmp     %o0, 2
F00125DC: 80a22000                 cmp     %o0, 0
F00125E0: 02800006                 be      loc_F00125F8
F00125E4: b0102000                 mov     0, %i0
F00125E8: 3080000e                 ba,a    loc_F0012620
F00125EC: 02800009                 be      loc_F0012610
F00125F0: b0102000                 mov     0, %i0
F00125F4: 3080000b                 ba,a    loc_F0012620
F00125F8: 4001de5f                 call    _fubyte
F00125FC: d0040000                 ld      [%l0], %o0
F0012600: 1080000b                 ba      loc_F001262C
F0012604: b0100008                 mov     %o0, %i0
F0012608: 10800009                 ba      loc_F001262C
F001260C: f00a0000                 ldub    [%o0], %i0
F0012610: 4001de64                 call    _fuibyte
F0012614: d0040000                 ld      [%l0], %o0
F0012618: 10800005                 ba      loc_F001262C
F001261C: b0100008                 mov     %o0, %i0
F0012620: 113c042c                 sethi   %hi(aUwritecBogusUi), %o0! "uwritec: bogus uio_segflg"
F0012624: 40000ad3                 call    _panic
F0012628: 901222d0                 bset    %lo(aUwritecBogusUi), %o0! "uwritec: bogus uio_segflg"
F001262C: 80a62000                 cmp     %i0, 0
F0012630: 0680000f                 bl      loc_F001266C
F0012634: b00e20ff                 and     %i0, 0xFF, %i0
F0012638: d0040000                 ld      [%l0], %o0
F001263C: d2042004                 ld      [%l0+4], %o1
F0012640: 90022001                 inc     %o0
F0012644: d0240000                 st      %o0, [%l0]
F0012648: 92027fff                 inc     -1, %o1
F001264C: d2242004                 st      %o1, [%l0+4]
F0012650: d2046014                 ld      [%l1+0x14], %o1
F0012654: d0046008                 ld      [%l1+8], %o0
F0012658: 92027fff                 inc     -1, %o1
F001265C: d2246014                 st      %o1, [%l1+0x14]
F0012660: 90022001                 inc     %o0
F0012664: 10800003                 ba      locret_F0012670
F0012668: d0246008                 st      %o0, [%l1+8]
F001266C: b0103fff                 mov     -1, %i0
F0012670: 81c7e008                 ret
F0012674: 81e80000                 restore

F005049C: 9de3bf98                 save    %sp, -0x68, %sp
F00504A0: 213c0447                 sethi   %hi(_page_size), %l0
F00504A4: d204213c                 ld      [%l0+%lo(_page_size)], %o1
F00504A8: 7ffed856                 call    _udiv
F00504AC: 11000008                 sethi   0x2000, %o0
F00504B0: 912a2002                 sll     %o0, 2, %o0
F00504B4: 9002206e                 inc     0x6E, %o0 ! 'n'
F00504B8: 900a3ff8                 and     %o0, -8, %o0
F00504BC: 9c238008                 sub     %sp, %o0, %sp
F00504C0: 113c04cfa81221e0         set     _bfreelist, %l4
F00504C8: 90052110                 add     %l4, 0x110, %o0
F00504CC: 80a50008                 cmp     %l4, %o0
F00504D0: 1a80004a                 bcc     locret_F00505F8
F00504D4: aa03a060                 add     %sp, arg_60, %l5
F00504D8: ac100010                 mov     %l0, %l6
F00504DC: 113c043bb21221cc         set     unk_F010EDCC, %i1
F00504E4: 313c043b                 sethi   -0xFEF1400, %i0
F00504E8: ae102000                 mov     0, %l7
F00504EC: a4102000                 mov     0, %l2
F00504F0: a2102000                 mov     0, %l1
F00504F4: a0102000                 mov     0, %l0
F00504F8: d205a13c                 ld      [%l6+0x13C], %o1
F00504FC: 7ffed841                 call    _udiv
F0050500: 11000008                 sethi   0x2000, %o0
F0050504: 80a44008                 cmp     %l1, %o0
F0050508: 18800006                 bgu     loc_F0050520
F005050C: 01000000                 nop
F0050510: c0240015                 clr     [%l0+%l5]
F0050514: a0042004                 inc     4, %l0
F0050518: 10bffff8                 ba      loc_F00504F8
F005051C: a2046001                 inc     %l1
F0050520: 400119a6                 call    _spltty
F0050524: 01000000                 nop
F0050528: e005200c                 ld      [%l4+0xC], %l0
F005052C: 80a40014                 cmp     %l0, %l4
F0050530: 0280000d                 be      loc_F0050564
F0050534: a2100008                 mov     %o0, %l1
F0050538: d0042018                 ld      [%l0+0x18], %o0
F005053C: 7ffed831                 call    _udiv
F0050540: d205a13c                 ld      [%l6+0x13C], %o1
F0050544: 912a2002                 sll     %o0, 2, %o0
F0050548: d2054008                 ld      [%l5+%o0], %o1
F005054C: 92026001                 inc     %o1
F0050550: d2254008                 st      %o1, [%l5+%o0]
F0050554: e004200c                 ld      [%l0+0xC], %l0
F0050558: 80a40014                 cmp     %l0, %l4
F005055C: 12bffff7                 bne     loc_F0050538
F0050560: a404a001                 inc     %l2
F0050564: 400119f0                 call    _splx
F0050568: 90100011                 mov     %l1, %o0
F005056C: 113c043b90122200         set     aSTotalD, %o0! "%s: total-%d"
F0050574: d205c019                 ld      [%l7+%i1], %o1
F0050578: 94100012                 mov     %l2, %o2
F005057C: a2102000                 mov     0, %l1
F0050580: 7fff1036                 call    _printf
F0050584: a6102000                 mov     0, %l3
F0050588: e405a13c                 ld      [%l6+0x13C], %l2
F005058C: 11000008                 sethi   0x2000, %o0
F0050590: 7ffed81c                 call    _udiv
F0050594: 92100012                 mov     %l2, %o1
F0050598: 80a44008                 cmp     %l1, %o0
F005059C: 3880000f                 bgu,a   loc_F00505D8
F00505A0: 113c043b                 sethi   -0xFEF1400, %o0
F00505A4: e004c015                 ld      [%l3+%l5], %l0
F00505A8: 80a42000                 cmp     %l0, 0
F00505AC: 02800008                 be      loc_F00505CC
F00505B0: 90100011                 mov     %l1, %o0
F00505B4: 7ffed7d3                 call    _umul
F00505B8: 92100012                 mov     %l2, %o1
F00505BC: 92100008                 mov     %o0, %o1
F00505C0: 90162210                 or      %i0, 0x210, %o0! char *
F00505C4: 7fff1025                 call    _printf
F00505C8: 94100010                 mov     %l0, %o2
F00505CC: a604e004                 inc     4, %l3
F00505D0: 10bfffee                 ba      loc_F0050588
F00505D4: a2046001                 inc     %l1
F00505D8: 7fff1020                 call    _printf
F00505DC: 90122218                 bset    0x218, %o0
F00505E0: a8052044                 inc     0x44, %l4 ! 'D'
F00505E4: 113c04cf901222f0         set     _buf, %o0
F00505EC: 80a50008                 cmp     %l4, %o0
F00505F0: 0abfffbf                 bcs     loc_F00504EC
F00505F4: ae05e004                 inc     4, %l7
F00505F8: 81c7e008                 ret
F00505FC: 81e80000                 restore

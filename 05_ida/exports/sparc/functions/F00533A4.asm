F00533A4: 9de3bf88                 save    %sp, -0x78, %sp
F00533A8: ba100018                 mov     %i0, %i5
F00533AC: e2076030                 ld      [%i5+0x30], %l1
F00533B0: d0146044                 lduh    [%l1+0x44], %o0
F00533B4: 808a2001                 btst    1, %o0
F00533B8: 0280000b                 be      loc_F00533E4
F00533BC: f227bff4                 st      %i1, [%fp+var_C]
F00533C0: 90122010                 bset    0x10, %o0
F00533C4: d0346044                 sth     %o0, [%l1+0x44]
F00533C8: 90100011                 mov     %l1, %o0! unsigned int
F00533CC: 7ffefcab                 call    _sleep
F00533D0: 9210200a                 mov     0xA, %o1
F00533D4: d0146044                 lduh    [%l1+0x44], %o0
F00533D8: 808a2001                 btst    1, %o0
F00533DC: 12bffffa                 bne     loc_F00533C4
F00533E0: 90122010                 bset    0x10, %o0
F00533E4: 113c0447                 sethi   %hi(_page_size), %o0
F00533E8: ec02213c                 ld      [%o0+%lo(_page_size)], %l6
F00533EC: c4046040                 ld      [%l1+0x40], %g2
F00533F0: e8046050                 ld      [%l1+0x50], %l4
F00533F4: d2046070                 ld      [%l1+0x70], %o1
F00533F8: b0102000                 mov     0, %i0
F00533FC: d0146044                 lduh    [%l1+0x44], %o0
F0053400: c427bfec                 st      %g2, [%fp+var_14]
F0053404: 90122005                 bset    5, %o0
F0053408: d0346044                 sth     %o0, [%l1+0x44]
F005340C: 90068016                 add     %i2, %l6, %o0
F0053410: 80a24008                 cmp     %o1, %o0
F0053414: 1a800004                 bcc     loc_F0053424
F0053418: f8052030                 ld      [%l4+0x30], %i4
F005341C: 4000d940                 call    _vm_page_zero_fill
F0053420: d007bff4                 ld      [%fp+var_C], %o0
F0053424: 1100003fb21223fe         set     0xFFFE, %i1
F005342C: 1100003fb61223ef         set     0xFFEF, %i3
F0053434: d0052048                 ld      [%l4+0x48], %o0
F0053438: a6100016                 mov     %l6, %l3
F005343C: ae2e8008                 andn    %i2, %o0, %l7
F0053440: 92270017                 sub     %i4, %l7, %o1
F0053444: d0052050                 ld      [%l4+0x50], %o0
F0053448: 80a24016                 cmp     %o1, %l6
F005344C: 1a800003                 bcc     loc_F0053458
F0053450: ab368008                 srl     %i2, %o0, %l5
F0053454: a6100009                 mov     %o1, %l3
F0053458: d0046070                 ld      [%l1+0x70], %o0
F005345C: 80a2001a                 cmp     %o0, %i2
F0053460: 18800007                 bgu     loc_F005347C
F0053464: 9022001a                 sub     %o0, %i2, %o0
F0053468: 80a62000                 cmp     %i0, 0
F005346C: 32800086                 bne,a   loc_F0053684
F0053470: d2146044                 lduh    [%l1+0x44], %o1
F0053474: 10800023                 ba      loc_F0053500
F0053478: d0146044                 lduh    [%l1+0x44], %o0
F005347C: 80a20013                 cmp     %o0, %l3
F0053480: 2a800002                 bcs,a   loc_F0053488
F0053484: a6100008                 mov     %o0, %l3
F0053488: 90100011                 mov     %l1, %o0
F005348C: 92100015                 mov     %l5, %o1
F0053490: 94102001                 mov     1, %o2
F0053494: 053c04cf                 sethi   %hi(dword_F0133DDC), %g2
F0053498: da00a1dc                 ld      [%g2+%lo(dword_F0133DDC)], %o5
F005349C: 9605c013                 add     %l7, %l3, %o3
F00534A0: e04b6038                 ldsb    [%o5+0x38], %l0
F00534A4: 98102000                 mov     0, %o4
F00534A8: 7fffdd93                 call    _bmap
F00534AC: c02b6038                 clrb    [%o5+0x38]
F00534B0: 053c04cf                 sethi   %hi(dword_F0133DDC), %g2
F00534B4: d200a1dc                 ld      [%g2+%lo(dword_F0133DDC)], %o1
F00534B8: d4052064                 ld      [%l4+0x64], %o2
F00534BC: d64a6038                 ldsb    [%o1+0x38], %o3
F00534C0: 992a000a                 sll     %o0, %o2, %o4
F00534C4: 80a2e000                 cmp     %o3, 0
F00534C8: 0280000a                 be      loc_F00534F0
F00534CC: e02a6038                 stb     %l0, [%o1+0x38]
F00534D0: 113c043c90122228         set     aIoErrorOnPagei, %o0! "IO error on pagein: error = %d.\n"
F00534D8: d4074000                 ld      [%i5], %o2
F00534DC: 9210000b                 mov     %o3, %o1
F00534E0: 7fff045e                 call    _printf
F00534E4: d222a034                 st      %o1, [%o2+0x34]
F00534E8: 10800045                 ba      loc_F00535FC
F00534EC: d0146044                 lduh    [%l1+0x44], %o0
F00534F0: 80a32000                 cmp     %o4, 0
F00534F4: 1680000d                 bge     loc_F0053528
F00534F8: 80a5600b                 cmp     %l5, 0xB
F00534FC: d0146044                 lduh    [%l1+0x44], %o0
F0053500: 900a0019                 and     %o0, %i1, %o0
F0053504: 808a2010                 btst    0x10, %o0
F0053508: 02800006                 be      loc_F0053520
F005350C: d0346044                 sth     %o0, [%l1+0x44]
F0053510: 900a001b                 and     %o0, %i3, %o0
F0053514: d0346044                 sth     %o0, [%l1+0x44]
F0053518: 7ffefe34                 call    _wakeup
F005351C: 90100011                 mov     %l1, %o0
F0053520: 10800066                 ba      locret_F00536B8
F0053524: b0102001                 mov     1, %i0
F0053528: 34800011                 bg,a    loc_F005356C
F005352C: e4052030                 ld      [%l4+0x30], %l2
F0053530: d2052050                 ld      [%l4+0x50], %o1
F0053534: 90056001                 add     %l5, 1, %o0
F0053538: d4046070                 ld      [%l1+0x70], %o2
F005353C: 912a0009                 sll     %o0, %o1, %o0
F0053540: 80a28008                 cmp     %o2, %o0
F0053544: 2a800004                 bcs,a   loc_F0053554
F0053548: d0052048                 ld      [%l4+0x48], %o0
F005354C: 10800008                 ba      loc_F005356C
F0053550: e4052030                 ld      [%l4+0x30], %l2
F0053554: d2052034                 ld      [%l4+0x34], %o1
F0053558: 902a8008                 andn    %o2, %o0, %o0
F005355C: 90020009                 add     %o0, %o1, %o0
F0053560: d205204c                 ld      [%l4+0x4C], %o1
F0053564: 90023fff                 inc     -1, %o0
F0053568: a40a0009                 and     %o0, %o1, %l2
F005356C: d0046058                 ld      [%l1+0x58], %o0
F0053570: 90022001                 inc     %o0
F0053574: 80a20015                 cmp     %o0, %l5
F0053578: 1280000b                 bne     loc_F00535A4
F005357C: d007bfec                 ld      [%fp+var_14], %o0
F0053580: 153c04eb                 sethi   %hi(_rablock), %o2
F0053584: d602a170                 ld      [%o2+%lo(_rablock)], %o3
F0053588: 9210000c                 mov     %o4, %o1
F005358C: 153c04eb                 sethi   %hi(_rasize), %o2
F0053590: d802a178                 ld      [%o2+%lo(_rasize)], %o4
F0053594: 7fff4411                 call    _breada
F0053598: 94100012                 mov     %l2, %o2
F005359C: 10800006                 ba      loc_F00535B4
F00535A0: a0100008                 mov     %o0, %l0
F00535A4: 9210000c                 mov     %o4, %o1
F00535A8: 7fff43de                 call    _bread
F00535AC: 94100012                 mov     %l2, %o2
F00535B0: a0100008                 mov     %o0, %l0
F00535B4: ea246058                 st      %l5, [%l1+0x58]
F00535B8: d0042028                 ld      [%l0+0x28], %o0
F00535BC: 90248008                 sub     %l2, %o0, %o0
F00535C0: 80a4c008                 cmp     %l3, %o0
F00535C4: 34800002                 bg,a    loc_F00535CC
F00535C8: a6100008                 mov     %o0, %l3
F00535CC: d0040000                 ld      [%l0], %o0
F00535D0: 808a2004                 btst    4, %o0
F00535D4: 02800014                 be      loc_F0053624
F00535D8: 90100010                 mov     %l0, %o0
F00535DC: d4074000                 ld      [%i5], %o2
F00535E0: d254201c                 ldsh    [%l0+0x1C], %o1
F00535E4: 7fff44a1                 call    _brelse
F00535E8: d222a034                 st      %o1, [%o2+0x34]
F00535EC: 113c043c                 sethi   %hi(aIoErrorOnPagei_0), %o0! "IO error on pagein (bread)\n"
F00535F0: 7fff041a                 call    _printf
F00535F4: 90122250                 bset    %lo(aIoErrorOnPagei_0), %o0! "IO error on pagein (bread)\n"
F00535F8: d0146044                 lduh    [%l1+0x44], %o0
F00535FC: 900a0019                 and     %o0, %i1, %o0
F0053600: 808a2010                 btst    0x10, %o0
F0053604: 02800006                 be      loc_F005361C
F0053608: d0346044                 sth     %o0, [%l1+0x44]
F005360C: 900a001b                 and     %o0, %i3, %o0
F0053610: d0346044                 sth     %o0, [%l1+0x44]
F0053614: 7ffefdf5                 call    _wakeup
F0053618: 90100011                 mov     %l1, %o0
F005361C: 10800027                 ba      locret_F00536B8
F0053620: b0102002                 mov     2, %i0
F0053624: d0042020                 ld      [%l0+0x20], %o0
F0053628: c407bff4                 ld      [%fp+var_C], %g2
F005362C: 94100013                 mov     %l3, %o2
F0053630: d200a024                 ld      [%g2+0x24], %o1
F0053634: 90020017                 add     %o0, %l7, %o0
F0053638: 400130c1                 call    _copy_to_phys
F005363C: 92024018                 add     %o1, %i0, %o1
F0053640: 80a4c01c                 cmp     %l3, %i4
F0053644: 12800005                 bne     loc_F0053658
F0053648: 13001000                 sethi   0x400000, %o1
F005364C: d0040000                 ld      [%l0], %o0
F0053650: 90120009                 bset    %o1, %o0
F0053654: d0240000                 st      %o0, [%l0]
F0053658: 7fff4484                 call    _brelse
F005365C: 90100010                 mov     %l0, %o0
F0053660: ac258013                 sub     %l6, %l3, %l6
F0053664: b0060013                 add     %i0, %l3, %i0
F0053668: 80a5a000                 cmp     %l6, 0
F005366C: 04800005                 ble     loc_F0053680
F0053670: b4068013                 add     %i2, %l3, %i2
F0053674: 80a4e000                 cmp     %l3, 0
F0053678: 32bfff70                 bne,a   loc_F0053438
F005367C: d0052048                 ld      [%l4+0x48], %o0
F0053680: d2146044                 lduh    [%l1+0x44], %o1
F0053684: 1100003f901223fe         set     0xFFFE, %o0
F005368C: 920a4008                 and     %o1, %o0, %o1
F0053690: 808a6010                 btst    0x10, %o1
F0053694: 02800008                 be      loc_F00536B4
F0053698: d2346044                 sth     %o1, [%l1+0x44]
F005369C: 1100003f901223ef         set     0xFFEF, %o0
F00536A4: 900a4008                 and     %o1, %o0, %o0
F00536A8: d0346044                 sth     %o0, [%l1+0x44]
F00536AC: 7ffefdcf                 call    _wakeup
F00536B0: 90100011                 mov     %l1, %o0
F00536B4: b0102000                 mov     0, %i0
F00536B8: 81c7e008                 ret
F00536BC: 81e80000                 restore

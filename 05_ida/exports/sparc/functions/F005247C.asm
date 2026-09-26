F005247C: 9de3bf88                 save    %sp, -0x78, %sp
F0052480: d0068000                 ld      [%i2], %o0
F0052484: 80a22002                 cmp     %o0, 2
F0052488: 12800004                 bne     loc_F0052498
F005248C: e207a05c                 ld      [%fp+arg_5C], %l1
F0052490: 1080009f                 ba      locret_F005270C
F0052494: b0102015                 mov     0x15, %i0
F0052498: d0546002                 ldsh    [%l1+2], %o0
F005249C: c027bff4                 clr     [%fp+var_C]
F00524A0: 80a22000                 cmp     %o0, 0
F00524A4: 02800007                 be      loc_F00524C0
F00524A8: f0062030                 ld      [%i0+0x30], %i0
F00524AC: d216a004                 lduh    [%i2+4], %o1
F00524B0: 1100003f901221ff         set     0xFDFF, %o0
F00524B8: 920a4008                 and     %o1, %o0, %o1
F00524BC: d236a004                 sth     %o1, [%i2+4]
F00524C0: 9007bff4                 add     %fp, var_C, %o0
F00524C4: d023a05c                 st      %o0, [%sp+0x78+var_1C]
F00524C8: 90100018                 mov     %i0, %o0
F00524CC: 92100019                 mov     %i1, %o1
F00524D0: 94102000                 mov     0, %o2
F00524D4: 96102000                 mov     0, %o3
F00524D8: 98102000                 mov     0, %o4
F00524DC: 7fffe40e                 call    _direnter
F00524E0: 9a10001a                 mov     %i2, %o5
F00524E4: d2162044                 lduh    [%i0+0x44], %o1
F00524E8: 808a6046                 btst    0x46, %o1 ! 'F'
F00524EC: 0280001d                 be      loc_F0052560
F00524F0: b2100008                 mov     %o0, %i1
F00524F4: 90126008                 or      %o1, 8, %o0
F00524F8: d0362044                 sth     %o0, [%i0+0x44]
F00524FC: 213c04d4                 sethi   %hi(_iuniqtime), %l0
F0052500: 40007034                 call    _microtime
F0052504: 90142148                 or      %l0, %lo(_iuniqtime), %o0
F0052508: d0162044                 lduh    [%i0+0x44], %o0
F005250C: 808a2004                 btst    4, %o0
F0052510: 02800003                 be      loc_F005251C
F0052514: d0042148                 ld      [%l0+%lo(_iuniqtime)], %o0
F0052518: d0262074                 st      %o0, [%i0+0x74]
F005251C: d0162044                 lduh    [%i0+0x44], %o0
F0052520: 808a2002                 btst    2, %o0
F0052524: 02800003                 be      loc_F0052530
F0052528: d0042148                 ld      [%l0+0x148], %o0
F005252C: d026207c                 st      %o0, [%i0+0x7C]
F0052530: d0162044                 lduh    [%i0+0x44], %o0
F0052534: 808a2040                 btst    0x40, %o0 ! '@'
F0052538: 22800006                 be,a    loc_F0052550
F005253C: d2162044                 lduh    [%i0+0x44], %o1
F0052540: c026204c                 clr     [%i0+0x4C]
F0052544: d0042148                 ld      [%l0+0x148], %o0
F0052548: d0262084                 st      %o0, [%i0+0x84]
F005254C: d2162044                 lduh    [%i0+0x44], %o1
F0052550: 1100003f901223b9         set     0xFFB9, %o0
F0052558: 920a4008                 and     %o1, %o0, %o1
F005255C: d2362044                 sth     %o1, [%i0+0x44]
F0052560: 80a66011                 cmp     %i1, 0x11
F0052564: 1280002b                 bne     loc_F0052610
F0052568: f007bff4                 ld      [%fp+var_C], %i0
F005256C: 80a6e000                 cmp     %i3, 0
F0052570: 12800015                 bne     loc_F00525C4
F0052574: 80a66000                 cmp     %i1, 0
F0052578: d0162064                 lduh    [%i0+0x64], %o0
F005257C: 1300003c                 sethi   0xF000, %o1
F0052580: 900a0009                 and     %o0, %o1, %o0
F0052584: 13000010                 sethi   0x4000, %o1
F0052588: 80a20009                 cmp     %o0, %o1
F005258C: 12800006                 bne     loc_F00525A4
F0052590: 80a72000                 cmp     %i4, 0
F0052594: 808f2080                 btst    0x80, %i4
F0052598: 1280000a                 bne     loc_F00525C0
F005259C: b2102015                 mov     0x15, %i1
F00525A0: 80a72000                 cmp     %i4, 0
F00525A4: 02800006                 be      loc_F00525BC
F00525A8: 90100018                 mov     %i0, %o0
F00525AC: 7ffff2d7                 call    _iaccess
F00525B0: 9210001c                 mov     %i4, %o1
F00525B4: 10800003                 ba      loc_F00525C0
F00525B8: b2100008                 mov     %o0, %i1
F00525BC: b2102000                 mov     0, %i1
F00525C0: 80a66000                 cmp     %i1, 0
F00525C4: 22800006                 be,a    loc_F00525DC
F00525C8: d0162064                 lduh    [%i0+0x64], %o0
F00525CC: 7fffeef3                 call    _iput
F00525D0: 90100018                 mov     %i0, %o0
F00525D4: 10800010                 ba      loc_F0052614
F00525D8: 80a66000                 cmp     %i1, 0
F00525DC: 1300003c                 sethi   0xF000, %o1
F00525E0: 900a0009                 and     %o0, %o1, %o0
F00525E4: 13000020                 sethi   0x8000, %o1
F00525E8: 80a20009                 cmp     %o0, %o1
F00525EC: 1280000a                 bne     loc_F0052614
F00525F0: 80a66000                 cmp     %i1, 0
F00525F4: d006a018                 ld      [%i2+0x18], %o0
F00525F8: 80a22000                 cmp     %o0, 0
F00525FC: 12800006                 bne     loc_F0052614
F0052600: 80a66000                 cmp     %i1, 0
F0052604: 90100018                 mov     %i0, %o0
F0052608: 7ffff03d                 call    _itrunc
F005260C: 92102000                 mov     0, %o1
F0052610: 80a66000                 cmp     %i1, 0
F0052614: 3280003e                 bne,a   locret_F005270C
F0052618: b0100019                 mov     %i1, %i0
F005261C: 9006200c                 add     %i0, 0xC, %o0
F0052620: d0274000                 st      %o0, [%i5]
F0052624: d0162044                 lduh    [%i0+0x44], %o0
F0052628: 808a2046                 btst    0x46, %o0 ! 'F'
F005262C: 0280001c                 be      loc_F005269C
F0052630: 90122008                 bset    8, %o0
F0052634: d0362044                 sth     %o0, [%i0+0x44]
F0052638: 213c04d4                 sethi   %hi(_iuniqtime), %l0
F005263C: 40006fe5                 call    _microtime
F0052640: 90142148                 or      %l0, %lo(_iuniqtime), %o0
F0052644: d0162044                 lduh    [%i0+0x44], %o0
F0052648: 808a2004                 btst    4, %o0
F005264C: 02800003                 be      loc_F0052658
F0052650: d0042148                 ld      [%l0+%lo(_iuniqtime)], %o0
F0052654: d0262074                 st      %o0, [%i0+0x74]
F0052658: d0162044                 lduh    [%i0+0x44], %o0
F005265C: 808a2002                 btst    2, %o0
F0052660: 02800003                 be      loc_F005266C
F0052664: d0042148                 ld      [%l0+0x148], %o0
F0052668: d026207c                 st      %o0, [%i0+0x7C]
F005266C: d0162044                 lduh    [%i0+0x44], %o0
F0052670: 808a2040                 btst    0x40, %o0 ! '@'
F0052674: 22800006                 be,a    loc_F005268C
F0052678: d2162044                 lduh    [%i0+0x44], %o1
F005267C: c026204c                 clr     [%i0+0x4C]
F0052680: d0042148                 ld      [%l0+0x148], %o0
F0052684: d0262084                 st      %o0, [%i0+0x84]
F0052688: d2162044                 lduh    [%i0+0x44], %o1
F005268C: 1100003f901223b9         set     0xFFB9, %o0
F0052694: 920a4008                 and     %o1, %o0, %o1
F0052698: d2362044                 sth     %o1, [%i0+0x44]
F005269C: 7ffff28b                 call    _iunlock
F00526A0: 90100018                 mov     %i0, %o0
F00526A4: d2074000                 ld      [%i5], %o1
F00526A8: d4026028                 ld      [%o1+0x28], %o2
F00526AC: 9002bffd                 add     %o2, -3, %o0
F00526B0: 80a22001                 cmp     %o0, 1
F00526B4: 08800007                 bleu    loc_F00526D0
F00526B8: 90100009                 mov     %o1, %o0
F00526BC: 9002bff8                 add     %o2, -8, %o0
F00526C0: 80a22001                 cmp     %o0, 1
F00526C4: 1880000a                 bgu     loc_F00526EC
F00526C8: 80a6a000                 cmp     %i2, 0
F00526CC: 90100009                 mov     %o1, %o0
F00526D0: 7fffd332                 call    _specvp
F00526D4: d252202c                 ldsh    [%o0+0x2C], %o1
F00526D8: a0100008                 mov     %o0, %l0
F00526DC: 7fff5922                 call    _vn_rele
F00526E0: d0074000                 ld      [%i5], %o0
F00526E4: e0274000                 st      %l0, [%i5]
F00526E8: 80a6a000                 cmp     %i2, 0
F00526EC: 02800007                 be      loc_F0052708
F00526F0: 9210001a                 mov     %i2, %o1
F00526F4: d0074000                 ld      [%i5], %o0
F00526F8: d602201c                 ld      [%o0+0x1C], %o3
F00526FC: d602e014                 ld      [%o3+0x14], %o3
F0052700: 9fc2c000                 call    %o3
F0052704: 94100011                 mov     %l1, %o2
F0052708: b0100019                 mov     %i1, %i0
F005270C: 81c7e008                 ret
F0052710: 81e80000                 restore

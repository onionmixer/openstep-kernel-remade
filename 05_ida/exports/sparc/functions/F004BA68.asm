F004BA68: 9de3bf98                 save    %sp, -0x68, %sp
F004BA6C: aa102000                 mov     0, %l5
F004BA70: a8102000                 mov     0, %l4
F004BA74: a4102000                 mov     0, %l2
F004BA78: ba102000                 mov     0, %i5
F004BA7C: d0062070                 ld      [%i0+0x70], %o0
F004BA80: a2102000                 mov     0, %l1
F004BA84: 900223ff                 inc     0x3FF, %o0
F004BA88: ae0a3c00                 and     %o0, -0x400, %l7
F004BA8C: 80a50017                 cmp     %l4, %l7
F004BA90: 9006a004                 add     %i2, 4, %o0
F004BA94: 900a3ffc                 and     %o0, -4, %o0
F004BA98: 1a80008a                 bcc     loc_F004BCC0
F004BA9C: ac022008                 add     %o0, 8, %l6
F004BAA0: d0062050                 ld      [%i0+0x50], %o0
F004BAA4: d0022048                 ld      [%o0+0x48], %o0
F004BAA8: 80ac4008                 andncc  %l1, %o0, %g0
F004BAAC: 3280000f                 bne,a   loc_F004BAE8
F004BAB0: d006c000                 ld      [%i3], %o0
F004BAB4: 80a52000                 cmp     %l4, 0
F004BAB8: 02800005                 be      loc_F004BACC
F004BABC: 90100018                 mov     %i0, %o0
F004BAC0: 7fff636a                 call    _brelse
F004BAC4: 90100014                 mov     %l4, %o0
F004BAC8: 90100018                 mov     %i0, %o0
F004BACC: 92100011                 mov     %l1, %o1
F004BAD0: 40000446                 call    _blkatoff
F004BAD4: 94102000                 mov     0, %o2
F004BAD8: a8920000                 orcc    %o0, %g0, %l4
F004BADC: 02800065                 be      loc_F004BC70
F004BAE0: a4102000                 mov     0, %l2
F004BAE4: d006c000                 ld      [%i3], %o0
F004BAE8: 80a22000                 cmp     %o0, 0
F004BAEC: 32800009                 bne,a   loc_F004BB10
F004BAF0: e6052020                 ld      [%l4+0x20], %l3
F004BAF4: 808ca3ff                 btst    0x3FF, %l2
F004BAF8: 32800006                 bne,a   loc_F004BB10
F004BAFC: e6052020                 ld      [%l4+0x20], %l3
F004BB00: 90103fff                 mov     -1, %o0
F004BB04: d026e004                 st      %o0, [%i3+4]
F004BB08: aa102000                 mov     0, %l5
F004BB0C: e6052020                 ld      [%l4+0x20], %l3
F004BB10: a004c012                 add     %l3, %l2, %l0
F004BB14: d0142004                 lduh    [%l0+4], %o0
F004BB18: 80a22000                 cmp     %o0, 0
F004BB1C: 02800009                 be      loc_F004BB40
F004BB20: 92100010                 mov     %l0, %o1
F004BB24: 90100018                 mov     %i0, %o0
F004BB28: 94100012                 mov     %l2, %o2
F004BB2C: 40000473                 call    sub_F004CCF8
F004BB30: 96100011                 mov     %l1, %o3
F004BB34: 80a22000                 cmp     %o0, 0
F004BB38: 22800006                 be,a    loc_F004BB50
F004BB3C: d406c000                 ld      [%i3], %o2! size_t
F004BB40: 920ca3ff                 and     %l2, 0x3FF, %o1
F004BB44: 90102400                 mov     0x400, %o0
F004BB48: 1080005a                 ba      loc_F004BCB0
F004BB4C: 90220009                 sub     %o0, %o1, %o0
F004BB50: 80a2a002                 cmp     %o2, 2
F004BB54: 22800026                 be,a    loc_F004BBEC
F004BB58: d0040000                 ld      [%l0], %o0
F004BB5C: d004c012                 ld      [%l3+%l2], %o0
F004BB60: 80a22000                 cmp     %o0, 0
F004BB64: 02800007                 be      loc_F004BB80
F004BB68: d2142004                 lduh    [%l0+4], %o1
F004BB6C: d0142006                 lduh    [%l0+6], %o0
F004BB70: 92027ff8                 inc     -8, %o1
F004BB74: 90022004                 inc     4, %o0
F004BB78: 900a3ffc                 and     %o0, -4, %o0
F004BB7C: 92224008                 sub     %o1, %o0, %o1
F004BB80: 80a26000                 cmp     %o1, 0
F004BB84: 04800019                 ble     loc_F004BBE8
F004BB88: 80a24016                 cmp     %o1, %l6
F004BB8C: 06800006                 bl      loc_F004BBA4
F004BB90: 90102002                 mov     2, %o0
F004BB94: d026c000                 st      %o0, [%i3]
F004BB98: e226e004                 st      %l1, [%i3+4]
F004BB9C: 10800012                 ba      loc_F004BBE4
F004BBA0: d0142004                 lduh    [%l0+4], %o0
F004BBA4: 80a2a000                 cmp     %o2, 0
F004BBA8: 32800011                 bne,a   loc_F004BBEC
F004BBAC: d0040000                 ld      [%l0], %o0
F004BBB0: d006e004                 ld      [%i3+4], %o0
F004BBB4: 80a23fff                 cmp     %o0, -1
F004BBB8: 12800003                 bne     loc_F004BBC4
F004BBBC: aa054009                 add     %l5, %o1, %l5
F004BBC0: e226e004                 st      %l1, [%i3+4]
F004BBC4: 80a54016                 cmp     %l5, %l6
F004BBC8: 06800008                 bl      loc_F004BBE8
F004BBCC: 90102001                 mov     1, %o0
F004BBD0: d026c000                 st      %o0, [%i3]
F004BBD4: d0142004                 lduh    [%l0+4], %o0
F004BBD8: d206e004                 ld      [%i3+4], %o1
F004BBDC: 90044008                 add     %l1, %o0, %o0
F004BBE0: 90220009                 sub     %o0, %o1, %o0
F004BBE4: d026e008                 st      %o0, [%i3+8]
F004BBE8: d0040000                 ld      [%l0], %o0
F004BBEC: 80a22000                 cmp     %o0, 0
F004BBF0: 2280002f                 be,a    loc_F004BCAC
F004BBF4: d0142004                 lduh    [%l0+4], %o0
F004BBF8: d0142006                 lduh    [%l0+6], %o0
F004BBFC: 80a2001a                 cmp     %o0, %i2
F004BC00: 3280002b                 bne,a   loc_F004BCAC
F004BC04: d0142004                 lduh    [%l0+4], %o0
F004BC08: d24e4000                 ldsb    [%i1], %o1
F004BC0C: d04c2008                 ldsb    [%l0+8], %o0
F004BC10: 80a24008                 cmp     %o1, %o0
F004BC14: 32800026                 bne,a   loc_F004BCAC
F004BC18: d0142004                 lduh    [%l0+4], %o0
F004BC1C: 90100019                 mov     %i1, %o0! void *
F004BC20: 92042008                 add     %l0, 8, %o1! void *
F004BC24: 7ffee8ce                 call    _bcmp
F004BC28: 9410001a                 mov     %i2, %o2
F004BC2C: 80a22000                 cmp     %o0, 0
F004BC30: 3280001f                 bne,a   loc_F004BCAC
F004BC34: d0142004                 lduh    [%l0+4], %o0
F004BC38: d0062048                 ld      [%i0+0x48], %o0
F004BC3C: e226204c                 st      %l1, [%i0+0x4C]
F004BC40: d4040000                 ld      [%l0], %o2
F004BC44: 80a2000a                 cmp     %o0, %o2
F004BC48: 2280000e                 be,a    loc_F004BC80
F004BC4C: f0270000                 st      %i0, [%i4]
F004BC50: d0562046                 ldsh    [%i0+0x46], %o0
F004BC54: 40000821                 call    _iget
F004BC58: d2062050                 ld      [%i0+0x50], %o1
F004BC5C: 80a22000                 cmp     %o0, 0
F004BC60: 1280000b                 bne     loc_F004BC8C
F004BC64: d0270000                 st      %o0, [%i4]
F004BC68: 7fff6300                 call    _brelse
F004BC6C: 90100014                 mov     %l4, %o0
F004BC70: 193c04cf                 sethi   %hi(dword_F0133DDC), %o4
F004BC74: d00321dc                 ld      [%o4+%lo(dword_F0133DDC)], %o0
F004BC78: 10800020                 ba      locret_F004BCF8
F004BC7C: f04a2038                 ldsb    [%o0+0x38], %i0
F004BC80: d0162012                 lduh    [%i0+0x12], %o0
F004BC84: 90022001                 inc     %o0
F004BC88: d0362012                 sth     %o0, [%i0+0x12]
F004BC8C: 90102003                 mov     3, %o0
F004BC90: d026c000                 st      %o0, [%i3]
F004BC94: e226e004                 st      %l1, [%i3+4]
F004BC98: 9024401d                 sub     %l1, %i5, %o0
F004BC9C: d026e008                 st      %o0, [%i3+8]
F004BCA0: e826e00c                 st      %l4, [%i3+0xC]
F004BCA4: 10800014                 ba      loc_F004BCF4
F004BCA8: e026e010                 st      %l0, [%i3+0x10]
F004BCAC: ba100011                 mov     %l1, %i5
F004BCB0: a2044008                 add     %l1, %o0, %l1
F004BCB4: 80a44017                 cmp     %l1, %l7
F004BCB8: 0abfff7a                 bcs     loc_F004BAA0
F004BCBC: a4048008                 add     %l2, %o0, %l2
F004BCC0: 80a52000                 cmp     %l4, 0
F004BCC4: 22800005                 be,a    loc_F004BCD8
F004BCC8: d006c000                 ld      [%i3], %o0
F004BCCC: 7fff62e7                 call    _brelse
F004BCD0: 90100014                 mov     %l4, %o0
F004BCD4: d006c000                 ld      [%i3], %o0
F004BCD8: 80a22000                 cmp     %o0, 0
F004BCDC: 32800006                 bne,a   loc_F004BCF4
F004BCE0: c0270000                 clr     [%i4]
F004BCE4: ee26e004                 st      %l7, [%i3+4]
F004BCE8: 90102400                 mov     0x400, %o0
F004BCEC: d026e008                 st      %o0, [%i3+8]
F004BCF0: c0270000                 clr     [%i4]
F004BCF4: b0102000                 mov     0, %i0
F004BCF8: 81c7e008                 ret
F004BCFC: 81e80000                 restore

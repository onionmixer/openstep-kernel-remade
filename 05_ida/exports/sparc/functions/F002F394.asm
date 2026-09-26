F002F394: 9de3bf90                 save    %sp, -0x70, %sp
F002F398: 113c04bda0122030         set     unk_F012F430, %l0
F002F3A0: d0060000                 ld      [%i0], %o0
F002F3A4: a207bff4                 add     %fp, var_C, %l1
F002F3A8: b0102000                 mov     0, %i0
F002F3AC: d027bff4                 st      %o0, [%fp+var_C]
F002F3B0: 80a62000                 cmp     %i0, 0
F002F3B4: 02800004                 be      loc_F002F3C4
F002F3B8: 9010202e                 mov     0x2E, %o0 ! '.'
F002F3BC: d02c0000                 stb     %o0, [%l0]
F002F3C0: a0042001                 inc     %l0
F002F3C4: d00c4000                 ldub    [%l1], %o0
F002F3C8: 80a22063                 cmp     %o0, 0x63 ! 'c'
F002F3CC: 08800019                 bleu    loc_F002F430
F002F3D0: 80a22009                 cmp     %o0, 9
F002F3D4: 7fff5c8b                 call    _udiv
F002F3D8: 92102064                 mov     0x64, %o1 ! 'd'
F002F3DC: 90022030                 inc     0x30, %o0 ! '0'
F002F3E0: d02c0000                 stb     %o0, [%l0]
F002F3E4: a0042001                 inc     %l0
F002F3E8: d00c4000                 ldub    [%l1], %o0
F002F3EC: 7fff5d2d                 call    _urem
F002F3F0: 92102064                 mov     0x64, %o1 ! 'd'
F002F3F4: 900a20ff                 and     %o0, 0xFF, %o0
F002F3F8: 7fff5c82                 call    _udiv
F002F3FC: 9210200a                 mov     0xA, %o1
F002F400: 808a20ff                 btst    0xFF, %o0
F002F404: 32800006                 bne,a   loc_F002F41C
F002F408: d00c4000                 ldub    [%l1], %o0
F002F40C: 90102030                 mov     0x30, %o0 ! '0'
F002F410: d02c0000                 stb     %o0, [%l0]
F002F414: a0042001                 inc     %l0
F002F418: d00c4000                 ldub    [%l1], %o0
F002F41C: 7fff5d21                 call    _urem
F002F420: 92102064                 mov     0x64, %o1 ! 'd'
F002F424: d02c4000                 stb     %o0, [%l1]
F002F428: d00c4000                 ldub    [%l1], %o0
F002F42C: 80a22009                 cmp     %o0, 9
F002F430: 2880000c                 bleu,a  loc_F002F460
F002F434: b0062001                 inc     %i0
F002F438: 7fff5c72                 call    _udiv
F002F43C: 9210200a                 mov     0xA, %o1
F002F440: 90022030                 inc     0x30, %o0 ! '0'
F002F444: d02c0000                 stb     %o0, [%l0]
F002F448: a0042001                 inc     %l0
F002F44C: d00c4000                 ldub    [%l1], %o0
F002F450: 7fff5d14                 call    _urem
F002F454: 9210200a                 mov     0xA, %o1
F002F458: d02c4000                 stb     %o0, [%l1]
F002F45C: b0062001                 inc     %i0
F002F460: d00c4000                 ldub    [%l1], %o0
F002F464: 80a62003                 cmp     %i0, 3
F002F468: 90022030                 inc     0x30, %o0 ! '0'
F002F46C: d02c0000                 stb     %o0, [%l0]
F002F470: a0042001                 inc     %l0
F002F474: 04bfffcf                 ble     loc_F002F3B0
F002F478: a2046001                 inc     %l1
F002F47C: c02c0000                 clrb    [%l0]
F002F480: 313c04bdb0162030         set     unk_F012F430, %i0
F002F488: 81c7e008                 ret
F002F48C: 81e80000                 restore

F001A088: 9de3bf90                 save    %sp, -0x70, %sp
F001A08C: e0064000                 ld      [%i1], %l0
F001A090: d404203c                 ld      [%l0+0x3C], %o2
F001A094: 808aa008                 btst    8, %o2
F001A098: 0280008e                 be      locret_F001A2D0
F001A09C: 11001000                 sethi   0x400000, %o0
F001A0A0: d2042040                 ld      [%l0+0x40], %o1
F001A0A4: 808a4008                 btst    %o0, %o1
F001A0A8: 1280008a                 bne     locret_F001A2D0
F001A0AC: 11002000                 sethi   0x800000, %o0
F001A0B0: 922a8008                 andn    %o2, %o0, %o1
F001A0B4: 11000040                 sethi   0x10000, %o0
F001A0B8: 808a4008                 btst    %o0, %o1
F001A0BC: 0280006f                 be      loc_F001A278
F001A0C0: d224203c                 st      %o1, [%l0+0x3C]
F001A0C4: d04c204b                 ldsb    [%l0+0x4B], %o0
F001A0C8: 80a22000                 cmp     %o0, 0
F001A0CC: 0280002c                 be      loc_F001A17C
F001A0D0: 90063ef7                 add     %i0, -0x109, %o0
F001A0D4: 80a22001                 cmp     %o0, 1
F001A0D8: 0880001f                 bleu    loc_F001A154
F001A0DC: b00e20ff                 and     %i0, 0xFF, %i0
F001A0E0: 113c042d901221a0         set     _partab, %o0
F001A0E8: d00e0008                 ldub    [%i0+%o0], %o0
F001A0EC: 920a203f                 and     %o0, 0x3F, %o1
F001A0F0: 80a26006                 cmp     %o1, 6! switch 7 cases
F001A0F4: 1880005c                 bgu     def_F001A108! jumptable F001A108 default case
F001A0F8: 113c0068                 sethi   %hi(jpt_F001A108), %o0
F001A0FC: 90122110                 bset    %lo(jpt_F001A108), %o0
F001A100: 932a6002                 sll     %o1, 2, %o1
F001A104: d0024008                 ld      [%o1+%o0], %o0
F001A108: 81c20000                 jmp     %o0! switch jump
F001A10C: 01000000                 nop
F001A12C: 90100010                 mov     %l0, %o0! jumptable F001A108 case 0
F001A130: 4000006a                 call    _ttyrubo
F001A134: 92102001                 mov     1, %o1
F001A138: 10800064                 ba      loc_F001A2C8
F001A13C: d00c204b                 ldub    [%l0+0x4B], %o0
F001A140: d204203c                 ld      [%l0+0x3C], %o1! jumptable F001A108 cases 1-3,5,6
F001A144: 11040000                 sethi   0x10000000, %o0
F001A148: 808a4008                 btst    %o0, %o1
F001A14C: 2280005f                 be,a    loc_F001A2C8
F001A150: d00c204b                 ldub    [%l0+0x4B], %o0
F001A154: 90100010                 mov     %l0, %o0
F001A158: 40000060                 call    _ttyrubo
F001A15C: 92102002                 mov     2, %o1
F001A160: 1080005a                 ba      loc_F001A2C8
F001A164: d00c204b                 ldub    [%l0+0x4B], %o0
F001A168: d24c204b                 ldsb    [%l0+0x4B], %o1! jumptable F001A108 case 4
F001A16C: d0040000                 ld      [%l0], %o0
F001A170: 80a24008                 cmp     %o1, %o0
F001A174: 16800005                 bge     loc_F001A188
F001A178: 01000000                 nop
F001A17C: 4000006b                 call    _ttyretype
F001A180: 90100019                 mov     %i1, %o0
F001A184: 30800053                 ba,a    locret_F001A2D0
F001A188: 4001f28c                 call    _spltty
F001A18C: 01000000                 nop
F001A190: a4100008                 mov     %o0, %l2
F001A194: d0042040                 ld      [%l0+0x40], %o0
F001A198: 13000800                 sethi   0x200000, %o1
F001A19C: e24c2048                 ldsb    [%l0+0x48], %l1
F001A1A0: 90120009                 bset    %o1, %o0
F001A1A4: d0242040                 st      %o0, [%l0+0x40]
F001A1A8: d004203c                 ld      [%l0+0x3C], %o0
F001A1AC: 13002000                 sethi   0x800000, %o1
F001A1B0: 90120009                 bset    %o1, %o0
F001A1B4: d20c204c                 ldub    [%l0+0x4C], %o1
F001A1B8: d024203c                 st      %o0, [%l0+0x3C]
F001A1BC: d0042004                 ld      [%l0+4], %o0
F001A1C0: d22c2048                 stb     %o1, [%l0+0x48]
F001A1C4: b0023fff                 add     %o0, -1, %i0
F001A1C8: 90100010                 mov     %l0, %o0
F001A1CC: 92100018                 mov     %i0, %o1
F001A1D0: 40000b0e                 call    _nextc3
F001A1D4: 9407bff4                 add     %fp, var_C, %o2
F001A1D8: b0920000                 orcc    %o0, %g0, %i0
F001A1DC: 02800006                 be      loc_F001A1F4
F001A1E0: d007bff4                 ld      [%fp+var_C], %o0
F001A1E4: 40000084                 call    _ttyecho
F001A1E8: 92100019                 mov     %i1, %o1
F001A1EC: 10bffff8                 ba      loc_F001A1CC
F001A1F0: 90100010                 mov     %l0, %o0
F001A1F4: 90100012                 mov     %l2, %o0
F001A1F8: d404203c                 ld      [%l0+0x3C], %o2
F001A1FC: 13002000                 sethi   0x800000, %o1
F001A200: 922a8009                 andn    %o2, %o1, %o1
F001A204: d224203c                 st      %o1, [%l0+0x3C]
F001A208: d4042040                 ld      [%l0+0x40], %o2
F001A20C: 13000800                 sethi   0x200000, %o1
F001A210: 922a8009                 andn    %o2, %o1, %o1
F001A214: 4001f2c4                 call    _splx
F001A218: d2242040                 st      %o1, [%l0+0x40]
F001A21C: d04c2048                 ldsb    [%l0+0x48], %o0
F001A220: a2244008                 sub     %l1, %o0, %l1
F001A224: 90020011                 add     %o0, %l1, %o0
F001A228: 80a46008                 cmp     %l1, 8
F001A22C: 04800003                 ble     loc_F001A238
F001A230: d02c2048                 stb     %o0, [%l0+0x48]
F001A234: a2102008                 mov     8, %l1
F001A238: a2847fff                 inccc   -1, %l1
F001A23C: 2c800023                 bneg,a  loc_F001A2C8
F001A240: d00c204b                 ldub    [%l0+0x4B], %o0
F001A244: 90102008                 mov     8, %o0
F001A248: 7ffffb52                 call    _ttyoutput
F001A24C: 92100010                 mov     %l0, %o1
F001A250: a2847fff                 inccc   -1, %l1
F001A254: 1cbffffd                 bpos    loc_F001A248
F001A258: 90102008                 mov     8, %o0
F001A25C: 1080001b                 ba      loc_F001A2C8
F001A260: d00c204b                 ldub    [%l0+0x4B], %o0
F001A264: 113c042e                 sethi   %hi(aTtyrub), %o0! jumptable F001A108 default case
F001A268: 7fffebc2                 call    _panic
F001A26C: 901220a8                 bset    %lo(aTtyrub), %o0! "ttyrub"
F001A270: 10800016                 ba      loc_F001A2C8
F001A274: d00c204b                 ldub    [%l0+0x4B], %o0
F001A278: 11000080                 sethi   0x20000, %o0
F001A27C: 808a4008                 btst    %o0, %o1
F001A280: 0280000e                 be      loc_F001A2B8
F001A284: 23000100                 sethi   0x40000, %l1
F001A288: d0042040                 ld      [%l0+0x40], %o0
F001A28C: 808a0011                 btst    %l1, %o0
F001A290: 3280000b                 bne,a   loc_F001A2BC
F001A294: 90100018                 mov     %i0, %o0
F001A298: 9010205c                 mov     0x5C, %o0 ! '\'
F001A29C: 7ffffb3d                 call    _ttyoutput
F001A2A0: 92100010                 mov     %l0, %o1
F001A2A4: d0042040                 ld      [%l0+0x40], %o0
F001A2A8: 90120011                 bset    %l1, %o0
F001A2AC: d0242040                 st      %o0, [%l0+0x40]
F001A2B0: 10800003                 ba      loc_F001A2BC
F001A2B4: 90100018                 mov     %i0, %o0
F001A2B8: d00c204d                 ldub    [%l0+0x4D], %o0
F001A2BC: 4000004e                 call    _ttyecho
F001A2C0: 92100019                 mov     %i1, %o1
F001A2C4: d00c204b                 ldub    [%l0+0x4B], %o0
F001A2C8: 90023fff                 inc     -1, %o0
F001A2CC: d02c204b                 stb     %o0, [%l0+0x4B]
F001A2D0: 81c7e008                 ret
F001A2D4: 81e80000                 restore

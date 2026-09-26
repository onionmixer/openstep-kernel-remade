F003B1DC: 9de3bf98                 save    %sp, -0x68, %sp
F003B1E0: d0062020                 ld      [%i0+0x20], %o0
F003B1E4: 80a22000                 cmp     %o0, 0
F003B1E8: 22800007                 be,a    loc_F003B204
F003B1EC: 9010200d                 mov     0xD, %o0
F003B1F0: d04a0000                 ldsb    [%o0], %o0
F003B1F4: 80a22000                 cmp     %o0, 0
F003B1F8: 12800005                 bne     loc_F003B20C
F003B1FC: 90100018                 mov     %i0, %o0
F003B200: 9010200d                 mov     0xD, %o0
F003B204: 10800032                 ba      locret_F003B2CC
F003B208: d0264000                 st      %o0, [%i1]
F003B20C: 40000385                 call    sub_F003C020
F003B210: 9210001a                 mov     %i2, %o1
F003B214: a0920000                 orcc    %o0, %g0, %l0
F003B218: 32800005                 bne,a   loc_F003B22C
F003B21C: d0068000                 ld      [%i2], %o0
F003B220: 90102046                 mov     0x46, %o0 ! 'F'
F003B224: 1080002a                 ba      locret_F003B2CC
F003B228: d0264000                 st      %o0, [%i1]
F003B22C: 808a2001                 btst    1, %o0
F003B230: 32800024                 bne,a   loc_F003B2C0
F003B234: b010201e                 mov     0x1E, %i0
F003B238: 808a2002                 btst    2, %o0
F003B23C: 0280000a                 be      loc_F003B264
F003B240: 9206a018                 add     %i2, 0x18, %o1
F003B244: d006e01c                 ld      [%i3+0x1C], %o0
F003B248: 4000039d                 call    sub_F003C0BC
F003B24C: 90022010                 inc     0x10, %o0
F003B250: 80a22000                 cmp     %o0, 0
F003B254: 32800005                 bne,a   loc_F003B268
F003B258: d404201c                 ld      [%l0+0x1C], %o2
F003B25C: 10800019                 ba      loc_F003B2C0
F003B260: b010201e                 mov     0x1E, %i0
F003B264: d404201c                 ld      [%l0+0x1C], %o2
F003B268: 113c04cf                 sethi   %hi(_active_u), %o0
F003B26C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F003B270: d602a028                 ld      [%o2+0x28], %o3
F003B274: d402201c                 ld      [%o0+0x1C], %o2
F003B278: d2062020                 ld      [%i0+0x20], %o1
F003B27C: 9fc2c000                 call    %o3
F003B280: 90100010                 mov     %l0, %o0
F003B284: b0100008                 mov     %o0, %i0
F003B288: 80a62002                 cmp     %i0, 2
F003B28C: 12800009                 bne     loc_F003B2B0
F003B290: 80a62000                 cmp     %i0, 0
F003B294: 40002817                 call    _svckudp_dup
F003B298: 9010001b                 mov     %i3, %o0
F003B29C: 80a22000                 cmp     %o0, 0
F003B2A0: 32800008                 bne,a   loc_F003B2C0
F003B2A4: b0102000                 mov     0, %i0
F003B2A8: 10800007                 ba      loc_F003B2C4
F003B2AC: f0264000                 st      %i0, [%i1]
F003B2B0: 32800005                 bne,a   loc_F003B2C4
F003B2B4: f0264000                 st      %i0, [%i1]
F003B2B8: 400027d1                 call    _svckudp_dupsave
F003B2BC: 9010001b                 mov     %i3, %o0
F003B2C0: f0264000                 st      %i0, [%i1]
F003B2C4: 7fffb628                 call    _vn_rele
F003B2C8: 90100010                 mov     %l0, %o0
F003B2CC: 81c7e008                 ret
F003B2D0: 81e80000                 restore

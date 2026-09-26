F003A16C: 9de3bf90                 save    %sp, -0x70, %sp
F003A170: a0100018                 mov     %i0, %l0
F003A174: f227a048                 st      %i1, [%fp+arg_48]
F003A178: d016a006                 lduh    [%i2+6], %o0
F003A17C: 80a66000                 cmp     %i1, 0
F003A180: 90022001                 inc     %o0
F003A184: 02800005                 be      loc_F003A198
F003A188: d036a006                 sth     %o0, [%i2+6]
F003A18C: d0166006                 lduh    [%i1+6], %o0
F003A190: 90022001                 inc     %o0
F003A194: d0366006                 sth     %o0, [%i1+6]
F003A198: d206a01c                 ld      [%i2+0x1C], %o1
F003A19C: d4026064                 ld      [%o1+0x64], %o2
F003A1A0: 9010001a                 mov     %i2, %o0
F003A1A4: 9fc28000                 call    %o2
F003A1A8: 9207bff4                 add     %fp, var_C, %o1
F003A1AC: b0920000                 orcc    %o0, %g0, %i0
F003A1B0: 12800029                 bne     loc_F003A254
F003A1B4: d207bff4                 ld      [%fp+var_C], %o1
F003A1B8: d006a024                 ld      [%i2+0x24], %o0
F003A1BC: 40000067                 call    _findexport
F003A1C0: 90022014                 inc     0x14, %o0
F003A1C4: d0240000                 st      %o0, [%l0]
F003A1C8: d007bff4                 ld      [%fp+var_C], %o0
F003A1CC: d2120000                 lduh    [%o0], %o1
F003A1D0: 4000b7f4                 call    _kfree
F003A1D4: 92026002                 inc     2, %o1
F003A1D8: d0040000                 ld      [%l0], %o0
F003A1DC: 80a22000                 cmp     %o0, 0
F003A1E0: 1280001d                 bne     loc_F003A254
F003A1E4: 01000000                 nop
F003A1E8: d016a004                 lduh    [%i2+4], %o0
F003A1EC: 808a2001                 btst    1, %o0
F003A1F0: 12800019                 bne     loc_F003A254
F003A1F4: b0102016                 mov     0x16, %i0
F003A1F8: d007a048                 ld      [%fp+arg_48], %o0
F003A1FC: 80a22000                 cmp     %o0, 0
F003A200: 12800010                 bne     loc_F003A240
F003A204: 9010001a                 mov     %i2, %o0
F003A208: 133c0432                 sethi   %hi(unk_F010C9E8), %o1
F003A20C: d606a01c                 ld      [%i2+0x1C], %o3
F003A210: 153c04cf                 sethi   %hi(_active_u), %o2
F003A214: da02a1d8                 ld      [%o2+%lo(_active_u)], %o5
F003A218: 921261e8                 bset    %lo(unk_F010C9E8), %o1
F003A21C: c402e020                 ld      [%o3+0x20], %g2
F003A220: 98102000                 mov     0, %o4
F003A224: d603601c                 ld      [%o5+0x1C], %o3
F003A228: 9407a048                 add     %fp, arg_48, %o2
F003A22C: 9fc08000                 call    %g2
F003A230: 9a102000                 mov     0, %o5
F003A234: b0920000                 orcc    %o0, %g0, %i0
F003A238: 12800007                 bne     loc_F003A254
F003A23C: 01000000                 nop
F003A240: 7fffba49                 call    _vn_rele
F003A244: 9010001a                 mov     %i2, %o0
F003A248: f407a048                 ld      [%fp+arg_48], %i2
F003A24C: 10bfffd3                 ba      loc_F003A198
F003A250: c027a048                 clr     [%fp+arg_48]
F003A254: 7fffba44                 call    _vn_rele
F003A258: 9010001a                 mov     %i2, %o0
F003A25C: d007a048                 ld      [%fp+arg_48], %o0
F003A260: 80a22000                 cmp     %o0, 0
F003A264: 02800004                 be      locret_F003A274
F003A268: 01000000                 nop
F003A26C: 7fffba3e                 call    _vn_rele
F003A270: 01000000                 nop
F003A274: 81c7e008                 ret
F003A278: 81e80000                 restore

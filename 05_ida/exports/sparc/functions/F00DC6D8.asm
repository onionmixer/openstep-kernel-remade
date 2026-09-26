F00DC6D8: 9de3bf88                 save    %sp, -0x78, %sp
F00DC6DC: f027bff0                 st      %i0, [%fp+var_10]
F00DC6E0: 113c0508                 sethi   %hi(stru_F01422CC.ext), %o0
F00DC6E4: 9610001b                 mov     %i3, %o3
F00DC6E8: 9810001c                 mov     %i4, %o4
F00DC6EC: d20222f8                 ld      [%o0+%lo(stru_F01422CC.ext)], %o1
F00DC6F0: 9a10001d                 mov     %i5, %o5
F00DC6F4: d407a05c                 ld      [%fp+arg_5C], %o2
F00DC6F8: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00DC6FC: d227bff4                 st      %o1, [%fp+var_C]
F00DC700: 133c0505                 sethi   %hi(paInitchannelTag), %o1
F00DC704: d423a05c                 st      %o2, [%sp+0x78+var_1C]
F00DC708: d2026084                 ld      [%o1+%lo(paInitchannelTag)], %o1! SEL
F00DC70C: 4000549c                 call    _objc_msgSendSuper
F00DC710: 9410001a                 mov     %i2, %o2
F00DC714: 80a22000                 cmp     %o0, 0
F00DC718: 12800004                 bne     loc_F00DC728
F00DC71C: 11000020                 sethi   0x8000, %o0
F00DC720: 10800031                 ba      locret_F00DC7E4
F00DC724: b0102000                 mov     0, %i0
F00DC728: d026207c                 st      %o0, [%i0+0x7C]
F00DC72C: d0262078                 st      %o0, [%i0+0x78]
F00DC730: 90102001                 mov     1, %o0
F00DC734: d0262098                 st      %o0, [%i0+0x98]
F00DC738: 9006208c                 add     %i0, 0x8C, %o0! id
F00DC73C: d0262090                 st      %o0, [%i0+0x90]
F00DC740: d026208c                 st      %o0, [%i0+0x8C]
F00DC744: b6102000                 mov     0, %i3
F00DC748: 393c0505                 sethi   -0xFEBEC00, %i4
F00DC74C: a0100008                 mov     %o0, %l0
F00DC750: d20721c4                 ld      [%i4+0x1C4], %o1! SEL
F00DC754: 40005447                 call    _objc_msgSend
F00DC758: 9010001a                 mov     %i2, %o0
F00DC75C: 80a6c008                 cmp     %i3, %o0
F00DC760: 3a800019                 bcc,a   loc_F00DC7C4
F00DC764: 213c0447                 sethi   -0xFEEE400, %l0
F00DC768: 7fffa5f2                 call    _IOMalloc
F00DC76C: 9010201c                 mov     0x1C, %o0
F00DC770: 92100008                 mov     %o0, %o1
F00DC774: c0224000                 clr     [%o1]
F00DC778: c0226004                 clr     [%o1+4]
F00DC77C: c022600c                 clr     [%o1+0xC]
F00DC780: c0226008                 clr     [%o1+8]
F00DC784: c0226010                 clr     [%o1+0x10]
F00DC788: d006208c                 ld      [%i0+0x8C], %o0
F00DC78C: 80a40008                 cmp     %l0, %o0
F00DC790: 22800009                 be,a    loc_F00DC7B4
F00DC794: d226208c                 st      %o1, [%i0+0x8C]
F00DC798: d0062090                 ld      [%i0+0x90], %o0
F00DC79C: d0226018                 st      %o0, [%o1+0x18]
F00DC7A0: e0226014                 st      %l0, [%o1+0x14]
F00DC7A4: d2262090                 st      %o1, [%i0+0x90]
F00DC7A8: d2222014                 st      %o1, [%o0+0x14]
F00DC7AC: 10bfffe9                 ba      loc_F00DC750
F00DC7B0: b606e001                 inc     %i3
F00DC7B4: d2262090                 st      %o1, [%i0+0x90]
F00DC7B8: e0226014                 st      %l0, [%o1+0x14]
F00DC7BC: 10bffffc                 ba      loc_F00DC7AC
F00DC7C0: e0226018                 st      %l0, [%o1+0x18]
F00DC7C4: d004213c                 ld      [%l0+0x13C], %o0
F00DC7C8: 7fffa5da                 call    _IOMalloc
F00DC7CC: 912a2003                 sll     %o0, 3, %o0
F00DC7D0: d204213c                 ld      [%l0+0x13C], %o1
F00DC7D4: d0262070                 st      %o0, [%i0+0x70]
F00DC7D8: 7fffa5d6                 call    _IOMalloc
F00DC7DC: 912a6002                 sll     %o1, 2, %o0
F00DC7E0: d0262074                 st      %o0, [%i0+0x74]
F00DC7E4: 81c7e008                 ret
F00DC7E8: 81e80000                 restore

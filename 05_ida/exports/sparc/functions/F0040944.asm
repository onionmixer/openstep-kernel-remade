F0040944: 9de3bf98                 save    %sp, -0x68, %sp
F0040948: d0060000                 ld      [%i0], %o0
F004094C: 808a2001                 btst    1, %o0
F0040950: 1280000f                 bne     loc_F004098C
F0040954: 113c04bd                 sethi   -0xFED0C00, %o0
F0040958: d0062040                 ld      [%i0+0x40], %o0
F004095C: d0022030                 ld      [%o0+0x30], %o0
F0040960: d0522062                 ldsh    [%o0+0x62], %o0
F0040964: 80a22000                 cmp     %o0, 0
F0040968: 22800009                 be,a    loc_F004098C
F004096C: 113c04bd                 sethi   -0xFED0C00, %o0
F0040970: d036201c                 sth     %o0, [%i0+0x1C]
F0040974: d2060000                 ld      [%i0], %o1
F0040978: 90100018                 mov     %i0, %o0
F004097C: 92126004                 bset    4, %o1
F0040980: 7fff91d4                 call    _biodone
F0040984: d2220000                 st      %o1, [%o0]
F0040988: 30800022                 ba,a    locret_F0040A10
F004098C: d0022128                 ld      [%o0+0x128], %o0
F0040990: 80a22000                 cmp     %o0, 0
F0040994: 0280001d                 be      loc_F0040A08
F0040998: 01000000                 nop
F004099C: d0060000                 ld      [%i0], %o0
F00409A0: 808a2100                 btst    0x100, %o0
F00409A4: 02800019                 be      loc_F0040A08
F00409A8: 133c04ea                 sethi   %hi(_async_bufhead), %o1
F00409AC: d00263d8                 ld      [%o1+%lo(_async_bufhead)], %o0
F00409B0: 80a22000                 cmp     %o0, 0
F00409B4: 22800008                 be,a    loc_F00409D4
F00409B8: f02263d8                 st      %i0, [%o1+%lo(_async_bufhead)]
F00409BC: 92100008                 mov     %o0, %o1
F00409C0: d002600c                 ld      [%o1+0xC], %o0
F00409C4: 80a22000                 cmp     %o0, 0
F00409C8: 32bffffe                 bne,a   loc_F00409C0
F00409CC: d202600c                 ld      [%o1+0xC], %o1
F00409D0: f022600c                 st      %i0, [%o1+0xC]
F00409D4: 113c0435                 sethi   %hi(_nfs_wakeup_one_biod), %o0
F00409D8: d0022324                 ld      [%o0+%lo(_nfs_wakeup_one_biod)], %o0
F00409DC: 80a22001                 cmp     %o0, 1
F00409E0: 12800006                 bne     loc_F00409F8
F00409E4: c026200c                 clr     [%i0+0xC]
F00409E8: 113c04ea                 sethi   %hi(_async_bufhead), %o0
F00409EC: 7fff490b                 call    _wakeup_one
F00409F0: 901223d8                 bset    %lo(_async_bufhead), %o0
F00409F4: 30800007                 ba,a    locret_F0040A10
F00409F8: 113c04ea                 sethi   %hi(_async_bufhead), %o0
F00409FC: 7fff48fb                 call    _wakeup
F0040A00: 901223d8                 bset    %lo(_async_bufhead), %o0
F0040A04: 30800003                 ba,a    locret_F0040A10
F0040A08: 4000005b                 call    sub_F0040B74
F0040A0C: 90100018                 mov     %i0, %o0
F0040A10: 81c7e008                 ret
F0040A14: 81e80000                 restore

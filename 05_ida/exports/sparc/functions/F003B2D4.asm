F003B2D4: 9de3bf98                 save    %sp, -0x68, %sp
F003B2D8: d0062020                 ld      [%i0+0x20], %o0
F003B2DC: 80a22000                 cmp     %o0, 0
F003B2E0: 2280000f                 be,a    loc_F003B31C
F003B2E4: 9010200d                 mov     0xD, %o0
F003B2E8: d04a0000                 ldsb    [%o0], %o0
F003B2EC: 80a22000                 cmp     %o0, 0
F003B2F0: 0280000b                 be      loc_F003B31C
F003B2F4: 9010200d                 mov     0xD, %o0
F003B2F8: d0062044                 ld      [%i0+0x44], %o0
F003B2FC: 80a22000                 cmp     %o0, 0
F003B300: 22800007                 be,a    loc_F003B31C
F003B304: 9010200d                 mov     0xD, %o0
F003B308: d04a0000                 ldsb    [%o0], %o0
F003B30C: 80a22000                 cmp     %o0, 0
F003B310: 12800005                 bne     loc_F003B324
F003B314: 90100018                 mov     %i0, %o0
F003B318: 9010200d                 mov     0xD, %o0
F003B31C: 1080003c                 ba      locret_F003B40C
F003B320: d0264000                 st      %o0, [%i1]
F003B324: 4000033f                 call    sub_F003C020
F003B328: 9210001a                 mov     %i2, %o1
F003B32C: a0920000                 orcc    %o0, %g0, %l0
F003B330: 32800005                 bne,a   loc_F003B344
F003B334: d0068000                 ld      [%i2], %o0
F003B338: 90102046                 mov     0x46, %o0 ! 'F'
F003B33C: 10800034                 ba      locret_F003B40C
F003B340: d0264000                 st      %o0, [%i1]
F003B344: 808a2001                 btst    1, %o0
F003B348: 32800024                 bne,a   loc_F003B3D8
F003B34C: b010201e                 mov     0x1E, %i0
F003B350: 808a2002                 btst    2, %o0
F003B354: 0280000a                 be      loc_F003B37C
F003B358: 9206a018                 add     %i2, 0x18, %o1
F003B35C: d006e01c                 ld      [%i3+0x1C], %o0
F003B360: 40000357                 call    sub_F003C0BC
F003B364: 90022010                 inc     0x10, %o0
F003B368: 80a22000                 cmp     %o0, 0
F003B36C: 12800005                 bne     loc_F003B380
F003B370: 90062024                 add     %i0, 0x24, %o0 ! '$'
F003B374: 10800019                 ba      loc_F003B3D8
F003B378: b010201e                 mov     0x1E, %i0
F003B37C: 90062024                 add     %i0, 0x24, %o0 ! '$'
F003B380: 40000328                 call    sub_F003C020
F003B384: 9210001a                 mov     %i2, %o1
F003B388: b4920000                 orcc    %o0, %g0, %i2
F003B38C: 32800007                 bne,a   loc_F003B3A8
F003B390: d2062020                 ld      [%i0+0x20], %o1
F003B394: 90102046                 mov     0x46, %o0 ! 'F'
F003B398: d0264000                 st      %o0, [%i1]
F003B39C: 7fffb5f2                 call    _vn_rele
F003B3A0: 90100010                 mov     %l0, %o0
F003B3A4: 3080001a                 ba,a    locret_F003B40C
F003B3A8: d404201c                 ld      [%l0+0x1C], %o2
F003B3AC: 113c04cf                 sethi   %hi(_active_u), %o0
F003B3B0: d80221d8                 ld      [%o0+%lo(_active_u)], %o4
F003B3B4: d6062044                 ld      [%i0+0x44], %o3
F003B3B8: da02a030                 ld      [%o2+0x30], %o5
F003B3BC: 90100010                 mov     %l0, %o0
F003B3C0: d803201c                 ld      [%o4+0x1C], %o4
F003B3C4: 9fc34000                 call    %o5
F003B3C8: 9410001a                 mov     %i2, %o2
F003B3CC: b0100008                 mov     %o0, %i0
F003B3D0: 7fffb5e5                 call    _vn_rele
F003B3D4: 9010001a                 mov     %i2, %o0
F003B3D8: 7fffb5e3                 call    _vn_rele
F003B3DC: 90100010                 mov     %l0, %o0
F003B3E0: 80a62000                 cmp     %i0, 0
F003B3E4: 12800005                 bne     loc_F003B3F8
F003B3E8: f0264000                 st      %i0, [%i1]
F003B3EC: 40002784                 call    _svckudp_dupsave
F003B3F0: 9010001b                 mov     %i3, %o0
F003B3F4: 30800006                 ba,a    locret_F003B40C
F003B3F8: 400027be                 call    _svckudp_dup
F003B3FC: 9010001b                 mov     %i3, %o0
F003B400: 80a22000                 cmp     %o0, 0
F003B404: 32800002                 bne,a   locret_F003B40C
F003B408: c0264000                 clr     [%i1]
F003B40C: 81c7e008                 ret
F003B410: 81e80000                 restore

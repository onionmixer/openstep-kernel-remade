F003B7EC: 9de3bf98                 save    %sp, -0x68, %sp
F003B7F0: d0062020                 ld      [%i0+0x20], %o0
F003B7F4: 80a22000                 cmp     %o0, 0
F003B7F8: 22800007                 be,a    loc_F003B814
F003B7FC: 9010200d                 mov     0xD, %o0
F003B800: d04a0000                 ldsb    [%o0], %o0
F003B804: 80a22000                 cmp     %o0, 0
F003B808: 12800005                 bne     loc_F003B81C
F003B80C: 90100018                 mov     %i0, %o0
F003B810: 9010200d                 mov     0xD, %o0
F003B814: 10800032                 ba      locret_F003B8DC
F003B818: d0264000                 st      %o0, [%i1]
F003B81C: 40000201                 call    sub_F003C020
F003B820: 9210001a                 mov     %i2, %o1
F003B824: a0920000                 orcc    %o0, %g0, %l0
F003B828: 32800005                 bne,a   loc_F003B83C
F003B82C: d0068000                 ld      [%i2], %o0
F003B830: 90102046                 mov     0x46, %o0 ! 'F'
F003B834: 1080002a                 ba      locret_F003B8DC
F003B838: d0264000                 st      %o0, [%i1]
F003B83C: 808a2001                 btst    1, %o0
F003B840: 32800024                 bne,a   loc_F003B8D0
F003B844: b010201e                 mov     0x1E, %i0
F003B848: 808a2002                 btst    2, %o0
F003B84C: 0280000a                 be      loc_F003B874
F003B850: 9206a018                 add     %i2, 0x18, %o1
F003B854: d006e01c                 ld      [%i3+0x1C], %o0
F003B858: 40000219                 call    sub_F003C0BC
F003B85C: 90022010                 inc     0x10, %o0
F003B860: 80a22000                 cmp     %o0, 0
F003B864: 32800005                 bne,a   loc_F003B878
F003B868: d404201c                 ld      [%l0+0x1C], %o2
F003B86C: 10800019                 ba      loc_F003B8D0
F003B870: b010201e                 mov     0x1E, %i0
F003B874: d404201c                 ld      [%l0+0x1C], %o2
F003B878: 113c04cf                 sethi   %hi(_active_u), %o0
F003B87C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F003B880: d602a038                 ld      [%o2+0x38], %o3
F003B884: d402201c                 ld      [%o0+0x1C], %o2
F003B888: d2062020                 ld      [%i0+0x20], %o1
F003B88C: 9fc2c000                 call    %o3
F003B890: 90100010                 mov     %l0, %o0
F003B894: b0100008                 mov     %o0, %i0
F003B898: 80a62002                 cmp     %i0, 2
F003B89C: 12800009                 bne     loc_F003B8C0
F003B8A0: 80a62000                 cmp     %i0, 0
F003B8A4: 40002693                 call    _svckudp_dup
F003B8A8: 9010001b                 mov     %i3, %o0
F003B8AC: 80a22000                 cmp     %o0, 0
F003B8B0: 32800008                 bne,a   loc_F003B8D0
F003B8B4: b0102000                 mov     0, %i0
F003B8B8: 10800007                 ba      loc_F003B8D4
F003B8BC: f0264000                 st      %i0, [%i1]
F003B8C0: 32800005                 bne,a   loc_F003B8D4
F003B8C4: f0264000                 st      %i0, [%i1]
F003B8C8: 4000264d                 call    _svckudp_dupsave
F003B8CC: 9010001b                 mov     %i3, %o0
F003B8D0: f0264000                 st      %i0, [%i1]
F003B8D4: 7fffb4a4                 call    _vn_rele
F003B8D8: 90100010                 mov     %l0, %o0
F003B8DC: 81c7e008                 ret
F003B8E0: 81e80000                 restore

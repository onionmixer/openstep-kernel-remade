F003B654: 9de3bf50                 save    %sp, -0xB0, %sp
F003B658: e2062020                 ld      [%i0+0x20], %l1
F003B65C: 80a46000                 cmp     %l1, 0
F003B660: 02800007                 be      loc_F003B67C
F003B664: 9010200d                 mov     0xD, %o0
F003B668: d04c4000                 ldsb    [%l1], %o0
F003B66C: 80a22000                 cmp     %o0, 0
F003B670: 12800005                 bne     loc_F003B684
F003B674: 90062024                 add     %i0, 0x24, %o0 ! '$'
F003B678: 9010200d                 mov     0xD, %o0
F003B67C: 1080005a                 ba      locret_F003B7E4
F003B680: d0264000                 st      %o0, [%i1]
F003B684: 40000252                 call    sub_F003BFCC
F003B688: 9207bfb8                 add     %fp, var_48, %o1
F003B68C: 90102002                 mov     2, %o0
F003B690: d027bfb8                 st      %o0, [%fp+var_48]
F003B694: 90100018                 mov     %i0, %o0
F003B698: 40000262                 call    sub_F003C020
F003B69C: 9210001a                 mov     %i2, %o1
F003B6A0: a0920000                 orcc    %o0, %g0, %l0
F003B6A4: 32800005                 bne,a   loc_F003B6B8
F003B6A8: d0068000                 ld      [%i2], %o0
F003B6AC: 90102046                 mov     0x46, %o0 ! 'F'
F003B6B0: 1080004d                 ba      locret_F003B7E4
F003B6B4: d0264000                 st      %o0, [%i1]
F003B6B8: 808a2001                 btst    1, %o0
F003B6BC: 12800047                 bne     loc_F003B7D8
F003B6C0: b010201e                 mov     0x1E, %i0
F003B6C4: 808a2002                 btst    2, %o0
F003B6C8: 0280000a                 be      loc_F003B6F0
F003B6CC: 9206a018                 add     %i2, 0x18, %o1
F003B6D0: d006e01c                 ld      [%i3+0x1C], %o0
F003B6D4: 4000027a                 call    sub_F003C0BC
F003B6D8: 90022010                 inc     0x10, %o0
F003B6DC: 80a22000                 cmp     %o0, 0
F003B6E0: 12800005                 bne     loc_F003B6F4
F003B6E4: 90100010                 mov     %l0, %o0
F003B6E8: 1080003c                 ba      loc_F003B7D8
F003B6EC: b010201e                 mov     0x1E, %i0
F003B6F0: 90100010                 mov     %l0, %o0
F003B6F4: 273c04cf                 sethi   %hi(_active_u), %l3
F003B6F8: d404e1d8                 ld      [%l3+%lo(_active_u)], %o2
F003B6FC: 92100011                 mov     %l1, %o1
F003B700: d604201c                 ld      [%l0+0x1C], %o3
F003B704: a807bfb8                 add     %fp, var_48, %l4
F003B708: d802a01c                 ld      [%o2+0x1C], %o4
F003B70C: a407bfb4                 add     %fp, var_4C, %l2
F003B710: da02e034                 ld      [%o3+0x34], %o5
F003B714: 94100014                 mov     %l4, %o2
F003B718: 9fc34000                 call    %o5
F003B71C: 96100012                 mov     %l2, %o3
F003B720: b0100008                 mov     %o0, %i0
F003B724: 80a62011                 cmp     %i0, 0x11
F003B728: 1280001b                 bne     loc_F003B794
F003B72C: 80a62000                 cmp     %i0, 0
F003B730: 400026f0                 call    _svckudp_dup
F003B734: 9010001b                 mov     %i3, %o0
F003B738: 80a22000                 cmp     %o0, 0
F003B73C: 02800015                 be      loc_F003B790
F003B740: d404e1d8                 ld      [%l3+0x1D8], %o2
F003B744: 90100010                 mov     %l0, %o0
F003B748: da04201c                 ld      [%l0+0x1C], %o5
F003B74C: 92100011                 mov     %l1, %o1
F003B750: d602a01c                 ld      [%o2+0x1C], %o3
F003B754: 98102000                 mov     0, %o4
F003B758: c4036020                 ld      [%o5+0x20], %g2
F003B75C: 94100012                 mov     %l2, %o2
F003B760: 9fc08000                 call    %g2
F003B764: 9a102000                 mov     0, %o5
F003B768: b0920000                 orcc    %o0, %g0, %i0
F003B76C: 1280000a                 bne     loc_F003B794
F003B770: d004e1d8                 ld      [%l3+0x1D8], %o0
F003B774: d204201c                 ld      [%l0+0x1C], %o1
F003B778: d402201c                 ld      [%o0+0x1C], %o2
F003B77C: d6026014                 ld      [%o1+0x14], %o3
F003B780: 90100010                 mov     %l0, %o0
F003B784: 9fc2c000                 call    %o3
F003B788: 92100014                 mov     %l4, %o1
F003B78C: b0100008                 mov     %o0, %i0
F003B790: 80a62000                 cmp     %i0, 0
F003B794: 1280000d                 bne     loc_F003B7C8
F003B798: 80a62000                 cmp     %i0, 0
F003B79C: 9007bfb8                 add     %fp, var_48, %o0
F003B7A0: 7ffff90a                 call    _vattr_to_nattr
F003B7A4: 92066024                 add     %i1, 0x24, %o1 ! '$'
F003B7A8: 90066004                 add     %i1, 4, %o0
F003B7AC: d207bfb4                 ld      [%fp+var_4C], %o1
F003B7B0: 7ffffab3                 call    _makefh
F003B7B4: 9410001a                 mov     %i2, %o2
F003B7B8: b0100008                 mov     %o0, %i0
F003B7BC: 7fffb4ea                 call    _vn_rele
F003B7C0: d007bfb4                 ld      [%fp+var_4C], %o0
F003B7C4: 80a62000                 cmp     %i0, 0
F003B7C8: 32800005                 bne,a   loc_F003B7DC
F003B7CC: f0264000                 st      %i0, [%i1]
F003B7D0: 4000268b                 call    _svckudp_dupsave
F003B7D4: 9010001b                 mov     %i3, %o0
F003B7D8: f0264000                 st      %i0, [%i1]
F003B7DC: 7fffb4e2                 call    _vn_rele
F003B7E0: 90100010                 mov     %l0, %o0
F003B7E4: 81c7e008                 ret
F003B7E8: 81e80000                 restore

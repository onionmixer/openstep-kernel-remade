F003A6A4: 9de3bf08                 save    %sp, -0xF8, %sp
F003A6A8: a0102000                 mov     0, %l0
F003A6AC: 90100018                 mov     %i0, %o0
F003A6B0: 4000065c                 call    sub_F003C020
F003A6B4: 9210001a                 mov     %i2, %o1
F003A6B8: a2920000                 orcc    %o0, %g0, %l1
F003A6BC: 32800005                 bne,a   loc_F003A6D0
F003A6C0: d0068000                 ld      [%i2], %o0
F003A6C4: 90102046                 mov     0x46, %o0 ! 'F'
F003A6C8: 10800067                 ba      locret_F003A864
F003A6CC: d0264000                 st      %o0, [%i1]
F003A6D0: 808a2001                 btst    1, %o0
F003A6D4: 32800061                 bne,a   loc_F003A858
F003A6D8: a010201e                 mov     0x1E, %l0
F003A6DC: 808a2002                 btst    2, %o0
F003A6E0: 0280000a                 be      loc_F003A708
F003A6E4: 9206a018                 add     %i2, 0x18, %o1
F003A6E8: d006e01c                 ld      [%i3+0x1C], %o0
F003A6EC: 40000674                 call    sub_F003C0BC
F003A6F0: 90022010                 inc     0x10, %o0
F003A6F4: 80a22000                 cmp     %o0, 0
F003A6F8: 12800005                 bne     loc_F003A70C
F003A6FC: 90062020                 add     %i0, 0x20, %o0 ! ' '
F003A700: 10800056                 ba      loc_F003A858
F003A704: a010201e                 mov     0x1E, %l0
F003A708: 90062020                 add     %i0, 0x20, %o0 ! ' '
F003A70C: 40000630                 call    sub_F003BFCC
F003A710: 9207bfb8                 add     %fp, var_48, %o1
F003A714: d007bfe0                 ld      [%fp+var_20], %o0
F003A718: 80a23fff                 cmp     %o0, -1
F003A71C: 0280000c                 be      loc_F003A74C
F003A720: d207bfe4                 ld      [%fp+var_1C], %o1
F003A724: 110003d090122240         set     0xF4240, %o0
F003A72C: 80a24008                 cmp     %o1, %o0
F003A730: 32800008                 bne,a   loc_F003A750
F003A734: d0046028                 ld      [%l1+0x28], %o0
F003A738: c027bfe0                 clr     [%fp+var_20]
F003A73C: 90103fff                 mov     -1, %o0
F003A740: d027bfe4                 st      %o0, [%fp+var_1C]
F003A744: d027bfd8                 st      %o0, [%fp+var_28]
F003A748: d027bfdc                 st      %o0, [%fp+var_24]
F003A74C: d0046028                 ld      [%l1+0x28], %o0
F003A750: 80a22001                 cmp     %o0, 1
F003A754: 12800026                 bne     loc_F003A7EC
F003A758: 80a42000                 cmp     %l0, 0
F003A75C: d007bfd0                 ld      [%fp+var_30], %o0
F003A760: 80a23fff                 cmp     %o0, -1
F003A764: 02800021                 be      loc_F003A7E8
F003A768: 313c04cf                 sethi   %hi(_active_u), %i0
F003A76C: d00621d8                 ld      [%i0+%lo(_active_u)], %o0
F003A770: d204601c                 ld      [%l1+0x1C], %o1
F003A774: d402201c                 ld      [%o0+0x1C], %o2
F003A778: c02fbf77                 clrb    [%fp+var_89]
F003A77C: d6026014                 ld      [%o1+0x14], %o3
F003A780: 90100011                 mov     %l1, %o0
F003A784: 9fc2c000                 call    %o3
F003A788: 9207bf78                 add     %fp, var_88, %o1
F003A78C: a0920000                 orcc    %o0, %g0, %l0
F003A790: 12800017                 bne     loc_F003A7EC
F003A794: d807bfd0                 ld      [%fp+var_30], %o4
F003A798: d007bf90                 ld      [%fp+var_70], %o0
F003A79C: 80a30008                 cmp     %o4, %o0
F003A7A0: 08800012                 bleu    loc_F003A7E8
F003A7A4: 92100011                 mov     %l1, %o1
F003A7A8: 90102004                 mov     4, %o0
F003A7AC: d023a05c                 st      %o0, [%sp+0xF8+var_9C]
F003A7B0: c023a060                 clr     [%sp+0xF8+var_98]
F003A7B4: 90102001                 mov     1, %o0
F003A7B8: 9407bf77                 add     %fp, var_89, %o2
F003A7BC: 96102001                 mov     1, %o3
F003A7C0: 98033fff                 inc     -1, %o4
F003A7C4: 7fffb8a4                 call    _vn_rdwr
F003A7C8: 9a102001                 mov     1, %o5
F003A7CC: d20621d8                 ld      [%i0+0x1D8], %o1
F003A7D0: d404601c                 ld      [%l1+0x1C], %o2
F003A7D4: d202601c                 ld      [%o1+0x1C], %o1
F003A7D8: a0100008                 mov     %o0, %l0
F003A7DC: d402a048                 ld      [%o2+0x48], %o2
F003A7E0: 9fc28000                 call    %o2
F003A7E4: 90100011                 mov     %l1, %o0
F003A7E8: 80a42000                 cmp     %l0, 0
F003A7EC: 3280001c                 bne,a   loc_F003A85C
F003A7F0: e0264000                 st      %l0, [%i1]
F003A7F4: 353c04cf                 sethi   %hi(_active_u), %i2
F003A7F8: d006a1d8                 ld      [%i2+%lo(_active_u)], %o0
F003A7FC: d204601c                 ld      [%l1+0x1C], %o1
F003A800: d402201c                 ld      [%o0+0x1C], %o2
F003A804: b007bfb8                 add     %fp, var_48, %i0
F003A808: d6026018                 ld      [%o1+0x18], %o3
F003A80C: 90100011                 mov     %l1, %o0
F003A810: 9fc2c000                 call    %o3
F003A814: 92100018                 mov     %i0, %o1
F003A818: a0920000                 orcc    %o0, %g0, %l0
F003A81C: 32800010                 bne,a   loc_F003A85C
F003A820: e0264000                 st      %l0, [%i1]
F003A824: d006a1d8                 ld      [%i2+%lo(_active_u)], %o0
F003A828: d204601c                 ld      [%l1+0x1C], %o1
F003A82C: d402201c                 ld      [%o0+0x1C], %o2
F003A830: d6026014                 ld      [%o1+0x14], %o3
F003A834: 90100011                 mov     %l1, %o0
F003A838: 9fc2c000                 call    %o3
F003A83C: 92100018                 mov     %i0, %o1
F003A840: a0920000                 orcc    %o0, %g0, %l0
F003A844: 32800006                 bne,a   loc_F003A85C
F003A848: e0264000                 st      %l0, [%i1]
F003A84C: 90100018                 mov     %i0, %o0
F003A850: 7ffffcde                 call    _vattr_to_nattr
F003A854: 92066004                 add     %i1, 4, %o1
F003A858: e0264000                 st      %l0, [%i1]
F003A85C: 7fffb8c2                 call    _vn_rele
F003A860: 90100011                 mov     %l1, %o0
F003A864: 81c7e008                 ret
F003A868: 81e80000                 restore

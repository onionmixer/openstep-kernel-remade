F003AF74: 9de3bf48                 save    %sp, -0xB8, %sp
F003AF78: e4062020                 ld      [%i0+0x20], %l2
F003AF7C: 80a4a000                 cmp     %l2, 0
F003AF80: 02800007                 be      loc_F003AF9C
F003AF84: 9010200d                 mov     0xD, %o0
F003AF88: d04c8000                 ldsb    [%l2], %o0
F003AF8C: 80a22000                 cmp     %o0, 0
F003AF90: 12800005                 bne     loc_F003AFA4
F003AF94: 90062024                 add     %i0, 0x24, %o0 ! '$'
F003AF98: 9010200d                 mov     0xD, %o0
F003AF9C: 1080008e                 ba      locret_F003B1D4
F003AFA0: d0264000                 st      %o0, [%i1]
F003AFA4: 4000040a                 call    sub_F003BFCC
F003AFA8: 9207bfb8                 add     %fp, var_48, %o1
F003AFAC: d017bfbc                 lduh    [%fp+var_44], %o0
F003AFB0: 1300003c                 sethi   0xF000, %o1
F003AFB4: 920a0009                 and     %o0, %o1, %o1
F003AFB8: 11000008                 sethi   0x2000, %o0
F003AFBC: 80a24008                 cmp     %o1, %o0
F003AFC0: 1280000a                 bne     loc_F003AFE8
F003AFC4: 11000018                 sethi   0x6000, %o0
F003AFC8: 90102004                 mov     4, %o0
F003AFCC: d207bfd0                 ld      [%fp+var_30], %o1
F003AFD0: 80a27fff                 cmp     %o1, -1
F003AFD4: 1280000b                 bne     loc_F003B000
F003AFD8: d027bfb8                 st      %o0, [%fp+var_48]
F003AFDC: 90102008                 mov     8, %o0
F003AFE0: 10800009                 ba      loc_F003B004
F003AFE4: d027bfb8                 st      %o0, [%fp+var_48]
F003AFE8: 80a24008                 cmp     %o1, %o0
F003AFEC: 12800008                 bne     loc_F003B00C
F003AFF0: 11000030                 sethi   0xC000, %o0
F003AFF4: 90102003                 mov     3, %o0
F003AFF8: d207bfd0                 ld      [%fp+var_30], %o1
F003AFFC: d027bfb8                 st      %o0, [%fp+var_48]
F003B000: d237bff0                 sth     %o1, [%fp+var_10]
F003B004: 10800007                 ba      loc_F003B020
F003B008: c027bfd0                 clr     [%fp+var_30]
F003B00C: 80a24008                 cmp     %o1, %o0
F003B010: 12800003                 bne     loc_F003B01C
F003B014: 90102001                 mov     1, %o0
F003B018: 90102006                 mov     6, %o0
F003B01C: d027bfb8                 st      %o0, [%fp+var_48]
F003B020: 90100018                 mov     %i0, %o0
F003B024: d417bfbc                 lduh    [%fp+var_44], %o2
F003B028: 9210001a                 mov     %i2, %o1
F003B02C: 940aafff                 and     %o2, 0xFFF, %o2
F003B030: 400003fc                 call    sub_F003C020
F003B034: d437bfbc                 sth     %o2, [%fp+var_44]
F003B038: a0920000                 orcc    %o0, %g0, %l0
F003B03C: 32800005                 bne,a   loc_F003B050
F003B040: d0068000                 ld      [%i2], %o0
F003B044: 90102046                 mov     0x46, %o0 ! 'F'
F003B048: 10800063                 ba      locret_F003B1D4
F003B04C: d0264000                 st      %o0, [%i1]
F003B050: 808a2001                 btst    1, %o0
F003B054: 12800045                 bne     loc_F003B168
F003B058: b010201e                 mov     0x1E, %i0
F003B05C: 808a2002                 btst    2, %o0
F003B060: 0280000a                 be      loc_F003B088
F003B064: 9206a018                 add     %i2, 0x18, %o1
F003B068: d006e01c                 ld      [%i3+0x1C], %o0
F003B06C: 40000414                 call    sub_F003C0BC
F003B070: 90022010                 inc     0x10, %o0
F003B074: 80a22000                 cmp     %o0, 0
F003B078: 32800005                 bne,a   loc_F003B08C
F003B07C: d007bfd0                 ld      [%fp+var_30], %o0
F003B080: 1080003a                 ba      loc_F003B168
F003B084: b010201e                 mov     0x1E, %i0
F003B088: d007bfd0                 ld      [%fp+var_30], %o0
F003B08C: 80a22000                 cmp     %o0, 0
F003B090: 12800011                 bne     loc_F003B0D4
F003B094: 90100010                 mov     %l0, %o0
F003B098: 40002896                 call    _svckudp_dup
F003B09C: 9010001b                 mov     %i3, %o0
F003B0A0: 80a22000                 cmp     %o0, 0
F003B0A4: 0280000b                 be      loc_F003B0D0
F003B0A8: 133c04cf                 sethi   %hi(_active_u), %o1
F003B0AC: d40261d8                 ld      [%o1+%lo(_active_u)], %o2
F003B0B0: 90100010                 mov     %l0, %o0
F003B0B4: da04201c                 ld      [%l0+0x1C], %o5
F003B0B8: 98102000                 mov     0, %o4
F003B0BC: d602a01c                 ld      [%o2+0x1C], %o3
F003B0C0: 92100012                 mov     %l2, %o1
F003B0C4: c4036020                 ld      [%o5+0x20], %g2
F003B0C8: 1080001f                 ba      loc_F003B144
F003B0CC: 9407bfb4                 add     %fp, var_4C, %o2
F003B0D0: 90100010                 mov     %l0, %o0
F003B0D4: 92100012                 mov     %l2, %o1
F003B0D8: 9407bfb8                 add     %fp, var_48, %o2
F003B0DC: 273c04cf                 sethi   %hi(_active_u), %l3
F003B0E0: d804e1d8                 ld      [%l3+%lo(_active_u)], %o4
F003B0E4: 96102000                 mov     0, %o3
F003B0E8: da03201c                 ld      [%o4+0x1C], %o5
F003B0EC: a207bfb4                 add     %fp, var_4C, %l1
F003B0F0: c404201c                 ld      [%l0+0x1C], %g2
F003B0F4: 98102080                 mov     0x80, %o4
F003B0F8: da23a05c                 st      %o5, [%sp+0xB8+var_5C]
F003B0FC: c400a024                 ld      [%g2+0x24], %g2
F003B100: 9fc08000                 call    %g2
F003B104: 9a100011                 mov     %l1, %o5
F003B108: b0920000                 orcc    %o0, %g0, %i0
F003B10C: 02800013                 be      loc_F003B158
F003B110: 01000000                 nop
F003B114: 40002877                 call    _svckudp_dup
F003B118: 9010001b                 mov     %i3, %o0
F003B11C: 80a22000                 cmp     %o0, 0
F003B120: 0280000d                 be      loc_F003B154
F003B124: d404e1d8                 ld      [%l3+0x1D8], %o2
F003B128: 90100010                 mov     %l0, %o0
F003B12C: da04201c                 ld      [%l0+0x1C], %o5
F003B130: 92100012                 mov     %l2, %o1
F003B134: d602a01c                 ld      [%o2+0x1C], %o3
F003B138: 98102000                 mov     0, %o4
F003B13C: c4036020                 ld      [%o5+0x20], %g2
F003B140: 94100011                 mov     %l1, %o2
F003B144: 9fc08000                 call    %g2
F003B148: 9a102000                 mov     0, %o5
F003B14C: 10800007                 ba      loc_F003B168
F003B150: b0100008                 mov     %o0, %i0
F003B154: 80a62000                 cmp     %i0, 0
F003B158: 12800005                 bne     loc_F003B16C
F003B15C: 80a62000                 cmp     %i0, 0
F003B160: 40002827                 call    _svckudp_dupsave
F003B164: 9010001b                 mov     %i3, %o0
F003B168: 80a62000                 cmp     %i0, 0
F003B16C: 32800018                 bne,a   loc_F003B1CC
F003B170: f0264000                 st      %i0, [%i1]
F003B174: 113c04cf                 sethi   %hi(_active_u), %o0
F003B178: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F003B17C: d402201c                 ld      [%o0+0x1C], %o2
F003B180: d007bfb4                 ld      [%fp+var_4C], %o0
F003B184: d602201c                 ld      [%o0+0x1C], %o3
F003B188: b607bfb8                 add     %fp, var_48, %i3
F003B18C: d602e014                 ld      [%o3+0x14], %o3
F003B190: 9fc2c000                 call    %o3
F003B194: 9210001b                 mov     %i3, %o1
F003B198: b0920000                 orcc    %o0, %g0, %i0
F003B19C: 12800009                 bne     loc_F003B1C0
F003B1A0: 9010001b                 mov     %i3, %o0
F003B1A4: 7ffffa89                 call    _vattr_to_nattr
F003B1A8: 92066024                 add     %i1, 0x24, %o1 ! '$'
F003B1AC: 90066004                 add     %i1, 4, %o0
F003B1B0: d207bfb4                 ld      [%fp+var_4C], %o1
F003B1B4: 7ffffc32                 call    _makefh
F003B1B8: 9410001a                 mov     %i2, %o2
F003B1BC: b0100008                 mov     %o0, %i0
F003B1C0: 7fffb669                 call    _vn_rele
F003B1C4: d007bfb4                 ld      [%fp+var_4C], %o0
F003B1C8: f0264000                 st      %i0, [%i1]
F003B1CC: 7fffb666                 call    _vn_rele
F003B1D0: 90100010                 mov     %l0, %o0
F003B1D4: 81c7e008                 ret
F003B1D8: 81e80000                 restore

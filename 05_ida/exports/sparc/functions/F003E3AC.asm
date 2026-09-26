F003E3AC: 9de3bf68                 save    %sp, -0x98, %sp
F003E3B0: a0100018                 mov     %i0, %l0
F003E3B4: f427a04c                 st      %i2, [%fp+arg_4C]
F003E3B8: 23000061                 sethi   0x18400, %l1
F003E3BC: 313c0435                 sethi   -0xFEF2C00, %i0
F003E3C0: 90100010                 mov     %l0, %o0
F003E3C4: 921462a5                 or      %l1, 0x2A5, %o1
F003E3C8: 94102001                 mov     1, %o2
F003E3CC: 40001488                 call    _pmap_kgetport
F003E3D0: 96102011                 mov     0x11, %o3
F003E3D4: b4100008                 mov     %o0, %i2
F003E3D8: 80a6bfff                 cmp     %i2, -1
F003E3DC: 02800039                 be      loc_F003E4C0
F003E3E0: 80a6a001                 cmp     %i2, 1
F003E3E4: 12800006                 bne     loc_F003E3FC
F003E3E8: 901620d0                 or      %i0, 0xD0, %o0! char *
F003E3EC: d407a04c                 ld      [%fp+arg_4C], %o2
F003E3F0: 7fff589a                 call    _printf
F003E3F4: 92100019                 mov     %i1, %o1
F003E3F8: 80a6a001                 cmp     %i2, 1
F003E3FC: 02bffff2                 be      loc_F003E3C4
F003E400: 90100010                 mov     %l0, %o0
F003E404: 293c0118                 sethi   -0xFFBA000, %l4
F003E408: 113c0119a61221a4         set     _xdr_fhstatus, %l3
F003E410: b407bfd0                 add     %fp, var_30, %i2
F003E414: 25000061                 sethi   0x18400, %l2
F003E418: 233c0435                 sethi   -0xFEF2C00, %l1
F003E41C: e623a05c                 st      %l3, [%sp+0x98+var_3C]
F003E420: f423a060                 st      %i2, [%sp+0x98+var_38]
F003E424: 90100010                 mov     %l0, %o0
F003E428: 9214a2a5                 or      %l2, 0x2A5, %o1
F003E42C: 94102001                 mov     1, %o2
F003E430: 96102001                 mov     1, %o3
F003E434: 981523cc                 or      %l4, 0x3CC, %o4
F003E438: 7fffff40                 call    sub_F003E138
F003E43C: 9a07a04c                 add     %fp, arg_4C, %o5
F003E440: b0100008                 mov     %o0, %i0
F003E444: 80a62005                 cmp     %i0, 5
F003E448: 12800006                 bne     loc_F003E460
F003E44C: 901460f8                 or      %l1, 0xF8, %o0! char *
F003E450: d407a04c                 ld      [%fp+arg_4C], %o2
F003E454: 7fff5881                 call    _printf
F003E458: 92100019                 mov     %i1, %o1
F003E45C: 80a62005                 cmp     %i0, 5
F003E460: 22bffff0                 be,a    loc_F003E420
F003E464: e623a05c                 st      %l3, [%sp+0x98+var_3C]
F003E468: 80a62000                 cmp     %i0, 0
F003E46C: 12800016                 bne     locret_F003E4C4
F003E470: 90102801                 mov     0x801, %o0
F003E474: d0342002                 sth     %o0, [%l0+2]
F003E478: d007bfd4                 ld      [%fp+var_2C], %o0
F003E47C: d026c000                 st      %o0, [%i3]
F003E480: d007bfd8                 ld      [%fp+var_28], %o0
F003E484: d026e004                 st      %o0, [%i3+4]
F003E488: d007bfdc                 ld      [%fp+var_24], %o0
F003E48C: d026e008                 st      %o0, [%i3+8]
F003E490: d007bfe0                 ld      [%fp+var_20], %o0
F003E494: d026e00c                 st      %o0, [%i3+0xC]
F003E498: d007bfe4                 ld      [%fp+var_1C], %o0
F003E49C: d026e010                 st      %o0, [%i3+0x10]
F003E4A0: d007bfe8                 ld      [%fp+var_18], %o0
F003E4A4: d026e014                 st      %o0, [%i3+0x14]
F003E4A8: d007bfec                 ld      [%fp+var_14], %o0
F003E4AC: d026e018                 st      %o0, [%i3+0x18]
F003E4B0: d007bff0                 ld      [%fp+var_10], %o0
F003E4B4: d026e01c                 st      %o0, [%i3+0x1C]
F003E4B8: 10800003                 ba      locret_F003E4C4
F003E4BC: f007bfd0                 ld      [%fp+var_30], %i0
F003E4C0: b010200f                 mov     0xF, %i0
F003E4C4: 81c7e008                 ret
F003E4C8: 81e80000                 restore

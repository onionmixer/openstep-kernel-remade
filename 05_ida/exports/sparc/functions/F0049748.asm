F0049748: 9de3bf90                 save    %sp, -0x70, %sp
F004974C: e4062050                 ld      [%i0+0x50], %l2
F0049750: d004a070                 ld      [%l2+0x70], %o0
F0049754: d204a06c                 ld      [%l2+0x6C], %o1
F0049758: 913e4008                 sra     %i1, %o0, %o0
F004975C: 912a2002                 sll     %o0, 2, %o0
F0049760: 90020012                 add     %o0, %l2, %o0
F0049764: 922e4009                 andn    %i1, %o1, %o1
F0049768: d00222d8                 ld      [%o0+0x2D8], %o0
F004976C: 932a6004                 sll     %o1, 4, %o1
F0049770: 90020009                 add     %o0, %o1, %o0
F0049774: d0022004                 ld      [%o0+4], %o0
F0049778: 80a22000                 cmp     %o0, 0
F004977C: 32800008                 bne,a   loc_F004979C
F0049780: d004a0bc                 ld      [%l2+0xBC], %o0
F0049784: d004a030                 ld      [%l2+0x30], %o0
F0049788: 80a6c008                 cmp     %i3, %o0
F004978C: 32800004                 bne,a   loc_F004979C
F0049790: d004a0bc                 ld      [%l2+0xBC], %o0
F0049794: 108000d2                 ba      locret_F0049ADC
F0049798: b0102000                 mov     0, %i0
F004979C: e2062040                 ld      [%i0+0x40], %l1
F00497A0: 7ffef358                 call    _umul
F00497A4: 92100019                 mov     %i1, %o1
F00497A8: d404a018                 ld      [%l2+0x18], %o2
F00497AC: a0100008                 mov     %o0, %l0
F00497B0: d204a01c                 ld      [%l2+0x1C], %o1
F00497B4: 9010000a                 mov     %o2, %o0
F00497B8: 7ffef352                 call    _umul
F00497BC: 922e4009                 andn    %i1, %o1, %o1
F00497C0: 92100008                 mov     %o0, %o1
F00497C4: d404a0a0                 ld      [%l2+0xA0], %o2
F00497C8: 90100011                 mov     %l1, %o0
F00497CC: d604a00c                 ld      [%l2+0xC], %o3
F00497D0: a0040009                 add     %l0, %o1, %l0
F00497D4: d204a064                 ld      [%l2+0x64], %o1
F00497D8: a004000b                 add     %l0, %o3, %l0
F00497DC: 7fff6b51                 call    _bread
F00497E0: 932c0009                 sll     %l0, %o1, %o1
F00497E4: a6100008                 mov     %o0, %l3
F00497E8: d004c000                 ld      [%l3], %o0
F00497EC: 808a2004                 btst    4, %o0
F00497F0: 1280007b                 bne     loc_F00499DC
F00497F4: e004e020                 ld      [%l3+0x20], %l0
F00497F8: d20423d4                 ld      [%l0+0x3D4], %o1
F00497FC: 1100024090122255         set     0x90255, %o0
F0049804: 80a24008                 cmp     %o1, %o0
F0049808: 12800075                 bne     loc_F00499DC
F004980C: 01000000                 nop
F0049810: d004201c                 ld      [%l0+0x1C], %o0
F0049814: 80a22000                 cmp     %o0, 0
F0049818: 12800006                 bne     loc_F0049830
F004981C: 01000000                 nop
F0049820: d004a030                 ld      [%l2+0x30], %o0
F0049824: 80a6c008                 cmp     %i3, %o0
F0049828: 0280006d                 be      loc_F00499DC
F004982C: 01000000                 nop
F0049830: 7fff25d7                 call    _getthetime
F0049834: 9007bff0                 add     %fp, var_10, %o0
F0049838: d007bff0                 ld      [%fp+var_10], %o0
F004983C: d0242008                 st      %o0, [%l0+8]
F0049840: d004a030                 ld      [%l2+0x30], %o0
F0049844: 80a6c008                 cmp     %i3, %o0
F0049848: 3280000a                 bne,a   loc_F0049870
F004984C: d004a054                 ld      [%l2+0x54], %o0
F0049850: 90100012                 mov     %l2, %o0
F0049854: 92100010                 mov     %l0, %o1
F0049858: 400000a3                 call    _alloccgblk
F004985C: 9410001a                 mov     %i2, %o2
F0049860: b0100008                 mov     %o0, %i0
F0049864: 7fff6be8                 call    _bdwrite
F0049868: 90100013                 mov     %l3, %o0
F004986C: 3080009c                 ba,a    locret_F0049ADC
F0049870: d404a038                 ld      [%l2+0x38], %o2
F0049874: b73ec008                 sra     %i3, %o0, %i3
F0049878: 80a6c00a                 cmp     %i3, %o2
F004987C: 1680000c                 bge     loc_F00498AC
F0049880: a210001b                 mov     %i3, %l1
F0049884: 912ee002                 sll     %i3, 2, %o0
F0049888: 92020010                 add     %o0, %l0, %o1
F004988C: d0026034                 ld      [%o1+0x34], %o0
F0049890: 80a22000                 cmp     %o0, 0
F0049894: 32800007                 bne,a   loc_F00498B0
F0049898: d004a038                 ld      [%l2+0x38], %o0
F004989C: a2046001                 inc     %l1
F00498A0: 80a4400a                 cmp     %l1, %o2
F00498A4: 06bffffa                 bl      loc_F004988C
F00498A8: 92026004                 inc     4, %o1
F00498AC: d004a038                 ld      [%l2+0x38], %o0
F00498B0: 80a44008                 cmp     %l1, %o0
F00498B4: 12800043                 bne     loc_F00499C0
F00498B8: 90100012                 mov     %l2, %o0
F00498BC: d004201c                 ld      [%l0+0x1C], %o0
F00498C0: 80a22000                 cmp     %o0, 0
F00498C4: 02800046                 be      loc_F00499DC
F00498C8: 90100012                 mov     %l2, %o0
F00498CC: 92100010                 mov     %l0, %o1
F00498D0: 40000085                 call    _alloccgblk
F00498D4: 9410001a                 mov     %i2, %o2
F00498D8: b0100008                 mov     %o0, %i0
F00498DC: 7ffef3f3                 call    _rem
F00498E0: d204a0bc                 ld      [%l2+0xBC], %o1
F00498E4: b4100008                 mov     %o0, %i2
F00498E8: d004a038                 ld      [%l2+0x38], %o0
F00498EC: 80a6c008                 cmp     %i3, %o0
F00498F0: 16800015                 bge     loc_F0049944
F00498F4: 9610001b                 mov     %i3, %o3
F00498F8: 98102001                 mov     1, %o4
F00498FC: 9206800b                 add     %i2, %o3, %o1
F0049900: 80a26000                 cmp     %o1, 0
F0049904: 16800003                 bge     loc_F0049910
F0049908: 90100009                 mov     %o1, %o0
F004990C: 90026007                 add     %o1, 7, %o0
F0049910: 913a2003                 sra     %o0, 3, %o0
F0049914: 94020010                 add     %o0, %l0, %o2
F0049918: 912a2003                 sll     %o0, 3, %o0
F004991C: 90224008                 sub     %o1, %o0, %o0
F0049920: d20aa3d8                 ldub    [%o2+0x3D8], %o1
F0049924: 912b0008                 sll     %o4, %o0, %o0
F0049928: 92124008                 bset    %o0, %o1
F004992C: d22aa3d8                 stb     %o1, [%o2+0x3D8]
F0049930: d004a038                 ld      [%l2+0x38], %o0
F0049934: 9602e001                 inc     %o3
F0049938: 80a2c008                 cmp     %o3, %o0
F004993C: 06bffff1                 bl      loc_F0049900
F0049940: 9206800b                 add     %i2, %o3, %o1
F0049944: d204a038                 ld      [%l2+0x38], %o1
F0049948: d0042024                 ld      [%l0+0x24], %o0
F004994C: 9622401b                 sub     %o1, %i3, %o3
F0049950: 9002000b                 add     %o0, %o3, %o0
F0049954: d0242024                 st      %o0, [%l0+0x24]
F0049958: d204a0cc                 ld      [%l2+0xCC], %o1
F004995C: d004a070                 ld      [%l2+0x70], %o0
F0049960: 9202400b                 add     %o1, %o3, %o1
F0049964: d224a0cc                 st      %o1, [%l2+0xCC]
F0049968: 913e4008                 sra     %i1, %o0, %o0
F004996C: 912a2002                 sll     %o0, 2, %o0
F0049970: d204a06c                 ld      [%l2+0x6C], %o1
F0049974: 90020012                 add     %o0, %l2, %o0
F0049978: d40222d8                 ld      [%o0+0x2D8], %o2
F004997C: 922e4009                 andn    %i1, %o1, %o1
F0049980: 932a6004                 sll     %o1, 4, %o1
F0049984: 94028009                 add     %o2, %o1, %o2
F0049988: d002a00c                 ld      [%o2+0xC], %o0
F004998C: 9002000b                 add     %o0, %o3, %o0
F0049990: d022a00c                 st      %o0, [%o2+0xC]
F0049994: 952ae002                 sll     %o3, 2, %o2
F0049998: d00ca0d0                 ldub    [%l2+0xD0], %o0
F004999C: 94028010                 add     %o2, %l0, %o2
F00499A0: 90022001                 inc     %o0
F00499A4: d02ca0d0                 stb     %o0, [%l2+0xD0]
F00499A8: d202a034                 ld      [%o2+0x34], %o1
F00499AC: 90100013                 mov     %l3, %o0
F00499B0: 92026001                 inc     %o1
F00499B4: 7fff6b94                 call    _bdwrite
F00499B8: d222a034                 st      %o1, [%o2+0x34]
F00499BC: 30800048                 ba,a    locret_F0049ADC
F00499C0: 92100010                 mov     %l0, %o1
F00499C4: 9410001a                 mov     %i2, %o2
F00499C8: 400003bf                 call    _mapsearch
F00499CC: 96100011                 mov     %l1, %o3
F00499D0: b0920000                 orcc    %o0, %g0, %i0
F00499D4: 16800006                 bge     loc_F00499EC
F00499D8: 96102000                 mov     0, %o3
F00499DC: 7fff6ba3                 call    _brelse
F00499E0: 90100013                 mov     %l3, %o0
F00499E4: 1080003e                 ba      locret_F0049ADC
F00499E8: b0102000                 mov     0, %i0
F00499EC: 80a2c01b                 cmp     %o3, %i3
F00499F0: 36800014                 bge,a   loc_F0049A40
F00499F4: d0042024                 ld      [%l0+0x24], %o0
F00499F8: 98102001                 mov     1, %o4
F00499FC: 9206000b                 add     %i0, %o3, %o1
F0049A00: 80a26000                 cmp     %o1, 0
F0049A04: 16800003                 bge     loc_F0049A10
F0049A08: 90100009                 mov     %o1, %o0
F0049A0C: 90026007                 add     %o1, 7, %o0
F0049A10: 9602e001                 inc     %o3
F0049A14: 80a2c01b                 cmp     %o3, %i3
F0049A18: 913a2003                 sra     %o0, 3, %o0
F0049A1C: 94020010                 add     %o0, %l0, %o2
F0049A20: 912a2003                 sll     %o0, 3, %o0
F0049A24: 90224008                 sub     %o1, %o0, %o0
F0049A28: d20aa3d8                 ldub    [%o2+0x3D8], %o1
F0049A2C: 912b0008                 sll     %o4, %o0, %o0
F0049A30: 902a4008                 andn    %o1, %o0, %o0
F0049A34: 06bffff2                 bl      loc_F00499FC
F0049A38: d02aa3d8                 stb     %o0, [%o2+0x3D8]
F0049A3C: d0042024                 ld      [%l0+0x24], %o0
F0049A40: 9022001b                 sub     %o0, %i3, %o0
F0049A44: d0242024                 st      %o0, [%l0+0x24]
F0049A48: d204a0cc                 ld      [%l2+0xCC], %o1
F0049A4C: d004a070                 ld      [%l2+0x70], %o0
F0049A50: 9222401b                 sub     %o1, %i3, %o1
F0049A54: d224a0cc                 st      %o1, [%l2+0xCC]
F0049A58: 913e4008                 sra     %i1, %o0, %o0
F0049A5C: 912a2002                 sll     %o0, 2, %o0
F0049A60: d204a06c                 ld      [%l2+0x6C], %o1
F0049A64: 90020012                 add     %o0, %l2, %o0
F0049A68: d40222d8                 ld      [%o0+0x2D8], %o2
F0049A6C: 922e4009                 andn    %i1, %o1, %o1
F0049A70: 932a6004                 sll     %o1, 4, %o1
F0049A74: 94028009                 add     %o2, %o1, %o2
F0049A78: d002a00c                 ld      [%o2+0xC], %o0
F0049A7C: 932c6002                 sll     %l1, 2, %o1
F0049A80: 9022001b                 sub     %o0, %i3, %o0
F0049A84: d022a00c                 st      %o0, [%o2+0xC]
F0049A88: d00ca0d0                 ldub    [%l2+0xD0], %o0
F0049A8C: 92024010                 add     %o1, %l0, %o1
F0049A90: 90022001                 inc     %o0
F0049A94: d02ca0d0                 stb     %o0, [%l2+0xD0]
F0049A98: d0026034                 ld      [%o1+0x34], %o0
F0049A9C: 80a6c011                 cmp     %i3, %l1
F0049AA0: 90023fff                 inc     -1, %o0
F0049AA4: 02800008                 be      loc_F0049AC4
F0049AA8: d0226034                 st      %o0, [%o1+0x34]
F0049AAC: 9224401b                 sub     %l1, %i3, %o1
F0049AB0: 932a6002                 sll     %o1, 2, %o1
F0049AB4: 92024010                 add     %o1, %l0, %o1
F0049AB8: d0026034                 ld      [%o1+0x34], %o0
F0049ABC: 90022001                 inc     %o0
F0049AC0: d0226034                 st      %o0, [%o1+0x34]
F0049AC4: 7fff6b50                 call    _bdwrite
F0049AC8: 90100013                 mov     %l3, %o0
F0049ACC: d204a0bc                 ld      [%l2+0xBC], %o1
F0049AD0: 7ffef28c                 call    _umul
F0049AD4: 90100019                 mov     %i1, %o0
F0049AD8: b0020018                 add     %o0, %i0, %i0
F0049ADC: 81c7e008                 ret
F0049AE0: 81e80000                 restore

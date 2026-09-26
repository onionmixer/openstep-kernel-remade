F00B37A0: 9de3bf98                 save    %sp, -0x68, %sp
F00B37A4: ae102000                 mov     0, %l7
F00B37A8: 113c04fc                 sethi   %hi(_nesp), %o0
F00B37AC: d0022098                 ld      [%o0+%lo(_nesp)], %o0
F00B37B0: 80a5c008                 cmp     %l7, %o0
F00B37B4: 1680001f                 bge     loc_F00B3830
F00B37B8: c026202c                 clr     [%i0+0x2C]
F00B37BC: d0062010                 ld      [%i0+0x10], %o0
F00B37C0: 80a22002                 cmp     %o0, 2
F00B37C4: 3480017c                 bg,a    locret_F00B3DB4
F00B37C8: b0103fff                 mov     -1, %i0
F00B37CC: d0062018                 ld      [%i0+0x18], %o0
F00B37D0: 80a22000                 cmp     %o0, 0
F00B37D4: 22800178                 be,a    locret_F00B3DB4
F00B37D8: b0103fff                 mov     -1, %i0
F00B37DC: d4062014                 ld      [%i0+0x14], %o2
F00B37E0: d002a004                 ld      [%o2+4], %o0
F00B37E4: d202a008                 ld      [%o2+8], %o1
F00B37E8: 7ffff78d                 call    _map_regs
F00B37EC: d4028000                 ld      [%o2], %o2
F00B37F0: ac920000                 orcc    %o0, %g0, %l6
F00B37F4: 32800005                 bne,a   loc_F00B3808
F00B37F8: d2062014                 ld      [%i0+0x14], %o1
F00B37FC: 113c0478                 sethi   %hi(aEspDUnableToMa), %o0! "esp%d: unable to map registers\n"
F00B3800: 1080000a                 ba      loc_F00B3828
F00B3804: 90122338                 bset    %lo(aEspDUnableToMa), %o0! "esp%d: unable to map registers\n"
F00B3808: d0024000                 ld      [%o1], %o0
F00B380C: 7ffffa95                 call    _dma_alloc
F00B3810: d2026004                 ld      [%o1+4], %o1
F00B3814: aa920000                 orcc    %o0, %g0, %l5
F00B3818: 32800008                 bne,a   loc_F00B3838
F00B381C: d2054000                 ld      [%l5], %o1
F00B3820: 113c047890122358         set     aEspDCannotFind, %o0! "esp%d: cannot find dma controller\n"
F00B3828: 7ffd838c                 call    _printf
F00B382C: 92102000                 mov     0, %o1
F00B3830: 10800161                 ba      locret_F00B3DB4
F00B3834: b0103fff                 mov     -1, %i0
F00B3838: 9132601c                 srl     %o1, 28, %o0
F00B383C: 80a22004                 cmp     %o0, 4
F00B3840: 32800005                 bne,a   loc_F00B3854
F00B3844: d2054000                 ld      [%l5], %o1
F00B3848: 900a7f7f                 and     %o1, -0x81, %o0
F00B384C: d0254000                 st      %o0, [%l5]
F00B3850: d2054000                 ld      [%l5], %o1
F00B3854: 901021b8                 mov     0x1B8, %o0
F00B3858: 920a7eff                 and     %o1, -0x101, %o1! size_t
F00B385C: 7ffed205                 call    _kalloc
F00B3860: d2254000                 st      %o1, [%l5]
F00B3864: a4920000                 orcc    %o0, %g0, %l2
F00B3868: 22800010                 be,a    loc_F00B38A8
F00B386C: d004a048                 ld      [%l2+0x48], %o0! void *
F00B3870: 7fff857a                 call    _bzero
F00B3874: 921021b8                 mov     0x1B8, %o1
F00B3878: 113c04f6                 sethi   %hi(_iopbmap), %o0
F00B387C: d0022300                 ld      [%o0+%lo(_iopbmap)], %o0
F00B3880: 7fffc578                 call    _rmalloc
F00B3884: 92102010                 mov     0x10, %o1
F00B3888: d024a048                 st      %o0, [%l2+0x48]
F00B388C: 80a4a000                 cmp     %l2, 0
F00B3890: 02800006                 be      loc_F00B38A8
F00B3894: d004a048                 ld      [%l2+0x48], %o0
F00B3898: 80a22000                 cmp     %o0, 0
F00B389C: 32800018                 bne,a   loc_F00B38FC
F00B38A0: c02ca030                 clrb    [%l2+0x30]
F00B38A4: d004a048                 ld      [%l2+0x48], %o0
F00B38A8: 80a22000                 cmp     %o0, 0
F00B38AC: 113c0478                 sethi   %hi(aEspDNoSpaceFor), %o0! "esp%d: no space for %s\n"
F00B38B0: 02800005                 be      loc_F00B38C4
F00B38B4: 92122380                 or      %o0, %lo(aEspDNoSpaceFor), %o1! "esp%d: no space for %s\n"
F00B38B8: 113c0478                 sethi   %hi(aCmdAreas), %o0! "cmd areas"
F00B38BC: 10800004                 ba      loc_F00B38CC
F00B38C0: 94122398                 or      %o0, %lo(aCmdAreas), %o2! "cmd areas"
F00B38C4: 113c0478941223a8         set     aDataStructures, %o2! "data structures"
F00B38CC: 90100009                 mov     %o1, %o0! char *
F00B38D0: 7ffd8362                 call    _printf
F00B38D4: 92102000                 mov     0, %o1
F00B38D8: 80a4a000                 cmp     %l2, 0
F00B38DC: 02800004                 be      loc_F00B38EC
F00B38E0: 90100012                 mov     %l2, %o0
F00B38E4: 7ffed22f                 call    _kfree
F00B38E8: 921021b8                 mov     0x1B8, %o1
F00B38EC: 7ffffa89                 call    _dma_free
F00B38F0: 90100015                 mov     %l5, %o0
F00B38F4: 10800130                 ba      locret_F00B3DB4
F00B38F8: b0103fff                 mov     -1, %i0
F00B38FC: 133c0478                 sethi   %hi(_esp_softc), %o1
F00B3900: d00261a8                 ld      [%o1+%lo(_esp_softc)], %o0
F00B3904: 80a22000                 cmp     %o0, 0
F00B3908: 1280000b                 bne     loc_F00B3934
F00B390C: c024a028                 clr     [%l2+0x28]
F00B3910: e42261a8                 st      %l2, [%o1+%lo(_esp_softc)]
F00B3914: 113c02dd                 sethi   %hi(_esp_watch), %o0
F00B3918: 133c043e                 sethi   %hi(_hz), %o1
F00B391C: d40263e0                 ld      [%o1+%lo(_hz)], %o2
F00B3920: 901220f0                 bset    %lo(_esp_watch), %o0! int
F00B3924: 7ffd59c1                 call    _timeout
F00B3928: 92102000                 mov     0, %o1
F00B392C: 10800009                 ba      loc_F00B3950
F00B3930: 80a62000                 cmp     %i0, 0
F00B3934: 92100008                 mov     %o0, %o1
F00B3938: d0026028                 ld      [%o1+0x28], %o0
F00B393C: 80a22000                 cmp     %o0, 0
F00B3940: 32bffffe                 bne,a   loc_F00B3938
F00B3944: d2026028                 ld      [%o1+0x28], %o1
F00B3948: e4226028                 st      %l2, [%o1+0x28]
F00B394C: 80a62000                 cmp     %i0, 0
F00B3950: 02800012                 be      loc_F00B3998
F00B3954: a0100018                 mov     %i0, %l0
F00B3958: 293c0478                 sethi   -0xFEE2000, %l4
F00B395C: 273c04fb                 sethi   -0xFEC1400, %l3
F00B3960: d0042028                 ld      [%l0+0x28], %o0
F00B3964: d2052308                 ld      [%l4+0x308], %o1
F00B3968: 7ffff5d1                 call    _getprop
F00B396C: 94103fff                 mov     -1, %o2
F00B3970: a2920000                 orcc    %o0, %g0, %l1
F00B3974: 14800009                 bg      loc_F00B3998
F00B3978: d004e088                 ld      [%l3+0x88], %o0
F00B397C: 80a40008                 cmp     %l0, %o0
F00B3980: 22800007                 be,a    loc_F00B399C
F00B3984: 11001312                 sethi   0x4C4800, %o0
F00B3988: e0040000                 ld      [%l0], %l0
F00B398C: 80a42000                 cmp     %l0, 0
F00B3990: 32bffff5                 bne,a   loc_F00B3964
F00B3994: d0042028                 ld      [%l0+0x28], %o0
F00B3998: 11001312                 sethi   0x4C4800, %o0
F00B399C: 92122340                 or      %o0, 0x340, %o1! int
F00B39A0: 80a44009                 cmp     %l1, %o1
F00B39A4: 04800007                 ble     loc_F00B39C0
F00B39A8: 11001312                 sethi   0x4C4800, %o0
F00B39AC: 9012233f                 bset    0x33F, %o0! int
F00B39B0: 7ffd4b16                 call    _div
F00B39B4: 90044008                 add     %l1, %o0, %o0
F00B39B8: 10800003                 ba      loc_F00B39C4
F00B39BC: b2100008                 mov     %o0, %i1
F00B39C0: b2102000                 mov     0, %i1
F00B39C4: 90067ffe                 add     %i1, -2, %o0
F00B39C8: 900a20ff                 and     %o0, 0xFF, %o0
F00B39CC: 80a22006                 cmp     %o0, 6
F00B39D0: 0880000b                 bleu    loc_F00B39FC
F00B39D4: 153c0478                 sethi   %hi(aBadClockFreque), %o2! "Bad clock frequency- setting 20mhz, asy"...
F00B39D8: 90100012                 mov     %l2, %o0
F00B39DC: 92102003                 mov     3, %o1! int
F00B39E0: 40001083                 call    _esplog
F00B39E4: 9412a3b8                 bset    %lo(aBadClockFreque), %o2! "Bad clock frequency- setting 20mhz, asy"...
F00B39E8: 901020ff                 mov     0xFF, %o0
F00B39EC: d02ca07a                 stb     %o0, [%l2+0x7A]
F00B39F0: b2102004                 mov     4, %i1
F00B39F4: 11004c4ba2122100         set     0x1312D00, %l1
F00B39FC: f22ca03d                 stb     %i1, [%l2+0x3D]
F00B3A00: 90100011                 mov     %l1, %o0! int
F00B3A04: 7ffd4b01                 call    _div
F00B3A08: 921023e8                 mov     0x3E8, %o1
F00B3A0C: 92100008                 mov     %o0, %o1! int
F00B3A10: 110ee6b2                 sethi   0x3B9AC800, %o0! int
F00B3A14: 7ffd4afd                 call    _div
F00B3A18: 90122200                 bset    0x200, %o0
F00B3A1C: d034a03e                 sth     %o0, [%l2+0x3E]
F00B3A20: 912a2010                 sll     %o0, 16, %o0
F00B3A24: 91322010                 srl     %o0, 16, %o0
F00B3A28: 932a2004                 sll     %o0, 4, %o1
F00B3A2C: 92224008                 sub     %o1, %o0, %o1
F00B3A30: 932a6008                 sll     %o1, 8, %o1
F00B3A34: 92024008                 add     %o1, %o0, %o1
F00B3A38: d00ca03d                 ldub    [%l2+0x3D], %o0! int
F00B3A3C: 7ffd4ab1                 call    _umul
F00B3A40: 932a6001                 sll     %o1, 1, %o1! int
F00B3A44: 7ffd4af1                 call    _div
F00B3A48: 921023e8                 mov     0x3E8, %o1
F00B3A4C: 92100008                 mov     %o0, %o1
F00B3A50: 1103b9ac9012227f         set     0xEE6B27F, %o0
F00B3A58: 7ffd4aea                 call    _udiv
F00B3A5C: 90024008                 add     %o1, %o0, %o0
F00B3A60: d02ca040                 stb     %o0, [%l2+0x40]
F00B3A64: d006201c                 ld      [%i0+0x1C], %o0
F00B3A68: 7fff9992                 call    _ipltospl
F00B3A6C: d0020000                 ld      [%o0], %o0
F00B3A70: 80a5c008                 cmp     %l7, %o0
F00B3A74: 16800003                 bge     loc_F00B3A80
F00B3A78: d024a0b4                 st      %o0, [%l2+0xB4]
F00B3A7C: ae100008                 mov     %o0, %l7
F00B3A80: 113c0478                 sethi   %hi(_esp_softc), %o0
F00B3A84: d20221a8                 ld      [%o0+%lo(_esp_softc)], %o1
F00B3A88: 80a26000                 cmp     %o1, 0
F00B3A8C: 02800008                 be      loc_F00B3AAC
F00B3A90: 113c02cf                 sethi   -0xFF4C400, %o0
F00B3A94: ee224000                 st      %l7, [%o1]
F00B3A98: d2026028                 ld      [%o1+0x28], %o1
F00B3A9C: 80a26000                 cmp     %o1, 0
F00B3AA0: 32bffffe                 bne,a   loc_F00B3A98
F00B3AA4: ee224000                 st      %l7, [%o1]
F00B3AA8: 113c02cf                 sethi   -0xFF4C400, %o0
F00B3AAC: 901221bc                 bset    0x1BC, %o0
F00B3AB0: d024a004                 st      %o0, [%l2+4]
F00B3AB4: 113c02cf901222c0         set     _esp_abort, %o0
F00B3ABC: d024a00c                 st      %o0, [%l2+0xC]
F00B3AC0: 113c02d0901220d0         set     _esp_reset, %o0
F00B3AC8: d024a008                 st      %o0, [%l2+8]
F00B3ACC: 113c02d1901220ac         set     _esp_getcap, %o0
F00B3AD4: d024a010                 st      %o0, [%l2+0x10]
F00B3AD8: 113c02d1901220d0         set     _esp_setcap, %o0
F00B3AE0: d024a014                 st      %o0, [%l2+0x14]
F00B3AE4: 113c02e290122180         set     _scsi_std_pktalloc, %o0
F00B3AEC: d024a018                 st      %o0, [%l2+0x18]
F00B3AF0: 113c02e290122390         set     _scsi_std_dmaget, %o0
F00B3AF8: d024a01c                 st      %o0, [%l2+0x1C]
F00B3AFC: 113c02e290122300         set     _scsi_std_pktfree, %o0
F00B3B04: d024a020                 st      %o0, [%l2+0x20]
F00B3B08: 113c02e3901221c8         set     _scsi_std_dmafree, %o0
F00B3B10: d024a024                 st      %o0, [%l2+0x24]
F00B3B14: f024a02c                 st      %i0, [%l2+0x2C]
F00B3B18: 90102007                 mov     7, %o0
F00B3B1C: d02ca032                 stb     %o0, [%l2+0x32]
F00B3B20: 80a62000                 cmp     %i0, 0
F00B3B24: 02800027                 be      loc_F00B3BC0
F00B3B28: a0100018                 mov     %i0, %l0
F00B3B2C: 353c0478                 sethi   -0xFEE2000, %i2
F00B3B30: 2f3c0478                 sethi   -0xFEE2000, %l7
F00B3B34: 293c0478                 sethi   -0xFEE2000, %l4
F00B3B38: 273c04fb                 sethi   -0xFEC1400, %l3
F00B3B3C: d0042028                 ld      [%l0+0x28], %o0
F00B3B40: d206a2d8                 ld      [%i2+0x2D8], %o1
F00B3B44: 7ffff55a                 call    _getprop
F00B3B48: 94103fff                 mov     -1, %o2
F00B3B4C: a2100008                 mov     %o0, %l1
F00B3B50: 80a47fff                 cmp     %l1, -1
F00B3B54: 12800008                 bne     loc_F00B3B74
F00B3B58: 80a46007                 cmp     %l1, 7
F00B3B5C: d0042028                 ld      [%l0+0x28], %o0
F00B3B60: d205e2f4                 ld      [%l7+0x2F4], %o1
F00B3B64: 7ffff552                 call    _getprop
F00B3B68: 94103fff                 mov     -1, %o2
F00B3B6C: a2100008                 mov     %o0, %l1
F00B3B70: 80a46007                 cmp     %l1, 7
F00B3B74: 02800009                 be      loc_F00B3B98
F00B3B78: 80a46007                 cmp     %l1, 7
F00B3B7C: 18800007                 bgu     loc_F00B3B98
F00B3B80: 90100012                 mov     %l2, %o0
F00B3B84: 92102006                 mov     6, %o1
F00B3B88: 941523f0                 or      %l4, 0x3F0, %o2
F00B3B8C: 40001018                 call    _esplog
F00B3B90: 96100011                 mov     %l1, %o3
F00B3B94: e22ca032                 stb     %l1, [%l2+0x32]
F00B3B98: 80a47fff                 cmp     %l1, -1
F00B3B9C: 14800009                 bg      loc_F00B3BC0
F00B3BA0: d004e088                 ld      [%l3+0x88], %o0
F00B3BA4: 80a40008                 cmp     %l0, %o0
F00B3BA8: 22800007                 be,a    loc_F00B3BC4
F00B3BAC: 113c047c                 sethi   -0xFEE1000, %o0
F00B3BB0: e0040000                 ld      [%l0], %l0
F00B3BB4: 80a42000                 cmp     %l0, 0
F00B3BB8: 32bfffe2                 bne,a   loc_F00B3B40
F00B3BBC: d0042028                 ld      [%l0+0x28], %o0
F00B3BC0: 113c047c                 sethi   -0xFEE1000, %o0
F00B3BC4: d0022158                 ld      [%o0+0x158], %o0
F00B3BC8: 808a2040                 btst    0x40, %o0 ! '@'
F00B3BCC: 22800006                 be,a    loc_F00B3BE4
F00B3BD0: ec24a09c                 st      %l6, [%l2+0x9C]
F00B3BD4: d00ca032                 ldub    [%l2+0x32], %o0
F00B3BD8: 90122010                 bset    0x10, %o0
F00B3BDC: d02ca032                 stb     %o0, [%l2+0x32]
F00B3BE0: ec24a09c                 st      %l6, [%l2+0x9C]
F00B3BE4: ea24a0a0                 st      %l5, [%l2+0xA0]
F00B3BE8: 293c0478                 sethi   -0xFEE2000, %l4
F00B3BEC: 113c0478                 sethi   %hi(_espconf), %o0
F00B3BF0: d202219c                 ld      [%o0+%lo(_espconf)], %o1
F00B3BF4: 273c04fb                 sethi   -0xFEC1400, %l3
F00B3BF8: e004a02c                 ld      [%l2+0x2C], %l0
F00B3BFC: 920a7ff8                 and     %o1, -8, %o1
F00B3C00: d00ca032                 ldub    [%l2+0x32], %o0
F00B3C04: 92126040                 bset    0x40, %o1 ! '@'
F00B3C08: 90120009                 bset    %o1, %o0
F00B3C0C: d02ca032                 stb     %o0, [%l2+0x32]
F00B3C10: 901020ff                 mov     0xFF, %o0
F00B3C14: d02ca07c                 stb     %o0, [%l2+0x7C]
F00B3C18: d0042028                 ld      [%l0+0x28], %o0
F00B3C1C: d205231c                 ld      [%l4+0x31C], %o1
F00B3C20: 7ffff523                 call    _getprop
F00B3C24: 94103fff                 mov     -1, %o2
F00B3C28: a2100008                 mov     %o0, %l1
F00B3C2C: 80a47fff                 cmp     %l1, -1
F00B3C30: 22800006                 be,a    loc_F00B3C48
F00B3C34: e0040000                 ld      [%l0], %l0
F00B3C38: d00ca07c                 ldub    [%l2+0x7C], %o0
F00B3C3C: 900a0011                 and     %o0, %l1, %o0
F00B3C40: d02ca07c                 stb     %o0, [%l2+0x7C]
F00B3C44: e0040000                 ld      [%l0], %l0
F00B3C48: d004e088                 ld      [%l3+0x88], %o0
F00B3C4C: 80a40008                 cmp     %l0, %o0
F00B3C50: 32bffff3                 bne,a   loc_F00B3C1C
F00B3C54: d0042028                 ld      [%l0+0x28], %o0
F00B3C58: e20ca07c                 ldub    [%l2+0x7C], %l1
F00B3C5C: 80a460ff                 cmp     %l1, 0xFF
F00B3C60: 02800004                 be      loc_F00B3C70
F00B3C64: 808c6030                 btst    0x30, %l1 ! '0'
F00B3C68: 32800005                 bne,a   loc_F00B3C7C
F00B3C6C: 113ffc00                 sethi   -0x100000, %o0
F00B3C70: 9010201f                 mov     0x1F, %o0
F00B3C74: d02ca07c                 stb     %o0, [%l2+0x7C]
F00B3C78: 113ffc00                 sethi   -0x100000, %o0
F00B3C7C: 90122000                 bset    0, %o0
F00B3C80: d024a0ac                 st      %o0, [%l2+0xAC]
F00B3C84: 90103fff                 mov     -1, %o0
F00B3C88: d034a0b2                 sth     %o0, [%l2+0xB2]
F00B3C8C: d034a0b0                 sth     %o0, [%l2+0xB0]
F00B3C90: d406200c                 ld      [%i0+0xC], %o2
F00B3C94: 133c02d3                 sethi   %hi(_esp_poll), %o1
F00B3C98: d606202c                 ld      [%i0+0x2C], %o3
F00B3C9C: 92126074                 bset    %lo(_esp_poll), %o1
F00B3CA0: d006201c                 ld      [%i0+0x1C], %o0
F00B3CA4: 9810001b                 mov     %i3, %o4
F00B3CA8: d0020000                 ld      [%o0], %o0
F00B3CAC: 7fff94ec                 call    _addintr
F00B3CB0: 9a10001c                 mov     %i4, %o5
F00B3CB4: d006201c                 ld      [%i0+0x1C], %o0
F00B3CB8: 7ffff6a4                 call    _adddma
F00B3CBC: d0020000                 ld      [%o0], %o0
F00B3CC0: 7ffff45e                 call    _report_dev
F00B3CC4: 90100018                 mov     %i0, %o0
F00B3CC8: 9010200a                 mov     0xA, %o0
F00B3CCC: d02da02c                 stb     %o0, [%l6+0x2C]
F00B3CD0: 9010202d                 mov     0x2D, %o0 ! '-'
F00B3CD4: d02ca076                 stb     %o0, [%l2+0x76]
F00B3CD8: d00da02c                 ldub    [%l6+0x2C], %o0
F00B3CDC: 900a200f                 and     %o0, 0xF, %o0
F00B3CE0: 80a2200a                 cmp     %o0, 0xA
F00B3CE4: 32800020                 bne,a   loc_F00B3D64
F00B3CE8: c02ca031                 clrb    [%l2+0x31]
F00B3CEC: a2102000                 mov     0, %l1
F00B3CF0: 113c0478                 sethi   %hi(_espconf2), %o0
F00B3CF4: d00221a0                 ld      [%o0+%lo(_espconf2)], %o0
F00B3CF8: 153c0478                 sethi   -0xFEE2000, %o2
F00B3CFC: d02ca033                 stb     %o0, [%l2+0x33]
F00B3D00: 90102005                 mov     5, %o0
F00B3D04: d02da030                 stb     %o0, [%l6+0x30]
F00B3D08: 92048011                 add     %l2, %l1, %o1
F00B3D0C: a2046001                 inc     %l1
F00B3D10: d002a1a4                 ld      [%o2+0x1A4], %o0
F00B3D14: 80a46007                 cmp     %l1, 7
F00B3D18: 04bffffc                 ble     loc_F00B3D08
F00B3D1C: d02a6034                 stb     %o0, [%o1+0x34]
F00B3D20: 900e60ff                 and     %i1, 0xFF, %o0
F00B3D24: 80a22005                 cmp     %o0, 5
F00B3D28: 08800009                 bleu    loc_F00B3D4C
F00B3D2C: d00ca033                 ldub    [%l2+0x33], %o0
F00B3D30: 90122040                 bset    0x40, %o0 ! '@'
F00B3D34: d02ca033                 stb     %o0, [%l2+0x33]
F00B3D38: d02da02c                 stb     %o0, [%l6+0x2C]
F00B3D3C: 90102019                 mov     0x19, %o0
F00B3D40: d02ca076                 stb     %o0, [%l2+0x76]
F00B3D44: 10800004                 ba      loc_F00B3D54
F00B3D48: 90102005                 mov     5, %o0
F00B3D4C: d02da02c                 stb     %o0, [%l6+0x2C]
F00B3D50: 90102002                 mov     2, %o0
F00B3D54: d02ca031                 stb     %o0, [%l2+0x31]
F00B3D58: 113c0478                 sethi   %hi(_espconf3), %o0
F00B3D5C: d00221a4                 ld      [%o0+%lo(_espconf3)], %o0
F00B3D60: d02da030                 stb     %o0, [%l6+0x30]
F00B3D64: d0062028                 ld      [%i0+0x28], %o0
F00B3D68: 133c0478                 sethi   %hi(off_F011E330), %o1! "differential"
F00B3D6C: d2026330                 ld      [%o1+%lo(off_F011E330)], %o1! "differential"
F00B3D70: 7ffff4cf                 call    _getprop
F00B3D74: 94103fff                 mov     -1, %o2
F00B3D78: 80a23fff                 cmp     %o0, -1
F00B3D7C: 22800006                 be,a    loc_F00B3D94
F00B3D80: 90100012                 mov     %l2, %o0
F00B3D84: d00ca03c                 ldub    [%l2+0x3C], %o0
F00B3D88: 90022001                 inc     %o0
F00B3D8C: d02ca03c                 stb     %o0, [%l2+0x3C]
F00B3D90: 90100012                 mov     %l2, %o0
F00B3D94: 40000eb4                 call    _esp_internal_reset
F00B3D98: 9210201f                 mov     0x1F, %o1
F00B3D9C: 90100012                 mov     %l2, %o0
F00B3DA0: 400010dd                 call    _scsi_config
F00B3DA4: 92100018                 mov     %i0, %o1
F00B3DA8: 400010d6                 call    _scsa_config
F00B3DAC: 90100012                 mov     %l2, %o0
F00B3DB0: b0102000                 mov     0, %i0
F00B3DB4: 81c7e008                 ret
F00B3DB8: 81e80000                 restore

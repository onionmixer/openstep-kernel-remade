F009DC78: 9de3bf98                 save    %sp, -0x68, %sp
F009DC7C: 80a6a001                 cmp     %i2, 1
F009DC80: 028000ac                 be      locret_F009DF30
F009DC84: f227a048                 st      %i1, [%fp+arg_48]
F009DC88: 133c04f792126270         set     _pmap_info, %o1
F009DC90: d002605c                 ld      [%o1+0x5C], %o0
F009DC94: 90022001                 inc     %o0
F009DC98: 7fffe419                 call    _splvm
F009DC9C: d022605c                 st      %o0, [%o1+0x5C]
F009DCA0: f2060000                 ld      [%i0], %i1
F009DCA4: d20fa048                 ldub    [%fp+arg_48], %o1
F009DCA8: a2100008                 mov     %o0, %l1
F009DCAC: d4064000                 ld      [%i1], %o2
F009DCB0: 932a6002                 sll     %o1, 2, %o1
F009DCB4: d6028009                 ld      [%o2+%o1], %o3
F009DCB8: 900ae003                 and     %o3, 3, %o0
F009DCBC: 80a22001                 cmp     %o0, 1
F009DCC0: 0280000d                 be      loc_F009DCF4
F009DCC4: a4028009                 add     %o2, %o1, %l2
F009DCC8: 80a22001                 cmp     %o0, 1
F009DCCC: 14800006                 bg      loc_F009DCE4
F009DCD0: 80a22002                 cmp     %o0, 2
F009DCD4: 80a22000                 cmp     %o0, 0
F009DCD8: 0280001a                 be      loc_F009DD40
F009DCDC: 113c045f                 sethi   -0xFEE8400, %o0
F009DCE0: 30800041                 ba,a    loc_F009DDE4
F009DCE4: 22800015                 be,a    loc_F009DD38
F009DCE8: 113c045f                 sethi   -0xFEE8400, %o0
F009DCEC: 1080003e                 ba      loc_F009DDE4
F009DCF0: 113c045f                 sethi   -0xFEE8400, %o0
F009DCF4: d007a048                 ld      [%fp+arg_48], %o0
F009DCF8: 333fc000                 sethi   -0x1000000, %i1
F009DCFC: d206200c                 ld      [%i0+0xC], %o1
F009DD00: 900a0019                 and     %o0, %i1, %o0
F009DD04: 80a20009                 cmp     %o0, %o1
F009DD08: 32800004                 bne,a   loc_F009DD18
F009DD0C: 9132e002                 srl     %o3, 2, %o0
F009DD10: 10800037                 ba      loc_F009DDEC
F009DD14: e0062004                 ld      [%i0+4], %l0
F009DD18: 4000122b                 call    _pmap_seg_entry
F009DD1C: 912a2006                 sll     %o0, 6, %o0
F009DD20: a0100008                 mov     %o0, %l0
F009DD24: d007a048                 ld      [%fp+arg_48], %o0
F009DD28: e0262004                 st      %l0, [%i0+4]
F009DD2C: 900a0019                 and     %o0, %i1, %o0! char *
F009DD30: 1080002f                 ba      loc_F009DDEC
F009DD34: d026200c                 st      %o0, [%i0+0xC]
F009DD38: 7ffddd0e                 call    _panic
F009DD3C: 90122258                 bset    0x258, %o0
F009DD40: 7fffe3f9                 call    _splx
F009DD44: 90100011                 mov     %l1, %o0
F009DD48: 90100018                 mov     %i0, %o0
F009DD4C: d207a048                 ld      [%fp+arg_48], %o1
F009DD50: 40001302                 call    _pmap_alloc_seg_entry
F009DD54: 94102002                 mov     2, %o2
F009DD58: 7fffffab                 call    _check_ptbl
F009DD5C: a0100008                 mov     %o0, %l0
F009DD60: 80a22000                 cmp     %o0, 0
F009DD64: 02800004                 be      loc_F009DD74
F009DD68: 113c045f                 sethi   %hi(aPmapExpandPage), %o0! "pmap_expand: page_table non-zero\n"
F009DD6C: 7ffddd01                 call    _panic
F009DD70: 90122270                 bset    %lo(aPmapExpandPage), %o0! "pmap_expand: page_table non-zero\n"
F009DD74: 7fffffb8                 call    _check_pmap
F009DD78: 90100010                 mov     %l0, %o0
F009DD7C: 7fffe3e0                 call    _splvm
F009DD80: 01000000                 nop
F009DD84: d2048000                 ld      [%l2], %o1
F009DD88: 808a6003                 btst    3, %o1
F009DD8C: 02800007                 be      loc_F009DDA8
F009DD90: a2100008                 mov     %o0, %l1
F009DD94: 7fffe3e4                 call    _splx
F009DD98: 01000000                 nop
F009DD9C: 400013fd                 call    _pmap_dealloc_seg_entry
F009DDA0: 90100010                 mov     %l0, %o0
F009DDA4: 30800063                 ba,a    locret_F009DF30
F009DDA8: d207a048                 ld      [%fp+arg_48], %o1
F009DDAC: d6042004                 ld      [%l0+4], %o3
F009DDB0: d40c200e                 ldub    [%l0+0xE], %o2
F009DDB4: 90100019                 mov     %i1, %o0
F009DDB8: d602e004                 ld      [%o3+4], %o3
F009DDBC: 952aa008                 sll     %o2, 8, %o2
F009DDC0: 40000f51                 call    _set_ptp
F009DDC4: 9402c00a                 add     %o3, %o2, %o2
F009DDC8: f2242020                 st      %i1, [%l0+0x20]
F009DDCC: e0262004                 st      %l0, [%i0+4]
F009DDD0: d007a048                 ld      [%fp+arg_48], %o0
F009DDD4: 133fc000                 sethi   -0x1000000, %o1
F009DDD8: 900a0009                 and     %o0, %o1, %o0! char *
F009DDDC: 10800004                 ba      loc_F009DDEC
F009DDE0: d026200c                 st      %o0, [%i0+0xC]
F009DDE4: 7ffddce3                 call    _panic
F009DDE8: 90122298                 bset    0x298, %o0
F009DDEC: 80a6a002                 cmp     %i2, 2
F009DDF0: 02800050                 be      locret_F009DF30
F009DDF4: d607a048                 ld      [%fp+arg_48], %o3
F009DDF8: e4040000                 ld      [%l0], %l2
F009DDFC: 9132e010                 srl     %o3, 16, %o0
F009DE00: b40a20fc                 and     %o0, 0xFC, %i2
F009DE04: d404801a                 ld      [%l2+%i2], %o2
F009DE08: 900aa003                 and     %o2, 3, %o0
F009DE0C: 80a22001                 cmp     %o0, 1
F009DE10: 2280000c                 be,a    loc_F009DE40
F009DE14: 213fff00                 sethi   -0x40000, %l0
F009DE18: 14800006                 bg      loc_F009DE30
F009DE1C: 80a22002                 cmp     %o0, 2
F009DE20: 80a22000                 cmp     %o0, 0
F009DE24: 02800016                 be      loc_F009DE7C
F009DE28: 113c045f                 sethi   -0xFEE8400, %o0
F009DE2C: 3080003d                 ba,a    loc_F009DF20
F009DE30: 22800010                 be,a    loc_F009DE70
F009DE34: 113c045f                 sethi   -0xFEE8400, %o0
F009DE38: 1080003a                 ba      loc_F009DF20
F009DE3C: 113c045f                 sethi   -0xFEE8400, %o0
F009DE40: d2062010                 ld      [%i0+0x10], %o1
F009DE44: 900ac010                 and     %o3, %l0, %o0
F009DE48: 80a20009                 cmp     %o0, %o1
F009DE4C: 02800037                 be      loc_F009DF28
F009DE50: 9132a002                 srl     %o2, 2, %o0
F009DE54: 400011dc                 call    _pmap_seg_entry
F009DE58: 912a2006                 sll     %o0, 6, %o0! char *
F009DE5C: d207a048                 ld      [%fp+arg_48], %o1
F009DE60: d0262008                 st      %o0, [%i0+8]
F009DE64: 920a4010                 and     %o1, %l0, %o1
F009DE68: 10800030                 ba      loc_F009DF28
F009DE6C: d2262010                 st      %o1, [%i0+0x10]
F009DE70: 7ffddcc0                 call    _panic
F009DE74: 901222b8                 bset    0x2B8, %o0
F009DE78: 3080002e                 ba,a    locret_F009DF30
F009DE7C: 7fffe3aa                 call    _splx
F009DE80: 90100011                 mov     %l1, %o0
F009DE84: 90100018                 mov     %i0, %o0
F009DE88: d207a048                 ld      [%fp+arg_48], %o1
F009DE8C: 400012b3                 call    _pmap_alloc_seg_entry
F009DE90: 94102003                 mov     3, %o2
F009DE94: 7fffff5c                 call    _check_ptbl
F009DE98: b2100008                 mov     %o0, %i1
F009DE9C: 80a22000                 cmp     %o0, 0
F009DEA0: 02800004                 be      loc_F009DEB0
F009DEA4: 113c045f                 sethi   %hi(aPmapExpandPage_0), %o0! "pmap_expand: page_table non-zero\n"
F009DEA8: 7ffddcb2                 call    _panic
F009DEAC: 901222d0                 bset    %lo(aPmapExpandPage_0), %o0! "pmap_expand: page_table non-zero\n"
F009DEB0: 7fffff69                 call    _check_pmap
F009DEB4: 90100019                 mov     %i1, %o0
F009DEB8: 7fffe391                 call    _splvm
F009DEBC: 01000000                 nop
F009DEC0: d204801a                 ld      [%l2+%i2], %o1
F009DEC4: 808a6003                 btst    3, %o1
F009DEC8: 02800007                 be      loc_F009DEE4
F009DECC: a2100008                 mov     %o0, %l1
F009DED0: 7fffe395                 call    _splx
F009DED4: 01000000                 nop
F009DED8: 400013ae                 call    _pmap_dealloc_seg_entry
F009DEDC: 90100019                 mov     %i1, %o0
F009DEE0: 30800014                 ba,a    locret_F009DF30
F009DEE4: d207a048                 ld      [%fp+arg_48], %o1
F009DEE8: d6066004                 ld      [%i1+4], %o3
F009DEEC: d40e600e                 ldub    [%i1+0xE], %o2
F009DEF0: 90100010                 mov     %l0, %o0
F009DEF4: d602e004                 ld      [%o3+4], %o3
F009DEF8: 952aa008                 sll     %o2, 8, %o2
F009DEFC: 40000f02                 call    _set_ptp
F009DF00: 9402c00a                 add     %o3, %o2, %o2
F009DF04: e0266020                 st      %l0, [%i1+0x20]
F009DF08: f2262008                 st      %i1, [%i0+8]
F009DF0C: d007a048                 ld      [%fp+arg_48], %o0
F009DF10: 133fff00                 sethi   -0x40000, %o1
F009DF14: 900a0009                 and     %o0, %o1, %o0! char *
F009DF18: 10800004                 ba      loc_F009DF28
F009DF1C: d0262010                 st      %o0, [%i0+0x10]
F009DF20: 7ffddc94                 call    _panic
F009DF24: 901222f8                 bset    0x2F8, %o0
F009DF28: 7fffe37f                 call    _splx
F009DF2C: 90100011                 mov     %l1, %o0
F009DF30: 81c7e008                 ret
F009DF34: 81e80000                 restore

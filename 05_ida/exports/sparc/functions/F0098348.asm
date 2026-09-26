F0098348: 9de3be18                 save    %sp, -0x1E8, %sp
F009834C: 113c044ba21221f4         set     off_F0112DF4, %l1! "iommu"
F0098354: a607be78                 add     %fp, var_188, %l3
F0098358: d00221f4                 ld      [%o0+0x1F4], %o0
F009835C: 80a22000                 cmp     %o0, 0
F0098360: 02800076                 be      locret_F0098538
F0098364: a8102001                 mov     1, %l4
F0098368: d0044000                 ld      [%l1], %o0! __s1
F009836C: 7ffdbf90                 call    _strcmp
F0098370: 9210001b                 mov     %i3, %o1
F0098374: 80a22000                 cmp     %o0, 0
F0098378: 02800008                 be      loc_F0098398
F009837C: 90100018                 mov     %i0, %o0
F0098380: a204600c                 inc     0xC, %l1
F0098384: d0044000                 ld      [%l1], %o0
F0098388: 80a22000                 cmp     %o0, 0
F009838C: 0280006b                 be      locret_F0098538
F0098390: 01000000                 nop
F0098394: 30bffff5                 ba,a    loc_F0098368
F0098398: 133c044ba0126168         set     _psreg, %l0! "reg"
F00983A0: 40005b0f                 call    _prom_getproplen
F00983A4: 92100010                 mov     %l0, %o1
F00983A8: 7ffdb896                 call    _udiv
F00983AC: 9210200c                 mov     0xC, %o1
F00983B0: 2b3c044b                 sethi   %hi(_debug_fillsysinfo), %l5
F00983B4: d2056140                 ld      [%l5+%lo(_debug_fillsysinfo)], %o1
F00983B8: 80a26000                 cmp     %o1, 0
F00983BC: 02800007                 be      loc_F00983D8
F00983C0: a4100008                 mov     %o0, %l2
F00983C4: 113c044b901222e0         set     aNregForSIsD, %o0! "nreg for %s is %d\n"
F00983CC: 9210001b                 mov     %i3, %o1
F00983D0: 40005cea                 call    _prom_printf
F00983D4: 94100012                 mov     %l2, %o2
F00983D8: 90100018                 mov     %i0, %o0
F00983DC: 92100010                 mov     %l0, %o1
F00983E0: a007be78                 add     %fp, var_188, %l0
F00983E4: 40005b08                 call    _prom_getprop
F00983E8: 94100010                 mov     %l0, %o2
F00983EC: 9010001b                 mov     %i3, %o0
F00983F0: 92100019                 mov     %i1, %o1
F00983F4: 9410001a                 mov     %i2, %o2
F00983F8: 96100012                 mov     %l2, %o3
F00983FC: 400060a1                 call    _apply_range_to_reg
F0098400: 98100010                 mov     %l0, %o4
F0098404: d0056140                 ld      [%l5+0x140], %o0
F0098408: 80a22000                 cmp     %o0, 0
F009840C: 02800006                 be      loc_F0098424
F0098410: 113c044b                 sethi   %hi(aMappingSToX), %o0! "mapping %s to %x\n"
F0098414: 901222f8                 bset    %lo(aMappingSToX), %o0! "mapping %s to %x\n"
F0098418: d4046004                 ld      [%l1+4], %o2
F009841C: 40005cd7                 call    _prom_printf
F0098420: 9210001b                 mov     %i3, %o1
F0098424: 80a4a000                 cmp     %l2, 0
F0098428: 02800041                 be      loc_F009852C
F009842C: b4102000                 mov     0, %i2
F0098430: 2d3c0464                 sethi   -0xFEE7000, %l6
F0098434: 2b000010                 sethi   0x4000, %l5
F0098438: 2f000004                 sethi   0x1000, %l7
F009843C: b004e008                 add     %l3, 8, %i0
F0098440: d0060000                 ld      [%i0], %o0
F0098444: f2063ffc                 ld      [%i0-4], %i1
F0098448: d205a2b0                 ld      [%l6+0x2B0], %o1
F009844C: f604c000                 ld      [%l3], %i3
F0098450: 90023fff                 inc     -1, %o0
F0098454: 9132200c                 srl     %o0, 12, %o0
F0098458: 80a26000                 cmp     %o1, 0
F009845C: 02800010                 be      loc_F009849C
F0098460: a0022001                 add     %o0, 1, %l0
F0098464: 80a52000                 cmp     %l4, 0
F0098468: 0280000e                 be      loc_F00984A0
F009846C: d005a2b0                 ld      [%l6+0x2B0], %o0
F0098470: d0044000                 ld      [%l1], %o0! __s1
F0098474: 133c044b                 sethi   %hi(aCounter), %o1! "counter"
F0098478: 7ffdbf4d                 call    _strcmp
F009847C: 92126310                 bset    %lo(aCounter), %o1! "counter"
F0098480: 80a22000                 cmp     %o0, 0
F0098484: 12800007                 bne     loc_F00984A0
F0098488: d005a2b0                 ld      [%l6+0x2B0], %o0
F009848C: d0060000                 ld      [%i0], %o0
F0098490: 80a20015                 cmp     %o0, %l5
F0098494: 32800002                 bne,a   loc_F009849C
F0098498: a0102004                 mov     4, %l0
F009849C: d005a2b0                 ld      [%l6+0x2B0], %o0
F00984A0: 80a22000                 cmp     %o0, 0
F00984A4: 0280000f                 be      loc_F00984E0
F00984A8: 80a52000                 cmp     %l4, 0
F00984AC: 0280000e                 be      loc_F00984E4
F00984B0: 80a42000                 cmp     %l0, 0
F00984B4: d0044000                 ld      [%l1], %o0! __s1
F00984B8: 133c044b                 sethi   %hi(aInterrupt), %o1! "interrupt"
F00984BC: 7ffdbf3c                 call    _strcmp
F00984C0: 92126318                 bset    %lo(aInterrupt), %o1! "interrupt"
F00984C4: 80a22000                 cmp     %o0, 0
F00984C8: 12800007                 bne     loc_F00984E4
F00984CC: 80a42000                 cmp     %l0, 0
F00984D0: d0060000                 ld      [%i0], %o0
F00984D4: 80a20015                 cmp     %o0, %l5
F00984D8: 32800002                 bne,a   loc_F00984E0
F00984DC: a0102004                 mov     4, %l0
F00984E0: 80a42000                 cmp     %l0, 0
F00984E4: 0280000e                 be      loc_F009851C
F00984E8: a8102000                 mov     0, %l4
F00984EC: 9210001b                 mov     %i3, %o1
F00984F0: 94100019                 mov     %i1, %o2
F00984F4: 17000004                 sethi   0x1000, %o3
F00984F8: b2064017                 add     %i1, %l7, %i1
F00984FC: 992ea00c                 sll     %i2, 12, %o4
F0098500: d0046004                 ld      [%l1+4], %o0
F0098504: b406a001                 inc     %i2
F0098508: 40005b7f                 call    _prom_map
F009850C: 9002000c                 add     %o0, %o4, %o0
F0098510: a0843fff                 inccc   -1, %l0
F0098514: 12bffff7                 bne     loc_F00984F0
F0098518: 9210001b                 mov     %i3, %o1
F009851C: b006200c                 inc     0xC, %i0
F0098520: a484bfff                 inccc   -1, %l2
F0098524: 12bfffc7                 bne     loc_F0098440
F0098528: a604e00c                 inc     0xC, %l3
F009852C: d014600a                 lduh    [%l1+0xA], %o0
F0098530: 90122002                 bset    2, %o0
F0098534: d034600a                 sth     %o0, [%l1+0xA]
F0098538: 81c7e008                 ret
F009853C: 81e80000                 restore

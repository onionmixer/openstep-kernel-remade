F00B2110: 9de3bf98                 save    %sp, -0x68, %sp
F00B2114: 213c04fc                 sethi   %hi(_dma_map), %l0
F00B2118: d0042080                 ld      [%l0+%lo(_dma_map)], %o0
F00B211C: 80a22000                 cmp     %o0, 0
F00B2120: 12800010                 bne     loc_F00B2160
F00B2124: 153c0474                 sethi   -0xFEE3000, %o2
F00B2128: 113c0474                 sethi   %hi(_ndma_map), %o0
F00B212C: d00221d8                 ld      [%o0+%lo(_ndma_map)], %o0
F00B2130: 7ffed7d0                 call    _kalloc
F00B2134: 912a2004                 sll     %o0, 4, %o0
F00B2138: 80a22000                 cmp     %o0, 0
F00B213C: 12800006                 bne     loc_F00B2154
F00B2140: d0242080                 st      %o0, [%l0+%lo(_dma_map)]
F00B2144: d206202c                 ld      [%i0+0x2C], %o1! size_t
F00B2148: 113c0474                 sethi   %hi(aDmaDNoSpaceFor), %o0! "dma%d: No space for dma_map structure\n"
F00B214C: 10800027                 ba      loc_F00B21E8
F00B2150: 90122218                 bset    %lo(aDmaDNoSpaceFor), %o0! "dma%d: No space for dma_map structure\n"
F00B2154: 7fff8b41                 call    _bzero
F00B2158: 92102010                 mov     0x10, %o1
F00B215C: 153c0474                 sethi   -0xFEE3000, %o2
F00B2160: d00aa214                 ldub    [%o2+0x214], %o0
F00B2164: 92022001                 add     %o0, 1, %o1
F00B2168: d22aa214                 stb     %o1, [%o2+0x214]
F00B216C: 912a2018                 sll     %o0, 24, %o0
F00B2170: 933a2018                 sra     %o0, 24, %o1
F00B2174: 113c0474                 sethi   %hi(_ndma_map), %o0
F00B2178: d00221d8                 ld      [%o0+%lo(_ndma_map)], %o0
F00B217C: 80a24008                 cmp     %o1, %o0
F00B2180: 06800005                 bl      loc_F00B2194
F00B2184: d226202c                 st      %o1, [%i0+0x2C]
F00B2188: 113c0474                 sethi   %hi(aDmaDBadUnitNum), %o0! "dma%d: bad unit number\n"
F00B218C: 10800017                 ba      loc_F00B21E8
F00B2190: 90122240                 bset    %lo(aDmaDBadUnitNum), %o0! "dma%d: bad unit number\n"
F00B2194: d0062010                 ld      [%i0+0x10], %o0
F00B2198: 80a22002                 cmp     %o0, 2
F00B219C: 113c04fc                 sethi   %hi(_dma_map), %o0
F00B21A0: e4022080                 ld      [%o0+%lo(_dma_map)], %l2
F00B21A4: a32a6004                 sll     %o1, 4, %l1
F00B21A8: 04800005                 ble     loc_F00B21BC
F00B21AC: a0048011                 add     %l2, %l1, %l0
F00B21B0: 113c0474                 sethi   %hi(aDmaDBadRegiste), %o0! "dma%d: bad register specification\n"
F00B21B4: 1080000d                 ba      loc_F00B21E8
F00B21B8: 90122258                 bset    %lo(aDmaDBadRegiste), %o0! "dma%d: bad register specification\n"
F00B21BC: d4062014                 ld      [%i0+0x14], %o2
F00B21C0: d002a004                 ld      [%o2+4], %o0
F00B21C4: d202a008                 ld      [%o2+8], %o1
F00B21C8: 7ffffd15                 call    _map_regs
F00B21CC: d4028000                 ld      [%o2], %o2
F00B21D0: 80a22000                 cmp     %o0, 0
F00B21D4: 12800008                 bne     loc_F00B21F4
F00B21D8: d0248011                 st      %o0, [%l2+%l1]
F00B21DC: d206202c                 ld      [%i0+0x2C], %o1
F00B21E0: 113c047490122280         set     aDmaDUnableToMa, %o0! "dma%d: unable to map registers\n"
F00B21E8: 7ffd891c                 call    _printf
F00B21EC: b0103fff                 mov     -1, %i0
F00B21F0: 3080001a                 ba,a    locret_F00B2258
F00B21F4: d0062014                 ld      [%i0+0x14], %o0
F00B21F8: d0020000                 ld      [%o0], %o0
F00B21FC: d0242004                 st      %o0, [%l0+4]
F00B2200: d0062014                 ld      [%i0+0x14], %o0
F00B2204: d0022004                 ld      [%o0+4], %o0
F00B2208: d0242008                 st      %o0, [%l0+8]
F00B220C: 90102001                 mov     1, %o0
F00B2210: d02c200c                 stb     %o0, [%l0+0xC]
F00B2214: d0062018                 ld      [%i0+0x18], %o0
F00B2218: 80a22000                 cmp     %o0, 0
F00B221C: 0280000a                 be      loc_F00B2244
F00B2220: 133c02c8                 sethi   %hi(_dmaintr), %o1
F00B2224: d406200c                 ld      [%i0+0xC], %o2
F00B2228: d006201c                 ld      [%i0+0x1C], %o0
F00B222C: 9212637c                 bset    %lo(_dmaintr), %o1
F00B2230: d606202c                 ld      [%i0+0x2C], %o3
F00B2234: 98102000                 mov     0, %o4
F00B2238: d0020000                 ld      [%o0], %o0
F00B223C: 7fff9b88                 call    _addintr
F00B2240: 9a102000                 mov     0, %o5
F00B2244: 7ffffafd                 call    _report_dev
F00B2248: 90100018                 mov     %i0, %o0
F00B224C: 7ffffa6c                 call    _attach_devs
F00B2250: 90100018                 mov     %i0, %o0
F00B2254: b0102000                 mov     0, %i0
F00B2258: 81c7e008                 ret
F00B225C: 81e80000                 restore

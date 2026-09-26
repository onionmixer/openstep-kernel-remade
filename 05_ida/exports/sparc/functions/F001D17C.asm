F001D17C: 9de3bf98                 save    %sp, -0x68, %sp
F001D180: 1108001d90122071         set     0x20007471, %o0
F001D188: 80a64008                 cmp     %i1, %o0
F001D18C: 1280001c                 bne     loc_F001D1FC
F001D190: 9410001a                 mov     %i2, %o2
F001D194: 333c04cf                 sethi   %hi(_active_u), %i1
F001D198: d00661d8                 ld      [%i1+%lo(_active_u)], %o0
F001D19C: f0020000                 ld      [%o0], %i0
F001D1A0: 7fffc660                 call    _get_posix_proc
F001D1A4: d0562030                 ldsh    [%i0+0x30], %o0
F001D1A8: 94100008                 mov     %o0, %o2
F001D1AC: d002a010                 ld      [%o2+0x10], %o0
F001D1B0: d2022008                 ld      [%o0+8], %o1
F001D1B4: d0026004                 ld      [%o1+4], %o0
F001D1B8: 80a20018                 cmp     %o0, %i0
F001D1BC: 32800007                 bne,a   loc_F001D1D8
F001D1C0: d2062028                 ld      [%i0+0x28], %o1
F001D1C4: c0226008                 clr     [%o1+8]
F001D1C8: d002a010                 ld      [%o2+0x10], %o0
F001D1CC: d0022008                 ld      [%o0+8], %o0
F001D1D0: c032200c                 clrh    [%o0+0xC]
F001D1D4: d2062028                 ld      [%i0+0x28], %o1
F001D1D8: 11100000                 sethi   0x40000000, %o0
F001D1DC: 902a4008                 andn    %o1, %o0, %o0
F001D1E0: d0262028                 st      %o0, [%i0+0x28]
F001D1E4: d00661d8                 ld      [%i1+0x1D8], %o0
F001D1E8: c0222164                 clr     [%o0+0x164]
F001D1EC: d00661d8                 ld      [%i1+0x1D8], %o0
F001D1F0: b0102000                 mov     0, %i0
F001D1F4: 10800019                 ba      locret_F001D258
F001D1F8: c0322168                 clrh    [%o0+0x168]
F001D1FC: 113c04cf                 sethi   %hi(_active_u), %o0
F001D200: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F001D204: d0026164                 ld      [%o1+0x164], %o0
F001D208: 80a22000                 cmp     %o0, 0
F001D20C: 02800013                 be      locret_F001D258
F001D210: b0102006                 mov     6, %i0
F001D214: d2126168                 lduh    [%o1+0x168], %o1
F001D218: 932a6010                 sll     %o1, 16, %o1
F001D21C: 913a6010                 sra     %o1, 16, %o0
F001D220: 93326018                 srl     %o1, 24, %o1
F001D224: 972a6001                 sll     %o1, 1, %o3
F001D228: 9602c009                 add     %o3, %o1, %o3
F001D22C: 972ae002                 sll     %o3, 2, %o3
F001D230: 9622c009                 sub     %o3, %o1, %o3
F001D234: 972ae002                 sll     %o3, 2, %o3
F001D238: 133c0472921261f0         set     _cdevsw, %o1
F001D240: 9602c009                 add     %o3, %o1, %o3
F001D244: d802e010                 ld      [%o3+0x10], %o4
F001D248: 92100019                 mov     %i1, %o1
F001D24C: 9fc30000                 call    %o4
F001D250: 9610001b                 mov     %i3, %o3
F001D254: b0100008                 mov     %o0, %i0
F001D258: 81c7e008                 ret
F001D25C: 81e80000                 restore

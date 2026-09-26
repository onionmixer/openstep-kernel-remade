F0043734: 9de3bf98                 save    %sp, -0x68, %sp
F0043738: a2100018                 mov     %i0, %l1
F004373C: a0102000                 mov     0, %l0
F0043740: 293c04d0                 sethi   -0xFECC000, %l4
F0043744: 253c04cf                 sethi   -0xFECC400, %l2
F0043748: 273c0437                 sethi   -0xFEF2400, %l3
F004374C: 90100011                 mov     %l1, %o0
F0043750: 92100019                 mov     %i1, %o1
F0043754: 9410001a                 mov     %i2, %o2
F0043758: 7fffffa5                 call    _pmap_kgetport
F004375C: 9610001b                 mov     %i3, %o3
F0043760: b0920000                 orcc    %o0, %g0, %i0
F0043764: 04800026                 ble     loc_F00437FC
F0043768: d2052260                 ld      [%l4+0x260], %o1
F004376C: d002618c                 ld      [%o1+0x18C], %o0
F0043770: 808a2003                 btst    3, %o0
F0043774: 12800026                 bne     loc_F004380C
F0043778: 9014e148                 or      %l3, 0x148, %o0
F004377C: d004a1d8                 ld      [%l2+0x1D8], %o0
F0043780: d4020000                 ld      [%o0], %o2
F0043784: d0026084                 ld      [%o1+0x84], %o0
F0043788: d202a018                 ld      [%o2+0x18], %o1
F004378C: d002204c                 ld      [%o0+0x4C], %o0
F0043790: 96924008                 orcc    %o1, %o0, %o3
F0043794: 22800012                 be,a    loc_F00437DC
F0043798: a0042001                 inc     %l0
F004379C: d002a028                 ld      [%o2+0x28], %o0
F00437A0: 808a2010                 btst    0x10, %o0
F00437A4: 12800008                 bne     loc_F00437C4
F00437A8: 01000000                 nop
F00437AC: d002a020                 ld      [%o2+0x20], %o0
F00437B0: d202a01c                 ld      [%o2+0x1C], %o1
F00437B4: 90120009                 bset    %o1, %o0
F00437B8: 80aac008                 andncc  %o3, %o0, %g0
F00437BC: 22800008                 be,a    loc_F00437DC
F00437C0: a0042001                 inc     %l0
F00437C4: 7fff387b                 call    _issig
F00437C8: 90102000                 mov     0, %o0
F00437CC: 80a22000                 cmp     %o0, 0
F00437D0: 1280000f                 bne     loc_F004380C
F00437D4: 9014e148                 or      %l3, 0x148, %o0
F00437D8: a0042001                 inc     %l0
F00437DC: 80a42001                 cmp     %l0, 1
F00437E0: 12bfffdc                 bne     loc_F0043750
F00437E4: 90100011                 mov     %l1, %o0
F00437E8: 113c0437                 sethi   %hi(aPortmapperNotR), %o0! "Portmapper not responding; still trying"...
F00437EC: 7fff439b                 call    _printf
F00437F0: 90122170                 bset    %lo(aPortmapperNotR), %o0! "Portmapper not responding; still trying"...
F00437F4: 10bfffd7                 ba      loc_F0043750
F00437F8: 90100011                 mov     %l1, %o0
F00437FC: 80a42000                 cmp     %l0, 0
F0043800: 02800005                 be      locret_F0043814
F0043804: 113c0437                 sethi   %hi(aPortmapperOk), %o0! "Portmapper ok\n"
F0043808: 901221a0                 bset    %lo(aPortmapperOk), %o0! "Portmapper ok\n"
F004380C: 7fff4393                 call    _printf
F0043810: 01000000                 nop
F0043814: 81c7e008                 ret
F0043818: 81e80000                 restore

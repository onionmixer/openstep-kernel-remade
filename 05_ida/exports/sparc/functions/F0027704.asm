F0027704: 9de3bf90                 save    %sp, -0x70, %sp
F0027708: 7fff8f37                 call    _falloc
F002770C: 01000000                 nop
F0027710: a0920000                 orcc    %o0, %g0, %l0
F0027714: 12800006                 bne     loc_F002772C
F0027718: 193c04cf                 sethi   -0xFECC400, %o4
F002771C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0027720: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0027724: 10800041                 ba      locret_F0027828
F0027728: f04a2038                 ldsb    [%o0+0x38], %i0
F002772C: a21321dc                 or      %o4, 0x1DC, %l1
F0027730: d0047ffc                 ld      [%l1-4], %o0
F0027734: 92102000                 mov     0, %o1
F0027738: d652216a                 ldsh    [%o0+0x16A], %o3
F002773C: 94100019                 mov     %i1, %o2
F0027740: d80321dc                 ld      [%o4+0x1DC], %o4
F0027744: 9638000b                 xnor    %g0, %o3, %o3
F0027748: 960aefff                 and     %o3, 0xFFF, %o3
F002774C: 960e800b                 and     %i2, %o3, %o3
F0027750: f4032030                 ld      [%o4+0x30], %i2
F0027754: 90100018                 mov     %i0, %o0
F0027758: 4000051a                 call    _vn_open
F002775C: 9807bff4                 add     %fp, var_C, %o4
F0027760: b0920000                 orcc    %o0, %g0, %i0
F0027764: 0280000c                 be      loc_F0027794
F0027768: 11280000                 sethi   -0x60000000, %o0
F002776C: d0047ffc                 ld      [%l1-4], %o0
F0027770: d202214c                 ld      [%o0+0x14C], %o1
F0027774: 912ea002                 sll     %i2, 2, %o0
F0027778: c0224008                 clr     [%o1+%o0]
F002777C: 7fffa0a7                 call    _crfree
F0027780: d0042020                 ld      [%l0+0x20], %o0
F0027784: c034200e                 clrh    [%l0+0xE]
F0027788: 7fff8f79                 call    _free_file
F002778C: 90100010                 mov     %l0, %o0
F0027790: 30800026                 ba,a    locret_F0027828
F0027794: 9012204b                 bset    0x4B, %o0 ! 'K'
F0027798: 940a0019                 and     %o0, %i1, %o2
F002779C: d4242008                 st      %o2, [%l0+8]
F00277A0: d0047ffc                 ld      [%l1-4], %o0
F00277A4: d0020000                 ld      [%o0], %o0
F00277A8: d2022014                 ld      [%o0+0x14], %o1
F00277AC: 11000010                 sethi   0x4000, %o0
F00277B0: 808a4008                 btst    %o0, %o1
F00277B4: 02800009                 be      loc_F00277D8
F00277B8: d007bff4                 ld      [%fp+var_C], %o0
F00277BC: d0022028                 ld      [%o0+0x28], %o0
F00277C0: 80a22001                 cmp     %o0, 1
F00277C4: 12800006                 bne     loc_F00277DC
F00277C8: 90102001                 mov     1, %o0
F00277CC: 1110000490128008         set     0x40001000, %o0
F00277D4: d0242008                 st      %o0, [%l0+8]
F00277D8: 90102001                 mov     1, %o0
F00277DC: d034200c                 sth     %o0, [%l0+0xC]
F00277E0: 113c0430901220b0         set     _vnodefops, %o0
F00277E8: d207bff4                 ld      [%fp+var_C], %o1
F00277EC: d0242014                 st      %o0, [%l0+0x14]
F00277F0: d2242018                 st      %o1, [%l0+0x18]
F00277F4: d0026028                 ld      [%o1+0x28], %o0
F00277F8: 80a22008                 cmp     %o0, 8
F00277FC: 12800007                 bne     loc_F0027818
F0027800: 113c04cf                 sethi   -0xFECC400, %o0
F0027804: d0042008                 ld      [%l0+8], %o0
F0027808: 920e6004                 and     %i1, 4, %o1
F002780C: 90120009                 bset    %o1, %o0
F0027810: d0242008                 st      %o0, [%l0+8]
F0027814: 113c04cf                 sethi   -0xFECC400, %o0
F0027818: d00221d8                 ld      [%o0+0x1D8], %o0
F002781C: d202214c                 ld      [%o0+0x14C], %o1
F0027820: 912ea002                 sll     %i2, 2, %o0
F0027824: e0224008                 st      %l0, [%o1+%o0]
F0027828: 81c7e008                 ret
F002782C: 81e80000                 restore

F0059818: 9de3bf90                 save    %sp, -0x70, %sp
F005981C: 113c04efa4122300         set     _ipc_object_zones, %l2
F0059824: a32e6002                 sll     %i1, 2, %l1
F0059828: d0044012                 ld      [%l1+%l2], %o0
F005982C: 40007e28                 call    _zalloc
F0059830: a6100018                 mov     %i0, %l3
F0059834: a0920000                 orcc    %o0, %g0, %l0
F0059838: 12800004                 bne     loc_F0059848
F005983C: 90100013                 mov     %l3, %o0
F0059840: 10800023                 ba      locret_F00598CC
F0059844: b0102006                 mov     6, %i0
F0059848: 9210001c                 mov     %i4, %o1
F005984C: 7fffe8b7                 call    _ipc_entry_alloc
F0059850: 9407bff4                 add     %fp, var_C, %o2
F0059854: b0920000                 orcc    %o0, %g0, %i0
F0059858: 02800006                 be      loc_F0059870
F005985C: d007bff4                 ld      [%fp+var_C], %o0
F0059860: d0044012                 ld      [%l1+%l2], %o0
F0059864: 40007e5b                 call    _zfree
F0059868: 92100010                 mov     %l0, %o1
F005986C: 30800018                 ba,a    locret_F00598CC
F0059870: 9416801b                 or      %i2, %i3, %o2
F0059874: d2020000                 ld      [%o0], %o1
F0059878: e0222004                 st      %l0, [%o0+4]
F005987C: 9212400a                 bset    %o2, %o1
F0059880: d2220000                 st      %o1, [%o0]
F0059884: c0240000                 clr     [%l0]
F0059888: d0040000                 ld      [%l0], %o0
F005988C: 80a22000                 cmp     %o0, 0
F0059890: 12bffffe                 bne     loc_F0059888
F0059894: 01000000                 nop
F0059898: 4000f584                 call    _simple_lock_try
F005989C: 90100010                 mov     %l0, %o0
F00598A0: 80a22000                 cmp     %o0, 0
F00598A4: 02bffff9                 be      loc_F0059888
F00598A8: 13200000                 sethi   0x80000000, %o1
F00598AC: c024e008                 clr     [%l3+8]
F00598B0: 90102001                 mov     1, %o0
F00598B4: d0242004                 st      %o0, [%l0+4]
F00598B8: 912e6010                 sll     %i1, 16, %o0
F00598BC: 90120009                 bset    %o1, %o0
F00598C0: d0242008                 st      %o0, [%l0+8]
F00598C4: e0274000                 st      %l0, [%i5]
F00598C8: b0102000                 mov     0, %i0
F00598CC: 81c7e008                 ret
F00598D0: 81e80000                 restore

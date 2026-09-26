F008747C: 9de3bf98                 save    %sp, -0x68, %sp
F0087480: 80a62000                 cmp     %i0, 0
F0087484: 02800026                 be      locret_F008751C
F0087488: 80a66000                 cmp     %i1, 0
F008748C: 02800024                 be      locret_F008751C
F0087490: 113c04f4                 sethi   %hi(_object_hash_zone), %o0
F0087494: 940e607f                 and     %i1, 0x7F, %o2
F0087498: 952aa003                 sll     %o2, 3, %o2
F008749C: 133c04f592126030         set     _vm_object_hashtable, %o1
F00874A4: d00223f8                 ld      [%o0+%lo(_object_hash_zone)], %o0
F00874A8: 7fffc709                 call    _zalloc
F00874AC: a0028009                 add     %o2, %o1, %l0
F00874B0: b2100008                 mov     %o0, %i1
F00874B4: f0266008                 st      %i0, [%i1+8]
F00874B8: 113c04f5a2122000         set     _vm_cache_lock, %l1
F00874C0: d0062044                 ld      [%i0+0x44], %o0
F00874C4: 13000004                 sethi   0x1000, %o1
F00874C8: 90120009                 bset    %o1, %o0
F00874CC: d0262044                 st      %o0, [%i0+0x44]
F00874D0: d0044000                 ld      [%l1], %o0
F00874D4: 80a22000                 cmp     %o0, 0
F00874D8: 12bffffe                 bne     loc_F00874D0
F00874DC: 01000000                 nop
F00874E0: 40003e72                 call    _simple_lock_try
F00874E4: 90100011                 mov     %l1, %o0
F00874E8: 80a22000                 cmp     %o0, 0
F00874EC: 02bffff9                 be      loc_F00874D0
F00874F0: 01000000                 nop
F00874F4: d0042004                 ld      [%l0+4], %o0
F00874F8: 80a40008                 cmp     %l0, %o0
F00874FC: 32800003                 bne,a   loc_F0087508
F0087500: f2220000                 st      %i1, [%o0]
F0087504: f2240000                 st      %i1, [%l0]
F0087508: d0266004                 st      %o0, [%i1+4]
F008750C: e0264000                 st      %l0, [%i1]
F0087510: f2242004                 st      %i1, [%l0+4]
F0087514: 113c04f5                 sethi   %hi(_vm_cache_lock), %o0
F0087518: c0222000                 clr     [%o0+%lo(_vm_cache_lock)]
F008751C: 81c7e008                 ret
F0087520: 81e80000                 restore

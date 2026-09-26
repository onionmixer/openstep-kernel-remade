F0087358: 9de3bf98                 save    %sp, -0x68, %sp
F008735C: a4100018                 mov     %i0, %l2
F0087360: 900ca07f                 and     %l2, 0x7F, %o0
F0087364: 912a2003                 sll     %o0, 3, %o0
F0087368: 133c04f592126030         set     _vm_object_hashtable, %o1
F0087370: a2020009                 add     %o0, %o1, %l1
F0087374: 113c04f5a0122000         set     _vm_cache_lock, %l0
F008737C: d0040000                 ld      [%l0], %o0
F0087380: 80a22000                 cmp     %o0, 0
F0087384: 12bffffe                 bne     loc_F008737C
F0087388: 01000000                 nop
F008738C: 40003ec7                 call    _simple_lock_try
F0087390: 90100010                 mov     %l0, %o0
F0087394: 80a22000                 cmp     %o0, 0
F0087398: 02bffff9                 be      loc_F008737C
F008739C: 01000000                 nop
F00873A0: d2044000                 ld      [%l1], %o1
F00873A4: 80a44009                 cmp     %l1, %o1
F00873A8: 02800031                 be      loc_F008746C
F00873AC: 113c04f5                 sethi   -0xFEC2C00, %o0
F00873B0: 2b3c04f5a6156018         set     _vm_object_cached_list, %l3
F00873B8: 293c04f5                 sethi   -0xFEC2C00, %l4
F00873BC: f0026008                 ld      [%o1+8], %i0
F00873C0: d0062028                 ld      [%i0+0x28], %o0
F00873C4: 80a20012                 cmp     %o0, %l2
F00873C8: 32800025                 bne,a   loc_F008745C
F00873CC: d2024000                 ld      [%o1], %o1
F00873D0: a0062010                 add     %i0, 0x10, %l0
F00873D4: d0040000                 ld      [%l0], %o0
F00873D8: 80a22000                 cmp     %o0, 0
F00873DC: 12bffffe                 bne     loc_F00873D4
F00873E0: 01000000                 nop
F00873E4: 40003eb1                 call    _simple_lock_try
F00873E8: 90100010                 mov     %l0, %o0
F00873EC: 80a22000                 cmp     %o0, 0
F00873F0: 02bffff9                 be      loc_F00873D4
F00873F4: 01000000                 nop
F00873F8: d0562018                 ldsh    [%i0+0x18], %o0
F00873FC: 80a22000                 cmp     %o0, 0
F0087400: 32800011                 bne,a   loc_F0087444
F0087404: d0162018                 lduh    [%i0+0x18], %o0
F0087408: d006204c                 ld      [%i0+0x4C], %o0
F008740C: 80a20013                 cmp     %o0, %l3
F0087410: 12800004                 bne     loc_F0087420
F0087414: d2062050                 ld      [%i0+0x50], %o1
F0087418: 10800003                 ba      loc_F0087424
F008741C: d2222004                 st      %o1, [%o0+4]
F0087420: d2222050                 st      %o1, [%o0+0x50]
F0087424: 80a24013                 cmp     %o1, %l3
F0087428: 22800003                 be,a    loc_F0087434
F008742C: d0256018                 st      %o0, [%l5+0x18]
F0087430: d022604c                 st      %o0, [%o1+0x4C]
F0087434: d0052010                 ld      [%l4+0x10], %o0
F0087438: 90023fff                 inc     -1, %o0
F008743C: d0252010                 st      %o0, [%l4+0x10]
F0087440: d0162018                 lduh    [%i0+0x18], %o0
F0087444: c0262010                 clr     [%i0+0x10]
F0087448: 90022001                 inc     %o0
F008744C: d0362018                 sth     %o0, [%i0+0x18]
F0087450: 113c04f5                 sethi   %hi(_vm_cache_lock), %o0
F0087454: c0222000                 clr     [%o0+%lo(_vm_cache_lock)]
F0087458: 30800007                 ba,a    locret_F0087474
F008745C: 80a44009                 cmp     %l1, %o1
F0087460: 32bfffd8                 bne,a   loc_F00873C0
F0087464: f0026008                 ld      [%o1+8], %i0
F0087468: 113c04f5                 sethi   -0xFEC2C00, %o0
F008746C: c0222000                 clr     [%o0]
F0087470: b0102000                 mov     0, %i0
F0087474: 81c7e008                 ret
F0087478: 81e80000                 restore

F003ED9C: 9de3bf50                 save    %sp, -0xB0, %sp
F003EDA0: 9410001a                 mov     %i2, %o2
F003EDA4: 113c0435                 sethi   %hi(_nfs_cto), %o0
F003EDA8: d00221c8                 ld      [%o0+%lo(_nfs_cto)], %o0
F003EDAC: 80a22000                 cmp     %o0, 0
F003EDB0: 1280000a                 bne     loc_F003EDD8
F003EDB4: a0102000                 mov     0, %l0
F003EDB8: d0060000                 ld      [%i0], %o0
F003EDBC: d0022024                 ld      [%o0+0x24], %o0
F003EDC0: d0022128                 ld      [%o0+0x128], %o0
F003EDC4: d2022014                 ld      [%o0+0x14], %o1
F003EDC8: 11010000                 sethi   0x4000000, %o0
F003EDCC: 808a4008                 btst    %o0, %o1
F003EDD0: 1280001b                 bne     locret_F003EE3C
F003EDD4: 01000000                 nop
F003EDD8: d0060000                 ld      [%i0], %o0
F003EDDC: a207bfb8                 add     %fp, var_48, %l1
F003EDE0: 7fffeac3                 call    _nfs_getattr_otw
F003EDE4: 92100011                 mov     %l1, %o1
F003EDE8: a0920000                 orcc    %o0, %g0, %l0
F003EDEC: 1280000f                 bne     loc_F003EE28
F003EDF0: 80a42046                 cmp     %l0, 0x46 ! 'F'
F003EDF4: d407bfd0                 ld      [%fp+var_30], %o2
F003EDF8: d607bfe0                 ld      [%fp+var_20], %o3
F003EDFC: 9207bfb0                 add     %fp, var_50, %o1
F003EE00: d007bfe4                 ld      [%fp+var_1C], %o0
F003EE04: d627bfb0                 st      %o3, [%fp+var_50]
F003EE08: d027bfb4                 st      %o0, [%fp+var_4C]
F003EE0C: d0060000                 ld      [%i0], %o0
F003EE10: 7fffea21                 call    _nfs_cache_check
F003EE14: 96102000                 mov     0, %o3
F003EE18: d0060000                 ld      [%i0], %o0
F003EE1C: 7fffea4a                 call    _nfs_attrcache_va
F003EE20: 92100011                 mov     %l1, %o1
F003EE24: 30800006                 ba,a    locret_F003EE3C
F003EE28: 12800005                 bne     locret_F003EE3C
F003EE2C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F003EE30: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F003EE34: 90102002                 mov     2, %o0
F003EE38: d02a6039                 stb     %o0, [%o1+0x39]
F003EE3C: 81c7e008                 ret
F003EE40: 91e80010                 restore %g0, %l0, %o0

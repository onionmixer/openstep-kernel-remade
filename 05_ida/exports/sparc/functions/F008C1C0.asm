F008C1C0: 9de3bf98                 save    %sp, -0x68, %sp
F008C1C4: d0060000                 ld      [%i0], %o0
F008C1C8: 80a22000                 cmp     %o0, 0
F008C1CC: 02800041                 be      locret_F008C2D0
F008C1D0: 01000000                 nop
F008C1D4: d0020000                 ld      [%o0], %o0
F008C1D8: 80a22000                 cmp     %o0, 0
F008C1DC: 0280003d                 be      locret_F008C2D0
F008C1E0: 113c043c                 sethi   %hi(_ufs_vnodeops), %o0
F008C1E4: d206201c                 ld      [%i0+0x1C], %o1
F008C1E8: 90122160                 bset    %lo(_ufs_vnodeops), %o0
F008C1EC: 80a24008                 cmp     %o1, %o0
F008C1F0: 1280000d                 bne     loc_F008C224
F008C1F4: a0102000                 mov     0, %l0
F008C1F8: d4062030                 ld      [%i0+0x30], %o2
F008C1FC: d212a044                 lduh    [%o2+0x44], %o1
F008C200: 808a6001                 btst    1, %o1
F008C204: 02800017                 be      loc_F008C260
F008C208: 01000000                 nop
F008C20C: a0102001                 mov     1, %l0
F008C210: 1100003f901223fe         set     0xFFFE, %o0
F008C218: 900a4008                 and     %o1, %o0, %o0
F008C21C: 10800011                 ba      loc_F008C260
F008C220: d032a044                 sth     %o0, [%o2+0x44]
F008C224: 113c0435901221cc         set     _nfs_vnodeops, %o0
F008C22C: 80a24008                 cmp     %o1, %o0
F008C230: 1280000c                 bne     loc_F008C260
F008C234: 01000000                 nop
F008C238: d4062030                 ld      [%i0+0x30], %o2
F008C23C: d212a060                 lduh    [%o2+0x60], %o1
F008C240: 808a6001                 btst    1, %o1
F008C244: 02800007                 be      loc_F008C260
F008C248: 01000000                 nop
F008C24C: a0102001                 mov     1, %l0
F008C250: 1100003f901223fe         set     0xFFFE, %o0
F008C258: 900a4008                 and     %o1, %o0, %o0
F008C25C: d032a060                 sth     %o0, [%o2+0x60]
F008C260: 7fff81d1                 call    _mfs_uncache
F008C264: 90100018                 mov     %i0, %o0
F008C268: d0060000                 ld      [%i0], %o0
F008C26C: 7fffec3b                 call    _vm_object_lookup
F008C270: d0020000                 ld      [%o0], %o0
F008C274: 7fffeafb                 call    _vm_object_cache_object
F008C278: 92102000                 mov     0, %o1
F008C27C: 80a42000                 cmp     %l0, 0
F008C280: 02800014                 be      locret_F008C2D0
F008C284: 113c043c                 sethi   %hi(_ufs_vnodeops), %o0
F008C288: d206201c                 ld      [%i0+0x1C], %o1
F008C28C: 90122160                 bset    %lo(_ufs_vnodeops), %o0
F008C290: 80a24008                 cmp     %o1, %o0
F008C294: 12800007                 bne     loc_F008C2B0
F008C298: 113c0435                 sethi   -0xFEF2C00, %o0
F008C29C: d2062030                 ld      [%i0+0x30], %o1
F008C2A0: d0126044                 lduh    [%o1+0x44], %o0
F008C2A4: 90122001                 bset    1, %o0
F008C2A8: 1080000a                 ba      locret_F008C2D0
F008C2AC: d0326044                 sth     %o0, [%o1+0x44]
F008C2B0: 901221cc                 bset    0x1CC, %o0
F008C2B4: 80a24008                 cmp     %o1, %o0
F008C2B8: 12800006                 bne     locret_F008C2D0
F008C2BC: 01000000                 nop
F008C2C0: d2062030                 ld      [%i0+0x30], %o1
F008C2C4: d0126060                 lduh    [%o1+0x60], %o0
F008C2C8: 90122001                 bset    1, %o0
F008C2CC: d0326060                 sth     %o0, [%o1+0x60]
F008C2D0: 81c7e008                 ret
F008C2D4: 81e80000                 restore

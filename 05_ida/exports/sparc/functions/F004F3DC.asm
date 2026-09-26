F004F3DC: 9de3bf98                 save    %sp, -0x68, %sp
F004F3E0: d0062008                 ld      [%i0+8], %o0
F004F3E4: 80a22000                 cmp     %o0, 0
F004F3E8: 1480001c                 bg      locret_F004F458
F004F3EC: 133c04ef                 sethi   %hi(_lf_svnode_hash), %o1
F004F3F0: d0060000                 ld      [%i0], %o0
F004F3F4: 921261c0                 bset    %lo(_lf_svnode_hash), %o1
F004F3F8: 900a203f                 and     %o0, 0x3F, %o0
F004F3FC: 912a2002                 sll     %o0, 2, %o0
F004F400: d4020009                 ld      [%o0+%o1], %o2
F004F404: 80a2a000                 cmp     %o2, 0
F004F408: 02800011                 be      loc_F004F44C
F004F40C: a2020009                 add     %o0, %o1, %l1
F004F410: e0044000                 ld      [%l1], %l0
F004F414: 80a40018                 cmp     %l0, %i0
F004F418: 3280000a                 bne,a   loc_F004F440
F004F41C: d004200c                 ld      [%l0+0xC], %o0
F004F420: 7fff65d1                 call    _vn_rele
F004F424: d0040000                 ld      [%l0], %o0
F004F428: d204200c                 ld      [%l0+0xC], %o1
F004F42C: 90100010                 mov     %l0, %o0
F004F430: d2244000                 st      %o1, [%l1]
F004F434: 4000635b                 call    _kfree
F004F438: 92102010                 mov     0x10, %o1
F004F43C: 30800007                 ba,a    locret_F004F458
F004F440: 80a22000                 cmp     %o0, 0
F004F444: 12bffff3                 bne     loc_F004F410
F004F448: a204200c                 add     %l0, 0xC, %l1
F004F44C: 113c043b                 sethi   %hi(aLfFreeSvnodeCa), %o0! "lf_free_svnode: cannot find shadow vnod"...
F004F450: 7fff1748                 call    _panic
F004F454: 901220d8                 bset    %lo(aLfFreeSvnodeCa), %o0! "lf_free_svnode: cannot find shadow vnod"...
F004F458: 81c7e008                 ret
F004F45C: 81e80000                 restore

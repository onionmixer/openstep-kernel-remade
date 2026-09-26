F00240C0: 9de3bf98                 save    %sp, -0x68, %sp
F00240C4: 213c04d4                 sethi   %hi(_rootvfs), %l0
F00240C8: d0042160                 ld      [%l0+%lo(_rootvfs)], %o0
F00240CC: 80a60008                 cmp     %i0, %o0
F00240D0: 12800006                 bne     loc_F00240E8
F00240D4: d4042160                 ld      [%l0+%lo(_rootvfs)], %o2
F00240D8: 113c042f                 sethi   %hi(aVfsRemoveUnmou), %o0! "vfs_remove: unmounting root"
F00240DC: 7fffc425                 call    _panic
F00240E0: 90122260                 bset    %lo(aVfsRemoveUnmou), %o0! "vfs_remove: unmounting root"
F00240E4: d4042160                 ld      [%l0+%lo(_rootvfs)], %o2
F00240E8: 80a2a000                 cmp     %o2, 0
F00240EC: 02800029                 be      loc_F0024190
F00240F0: 173c042f                 sethi   -0xFEF4400, %o3
F00240F4: d2028000                 ld      [%o2], %o1
F00240F8: 80a24018                 cmp     %o1, %i0
F00240FC: 32800022                 bne,a   loc_F0024184
F0024100: 94100009                 mov     %o1, %o2
F0024104: d0024000                 ld      [%o1], %o0
F0024108: d0228000                 st      %o0, [%o2]
F002410C: e2026008                 ld      [%o1+8], %l1
F0024110: d004600c                 ld      [%l1+0xC], %o0
F0024114: 80a22000                 cmp     %o0, 0
F0024118: 32800018                 bne,a   loc_F0024178
F002411C: c024600c                 clr     [%l1+0xC]
F0024120: d0046010                 ld      [%l1+0x10], %o0
F0024124: 80a22000                 cmp     %o0, 0
F0024128: 0280000a                 be      loc_F0024150
F002412C: a0046010                 add     %l1, 0x10, %l0
F0024130: d2040000                 ld      [%l0], %o1
F0024134: 80a24018                 cmp     %o1, %i0
F0024138: 22800007                 be,a    loc_F0024154
F002413C: d0040000                 ld      [%l0], %o0
F0024140: d0026120                 ld      [%o1+0x120], %o0
F0024144: 80a22000                 cmp     %o0, 0
F0024148: 12bffffa                 bne     loc_F0024130
F002414C: a0026120                 add     %o1, 0x120, %l0
F0024150: d0040000                 ld      [%l0], %o0! char *
F0024154: 80a20018                 cmp     %o0, %i0
F0024158: 22800005                 be,a    loc_F002416C
F002415C: d2062120                 ld      [%i0+0x120], %o1
F0024160: 7fffc404                 call    _panic
F0024164: 9012e280                 or      %o3, 0x280, %o0
F0024168: d2062120                 ld      [%i0+0x120], %o1
F002416C: 90046014                 add     %l1, 0x14, %o0
F0024170: 40012918                 call    _microtime
F0024174: d2240000                 st      %o1, [%l0]
F0024178: 40000015                 call    _vfs_unlock
F002417C: 90100018                 mov     %i0, %o0
F0024180: 30800007                 ba,a    locret_F002419C
F0024184: 80a2a000                 cmp     %o2, 0
F0024188: 32bfffdc                 bne,a   loc_F00240F8
F002418C: d2028000                 ld      [%o2], %o1
F0024190: 113c042f                 sethi   %hi(aVfsRemoveVfsNo), %o0! "vfs_remove: vfs not found"
F0024194: 7fffc3f7                 call    _panic
F0024198: 901222a8                 bset    %lo(aVfsRemoveVfsNo), %o0! "vfs_remove: vfs not found"
F002419C: 81c7e008                 ret
F00241A0: 81e80000                 restore

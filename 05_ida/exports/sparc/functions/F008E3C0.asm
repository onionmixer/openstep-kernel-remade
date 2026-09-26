F008E3C0: 9de3bf98                 save    %sp, -0x68, %sp
F008E3C4: 80a62000                 cmp     %i0, 0
F008E3C8: 0280000c                 be      locret_F008E3F8
F008E3CC: a0100018                 mov     %i0, %l0
F008E3D0: 7ffff963                 call    _KernLockAcquire
F008E3D4: d0062024                 ld      [%i0+0x24], %o0
F008E3D8: d2062020                 ld      [%i0+0x20], %o1
F008E3DC: 90026001                 add     %o1, 1, %o0
F008E3E0: 80a22000                 cmp     %o0, 0
F008E3E4: 16800003                 bge     loc_F008E3F0
F008E3E8: d0262020                 st      %o0, [%i0+0x20]
F008E3EC: d2262020                 st      %o1, [%i0+0x20]
F008E3F0: 7ffff96c                 call    _KernLockRelease
F008E3F4: d0042024                 ld      [%l0+0x24], %o0
F008E3F8: 81c7e008                 ret
F008E3FC: 81e80000                 restore

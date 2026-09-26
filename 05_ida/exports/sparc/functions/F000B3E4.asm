F000B3E4: 9de3bf98                 save    %sp, -0x68, %sp
F000B3E8: 7fffffaa                 call    _ufalloc
F000B3EC: 90102000                 mov     0, %o0
F000B3F0: 80a22000                 cmp     %o0, 0
F000B3F4: 16800004                 bge     loc_F000B404
F000B3F8: 113c04d2                 sethi   -0xFECB800, %o0
F000B3FC: 10800020                 ba      locret_F000B47C
F000B400: b0102000                 mov     0, %i0
F000B404: 4001b732                 call    _zalloc
F000B408: d0022230                 ld      [%o0+0x230], %o0
F000B40C: b0100008                 mov     %o0, %i0
F000B410: 113c04d0                 sethi   %hi(dword_F013405C), %o0
F000B414: d202205c                 ld      [%o0+%lo(dword_F013405C)], %o1
F000B418: 9412205c                 or      %o0, %lo(dword_F013405C), %o2
F000B41C: 9002bffc                 add     %o2, -4, %o0
F000B420: 80a24008                 cmp     %o1, %o0
F000B424: 32800003                 bne,a   loc_F000B430
F000B428: f0224000                 st      %i0, [%o1]
F000B42C: f022bffc                 st      %i0, [%o2-4]
F000B430: d2262004                 st      %o1, [%i0+4]
F000B434: 113c04d090122058         set     _file_list, %o0
F000B43C: d0260000                 st      %o0, [%i0]
F000B440: f0222004                 st      %i0, [%o0+4]
F000B444: 90102001                 mov     1, %o0
F000B448: d036200e                 sth     %o0, [%i0+0xE]
F000B44C: c0262018                 clr     [%i0+0x18]
F000B450: c026201c                 clr     [%i0+0x1C]
F000B454: c0262014                 clr     [%i0+0x14]
F000B458: 153c04cf                 sethi   %hi(_active_u), %o2
F000B45C: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F000B460: d202201c                 ld      [%o0+0x1C], %o1
F000B464: d0124000                 lduh    [%o1], %o0
F000B468: 90022001                 inc     %o0
F000B46C: d0324000                 sth     %o0, [%o1]
F000B470: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F000B474: d002201c                 ld      [%o0+0x1C], %o0
F000B478: d0262020                 st      %o0, [%i0+0x20]
F000B47C: 81c7e008                 ret
F000B480: 81e80000                 restore

F008B4D0: 9de3bf98                 save    %sp, -0x68, %sp
F008B4D4: 113c04f6                 sethi   %hi(_vstruct_zone), %o0
F008B4D8: d00221a0                 ld      [%o0+%lo(_vstruct_zone)], %o0! void *
F008B4DC: 7fffb6fc                 call    _zalloc
F008B4E0: a0100018                 mov     %i0, %l0
F008B4E4: b0920000                 orcc    %o0, %g0, %i0
F008B4E8: 22800013                 be,a    locret_F008B534
F008B4EC: b0102000                 mov     0, %i0
F008B4F0: 4000265a                 call    _bzero
F008B4F4: 92102018                 mov     0x18, %o1
F008B4F8: c0260000                 clr     [%i0]
F008B4FC: 90102001                 mov     1, %o0
F008B500: d036200e                 sth     %o0, [%i0+0xE]
F008B504: d0040000                 ld      [%l0], %o0
F008B508: f0220000                 st      %i0, [%o0]
F008B50C: e0262014                 st      %l0, [%i0+0x14]
F008B510: d206200c                 ld      [%i0+0xC], %o1
F008B514: 11200000                 sethi   0x80000000, %o0
F008B518: 902a4008                 andn    %o1, %o0, %o0
F008B51C: d026200c                 st      %o0, [%i0+0xC]
F008B520: d2142006                 lduh    [%l0+6], %o1
F008B524: 90100018                 mov     %i0, %o0
F008B528: 92026001                 inc     %o1
F008B52C: 7ffffdbf                 call    _vnode_pager_vput
F008B530: d2342006                 sth     %o1, [%l0+6]
F008B534: 81c7e008                 ret
F008B538: 81e80000                 restore

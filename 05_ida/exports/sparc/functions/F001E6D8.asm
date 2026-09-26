F001E6D8: 9de3bf98                 save    %sp, -0x68, %sp
F001E6DC: 4001e16e                 call    _splnet
F001E6E0: 01000000                 nop
F001E6E4: a0100008                 mov     %o0, %l0
F001E6E8: 90100018                 mov     %i0, %o0
F001E6EC: 92102002                 mov     2, %o1
F001E6F0: d802200c                 ld      [%o0+0xC], %o4
F001E6F4: 94102000                 mov     0, %o2
F001E6F8: da03201c                 ld      [%o4+0x1C], %o5
F001E6FC: 96100019                 mov     %i1, %o3
F001E700: 9fc34000                 call    %o5
F001E704: 98102000                 mov     0, %o4
F001E708: b0100008                 mov     %o0, %i0
F001E70C: 4001e186                 call    _splx
F001E710: 90100010                 mov     %l0, %o0
F001E714: 81c7e008                 ret
F001E718: 81e80000                 restore

F001EAC0: 9de3bf98                 save    %sp, -0x68, %sp
F001EAC4: 4001e074                 call    _splnet
F001EAC8: 01000000                 nop
F001EACC: a0100008                 mov     %o0, %l0
F001EAD0: 90100018                 mov     %i0, %o0
F001EAD4: 92102011                 mov     0x11, %o1
F001EAD8: d802200c                 ld      [%o0+0xC], %o4
F001EADC: 94102000                 mov     0, %o2
F001EAE0: da03201c                 ld      [%o4+0x1C], %o5
F001EAE4: 96100019                 mov     %i1, %o3
F001EAE8: 9fc34000                 call    %o5
F001EAEC: 98102000                 mov     0, %o4
F001EAF0: b0100008                 mov     %o0, %i0
F001EAF4: 4001e08c                 call    _splx
F001EAF8: 90100010                 mov     %l0, %o0
F001EAFC: 81c7e008                 ret
F001EB00: 81e80000                 restore

F0017A58: 9de3bf98                 save    %sp, -0x68, %sp
F0017A5C: a2100018                 mov     %i0, %l1
F0017A60: e0044000                 ld      [%l1], %l0
F0017A64: d204203c                 ld      [%l0+0x3C], %o1
F0017A68: 11080000                 sethi   0x20000000, %o0
F0017A6C: 808a4008                 btst    %o0, %o1
F0017A70: 22800005                 be,a    loc_F0017A84
F0017A74: d004203c                 ld      [%l0+0x3C], %o0
F0017A78: 4000016e                 call    _ttypend
F0017A7C: 90100010                 mov     %l0, %o0
F0017A80: d004203c                 ld      [%l0+0x3C], %o0
F0017A84: 808a2022                 btst    0x22, %o0 ! '"'
F0017A88: 02800008                 be      locret_F0017AA8
F0017A8C: f004200c                 ld      [%l0+0xC], %i0
F0017A90: d0040000                 ld      [%l0], %o0
F0017A94: d20c6015                 ldub    [%l1+0x15], %o1
F0017A98: b0060008                 add     %i0, %o0, %i0
F0017A9C: 80a60009                 cmp     %i0, %o1
F0017AA0: 26800002                 bl,a    locret_F0017AA8
F0017AA4: b0102000                 mov     0, %i0
F0017AA8: 81c7e008                 ret
F0017AAC: 81e80000                 restore

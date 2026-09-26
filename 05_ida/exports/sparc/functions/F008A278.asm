F008A278: 9de3bf98                 save    %sp, -0x68, %sp
F008A27C: 7ffe1091                 call    _pfind
F008A280: 90100019                 mov     %i1, %o0
F008A284: b2920000                 orcc    %o0, %g0, %i1
F008A288: 2280002b                 be,a    loc_F008A334
F008A28C: c0268000                 clr     [%i2]
F008A290: f006203c                 ld      [%i0+0x3C], %i0
F008A294: 80a62000                 cmp     %i0, 0
F008A298: 22800027                 be,a    loc_F008A334
F008A29C: c0268000                 clr     [%i2]
F008A2A0: d256602c                 ldsh    [%i1+0x2C], %o1
F008A2A4: d056202c                 ldsh    [%i0+0x2C], %o0
F008A2A8: 80a24008                 cmp     %o1, %o0
F008A2AC: 22800008                 be,a    loc_F008A2CC
F008A2B0: d04e6013                 ldsb    [%i1+0x13], %o0
F008A2B4: 7ffe15ae                 call    _suser
F008A2B8: 01000000                 nop
F008A2BC: 80a22000                 cmp     %o0, 0
F008A2C0: 2280001d                 be,a    loc_F008A334
F008A2C4: c0268000                 clr     [%i2]
F008A2C8: d04e6013                 ldsb    [%i1+0x13], %o0
F008A2CC: 80a22005                 cmp     %o0, 5
F008A2D0: 22800019                 be,a    loc_F008A334
F008A2D4: c0268000                 clr     [%i2]
F008A2D8: d0066068                 ld      [%i1+0x68], %o0
F008A2DC: 80a22000                 cmp     %o0, 0
F008A2E0: 02800005                 be      loc_F008A2F4
F008A2E4: 01000000                 nop
F008A2E8: 7fffa39f                 call    _task_reference
F008A2EC: 01000000                 nop
F008A2F0: d0066068                 ld      [%i1+0x68], %o0
F008A2F4: 7ffe159e                 call    _suser
F008A2F8: d0268000                 st      %o0, [%i2]
F008A2FC: 80a22000                 cmp     %o0, 0
F008A300: 0280000b                 be      loc_F008A32C
F008A304: 113c04d0                 sethi   %hi(_active_threads), %o0
F008A308: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F008A30C: d002200c                 ld      [%o0+0xC], %o0
F008A310: d402203c                 ld      [%o0+0x3C], %o2
F008A314: 80a2a000                 cmp     %o2, 0
F008A318: 02800005                 be      loc_F008A32C
F008A31C: 13000020                 sethi   0x8000, %o1
F008A320: d002a014                 ld      [%o2+0x14], %o0
F008A324: 90120009                 bset    %o1, %o0
F008A328: d022a014                 st      %o0, [%o2+0x14]
F008A32C: 10800003                 ba      locret_F008A338
F008A330: b0102000                 mov     0, %i0
F008A334: b0102005                 mov     5, %i0
F008A338: 81c7e008                 ret
F008A33C: 81e80000                 restore

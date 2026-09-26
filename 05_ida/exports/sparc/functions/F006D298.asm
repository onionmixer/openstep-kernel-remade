F006D298: 9de3bf98                 save    %sp, -0x68, %sp
F006D29C: f0060000                 ld      [%i0], %i0
F006D2A0: 80a62000                 cmp     %i0, 0
F006D2A4: 22800015                 be,a    locret_F006D2F8
F006D2A8: f0062034                 ld      [%i0+0x34], %i0
F006D2AC: d2062038                 ld      [%i0+0x38], %o1
F006D2B0: 11020000                 sethi   0x8000000, %o0
F006D2B4: 808a4008                 btst    %o0, %o1
F006D2B8: 22800010                 be,a    locret_F006D2F8
F006D2BC: f0062034                 ld      [%i0+0x34], %i0
F006D2C0: d0562006                 ldsh    [%i0+6], %o0
F006D2C4: 80a22000                 cmp     %o0, 0
F006D2C8: 04800005                 ble     loc_F006D2DC
F006D2CC: 11040000                 sethi   0x10000000, %o0
F006D2D0: 90124008                 bset    %o1, %o0
F006D2D4: 10800008                 ba      loc_F006D2F4
F006D2D8: d0262038                 st      %o0, [%i0+0x38]
F006D2DC: 7ffffd6b                 call    _vmp_get
F006D2E0: 90100018                 mov     %i0, %o0
F006D2E4: 4000005f                 call    _vmp_invalidate
F006D2E8: 90100018                 mov     %i0, %o0
F006D2EC: 7ffffd82                 call    _vmp_put
F006D2F0: 90100018                 mov     %i0, %o0
F006D2F4: f0062034                 ld      [%i0+0x34], %i0
F006D2F8: 81c7e008                 ret
F006D2FC: 81e80000                 restore

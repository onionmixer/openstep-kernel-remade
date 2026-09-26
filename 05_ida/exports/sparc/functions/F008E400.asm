F008E400: 9de3bf98                 save    %sp, -0x68, %sp
F008E404: 80a62000                 cmp     %i0, 0
F008E408: 0280000b                 be      locret_F008E434
F008E40C: a0100018                 mov     %i0, %l0
F008E410: 7ffff953                 call    _KernLockAcquire
F008E414: d0062024                 ld      [%i0+0x24], %o0
F008E418: d0062020                 ld      [%i0+0x20], %o0
F008E41C: 80a22000                 cmp     %o0, 0
F008E420: 04800003                 ble     loc_F008E42C
F008E424: 90023fff                 inc     -1, %o0
F008E428: d0262020                 st      %o0, [%i0+0x20]
F008E42C: 7ffff95d                 call    _KernLockRelease
F008E430: d0042024                 ld      [%l0+0x24], %o0
F008E434: 81c7e008                 ret
F008E438: 81e80000                 restore

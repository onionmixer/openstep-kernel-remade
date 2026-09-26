F008ECAC: 9de3bf98                 save    %sp, -0x68, %sp
F008ECB0: 7ffff72b                 call    _KernLockAcquire
F008ECB4: d0062008                 ld      [%i0+8], %o0
F008ECB8: d0062008                 ld      [%i0+8], %o0
F008ECBC: e00e2018                 ldub    [%i0+0x18], %l0
F008ECC0: 92102001                 mov     1, %o1
F008ECC4: e2062004                 ld      [%i0+4], %l1
F008ECC8: 7ffff736                 call    _KernLockRelease
F008ECCC: d22e2018                 stb     %o1, [%i0+0x18]
F008ECD0: 80a42000                 cmp     %l0, 0
F008ECD4: 12800004                 bne     locret_F008ECE4
F008ECD8: 01000000                 nop
F008ECDC: 7ffffdb9                 call    _KernBusInterruptSuspend
F008ECE0: 90100011                 mov     %l1, %o0
F008ECE4: 81c7e008                 ret
F008ECE8: 81e80000                 restore

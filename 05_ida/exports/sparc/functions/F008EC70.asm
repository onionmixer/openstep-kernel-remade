F008EC70: 9de3bf98                 save    %sp, -0x68, %sp
F008EC74: 7ffff73a                 call    _KernLockAcquire
F008EC78: d0062008                 ld      [%i0+8], %o0
F008EC7C: d0062008                 ld      [%i0+8], %o0
F008EC80: e00e2018                 ldub    [%i0+0x18], %l0
F008EC84: e2062004                 ld      [%i0+4], %l1
F008EC88: 7ffff746                 call    _KernLockRelease
F008EC8C: c02e2018                 clrb    [%i0+0x18]
F008EC90: 80a42000                 cmp     %l0, 0
F008EC94: 02800004                 be      locret_F008ECA4
F008EC98: 01000000                 nop
F008EC9C: 7ffffdd9                 call    _KernBusInterruptResume
F008ECA0: 90100011                 mov     %l1, %o0
F008ECA4: 81c7e008                 ret
F008ECA8: 81e80000                 restore

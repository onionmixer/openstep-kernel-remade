F008EDC4: 9de3bf98                 save    %sp, -0x68, %sp
F008EDC8: 7ffff6e5                 call    _KernLockAcquire
F008EDCC: d0062030                 ld      [%i0+0x30], %o0
F008EDD0: d4062060                 ld      [%i0+0x60], %o2
F008EDD4: 13100000                 sethi   0x40000000, %o1
F008EDD8: d0062030                 ld      [%i0+0x30], %o0
F008EDDC: 922a8009                 andn    %o2, %o1, %o1
F008EDE0: 15200000                 sethi   0x80000000, %o2
F008EDE4: 9212400a                 bset    %o2, %o1
F008EDE8: 7ffff6ee                 call    _KernLockRelease
F008EDEC: d2262060                 st      %o1, [%i0+0x60]
F008EDF0: 90100018                 mov     %i0, %o0
F008EDF4: 1300004092126010         set     0x10010, %o1
F008EDFC: 94102000                 mov     0, %o2
F008EE00: 7fff259f                 call    _ipc_mqueue_send
F008EE04: 96102000                 mov     0, %o3
F008EE08: 80a22000                 cmp     %o0, 0
F008EE0C: 02800006                 be      locret_F008EE24
F008EE10: 01000000                 nop
F008EE14: 7fff2a17                 call    _ipc_object_release
F008EE18: d006202c                 ld      [%i0+0x2C], %o0
F008EE1C: 7fffff6d                 call    _KernDeviceInterruptMsgRelease
F008EE20: 90100018                 mov     %i0, %o0
F008EE24: 81c7e008                 ret
F008EE28: 81e80000                 restore

F008E338: 9de3bf98                 save    %sp, -0x68, %sp
F008E33C: d006201c                 ld      [%i0+0x1C], %o0
F008E340: 7ffff987                 call    _KernLockAcquire
F008E344: e4062028                 ld      [%i0+0x28], %l2
F008E348: e0062018                 ld      [%i0+0x18], %l0
F008E34C: d0062014                 ld      [%i0+0x14], %o0
F008E350: 92100010                 mov     %l0, %o1
F008E354: a0043fff                 inc     -1, %l0
F008E358: 80a26000                 cmp     %o1, 0
F008E35C: 04800009                 ble     loc_F008E380
F008E360: e2022004                 ld      [%o0+4], %l1
F008E364: d0044000                 ld      [%l1], %o0
F008E368: 92100019                 mov     %i1, %o1
F008E36C: 9fc48000                 call    %l2
F008E370: a2046004                 inc     4, %l1
F008E374: 90940000                 orcc    %l0, %g0, %o0
F008E378: 14bffffb                 bg      loc_F008E364
F008E37C: a0043fff                 inc     -1, %l0
F008E380: 7ffff977                 call    _KernLockAcquire
F008E384: d0062024                 ld      [%i0+0x24], %o0
F008E388: d0062018                 ld      [%i0+0x18], %o0
F008E38C: 80a22000                 cmp     %o0, 0
F008E390: 04800006                 ble     loc_F008E3A8
F008E394: a0102000                 mov     0, %l0
F008E398: d0062020                 ld      [%i0+0x20], %o0
F008E39C: 80a00008                 cmp     %g0, %o0
F008E3A0: 90603fff                 subc    %g0, -1, %o0
F008E3A4: a0100008                 mov     %o0, %l0
F008E3A8: 7ffff97e                 call    _KernLockRelease
F008E3AC: d0062024                 ld      [%i0+0x24], %o0
F008E3B0: 7ffff97c                 call    _KernLockRelease
F008E3B4: d006201c                 ld      [%i0+0x1C], %o0
F008E3B8: 81c7e008                 ret
F008E3BC: 91e80010                 restore %g0, %l0, %o0

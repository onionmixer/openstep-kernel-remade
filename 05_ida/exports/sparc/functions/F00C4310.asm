F00C4310: 9de3bf98                 save    %sp, -0x68, %sp
F00C4314: d006201c                 ld      [%i0+0x1C], %o0
F00C4318: 7fff2191                 call    _KernLockAcquire
F00C431C: e6062028                 ld      [%i0+0x28], %l3
F00C4320: e0062018                 ld      [%i0+0x18], %l0
F00C4324: a4102000                 mov     0, %l2
F00C4328: d0062014                 ld      [%i0+0x14], %o0
F00C432C: 92100010                 mov     %l0, %o1
F00C4330: a0043fff                 inc     -1, %l0
F00C4334: 80a26000                 cmp     %o1, 0
F00C4338: 0480000c                 ble     loc_F00C4368
F00C433C: e2022004                 ld      [%o0+4], %l1
F00C4340: d0044000                 ld      [%l1], %o0
F00C4344: 92100019                 mov     %i1, %o1
F00C4348: 9fc4c000                 call    %l3
F00C434C: a2046004                 inc     4, %l1
F00C4350: a4920000                 orcc    %o0, %g0, %l2
F00C4354: 12800005                 bne     loc_F00C4368
F00C4358: 90100010                 mov     %l0, %o0
F00C435C: 80a22000                 cmp     %o0, 0
F00C4360: 14bffff8                 bg      loc_F00C4340
F00C4364: a0043fff                 inc     -1, %l0
F00C4368: 7fff217d                 call    _KernLockAcquire
F00C436C: d0062024                 ld      [%i0+0x24], %o0
F00C4370: 7fff218c                 call    _KernLockRelease
F00C4374: d0062024                 ld      [%i0+0x24], %o0
F00C4378: 7fff218a                 call    _KernLockRelease
F00C437C: d006201c                 ld      [%i0+0x1C], %o0
F00C4380: 81c7e008                 ret
F00C4384: 91e80012                 restore %g0, %l2, %o0

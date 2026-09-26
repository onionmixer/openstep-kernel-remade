F0052080: 9de3bf98                 save    %sp, -0x68, %sp
F0052084: a0100019                 mov     %i1, %l0
F0052088: b32e6010                 sll     %i1, 16, %i1
F005208C: b33e6010                 sra     %i1, 16, %i1
F0052090: 80a67fff                 cmp     %i1, -1
F0052094: 12800003                 bne     loc_F00520A0
F0052098: a210001a                 mov     %i2, %l1
F005209C: e0162068                 lduh    [%i0+0x68], %l0
F00520A0: 912ea010                 sll     %i2, 16, %o0
F00520A4: 913a2010                 sra     %o0, 16, %o0
F00520A8: 80a23fff                 cmp     %o0, -1
F00520AC: 22800002                 be,a    loc_F00520B4
F00520B0: e216206a                 lduh    [%i0+0x6A], %l1
F00520B4: 113c04cf                 sethi   %hi(_active_u), %o0
F00520B8: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00520BC: d202201c                 ld      [%o0+0x1C], %o1
F00520C0: 912c2010                 sll     %l0, 16, %o0
F00520C4: d2526002                 ldsh    [%o1+2], %o1
F00520C8: 913a2010                 sra     %o0, 16, %o0
F00520CC: 80a24008                 cmp     %o1, %o0
F00520D0: 1280000b                 bne     loc_F00520FC
F00520D4: 01000000                 nop
F00520D8: d0562068                 ldsh    [%i0+0x68], %o0
F00520DC: 80a24008                 cmp     %o1, %o0
F00520E0: 12800007                 bne     loc_F00520FC
F00520E4: 912c6010                 sll     %l1, 16, %o0
F00520E8: 7ffef604                 call    _groupmember
F00520EC: 913a2010                 sra     %o0, 16, %o0
F00520F0: 80a22000                 cmp     %o0, 0
F00520F4: 32800009                 bne,a   loc_F0052118
F00520F8: e0362068                 sth     %l0, [%i0+0x68]
F00520FC: 7ffef61c                 call    _suser
F0052100: 01000000                 nop
F0052104: 80a22000                 cmp     %o0, 0
F0052108: 32800004                 bne,a   loc_F0052118
F005210C: e0362068                 sth     %l0, [%i0+0x68]
F0052110: 10800011                 ba      locret_F0052154
F0052114: b0102001                 mov     1, %i0
F0052118: d0162044                 lduh    [%i0+0x44], %o0
F005211C: e236206a                 sth     %l1, [%i0+0x6A]
F0052120: 90122040                 bset    0x40, %o0 ! '@'
F0052124: d0362044                 sth     %o0, [%i0+0x44]
F0052128: 113c04cf                 sethi   %hi(_active_u), %o0
F005212C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0052130: d002201c                 ld      [%o0+0x1C], %o0
F0052134: d0522002                 ldsh    [%o0+2], %o0
F0052138: 80a22000                 cmp     %o0, 0
F005213C: 22800006                 be,a    locret_F0052154
F0052140: b0102000                 mov     0, %i0
F0052144: d0162064                 lduh    [%i0+0x64], %o0
F0052148: 900a33ff                 and     %o0, -0xC01, %o0
F005214C: d0362064                 sth     %o0, [%i0+0x64]
F0052150: b0102000                 mov     0, %i0
F0052154: 81c7e008                 ret
F0052158: 81e80000                 restore

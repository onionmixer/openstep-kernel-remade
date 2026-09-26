F001FFA8: 9de3bf98                 save    %sp, -0x68, %sp
F001FFAC: d2162006                 lduh    [%i0+6], %o1
F001FFB0: 90062054                 add     %i0, 0x54, %o0 ! 'T'
F001FFB4: 920a7ff5                 and     %o1, -0xB, %o1
F001FFB8: 92126004                 bset    4, %o1
F001FFBC: 7fffcb8b                 call    _wakeup
F001FFC0: d2362006                 sth     %o1, [%i0+6]
F001FFC4: 81c7e008                 ret
F001FFC8: 81e80000                 restore

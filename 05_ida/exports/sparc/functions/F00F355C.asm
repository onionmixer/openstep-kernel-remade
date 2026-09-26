F00F355C: 9de3bf98                 save    %sp, -0x68, %sp
F00F3560: 7ffff4d6                 call    __objc_create_zone
F00F3564: a0100018                 mov     %i0, %l0
F00F3568: d4022004                 ld      [%o0+4], %o2
F00F356C: 9fc28000                 call    %o2
F00F3570: 92100010                 mov     %l0, %o1
F00F3574: b0920000                 orcc    %o0, %g0, %i0
F00F3578: 12800006                 bne     locret_F00F3590
F00F357C: 80a42000                 cmp     %l0, 0
F00F3580: 02800004                 be      locret_F00F3590
F00F3584: 113c03f4                 sethi   %hi(aUnableToAlloca), %o0! "unable to allocate space"
F00F3588: 7ffff520                 call    __objc_fatal
F00F358C: 90122110                 bset    %lo(aUnableToAlloca), %o0! "unable to allocate space"
F00F3590: 81c7e008                 ret
F00F3594: 81e80000                 restore

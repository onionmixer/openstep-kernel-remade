F007525C: 9de3bf98                 save    %sp, -0x68, %sp
F0075260: 4000864a                 call    _splusclock
F0075264: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0075268: a2100008                 mov     %o0, %l1
F007526C: d0040000                 ld      [%l0], %o0
F0075270: 80a22000                 cmp     %o0, 0
F0075274: 12bffffe                 bne     loc_F007526C
F0075278: 01000000                 nop
F007527C: 4000870b                 call    _simple_lock_try
F0075280: 90100010                 mov     %l0, %o0
F0075284: 80a22000                 cmp     %o0, 0
F0075288: 02bffff9                 be      loc_F007526C
F007528C: 01000000                 nop
F0075290: c0262020                 clr     [%i0+0x20]
F0075294: d4062040                 ld      [%i0+0x40], %o2
F0075298: 90100011                 mov     %l1, %o0
F007529C: d206204c                 ld      [%i0+0x4C], %o1
F00752A0: 9402a001                 inc     %o2
F00752A4: d4262040                 st      %o2, [%i0+0x40]
F00752A8: 92126002                 bset    2, %o1
F00752AC: 4000869e                 call    _splx
F00752B0: d226204c                 st      %o1, [%i0+0x4C]
F00752B4: 81c7e008                 ret
F00752B8: 81e80000                 restore

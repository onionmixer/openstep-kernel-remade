F00EE5D8: 9de3bf98                 save    %sp, -0x68, %sp
F00EE5DC: e006200c                 ld      [%i0+0xC], %l0
F00EE5E0: d0060000                 ld      [%i0], %o0
F00EE5E4: e2062008                 ld      [%i0+8], %l1
F00EE5E8: a2047fff                 inc     -1, %l1
F00EE5EC: 80a47fff                 cmp     %l1, -1
F00EE5F0: 0280000f                 be      loc_F00EE62C
F00EE5F4: e4022008                 ld      [%o0+8], %l2
F00EE5F8: a6103fff                 mov     -1, %l3
F00EE5FC: d2040000                 ld      [%l0], %o1
F00EE600: 80a27fff                 cmp     %o1, -1
F00EE604: 02800006                 be      loc_F00EE61C
F00EE608: 90100018                 mov     %i0, %o0
F00EE60C: 9fc48000                 call    %l2
F00EE610: d4042004                 ld      [%l0+4], %o2
F00EE614: e6240000                 st      %l3, [%l0]
F00EE618: c0242004                 clr     [%l0+4]
F00EE61C: a2047fff                 inc     -1, %l1
F00EE620: 80a47fff                 cmp     %l1, -1
F00EE624: 12bffff6                 bne     loc_F00EE5FC
F00EE628: a0042008                 inc     8, %l0
F00EE62C: c0262004                 clr     [%i0+4]
F00EE630: 81c7e008                 ret
F00EE634: 81e80000                 restore

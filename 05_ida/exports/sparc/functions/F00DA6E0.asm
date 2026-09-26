F00DA6E0: 9de3bf90                 save    %sp, -0x70, %sp
F00DA6E4: d0062024                 ld      [%i0+0x24], %o0
F00DA6E8: 92062024                 add     %i0, 0x24, %o1 ! '$'
F00DA6EC: 80a24008                 cmp     %o1, %o0
F00DA6F0: 0280000c                 be      loc_F00DA720
F00DA6F4: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00DA6F8: 233c0505                 sethi   %hi(paDequeuedescrip), %l1
F00DA6FC: a0100009                 mov     %o1, %l0
F00DA700: d2046188                 ld      [%l1+%lo(paDequeuedescrip)], %o1! SEL
F00DA704: 40005c5b                 call    _objc_msgSend
F00DA708: 90100018                 mov     %i0, %o0
F00DA70C: d0062024                 ld      [%i0+0x24], %o0
F00DA710: 80a40008                 cmp     %l0, %o0
F00DA714: 12bffffc                 bne     loc_F00DA704
F00DA718: d2046188                 ld      [%l1+0x188], %o1
F00DA71C: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00DA720: d20220a4                 ld      [%o0+0xA4], %o1! SEL
F00DA724: 40005c53                 call    _objc_msgSend
F00DA728: 90100018                 mov     %i0, %o0
F00DA72C: 81c7e008                 ret
F00DA730: 81e80000                 restore

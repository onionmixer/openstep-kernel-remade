F0034788: 9de3bf98                 save    %sp, -0x68, %sp
F003478C: 80a62000                 cmp     %i0, 0
F0034790: 02800012                 be      locret_F00347D8
F0034794: a0102000                 mov     0, %l0
F0034798: d0062004                 ld      [%i0+4], %o0
F003479C: a4060008                 add     %i0, %o0, %l2
F00347A0: d014a006                 lduh    [%l2+6], %o0
F00347A4: 80a40008                 cmp     %l0, %o0
F00347A8: 1680000a                 bge     loc_F00347D0
F00347AC: 01000000                 nop
F00347B0: a2100012                 mov     %l2, %l1
F00347B4: d0046008                 ld      [%l1+8], %o0
F00347B8: 7fffebf5                 call    _in_delmulti
F00347BC: a0042001                 inc     %l0
F00347C0: d014a006                 lduh    [%l2+6], %o0
F00347C4: 80a40008                 cmp     %l0, %o0
F00347C8: 06bffffb                 bl      loc_F00347B4
F00347CC: a2046004                 inc     4, %l1
F00347D0: 7fffa4b9                 call    _m_free
F00347D4: 90100018                 mov     %i0, %o0
F00347D8: 81c7e008                 ret
F00347DC: 81e80000                 restore

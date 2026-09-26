F006F560: 9de3bf98                 save    %sp, -0x68, %sp
F006F564: 80a62000                 cmp     %i0, 0
F006F568: 02800007                 be      loc_F006F584
F006F56C: 80a66001                 cmp     %i1, 1
F006F570: 02800005                 be      loc_F006F584
F006F574: 90067fff                 add     %i1, -1, %o0
F006F578: 80a22003                 cmp     %o0, 3
F006F57C: 08800004                 bleu    loc_F006F58C
F006F580: a0062158                 add     %i0, 0x158, %l0
F006F584: 10800025                 ba      locret_F006F618
F006F588: b0102004                 mov     4, %i0
F006F58C: d0040000                 ld      [%l0], %o0
F006F590: 80a22000                 cmp     %o0, 0
F006F594: 12bffffe                 bne     loc_F006F58C
F006F598: 01000000                 nop
F006F59C: 40009e43                 call    _simple_lock_try
F006F5A0: 90100010                 mov     %l0, %o0
F006F5A4: 80a22000                 cmp     %o0, 0
F006F5A8: 02bffff9                 be      loc_F006F58C
F006F5AC: 01000000                 nop
F006F5B0: d0062168                 ld      [%i0+0x168], %o0
F006F5B4: 808a0019                 btst    %i1, %o0
F006F5B8: 02800016                 be      loc_F006F610
F006F5BC: 902a0019                 bclr    %i1, %o0
F006F5C0: 80a6a000                 cmp     %i2, 0
F006F5C4: 02800013                 be      loc_F006F610
F006F5C8: d0262168                 st      %o0, [%i0+0x168]
F006F5CC: f4062138                 ld      [%i0+0x138], %i2
F006F5D0: a0062138                 add     %i0, 0x138, %l0
F006F5D4: 80a4001a                 cmp     %l0, %i2
F006F5D8: 0280000e                 be      loc_F006F610
F006F5DC: 01000000                 nop
F006F5E0: d006a060                 ld      [%i2+0x60], %o0
F006F5E4: 80a20019                 cmp     %o0, %i1
F006F5E8: 32800007                 bne,a   loc_F006F604
F006F5EC: f406a018                 ld      [%i2+0x18], %i2
F006F5F0: 9010001a                 mov     %i2, %o0! thr_act
F006F5F4: 92102001                 mov     1, %o1! policy
F006F5F8: 400019eb                 call    _thread_policy
F006F5FC: 94102000                 mov     0, %o2
F006F600: f406a018                 ld      [%i2+0x18], %i2
F006F604: 80a4001a                 cmp     %l0, %i2
F006F608: 32bffff7                 bne,a   loc_F006F5E4
F006F60C: d006a060                 ld      [%i2+0x60], %o0
F006F610: c0262158                 clr     [%i0+0x158]
F006F614: b0102000                 mov     0, %i0
F006F618: 81c7e008                 ret
F006F61C: 81e80000                 restore

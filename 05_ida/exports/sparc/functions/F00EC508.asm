F00EC508: 9de3bf90                 save    %sp, -0x70, %sp
F00EC50C: a0102000                 mov     0, %l0
F00EC510: 80a4001b                 cmp     %l0, %i3
F00EC514: 16800028                 bge     locret_F00EC5B4
F00EC518: 273c03f3                 sethi   -0xFF03400, %l3
F00EC51C: 253c03f3                 sethi   -0xFF03400, %l2
F00EC520: 912c2002                 sll     %l0, 2, %o0
F00EC524: 90020010                 add     %o0, %l0, %o0
F00EC528: 932a2002                 sll     %o0, 2, %o1
F00EC52C: d0068009                 ld      [%i2+%o1], %o0
F00EC530: 80a22001                 cmp     %o0, 1
F00EC534: 14800009                 bg      loc_F00EC558
F00EC538: 912c2002                 sll     %l0, 2, %o0
F00EC53C: 92068009                 add     %i2, %o1, %o1
F00EC540: d0026008                 ld      [%o1+8], %o0
F00EC544: 80a22000                 cmp     %o0, 0
F00EC548: 02800003                 be      loc_F00EC554
F00EC54C: 90023ffc                 inc     -4, %o0
F00EC550: d0226008                 st      %o0, [%o1+8]
F00EC554: 912c2002                 sll     %l0, 2, %o0
F00EC558: 90020010                 add     %o0, %l0, %o0
F00EC55C: 932a2002                 sll     %o0, 2, %o1
F00EC560: d0068009                 ld      [%i2+%o1], %o0
F00EC564: 80a22000                 cmp     %o0, 0
F00EC568: 1280000d                 bne     loc_F00EC59C
F00EC56C: 912c2002                 sll     %l0, 2, %o0
F00EC570: a2068009                 add     %i2, %o1, %l1
F00EC574: d0046008                 ld      [%l1+8], %o0
F00EC578: 80a22000                 cmp     %o0, 0
F00EC57C: 02800008                 be      loc_F00EC59C
F00EC580: 912c2002                 sll     %l0, 2, %o0
F00EC584: 4000112b                 call    __objc_inform
F00EC588: 9014e1a8                 or      %l3, 0x1A8, %o0
F00EC58C: 9014a1d0                 or      %l2, 0x1D0, %o0
F00EC590: 40001128                 call    __objc_inform
F00EC594: d2046004                 ld      [%l1+4], %o1
F00EC598: 912c2002                 sll     %l0, 2, %o0
F00EC59C: 90020010                 add     %o0, %l0, %o0
F00EC5A0: 912a2002                 sll     %o0, 2, %o0
F00EC5A4: a0042001                 inc     %l0
F00EC5A8: 80a4001b                 cmp     %l0, %i3
F00EC5AC: 06bfffdd                 bl      loc_F00EC520
F00EC5B0: f0268008                 st      %i0, [%i2+%o0]
F00EC5B4: 81c7e008                 ret
F00EC5B8: 81e80000                 restore

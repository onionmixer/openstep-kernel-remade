F007656C: 9de3bf98                 save    %sp, -0x68, %sp
F0076570: 293c04f2a6152330         set     _swapper_lock_data, %l3
F0076578: 2b3c04f2                 sethi   -0xFEC3800, %l5
F007657C: 40008183                 call    _splusclock
F0076580: 01000000                 nop
F0076584: a2100008                 mov     %o0, %l1
F0076588: d004c000                 ld      [%l3], %o0
F007658C: 80a22000                 cmp     %o0, 0
F0076590: 12bffffe                 bne     loc_F0076588
F0076594: 01000000                 nop
F0076598: 40008244                 call    _simple_lock_try
F007659C: 90100013                 mov     %l3, %o0
F00765A0: 80a22000                 cmp     %o0, 0
F00765A4: 02bffff9                 be      loc_F0076588
F00765A8: 113c04f2                 sethi   %hi(_swapin_queue), %o0
F00765AC: a4122328                 or      %o0, %lo(_swapin_queue), %l2
F00765B0: d2056328                 ld      [%l5+0x328], %o1
F00765B4: 80a24012                 cmp     %o1, %l2
F00765B8: 32800004                 bne,a   loc_F00765C8
F00765BC: d0024000                 ld      [%o1], %o0
F00765C0: 10800006                 ba      loc_F00765D8
F00765C4: a0102000                 mov     0, %l0
F00765C8: e4222004                 st      %l2, [%o0+4]
F00765CC: d0024000                 ld      [%o1], %o0
F00765D0: a0100009                 mov     %o1, %l0
F00765D4: d0256328                 st      %o0, [%l5+0x328]
F00765D8: 80a42000                 cmp     %l0, 0
F00765DC: 02800014                 be      loc_F007662C
F00765E0: 90156328                 or      %l5, 0x328, %o0
F00765E4: c0252330                 clr     [%l4+0x330]
F00765E8: 400081cf                 call    _splx
F00765EC: 90100011                 mov     %l1, %o0
F00765F0: 7fffffc1                 call    _thread_doswapin
F00765F4: 90100010                 mov     %l0, %o0
F00765F8: 40008164                 call    _splusclock
F00765FC: a0152330                 or      %l4, 0x330, %l0
F0076600: a2100008                 mov     %o0, %l1
F0076604: d0040000                 ld      [%l0], %o0
F0076608: 80a22000                 cmp     %o0, 0
F007660C: 12bffffe                 bne     loc_F0076604
F0076610: 01000000                 nop
F0076614: 40008225                 call    _simple_lock_try
F0076618: 90100010                 mov     %l0, %o0
F007661C: 80a22000                 cmp     %o0, 0
F0076620: 02bffff9                 be      loc_F0076604
F0076624: d2056328                 ld      [%l5+0x328], %o1
F0076628: 30bfffe3                 ba,a    loc_F00765B4
F007662C: 7fffe9aa                 call    _assert_wait
F0076630: 92102000                 mov     0, %o1
F0076634: c0252330                 clr     [%l4+0x330]
F0076638: 400081bb                 call    _splx
F007663C: 90100011                 mov     %l1, %o0
F0076640: 113c01d9                 sethi   %hi(_swapin_thread_continue), %o0
F0076644: 7fffec3f                 call    _thread_block_with_continuation
F0076648: 9012216c                 bset    %lo(_swapin_thread_continue), %o0
F007664C: 30bfffcc                 ba,a    loc_F007657C

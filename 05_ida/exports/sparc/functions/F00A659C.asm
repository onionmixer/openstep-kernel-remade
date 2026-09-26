F00A659C: 9de3bf98                 save    %sp, -0x68, %sp
F00A65A0: 113c04f890122110         set     _a_head, %o0
F00A65A8: 952e2002                 sll     %i0, 2, %o2
F00A65AC: d2028008                 ld      [%o2+%o0], %o1
F00A65B0: 92026001                 inc     %o1
F00A65B4: 920a603f                 and     %o1, 0x3F, %o1
F00A65B8: d2228008                 st      %o1, [%o2+%o0]
F00A65BC: 113c04f890122118         set     _a_tail, %o0
F00A65C4: d0028008                 ld      [%o2+%o0], %o0
F00A65C8: a0100009                 mov     %o1, %l0
F00A65CC: 80a40008                 cmp     %l0, %o0
F00A65D0: 12800006                 bne     loc_F00A65E8
F00A65D4: 153c04f9                 sethi   -0xFEC1C00, %o2
F00A65D8: 113c0467                 sethi   %hi(aOverflowOfAsyn), %o0! "Overflow of asynchronous faults.\n"
F00A65DC: 7ffdbae5                 call    _panic
F00A65E0: 90122050                 bset    %lo(aOverflowOfAsyn), %o0! "Overflow of asynchronous faults.\n"
F00A65E4: 153c04f9                 sethi   -0xFEC1C00, %o2
F00A65E8: 9412a270                 bset    0x270, %o2
F00A65EC: 932c2001                 sll     %l0, 1, %o1
F00A65F0: 92024010                 add     %o1, %l0, %o1
F00A65F4: 932a6003                 sll     %o1, 3, %o1
F00A65F8: 912e2001                 sll     %i0, 1, %o0
F00A65FC: 90020018                 add     %o0, %i0, %o0
F00A6600: 912a2009                 sll     %o0, 9, %o0
F00A6604: 92024008                 add     %o1, %o0, %o1
F00A6608: f232400a                 sth     %i1, [%o1+%o2]
F00A660C: 9202400a                 add     %o1, %o2, %o1
F00A6610: f4226004                 st      %i2, [%o1+4]
F00A6614: f6226008                 st      %i3, [%o1+8]
F00A6618: f822600c                 st      %i4, [%o1+0xC]
F00A661C: 90100018                 mov     %i0, %o0
F00A6620: 7fffffcb                 call    _send_dirint
F00A6624: 9210200c                 mov     0xC, %o1
F00A6628: 81c7e008                 ret
F00A662C: 81e80000                 restore

F002C504: 9de3bf98                 save    %sp, -0x68, %sp
F002C508: d0062038                 ld      [%i0+0x38], %o0
F002C50C: 80a22000                 cmp     %o0, 0
F002C510: 02800004                 be      loc_F002C520
F002C514: e0062008                 ld      [%i0+8], %l0
F002C518: 40000243                 call    _rtfree
F002C51C: 01000000                 nop
F002C520: c0242008                 clr     [%l0+8]
F002C524: 7fffc8a4                 call    _sofree
F002C528: 90100010                 mov     %l0, %o0
F002C52C: d2060000                 ld      [%i0], %o1
F002C530: d0062004                 ld      [%i0+4], %o0
F002C534: d0226004                 st      %o0, [%o1+4]
F002C538: d2062004                 ld      [%i0+4], %o1
F002C53C: d0060000                 ld      [%i0], %o0
F002C540: d0224000                 st      %o0, [%o1]
F002C544: d0062034                 ld      [%i0+0x34], %o0
F002C548: 80a22000                 cmp     %o0, 0
F002C54C: 22800005                 be,a    loc_F002C560
F002C550: 113c0432                 sethi   -0xFEF3800, %o0
F002C554: 7fffc5c4                 call    _m_freem
F002C558: 900a3f80                 and     %o0, -0x80, %o0
F002C55C: 113c0432                 sethi   -0xFEF3800, %o0
F002C560: d00221e0                 ld      [%o0+0x1E0], %o0
F002C564: 80a40008                 cmp     %l0, %o0
F002C568: 32800005                 bne,a   loc_F002C57C
F002C56C: d016202c                 lduh    [%i0+0x2C], %o0
F002C570: 40003420                 call    _ip_mrouter_done
F002C574: 01000000                 nop
F002C578: d016202c                 lduh    [%i0+0x2C], %o0
F002C57C: 80a22002                 cmp     %o0, 2
F002C580: 12800004                 bne     loc_F002C590
F002C584: 01000000                 nop
F002C588: 40002080                 call    _ip_freemoptions
F002C58C: d0062050                 ld      [%i0+0x50], %o0
F002C590: 7fffc5b5                 call    _m_freem
F002C594: 900e3f80                 and     %i0, -0x80, %o0
F002C598: 81c7e008                 ret
F002C59C: 81e80000                 restore

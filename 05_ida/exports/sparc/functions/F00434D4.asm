F00434D4: 9de3bf98                 save    %sp, -0x68, %sp
F00434D8: a8100018                 mov     %i0, %l4
F00434DC: 90102001                 mov     1, %o0
F00434E0: 7fff691f                 call    _m_get
F00434E4: 92102008                 mov     8, %o1
F00434E8: a2920000                 orcc    %o0, %g0, %l1
F00434EC: 12800007                 bne     loc_F0043508
F00434F0: 90102002                 mov     2, %o0
F00434F4: 113c0436                 sethi   %hi(aBindresvportCo), %o0! "bindresvport: couldn't alloc mbuf"
F00434F8: 7fff4458                 call    _printf
F00434FC: 90122278                 bset    %lo(aBindresvportCo), %o0! "bindresvport: couldn't alloc mbuf"
F0043500: 10800028                 ba      locret_F00435A0
F0043504: b0102037                 mov     0x37, %i0 ! '7'
F0043508: d2046004                 ld      [%l1+4], %o1
F004350C: 213c04cf                 sethi   %hi(_active_u), %l0
F0043510: d0344009                 sth     %o0, [%l1+%o1]
F0043514: a4044009                 add     %l1, %o1, %l2
F0043518: c024a004                 clr     [%l2+4]
F004351C: 90102010                 mov     0x10, %o0
F0043520: d0346008                 sth     %o0, [%l1+8]
F0043524: d00421d8                 ld      [%l0+%lo(_active_u)], %o0
F0043528: 7fff315f                 call    _crdup
F004352C: d002201c                 ld      [%o0+0x1C], %o0
F0043530: d20421d8                 ld      [%l0+%lo(_active_u)], %o1
F0043534: ea02601c                 ld      [%o1+0x1C], %l5
F0043538: a6100008                 mov     %o0, %l3
F004353C: e622601c                 st      %l3, [%o1+0x1C]
F0043540: d00421d8                 ld      [%l0+%lo(_active_u)], %o0
F0043544: b0102030                 mov     0x30, %i0 ! '0'
F0043548: d002201c                 ld      [%o0+0x1C], %o0
F004354C: a01023ff                 mov     0x3FF, %l0
F0043550: c0322002                 clrh    [%o0+2]
F0043554: 912c2010                 sll     %l0, 16, %o0
F0043558: 91322010                 srl     %o0, 16, %o0
F004355C: 80a221ff                 cmp     %o0, 0x1FF
F0043560: 08800009                 bleu    loc_F0043584
F0043564: 90100014                 mov     %l4, %o0
F0043568: e034a002                 sth     %l0, [%l2+2]
F004356C: 7fff6c5b                 call    _sobind
F0043570: 92100011                 mov     %l1, %o1
F0043574: b0100008                 mov     %o0, %i0
F0043578: 80a62030                 cmp     %i0, 0x30 ! '0'
F004357C: 02bffff6                 be      loc_F0043554
F0043580: a0043fff                 inc     -1, %l0
F0043584: 7fff69b8                 call    _m_freem
F0043588: 90100011                 mov     %l1, %o0
F004358C: 113c04cf                 sethi   %hi(_active_u), %o0
F0043590: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0043594: 90100013                 mov     %l3, %o0
F0043598: 7fff3120                 call    _crfree
F004359C: ea22601c                 st      %l5, [%o1+0x1C]
F00435A0: 81c7e008                 ret
F00435A4: 81e80000                 restore

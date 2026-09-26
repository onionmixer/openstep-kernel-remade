F00EC7EC: 9de3bf98                 save    %sp, -0x68, %sp
F00EC7F0: a2100018                 mov     %i0, %l1
F00EC7F4: b0102000                 mov     0, %i0
F00EC7F8: 10800019                 ba      loc_F00EC85C
F00EC7FC: a0102000                 mov     0, %l0
F00EC800: 90020011                 add     %o0, %l1, %o0
F00EC804: d0022008                 ld      [%o0+8], %o0
F00EC808: d0022010                 ld      [%o0+0x10], %o0
F00EC80C: 80a22000                 cmp     %o0, 0
F00EC810: 02800005                 be      loc_F00EC824
F00EC814: 80a62000                 cmp     %i0, 0
F00EC818: 7fffffba                 call    sub_F00EC700
F00EC81C: 92100019                 mov     %i1, %o1
F00EC820: b0920000                 orcc    %o0, %g0, %i0
F00EC824: 1280000c                 bne     loc_F00EC854
F00EC828: 80a62000                 cmp     %i0, 0
F00EC82C: 912c2002                 sll     %l0, 2, %o0
F00EC830: 90020011                 add     %o0, %l1, %o0
F00EC834: d0022008                 ld      [%o0+8], %o0
F00EC838: d0022008                 ld      [%o0+8], %o0
F00EC83C: 80a22000                 cmp     %o0, 0
F00EC840: 02800005                 be      loc_F00EC854
F00EC844: 80a62000                 cmp     %i0, 0
F00EC848: 7fffffe9                 call    sub_F00EC7EC
F00EC84C: 92100019                 mov     %i1, %o1
F00EC850: b0920000                 orcc    %o0, %g0, %i0
F00EC854: 12800007                 bne     locret_F00EC870
F00EC858: a0042001                 inc     %l0
F00EC85C: d0046004                 ld      [%l1+4], %o0
F00EC860: 80a40008                 cmp     %l0, %o0
F00EC864: 06bfffe7                 bl      loc_F00EC800
F00EC868: 912c2002                 sll     %l0, 2, %o0
F00EC86C: b0102000                 mov     0, %i0
F00EC870: 81c7e008                 ret
F00EC874: 81e80000                 restore

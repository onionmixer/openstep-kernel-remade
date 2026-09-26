F00EC760: 9de3bf98                 save    %sp, -0x68, %sp
F00EC764: a2100018                 mov     %i0, %l1
F00EC768: b0102000                 mov     0, %i0
F00EC76C: 10800019                 ba      loc_F00EC7D0
F00EC770: a0102000                 mov     0, %l0
F00EC774: 90020011                 add     %o0, %l1, %o0
F00EC778: d0022008                 ld      [%o0+8], %o0
F00EC77C: d002200c                 ld      [%o0+0xC], %o0
F00EC780: 80a22000                 cmp     %o0, 0
F00EC784: 02800005                 be      loc_F00EC798
F00EC788: 80a62000                 cmp     %i0, 0
F00EC78C: 7fffffdd                 call    sub_F00EC700
F00EC790: 92100019                 mov     %i1, %o1
F00EC794: b0920000                 orcc    %o0, %g0, %i0
F00EC798: 1280000c                 bne     loc_F00EC7C8
F00EC79C: 80a62000                 cmp     %i0, 0
F00EC7A0: 912c2002                 sll     %l0, 2, %o0
F00EC7A4: 90020011                 add     %o0, %l1, %o0
F00EC7A8: d0022008                 ld      [%o0+8], %o0
F00EC7AC: d0022008                 ld      [%o0+8], %o0
F00EC7B0: 80a22000                 cmp     %o0, 0
F00EC7B4: 02800005                 be      loc_F00EC7C8
F00EC7B8: 80a62000                 cmp     %i0, 0
F00EC7BC: 7fffffe9                 call    sub_F00EC760
F00EC7C0: 92100019                 mov     %i1, %o1
F00EC7C4: b0920000                 orcc    %o0, %g0, %i0
F00EC7C8: 12800007                 bne     locret_F00EC7E4
F00EC7CC: a0042001                 inc     %l0
F00EC7D0: d0046004                 ld      [%l1+4], %o0
F00EC7D4: 80a40008                 cmp     %l0, %o0
F00EC7D8: 06bfffe7                 bl      loc_F00EC774
F00EC7DC: 912c2002                 sll     %l0, 2, %o0
F00EC7E0: b0102000                 mov     0, %i0
F00EC7E4: 81c7e008                 ret
F00EC7E8: 81e80000                 restore

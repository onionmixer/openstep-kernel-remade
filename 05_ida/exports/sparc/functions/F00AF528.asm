F00AF528: 9de3bf98                 save    %sp, -0x68, %sp
F00AF52C: a0102000                 mov     0, %l0
F00AF530: 10800011                 ba      loc_F00AF574
F00AF534: 233c0470                 sethi   -0xFEE4000, %l1
F00AF538: 02800013                 be      loc_F00AF584
F00AF53C: d2068000                 ld      [%i2], %o1
F00AF540: 90026004                 add     %o1, 4, %o0
F00AF544: d0268000                 st      %o0, [%i2]
F00AF548: f0224000                 st      %i0, [%o1]
F00AF54C: d2068000                 ld      [%i2], %o1
F00AF550: d006a008                 ld      [%i2+8], %o0! char *
F00AF554: 80a24008                 cmp     %o1, %o0
F00AF558: 08800004                 bleu    loc_F00AF568
F00AF55C: 01000000                 nop
F00AF560: 7ffd9704                 call    _panic
F00AF564: 901462b8                 or      %l1, 0x2B8, %o0
F00AF568: 7fffffcd                 call    _prom_childnode
F00AF56C: 90100018                 mov     %i0, %o0
F00AF570: b0100008                 mov     %o0, %i0
F00AF574: 80a63fff                 cmp     %i0, -1
F00AF578: 12bffff0                 bne     loc_F00AF538
F00AF57C: 80a62000                 cmp     %i0, 0
F00AF580: d2068000                 ld      [%i2], %o1
F00AF584: d006a004                 ld      [%i2+4], %o0
F00AF588: 80a24008                 cmp     %o1, %o0
F00AF58C: 0880000e                 bleu    loc_F00AF5C4
F00AF590: 90027ffc                 add     %o1, -4, %o0
F00AF594: d0268000                 st      %o0, [%i2]
F00AF598: f0027ffc                 ld      [%o1-4], %i0
F00AF59C: 90100018                 mov     %i0, %o0
F00AF5A0: 40000010                 call    _prom_getnode_byname
F00AF5A4: 92100019                 mov     %i1, %o1
F00AF5A8: 80a22000                 cmp     %o0, 0
F00AF5AC: 1280000b                 bne     locret_F00AF5D8
F00AF5B0: 01000000                 nop
F00AF5B4: 7fffffb1                 call    _prom_nextnode
F00AF5B8: 90100018                 mov     %i0, %o0
F00AF5BC: 10800003                 ba      loc_F00AF5C8
F00AF5C0: b0100008                 mov     %o0, %i0
F00AF5C4: a0102001                 mov     1, %l0
F00AF5C8: 80a42000                 cmp     %l0, 0
F00AF5CC: 02bfffeb                 be      loc_F00AF578
F00AF5D0: 80a63fff                 cmp     %i0, -1
F00AF5D4: b0102000                 mov     0, %i0
F00AF5D8: 81c7e008                 ret
F00AF5DC: 81e80000                 restore

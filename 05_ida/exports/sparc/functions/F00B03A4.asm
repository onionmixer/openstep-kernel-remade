F00B03A4: 9de3bf98                 save    %sp, -0x68, %sp
F00B03A8: a0102000                 mov     0, %l0
F00B03AC: 10800011                 ba      loc_F00B03F0
F00B03B0: 233c0470                 sethi   -0xFEE4000, %l1
F00B03B4: 02800013                 be      loc_F00B0400
F00B03B8: d2068000                 ld      [%i2], %o1
F00B03BC: 90026004                 add     %o1, 4, %o0
F00B03C0: d0268000                 st      %o0, [%i2]
F00B03C4: f0224000                 st      %i0, [%o1]
F00B03C8: d2068000                 ld      [%i2], %o1
F00B03CC: d006a008                 ld      [%i2+8], %o0
F00B03D0: 80a24008                 cmp     %o1, %o0
F00B03D4: 08800004                 bleu    loc_F00B03E4
F00B03D8: 01000000                 nop
F00B03DC: 40000059                 call    _prom_panic
F00B03E0: 90146380                 or      %l1, 0x380, %o0
F00B03E4: 7ffffc2e                 call    _prom_childnode
F00B03E8: 90100018                 mov     %i0, %o0
F00B03EC: b0100008                 mov     %o0, %i0
F00B03F0: 80a63fff                 cmp     %i0, -1
F00B03F4: 12bffff0                 bne     loc_F00B03B4
F00B03F8: 80a62000                 cmp     %i0, 0
F00B03FC: d2068000                 ld      [%i2], %o1
F00B0400: d006a004                 ld      [%i2+4], %o0
F00B0404: 80a24008                 cmp     %o1, %o0
F00B0408: 0880000e                 bleu    loc_F00B0440
F00B040C: 90027ffc                 add     %o1, -4, %o0
F00B0410: d0268000                 st      %o0, [%i2]
F00B0414: f0027ffc                 ld      [%o1-4], %i0
F00B0418: 90100018                 mov     %i0, %o0
F00B041C: 7ffffa92                 call    _prom_devicetype
F00B0420: 92100019                 mov     %i1, %o1
F00B0424: 80a22000                 cmp     %o0, 0
F00B0428: 1280000b                 bne     locret_F00B0454
F00B042C: 01000000                 nop
F00B0430: 7ffffc12                 call    _prom_nextnode
F00B0434: 90100018                 mov     %i0, %o0
F00B0438: 10800003                 ba      loc_F00B0444
F00B043C: b0100008                 mov     %o0, %i0
F00B0440: a0102001                 mov     1, %l0
F00B0444: 80a42000                 cmp     %l0, 0
F00B0448: 02bfffeb                 be      loc_F00B03F4
F00B044C: 80a63fff                 cmp     %i0, -1
F00B0450: b0102000                 mov     0, %i0
F00B0454: 81c7e008                 ret
F00B0458: 81e80000                 restore

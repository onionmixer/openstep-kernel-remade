F00F0B90: c402201c                 ld      [%o0+0x1C], %g2
F00F0B94: 80a0a000                 cmp     %g2, 0
F00F0B98: 02800007                 be      locret_F00F0BB4
F00F0B9C: 86102000                 mov     0, %g3
F00F0BA0: 86100002                 mov     %g2, %g3
F00F0BA4: c400c000                 ld      [%g3], %g2
F00F0BA8: 80a0a000                 cmp     %g2, 0
F00F0BAC: 32bffffe                 bne,a   loc_F00F0BA4
F00F0BB0: 86100002                 mov     %g2, %g3
F00F0BB4: 81c3e008                 retl
F00F0BB8: 90100003                 mov     %g3, %o0

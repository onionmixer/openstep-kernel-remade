F0032DE8: 9de3bf98                 save    %sp, -0x68, %sp
F0032DEC: 90100018                 mov     %i0, %o0
F0032DF0: f00a2001                 ldub    [%o0+1], %i0
F0032DF4: 80a620a3                 cmp     %i0, 0xA3
F0032DF8: 0880000b                 bleu    loc_F0032E24
F0032DFC: f2064000                 ld      [%i1], %i1
F0032E00: 113c0432                 sethi   %hi(_ipprintfs), %o0
F0032E04: d0022028                 ld      [%o0+%lo(_ipprintfs)], %o0
F0032E08: 80a22000                 cmp     %o0, 0
F0032E0C: 02800013                 be      locret_F0032E58
F0032E10: 113c0431                 sethi   %hi(aSaveRteOlenD), %o0! "save_rte: olen %d\n"
F0032E14: 901223f8                 bset    %lo(aSaveRteOlenD), %o0! "save_rte: olen %d\n"
F0032E18: 7fff8610                 call    _printf
F0032E1C: 92100018                 mov     %i0, %o1
F0032E20: 3080000e                 ba,a    locret_F0032E58
F0032E24: 213c04bda0142045         set     unk_F012F445, %l0
F0032E2C: 92100010                 mov     %l0, %o1! void *
F0032E30: 40018738                 call    _bcopy
F0032E34: 94100018                 mov     %i0, %o2
F0032E38: 90063ffd                 add     %i0, -3, %o0
F0032E3C: 91322002                 srl     %o0, 2, %o0
F0032E40: 153c0431                 sethi   %hi(_ip_nhops), %o2
F0032E44: 92022001                 add     %o0, 1, %o1
F0032E48: d222a3cc                 st      %o1, [%o2+%lo(_ip_nhops)]
F0032E4C: a0042003                 inc     3, %l0
F0032E50: 912a2002                 sll     %o0, 2, %o0
F0032E54: f2220010                 st      %i1, [%o0+%l0]
F0032E58: 81c7e008                 ret
F0032E5C: 81e80000                 restore

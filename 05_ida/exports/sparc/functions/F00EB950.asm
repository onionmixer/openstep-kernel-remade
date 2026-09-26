F00EB950: 9de3bf90                 save    %sp, -0x70, %sp
F00EB954: f0060000                 ld      [%i0], %i0
F00EB958: 80a62000                 cmp     %i0, 0
F00EB95C: 2280000e                 be,a    locret_F00EB994
F00EB960: b0102000                 mov     0, %i0
F00EB964: 9010001a                 mov     %i2, %o0! __s1
F00EB968: 7ffc7211                 call    _strcmp
F00EB96C: d2062008                 ld      [%i0+8], %o1
F00EB970: 80a22000                 cmp     %o0, 0
F00EB974: 32800004                 bne,a   loc_F00EB984
F00EB978: f0062004                 ld      [%i0+4], %i0
F00EB97C: 10800006                 ba      locret_F00EB994
F00EB980: b0102001                 mov     1, %i0
F00EB984: 80a62000                 cmp     %i0, 0
F00EB988: 12bffff8                 bne     loc_F00EB968
F00EB98C: 9010001a                 mov     %i2, %o0
F00EB990: b0102000                 mov     0, %i0
F00EB994: 81c7e008                 ret
F00EB998: 81e80000                 restore

F00EB8F4: 9c03bf90                 inc     -0x70, %sp
F00EB8F8: d0020000                 ld      [%o0], %o0
F00EB8FC: 80a22000                 cmp     %o0, 0
F00EB900: 2280000b                 be,a    locret_F00EB92C
F00EB904: 90102000                 mov     0, %o0
F00EB908: 80a2000a                 cmp     %o0, %o2
F00EB90C: 32800004                 bne,a   loc_F00EB91C
F00EB910: d0022004                 ld      [%o0+4], %o0
F00EB914: 10800006                 ba      locret_F00EB92C
F00EB918: 90102001                 mov     1, %o0
F00EB91C: 80a22000                 cmp     %o0, 0
F00EB920: 12bffffb                 bne     loc_F00EB90C
F00EB924: 80a2000a                 cmp     %o0, %o2
F00EB928: 90102000                 mov     0, %o0
F00EB92C: 81c3e008                 retl
F00EB930: 9c23bf90                 dec     -0x70, %sp

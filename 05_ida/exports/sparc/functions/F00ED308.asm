F00ED308: 9de3bf98                 save    %sp, -0x68, %sp
F00ED30C: e0064000                 ld      [%i1], %l0
F00ED310: 80a42001                 cmp     %l0, 1
F00ED314: 32800009                 bne,a   loc_F00ED338
F00ED318: e2066004                 ld      [%i1+4], %l1
F00ED31C: 9010001a                 mov     %i2, %o0
F00ED320: 9fc60000                 call    %i0
F00ED324: d2066004                 ld      [%i1+4], %o1
F00ED328: 3080000a                 ba,a    locret_F00ED350
F00ED32C: 9fc60000                 call    %i0
F00ED330: d2044000                 ld      [%l1], %o1
F00ED334: a2046004                 inc     4, %l1
F00ED338: a0043fff                 inc     -1, %l0
F00ED33C: 80a43fff                 cmp     %l0, -1
F00ED340: 12bffffb                 bne     loc_F00ED32C
F00ED344: 9010001a                 mov     %i2, %o0! void *
F00ED348: 7ffdebee                 call    _free
F00ED34C: d0066004                 ld      [%i1+4], %o0
F00ED350: 81c7e008                 ret
F00ED354: 81e80000                 restore

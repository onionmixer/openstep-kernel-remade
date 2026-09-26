F002BAE8: 9de3bf98                 save    %sp, -0x68, %sp
F002BAEC: 9410001a                 mov     %i2, %o2! size_t
F002BAF0: d2562008                 ldsh    [%i0+8], %o1
F002BAF4: 9006400a                 add     %i1, %o2, %o0
F002BAF8: 80a20009                 cmp     %o0, %o1
F002BAFC: 18800008                 bgu     loc_F002BB1C
F002BB00: 9210001b                 mov     %i3, %o1! void *
F002BB04: d0062004                 ld      [%i0+4], %o0
F002BB08: 90060008                 add     %i0, %o0, %o0! void *
F002BB0C: 4001a401                 call    _bcopy
F002BB10: 90020019                 add     %o0, %i1, %o0
F002BB14: 10800003                 ba      locret_F002BB20
F002BB18: b0102000                 mov     0, %i0
F002BB1C: b0103fff                 mov     -1, %i0
F002BB20: 81c7e008                 ret
F002BB24: 81e80000                 restore

F002BB28: 9de3bf98                 save    %sp, -0x68, %sp
F002BB2C: 9410001a                 mov     %i2, %o2! size_t
F002BB30: d2562008                 ldsh    [%i0+8], %o1
F002BB34: 9006400a                 add     %i1, %o2, %o0
F002BB38: 80a20009                 cmp     %o0, %o1
F002BB3C: 18800008                 bgu     loc_F002BB5C
F002BB40: 9010001b                 mov     %i3, %o0! void *
F002BB44: d2062004                 ld      [%i0+4], %o1
F002BB48: 92060009                 add     %i0, %o1, %o1! void *
F002BB4C: 4001a3f1                 call    _bcopy
F002BB50: 92024019                 add     %o1, %i1, %o1
F002BB54: 10800003                 ba      locret_F002BB60
F002BB58: b0102000                 mov     0, %i0
F002BB5C: b0103fff                 mov     -1, %i0
F002BB60: 81c7e008                 ret
F002BB64: 81e80000                 restore

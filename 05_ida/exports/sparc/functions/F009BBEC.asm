F009BBEC: 9de3bf98                 save    %sp, -0x68, %sp
F009BBF0: d0068000                 ld      [%i2], %o0
F009BBF4: 80a22012                 cmp     %o0, 0x12
F009BBF8: 0880000a                 bleu    loc_F009BC20
F009BBFC: 90100019                 mov     %i1, %o0! __dst
F009BC00: d2062028                 ld      [%i0+0x28], %o1! __src
F009BC04: 9410204c                 mov     0x4C, %o2 ! 'L'! __n
F009BC08: 7ffdada6                 call    _memcpy
F009BC0C: 92026234                 inc     0x234, %o1
F009BC10: 90102013                 mov     0x13, %o0
F009BC14: d0268000                 st      %o0, [%i2]
F009BC18: 10800003                 ba      locret_F009BC24
F009BC1C: b0102000                 mov     0, %i0
F009BC20: b0102004                 mov     4, %i0
F009BC24: 81c7e008                 ret
F009BC28: 81e80000                 restore

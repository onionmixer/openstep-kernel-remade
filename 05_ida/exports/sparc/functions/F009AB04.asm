F009AB04: 9de3bf98                 save    %sp, -0x68, %sp
F009AB08: 7ffff0be                 call    _getpsr
F009AB0C: 01000000                 nop
F009AB10: 91322018                 srl     %o0, 24, %o0
F009AB14: 901a2004                 btog    4, %o0
F009AB18: 80a00008                 cmp     %g0, %o0
F009AB1C: b0603fff                 subc    %g0, -1, %i0
F009AB20: 81c7e008                 ret
F009AB24: 81e80000                 restore

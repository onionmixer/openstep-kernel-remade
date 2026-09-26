F00F0B24: 9de3bf98                 save    %sp, -0x68, %sp
F00F0B28: 90964000                 orcc    %i1, %g0, %o0! void *
F00F0B2C: 02800004                 be      locret_F00F0B3C
F00F0B30: 01000000                 nop
F00F0B34: 7ffdddf3                 call    _free
F00F0B38: 01000000                 nop
F00F0B3C: 81c7e008                 ret
F00F0B40: 81e80000                 restore

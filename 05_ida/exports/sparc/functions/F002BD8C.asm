F002BD8C: 9de3bf98                 save    %sp, -0x68, %sp
F002BD90: 90100018                 mov     %i0, %o0
F002BD94: d2022030                 ld      [%o0+0x30], %o1
F002BD98: 80a26000                 cmp     %o1, 0
F002BD9C: 02800005                 be      locret_F002BDB0
F002BDA0: b0102006                 mov     6, %i0
F002BDA4: 9fc24000                 call    %o1
F002BDA8: 01000000                 nop
F002BDAC: b0100008                 mov     %o0, %i0
F002BDB0: 81c7e008                 ret
F002BDB4: 81e80000                 restore

F002945C: 9de3bf98                 save    %sp, -0x68, %sp
F0029460: c6062028                 ld      [%i0+0x28], %g3
F0029464: 8400fffd                 add     %g3, -3, %g2
F0029468: 80a0a001                 cmp     %g2, 1
F002946C: 08800008                 bleu    locret_F002948C
F0029470: b2102000                 mov     0, %i1
F0029474: 80a0e008                 cmp     %g3, 8
F0029478: 02800005                 be      locret_F002948C
F002947C: 01000000                 nop
F0029480: c4062024                 ld      [%i0+0x24], %g2
F0029484: c400a00c                 ld      [%g2+0xC], %g2
F0029488: b208a001                 and     %g2, 1, %i1
F002948C: 81c7e008                 ret
F0029490: 91e80019                 restore %g0, %i1, %o0

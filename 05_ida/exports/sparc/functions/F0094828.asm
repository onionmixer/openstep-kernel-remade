F0094828: 9de3bf98                 save    %sp, -0x68, %sp
F009482C: 4000a3de                 call    _kmtrygetc
F0094830: 01000000                 nop
F0094834: b0100008                 mov     %o0, %i0
F0094838: 80a63fff                 cmp     %i0, -1
F009483C: 02bffffc                 be      loc_F009482C
F0094840: 80a62015                 cmp     %i0, 0x15
F0094844: 22800010                 be,a    loc_F0094884
F0094848: 90102000                 mov     0, %o0
F009484C: 14800006                 bg      loc_F0094864
F0094850: 80a6207f                 cmp     %i0, 0x7F
F0094854: 80a6200d                 cmp     %i0, 0xD
F0094858: 02800007                 be      loc_F0094874
F009485C: 90102000                 mov     0, %o0
F0094860: 30800008                 ba,a    loc_F0094880
F0094864: 22800007                 be,a    loc_F0094880
F0094868: b0102008                 mov     8, %i0
F009486C: 10800006                 ba      loc_F0094884
F0094870: 90102000                 mov     0, %o0
F0094874: 40009cff                 call    _kmputc
F0094878: 9210200d                 mov     0xD, %o1
F009487C: b010200a                 mov     0xA, %i0
F0094880: 90102000                 mov     0, %o0
F0094884: 40009cfb                 call    _kmputc
F0094888: 92100018                 mov     %i0, %o1
F009488C: 81c7e008                 ret
F0094890: 81e80000                 restore

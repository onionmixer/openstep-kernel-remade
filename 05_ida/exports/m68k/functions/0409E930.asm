0409E930: 2f07                     move.l  d7,-(sp)
0409E932: ede870000004             bfffo   4(a0){0:32},d7
0409E938: 67ff0000002e             beq.l   loc_409E968
0409E93E: 2f06                     move.l  d6,-(sp)
0409E940: 9f680000                 sub.w   d7,0(a0)
0409E944: 20280004                 move.l  4(a0),d0
0409E948: 22280008                 move.l  8(a0),d1
0409E94C: efa8                     lsl.l   d7,d0
0409E94E: 2c01                     move.l  d1,d6
0409E950: efae                     lsl.l   d7,d6
0409E952: 21460008                 move.l  d6,8(a0)
0409E956: 7c20                     moveq   #$20,d6 ; ' '
0409E958: 9c87                     sub.l   d7,d6
0409E95A: eca9                     lsr.l   d6,d1
0409E95C: 8081                     or.l    d1,d0
0409E95E: 21400004                 move.l  d0,4(a0)
0409E962: 4cdf00c0                 movem.l (sp)+,d6-d7
0409E966: 4e75                     rts
0409E968: 30280000                 move.w  0(a0),d0
0409E96C: 22280008                 move.l  8(a0),d1
0409E970: 04400020                 subi.w  #$20,d0 ; ' '
0409E974: edc17000                 bfffo   d1{0:32},d7
0409E978: 9047                     sub.w   d7,d0
0409E97A: efa9                     lsl.l   d7,d1
0409E97C: 31400000                 move.w  d0,0(a0)
0409E980: 21410004                 move.l  d1,4(a0)
0409E984: 42a80008                 clr.l   8(a0)
0409E988: 2e1f                     move.l  (sp)+,d7
0409E98A: 4e75                     rts

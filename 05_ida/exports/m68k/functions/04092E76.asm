04092E76: 4e560000                 link    a6,#0
04092E7A: 7000                     moveq   #0,d0
04092E7C: 222e0008                 move.l  arg_0(a6),d1
04092E80: 6724                     beq.s   loc_4092EA6
04092E82: 4a41                     tst.w   d1
04092E84: 6608                     bne.s   loc_4092E8E
04092E86: 4841                     swap    d1
04092E88: 068000000010             addi.l  #$10,d0
04092E8E: 4a01                     tst.b   d1
04092E90: 6604                     bne.s   loc_4092E96
04092E92: e089                     lsr.l   #8,d1
04092E94: 5080                     addq.l  #8,d0
04092E96: 0281000000ff             andi.l  #$FF,d1
04092E9C: 41f904092eaa             lea     (word_4092EAA).l,a0
04092EA2: d1c1                     adda.l  d1,a0
04092EA4: d010                     add.b   (a0),d0
04092EA6: 4e5e                     unlk    a6
04092EA8: 4e75                     rts

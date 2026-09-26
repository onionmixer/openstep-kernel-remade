0401EBEC: 4856                     pea     (a6)
0401EBEE: 2c4f                     movea.l sp,a6
0401EBF0: 48e73020                 movem.l d2-d3/a2,-(sp)
0401EBF4: 226e0008                 movea.l 8(a6),a1
0401EBF8: 41f9040b345e             lea     (unk_40B345E).l,a0
0401EBFE: 4282                     clr.l   d2
0401EC00: 4281                     clr.l   d1
0401EC02: 45f9040ae944             lea     (a0123456789abcd_1).l,a2; "0123456789abcdef"
0401EC08: 1011                     move.b  (a1),d0
0401EC0A: e808                     lsr.b   #4,d0
0401EC0C: 1200                     move.b  d0,d1
0401EC0E: 10f21800                 move.b  (a2,d1.l),(a0)+
0401EC12: 1019                     move.b  (a1)+,d0
0401EC14: 0200000f                 andi.b  #$F,d0
0401EC18: 760f                     moveq   #$F,d3
0401EC1A: c083                     and.l   d3,d0
0401EC1C: 10f20800                 move.b  (a2,d0.l),(a0)+
0401EC20: 10fc003a                 move.b  #$3A,(a0)+ ; ':'
0401EC24: 5282                     addq.l  #1,d2
0401EC26: 7605                     moveq   #5,d3
0401EC28: b682                     cmp.l   d2,d3
0401EC2A: 6cdc                     bge.s   loc_401EC08
0401EC2C: 4228ffff                 clr.b   -1(a0)
0401EC30: 203c040b345e             move.l  #$40B345E,d0
0401EC36: 4cee040cfff4             movem.l -$C(a6),d2-d3/a2
0401EC3C: 4e5e                     unlk    a6
0401EC3E: 4e75                     rts

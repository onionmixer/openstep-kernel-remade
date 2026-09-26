04013DB6: 4856                     pea     (a6)
04013DB8: 2c4f                     movea.l sp,a6
04013DBA: 2f0b                     move.l  a3,-(sp)
04013DBC: 2f0a                     move.l  a2,-(sp)
04013DBE: 246e0008                 movea.l 8(a6),a2
04013DC2: 302a0006                 move.w  6(a2),d0
04013DC6: 0240fffb                 andi.w  #$FFFB,d0
04013DCA: 00400038                 ori.w   #$38,d0 ; '8'
04013DCE: 35400006                 move.w  d0,6(a2)
04013DD2: 486a004e                 pea     $4E(a2)
04013DD6: 61ffffff642a             bsr.l   _wakeup
04013DDC: 486a0038                 pea     $38(a2)
04013DE0: 2f0a                     move.l  a2,-(sp)
04013DE2: 47f9040140d4             lea     (_sowakeup).l,a3
04013DE8: 4e93                     jsr     (a3)
04013DEA: 486a0022                 pea     $22(a2)
04013DEE: 2f0a                     move.l  a2,-(sp)
04013DF0: 4e93                     jsr     (a3)
04013DF2: 246efff8                 movea.l -8(a6),a2
04013DF6: 266efffc                 movea.l -4(a6),a3
04013DFA: 4e5e                     unlk    a6
04013DFC: 4e75                     rts

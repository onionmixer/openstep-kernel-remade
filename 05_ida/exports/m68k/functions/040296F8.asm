040296F8: 4856                     pea     (a6)
040296FA: 2c4f                     movea.l sp,a6
040296FC: 202e0008                 move.l  8(a6),d0
04029700: 52b9040bbfac             addq.l  #1,(_rlock_awaken_count).l
04029706: 4a80                     tst.l   d0
04029708: 6708                     beq.s   loc_4029712
0402970A: 2f00                     move.l  d0,-(sp)
0402970C: 61fffffe0af4             bsr.l   _wakeup
04029712: 4e5e                     unlk    a6
04029714: 4e75                     rts

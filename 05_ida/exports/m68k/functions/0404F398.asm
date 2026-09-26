0404F398: 4856                     pea     (a6)
0404F39A: 2c4f                     movea.l sp,a6
0404F39C: 7004                     moveq   #4,d0
0404F39E: 4aae0008                 tst.l   8(a6)
0404F3A2: 6702                     beq.s   loc_404F3A6
0404F3A4: 7005                     moveq   #5,d0
0404F3A6: 4e5e                     unlk    a6
0404F3A8: 4e75                     rts

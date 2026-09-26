0404F3AA: 4856                     pea     (a6)
0404F3AC: 2c4f                     movea.l sp,a6
0404F3AE: 7004                     moveq   #4,d0
0404F3B0: 4aae0008                 tst.l   8(a6)
0404F3B4: 6702                     beq.s   loc_404F3B8
0404F3B6: 7005                     moveq   #5,d0
0404F3B8: 4e5e                     unlk    a6
0404F3BA: 4e75                     rts

0404F386: 4856                     pea     (a6)
0404F388: 2c4f                     movea.l sp,a6
0404F38A: 7004                     moveq   #4,d0
0404F38C: 4aae0008                 tst.l   8(a6)
0404F390: 6702                     beq.s   loc_404F394
0404F392: 7005                     moveq   #5,d0
0404F394: 4e5e                     unlk    a6
0404F396: 4e75                     rts

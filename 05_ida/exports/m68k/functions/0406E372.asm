0406E372: 4856                     pea     (a6)
0406E374: 2c4f                     movea.l sp,a6
0406E376: 2f0b                     move.l  a3,-(sp)
0406E378: 2f0a                     move.l  a2,-(sp)
0406E37A: 266e0008                 movea.l 8(a6),a3
0406E37E: 206e000c                 movea.l $C(a6),a0
0406E382: 43f08c00                 lea     (a0,a0.l*4),a1
0406E386: 45f9040c36fc             lea     (_fd_drive).l,a2
0406E38C: 43f29e00                 lea     (a2,a1.l*8),a1
0406E390: 27480004                 move.l  a0,4(a3)
0406E394: 27690014000c             move.l  $14(a1),$C(a3)
0406E39A: 234b000c                 move.l  a3,$C(a1)
0406E39E: 70ef                     moveq   #$FFFFFFEF,d0
0406E3A0: c1ab0124                 and.l   d0,$124(a3)
0406E3A4: 246efff8                 movea.l -8(a6),a2
0406E3A8: 266efffc                 movea.l -4(a6),a3
0406E3AC: 4e5e                     unlk    a6
0406E3AE: 4e75                     rts

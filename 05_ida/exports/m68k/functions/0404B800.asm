0404B800: 4856                     pea     (a6)
0404B802: 2c4f                     movea.l sp,a6
0404B804: 206e0008                 movea.l 8(a6),a0
0404B808: 4a88                     tst.l   a0
0404B80A: 6706                     beq.s   loc_404B812
0404B80C: 4aa80030                 tst.l   $30(a0)
0404B810: 6604                     bne.s   loc_404B816
0404B812: 4280                     clr.l   d0
0404B814: 6004                     bra.s   loc_404B81A
0404B816: 7038                     moveq   #$38,d0 ; '8'
0404B818: d088                     add.l   a0,d0
0404B81A: 4e5e                     unlk    a6
0404B81C: 4e75                     rts

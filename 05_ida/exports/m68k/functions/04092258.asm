04092258: 4856                     pea     (a6)
0409225A: 2c4f                     movea.l sp,a6
0409225C: 203c040ad8ea             move.l  #$40AD8EA,d0
04092262: 4aae0008                 tst.l   8(a6)
04092266: 6702                     beq.s   loc_409226A
04092268: 4280                     clr.l   d0
0409226A: 4e5e                     unlk    a6
0409226C: 4e75                     rts

0401D29A: 4856                     pea     (a6)
0401D29C: 2c4f                     movea.l sp,a6
0401D29E: 226e0008                 movea.l 8(a6),a1
0401D2A2: 0269fffd004c             andi.w  #$FFFD,$4C(a1)
0401D2A8: 20690008                 movea.l 8(a1),a0
0401D2AC: 082800000007             btst    #0,7(a0)
0401D2B2: 6708                     beq.s   loc_401D2BC
0401D2B4: 2f09                     move.l  a1,-(sp)
0401D2B6: 61ffffffff58             bsr.l   _raw_detach
0401D2BC: 4e5e                     unlk    a6
0401D2BE: 4e75                     rts

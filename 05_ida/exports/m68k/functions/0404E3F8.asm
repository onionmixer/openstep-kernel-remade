0404E3F8: 4856                     pea     (a6)
0404E3FA: 2c4f                     movea.l sp,a6
0404E3FC: 2f02                     move.l  d2,-(sp)
0404E3FE: 40c2                     move    sr,d2
0404E400: 46fc2600                 move    #$2600,sr
0404E404: 48c2                     ext.l   d2
0404E406: 48790404e458             pea     (sub_404E458).l
0404E40C: 42a7                     clr.l   -(sp)
0404E40E: 61ff00043e6e             bsr.l   __set_timer_expire_func
0404E414: 40c0                     move    sr,d0
0404E416: 46c2                     move    d2,sr
0404E418: 242efffc                 move.l  -4(a6),d2
0404E41C: 4e5e                     unlk    a6
0404E41E: 4e75                     rts

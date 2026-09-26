04075660: 4856                     pea     (a6)
04075662: 2c4f                     movea.l sp,a6
04075664: 2f02                     move.l  d2,-(sp)
04075666: 222e0008                 move.l  8(a6),d1
0407566A: 40c2                     move    sr,d2
0407566C: 2039040c3e98             move.l  (_od_spl).l,d0
04075672: 46c0                     move    d0,sr
04075674: 48c2                     ext.l   d2
04075676: 33fc0002040c3e84         move.w  #2,(_od_runout).l
0407567E: 2f01                     move.l  d1,-(sp)
04075680: 61ff00000010             bsr.l   _od_ctrl_start
04075686: 40c0                     move    sr,d0
04075688: 46c2                     move    d2,sr
0407568A: 242efffc                 move.l  -4(a6),d2
0407568E: 4e5e                     unlk    a6
04075690: 4e75                     rts

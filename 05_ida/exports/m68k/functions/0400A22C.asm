0400A22C: 4856                     pea     (a6)
0400A22E: 2c4f                     movea.l sp,a6
0400A230: 2f02                     move.l  d2,-(sp)
0400A232: 202e0008                 move.l  8(a6),d0
0400A236: 40c2                     move    sr,d2
0400A238: 46fc2700                 move    #$2700,sr
0400A23C: 48c2                     ext.l   d2
0400A23E: 42a7                     clr.l   -(sp)
0400A240: 48780001                 pea     (1).w
0400A244: 2f00                     move.l  d0,-(sp)
0400A246: 61ff00046708             bsr.l   _thread_wakeup_prim
0400A24C: 40c0                     move    sr,d0
0400A24E: 46c2                     move    d2,sr
0400A250: 242efffc                 move.l  -4(a6),d2
0400A254: 4e5e                     unlk    a6
0400A256: 4e75                     rts

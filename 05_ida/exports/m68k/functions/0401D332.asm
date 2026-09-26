0401D332: 4856                     pea     (a6)
0401D334: 2c4f                     movea.l sp,a6
0401D336: 2f0a                     move.l  a2,-(sp)
0401D338: 246e0008                 movea.l 8(a6),a2
0401D33C: 206e000c                 movea.l $C(a6),a0
0401D340: 48780010                 pea     ($10).w
0401D344: 486a000c                 pea     $C(a2)
0401D348: d1e80004                 adda.l  4(a0),a0
0401D34C: 2f08                     move.l  a0,-(sp)
0401D34E: 61ff000759dc             bsr.l   _bcopy
0401D354: 006a0002004c             ori.w   #2,$4C(a2)
0401D35A: 246efffc                 movea.l -4(a6),a2
0401D35E: 4e5e                     unlk    a6
0401D360: 4e75                     rts

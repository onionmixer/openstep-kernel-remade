0405448E: 4856                     pea     (a6)
04054490: 2c4f                     movea.l sp,a6
04054492: 2f03                     move.l  d3,-(sp)
04054494: 2f02                     move.l  d2,-(sp)
04054496: 206e0008                 movea.l 8(a6),a0
0405449A: 2408                     move.l  a0,d2
0405449C: 40c0                     move    sr,d0
0405449E: 46fc2300                 move    #$2300,sr
040544A2: 3600                     move.w  d0,d3
040544A4: 48c3                     ext.l   d3
040544A6: 4aa8001c                 tst.l   $1C(a0)
040544AA: 670e                     beq.s   loc_40544BA
040544AC: 4879040a90c5             pea     (aCalloutentryfr).l; "calloutEntryFree"
040544B2: 61fffffb77b2             bsr.l   _panic
040544B8: 584f                     addq.w  #4,sp
040544BA: 40c0                     move    sr,d0
040544BC: 46c3                     move    d3,sr
040544BE: 48780020                 pea     ($20).w
040544C2: 2f02                     move.l  d2,-(sp)
040544C4: 61ffffff5dfe             bsr.l   _kfree
040544CA: 242efff8                 move.l  -8(a6),d2
040544CE: 262efffc                 move.l  -4(a6),d3
040544D2: 4e5e                     unlk    a6
040544D4: 4e75                     rts

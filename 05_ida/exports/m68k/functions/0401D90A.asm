0401D90A: 4856                     pea     (a6)
0401D90C: 2c4f                     movea.l sp,a6
0401D90E: 2f0a                     move.l  a2,-(sp)
0401D910: 2f02                     move.l  d2,-(sp)
0401D912: 246e0008                 movea.l 8(a6),a2
0401D916: 4a8a                     tst.l   a2
0401D918: 660e                     bne.s   loc_401D928
0401D91A: 4879040a676e             pea     (aRtfree).l; "rtfree"
0401D920: 61fffffee344             bsr.l   _panic
0401D926: 584f                     addq.w  #4,sp
0401D928: 536a0026                 subq.w  #1,$26(a2)
0401D92C: e8ea01d10025             bftst   $25(a2){7:17}
0401D932: 6614                     bne.s   loc_401D948
0401D934: 53b9040b6e44             subq.l  #1,(_rttrash).l
0401D93A: 220a                     move.l  a2,d1
0401D93C: 7480                     moveq   #$FFFFFF80,d2
0401D93E: c282                     and.l   d2,d1
0401D940: 2f01                     move.l  d1,-(sp)
0401D942: 61ffffff471e             bsr.l   _m_free
0401D948: 242efff8                 move.l  -8(a6),d2
0401D94C: 246efffc                 movea.l -4(a6),a2
0401D950: 4e5e                     unlk    a6
0401D952: 4e75                     rts

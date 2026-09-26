04051374: 4856                     pea     (a6)
04051376: 2c4f                     movea.l sp,a6
04051378: 2f0a                     move.l  a2,-(sp)
0405137A: 246e0008                 movea.l 8(a6),a2
0405137E: 226a0008                 movea.l 8(a2),a1
04051382: 4a89                     tst.l   a1
04051384: 6716                     beq.s   loc_405139C
04051386: 2052                     movea.l (a2),a0
04051388: 216a00040004             move.l  4(a2),4(a0)
0405138E: 206a0004                 movea.l 4(a2),a0
04051392: 2092                     move.l  (a2),(a0)
04051394: 53a90104                 subq.l  #1,$104(a1)
04051398: 42aa0008                 clr.l   8(a2)
0405139C: 2009                     move.l  a1,d0
0405139E: 246efffc                 movea.l -4(a6),a2
040513A2: 4e5e                     unlk    a6
040513A4: 4e75                     rts

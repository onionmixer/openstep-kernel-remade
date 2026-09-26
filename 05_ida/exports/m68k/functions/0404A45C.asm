0404A45C: 4856                     pea     (a6)
0404A45E: 2c4f                     movea.l sp,a6
0404A460: 2f0a                     move.l  a2,-(sp)
0404A462: 246e0008                 movea.l 8(a6),a2
0404A466: 42aa0008                 clr.l   8(a2)
0404A46A: 41f9040b3716             lea     (dword_40B3716).l,a0
0404A470: 2250                     movea.l (a0),a1
0404A472: 228a                     move.l  a2,(a1)
0404A474: 25490004                 move.l  a1,4(a2)
0404A478: 24bc040b3712             move.l  #$40B3712,(a2)
0404A47E: 23ca040b3716             move.l  a2,(dword_40B3716).l
0404A484: 52b9040af7d4             addq.l  #1,(dword_40AF7D4).l
0404A48A: 52b9040c2330             addq.l  #1,(dword_40C2330).l
0404A490: 246efffc                 movea.l -4(a6),a2
0404A494: 4e5e                     unlk    a6
0404A496: 4e75                     rts

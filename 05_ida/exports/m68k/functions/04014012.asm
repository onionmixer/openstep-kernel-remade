04014012: 4856                     pea     (a6)
04014014: 2c4f                     movea.l sp,a6
04014016: 2f0a                     move.l  a2,-(sp)
04014018: 246e0008                 movea.l 8(a6),a2
0401401C: 486a0010                 pea     $10(a2)
04014020: 61ffffff87e8             bsr.l   _selthreadcache
04014026: 4a80                     tst.l   d0
04014028: 6706                     beq.s   loc_4014030
0401402A: 006a00100014             ori.w   #$10,$14(a2)
04014030: 246efffc                 movea.l -4(a6),a2
04014034: 4e5e                     unlk    a6
04014036: 4e75                     rts

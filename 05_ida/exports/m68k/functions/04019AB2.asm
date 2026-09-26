04019AB2: 4856                     pea     (a6)
04019AB4: 2c4f                     movea.l sp,a6
04019AB6: 2f0a                     move.l  a2,-(sp)
04019AB8: 246e0008                 movea.l 8(a6),a2
04019ABC: 48780400                 pea     ($400).w
04019AC0: 61ff0003073e             bsr.l   _kalloc
04019AC6: 2480                     move.l  d0,(a2)
04019AC8: 25400004                 move.l  d0,4(a2)
04019ACC: 42aa0008                 clr.l   8(a2)
04019AD0: 246efffc                 movea.l -4(a6),a2
04019AD4: 4e5e                     unlk    a6
04019AD6: 4e75                     rts

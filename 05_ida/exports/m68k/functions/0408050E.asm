0408050E: 4856                     pea     (a6)
04080510: 2c4f                     movea.l sp,a6
04080512: 203c00000100             move.l  #$100,d0
04080518: 4aae0008                 tst.l   8(a6)
0408051C: 6606                     bne.s   loc_4080524
0408051E: 2039040b06d0             move.l  (_page_size).l,d0
04080524: 4e5e                     unlk    a6
04080526: 4e75                     rts

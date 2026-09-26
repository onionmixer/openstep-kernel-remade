0406386E: 4856                     pea     (a6)
04063870: 2c4f                     movea.l sp,a6
04063872: 4a39040b4e80             tst.b   (byte_40B4E80).l
04063878: 660c                     bne.s   loc_4063886
0406387A: 13fc0001040b4e80         move.b  #1,(byte_40B4E80).l
04063882: 4280                     clr.l   d0
04063884: 6002                     bra.s   loc_4063888
04063886: 7010                     moveq   #$10,d0
04063888: 4e5e                     unlk    a6
0406388A: 4e75                     rts

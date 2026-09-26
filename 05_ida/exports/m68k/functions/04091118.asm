04091118: 4856                     pea     (a6)
0409111A: 2c4f                     movea.l sp,a6
0409111C: 4ab9040c9478             tst.l   (_new_clock_chip).l
04091122: 671a                     beq.s   loc_409113E
04091124: 4280                     clr.l   d0
04091126: 4aae0008                 tst.l   8(a6)
0409112A: 6702                     beq.s   loc_409112E
0409112C: 70ff                     moveq   #$FFFFFFFF,d0
0409112E: 2f00                     move.l  d0,-(sp)
04091130: 48780020                 pea     ($20).w
04091134: 48780031                 pea     ($31).w
04091138: 61ffffffff9c             bsr.l   _rtc_set_clr
0409113E: 4e5e                     unlk    a6
04091140: 4e75                     rts

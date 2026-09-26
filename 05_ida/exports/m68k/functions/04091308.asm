04091308: 4856                     pea     (a6)
0409130A: 2c4f                     movea.l sp,a6
0409130C: 40c0                     move    sr,d0
0409130E: 46fc2600                 move    #$2600,sr
04091312: 4ab9040c9478             tst.l   (_new_clock_chip).l
04091318: 6714                     beq.s   loc_409132E
0409131A: 61ffffffffa2             bsr.l   _rtc_tick
04091320: 2f3c000cf850             move.l  #$CF850,-(sp)
04091326: 61ff00001052             bsr.l   _delay
0409132C: 584f                     addq.w  #4,sp
0409132E: 48780030                 pea     ($30).w
04091332: 61ff00000812             bsr.l   _rtc_read
04091338: 584f                     addq.w  #4,sp
0409133A: 7232                     moveq   #$32,d1 ; '2'
0409133C: 4a00                     tst.b   d0
0409133E: 6c02                     bge.s   loc_4091342
04091340: 7231                     moveq   #$31,d1 ; '1'
04091342: 4878ffff                 pea     ($FFFFFFFF).w
04091346: 48780040                 pea     ($40).w
0409134A: 2f01                     move.l  d1,-(sp)
0409134C: 61fffffffd88             bsr.l   _rtc_set_clr
04091352: 60fe                     bra.s   loc_4091352

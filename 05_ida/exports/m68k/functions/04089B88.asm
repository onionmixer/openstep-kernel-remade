04089B88: 4856                     pea     (a6)
04089B8A: 2c4f                     movea.l sp,a6
04089B8C: 2079040b69bc             movea.l (_mon_global).l,a0
04089B92: 022800f70004             andi.b  #$F7,4(a0)
04089B98: 4ab9040b2286             tst.l   (dword_40B2286).l
04089B9E: 6706                     beq.s   loc_4089BA6
04089BA0: 61ff0000004e             bsr.l   _vidResumeAnimation
04089BA6: 2f3c000186a0             move.l  #$186A0,-(sp)
04089BAC: 61ff000087cc             bsr.l   _delay
04089BB2: 4e5e                     unlk    a6
04089BB4: 4e75                     rts

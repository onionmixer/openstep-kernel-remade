04017AA6: 4856                     pea     (a6)
04017AA8: 2c4f                     movea.l sp,a6
04017AAA: 226e0008                 movea.l 8(a6),a1
04017AAE: 082900010002             btst    #1,2(a1)
04017AB4: 660a                     bne.s   loc_4017AC0
04017AB6: 2079040b57d0             movea.l (_active_u).l,a0
04017ABC: 52a80196                 addq.l  #1,$196(a0)
04017AC0: 006902020002             ori.w   #$202,2(a1)
04017AC6: 2f09                     move.l  a1,-(sp)
04017AC8: 61ff00000022             bsr.l   _brelse
04017ACE: 4e5e                     unlk    a6
04017AD0: 4e75                     rts

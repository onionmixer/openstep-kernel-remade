04089CE8: 4856                     pea     (a6)
04089CEA: 2c4f                     movea.l sp,a6
04089CEC: 2f02                     move.l  d2,-(sp)
04089CEE: 74ff                     moveq   #$FFFFFFFF,d2
04089CF0: b4b9040b2282             cmp.l   (dword_40B2282).l,d2
04089CF6: 6718                     beq.s   loc_4089D10
04089CF8: 40c0                     move    sr,d0
04089CFA: 46fc2700                 move    #$2700,sr
04089CFE: 48c0                     ext.l   d0
04089D00: 42b9040b2286             clr.l   (dword_40B2286).l
04089D06: 42b9040b5188             clr.l   (dword_40B5188).l
04089D0C: 40c1                     move    sr,d1
04089D0E: 46c0                     move    d0,sr
04089D10: 242efffc                 move.l  -4(a6),d2
04089D14: 4e5e                     unlk    a6
04089D16: 4e75                     rts

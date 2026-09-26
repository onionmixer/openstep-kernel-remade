04089786: 4856                     pea     (a6)
04089788: 2c4f                     movea.l sp,a6
0408978A: 72ff                     moveq   #$FFFFFFFF,d1
0408978C: b2b9040b2282             cmp.l   (dword_40B2282).l,d1
04089792: 6610                     bne.s   loc_40897A4
04089794: 61ff00000316             bsr.l   _vidProbeForFB
0408979A: 72ff                     moveq   #$FFFFFFFF,d1
0408979C: b280                     cmp.l   d0,d1
0408979E: 6604                     bne.s   loc_40897A4
040897A0: 7013                     moveq   #$13,d0
040897A2: 6002                     bra.s   loc_40897A6
040897A4: 4280                     clr.l   d0
040897A6: 4e5e                     unlk    a6
040897A8: 4e75                     rts

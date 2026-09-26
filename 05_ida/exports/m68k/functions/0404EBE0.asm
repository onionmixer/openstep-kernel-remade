0404EBE0: 4856                     pea     (a6)
0404EBE2: 2c4f                     movea.l sp,a6
0404EBE4: 4ab9040af944             tst.l   (dword_40AF944).l
0404EBEA: 6622                     bne.s   loc_404EC0E
0404EBEC: 61ff0004209c             bsr.l   _PMConnect
0404EBF2: 4a80                     tst.l   d0
0404EBF4: 660a                     bne.s   loc_404EC00
0404EBF6: 42a7                     clr.l   -(sp)
0404EBF8: 42a7                     clr.l   -(sp)
0404EBFA: 61ffffffff94             bsr.l   _power_callout
0404EC00: 42b9040b39c2             clr.l   (dword_40B39C2).l
0404EC06: 7201                     moveq   #1,d1
0404EC08: 23c1040af944             move.l  d1,(dword_40AF944).l
0404EC0E: 4e5e                     unlk    a6
0404EC10: 4e75                     rts

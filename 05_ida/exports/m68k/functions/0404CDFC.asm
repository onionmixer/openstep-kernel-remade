0404CDFC: 4856                     pea     (a6)
0404CDFE: 2c4f                     movea.l sp,a6
0404CE00: 206e000c                 movea.l $C(a6),a0
0404CE04: 20f9040c22c8             move.l  (_machine_info).l,(a0)+
0404CE0A: 20f9040c22cc             move.l  (dword_40C22CC).l,(a0)+
0404CE10: 20f9040c22d0             move.l  (dword_40C22D0).l,(a0)+
0404CE16: 20f9040c22d4             move.l  (dword_40C22D4).l,(a0)+
0404CE1C: 20b9040c22d8             move.l  (dword_40C22D8).l,(a0)
0404CE22: 4280                     clr.l   d0
0404CE24: 4e5e                     unlk    a6
0404CE26: 4e75                     rts

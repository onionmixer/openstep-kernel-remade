0402B1BE: 4856                     pea     (a6)
0402B1C0: 2c4f                     movea.l sp,a6
0402B1C2: 48e73800                 movem.l d2-d4,-(sp)
0402B1C6: 242e0008                 move.l  8(a6),d2
0402B1CA: 282e000c                 move.l  $C(a6),d4
0402B1CE: 262e0010                 move.l  $10(a6),d3
0402B1D2: 2f02                     move.l  d2,-(sp)
0402B1D4: 61ff000012fc             bsr.l   _sync_vp
0402B1DA: 42a7                     clr.l   -(sp)
0402B1DC: 2f03                     move.l  d3,-(sp)
0402B1DE: 2f04                     move.l  d4,-(sp)
0402B1E0: 2f02                     move.l  d2,-(sp)
0402B1E2: 61ffffffb2d4             bsr.l   _nfsgetattr
0402B1E8: 4cee001cfff4             movem.l -$C(a6),d2-d4
0402B1EE: 4e5e                     unlk    a6
0402B1F0: 4e75                     rts

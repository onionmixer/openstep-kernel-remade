0400B384: 4856                     pea     (a6)
0400B386: 2c4f                     movea.l sp,a6
0400B388: 2f02                     move.l  d2,-(sp)
0400B38A: 2079040b57d0             movea.l (_active_u).l,a0
0400B390: 2428015e                 move.l  $15E(a0),d2
0400B394: 6722                     beq.s   loc_400B3B8
0400B396: 48780001                 pea     (1).w
0400B39A: 2f02                     move.l  d2,-(sp)
0400B39C: 61ff00003c4a             bsr.l   _ttycheckoutq
0400B3A2: 2f02                     move.l  d2,-(sp)
0400B3A4: 48780002                 pea     (2).w
0400B3A8: 486e000c                 pea     $C(a6)
0400B3AC: 2f2e0008                 move.l  8(a6),-(sp)
0400B3B0: 61ff0000019e             bsr.l   _prf
0400B3B6: 4280                     clr.l   d0
0400B3B8: 242efffc                 move.l  -4(a6),d2
0400B3BC: 4e5e                     unlk    a6
0400B3BE: 4e75                     rts

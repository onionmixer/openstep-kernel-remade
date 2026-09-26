0401EC7C: 4856                     pea     (a6)
0401EC7E: 2c4f                     movea.l sp,a6
0401EC80: 48e72030                 movem.l d2/a2-a3,-(sp)
0401EC84: 206e0008                 movea.l 8(a6),a0
0401EC88: 266e000c                 movea.l $C(a6),a3
0401EC8C: 2f280004                 move.l  4(a0),-(sp)
0401EC90: 45f90401ed18             lea     (_in_netof).l,a2
0401EC96: 4e92                     jsr     (a2)
0401EC98: 2400                     move.l  d0,d2
0401EC9A: 2f2b0004                 move.l  4(a3),-(sp)
0401EC9E: 4e92                     jsr     (a2)
0401ECA0: b082                     cmp.l   d2,d0
0401ECA2: 57c0                     seq     d0
0401ECA4: 49c0                     extb.l  d0
0401ECA6: 4480                     neg.l   d0
0401ECA8: 4cee0c04fff4             movem.l -$C(a6),d2/a2-a3
0401ECAE: 4e5e                     unlk    a6
0401ECB0: 4e75                     rts

0401CD94: 4856                     pea     (a6)
0401CD96: 2c4f                     movea.l sp,a6
0401CD98: 206e0008                 movea.l 8(a6),a0
0401CD9C: 20bc040acfd6             move.l  #$40ACFD6,(a0)
0401CDA2: 217c040acfd60004         move.l  #$40ACFD6,4(a0)
0401CDAA: 42680008                 clr.w   8(a0)
0401CDAE: 4268000a                 clr.w   $A(a0)
0401CDB2: 4268000c                 clr.w   $C(a0)
0401CDB6: 42a80026                 clr.l   $26(a0)
0401CDBA: 217c0401cd80002e         move.l  #$401CD80,$2E(a0)
0401CDC2: 217c0401cd800032         move.l  #$401CD80,$32(a0)
0401CDCA: 217c0401cd800036         move.l  #$401CD80,$36(a0)
0401CDD2: 217c0401cd80003a         move.l  #$401CD80,$3A(a0)
0401CDDA: 217c0401cd8a003e         move.l  #$401CD8A,$3E(a0)
0401CDE2: 42a80056                 clr.l   $56(a0)
0401CDE6: 4e5e                     unlk    a6
0401CDE8: 4e75                     rts

040066AA: 4856                     pea     (a6)
040066AC: 2c4f                     movea.l sp,a6
040066AE: 206e0008                 movea.l 8(a6),a0
040066B2: 20680080                 movea.l $80(a0),a0
040066B6: 43e80004                 lea     4(a0),a1
040066BA: 21490024                 move.l  a1,$24(a0)
040066BE: 4e5e                     unlk    a6
040066C0: 4e75                     rts

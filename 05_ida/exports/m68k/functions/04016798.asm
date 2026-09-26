04016798: 4856                     pea     (a6)
0401679A: 2c4f                     movea.l sp,a6
0401679C: 206e0008                 movea.l 8(a6),a0
040167A0: 53680010                 subq.w  #1,$10(a0)
040167A4: 53b9040b6a84             subq.l  #1,(_unp_rights).l
040167AA: 2f08                     move.l  a0,-(sp)
040167AC: 61fffffede72             bsr.l   _closef
040167B2: 4e5e                     unlk    a6
040167B4: 4e75                     rts

040066C2: 4856                     pea     (a6)
040066C4: 2c4f                     movea.l sp,a6
040066C6: 206e0008                 movea.l 8(a6),a0
040066CA: 4878014e                 pea     ($14E).w
040066CE: 2f280080                 move.l  $80(a0),-(sp)
040066D2: 61ff0008c73e             bsr.l   _bzero
040066D8: 4e5e                     unlk    a6
040066DA: 4e75                     rts

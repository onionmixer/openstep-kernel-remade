0402DBD2: 4856                     pea     (a6)
0402DBD4: 2c4f                     movea.l sp,a6
0402DBD6: 206e0008                 movea.l 8(a6),a0
0402DBDA: 20680008                 movea.l 8(a0),a0
0402DBDE: 4aae000c                 tst.l   $C(a6)
0402DBE2: 6706                     beq.s   loc_402DBEA
0402DBE4: 7020                     moveq   #$20,d0 ; ' '
0402DBE6: 8190                     or.l    d0,(a0)
0402DBE8: 6004                     bra.s   loc_402DBEE
0402DBEA: 70df                     moveq   #$FFFFFFDF,d0
0402DBEC: c190                     and.l   d0,(a0)
0402DBEE: 4e5e                     unlk    a6
0402DBF0: 4e75                     rts

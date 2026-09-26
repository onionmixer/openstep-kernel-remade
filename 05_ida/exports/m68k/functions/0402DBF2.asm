0402DBF2: 4856                     pea     (a6)
0402DBF4: 2c4f                     movea.l sp,a6
0402DBF6: 206e0008                 movea.l 8(a6),a0
0402DBFA: 20680008                 movea.l 8(a0),a0
0402DBFE: 4aae000c                 tst.l   $C(a6)
0402DC02: 6708                     beq.s   loc_402DC0C
0402DC04: 006808000002             ori.w   #$800,2(a0)
0402DC0A: 6006                     bra.s   loc_402DC12
0402DC0C: 0268f7ff0002             andi.w  #$F7FF,2(a0)
0402DC12: 4e5e                     unlk    a6
0402DC14: 4e75                     rts

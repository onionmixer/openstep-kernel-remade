040569AE: 4856                     pea     (a6)
040569B0: 2c4f                     movea.l sp,a6
040569B2: 2f02                     move.l  d2,-(sp)
040569B4: 206e0008                 movea.l 8(a6),a0
040569B8: 222e000c                 move.l  $C(a6),d1
040569BC: 2050                     movea.l (a0),a0
040569BE: 4a88                     tst.l   a0
040569C0: 6728                     beq.s   loc_40569EA
040569C2: b2a804b0                 cmp.l   $4B0(a0),d1
040569C6: 6604                     bne.s   loc_40569CC
040569C8: 42a804b0                 clr.l   $4B0(a0)
040569CC: 4280                     clr.l   d0
040569CE: b2a8018c                 cmp.l   $18C(a0),d1
040569D2: 660a                     bne.s   loc_40569DE
040569D4: 42a8018c                 clr.l   $18C(a0)
040569D8: 42a80190                 clr.l   $190(a0)
040569DC: 600c                     bra.s   loc_40569EA
040569DE: 5048                     addq.w  #8,a0
040569E0: 5048                     addq.w  #8,a0
040569E2: 5280                     addq.l  #1,d0
040569E4: 7431                     moveq   #$31,d2 ; '1'
040569E6: b480                     cmp.l   d0,d2
040569E8: 6ce4                     bge.s   loc_40569CE
040569EA: 242efffc                 move.l  -4(a6),d2
040569EE: 4e5e                     unlk    a6
040569F0: 4e75                     rts

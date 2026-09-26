0407A470: 4856                     pea     (a6)
0407A472: 2c4f                     movea.l sp,a6
0407A474: 2f0a                     move.l  a2,-(sp)
0407A476: 48781c48                 pea     ($1C48).w
0407A47A: 4879040c3e5c             pea     (_od_label).l
0407A480: 2f39040b5dbc             move.l  (_kernel_map).l,-(sp)
0407A486: 45f90405d6cc             lea     (_kmem_alloc_wired).l,a2
0407A48C: 4e92                     jsr     (a2)
0407A48E: 504f                     addq.w  #8,sp
0407A490: 584f                     addq.w  #4,sp
0407A492: 4a80                     tst.l   d0
0407A494: 670e                     beq.s   loc_407A4A4
0407A496: 4879040ab25c             pea     (aOdLabelAlloc).l; "od: label alloc"
0407A49C: 61fffff917c8             bsr.l   _panic
0407A4A2: 584f                     addq.w  #4,sp
0407A4A4: 48783000                 pea     ($3000).w
0407A4A8: 4879040c3b7c             pea     (_od_bad_block).l
0407A4AE: 2f39040b5dbc             move.l  (_kernel_map).l,-(sp)
0407A4B4: 4e92                     jsr     (a2)
0407A4B6: 504f                     addq.w  #8,sp
0407A4B8: 584f                     addq.w  #4,sp
0407A4BA: 4a80                     tst.l   d0
0407A4BC: 670e                     beq.s   loc_407A4CC
0407A4BE: 4879040ab26c             pea     (aOdBadBlockAllo).l; "od: bad_block alloc"
0407A4C4: 61fffff917a0             bsr.l   _panic
0407A4CA: 584f                     addq.w  #4,sp
0407A4CC: 2f3c00010000             move.l  #$10000,-(sp)
0407A4D2: 4879040c3b80             pea     (_od_bitmap).l
0407A4D8: 2f39040b5dbc             move.l  (_kernel_map).l,-(sp)
0407A4DE: 4e92                     jsr     (a2)
0407A4E0: 504f                     addq.w  #8,sp
0407A4E2: 584f                     addq.w  #4,sp
0407A4E4: 4a80                     tst.l   d0
0407A4E6: 670c                     beq.s   loc_407A4F4
0407A4E8: 4879040ab280             pea     (aOdBitmapAlloc).l; "od: bitmap alloc"
0407A4EE: 61fffff91776             bsr.l   _panic
0407A4F4: 246efffc                 movea.l -4(a6),a2
0407A4F8: 4e5e                     unlk    a6
0407A4FA: 4e75                     rts

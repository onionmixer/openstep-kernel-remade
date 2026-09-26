04004620: 4856                     pea     (a6)
04004622: 2c4f                     movea.l sp,a6
04004624: 2f0a                     move.l  a2,-(sp)
04004626: 246e0008                 movea.l 8(a6),a2
0400462A: 4a8a                     tst.l   a2
0400462C: 6766                     beq.s   loc_4004694
0400462E: 302a000e                 move.w  $E(a2),d0
04004632: 0c400001                 cmpi.w  #1,d0
04004636: 6f08                     ble.s   loc_4004640
04004638: 5340                     subq.w  #1,d0
0400463A: 3540000e                 move.w  d0,$E(a2)
0400463E: 6054                     bra.s   loc_4004694
04004640: 0c400001                 cmpi.w  #1,d0
04004644: 670e                     beq.s   loc_4004654
04004646: 4879040a5df1             pea     (aFpNotOne).l; "fp not one\n"
0400464C: 61ff00007618             bsr.l   _panic
04004652: 584f                     addq.w  #4,sp
04004654: 206a0012                 movea.l $12(a2),a0
04004658: 4a88                     tst.l   a0
0400465A: 670a                     beq.s   loc_4004666
0400465C: 2f0a                     move.l  a2,-(sp)
0400465E: 2068000c                 movea.l $C(a0),a0
04004662: 4e90                     jsr     (a0)
04004664: 584f                     addq.w  #4,sp
04004666: 2f2a001e                 move.l  $1E(a2),-(sp)
0400466A: 61ff000035da             bsr.l   _crfree
04004670: 584f                     addq.w  #4,sp
04004672: 0c6a0001000e             cmpi.w  #1,$E(a2)
04004678: 670e                     beq.s   loc_4004688
0400467A: 4879040a5dfd             pea     (aFpNotOne2).l; "fp not one2\n"
04004680: 61ff000075e4             bsr.l   _panic
04004686: 584f                     addq.w  #4,sp
04004688: 426a000e                 clr.w   $E(a2)
0400468C: 2f0a                     move.l  a2,-(sp)
0400468E: 61ff0000000c             bsr.l   _free_file
04004694: 246efffc                 movea.l -4(a6),a2
04004698: 4e5e                     unlk    a6
0400469A: 4e75                     rts

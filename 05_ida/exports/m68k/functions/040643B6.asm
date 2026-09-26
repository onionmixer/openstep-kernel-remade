040643B6: 4856                     pea     (a6)
040643B8: 2c4f                     movea.l sp,a6
040643BA: 42b9040b0858             clr.l   (dword_40B0858).l
040643C0: 2039040b0834             move.l  (dword_40B0834).l,d0
040643C6: efc10404                 bfins   d0,d1{16:4}
040643CA: 00410c00                 ori.w   #$C00,d1
040643CE: 42a7                     clr.l   -(sp)
040643D0: 42a7                     clr.l   -(sp)
040643D2: 42a7                     clr.l   -(sp)
040643D4: 0241fcff                 andi.w  #$FCFF,d1
040643D8: 3f01                     move.w  d1,-(sp)
040643DA: 554f                     subq.w  #2,sp
040643DC: 61ff0000020c             bsr.l   sub_40645EA
040643E2: 4e5e                     unlk    a6
040643E4: 4e75                     rts

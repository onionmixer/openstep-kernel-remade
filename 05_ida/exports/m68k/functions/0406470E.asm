0406470E: 4856                     pea     (a6)
04064710: 2c4f                     movea.l sp,a6
04064712: 2f02                     move.l  d2,-(sp)
04064714: 202e0008                 move.l  8(a6),d0
04064718: 222e000c                 move.l  $C(a6),d1
0406471C: efc20404                 bfins   d0,d2{16:4}
04064720: 7002                     moveq   #2,d0
04064722: efc20502                 bfins   d0,d2{20:2}
04064726: efc21582                 bfins   d1,d2{22:2}
0406472A: 48780001                 pea     (1).w
0406472E: 2f2e0014                 move.l  $14(a6),-(sp)
04064732: 2f2e0010                 move.l  $10(a6),-(sp)
04064736: 3f02                     move.w  d2,-(sp)
04064738: 554f                     subq.w  #2,sp
0406473A: 61fffffffeae             bsr.l   sub_40645EA
04064740: 242efffc                 move.l  -4(a6),d2
04064744: 4e5e                     unlk    a6
04064746: 4e75                     rts

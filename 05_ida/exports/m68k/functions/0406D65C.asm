0406D65C: 4856                     pea     (a6)
0406D65E: 2c4f                     movea.l sp,a6
0406D660: 2f02                     move.l  d2,-(sp)
0406D662: 206e0008                 movea.l 8(a6),a0
0406D666: 242e000c                 move.l  $C(a6),d2
0406D66A: 40c1                     move    sr,d1
0406D66C: 46fc2300                 move    #$2300,sr
0406D670: 48c1                     ext.l   d1
0406D672: 20280018                 move.l  $18(a0),d0
0406D676: 8082                     or.l    d2,d0
0406D678: 21400018                 move.l  d0,$18(a0)
0406D67C: 40c0                     move    sr,d0
0406D67E: 46c1                     move    d1,sr
0406D680: 242efffc                 move.l  -4(a6),d2
0406D684: 4e5e                     unlk    a6
0406D686: 4e75                     rts

04080038: 4856                     pea     (a6)
0408003A: 2c4f                     movea.l sp,a6
0408003C: 2f02                     move.l  d2,-(sp)
0408003E: 2039040c36f4             move.l  (_gpflags).l,d0
04080044: e9c01701                 bfextu  d0{28:1},d1
04080048: 2039040c36f4             move.l  (_gpflags).l,d0
0408004E: 08000004                 btst    #4,d0
04080052: 6604                     bne.s   loc_4080058
04080054: 7402                     moveq   #2,d2
04080056: 8282                     or.l    d2,d1
04080058: 2001                     move.l  d1,d0
0408005A: 242efffc                 move.l  -4(a6),d2
0408005E: 4e5e                     unlk    a6
04080060: 4e75                     rts

0402FF8C: 4e56fffc                 link    a6,#-4
0402FF90: 2f0a                     move.l  a2,-(sp)
0402FF92: 246e000c                 movea.l arg_4(a6),a2
0402FF96: 1212                     move.b  (a2),d1
0402FF98: 49c1                     extb.l  d1
0402FF9A: 2d41fffc                 move.l  d1,var_4(a6)
0402FF9E: 486efffc                 pea     var_4(a6)
0402FFA2: 2f2e0008                 move.l  arg_0(a6),-(sp)
0402FFA6: 61fffffffe38             bsr.l   _xdr_int
0402FFAC: 4a80                     tst.l   d0
0402FFAE: 6708                     beq.s   loc_402FFB8
0402FFB0: 14aeffff                 move.b  var_4+3(a6),(a2)
0402FFB4: 7001                     moveq   #1,d0
0402FFB6: 6002                     bra.s   loc_402FFBA
0402FFB8: 4280                     clr.l   d0
0402FFBA: 246efff8                 movea.l var_8(a6),a2
0402FFBE: 4e5e                     unlk    a6
0402FFC0: 4e75                     rts

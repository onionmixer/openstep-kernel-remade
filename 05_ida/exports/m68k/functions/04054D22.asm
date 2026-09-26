04054D22: 4e56fff8                 link    a6,#-8
04054D26: 206e0008                 movea.l arg_0(a6),a0
04054D2A: 226e000c                 movea.l arg_4(a6),a1
04054D2E: 2d680004fffc             move.l  4(a0),var_4(a6)
04054D34: 2d50fff8                 move.l  (a0),var_8(a6)
04054D38: 222efffc                 move.l  var_4(a6),d1
04054D3C: b2a80008                 cmp.l   8(a0),d1
04054D40: 66ec                     bne.s   loc_4054D2E
04054D42: 2001                     move.l  d1,d0
04054D44: 90a90004                 sub.l   4(a1),d0
04054D48: 4c3c0800000f4240         muls.l  #$F4240,d0
04054D50: d0aefff8                 add.l   var_8(a6),d0
04054D54: 9091                     sub.l   (a1),d0
04054D56: 23410004                 move.l  d1,4(a1)
04054D5A: 22aefff8                 move.l  var_8(a6),(a1)
04054D5E: 4e5e                     unlk    a6
04054D60: 4e75                     rts

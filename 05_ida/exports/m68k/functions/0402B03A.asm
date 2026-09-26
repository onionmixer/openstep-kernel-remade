0402B03A: 4e56ffe0                 link    a6,#-$20
0402B03E: 2f02                     move.l  d2,-(sp)
0402B040: 48780020                 pea     ($20).w
0402B044: 486effe0                 pea     var_20(a6)
0402B048: 2f2e0008                 move.l  arg_0(a6),-(sp)
0402B04C: 61ff00067cde             bsr.l   _bcopy
0402B052: 4282                     clr.l   d2
0402B054: 504f                     addq.w  #8,sp
0402B056: 584f                     addq.w  #4,sp
0402B058: 2f362ce0                 move.l  var_20(a6,d2.l*4),-(sp)
0402B05C: 4879040a70f7             pea     (aX).l; "%x "
0402B062: 61fffffe02f4             bsr.l   _printf
0402B068: 504f                     addq.w  #8,sp
0402B06A: 5282                     addq.l  #1,d2
0402B06C: 7207                     moveq   #7,d1
0402B06E: b282                     cmp.l   d2,d1
0402B070: 64e6                     bcc.s   loc_402B058
0402B072: 242effdc                 move.l  var_24(a6),d2
0402B076: 4e5e                     unlk    a6
0402B078: 4e75                     rts

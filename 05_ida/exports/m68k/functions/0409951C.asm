0409951C: 4856                     pea     (a6)
0409951E: 2c4f                     movea.l sp,a6
04099520: 2f02                     move.l  d2,-(sp)
04099522: 202e0008                 move.l  8(a6),d0
04099526: 242e000c                 move.l  $C(a6),d2
0409952A: 08390000040b606f         btst    #0,(byte_40B606F).l
04099532: 671a                     beq.s   loc_409954E
04099534: 2f00                     move.l  d0,-(sp)
04099536: 2f00                     move.l  d0,-(sp)
04099538: 4879040aca59             pea     (aSKeyS).l; "%s key [%s]: "
0409953E: 61fffff71e18             bsr.l   _printf
04099544: 2f02                     move.l  d2,-(sp)
04099546: 2f02                     move.l  d2,-(sp)
04099548: 61ffffffff2c             bsr.l   _gets
0409954E: 242efffc                 move.l  -4(a6),d2
04099552: 4e5e                     unlk    a6
04099554: 4e75                     rts

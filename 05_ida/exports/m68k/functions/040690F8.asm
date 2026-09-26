040690F8: 4856                     pea     (a6)
040690FA: 2c4f                     movea.l sp,a6
040690FC: 2f03                     move.l  d3,-(sp)
040690FE: 2f02                     move.l  d2,-(sp)
04069100: 262e0008                 move.l  8(a6),d3
04069104: 6c02                     bge.s   loc_4069108
04069106: 4283                     clr.l   d3
04069108: 723d                     moveq   #$3D,d1 ; '='
0406910A: b283                     cmp.l   d3,d1
0406910C: 6c02                     bge.s   loc_4069110
0406910E: 763d                     moveq   #$3D,d3 ; '='
04069110: 4ab9040c3628             tst.l   (_evOpenCalled).l
04069116: 6728                     beq.s   loc_4069140
04069118: 3439040c36ca             move.w  (_screens+2).l,d2
0406911E: 5342                     subq.w  #1,d2
04069120: 0c42ffff                 cmpi.w  #$FFFF,d2
04069124: 6722                     beq.s   loc_4069148
04069126: 2f03                     move.l  d3,-(sp)
04069128: 3042                     movea.w d2,a0
0406912A: 2f08                     move.l  a0,-(sp)
0406912C: 48780004                 pea     (4).w
04069130: 61ff00001738             bsr.l   _evdispatch
04069136: 504f                     addq.w  #8,sp
04069138: 584f                     addq.w  #4,sp
0406913A: 51caffea                 dbf     d2,loc_4069126
0406913E: 6008                     bra.s   loc_4069148
04069140: 2f03                     move.l  d3,-(sp)
04069142: 61ff00020ae4             bsr.l   _vidSetBrightness
04069148: 2003                     move.l  d3,d0
0406914A: 242efff8                 move.l  -8(a6),d2
0406914E: 262efffc                 move.l  -4(a6),d3
04069152: 4e5e                     unlk    a6
04069154: 4e75                     rts

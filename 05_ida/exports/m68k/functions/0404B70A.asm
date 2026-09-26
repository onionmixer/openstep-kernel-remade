0404B70A: 4856                     pea     (a6)
0404B70C: 2c4f                     movea.l sp,a6
0404B70E: 2f02                     move.l  d2,-(sp)
0404B710: 242e0008                 move.l  8(a6),d2
0404B714: 2f02                     move.l  d2,-(sp)
0404B716: 487904000000             pea     (dword_4000000).l
0404B71C: 61ff0000001c             bsr.l   _nextsegfromheader
0404B722: 4a80                     tst.l   d0
0404B724: 660c                     bne.s   loc_404B732
0404B726: 2239040c2344             move.l  (_fvm_seg).l,d1
0404B72C: b282                     cmp.l   d2,d1
0404B72E: 6702                     beq.s   loc_404B732
0404B730: 2001                     move.l  d1,d0
0404B732: 242efffc                 move.l  -4(a6),d2
0404B736: 4e5e                     unlk    a6
0404B738: 4e75                     rts

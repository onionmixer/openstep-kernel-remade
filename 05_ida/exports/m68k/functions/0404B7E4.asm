0404B7E4: 4856                     pea     (a6)
0404B7E6: 2c4f                     movea.l sp,a6
0404B7E8: 2f2e000c                 move.l  $C(a6),-(sp)
0404B7EC: 2f2e0008                 move.l  8(a6),-(sp)
0404B7F0: 487904000000             pea     (dword_4000000).l
0404B7F6: 61fffffffdcc             bsr.l   _getsectbynamefromheader
0404B7FC: 4e5e                     unlk    a6
0404B7FE: 4e75                     rts

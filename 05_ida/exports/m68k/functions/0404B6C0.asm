0404B6C0: 4856                     pea     (a6)
0404B6C2: 2c4f                     movea.l sp,a6
0404B6C4: 487904000000             pea     (dword_4000000).l
0404B6CA: 61ff00000008             bsr.l   _firstsegfromheader
0404B6D0: 4e5e                     unlk    a6
0404B6D2: 4e75                     rts

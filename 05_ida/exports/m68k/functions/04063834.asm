04063834: 4856                     pea     (a6)
04063836: 2c4f                     movea.l sp,a6
04063838: 4879040a9af8             pea     (aVnodePagerStru).l; "vnode pager structures"
0406383E: 42a7                     clr.l   -(sp)
04063840: 2f39040b06d0             move.l  (_page_size).l,-(sp)
04063846: 2f3c0003a980             move.l  #$3A980,-(sp)
0406384C: 48780018                 pea     ($18).w
04063850: 61ffffff1790             bsr.l   _zinit
04063856: 23c0040c32cc             move.l  d0,(_vstruct_zone).l
0406385C: 41f9040b4df4             lea     (dword_40B4DF4).l,a0
04063862: 23c8040b4df8             move.l  a0,(dword_40B4DF8).l
04063868: 2088                     move.l  a0,(a0)
0406386A: 4e5e                     unlk    a6
0406386C: 4e75                     rts

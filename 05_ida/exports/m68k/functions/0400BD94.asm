0400BD94: 4856                     pea     (a6)
0400BD96: 2c4f                     movea.l sp,a6
0400BD98: 42a7                     clr.l   -(sp)
0400BD9A: 48780004                 pea     (4).w
0400BD9E: 2f2e0008                 move.l  8(a6),-(sp)
0400BDA2: 61ff00000008             bsr.l   sub_400BDAC
0400BDA8: 4e5e                     unlk    a6
0400BDAA: 4e75                     rts

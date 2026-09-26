04006164: 4856                     pea     (a6)
04006166: 2c4f                     movea.l sp,a6
04006168: 42a7                     clr.l   -(sp)
0400616A: 61ff0000001a             bsr.l   _fork1
04006170: 4e5e                     unlk    a6
04006172: 4e75                     rts

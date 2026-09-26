0400A1DA: 4856                     pea     (a6)
0400A1DC: 2c4f                     movea.l sp,a6
0400A1DE: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400A1E4: 4228006a                 clr.b   $6A(a0)
0400A1E8: 2239040b57d0             move.l  (_active_u).l,d1
0400A1EE: 5081                     addq.l  #8,d1
0400A1F0: 2f01                     move.l  d1,-(sp)
0400A1F2: 4879040a610a             pea     (aSContinuing).l; "[%s: ... continuing]\r\n"
0400A1F8: 61ff0000118a             bsr.l   _uprintf
0400A1FE: 4e5e                     unlk    a6
0400A200: 4e75                     rts

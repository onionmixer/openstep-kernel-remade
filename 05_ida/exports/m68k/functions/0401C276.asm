0401C276: 4856                     pea     (a6)
0401C278: 2c4f                     movea.l sp,a6
0401C27A: 42a7                     clr.l   -(sp)
0401C27C: 48781000                 pea     ($1000).w
0401C280: 48780808                 pea     ($808).w
0401C284: 48780600                 pea     ($600).w
0401C288: 4879040acf46             pea     (aInternetProtoc).l; "Internet Protocol"
0401C28E: 42a7                     clr.l   -(sp)
0401C290: 4879040a671f             pea     (aLo).l; "lo"
0401C296: 48790401c1fa             pea     (_locontrol).l
0401C29C: 48790401c186             pea     (_logetbuf).l
0401C2A2: 48790401c198             pea     (_looutput).l
0401C2A8: 42a7                     clr.l   -(sp)
0401C2AA: 42a7                     clr.l   -(sp)
0401C2AC: 61ff00000b3c             bsr.l   _if_attach
0401C2B2: 23c0040b6dd8             move.l  d0,(_loifp).l
0401C2B8: 4e5e                     unlk    a6
0401C2BA: 4e75                     rts

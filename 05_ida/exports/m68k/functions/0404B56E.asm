0404B56E: 4856                     pea     (a6)
0404B570: 2c4f                     movea.l sp,a6
0404B572: 48780008                 pea     (8).w
0404B576: 61ffffffedac             bsr.l   _malloc
0404B57C: 2040                     movea.l d0,a0
0404B57E: 20bc04000000             move.l  #$4000000,(a0)
0404B584: 42a80004                 clr.l   4(a0)
0404B588: 4e5e                     unlk    a6
0404B58A: 4e75                     rts

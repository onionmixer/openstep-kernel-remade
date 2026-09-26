0408A330: 4856                     pea     (a6)
0408A332: 2c4f                     movea.l sp,a6
0408A334: 202e0008                 move.l  8(a6),d0
0408A338: 41f9040b2380             lea     (unk_40B2380).l,a0
0408A33E: 2279040b6120             movea.l (_brightness).l,a1
0408A344: 10300800                 move.b  (a0,d0.l),d0
0408A348: 00000040                 ori.b   #$40,d0 ; '@'
0408A34C: 1280                     move.b  d0,(a1)
0408A34E: 4e5e                     unlk    a6
0408A350: 4e75                     rts

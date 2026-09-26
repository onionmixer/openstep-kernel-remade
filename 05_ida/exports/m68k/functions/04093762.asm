04093762: 4856                     pea     (a6)
04093764: 2c4f                     movea.l sp,a6
04093766: 2f0a                     move.l  a2,-(sp)
04093768: 2f02                     move.l  d2,-(sp)
0409376A: 242e0008                 move.l  8(a6),d2
0409376E: 42a7                     clr.l   -(sp)
04093770: 45f904064792             lea     (_adb_watchdog).l,a2
04093776: 4e92                     jsr     (a2)
04093778: 23c2040b564c             move.l  d2,(_boot_action).l
0409377E: 4e4d                     trap    #$D
04093780: 48780001                 pea     (1).w
04093784: 4e92                     jsr     (a2)
04093786: 242efff8                 move.l  -8(a6),d2
0409378A: 246efffc                 movea.l -4(a6),a2
0409378E: 4e5e                     unlk    a6
04093790: 4e75                     rts

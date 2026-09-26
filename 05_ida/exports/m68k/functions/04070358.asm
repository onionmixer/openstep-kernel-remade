04070358: 4856                     pea     (a6)
0407035A: 2c4f                     movea.l sp,a6
0407035C: 4ab9040c36d4             tst.l   (_sound_active).l
04070362: 6612                     bne.s   loc_4070376
04070364: 2f3c01fffff1             move.l  #$1FFFFF1,-(sp)
0407036A: 487800c6                 pea     ($C6).w
0407036E: 61ff00002134             bsr.l   _mon_send
04070374: 504f                     addq.w  #8,sp
04070376: 2079040af7e4             movea.l (_hz).l,a0
0407037C: 48708a00                 pea     (a0,a0.l*2)
04070380: 42a7                     clr.l   -(sp)
04070382: 487904070358             pea     (_reconpoll).l
04070388: 61fffff93256             bsr.l   _timeout
0407038E: 4e5e                     unlk    a6
04070390: 4e75                     rts

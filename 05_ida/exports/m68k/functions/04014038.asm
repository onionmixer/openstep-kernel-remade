04014038: 4856                     pea     (a6)
0401403A: 2c4f                     movea.l sp,a6
0401403C: 206e0008                 movea.l 8(a6),a0
04014040: 006800040014             ori.w   #4,$14(a0)
04014046: 4878001a                 pea     ($1A).w
0401404A: 2f08                     move.l  a0,-(sp)
0401404C: 61ffffff5be8             bsr.l   _sleep
04014052: 4e5e                     unlk    a6
04014054: 4e75                     rts

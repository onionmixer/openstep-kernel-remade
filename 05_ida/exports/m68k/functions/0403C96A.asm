0403C96A: 4856                     pea     (a6)
0403C96C: 2c4f                     movea.l sp,a6
0403C96E: 206e0008                 movea.l 8(a6),a0
0403C972: 222e000c                 move.l  $C(a6),d1
0403C976: 226e0014                 movea.l $14(a6),a1
0403C97A: 52a80038                 addq.l  #1,$38(a0)
0403C97E: 2008                     move.l  a0,d0
0403C980: e888                     lsr.l   #4,d0
0403C982: ec89                     lsr.l   #6,d1
0403C984: d081                     add.l   d1,d0
0403C986: c0b9040c21c0             and.l   (_ipc_hash_global_mask).l,d0
0403C98C: 2079040c21c8             movea.l (_ipc_hash_global_table).l,a0
0403C992: 41f00c00                 lea     (a0,d0.l*4),a0
0403C996: 2350000c                 move.l  (a0),$C(a1)
0403C99A: 2089                     move.l  a1,(a0)
0403C99C: 4e5e                     unlk    a6
0403C99E: 4e75                     rts

04072752: 4e56fffc                 link    a6,#-4
04072756: 2f0a                     move.l  a2,-(sp)
04072758: 42aefffc                 clr.l   var_4(a6)
0407275C: 2f2e0008                 move.l  arg_0(a6),-(sp)
04072760: 45eefffc                 lea     var_4(a6),a2
04072764: 2f0a                     move.l  a2,-(sp)
04072766: 48790405188e             pea     (_thread_wakeup).l
0407276C: 61fffff90e72             bsr.l   _timeout
04072772: 42a7                     clr.l   -(sp)
04072774: 2f0a                     move.l  a2,-(sp)
04072776: 61fffffde00c             bsr.l   _assert_wait
0407277C: 61fffffdf138             bsr.l   _thread_block
04072782: 246efff8                 movea.l var_8(a6),a2
04072786: 4e5e                     unlk    a6
04072788: 4e75                     rts

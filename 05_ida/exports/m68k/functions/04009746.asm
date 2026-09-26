04009746: 4856                     pea     (a6)
04009748: 2c4f                     movea.l sp,a6
0400974A: 2f0a                     move.l  a2,-(sp)
0400974C: 246e0008                 movea.l 8(a6),a2
04009750: 2f2a0066                 move.l  $66(a2),-(sp)
04009754: 61ff00048f1c             bsr.l   _task_suspend_nowait
0400975A: 157c00060013             move.b  #6,$13(a2)
04009760: 72df                     moveq   #$FFFFFFDF,d1
04009762: c3aa0028                 and.l   d1,$28(a2)
04009766: 2f2a0042                 move.l  $42(a2),-(sp)
0400976A: 61ff00000a96             bsr.l   _wakeup
04009770: 246efffc                 movea.l -4(a6),a2
04009774: 4e5e                     unlk    a6
04009776: 4e75                     rts

04051DC6: 4856                     pea     (a6)
04051DC8: 2c4f                     movea.l sp,a6
04051DCA: 4879040a8fa2             pea     (aTasks).l; "tasks"
04051DD0: 42a7                     clr.l   -(sp)
04051DD2: 48782000                 pea     ($2000).w
04051DD6: 2f3c00010000             move.l  #$10000,-(sp)
04051DDC: 48780080                 pea     ($80).w
04051DE0: 61ff00003200             bsr.l   _zinit
04051DE6: 23c0040c29d8             move.l  d0,(_task_zone).l
04051DEC: 4879040aff10             pea     (_kernel_task).l
04051DF2: 42a7                     clr.l   -(sp)
04051DF4: 42a7                     clr.l   -(sp)
04051DF6: 61ff00000094             bsr.l   _task_create
04051DFC: 2079040aff10             movea.l (_kernel_task).l,a0
04051E02: 7201                     moveq   #1,d1
04051E04: 21410044                 move.l  d1,$44(a0)
04051E08: 21410048                 move.l  d1,$48(a0)
04051E0C: 4e5e                     unlk    a6
04051E0E: 4e75                     rts

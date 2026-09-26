04057640: 4e56fff8                 link    a6,#-8
04057644: 486efffc                 pea     var_4(a6)
04057648: 42a7                     clr.l   -(sp)
0405764A: 2f39040aff10             move.l  (_kernel_task).l,-(sp)
04057650: 61ffffffa83a             bsr.l   _task_create
04057656: 2f2efffc                 move.l  var_4(a6),-(sp)
0405765A: 61ffffffa984             bsr.l   _task_deallocate
04057660: 486efff8                 pea     var_8(a6)
04057664: 2f2efffc                 move.l  var_4(a6),-(sp)
04057668: 61ffffffb2a2             bsr.l   _thread_create
0405766E: 2f2efff8                 move.l  var_8(a6),-(sp)
04057672: 61ffffffb422             bsr.l   _thread_deallocate
04057678: 48790405723c             pea     (_notify_server_loop).l
0405767E: 2f2efff8                 move.l  var_8(a6),-(sp)
04057682: 61ffffffc0a8             bsr.l   _thread_start
04057688: defc0020                 adda.w  #$20,sp ; ' '
0405768C: 2eaefff8                 move.l  var_8(a6),(sp)
04057690: 61ffffffbd44             bsr.l   _thread_resume
04057696: 4e5e                     unlk    a6
04057698: 4e75                     rts

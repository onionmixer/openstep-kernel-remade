04057404: 4856                     pea     (a6)
04057406: 2c4f                     movea.l sp,a6
04057408: 2f2e0008                 move.l  8(a6),-(sp)
0405740C: 2f2e000c                 move.l  $C(a6),-(sp)
04057410: 4879040a934e             pea     (aNotificationSe).l; "notification server: %s: krtn = %d\n"
04057416: 61fffffb3f40             bsr.l   _printf
0405741C: 4879040a9372             pea     (aNotificationSe_0).l; "notification server"
04057422: 61fffffb4842             bsr.l   _panic

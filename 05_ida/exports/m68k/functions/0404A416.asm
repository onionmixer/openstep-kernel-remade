0404A416: 4856                     pea     (a6)
0404A418: 2c4f                     movea.l sp,a6
0404A41A: 41f9040b3712             lea     (dword_40B3712).l,a0
0404A420: 23c8040b3716             move.l  a0,(dword_40B3716).l
0404A426: 2088                     move.l  a0,(a0)
0404A428: 48780001                 pea     (1).w
0404A42C: 4879040c233c             pea     (_stack_queue_lock).l
0404A432: 61ff00000738             bsr.l   _lock_init
0404A438: 23fc00001000040b371a     move.l  #$1000,(dword_40B371A).l
0404A442: 2039040b06d0             move.l  (_page_size).l,d0
0404A448: 068000000fff             addi.l  #$FFF,d0
0404A44E: 720c                     moveq   #$C,d1
0404A450: e2a8                     lsr.l   d1,d0
0404A452: 23c0040b371e             move.l  d0,(dword_40B371E).l
0404A458: 4e5e                     unlk    a6
0404A45A: 4e75                     rts

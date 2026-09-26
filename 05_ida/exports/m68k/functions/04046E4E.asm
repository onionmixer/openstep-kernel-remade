04046E4E: 4856                     pea     (a6)
04046E50: 2c4f                     movea.l sp,a6
04046E52: 2f2e0010                 move.l  $10(a6),-(sp)
04046E56: 2f2e000c                 move.l  $C(a6),-(sp)
04046E5A: 2f2e0008                 move.l  8(a6),-(sp)
04046E5E: 61fffffff454             bsr.l   _mach_port_rename
04046E64: 4a80                     tst.l   d0
04046E66: 6708                     beq.s   loc_4046E70
04046E68: 720d                     moveq   #$D,d1
04046E6A: b280                     cmp.l   d0,d1
04046E6C: 6702                     beq.s   loc_4046E70
04046E6E: 7004                     moveq   #4,d0
04046E70: 4e5e                     unlk    a6
04046E72: 4e75                     rts

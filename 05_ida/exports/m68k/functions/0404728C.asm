0404728C: 4856                     pea     (a6)
0404728E: 2c4f                     movea.l sp,a6
04047290: 2f2e0014                 move.l  $14(a6),-(sp)
04047294: 2f2e0010                 move.l  $10(a6),-(sp)
04047298: 2f2e000c                 move.l  $C(a6),-(sp)
0404729C: 2f2e0008                 move.l  8(a6),-(sp)
040472A0: 61fffffff414             bsr.l   _mach_port_get_set_status
040472A6: 4a80                     tst.l   d0
040472A8: 6708                     beq.s   loc_40472B2
040472AA: 7206                     moveq   #6,d1
040472AC: b280                     cmp.l   d0,d1
040472AE: 6702                     beq.s   loc_40472B2
040472B0: 7004                     moveq   #4,d0
040472B2: 4e5e                     unlk    a6
040472B4: 4e75                     rts

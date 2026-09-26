04046E74: 4e56fffc                 link    a6,#-4
04046E78: 202e0008                 move.l  arg_0(a6),d0
04046E7C: 671a                     beq.s   loc_4046E98
04046E7E: 486efffc                 pea     var_4(a6)
04046E82: 2f2e000c                 move.l  arg_4(a6),-(sp)
04046E86: 2f00                     move.l  d0,-(sp)
04046E88: 61ffffffa568             bsr.l   _ipc_port_alloc_compat
04046E8E: 4a80                     tst.l   d0
04046E90: 6708                     beq.s   loc_4046E9A
04046E92: 7206                     moveq   #6,d1
04046E94: b280                     cmp.l   d0,d1
04046E96: 6702                     beq.s   loc_4046E9A
04046E98: 7004                     moveq   #4,d0
04046E9A: 4e5e                     unlk    a6
04046E9C: 4e75                     rts

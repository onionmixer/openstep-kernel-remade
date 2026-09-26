040470E6: 4e56fffc                 link    a6,#-4
040470EA: 202e0008                 move.l  arg_0(a6),d0
040470EE: 671a                     beq.s   loc_404710A
040470F0: 486efffc                 pea     var_4(a6)
040470F4: 2f2e000c                 move.l  arg_4(a6),-(sp)
040470F8: 2f00                     move.l  d0,-(sp)
040470FA: 61ffffffa4c4             bsr.l   _ipc_pset_alloc
04047100: 4a80                     tst.l   d0
04047102: 6708                     beq.s   loc_404710C
04047104: 7206                     moveq   #6,d1
04047106: b280                     cmp.l   d0,d1
04047108: 6702                     beq.s   loc_404710C
0404710A: 7004                     moveq   #4,d0
0404710C: 4e5e                     unlk    a6
0404710E: 4e75                     rts

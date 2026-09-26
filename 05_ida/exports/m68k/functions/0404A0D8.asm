0404A0D8: 4e56fffc                 link    a6,#-4
0404A0DC: 7242                     moveq   #$42,d1 ; 'B'
0404A0DE: b2ae000c                 cmp.l   arg_4(a6),d1
0404A0E2: 6628                     bne.s   loc_404A10C
0404A0E4: 486efffc                 pea     var_4(a6)
0404A0E8: 48780002                 pea     (2).w
0404A0EC: 2f2e0008                 move.l  arg_0(a6),-(sp)
0404A0F0: 61fffffff972             bsr.l   _task_get_special_port
0404A0F6: 504f                     addq.w  #8,sp
0404A0F8: 584f                     addq.w  #4,sp
0404A0FA: 4a80                     tst.l   d0
0404A0FC: 660e                     bne.s   loc_404A10C
0404A0FE: 2f2e0010                 move.l  arg_8(a6),-(sp)
0404A102: 2f2efffc                 move.l  var_4(a6),-(sp)
0404A106: 61ffffff5eda             bsr.l   _ipc_notify_msg_accepted_compat
0404A10C: 4e5e                     unlk    a6
0404A10E: 4e75                     rts

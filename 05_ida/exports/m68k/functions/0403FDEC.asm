0403FDEC: 4856                     pea     (a6)
0403FDEE: 2c4f                     movea.l sp,a6
0403FDF0: 2f02                     move.l  d2,-(sp)
0403FDF2: 242e0008                 move.l  8(a6),d2
0403FDF6: 4878002c                 pea     ($2C).w
0403FDFA: 61ff0000a404             bsr.l   _kalloc
0403FE00: 2040                     movea.l d0,a0
0403FE02: 584f                     addq.w  #4,sp
0403FE04: 4a88                     tst.l   a0
0403FE06: 6618                     bne.s   loc_403FE20
0403FE08: 2f02                     move.l  d2,-(sp)
0403FE0A: 4879040a8450             pea     (aDroppedSendOnc).l; "dropped send-once (0x%08x)\n"
0403FE10: 61fffffcb546             bsr.l   _printf
0403FE16: 2f02                     move.l  d2,-(sp)
0403FE18: 61ff000014fc             bsr.l   _ipc_port_release_sonce
0403FE1E: 6054                     bra.s   loc_403FE74
0403FE20: 722c                     moveq   #$2C,d1 ; ','
0403FE22: 21410008                 move.l  d1,8(a0)
0403FE26: 42a8000c                 clr.l   $C(a0)
0403FE2A: 42a80010                 clr.l   $10(a0)
0403FE2E: 2179040c22a40014         move.l  (_ipc_notify_send_once_template).l,$14(a0)
0403FE36: 2179040c22a80018         move.l  (dword_40C22A8).l,$18(a0)
0403FE3E: 2179040c22ac001c         move.l  (dword_40C22AC).l,$1C(a0)
0403FE46: 2179040c22b00020         move.l  (dword_40C22B0).l,$20(a0)
0403FE4E: 2179040c22b40024         move.l  (dword_40C22B4).l,$24(a0)
0403FE56: 2179040c22b80028         move.l  (dword_40C22B8).l,$28(a0)
0403FE5E: 2142001c                 move.l  d2,$1C(a0)
0403FE62: 42a7                     clr.l   -(sp)
0403FE64: 42a7                     clr.l   -(sp)
0403FE66: 2f3c00010000             move.l  #$10000,-(sp)
0403FE6C: 2f08                     move.l  a0,-(sp)
0403FE6E: 61fffffff508             bsr.l   _ipc_mqueue_send
0403FE74: 242efffc                 move.l  -4(a6),d2
0403FE78: 4e5e                     unlk    a6
0403FE7A: 4e75                     rts

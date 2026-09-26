0404739E: 4856                     pea     (a6)
040473A0: 2c4f                     movea.l sp,a6
040473A2: 202e0008                 move.l  8(a6),d0
040473A6: 671c                     beq.s   loc_40473C4
040473A8: 2f2e0010                 move.l  $10(a6),-(sp)
040473AC: 48780001                 pea     (1).w
040473B0: 48780005                 pea     (5).w
040473B4: 2f2e000c                 move.l  $C(a6),-(sp)
040473B8: 2f00                     move.l  d0,-(sp)
040473BA: 61ffffff94ce             bsr.l   _ipc_object_copyin_compat
040473C0: 4a80                     tst.l   d0
040473C2: 6702                     beq.s   loc_40473C6
040473C4: 7004                     moveq   #4,d0
040473C6: 4e5e                     unlk    a6
040473C8: 4e75                     rts

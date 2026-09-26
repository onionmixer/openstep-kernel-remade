0401739C: 4856                     pea     (a6)
0401739E: 2c4f                     movea.l sp,a6
040173A0: 2f0a                     move.l  a2,-(sp)
040173A2: 246e0008                 movea.l 8(a6),a2
040173A6: 082a0001000f             btst    #1,$F(a2)
040173AC: 660e                     bne.s   loc_40173BC
040173AE: 4879040a65e0             pea     (aVfsUnlock).l; "vfs_unlock"
040173B4: 61ffffff48b0             bsr.l   _panic
040173BA: 584f                     addq.w  #4,sp
040173BC: 202a000c                 move.l  $C(a2),d0
040173C0: 72fd                     moveq   #$FFFFFFFD,d1
040173C2: c280                     and.l   d0,d1
040173C4: 2541000c                 move.l  d1,$C(a2)
040173C8: 08000002                 btst    #2,d0
040173CC: 6710                     beq.s   loc_40173DE
040173CE: 72f9                     moveq   #$FFFFFFF9,d1
040173D0: c280                     and.l   d0,d1
040173D2: 2541000c                 move.l  d1,$C(a2)
040173D6: 2f0a                     move.l  a2,-(sp)
040173D8: 61ffffff2e28             bsr.l   _wakeup
040173DE: 246efffc                 movea.l -4(a6),a2
040173E2: 4e5e                     unlk    a6
040173E4: 4e75                     rts

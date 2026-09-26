0406303A: 4e56fffc                 link    a6,#-4
0406303E: 2f0a                     move.l  a2,-(sp)
04063040: 246e0008                 movea.l arg_0(a6),a2
04063044: 4a8a                     tst.l   a2
04063046: 660e                     bne.s   loc_4063056
04063048: 4879040a9a7b             pea     (aVnodeHasPageFa).l; "vnode_has_page: failed lookup"
0406304E: 61fffffa8c16             bsr.l   _panic
04063054: 584f                     addq.w  #4,sp
04063056: 4a2a000c                 tst.b   $C(a2)
0406305A: 6c22                     bge.s   loc_406307E
0406305C: 486efffc                 pea     var_4(a6)
04063060: 48780001                 pea     (1).w
04063064: 2f2e000c                 move.l  arg_4(a6),-(sp)
04063068: 2f0a                     move.l  a2,-(sp)
0406306A: 61fffffffa68             bsr.l   sub_4062AD4
04063070: 7205                     moveq   #5,d1
04063072: b280                     cmp.l   d0,d1
04063074: 6604                     bne.s   loc_406307A
04063076: 4280                     clr.l   d0
04063078: 6010                     bra.s   loc_406308A
0406307A: 7001                     moveq   #1,d0
0406307C: 600c                     bra.s   loc_406308A
0406307E: 4879040a9a99             pea     (aVnodeHasPageCa).l; "vnode_has_page called on non-default pa"...
04063084: 61fffffa8be0             bsr.l   _panic
0406308A: 246efff8                 movea.l var_8(a6),a2
0406308E: 4e5e                     unlk    a6
04063090: 4e75                     rts

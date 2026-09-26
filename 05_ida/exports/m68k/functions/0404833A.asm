0404833A: 4856                     pea     (a6)
0404833C: 2c4f                     movea.l sp,a6
0404833E: 48e72030                 movem.l d2/a2-a3,-(sp)
04048342: 266e0008                 movea.l 8(a6),a3
04048346: 2f39040c21e4             move.l  (_ipc_space_kernel).l,-(sp)
0404834C: 45f904041384             lea     (_ipc_port_alloc_special).l,a2
04048352: 4e92                     jsr     (a2)
04048354: 2400                     move.l  d0,d2
04048356: 584f                     addq.w  #4,sp
04048358: 660e                     bne.s   loc_4048368
0404835A: 4879040a87ea             pea     (aIpcPsetInit).l; "ipc_pset_init"
04048360: 61fffffc3904             bsr.l   _panic
04048366: 584f                     addq.w  #4,sp
04048368: 2742014c                 move.l  d2,$14C(a3)
0404836C: 2f39040c21e4             move.l  (_ipc_space_kernel).l,-(sp)
04048372: 4e92                     jsr     (a2)
04048374: 2400                     move.l  d0,d2
04048376: 584f                     addq.w  #4,sp
04048378: 660c                     bne.s   loc_4048386
0404837A: 4879040a87ea             pea     (aIpcPsetInit).l; "ipc_pset_init"
04048380: 61fffffc38e4             bsr.l   _panic
04048386: 27420150                 move.l  d2,$150(a3)
0404838A: 4cee0c04fff4             movem.l -$C(a6),d2/a2-a3
04048390: 4e5e                     unlk    a6
04048392: 4e75                     rts

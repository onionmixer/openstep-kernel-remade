0403CD3C: 4e56fff8                 link    a6,#-8
0403CD40: 4879040c21e0             pea     (_ipc_soft_task).l
0403CD46: 42a7                     clr.l   -(sp)
0403CD48: 42a7                     clr.l   -(sp)
0403CD4A: 61ff00015140             bsr.l   _task_create
0403CD50: 504f                     addq.w  #8,sp
0403CD52: 584f                     addq.w  #4,sp
0403CD54: 4a80                     tst.l   d0
0403CD56: 670e                     beq.s   loc_403CD66
0403CD58: 4879040a8373             pea     (aIpcInit).l; "ipc_init"
0403CD5E: 61fffffcef06             bsr.l   _panic
0403CD64: 584f                     addq.w  #4,sp
0403CD66: 2079040c21e0             movea.l (_ipc_soft_task).l,a0
0403CD6C: 23e80008040c21dc         move.l  8(a0),(_ipc_soft_map).l
0403CD74: 48780001                 pea     (1).w
0403CD78: 2f39040af748             move.l  (_ipc_kernel_map_size).l,-(sp)
0403CD7E: 486efff8                 pea     var_8(a6)
0403CD82: 486efffc                 pea     var_4(a6)
0403CD86: 2f39040b5dbc             move.l  (_kernel_map).l,-(sp)
0403CD8C: 61ff00020a76             bsr.l   _kmem_suballoc
0403CD92: 23c0040c21cc             move.l  d0,(_ipc_kernel_map).l
0403CD98: 61ff0000b460             bsr.l   _ipc_host_init
0403CD9E: 4e5e                     unlk    a6
0403CDA0: 4e75                     rts

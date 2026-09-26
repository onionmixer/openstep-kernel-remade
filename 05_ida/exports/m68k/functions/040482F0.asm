040482F0: 4856                     pea     (a6)
040482F2: 2c4f                     movea.l sp,a6
040482F4: 2f0a                     move.l  a2,-(sp)
040482F6: 2f02                     move.l  d2,-(sp)
040482F8: 246e0008                 movea.l 8(a6),a2
040482FC: 2f39040c21e4             move.l  (_ipc_space_kernel).l,-(sp)
04048302: 61ffffff9080             bsr.l   _ipc_port_alloc_special
04048308: 2400                     move.l  d0,d2
0404830A: 584f                     addq.w  #4,sp
0404830C: 660e                     bne.s   loc_404831C
0404830E: 4879040a87d7             pea     (aIpcProcessorIn).l; "ipc_processor_init"
04048314: 61fffffc3950             bsr.l   _panic
0404831A: 584f                     addq.w  #4,sp
0404831C: 25420138                 move.l  d2,$138(a2)
04048320: 48780005                 pea     (5).w
04048324: 2f0a                     move.l  a2,-(sp)
04048326: 2f02                     move.l  d2,-(sp)
04048328: 61ff000004e2             bsr.l   _ipc_kobject_set
0404832E: 242efff8                 move.l  -8(a6),d2
04048332: 246efffc                 movea.l -4(a6),a2
04048336: 4e5e                     unlk    a6
04048338: 4e75                     rts

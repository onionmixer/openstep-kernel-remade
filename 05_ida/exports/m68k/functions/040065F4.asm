040065F4: 4856                     pea     (a6)
040065F6: 2c4f                     movea.l sp,a6
040065F8: 2f0a                     move.l  a2,-(sp)
040065FA: 4879040a5ee4             pea     (aUtasks).l; "utasks"
04006600: 42a7                     clr.l   -(sp)
04006602: 2f3c0000a280             move.l  #$A280,-(sp)
04006608: 2f3c00051400             move.l  #$51400,-(sp)
0400660E: 4878028a                 pea     ($28A).w
04006612: 45f904054fe2             lea     (_zinit).l,a2
04006618: 4e92                     jsr     (a2)
0400661A: 23c0040b652c             move.l  d0,(_u_task_zone).l
04006620: 4879040a5eeb             pea     (aUthreads).l; "uthreads"
04006626: 42a7                     clr.l   -(sp)
04006628: 48785380                 pea     ($5380).w
0400662C: 2f3c00029c00             move.l  #$29C00,-(sp)
04006632: 4878014e                 pea     ($14E).w
04006636: 4e92                     jsr     (a2)
04006638: 23c0040b6530             move.l  d0,(_u_thread_zone).l
0400663E: 246efffc                 movea.l -4(a6),a2
04006642: 4e5e                     unlk    a6
04006644: 4e75                     rts

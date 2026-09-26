04041358: 4856                     pea     (a6)
0404135A: 2c4f                     movea.l sp,a6
0404135C: 2f02                     move.l  d2,-(sp)
0404135E: 206e0008                 movea.l 8(a6),a0
04041362: 24280008                 move.l  8(a0),d2
04041366: 2f08                     move.l  a0,-(sp)
04041368: 61fffffffc76             bsr.l   _ipc_port_destroy
0404136E: 584f                     addq.w  #4,sp
04041370: 4a82                     tst.l   d2
04041372: 6708                     beq.s   loc_404137C
04041374: 2f02                     move.l  d2,-(sp)
04041376: 61ffffffedee             bsr.l   _ipc_object_release
0404137C: 242efffc                 move.l  -4(a6),d2
04041380: 4e5e                     unlk    a6
04041382: 4e75                     rts

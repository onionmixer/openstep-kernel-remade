0404A0B0: 4856                     pea     (a6)
0404A0B2: 2c4f                     movea.l sp,a6
0404A0B4: 202e0008                 move.l  8(a6),d0
0404A0B8: 6708                     beq.s   loc_404A0C2
0404A0BA: 2f00                     move.l  d0,-(sp)
0404A0BC: 61ffffff71d0             bsr.l   _ipc_port_release_send
0404A0C2: 4e5e                     unlk    a6
0404A0C4: 4e75                     rts

0404A09A: 4856                     pea     (a6)
0404A09C: 2c4f                     movea.l sp,a6
0404A09E: 202e0008                 move.l  8(a6),d0
0404A0A2: 6708                     beq.s   loc_404A0AC
0404A0A4: 2f00                     move.l  d0,-(sp)
0404A0A6: 61ffffff7156             bsr.l   _ipc_port_copy_send
0404A0AC: 4e5e                     unlk    a6
0404A0AE: 4e75                     rts

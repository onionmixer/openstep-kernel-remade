0404F7EC: 4856                     pea     (a6)
0404F7EE: 2c4f                     movea.l sp,a6
0404F7F0: 2f0a                     move.l  a2,-(sp)
0404F7F2: 246e0008                 movea.l 8(a6),a2
0404F7F6: 226a0004                 movea.l 4(a2),a1
0404F7FA: b5c9                     cmpa.l  a1,a2
0404F7FC: 6710                     beq.s   loc_404F80E
0404F7FE: 20690004                 movea.l 4(a1),a0
0404F802: 208a                     move.l  a2,(a0)
0404F804: 256900040004             move.l  4(a1),4(a2)
0404F80A: 2009                     move.l  a1,d0
0404F80C: 6002                     bra.s   loc_404F810
0404F80E: 4280                     clr.l   d0
0404F810: 246efffc                 movea.l -4(a6),a2
0404F814: 4e5e                     unlk    a6
0404F816: 4e75                     rts

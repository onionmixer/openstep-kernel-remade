0404A010: 4856                     pea     (a6)
0404A012: 2c4f                     movea.l sp,a6
0404A014: 206e0008                 movea.l 8(a6),a0
0404A018: 2f2e0018                 move.l  $18(a6),-(sp)
0404A01C: 2f2e0014                 move.l  $14(a6),-(sp)
0404A020: 2f2e0010                 move.l  $10(a6),-(sp)
0404A024: 2f2e000c                 move.l  $C(a6),-(sp)
0404A028: 2f28007c                 move.l  $7C(a0),-(sp)
0404A02C: 61ffffff685c             bsr.l   _ipc_object_copyin_compat
0404A032: 2200                     move.l  d0,d1
0404A034: 4280                     clr.l   d0
0404A036: 4a81                     tst.l   d1
0404A038: 6602                     bne.s   loc_404A03C
0404A03A: 7001                     moveq   #1,d0
0404A03C: 4e5e                     unlk    a6
0404A03E: 4e75                     rts

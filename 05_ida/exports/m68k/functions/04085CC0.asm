04085CC0: 4856                     pea     (a6)
04085CC2: 2c4f                     movea.l sp,a6
04085CC4: 226e0008                 movea.l 8(a6),a1
04085CC8: 222e000c                 move.l  $C(a6),d1
04085CCC: 2011                     move.l  (a1),d0
04085CCE: b089                     cmp.l   a1,d0
04085CD0: 6712                     beq.s   loc_4085CE4
04085CD2: 2040                     movea.l d0,a0
04085CD4: b290                     cmp.l   (a0),d1
04085CD6: 6604                     bne.s   loc_4085CDC
04085CD8: 2008                     move.l  a0,d0
04085CDA: 600a                     bra.s   loc_4085CE6
04085CDC: 20680008                 movea.l 8(a0),a0
04085CE0: b1c9                     cmpa.l  a1,a0
04085CE2: 66f0                     bne.s   loc_4085CD4
04085CE4: 4280                     clr.l   d0
04085CE6: 4e5e                     unlk    a6
04085CE8: 4e75                     rts

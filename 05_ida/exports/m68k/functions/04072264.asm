04072264: 4856                     pea     (a6)
04072266: 2c4f                     movea.l sp,a6
04072268: 4240                     clr.w   d0
0407226A: 102e000b                 move.b  $B(a6),d0
0407226E: 0c400003                 cmpi.w  #3,d0
04072272: 6e04                     bgt.s   loc_4072278
04072274: 4a40                     tst.w   d0
04072276: 6c04                     bge.s   loc_407227C
04072278: 7016                     moveq   #$16,d0
0407227A: 6002                     bra.s   loc_407227E
0407227C: 4280                     clr.l   d0
0407227E: 4e5e                     unlk    a6
04072280: 4e75                     rts

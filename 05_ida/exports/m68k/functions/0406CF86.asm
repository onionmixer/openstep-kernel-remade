0406CF86: 4856                     pea     (a6)
0406CF88: 2c4f                     movea.l sp,a6
0406CF8A: 2f0a                     move.l  a2,-(sp)
0406CF8C: 2f02                     move.l  d2,-(sp)
0406CF8E: 246e0008                 movea.l 8(a6),a2
0406CF92: 142e000f                 move.b  $F(a6),d2
0406CF96: 42a7                     clr.l   -(sp)
0406CF98: 2f0a                     move.l  a2,-(sp)
0406CF9A: 61ff0000004c             bsr.l   sub_406CFE8
0406CFA0: 4a80                     tst.l   d0
0406CFA2: 6606                     bne.s   loc_406CFAA
0406CFA4: 2052                     movea.l (a2),a0
0406CFA6: 11420005                 move.b  d2,5(a0)
0406CFAA: 242efff8                 move.l  -8(a6),d2
0406CFAE: 246efffc                 movea.l -4(a6),a2
0406CFB2: 4e5e                     unlk    a6
0406CFB4: 4e75                     rts

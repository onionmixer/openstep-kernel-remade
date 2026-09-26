0400CB98: 4856                     pea     (a6)
0400CB9A: 2c4f                     movea.l sp,a6
0400CB9C: 2f0a                     move.l  a2,-(sp)
0400CB9E: 246e0008                 movea.l 8(a6),a2
0400CBA2: 4280                     clr.l   d0
0400CBA4: 222a0016                 move.l  $16(a2),d1
0400CBA8: 6708                     beq.s   loc_400CBB2
0400CBAA: 2f01                     move.l  d1,-(sp)
0400CBAC: 61ff00005f1c             bsr.l   _soclose
0400CBB2: 42aa0016                 clr.l   $16(a2)
0400CBB6: 246efffc                 movea.l -4(a6),a2
0400CBBA: 4e5e                     unlk    a6
0400CBBC: 4e75                     rts

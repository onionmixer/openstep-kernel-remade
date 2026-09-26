0403951C: 4856                     pea     (a6)
0403951E: 2c4f                     movea.l sp,a6
04039520: 206e0010                 movea.l $10(a6),a0
04039524: 122e000b                 move.b  $B(a6),d1
04039528: 2008                     move.l  a0,d0
0403952A: d0ae000c                 add.l   $C(a6),d0
0403952E: b088                     cmp.l   a0,d0
04039530: 630a                     bls.s   loc_403953C
04039532: b210                     cmp.b   (a0),d1
04039534: 6606                     bne.s   loc_403953C
04039536: 5248                     addq.w  #1,a0
04039538: b088                     cmp.l   a0,d0
0403953A: 62f6                     bhi.s   loc_4039532
0403953C: 9088                     sub.l   a0,d0
0403953E: 4e5e                     unlk    a6
04039540: 4e75                     rts

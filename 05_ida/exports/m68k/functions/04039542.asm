04039542: 4856                     pea     (a6)
04039544: 2c4f                     movea.l sp,a6
04039546: 206e0010                 movea.l $10(a6),a0
0403954A: 122e000b                 move.b  $B(a6),d1
0403954E: 2008                     move.l  a0,d0
04039550: d0ae000c                 add.l   $C(a6),d0
04039554: b088                     cmp.l   a0,d0
04039556: 630a                     bls.s   loc_4039562
04039558: b210                     cmp.b   (a0),d1
0403955A: 6706                     beq.s   loc_4039562
0403955C: 5248                     addq.w  #1,a0
0403955E: b088                     cmp.l   a0,d0
04039560: 62f6                     bhi.s   loc_4039558
04039562: 9088                     sub.l   a0,d0
04039564: 4e5e                     unlk    a6
04039566: 4e75                     rts

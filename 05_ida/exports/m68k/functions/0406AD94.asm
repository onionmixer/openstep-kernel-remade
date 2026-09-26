0406AD94: 4856                     pea     (a6)
0406AD96: 2c4f                     movea.l sp,a6
0406AD98: 226e0008                 movea.l 8(a6),a1
0406AD9C: 2069001c                 movea.l $1C(a1),a0
0406ADA0: 4280                     clr.l   d0
0406ADA2: 10280058                 move.b  $58(a0),d0
0406ADA6: 7210                     moveq   #$10,d1
0406ADA8: e1a1                     asl.l   d0,d1
0406ADAA: 2051                     movea.l (a1),a0
0406ADAC: 4601                     not.b   d1
0406ADAE: 10280002                 move.b  2(a0),d0
0406ADB2: c001                     and.b   d1,d0
0406ADB4: 11400002                 move.b  d0,2(a0)
0406ADB8: 4e5e                     unlk    a6
0406ADBA: 4e75                     rts

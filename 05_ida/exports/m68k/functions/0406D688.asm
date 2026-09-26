0406D688: 4856                     pea     (a6)
0406D68A: 2c4f                     movea.l sp,a6
0406D68C: 2f02                     move.l  d2,-(sp)
0406D68E: 206e0008                 movea.l 8(a6),a0
0406D692: 222e000c                 move.l  $C(a6),d1
0406D696: 40c2                     move    sr,d2
0406D698: 46fc2300                 move    #$2300,sr
0406D69C: 48c2                     ext.l   d2
0406D69E: 4681                     not.l   d1
0406D6A0: 20280018                 move.l  $18(a0),d0
0406D6A4: c081                     and.l   d1,d0
0406D6A6: 21400018                 move.l  d0,$18(a0)
0406D6AA: 40c0                     move    sr,d0
0406D6AC: 46c2                     move    d2,sr
0406D6AE: 242efffc                 move.l  -4(a6),d2
0406D6B2: 4e5e                     unlk    a6
0406D6B4: 4e75                     rts

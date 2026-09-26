0405070A: 4856                     pea     (a6)
0405070C: 2c4f                     movea.l sp,a6
0405070E: 2f02                     move.l  d2,-(sp)
04050710: 2079040b5648             movea.l (_active_threads).l,a0
04050716: 40c0                     move    sr,d0
04050718: 46fc2300                 move    #$2300,sr
0405071C: 3400                     move.w  d0,d2
0405071E: 48c2                     ext.l   d2
04050720: 08280000004b             btst    #0,$4B(a0)
04050726: 670e                     beq.s   loc_4050736
04050728: 2f2e0008                 move.l  8(a6),-(sp)
0405072C: 48680110                 pea     $110(a0)
04050730: 61ffffffaa08             bsr.l   _set_timeout
04050736: 40c0                     move    sr,d0
04050738: 46c2                     move    d2,sr
0405073A: 242efffc                 move.l  -4(a6),d2
0405073E: 4e5e                     unlk    a6
04050740: 4e75                     rts

0408E796: 4856                     pea     (a6)
0408E798: 2c4f                     movea.l sp,a6
0408E79A: 2f02                     move.l  d2,-(sp)
0408E79C: 202e0008                 move.l  8(a6),d0
0408E7A0: 4c3c08000000052c         muls.l  #$52C,d0
0408E7A8: 2040                     movea.l d0,a0
0408E7AA: d1fc040c8f34             adda.l  #$40C8F34,a0
0408E7B0: 40c2                     move    sr,d2
0408E7B2: 46fc2300                 move    #$2300,sr
0408E7B6: 48c2                     ext.l   d2
0408E7B8: 2f10                     move.l  (a0),-(sp)
0408E7BA: 61fffff8d5bc             bsr.l   _if_down
0408E7C0: 40c0                     move    sr,d0
0408E7C2: 46c2                     move    d2,sr
0408E7C4: 242efffc                 move.l  -4(a6),d2
0408E7C8: 4e5e                     unlk    a6
0408E7CA: 4e75                     rts

0405FDE8: 4856                     pea     (a6)
0405FDEA: 2c4f                     movea.l sp,a6
0405FDEC: 48e73030                 movem.l d2-d3/a2-a3,-(sp)
0405FDF0: 266e0008                 movea.l 8(a6),a3
0405FDF4: 262e000c                 move.l  $C(a6),d3
0405FDF8: 242e0010                 move.l  $10(a6),d2
0405FDFC: 4a8b                     tst.l   a3
0405FDFE: 6734                     beq.s   loc_405FE34
0405FE00: 2453                     movea.l (a3),a2
0405FE02: b5cb                     cmpa.l  a3,a2
0405FE04: 672e                     beq.s   loc_405FE34
0405FE06: 202a0018                 move.l  $18(a2),d0
0405FE0A: b083                     cmp.l   d3,d0
0405FE0C: 651e                     bcs.s   loc_405FE2C
0405FE0E: b480                     cmp.l   d0,d2
0405FE10: 631a                     bls.s   loc_405FE2C
0405FE12: 082a00050021             btst    #5,$21(a2)
0405FE18: 6612                     bne.s   loc_405FE2C
0405FE1A: 2f2a0022                 move.l  $22(a2),-(sp)
0405FE1E: 61ff000382b6             bsr.l   _pmap_copy_on_write
0405FE24: 002a00200021             ori.b   #$20,$21(a2) ; ' '
0405FE2A: 584f                     addq.w  #4,sp
0405FE2C: 246a0008                 movea.l 8(a2),a2
0405FE30: b5cb                     cmpa.l  a3,a2
0405FE32: 66d2                     bne.s   loc_405FE06
0405FE34: 4cee0c0cfff0             movem.l -$10(a6),d2-d3/a2-a3
0405FE3A: 4e5e                     unlk    a6
0405FE3C: 4e75                     rts

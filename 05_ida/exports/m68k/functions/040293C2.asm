040293C2: 4856                     pea     (a6)
040293C4: 2c4f                     movea.l sp,a6
040293C6: 2f0a                     move.l  a2,-(sp)
040293C8: 246e0008                 movea.l 8(a6),a2
040293CC: 206a0030                 movea.l $30(a2),a0
040293D0: 20680126                 movea.l $126(a0),a0
040293D4: 53a80016                 subq.l  #1,$16(a0)
040293D8: 2f0a                     move.l  a2,-(sp)
040293DA: 61ffffffffc2             bsr.l   _rinactive
040293E0: 48780001                 pea     (1).w
040293E4: 2f0a                     move.l  a2,-(sp)
040293E6: 61ffffffff26             bsr.l   sub_402930E
040293EC: 246efffc                 movea.l -4(a6),a2
040293F0: 4e5e                     unlk    a6
040293F2: 4e75                     rts

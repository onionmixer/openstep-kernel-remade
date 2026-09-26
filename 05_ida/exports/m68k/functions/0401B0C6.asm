0401B0C6: 4856                     pea     (a6)
0401B0C8: 2c4f                     movea.l sp,a6
0401B0CA: 2f0a                     move.l  a2,-(sp)
0401B0CC: 246e0008                 movea.l 8(a6),a2
0401B0D0: 4a6a0006                 tst.w   6(a2)
0401B0D4: 660e                     bne.s   loc_401B0E4
0401B0D6: 4879040a6717             pea     (aVnRele).l; "vn_rele"
0401B0DC: 61ffffff0b88             bsr.l   _panic
0401B0E2: 584f                     addq.w  #4,sp
0401B0E4: 302a0006                 move.w  6(a2),d0
0401B0E8: 3200                     move.w  d0,d1
0401B0EA: 5341                     subq.w  #1,d1
0401B0EC: 35410006                 move.w  d1,6(a2)
0401B0F0: 0c400001                 cmpi.w  #1,d0
0401B0F4: 6616                     bne.s   loc_401B10C
0401B0F6: 206a001c                 movea.l $1C(a2),a0
0401B0FA: 2279040b57d0             movea.l (_active_u).l,a1
0401B100: 2f29001a                 move.l  $1A(a1),-(sp)
0401B104: 2f0a                     move.l  a2,-(sp)
0401B106: 2068004c                 movea.l $4C(a0),a0
0401B10A: 4e90                     jsr     (a0)
0401B10C: 246efffc                 movea.l -4(a6),a2
0401B110: 4e5e                     unlk    a6
0401B112: 4e75                     rts

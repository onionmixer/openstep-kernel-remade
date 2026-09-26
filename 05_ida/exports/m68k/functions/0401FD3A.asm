0401FD3A: 4856                     pea     (a6)
0401FD3C: 2c4f                     movea.l sp,a6
0401FD3E: 2f0b                     move.l  a3,-(sp)
0401FD40: 2f0a                     move.l  a2,-(sp)
0401FD42: 266e0008                 movea.l 8(a6),a3
0401FD46: 246e000c                 movea.l $C(a6),a2
0401FD4A: 357c00100008             move.w  #$10,8(a2)
0401FD50: d5ea0004                 adda.l  4(a2),a2
0401FD54: 48780010                 pea     ($10).w
0401FD58: 2f0a                     move.l  a2,-(sp)
0401FD5A: 61ff000730b6             bsr.l   _bzero
0401FD60: 34bc0002                 move.w  #2,(a2)
0401FD64: 356b00100002             move.w  $10(a3),2(a2)
0401FD6A: 256b000c0004             move.l  $C(a3),4(a2)
0401FD70: 246efff8                 movea.l -8(a6),a2
0401FD74: 266efffc                 movea.l -4(a6),a3
0401FD78: 4e5e                     unlk    a6
0401FD7A: 4e75                     rts

0401FCF8: 4856                     pea     (a6)
0401FCFA: 2c4f                     movea.l sp,a6
0401FCFC: 2f0b                     move.l  a3,-(sp)
0401FCFE: 2f0a                     move.l  a2,-(sp)
0401FD00: 266e0008                 movea.l 8(a6),a3
0401FD04: 246e000c                 movea.l $C(a6),a2
0401FD08: 357c00100008             move.w  #$10,8(a2)
0401FD0E: d5ea0004                 adda.l  4(a2),a2
0401FD12: 48780010                 pea     ($10).w
0401FD16: 2f0a                     move.l  a2,-(sp)
0401FD18: 61ff000730f8             bsr.l   _bzero
0401FD1E: 34bc0002                 move.w  #2,(a2)
0401FD22: 356b00160002             move.w  $16(a3),2(a2)
0401FD28: 256b00120004             move.l  $12(a3),4(a2)
0401FD2E: 246efff8                 movea.l -8(a6),a2
0401FD32: 266efffc                 movea.l -4(a6),a3
0401FD36: 4e5e                     unlk    a6
0401FD38: 4e75                     rts

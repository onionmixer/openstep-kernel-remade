04019BEE: 4856                     pea     (a6)
04019BF0: 2c4f                     movea.l sp,a6
04019BF2: 48e73020                 movem.l d2-d3/a2,-(sp)
04019BF6: 246e0008                 movea.l 8(a6),a2
04019BFA: 262e000c                 move.l  $C(a6),d3
04019BFE: 2f03                     move.l  d3,-(sp)
04019C00: 61ff000794e4             bsr.l   _strlen
04019C06: 2400                     move.l  d0,d2
04019C08: 222a0008                 move.l  8(a2),d1
04019C0C: 2001                     move.l  d1,d0
04019C0E: d082                     add.l   d2,d0
04019C10: 584f                     addq.w  #4,sp
04019C12: 0c80000003ff             cmpi.l  #$3FF,d0
04019C18: 621c                     bhi.s   loc_4019C36
04019C1A: 2042                     movea.l d2,a0
04019C1C: 48680001                 pea     1(a0)
04019C20: d2aa0004                 add.l   4(a2),d1
04019C24: 2f01                     move.l  d1,-(sp)
04019C26: 2f03                     move.l  d3,-(sp)
04019C28: 61ff00079102             bsr.l   _bcopy
04019C2E: d5aa0008                 add.l   d2,8(a2)
04019C32: 4280                     clr.l   d0
04019C34: 6002                     bra.s   loc_4019C38
04019C36: 703f                     moveq   #$3F,d0 ; '?'
04019C38: 4cee040cfff4             movem.l -$C(a6),d2-d3/a2
04019C3E: 4e5e                     unlk    a6
04019C40: 4e75                     rts

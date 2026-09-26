040187B4: 4856                     pea     (a6)
040187B6: 2c4f                     movea.l sp,a6
040187B8: 48e73020                 movem.l d2-d3/a2,-(sp)
040187BC: 246e0008                 movea.l 8(a6),a2
040187C0: 242e000c                 move.l  $C(a6),d2
040187C4: 2f0a                     move.l  a2,-(sp)
040187C6: 61ff0007a91e             bsr.l   _strlen
040187CC: 2040                     movea.l d0,a0
040187CE: 584f                     addq.w  #4,sp
040187D0: 7620                     moveq   #$20,d3 ; ' '
040187D2: b688                     cmp.l   a0,d3
040187D4: 6c04                     bge.s   loc_40187DA
040187D6: 4280                     clr.l   d0
040187D8: 6026                     bra.s   loc_4018800
040187DA: 1012                     move.b  (a2),d0
040187DC: 49c0                     extb.l  d0
040187DE: 123288ff                 move.b  -1(a2,a0.l),d1
040187E2: 49c1                     extb.l  d1
040187E4: d081                     add.l   d1,d0
040187E6: d088                     add.l   a0,d0
040187E8: d082                     add.l   d2,d0
040187EA: 4878ffff                 pea     ($FFFFFFFF).w
040187EE: 763f                     moveq   #$3F,d3 ; '?'
040187F0: c680                     and.l   d0,d3
040187F2: 2f03                     move.l  d3,-(sp)
040187F4: 2f08                     move.l  a0,-(sp)
040187F6: 2f0a                     move.l  a2,-(sp)
040187F8: 2f02                     move.l  d2,-(sp)
040187FA: 61ff000003b2             bsr.l   sub_4018BAE
04018800: 4cee040cfff4             movem.l -$C(a6),d2-d3/a2
04018806: 4e5e                     unlk    a6
04018808: 4e75                     rts

04071E0E: 4856                     pea     (a6)
04071E10: 2c4f                     movea.l sp,a6
04071E12: 48e73020                 movem.l d2-d3/a2,-(sp)
04071E16: 242e0008                 move.l  8(a6),d2
04071E1A: 93c9                     suba.l  a1,a1
04071E1C: 45f9040b693c             lea     (_km_coni).l,a2
04071E22: 91c8                     suba.l  a0,a0
04071E24: 2032883c                 move.l  $3C(a2,a0.l),d0
04071E28: 6718                     beq.s   loc_4071E42
04071E2A: 22328834                 move.l  $34(a2,a0.l),d1
04071E2E: b282                     cmp.l   d2,d1
04071E30: 6210                     bhi.s   loc_4071E42
04071E32: d081                     add.l   d1,d0
04071E34: b082                     cmp.l   d2,d0
04071E36: 630a                     bls.s   loc_4071E42
04071E38: 2002                     move.l  d2,d0
04071E3A: 9081                     sub.l   d1,d0
04071E3C: d0b28838                 add.l   $38(a2,a0.l),d0
04071E40: 6034                     bra.s   loc_4071E76
04071E42: 5048                     addq.w  #8,a0
04071E44: 5848                     addq.w  #4,a0
04071E46: 5249                     addq.w  #1,a1
04071E48: 7605                     moveq   #5,d3
04071E4A: b689                     cmp.l   a1,d3
04071E4C: 6cd6                     bge.s   loc_4071E24
04071E4E: 1639040b6964             move.b  (byte_40B6964).l,d3
04071E54: 49c3                     extb.l  d3
04071E56: 2f03                     move.l  d3,-(sp)
04071E58: 2f02                     move.l  d2,-(sp)
04071E5A: 4879040aa663             pea     (aKmConvertAddr0).l; "km_convert_addr(0x%x): Bad p-code ROM a"...
04071E60: 48780003                 pea     (3).w
04071E64: 61fffff995f2             bsr.l   _log
04071E6A: 4879040aa69c             pea     (aKmConvertAddrH).l; "km_convert_addr() hit invalid phys addr"...
04071E70: 61fffff99df4             bsr.l   _panic
04071E76: 4cee040cfff4             movem.l -$C(a6),d2-d3/a2
04071E7C: 4e5e                     unlk    a6
04071E7E: 4e75                     rts

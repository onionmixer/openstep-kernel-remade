0405D592: 4856                     pea     (a6)
0405D594: 2c4f                     movea.l sp,a6
0405D596: 48e73800                 movem.l d2-d4,-(sp)
0405D59A: 282e0008                 move.l  8(a6),d4
0405D59E: 262e000c                 move.l  $C(a6),d3
0405D5A2: 242e0010                 move.l  $10(a6),d2
0405D5A6: 2f02                     move.l  d2,-(sp)
0405D5A8: 61ff000024c2             bsr.l   _vm_object_allocate
0405D5AE: 48780001                 pea     (1).w
0405D5B2: 2f00                     move.l  d0,-(sp)
0405D5B4: 48780001                 pea     (1).w
0405D5B8: 2f02                     move.l  d2,-(sp)
0405D5BA: 2f03                     move.l  d3,-(sp)
0405D5BC: 2f04                     move.l  d4,-(sp)
0405D5BE: 61fffffffe88             bsr.l   sub_405D448
0405D5C4: 4cee001cfff4             movem.l -$C(a6),d2-d4
0405D5CA: 4e5e                     unlk    a6
0405D5CC: 4e75                     rts

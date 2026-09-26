0404814A: 4856                     pea     (a6)
0404814C: 2c4f                     movea.l sp,a6
0404814E: 4aae0008                 tst.l   8(a6)
04048152: 6718                     beq.s   loc_404816C
04048154: 48780200                 pea     ($200).w
04048158: 4879040b3119             pea     (_version).l; "NeXT Mach 4.2: Sun Apr 27 13:42:14 PDT "...
0404815E: 2f2e000c                 move.l  $C(a6),-(sp)
04048162: 61ff0004aed2             bsr.l   _strncpy
04048168: 4280                     clr.l   d0
0404816A: 6002                     bra.s   loc_404816E
0404816C: 7004                     moveq   #4,d0
0404816E: 4e5e                     unlk    a6
04048170: 4e75                     rts

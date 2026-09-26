0404D002: 4856                     pea     (a6)
0404D004: 2c4f                     movea.l sp,a6
0404D006: 2f0b                     move.l  a3,-(sp)
0404D008: 2f0a                     move.l  a2,-(sp)
0404D00A: 266e0008                 movea.l 8(a6),a3
0404D00E: 2453                     movea.l (a3),a2
0404D010: 4a8a                     tst.l   a2
0404D012: 6610                     bne.s   loc_404D024
0404D014: 2f39040b611c             move.l  (_vm_info_zone).l,-(sp)
0404D01A: 61ff00008b3a             bsr.l   _zalloc
0404D020: 2440                     movea.l d0,a2
0404D022: 584f                     addq.w  #4,sp
0404D024: 4292                     clr.l   (a2)
0404D026: 426a0004                 clr.w   4(a2)
0404D02A: 426a0006                 clr.w   6(a2)
0404D02E: 42aa0008                 clr.l   8(a2)
0404D032: 42aa000c                 clr.l   $C(a2)
0404D036: 42aa0010                 clr.l   $10(a2)
0404D03A: 42aa002c                 clr.l   $2C(a2)
0404D03E: 42aa0030                 clr.l   $30(a2)
0404D042: 102a0034                 move.b  $34(a2),d0
0404D046: 00000020                 ori.b   #$20,d0 ; ' '
0404D04A: 02000037                 andi.b  #$37,d0 ; '7'
0404D04E: 15400034                 move.b  d0,$34(a2)
0404D052: 42aa0014                 clr.l   $14(a2)
0404D056: 48780001                 pea     (1).w
0404D05A: 486a0018                 pea     $18(a2)
0404D05E: 61ffffffdb0c             bsr.l   _lock_init
0404D064: 42aa0020                 clr.l   $20(a2)
0404D068: 268a                     move.l  a2,(a3)
0404D06A: 246efff8                 movea.l -8(a6),a2
0404D06E: 266efffc                 movea.l -4(a6),a3
0404D072: 4e5e                     unlk    a6
0404D074: 4e75                     rts

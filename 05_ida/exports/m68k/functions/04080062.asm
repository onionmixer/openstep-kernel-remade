04080062: 4856                     pea     (a6)
04080064: 2c4f                     movea.l sp,a6
04080066: 2f02                     move.l  d2,-(sp)
04080068: 202e0008                 move.l  8(a6),d0
0408006C: e9c01408                 bfextu  d0{16:8},d1
04080070: 742b                     moveq   #$2B,d2 ; '+'
04080072: 9481                     sub.l   d1,d2
04080074: 2202                     move.l  d2,d1
04080076: 23c1040b20c4             move.l  d1,(_vol_l).l
0408007C: 0280000000ff             andi.l  #$FF,d0
04080082: 742b                     moveq   #$2B,d2 ; '+'
04080084: 9480                     sub.l   d0,d2
04080086: 2002                     move.l  d2,d0
04080088: 23c0040b20c0             move.l  d0,(_vol_r).l
0408008E: 61ff0000003c             bsr.l   sub_40800CC
04080094: 61ff000002f2             bsr.l   sub_4080388
0408009A: 242efffc                 move.l  -4(a6),d2
0408009E: 4e5e                     unlk    a6
040800A0: 4e75                     rts

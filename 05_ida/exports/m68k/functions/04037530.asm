04037530: 4856                     pea     (a6)
04037532: 2c4f                     movea.l sp,a6
04037534: 41f9040c10ac             lea     (_ihead).l,a0
0403753A: 203c000001ff             move.l  #$1FF,d0
04037540: 2088                     move.l  a0,(a0)
04037542: 21480004                 move.l  a0,4(a0)
04037546: 5048                     addq.w  #8,a0
04037548: 51c8fff6                 dbf     d0,loc_4037540
0403754C: 4240                     clr.w   d0
0403754E: 5380                     subq.l  #1,d0
04037550: 64ee                     bcc.s   loc_4037540
04037552: 42b9040c10a4             clr.l   (_ifreeh).l
04037558: 42b9040c10a8             clr.l   (_ifreet).l
0403755E: 42b9040b67b4             clr.l   (_inode_list).l
04037564: 4879040a8099             pea     (aInodeStructure).l; "inode structures"
0403756A: 42a7                     clr.l   -(sp)
0403756C: 42a7                     clr.l   -(sp)
0403756E: 2f3c00231860             move.l  #$231860,-(sp)
04037574: 487800e6                 pea     ($E6).w
04037578: 61ff0001da68             bsr.l   _zinit
0403757E: 23c0040c20ac             move.l  d0,(_inode_zone).l
04037584: 4e5e                     unlk    a6
04037586: 4e75                     rts

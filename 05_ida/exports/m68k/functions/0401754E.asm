0401754E: 4856                     pea     (a6)
04017550: 2c4f                     movea.l sp,a6
04017552: 226e0008                 movea.l 8(a6),a1
04017556: 7080                     moveq   #$FFFFFF80,d0
04017558: d0ae000c                 add.l   $C(a6),d0
0401755C: 41f9040ae796             lea     (_vfssw).l,a0
04017562: 22690004                 movea.l 4(a1),a1
04017566: b3f00e04                 cmpa.l  4(a0,d0.l*8),a1
0401756A: 670e                     beq.s   loc_401757A
0401756C: 2f00                     move.l  d0,-(sp)
0401756E: 4879040b3444             pea     (unk_40B3444).l
04017574: 61ff0000006a             bsr.l   _vfs_putnum
0401757A: 4e5e                     unlk    a6
0401757C: 4e75                     rts

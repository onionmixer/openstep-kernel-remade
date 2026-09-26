0400452A: 4856                     pea     (a6)
0400452C: 2c4f                     movea.l sp,a6
0400452E: 41f9040b59c4             lea     (_file_list).l,a0
04004534: 23c8040b59c8             move.l  a0,(dword_40B59C8).l
0400453A: 2088                     move.l  a0,(a0)
0400453C: 4879040a5de4             pea     (aFileStructs).l; "file structs"
04004542: 42a7                     clr.l   -(sp)
04004544: 42a7                     clr.l   -(sp)
04004546: 7222                     moveq   #$22,d1 ; '"'
04004548: 4c391800040ae120         muls.l  (_max_file).l,d1
04004550: 2f01                     move.l  d1,-(sp)
04004552: 48780022                 pea     ($22).w
04004556: 61ff00050a8a             bsr.l   _zinit
0400455C: 23c0040b6068             move.l  d0,(_file_zone).l
04004562: 4e5e                     unlk    a6
04004564: 4e75                     rts

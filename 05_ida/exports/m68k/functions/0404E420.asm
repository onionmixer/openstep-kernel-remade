0404E420: 4856                     pea     (a6)
0404E422: 2c4f                     movea.l sp,a6
0404E424: 2f02                     move.l  d2,-(sp)
0404E426: 203c3b9aca00             move.l  #$3B9ACA00,d0
0404E42C: 4c790800040af7e4         divs.l  (_hz).l,d0
0404E434: 2200                     move.l  d0,d1
0404E436: 5bc0                     smi     d0
0404E438: 49c0                     extb.l  d0
0404E43A: 23c0040c2444             move.l  d0,(_ns_per_tick).l
0404E440: 23c1040c2448             move.l  d1,(dword_40C2448).l
0404E446: 2f01                     move.l  d1,-(sp)
0404E448: 2f00                     move.l  d0,-(sp)
0404E44A: 61ff00043a56             bsr.l   _hardclock_init
0404E450: 242efffc                 move.l  -4(a6),d2
0404E454: 4e5e                     unlk    a6
0404E456: 4e75                     rts

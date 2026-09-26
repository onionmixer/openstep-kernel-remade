0408A41A: 4856                     pea     (a6)
0408A41C: 2c4f                     movea.l sp,a6
0408A41E: 2f0a                     move.l  a2,-(sp)
0408A420: 2479040b69bc             movea.l (_mon_global).l,a2
0408A426: 61fffff76f9c             bsr.l   _curipl
0408A42C: 7202                     moveq   #2,d1
0408A42E: b280                     cmp.l   d0,d1
0408A430: 6d1a                     blt.s   loc_408A44C
0408A432: 022a00f70004             andi.b  #$F7,4(a2)
0408A438: 13fc0001040b228b         move.b  #1,(byte_40B228B).l
0408A440: 2f3c000186a0             move.l  #$186A0,-(sp)
0408A446: 61ff00007f32             bsr.l   _delay
0408A44C: 246efffc                 movea.l -4(a6),a2
0408A450: 4e5e                     unlk    a6
0408A452: 4e75                     rts

04037382: 4856                     pea     (a6)
04037384: 2c4f                     movea.l sp,a6
04037386: 2f0a                     move.l  a2,-(sp)
04037388: 246e0008                 movea.l 8(a6),a2
0403738C: 48780026                 pea     ($26).w
04037390: 2f0a                     move.l  a2,-(sp)
04037392: 61ff0005ba7e             bsr.l   _bzero
04037398: 2f0a                     move.l  a2,-(sp)
0403739A: 61fffffff9a2             bsr.l   sub_4036D3E
040373A0: 41ea000e                 lea     $E(a2),a0
040373A4: 25480012                 move.l  a0,$12(a2)
040373A8: 2088                     move.l  a0,(a0)
040373AA: 7214                     moveq   #$14,d1
040373AC: 25410016                 move.l  d1,$16(a2)
040373B0: 246efffc                 movea.l -4(a6),a2
040373B4: 4e5e                     unlk    a6
040373B6: 4e75                     rts

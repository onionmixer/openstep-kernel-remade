0401F898: 4856                     pea     (a6)
0401F89A: 2c4f                     movea.l sp,a6
0401F89C: 48e70038                 movem.l a2-a4,-(sp)
0401F8A0: 286e0008                 movea.l 8(a6),a4
0401F8A4: 266e000c                 movea.l $C(a6),a3
0401F8A8: 4878003c                 pea     ($3C).w
0401F8AC: 61ff0002a952             bsr.l   _kalloc
0401F8B2: 2440                     movea.l d0,a2
0401F8B4: 584f                     addq.w  #4,sp
0401F8B6: 4a8a                     tst.l   a2
0401F8B8: 672a                     beq.s   loc_401F8E4
0401F8BA: 4878003c                 pea     ($3C).w
0401F8BE: 2f0a                     move.l  a2,-(sp)
0401F8C0: 61ff00073550             bsr.l   _bzero
0401F8C6: 254b0008                 move.l  a3,8(a2)
0401F8CA: 254c0018                 move.l  a4,$18(a2)
0401F8CE: 2493                     move.l  (a3),(a2)
0401F8D0: 254b0004                 move.l  a3,4(a2)
0401F8D4: 2053                     movea.l (a3),a0
0401F8D6: 214a0004                 move.l  a2,4(a0)
0401F8DA: 268a                     move.l  a2,(a3)
0401F8DC: 294a0008                 move.l  a2,8(a4)
0401F8E0: 4280                     clr.l   d0
0401F8E2: 6002                     bra.s   loc_401F8E6
0401F8E4: 7037                     moveq   #$37,d0 ; '7'
0401F8E6: 4cee1c00fff4             movem.l -$C(a6),a2-a4
0401F8EC: 4e5e                     unlk    a6
0401F8EE: 4e75                     rts

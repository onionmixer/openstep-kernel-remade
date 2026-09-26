040431D2: 4856                     pea     (a6)
040431D4: 2c4f                     movea.l sp,a6
040431D6: 48e70038                 movem.l a2-a4,-(sp)
040431DA: 206e0008                 movea.l 8(a6),a0
040431DE: 286e000c                 movea.l $C(a6),a4
040431E2: 246e0010                 movea.l $10(a6),a2
040431E6: 266e0014                 movea.l $14(a6),a3
040431EA: 226e0018                 movea.l $18(a6),a1
040431EE: 24a80018                 move.l  $18(a0),(a2)
040431F2: 22a8001c                 move.l  $1C(a0),(a1)
040431F6: 21540018                 move.l  (a4),$18(a0)
040431FA: 2153001c                 move.l  (a3),$1C(a0)
040431FE: 4cee1c00fff4             movem.l -$C(a6),a2-a4
04043204: 4e5e                     unlk    a6
04043206: 4e75                     rts

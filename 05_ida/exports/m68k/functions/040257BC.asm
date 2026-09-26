040257BC: 4856                     pea     (a6)
040257BE: 2c4f                     movea.l sp,a6
040257C0: 2f0b                     move.l  a3,-(sp)
040257C2: 2f0a                     move.l  a2,-(sp)
040257C4: 266e0008                 movea.l 8(a6),a3
040257C8: 206b0018                 movea.l $18(a3),a0
040257CC: 48680022                 pea     $22(a0)
040257D0: 2f08                     move.l  a0,-(sp)
040257D2: 45f9040140d4             lea     (_sowakeup).l,a2
040257D8: 4e92                     jsr     (a2)
040257DA: 206b0018                 movea.l $18(a3),a0
040257DE: 48680038                 pea     $38(a0)
040257E2: 2f08                     move.l  a0,-(sp)
040257E4: 4e92                     jsr     (a2)
040257E6: 246efff8                 movea.l -8(a6),a2
040257EA: 266efffc                 movea.l -4(a6),a3
040257EE: 4e5e                     unlk    a6
040257F0: 4e75                     rts

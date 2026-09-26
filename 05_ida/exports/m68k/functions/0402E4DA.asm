0402E4DA: 4856                     pea     (a6)
0402E4DC: 2c4f                     movea.l sp,a6
0402E4DE: 206e0008                 movea.l 8(a6),a0
0402E4E2: 226e000c                 movea.l $C(a6),a1
0402E4E6: 20680008                 movea.l 8(a0),a0
0402E4EA: d0fc0034                 adda.w  #$34,a0 ; '4'
0402E4EE: 7202                     moveq   #2,d1
0402E4F0: 2081                     move.l  d1,(a0)
0402E4F2: 2f2e0010                 move.l  $10(a6),-(sp)
0402E4F6: 2f08                     move.l  a0,-(sp)
0402E4F8: 4e91                     jsr     (a1)
0402E4FA: 4e5e                     unlk    a6
0402E4FC: 4e75                     rts

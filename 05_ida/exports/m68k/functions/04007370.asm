04007370: 4856                     pea     (a6)
04007372: 2c4f                     movea.l sp,a6
04007374: 2f0a                     move.l  a2,-(sp)
04007376: 2079040b5648             movea.l (_active_threads).l,a0
0400737C: 22680080                 movea.l $80(a0),a1
04007380: 2079040b57d0             movea.l (_active_u).l,a0
04007386: 2050                     movea.l (a0),a0
04007388: 34680030                 movea.w $30(a0),a2
0400738C: 234a005c                 move.l  a2,$5C(a1)
04007390: 30680032                 movea.w $32(a0),a0
04007394: 23480060                 move.l  a0,$60(a1)
04007398: 246efffc                 movea.l -4(a6),a2
0400739C: 4e5e                     unlk    a6
0400739E: 4e75                     rts

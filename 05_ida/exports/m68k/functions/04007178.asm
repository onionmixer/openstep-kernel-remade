04007178: 4856                     pea     (a6)
0400717A: 2c4f                     movea.l sp,a6
0400717C: 2f0a                     move.l  a2,-(sp)
0400717E: 4878001e                 pea     ($1E).w
04007182: 61ff0004307c             bsr.l   _kalloc
04007188: 2440                     movea.l d0,a2
0400718A: 4878001e                 pea     ($1E).w
0400718E: 2f0a                     move.l  a2,-(sp)
04007190: 61ff0008bc80             bsr.l   _bzero
04007196: 4292                     clr.l   (a2)
04007198: 200a                     move.l  a2,d0
0400719A: 246efffc                 movea.l -4(a6),a2
0400719E: 4e5e                     unlk    a6
040071A0: 4e75                     rts

04012BC8: 4856                     pea     (a6)
04012BCA: 2c4f                     movea.l sp,a6
04012BCC: 206e0008                 movea.l 8(a6),a0
04012BD0: 2268000c                 movea.l $C(a0),a1
04012BD4: 42a7                     clr.l   -(sp)
04012BD6: 42a7                     clr.l   -(sp)
04012BD8: 42a7                     clr.l   -(sp)
04012BDA: 4878000a                 pea     ($A).w
04012BDE: 2f08                     move.l  a0,-(sp)
04012BE0: 2069001a                 movea.l $1A(a1),a0
04012BE4: 4e90                     jsr     (a0)
04012BE6: 4e5e                     unlk    a6
04012BE8: 4e75                     rts

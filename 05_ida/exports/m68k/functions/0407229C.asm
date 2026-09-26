0407229C: 4856                     pea     (a6)
0407229E: 2c4f                     movea.l sp,a6
040722A0: 48780001                 pea     (1).w
040722A4: 2f2e000c                 move.l  $C(a6),-(sp)
040722A8: 306e000a                 movea.w $A(a6),a0
040722AC: 2f08                     move.l  a0,-(sp)
040722AE: 61ff00000008             bsr.l   _mmrw
040722B4: 4e5e                     unlk    a6
040722B6: 4e75                     rts

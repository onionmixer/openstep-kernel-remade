04074A6C: 4856                     pea     (a6)
04074A6E: 2c4f                     movea.l sp,a6
04074A70: 4e5e                     unlk    a6
04074A72: 23df040c3e88             move.l  (sp)+,(_od_save_ra).l
04074A78: 4eb90400b358             jsr     _printf
04074A7E: 2f39040c3e88             move.l  (_od_save_ra).l,-(sp)
04074A84: 4e75                     rts

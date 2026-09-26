040571BC: 4856                     pea     (a6)
040571BE: 2c4f                     movea.l sp,a6
040571C0: 206e0008                 movea.l 8(a6),a0
040571C4: 2050                     movea.l (a0),a0
040571C6: 20280010                 move.l  $10(a0),d0
040571CA: 4e5e                     unlk    a6
040571CC: 4e75                     rts

0402939E: 4856                     pea     (a6)
040293A0: 2c4f                     movea.l sp,a6
040293A2: 2f0a                     move.l  a2,-(sp)
040293A4: 246e0008                 movea.l 8(a6),a2
040293A8: 202a006c                 move.l  $6C(a2),d0
040293AC: 670c                     beq.s   loc_40293BA
040293AE: 2f00                     move.l  d0,-(sp)
040293B0: 61fffffde894             bsr.l   _crfree
040293B6: 42aa006c                 clr.l   $6C(a2)
040293BA: 246efffc                 movea.l -4(a6),a2
040293BE: 4e5e                     unlk    a6
040293C0: 4e75                     rts

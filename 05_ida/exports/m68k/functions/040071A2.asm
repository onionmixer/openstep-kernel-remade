040071A2: 4856                     pea     (a6)
040071A4: 2c4f                     movea.l sp,a6
040071A6: 4878001e                 pea     ($1E).w
040071AA: 2f2e0008                 move.l  8(a6),-(sp)
040071AE: 61ff00043114             bsr.l   _kfree
040071B4: 4e5e                     unlk    a6
040071B6: 4e75                     rts

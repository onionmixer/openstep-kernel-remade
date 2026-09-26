040066DC: 4856                     pea     (a6)
040066DE: 2c4f                     movea.l sp,a6
040066E0: 2f0a                     move.l  a2,-(sp)
040066E2: 246e0008                 movea.l 8(a6),a2
040066E6: 4878028a                 pea     ($28A).w
040066EA: 2f2a0030                 move.l  $30(a2),-(sp)
040066EE: 61ff0008c722             bsr.l   _bzero
040066F4: 42aa0034                 clr.l   $34(a2)
040066F8: 246efffc                 movea.l -4(a6),a2
040066FC: 4e5e                     unlk    a6
040066FE: 4e75                     rts

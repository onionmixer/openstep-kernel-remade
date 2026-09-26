040384B8: 4856                     pea     (a6)
040384BA: 2c4f                     movea.l sp,a6
040384BC: 2f0a                     move.l  a2,-(sp)
040384BE: 246e0008                 movea.l 8(a6),a2
040384C2: 6016                     bra.s   loc_40384DA
040384C4: 00400010                 ori.w   #$10,d0
040384C8: 35400042                 move.w  d0,$42(a2)
040384CC: 4878000a                 pea     ($A).w
040384D0: 2f0a                     move.l  a2,-(sp)
040384D2: 61fffffd1762             bsr.l   _sleep
040384D8: 504f                     addq.w  #8,sp
040384DA: 302a0042                 move.w  $42(a2),d0
040384DE: 08000000                 btst    #0,d0
040384E2: 66e0                     bne.s   loc_40384C4
040384E4: 006a00010042             ori.w   #1,$42(a2)
040384EA: 246efffc                 movea.l -4(a6),a2
040384EE: 4e5e                     unlk    a6
040384F0: 4e75                     rts

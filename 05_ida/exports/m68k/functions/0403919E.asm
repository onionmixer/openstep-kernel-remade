0403919E: 4856                     pea     (a6)
040391A0: 2c4f                     movea.l sp,a6
040391A2: 2f0a                     move.l  a2,-(sp)
040391A4: 246e0008                 movea.l 8(a6),a2
040391A8: 202e000c                 move.l  $C(a6),d0
040391AC: b0aa0024                 cmp.l   $24(a2),d0
040391B0: 6404                     bcc.s   loc_40391B6
040391B2: 4280                     clr.l   d0
040391B4: 601e                     bra.s   loc_40391D4
040391B6: 2f00                     move.l  d0,-(sp)
040391B8: 4879040a817b             pea     (aBadBlockD).l; "bad block %d, "
040391BE: 61fffffd2198             bsr.l   _printf
040391C4: 4879040a818a             pea     (aBadBlock).l; "bad block"
040391CA: 2f0a                     move.l  a2,-(sp)
040391CC: 61ffffffbdfe             bsr.l   _fserr
040391D2: 7001                     moveq   #1,d0
040391D4: 246efffc                 movea.l -4(a6),a2
040391D8: 4e5e                     unlk    a6
040391DA: 4e75                     rts

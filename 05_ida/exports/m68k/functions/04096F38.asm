04096F38: 4856                     pea     (a6)
04096F3A: 2c4f                     movea.l sp,a6
04096F3C: 2f0a                     move.l  a2,-(sp)
04096F3E: 2f02                     move.l  d2,-(sp)
04096F40: 43f9040c9840             lea     (_protection_codes).l,a1
04096F46: 247c04096f5c             movea.l #$4096F5C,a2
04096F4C: 203c04096f78             move.l  #$4096F78,d0
04096F52: 2200                     move.l  d0,d1
04096F54: b28a                     cmp.l   a2,d1
04096F56: 652c                     bcs.s   loc_4096F84
04096F58: 2052                     movea.l (a2),a0
04096F5A: 4ed0                     jmp     (a0)
04096F5C: 04096f82                 subi.b  #$82,a1
04096F60: 04096f7c                 subi.b  #$7C,a1 ; '|'
04096F64: 04096f82                 subi.b  #$82,a1
04096F68: 04096f82                 subi.b  #$82,a1
04096F6C: 04096f7c                 subi.b  #$7C,a1 ; '|'
04096F70: 04096f7c                 subi.b  #$7C,a1 ; '|'
04096F74: 04096f82                 subi.b  #$82,a1
04096F78: 04096f82                 subi.b  #$82,a1
04096F7C: 7401                     moveq   #1,d2
04096F7E: 22c2                     move.l  d2,(a1)+
04096F80: 6002                     bra.s   loc_4096F84
04096F82: 4299                     clr.l   (a1)+
04096F84: 584a                     addq.w  #4,a2
04096F86: b08a                     cmp.l   a2,d0
04096F88: 6cca                     bge.s   loc_4096F54
04096F8A: 242efff8                 move.l  -8(a6),d2
04096F8E: 246efffc                 movea.l -4(a6),a2
04096F92: 4e5e                     unlk    a6
04096F94: 4e75                     rts

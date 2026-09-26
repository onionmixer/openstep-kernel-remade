04054B72: 4856                     pea     (a6)
04054B74: 2c4f                     movea.l sp,a6
04054B76: 48e72030                 movem.l d2/a2-a3,-(sp)
04054B7A: 47f9040c2b84             lea     (_kernel_timer).l,a3
04054B80: 243c040c2b80             move.l  #$40C2B80,d2
04054B86: 2442                     movea.l d2,a2
04054B88: 2f0b                     move.l  a3,-(sp)
04054B8A: 61ff0000001a             bsr.l   _timer_init
04054B90: 429a                     clr.l   (a2)+
04054B92: 584f                     addq.w  #4,sp
04054B94: 504b                     addq.w  #8,a3
04054B96: 504b                     addq.w  #8,a3
04054B98: b48a                     cmp.l   a2,d2
04054B9A: 6cec                     bge.s   loc_4054B88
04054B9C: 4cee0c04fff4             movem.l -$C(a6),d2/a2-a3
04054BA2: 4e5e                     unlk    a6
04054BA4: 4e75                     rts

04015BE4: 4856                     pea     (a6)
04015BE6: 2c4f                     movea.l sp,a6
04015BE8: 48e72030                 movem.l d2/a2-a3,-(sp)
04015BEC: 266e0008                 movea.l 8(a6),a3
04015BF0: 242e0010                 move.l  $10(a6),d2
04015BF4: 7270                     moveq   #$70,d1 ; 'p'
04015BF6: b282                     cmp.l   d2,d1
04015BF8: 6c04                     bge.s   loc_4015BFE
04015BFA: 7016                     moveq   #$16,d0
04015BFC: 6048                     bra.s   loc_4015C46
04015BFE: 2f2e0014                 move.l  $14(a6),-(sp)
04015C02: 48780001                 pea     (1).w
04015C06: 61ffffffc35c             bsr.l   _m_get
04015C0C: 2440                     movea.l d0,a2
04015C0E: 504f                     addq.w  #8,sp
04015C10: 4a8a                     tst.l   a2
04015C12: 6604                     bne.s   loc_4015C18
04015C14: 7037                     moveq   #$37,d0 ; '7'
04015C16: 602e                     bra.s   loc_4015C46
04015C18: 35420008                 move.w  d2,8(a2)
04015C1C: 2f02                     move.l  d2,-(sp)
04015C1E: 220a                     move.l  a2,d1
04015C20: d2aa0004                 add.l   4(a2),d1
04015C24: 2f01                     move.l  d1,-(sp)
04015C26: 2f2e000c                 move.l  $C(a6),-(sp)
04015C2A: 61fffffebaa4             bsr.l   _copyinmsg
04015C30: 2400                     move.l  d0,d2
04015C32: 504f                     addq.w  #8,sp
04015C34: 584f                     addq.w  #4,sp
04015C36: 670a                     beq.s   loc_4015C42
04015C38: 2f0a                     move.l  a2,-(sp)
04015C3A: 61ffffffc426             bsr.l   _m_free
04015C40: 6002                     bra.s   loc_4015C44
04015C42: 268a                     move.l  a2,(a3)
04015C44: 2002                     move.l  d2,d0
04015C46: 4cee0c04fff4             movem.l -$C(a6),d2/a2-a3
04015C4C: 4e5e                     unlk    a6
04015C4E: 4e75                     rts

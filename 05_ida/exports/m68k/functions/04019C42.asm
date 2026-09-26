04019C42: 4856                     pea     (a6)
04019C44: 2c4f                     movea.l sp,a6
04019C46: 2f0a                     move.l  a2,-(sp)
04019C48: 2f02                     move.l  d2,-(sp)
04019C4A: 246e0008                 movea.l 8(a6),a2
04019C4E: 206e000c                 movea.l $C(a6),a0
04019C52: 226a0004                 movea.l 4(a2),a1
04019C56: 222a0008                 move.l  8(a2),d1
04019C5A: 7400                     moveq   #0,d2
04019C5C: 4602                     not.b   d2
04019C5E: 4a81                     tst.l   d1
04019C60: 6f1a                     ble.s   loc_4019C7C
04019C62: 1011                     move.b  (a1),d0
04019C64: 0c00002f                 cmpi.b  #$2F,d0 ; '/'
04019C68: 6712                     beq.s   loc_4019C7C
04019C6A: 5382                     subq.l  #1,d2
04019C6C: 6a04                     bpl.s   loc_4019C72
04019C6E: 703f                     moveq   #$3F,d0 ; '?'
04019C70: 6016                     bra.s   loc_4019C88
04019C72: 5249                     addq.w  #1,a1
04019C74: 10c0                     move.b  d0,(a0)+
04019C76: 5381                     subq.l  #1,d1
04019C78: 4a81                     tst.l   d1
04019C7A: 6ee6                     bgt.s   loc_4019C62
04019C7C: 25490004                 move.l  a1,4(a2)
04019C80: 25410008                 move.l  d1,8(a2)
04019C84: 4210                     clr.b   (a0)
04019C86: 4280                     clr.l   d0
04019C88: 242efff8                 move.l  -8(a6),d2
04019C8C: 246efffc                 movea.l -4(a6),a2
04019C90: 4e5e                     unlk    a6
04019C92: 4e75                     rts

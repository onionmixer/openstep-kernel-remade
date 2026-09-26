04012CF2: 4856                     pea     (a6)
04012CF4: 2c4f                     movea.l sp,a6
04012CF6: 2f02                     move.l  d2,-(sp)
04012CF8: 226e0008                 movea.l 8(a6),a1
04012CFC: 40c0                     move    sr,d0
04012CFE: 46fc2200                 move    #$2200,sr
04012D02: 3400                     move.w  d0,d2
04012D04: 48c2                     ext.l   d2
04012D06: 30290006                 move.w  6(a1),d0
04012D0A: 08000001                 btst    #1,d0
04012D0E: 6604                     bne.s   loc_4012D14
04012D10: 7239                     moveq   #$39,d1 ; '9'
04012D12: 6022                     bra.s   loc_4012D36
04012D14: 08000003                 btst    #3,d0
04012D18: 6704                     beq.s   loc_4012D1E
04012D1A: 7225                     moveq   #$25,d1 ; '%'
04012D1C: 6018                     bra.s   loc_4012D36
04012D1E: 2069000c                 movea.l $C(a1),a0
04012D22: 42a7                     clr.l   -(sp)
04012D24: 42a7                     clr.l   -(sp)
04012D26: 42a7                     clr.l   -(sp)
04012D28: 48780006                 pea     (6).w
04012D2C: 2f09                     move.l  a1,-(sp)
04012D2E: 2068001a                 movea.l $1A(a0),a0
04012D32: 4e90                     jsr     (a0)
04012D34: 2200                     move.l  d0,d1
04012D36: 40c0                     move    sr,d0
04012D38: 46c2                     move    d2,sr
04012D3A: 2001                     move.l  d1,d0
04012D3C: 242efffc                 move.l  -4(a6),d2
04012D40: 4e5e                     unlk    a6
04012D42: 4e75                     rts

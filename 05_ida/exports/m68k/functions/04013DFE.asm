04013DFE: 4856                     pea     (a6)
04013E00: 2c4f                     movea.l sp,a6
04013E02: 2f0b                     move.l  a3,-(sp)
04013E04: 2f0a                     move.l  a2,-(sp)
04013E06: 246e0008                 movea.l 8(a6),a2
04013E0A: 302a0006                 move.w  6(a2),d0
04013E0E: 0240fff1                 andi.w  #$FFF1,d0
04013E12: 00400030                 ori.w   #$30,d0 ; '0'
04013E16: 35400006                 move.w  d0,6(a2)
04013E1A: 486a004e                 pea     $4E(a2)
04013E1E: 61ffffff63e2             bsr.l   _wakeup
04013E24: 486a0038                 pea     $38(a2)
04013E28: 2f0a                     move.l  a2,-(sp)
04013E2A: 47f9040140d4             lea     (_sowakeup).l,a3
04013E30: 4e93                     jsr     (a3)
04013E32: 486a0022                 pea     $22(a2)
04013E36: 2f0a                     move.l  a2,-(sp)
04013E38: 4e93                     jsr     (a3)
04013E3A: 246efff8                 movea.l -8(a6),a2
04013E3E: 266efffc                 movea.l -4(a6),a3
04013E42: 4e5e                     unlk    a6
04013E44: 4e75                     rts

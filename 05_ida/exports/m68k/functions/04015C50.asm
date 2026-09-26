04015C50: 4856                     pea     (a6)
04015C52: 2c4f                     movea.l sp,a6
04015C54: 2f2e0008                 move.l  8(a6),-(sp)
04015C58: 61fffffee980             bsr.l   _getf
04015C5E: 2040                     movea.l d0,a0
04015C60: 4a88                     tst.l   a0
04015C62: 6718                     beq.s   loc_4015C7C
04015C64: 0c680002000c             cmpi.w  #2,$C(a0)
04015C6A: 6604                     bne.s   loc_4015C70
04015C6C: 2008                     move.l  a0,d0
04015C6E: 600e                     bra.s   loc_4015C7E
04015C70: 2079040b57d4             movea.l (dword_40B57D4).l,a0
04015C76: 117c00260064             move.b  #$26,$64(a0) ; '&'
04015C7C: 4280                     clr.l   d0
04015C7E: 4e5e                     unlk    a6
04015C80: 4e75                     rts

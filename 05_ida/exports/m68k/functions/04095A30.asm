04095A30: 4856                     pea     (a6)
04095A32: 2c4f                     movea.l sp,a6
04095A34: 2039040c9474             move.l  (dword_40C9474).l,d0
04095A3A: 4a80                     tst.l   d0
04095A3C: 6602                     bne.s   loc_4095A40
04095A3E: 6022                     bra.s   loc_4095A60+2
04095A40: 206e0008                 movea.l 8(a6),a0
04095A44: 2028002e                 move.l  $2E(a0),d0
04095A48: 7211                     moveq   #$11,d1
04095A4A: b280                     cmp.l   d0,d1
04095A4C: 6702                     beq.s   loc_4095A50
04095A4E: 6012                     bra.s   loc_4095A60+2
04095A50: 23ee0008040c977c         move.l  8(a6),(_dbg_connect_pkt).l
04095A58: 7201                     moveq   #1,d1
04095A5A: 23c1040b562c             move.l  d1,(dword_40B562C).l
04095A60: 4e4f4e5e                 trap    #$F
04095A64: 4e75                     rts

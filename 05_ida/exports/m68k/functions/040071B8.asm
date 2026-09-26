040071B8: 4856                     pea     (a6)
040071BA: 2c4f                     movea.l sp,a6
040071BC: 226e0008                 movea.l 8(a6),a1
040071C0: 222e000c                 move.l  $C(a6),d1
040071C4: 703f                     moveq   #$3F,d0 ; '?'
040071C6: c081                     and.l   d1,d0
040071C8: 41f9040b5f04             lea     (_posix_proc_hash).l,a0
040071CE: 20700c00                 movea.l (a0,d0.l*4),a0
040071D2: 4a88                     tst.l   a0
040071D4: 6710                     beq.s   loc_40071E6
040071D6: b290                     cmp.l   (a0),d1
040071D8: 6604                     bne.s   loc_40071DE
040071DA: 4280                     clr.l   d0
040071DC: 6020                     bra.s   loc_40071FE
040071DE: 2068001a                 movea.l $1A(a0),a0
040071E2: 4a88                     tst.l   a0
040071E4: 66f0                     bne.s   loc_40071D6
040071E6: 2281                     move.l  d1,(a1)
040071E8: 703f                     moveq   #$3F,d0 ; '?'
040071EA: c081                     and.l   d1,d0
040071EC: 41f9040b5f04             lea     (_posix_proc_hash).l,a0
040071F2: 23700c00001a             move.l  (a0,d0.l*4),$1A(a1)
040071F8: 21890c00                 move.l  a1,(a0,d0.l*4)
040071FC: 7001                     moveq   #1,d0
040071FE: 4e5e                     unlk    a6
04007200: 4e75                     rts

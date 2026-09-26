040481CE: 4856                     pea     (a6)
040481D0: 2c4f                     movea.l sp,a6
040481D2: 202e000c                 move.l  $C(a6),d0
040481D6: 206e0010                 movea.l $10(a6),a0
040481DA: 4aae0008                 tst.l   8(a6)
040481DE: 6704                     beq.s   loc_40481E4
040481E0: 4a80                     tst.l   d0
040481E2: 6606                     bne.s   loc_40481EA
040481E4: 4290                     clr.l   (a0)
040481E6: 7004                     moveq   #4,d0
040481E8: 600c                     bra.s   loc_40481F6
040481EA: 2080                     move.l  d0,(a0)
040481EC: 2f00                     move.l  d0,-(sp)
040481EE: 61ff000070f4             bsr.l   _pset_reference
040481F4: 4280                     clr.l   d0
040481F6: 4e5e                     unlk    a6
040481F8: 4e75                     rts

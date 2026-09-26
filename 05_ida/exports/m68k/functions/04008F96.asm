04008F96: 4856                     pea     (a6)
04008F98: 2c4f                     movea.l sp,a6
04008F9A: 202e0008                 move.l  8(a6),d0
04008F9E: 671c                     beq.s   loc_4008FBC
04008FA0: 2f00                     move.l  d0,-(sp)
04008FA2: 61ffffffdda6             bsr.l   _pgfind
04008FA8: 584f                     addq.w  #4,sp
04008FAA: 4a80                     tst.l   d0
04008FAC: 670e                     beq.s   loc_4008FBC
04008FAE: 42a7                     clr.l   -(sp)
04008FB0: 2f2e000c                 move.l  $C(a6),-(sp)
04008FB4: 2f00                     move.l  d0,-(sp)
04008FB6: 61ff00000008             bsr.l   _pgsignal
04008FBC: 4e5e                     unlk    a6
04008FBE: 4e75                     rts

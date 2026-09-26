040803EA: 4856                     pea     (a6)
040803EC: 2c4f                     movea.l sp,a6
040803EE: 42a7                     clr.l   -(sp)
040803F0: 487904080388             pea     (sub_4080388).l
040803F6: 48780004                 pea     (4).w
040803FA: 61ff00013a84             bsr.l   _callout_dispatch
04080400: 4e5e                     unlk    a6
04080402: 4e75                     rts

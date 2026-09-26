040301C6: 4856                     pea     (a6)
040301C8: 2c4f                     movea.l sp,a6
040301CA: 206e000c                 movea.l $C(a6),a0
040301CE: 48780400                 pea     ($400).w
040301D2: 2f08                     move.l  a0,-(sp)
040301D4: 48680004                 pea     4(a0)
040301D8: 2f2e0008                 move.l  8(a6),-(sp)
040301DC: 61ffffffff40             bsr.l   _xdr_bytes
040301E2: 4e5e                     unlk    a6
040301E4: 4e75                     rts

04025F4C: 4856                     pea     (a6)
04025F4E: 2c4f                     movea.l sp,a6
04025F50: 206e0008                 movea.l 8(a6),a0
04025F54: 20b9040b7bb4             move.l  (_in_ifaddr).l,(a0)
04025F5A: 42a80004                 clr.l   4(a0)
04025F5E: 2f08                     move.l  a0,-(sp)
04025F60: 61ffffffffb4             bsr.l   sub_4025F16
04025F66: 4e5e                     unlk    a6
04025F68: 4e75                     rts

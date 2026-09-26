04006692: 4856                     pea     (a6)
04006694: 2c4f                     movea.l sp,a6
04006696: 2f2e0008                 move.l  8(a6),-(sp)
0400669A: 2f39040b6530             move.l  (_u_thread_zone).l,-(sp)
040066A0: 61ff0004f55a             bsr.l   _zfree
040066A6: 4e5e                     unlk    a6
040066A8: 4e75                     rts

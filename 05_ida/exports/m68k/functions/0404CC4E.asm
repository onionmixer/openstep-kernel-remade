0404CC4E: 4856                     pea     (a6)
0404CC50: 2c4f                     movea.l sp,a6
0404CC52: 2f2e0008                 move.l  8(a6),-(sp)
0404CC56: 2f39040c2398             move.l  (_mach_net_kmsg_zone).l,-(sp)
0404CC5C: 61ff00008f9e             bsr.l   _zfree
0404CC62: 4e5e                     unlk    a6
0404CC64: 4e75                     rts

0402F55C: 4856                     pea     (a6)
0402F55E: 2c4f                     movea.l sp,a6
0402F560: 48780005                 pea     (5).w
0402F564: 2f2e0008                 move.l  8(a6),-(sp)
0402F568: 61ffffffffc2             bsr.l   _svcerr_auth
0402F56E: 4e5e                     unlk    a6
0402F570: 4e75                     rts

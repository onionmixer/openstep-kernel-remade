0406232C: 4856                     pea     (a6)
0406232E: 2c4f                     movea.l sp,a6
04062330: 48780001                 pea     (1).w
04062334: 4879040c23c4             pea     (_vm_alloc_lock).l
0406233A: 61fffffe8830             bsr.l   _lock_init
04062340: 4e5e                     unlk    a6
04062342: 4e75                     rts

04010140: 4856                     pea     (a6)
04010142: 2c4f                     movea.l sp,a6
04010144: 48780001                 pea     (1).w
04010148: 4879040b6a6c             pea     (_pty_alloc_lock).l
0401014E: 61ff0003aa1c             bsr.l   _lock_init
04010154: 4e5e                     unlk    a6
04010156: 4e75                     rts

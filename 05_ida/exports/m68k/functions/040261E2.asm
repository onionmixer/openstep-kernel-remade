040261E2: 4856                     pea     (a6)
040261E4: 2c4f                     movea.l sp,a6
040261E6: 2f0a                     move.l  a2,-(sp)
040261E8: 246e0008                 movea.l 8(a6),a2
040261EC: 2f2e000c                 move.l  $C(a6),-(sp)
040261F0: 2f0a                     move.l  a2,-(sp)
040261F2: 61ff0000630e             bsr.l   _sync_vp_invalidate
040261F8: 2f0a                     move.l  a2,-(sp)
040261FA: 61ff0003d580             bsr.l   _vnode_uncache
04026200: 206a002e                 movea.l $2E(a2),a0
04026204: 42a800b6                 clr.l   $B6(a0)
04026208: 2f0a                     move.l  a2,-(sp)
0402620A: 61ffffff286a             bsr.l   _dnlc_purge_vp
04026210: 2f0a                     move.l  a2,-(sp)
04026212: 61ffffff218a             bsr.l   _binvalfree
04026218: 246efffc                 movea.l -4(a6),a2
0402621C: 4e5e                     unlk    a6
0402621E: 4e75                     rts

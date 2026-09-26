040261A8: 4856                     pea     (a6)
040261AA: 2c4f                     movea.l sp,a6
040261AC: 2f0a                     move.l  a2,-(sp)
040261AE: 246e0008                 movea.l 8(a6),a2
040261B2: 2f0a                     move.l  a2,-(sp)
040261B4: 61ff0003d5c6             bsr.l   _vnode_uncache
040261BA: 2f0a                     move.l  a2,-(sp)
040261BC: 61ff000279fa             bsr.l   _mfs_invalidate
040261C2: 206a002e                 movea.l $2E(a2),a0
040261C6: 42a800b6                 clr.l   $B6(a0)
040261CA: 2f0a                     move.l  a2,-(sp)
040261CC: 61ffffff28a8             bsr.l   _dnlc_purge_vp
040261D2: 2f0a                     move.l  a2,-(sp)
040261D4: 61ffffff21c8             bsr.l   _binvalfree
040261DA: 246efffc                 movea.l -4(a6),a2
040261DE: 4e5e                     unlk    a6
040261E0: 4e75                     rts

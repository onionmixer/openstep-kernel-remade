040608BE: 4856                     pea     (a6)
040608C0: 2c4f                     movea.l sp,a6
040608C2: 2f0a                     move.l  a2,-(sp)
040608C4: 2f02                     move.l  d2,-(sp)
040608C6: 246e0008                 movea.l 8(a6),a2
040608CA: 242e000c                 move.l  $C(a6),d2
040608CE: 4a8a                     tst.l   a2
040608D0: 660e                     bne.s   loc_40608E0
040608D2: 4879040a98b7             pea     (aVmPagerPutNull).l; "vm_pager_put: null pager"
040608D8: 61fffffab38c             bsr.l   _panic
040608DE: 584f                     addq.w  #4,sp
040608E0: 4a92                     tst.l   (a2)
040608E2: 660a                     bne.s   loc_40608EE
040608E4: 2f02                     move.l  d2,-(sp)
040608E6: 61ff00002642             bsr.l   _vnode_pageout
040608EC: 6008                     bra.s   loc_40608F6
040608EE: 2f02                     move.l  d2,-(sp)
040608F0: 61ff0000188a             bsr.l   _device_pageout
040608F6: 242efff8                 move.l  -8(a6),d2
040608FA: 246efffc                 movea.l -4(a6),a2
040608FE: 4e5e                     unlk    a6
04060900: 4e75                     rts

04060902: 4856                     pea     (a6)
04060904: 2c4f                     movea.l sp,a6
04060906: 2f0a                     move.l  a2,-(sp)
04060908: 246e0008                 movea.l 8(a6),a2
0406090C: 4a8a                     tst.l   a2
0406090E: 660e                     bne.s   loc_406091E
04060910: 4879040a98d0             pea     (aVmPagerDealloc).l; "vm_pager_deallocate: null pager"
04060916: 61fffffab34e             bsr.l   _panic
0406091C: 584f                     addq.w  #4,sp
0406091E: 4a92                     tst.l   (a2)
04060920: 660a                     bne.s   loc_406092C
04060922: 2f0a                     move.l  a2,-(sp)
04060924: 61ff00002d08             bsr.l   _vnode_dealloc
0406092A: 6008                     bra.s   loc_4060934
0406092C: 2f0a                     move.l  a2,-(sp)
0406092E: 61ff00001860             bsr.l   _device_dealloc
04060934: 246efffc                 movea.l -4(a6),a2
04060938: 4e5e                     unlk    a6
0406093A: 4e75                     rts

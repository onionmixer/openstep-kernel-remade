0406094E: 4856                     pea     (a6)
04060950: 2c4f                     movea.l sp,a6
04060952: 2f0a                     move.l  a2,-(sp)
04060954: 246e0008                 movea.l 8(a6),a2
04060958: 4a8a                     tst.l   a2
0406095A: 6704                     beq.s   loc_4060960
0406095C: 4a92                     tst.l   (a2)
0406095E: 670e                     beq.s   loc_406096E
04060960: 4879040a98f0             pea     (aVmPagerHasPage).l; "vm_pager_has_page"
04060966: 61fffffab2fe             bsr.l   _panic
0406096C: 584f                     addq.w  #4,sp
0406096E: 2f2e000c                 move.l  $C(a6),-(sp)
04060972: 2f0a                     move.l  a2,-(sp)
04060974: 61ff000026c4             bsr.l   _vnode_has_page
0406097A: 246efffc                 movea.l -4(a6),a2
0406097E: 4e5e                     unlk    a6
04060980: 4e75                     rts

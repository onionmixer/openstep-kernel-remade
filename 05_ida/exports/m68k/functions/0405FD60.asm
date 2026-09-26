0405FD60: 4856                     pea     (a6)
0405FD62: 2c4f                     movea.l sp,a6
0405FD64: 2f0a                     move.l  a2,-(sp)
0405FD66: 6030                     bra.s   loc_405FD98
0405FD68: 2479040c2da0             movea.l (_vm_object_cached_list).l,a2
0405FD6E: 2f2a0024                 move.l  $24(a2),-(sp)
0405FD72: 61ff0000028e             bsr.l   _vm_object_lookup
0405FD78: 584f                     addq.w  #4,sp
0405FD7A: b08a                     cmp.l   a2,d0
0405FD7C: 670e                     beq.s   loc_405FD8C
0405FD7E: 4879040a97be             pea     (aVmObjectDeacti).l; "vm_object_deactivate: I'm sooo confused"...
0405FD84: 61fffffabee0             bsr.l   _panic
0405FD8A: 584f                     addq.w  #4,sp
0405FD8C: 42a7                     clr.l   -(sp)
0405FD8E: 2f0a                     move.l  a2,-(sp)
0405FD90: 61ff0000001c             bsr.l   _vm_object_cache_object
0405FD96: 504f                     addq.w  #8,sp
0405FD98: 2239040c2d9c             move.l  (_vm_object_cached).l,d1
0405FD9E: b2b9040c2d98             cmp.l   (_vm_cache_max).l,d1
0405FDA4: 6ec2                     bgt.s   loc_405FD68
0405FDA6: 246efffc                 movea.l -4(a6),a2
0405FDAA: 4e5e                     unlk    a6
0405FDAC: 4e75                     rts

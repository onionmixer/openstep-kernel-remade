0406014C: 4856                     pea     (a6)
0406014E: 2c4f                     movea.l sp,a6
04060150: 2f0b                     move.l  a3,-(sp)
04060152: 2f0a                     move.l  a2,-(sp)
04060154: 41f9040c2da0             lea     (_vm_object_cached_list).l,a0
0406015A: b1d0                     cmpa.l  (a0),a0
0406015C: 6732                     beq.s   loc_4060190
0406015E: 2648                     movea.l a0,a3
04060160: 2453                     movea.l (a3),a2
04060162: 2f2a0024                 move.l  $24(a2),-(sp)
04060166: 61fffffffe9a             bsr.l   _vm_object_lookup
0406016C: 584f                     addq.w  #4,sp
0406016E: b08a                     cmp.l   a2,d0
04060170: 670e                     beq.s   loc_4060180
04060172: 4879040a983b             pea     (aVmObjectCacheC).l; "vm_object_cache_clear: I'm sooo confuse"...
04060178: 61fffffabaec             bsr.l   _panic
0406017E: 584f                     addq.w  #4,sp
04060180: 42a7                     clr.l   -(sp)
04060182: 2f0a                     move.l  a2,-(sp)
04060184: 61fffffffc28             bsr.l   _vm_object_cache_object
0406018A: 504f                     addq.w  #8,sp
0406018C: b7d3                     cmpa.l  (a3),a3
0406018E: 66d0                     bne.s   loc_4060160
04060190: 246efff8                 movea.l -8(a6),a2
04060194: 266efffc                 movea.l -4(a6),a3
04060198: 4e5e                     unlk    a6
0406019A: 4e75                     rts

0404AA5E: 4856                     pea     (a6)
0404AA60: 2c4f                     movea.l sp,a6
0404AA62: 2f02                     move.l  d2,-(sp)
0404AA64: 61fffffffc34             bsr.l   _allocStack
0404AA6A: 2400                     move.l  d0,d2
0404AA6C: 660e                     bne.s   loc_404AA7C
0404AA6E: 4879040a8953             pea     (aStackAlloc).l; "stack_alloc"
0404AA74: 61fffffc11f0             bsr.l   _panic
0404AA7A: 584f                     addq.w  #4,sp
0404AA7C: 2f2e000c                 move.l  $C(a6),-(sp)
0404AA80: 2f02                     move.l  d2,-(sp)
0404AA82: 2f2e0008                 move.l  8(a6),-(sp)
0404AA86: 61ff0004bd36             bsr.l   _stack_attach
0404AA8C: 242efffc                 move.l  -4(a6),d2
0404AA90: 4e5e                     unlk    a6
0404AA92: 4e75                     rts

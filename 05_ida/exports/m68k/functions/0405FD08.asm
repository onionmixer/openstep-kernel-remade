0405FD08: 4856                     pea     (a6)
0405FD0A: 2c4f                     movea.l sp,a6
0405FD0C: 2f2e0008                 move.l  8(a6),-(sp)
0405FD10: 61ff000002f0             bsr.l   _vm_object_lookup
0405FD16: 584f                     addq.w  #4,sp
0405FD18: 4a80                     tst.l   d0
0405FD1A: 6708                     beq.s   loc_405FD24
0405FD1C: 2f00                     move.l  d0,-(sp)
0405FD1E: 61fffffffdf8             bsr.l   _vm_object_deallocate
0405FD24: 4e5e                     unlk    a6
0405FD26: 4e75                     rts

04042EB2: 4856                     pea     (a6)
04042EB4: 2c4f                     movea.l sp,a6
04042EB6: 2f0a                     move.l  a2,-(sp)
04042EB8: 226e0008                 movea.l 8(a6),a1
04042EBC: 2051                     movea.l (a1),a0
04042EBE: 45e8ffff                 lea     -1(a0),a2
04042EC2: 228a                     move.l  a2,(a1)
04042EC4: 7001                     moveq   #1,d0
04042EC6: b088                     cmp.l   a0,d0
04042EC8: 660e                     bne.s   loc_4042ED8
04042ECA: 2f09                     move.l  a1,-(sp)
04042ECC: 2f39040c21ec             move.l  (_ipc_space_zone).l,-(sp)
04042ED2: 61ff00012d28             bsr.l   _zfree
04042ED8: 246efffc                 movea.l -4(a6),a2
04042EDC: 4e5e                     unlk    a6
04042EDE: 4e75                     rts

040062D6: 4856                     pea     (a6)
040062D8: 2c4f                     movea.l sp,a6
040062DA: 2f02                     move.l  d2,-(sp)
040062DC: 242e0008                 move.l  8(a6),d2
040062E0: 61ff00000e96             bsr.l   _alloc_posix_proc
040062E6: 2f00                     move.l  d0,-(sp)
040062E8: 2f02                     move.l  d2,-(sp)
040062EA: 2079040b57d0             movea.l (_active_u).l,a0
040062F0: 2f10                     move.l  (a0),-(sp)
040062F2: 61ff0000000c             bsr.l   _cloneproc
040062F8: 242efffc                 move.l  -4(a6),d2
040062FC: 4e5e                     unlk    a6
040062FE: 4e75                     rts

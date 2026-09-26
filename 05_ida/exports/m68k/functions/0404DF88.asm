0404DF88: 4856                     pea     (a6)
0404DF8A: 2c4f                     movea.l sp,a6
0404DF8C: 2f0a                     move.l  a2,-(sp)
0404DF8E: 246e0008                 movea.l 8(a6),a2
0404DF92: 2f0a                     move.l  a2,-(sp)
0404DF94: 61fffffff684             bsr.l   _mfs_uncache
0404DF9A: 2f12                     move.l  (a2),-(sp)
0404DF9C: 2f39040b611c             move.l  (_vm_info_zone).l,-(sp)
0404DFA2: 61ff00007c58             bsr.l   _zfree
0404DFA8: 246efffc                 movea.l -4(a6),a2
0404DFAC: 4e5e                     unlk    a6
0404DFAE: 4e75                     rts

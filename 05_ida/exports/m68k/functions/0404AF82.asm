0404AF82: 4856                     pea     (a6)
0404AF84: 2c4f                     movea.l sp,a6
0404AF86: 2f0a                     move.l  a2,-(sp)
0404AF88: 246e0008                 movea.l 8(a6),a2
0404AF8C: 082a00060006             btst    #6,6(a2)
0404AF92: 660c                     bne.s   loc_404AFA0
0404AF94: 4879040a895f             pea     (aLockSetRecursi).l; "lock_set_recursive: don't have write lo"...
0404AF9A: 61fffffc0cca             bsr.l   _panic
0404AFA0: 24b9040b5648             move.l  (_active_threads).l,(a2)
0404AFA6: 246efffc                 movea.l -4(a6),a2
0404AFAA: 4e5e                     unlk    a6
0404AFAC: 4e75                     rts

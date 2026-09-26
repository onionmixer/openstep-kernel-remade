0404AFAE: 4856                     pea     (a6)
0404AFB0: 2c4f                     movea.l sp,a6
0404AFB2: 2f0a                     move.l  a2,-(sp)
0404AFB4: 246e0008                 movea.l 8(a6),a2
0404AFB8: 2212                     move.l  (a2),d1
0404AFBA: b2b9040b5648             cmp.l   (_active_threads).l,d1
0404AFC0: 670c                     beq.s   loc_404AFCE
0404AFC2: 4879040a8989             pea     (aLockClearRecur).l; "lock_clear_recursive: wrong thread"
0404AFC8: 61fffffc0c9c             bsr.l   _panic
0404AFCE: e8ea010c0006             bftst   6(a2){4:12}
0404AFD4: 6604                     bne.s   loc_404AFDA
0404AFD6: 72ff                     moveq   #$FFFFFFFF,d1
0404AFD8: 2481                     move.l  d1,(a2)
0404AFDA: 246efffc                 movea.l -4(a6),a2
0404AFDE: 4e5e                     unlk    a6
0404AFE0: 4e75                     rts

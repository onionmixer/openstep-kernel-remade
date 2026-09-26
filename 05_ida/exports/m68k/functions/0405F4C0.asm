0405F4C0: 4856                     pea     (a6)
0405F4C2: 2c4f                     movea.l sp,a6
0405F4C4: 206e000c                 movea.l $C(a6),a0
0405F4C8: 4a280018                 tst.b   $18(a0)
0405F4CC: 6c0c                     bge.s   loc_405F4DA
0405F4CE: 2f280010                 move.l  $10(a0),-(sp)
0405F4D2: 61fffffeb7da             bsr.l   _lock_done
0405F4D8: 584f                     addq.w  #4,sp
0405F4DA: 2f2e0008                 move.l  8(a6),-(sp)
0405F4DE: 61fffffeb7ce             bsr.l   _lock_done
0405F4E4: 4e5e                     unlk    a6
0405F4E6: 4e75                     rts

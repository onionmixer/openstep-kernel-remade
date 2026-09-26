0406B4DA: 4856                     pea     (a6)
0406B4DC: 2c4f                     movea.l sp,a6
0406B4DE: 2f0a                     move.l  a2,-(sp)
0406B4E0: 246e0008                 movea.l 8(a6),a2
0406B4E4: 48780008                 pea     (8).w
0406B4E8: 2f0a                     move.l  a2,-(sp)
0406B4EA: 61ff00002170             bsr.l   _fc_flags_bset
0406B4F0: 48780010                 pea     ($10).w
0406B4F4: 2f0a                     move.l  a2,-(sp)
0406B4F6: 61ff00002190             bsr.l   _fc_flags_bclr
0406B4FC: 42a7                     clr.l   -(sp)
0406B4FE: 42a7                     clr.l   -(sp)
0406B500: 486a0018                 pea     $18(a2)
0406B504: 61fffffe544a             bsr.l   _thread_wakeup_prim
0406B50A: 246efffc                 movea.l -4(a6),a2
0406B50E: 4e5e                     unlk    a6
0406B510: 4e75                     rts

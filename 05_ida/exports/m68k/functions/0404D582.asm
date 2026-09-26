0404D582: 4856                     pea     (a6)
0404D584: 2c4f                     movea.l sp,a6
0404D586: 2f0a                     move.l  a2,-(sp)
0404D588: 246e0008                 movea.l 8(a6),a2
0404D58C: 4a2a0034                 tst.b   $34(a2)
0404D590: 6c0a                     bge.s   loc_404D59C
0404D592: 2f0a                     move.l  a2,-(sp)
0404D594: 61fffffffb2c             bsr.l   _vm_info_dequeue
0404D59A: 584f                     addq.w  #4,sp
0404D59C: 526a0006                 addq.w  #1,6(a2)
0404D5A0: 486a0018                 pea     $18(a2)
0404D5A4: 61ffffffd626             bsr.l   _lock_write
0404D5AA: 246efffc                 movea.l -4(a6),a2
0404D5AE: 4e5e                     unlk    a6
0404D5B0: 4e75                     rts

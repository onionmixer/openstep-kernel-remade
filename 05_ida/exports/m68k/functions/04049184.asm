04049184: 4856                     pea     (a6)
04049186: 2c4f                     movea.l sp,a6
04049188: 2f0a                     move.l  a2,-(sp)
0404918A: 2479040b5648             movea.l (_active_threads).l,a2
04049190: 4aaa00b4                 tst.l   $B4(a2)
04049194: 660a                     bne.s   loc_40491A0
04049196: 61ff00000784             bsr.l   _mach_reply_port
0404919C: 254000b4                 move.l  d0,$B4(a2)
040491A0: 202a00b4                 move.l  $B4(a2),d0
040491A4: 246efffc                 movea.l -4(a6),a2
040491A8: 4e5e                     unlk    a6
040491AA: 4e75                     rts

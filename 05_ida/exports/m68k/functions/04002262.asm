04002262: 3017                     move.w  (sp),d0
04002264: 02402000                 andi.w  #$2000,d0
04002268: 660c                     bne.s   loc_4002276
0400226A: 4eb904007bd0             jsr     _suser
04002270: 4a80                     tst.l   d0
04002272: 6602                     bne.s   loc_4002276
04002274: 4e73                     rte
04002276: 2039040b564c             move.l  (_boot_action).l,d0
0400227C: 2079040b57c8             movea.l (_reboot_vector).l,a0
04002282: 4ed0                     jmp     (a0)

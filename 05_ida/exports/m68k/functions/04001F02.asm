04001F02: 2079040b5648             movea.l (_active_threads).l,a0
04001F08: 20680024                 movea.l $24(a0),a0
04001F0C: 20280050                 move.l  $50(a0),d0
04001F10: 4e73                     rte

04001F12: 2079040b5648             movea.l (_active_threads).l,a0
04001F18: 20680024                 movea.l $24(a0),a0
04001F1C: 21400050                 move.l  d0,$50(a0)
04001F20: 4e73                     rte

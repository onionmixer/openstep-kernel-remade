040518A4: 4856                     pea     (a6)
040518A6: 2c4f                     movea.l sp,a6
040518A8: 2079040b5648             movea.l (_active_threads).l,a0
040518AE: 20280040                 move.l  $40(a0),d0
040518B2: 4e5e                     unlk    a6
040518B4: 4e75                     rts

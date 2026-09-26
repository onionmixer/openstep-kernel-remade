0407A3AC: 4856                     pea     (a6)
0407A3AE: 2c4f                     movea.l sp,a6
0407A3B0: 3239040c3e68             move.w  (_od_lock_pid).l,d1
0407A3B6: b26e000a                 cmp.w   $A(a6),d1
0407A3BA: 660c                     bne.s   loc_407A3C8
0407A3BC: 2f3c20006410             move.l  #$20006410,-(sp)
0407A3C2: 61fffffffe18             bsr.l   _od_lock
0407A3C8: 4e5e                     unlk    a6
0407A3CA: 4e75                     rts

0406BD66: 4856                     pea     (a6)
0406BD68: 2c4f                     movea.l sp,a6
0406BD6A: 206e0008                 movea.l 8(a6),a0
0406BD6E: 0ca8000100000014         cmpi.l  #$10000,$14(a0)
0406BD76: 6f08                     ble.s   loc_406BD80
0406BD78: 217c000100000014         move.l  #$10000,$14(a0)
0406BD80: 4e5e                     unlk    a6
0406BD82: 4e75                     rts

0401C8EA: 4856                     pea     (a6)
0401C8EC: 2c4f                     movea.l sp,a6
0401C8EE: 206e0008                 movea.l 8(a6),a0
0401C8F2: 2f10                     move.l  (a0),-(sp)
0401C8F4: 2f08                     move.l  a0,-(sp)
0401C8F6: 61ff0002d9cc             bsr.l   _kfree
0401C8FC: 4e5e                     unlk    a6
0401C8FE: 4e75                     rts

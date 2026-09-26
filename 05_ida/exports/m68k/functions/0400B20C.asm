0400B20C: 4856                     pea     (a6)
0400B20E: 2c4f                     movea.l sp,a6
0400B210: 4ab9040b67e0             tst.l   (_log_open).l
0400B216: 670c                     beq.s   loc_400B224
0400B218: 2f39040b67f0             move.l  (dword_40B67F0).l,-(sp)
0400B21E: 61ff000492b6             bsr.l   _calloutEntryDispatch
0400B224: 4e5e                     unlk    a6
0400B226: 4e75                     rts

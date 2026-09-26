0406908C: 4856                     pea     (a6)
0406908E: 2c4f                     movea.l sp,a6
04069090: 2f02                     move.l  d2,-(sp)
04069092: 242e0008                 move.l  8(a6),d2
04069096: 4280                     clr.l   d0
04069098: 4a82                     tst.l   d2
0406909A: 6704                     beq.s   loc_40690A0
0406909C: 7003                     moveq   #3,d0
0406909E: 4840                     swap    d0
040690A0: 2f00                     move.l  d0,-(sp)
040690A2: 487800c5                 pea     ($C5).w
040690A6: 61ff00007684             bsr.l   _km_send
040690AC: 2f02                     move.l  d2,-(sp)
040690AE: 61ffffffb7fc             bsr.l   _adb_keyboard_LED
040690B4: 242efffc                 move.l  -4(a6),d2
040690B8: 4e5e                     unlk    a6
040690BA: 4e75                     rts

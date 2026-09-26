0406A7CA: 4856                     pea     (a6)
0406A7CC: 2c4f                     movea.l sp,a6
0406A7CE: 4ab9040c3308             tst.l   (_autoDimmed).l
0406A7D4: 6706                     beq.s   loc_406A7DC
0406A7D6: 61ffffffe9a4             bsr.l   _UndoAutoDim
0406A7DC: 61fffffffdbc             bsr.l   _InitMouseVars
0406A7E2: 4e5e                     unlk    a6
0406A7E4: 4e75                     rts

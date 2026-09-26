0406A7A8: 4856                     pea     (a6)
0406A7AA: 2c4f                     movea.l sp,a6
0406A7AC: 4ab9040c36c8             tst.l   (_screens).l
0406A7B2: 6712                     beq.s   loc_406A7C6
0406A7B4: 42a7                     clr.l   -(sp)
0406A7B6: 2f39040c3610             move.l  (_currentScreen).l,-(sp)
0406A7BC: 48780001                 pea     (1).w
0406A7C0: 61ff000000a8             bsr.l   _evdispatch
0406A7C6: 4e5e                     unlk    a6
0406A7C8: 4e75                     rts

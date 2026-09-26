0408103E: 4856                     pea     (a6)
04081040: 2c4f                     movea.l sp,a6
04081042: 2239040c32d4             move.l  (_slot_id).l,d1
04081048: 0681020000d0             addi.l  #$20000D0,d1
0408104E: 23c1040c6d18             move.l  d1,(dword_40C6D18).l
04081054: 7205                     moveq   #5,d1
04081056: 23c1040c6d28             move.l  d1,(dword_40C6D28).l
0408105C: 42b9040c6d10             clr.l   (dword_40C6D10).l
04081062: 42b9040c6e84             clr.l   (dword_40C6E84).l
04081068: 42b9040c6e7c             clr.l   (dword_40C6E7C).l
0408106E: 42b9040c6e80             clr.l   (dword_40C6E80).l
04081074: 42b9040c6e5e             clr.l   (dword_40C6E5E).l
0408107A: 61ff000016e8             bsr.l   _dspq_init_lmsg
04081080: 42a7                     clr.l   -(sp)
04081082: 61ff00001662             bsr.l   sub_40826E6
04081088: 4e5e                     unlk    a6
0408108A: 4e75                     rts

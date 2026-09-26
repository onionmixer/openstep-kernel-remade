04047D8C: 4e56fff8                 link    a6,#-8
04047D90: 2079040b5648             movea.l (_active_threads).l,a0
04047D96: 486efff8                 pea     var_8(a6)
04047D9A: 486efffc                 pea     var_4(a6)
04047D9E: 487904047d8c             pea     (_exception_raise_continue).l
04047DA4: 48780001                 pea     (1).w
04047DA8: 42a7                     clr.l   -(sp)
04047DAA: 4878ffff                 pea     ($FFFFFFFF).w
04047DAE: 42a7                     clr.l   -(sp)
04047DB0: 723c                     moveq   #$3C,d1 ; '<'
04047DB2: d2a800bc                 add.l   $BC(a0),d1
04047DB6: 2f01                     move.l  d1,-(sp)
04047DB8: 61ffffff7956             bsr.l   _ipc_mqueue_receive
04047DBE: defc001c                 adda.w  #$1C,sp
04047DC2: 2eaefff8                 move.l  var_8(a6),(sp)
04047DC6: 2f2efffc                 move.l  var_4(a6),-(sp)
04047DCA: 2f00                     move.l  d0,-(sp)
04047DCC: 61ff00000008             bsr.l   _exception_raise_continue_slow
04047DD2: 4e5e                     unlk    a6
04047DD4: 4e75                     rts

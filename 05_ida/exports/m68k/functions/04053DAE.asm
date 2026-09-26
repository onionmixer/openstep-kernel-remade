04053DAE: 4856                     pea     (a6)
04053DB0: 2c4f                     movea.l sp,a6
04053DB2: 226e0008                 movea.l 8(a6),a1
04053DB6: 20290048                 move.l  $48(a1),d0
04053DBA: 2200                     move.l  d0,d1
04053DBC: 028100000300             andi.l  #$300,d1
04053DC2: 0c8100000100             cmpi.l  #$100,d1
04053DC8: 6638                     bne.s   loc_4053E02
04053DCA: 0240fcff                 andi.w  #$FCFF,d0
04053DCE: 00400200                 ori.w   #$200,d0
04053DD2: 23400048                 move.l  d0,$48(a1)
04053DD6: 22bc040c2b68             move.l  #$40C2B68,(a1)
04053DDC: 2379040c2b6c0004         move.l  (dword_40C2B6C).l,4(a1)
04053DE4: 20690004                 movea.l 4(a1),a0
04053DE8: 2089                     move.l  a1,(a0)
04053DEA: 23c9040c2b6c             move.l  a1,(dword_40C2B6C).l
04053DF0: 42a7                     clr.l   -(sp)
04053DF2: 42a7                     clr.l   -(sp)
04053DF4: 4879040c2b68             pea     (_swapin_queue).l
04053DFA: 61ffffffcb54             bsr.l   _thread_wakeup_prim
04053E00: 6014                     bra.s   loc_4053E16
04053E02: 0c8100000200             cmpi.l  #$200,d1
04053E08: 670c                     beq.s   loc_4053E16
04053E0A: 4879040a90a1             pea     (aThreadSwapin).l; "thread_swapin"
04053E10: 61fffffb7e54             bsr.l   _panic
04053E16: 4e5e                     unlk    a6
04053E18: 4e75                     rts

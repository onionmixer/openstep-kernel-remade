04002DC8: 4856                     pea     (a6)
04002DCA: 2c4f                     movea.l sp,a6
04002DCC: 2f0a                     move.l  a2,-(sp)
04002DCE: 4879040a5d8a             pea     (aInit).l; "init"
04002DD4: 61fffffffb40             bsr.l   _task_name
04002DDA: 584f                     addq.w  #4,sp
04002DDC: 2479040b57d4             movea.l (dword_40B57D4).l,a2
04002DE2: 2079040b5648             movea.l (_active_threads).l,a0
04002DE8: 20680024                 movea.l $24(a0),a0
04002DEC: 4aa8004c                 tst.l   $4C(a0)
04002DF0: 6706                     beq.s   loc_4002DF8
04002DF2: 20280048                 move.l  $48(a0),d0
04002DF6: 600e                     bra.s   loc_4002E06
04002DF8: 2f39040b5648             move.l  (_active_threads).l,-(sp)
04002DFE: 61ff00093b52             bsr.l   _thread_user_state
04002E04: 584f                     addq.w  #4,sp
04002E06: 2480                     move.l  d0,(a2)
04002E08: 61ff00002416             bsr.l   _load_init_program
04002E0E: 61ff00093bb2             bsr.l   _thread_exception_return
04002E14: 246efffc                 movea.l -4(a6),a2
04002E18: 4e5e                     unlk    a6
04002E1A: 4e75                     rts

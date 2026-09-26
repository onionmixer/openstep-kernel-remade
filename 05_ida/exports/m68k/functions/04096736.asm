04096736: 23cf040b5640             move.l  sp,(dword_40B5640).l
0409673C: 4267                     clr.w   -(sp)
0409673E: 48e7ffff                 movem.l d0-d7/a0-a7,-(sp)
04096742: 4e7a8800                 movec   usp,a0
04096746: 2f08                     move.l  a0,-(sp)
04096748: 204f                     movea.l sp,a0
0409674A: 2f08                     move.l  a0,-(sp)
0409674C: d1fc00000046             adda.l  #$46,a0 ; 'F'
04096752: 2f480044                 move.l  a0,$4A+var_6(sp)
04096756: 4eb90409554a             jsr     _dbg_trap
0409675C: 23c0040b563c             move.l  d0,(dword_40B563C).l
04096762: 588f                     addq.l  #4,sp
04096764: 205f                     movea.l (sp)+,a0
04096766: 4e7b8800                 movec   a0,usp
0409676A: 4cdfffff                 movem.l (sp)+,d0-d7/a0-a7
0409676E: 2e79040b5640             movea.l (dword_40B5640).l,sp
04096774: 2f39040b563c             move.l  (dword_40B563C).l,-(sp)
0409677A: 4e75                     rts

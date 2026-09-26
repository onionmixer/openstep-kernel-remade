04071DA0: 4856                     pea     (a6)
04071DA2: 2c4f                     movea.l sp,a6
04071DA4: 2079040b1bbe             movea.l (dword_40B1BBE).l,a0
04071DAA: 43e80001                 lea     1(a0),a1
04071DAE: 23c9040b1bbe             move.l  a1,(dword_40B1BBE).l
04071DB4: 4a88                     tst.l   a0
04071DB6: 6610                     bne.s   loc_4071DC8
04071DB8: 2039040b6968             move.l  (dword_40B6968).l,d0
04071DBE: 6708                     beq.s   loc_4071DC8
04071DC0: 2f00                     move.l  d0,-(sp)
04071DC2: 61ff000000bc             bsr.l   _km_run_pcode
04071DC8: 4e5e                     unlk    a6
04071DCA: 4e75                     rts

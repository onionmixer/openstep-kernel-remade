04002FA2: 4856                     pea     (a6)
04002FA4: 2c4f                     movea.l sp,a6
04002FA6: 703f                     moveq   #$3F,d0 ; '?'
04002FA8: d0b9040b5b38             add.l   (_cfree).l,d0
04002FAE: 72c0                     moveq   #$FFFFFFC0,d1
04002FB0: c280                     and.l   d0,d1
04002FB2: 2241                     movea.l d1,a1
04002FB4: 2039040af71c             move.l  (_nclist).l,d0
04002FBA: ed80                     asl.l   #6,d0
04002FBC: 2079040b5b38             movea.l (_cfree).l,a0
04002FC2: 41f008c0                 lea     -$40(a0,d0.l),a0
04002FC6: 2008                     move.l  a0,d0
04002FC8: b089                     cmp.l   a1,d0
04002FCA: 631c                     bls.s   loc_4002FE8
04002FCC: 22b9040af730             move.l  (_cfreelist).l,(a1)
04002FD2: 23c9040af730             move.l  a1,(_cfreelist).l
04002FD8: 7234                     moveq   #$34,d1 ; '4'
04002FDA: d3b9040af734             add.l   d1,(_cfreecount).l
04002FE0: d2fc0040                 adda.w  #$40,a1 ; '@'
04002FE4: b089                     cmp.l   a1,d0
04002FE6: 62e4                     bhi.s   loc_4002FCC
04002FE8: 4e5e                     unlk    a6
04002FEA: 4e75                     rts

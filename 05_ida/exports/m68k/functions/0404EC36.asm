0404EC36: 4856                     pea     (a6)
0404EC38: 2c4f                     movea.l sp,a6
0404EC3A: 0cae040b67d80008         cmpi.l  #$40B67D8,8(a6)
0404EC42: 660c                     bne.s   loc_404EC50
0404EC44: 2f2e000c                 move.l  $C(a6),-(sp)
0404EC48: 61fffffffe64             bsr.l   sub_404EAAE
0404EC4E: 6002                     bra.s   loc_404EC52
0404EC50: 7016                     moveq   #$16,d0
0404EC52: 4e5e                     unlk    a6
0404EC54: 4e75                     rts

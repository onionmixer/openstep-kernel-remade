0409C6D0: 61ff000021ce             bsr.l   nrm_zero
0409C6D6: 082800070004             btst    #7,4(a0)
0409C6DC: 67ff0000000c             beq.l   loc_409C6EA
0409C6E2: 002e0000ffac             ori.b   #0,-$54(a6)
0409C6E8: 4e75                     rts
0409C6EA: 002e0080ffac             ori.b   #$80,-$54(a6)
0409C6F0: 4e75                     rts

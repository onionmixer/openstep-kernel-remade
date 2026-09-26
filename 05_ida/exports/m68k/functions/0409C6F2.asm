0409C6F2: 61ff000021ac             bsr.l   nrm_zero
0409C6F8: 082800070004             btst    #7,4(a0)
0409C6FE: 67ff0000000c             beq.l   loc_409C70C
0409C704: 002e0000ffac             ori.b   #0,-$54(a6)
0409C70A: 4e75                     rts
0409C70C: 002e0080ffac             ori.b   #$80,-$54(a6)
0409C712: 4e75                     rts

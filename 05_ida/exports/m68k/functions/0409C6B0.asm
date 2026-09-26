0409C6B0: 61ff000021ee             bsr.l   nrm_zero
0409C6B6: 082800070004             btst    #7,4(a0)
0409C6BC: 66ff00000010             bne.l   locret_409C6CE
0409C6C2: 006e0080ffac             ori.w   #$80,-$54(a6)
0409C6C8: 08ee0003ff86             bset    #3,-$7A(a6)
0409C6CE: 4e75                     rts

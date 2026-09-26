0409CBB2: 00ae00000208ff84         ori.l   #$208,-$7C(a6)
0409CBBA: 082e0003ff86             btst    #3,-$7A(a6)
0409CBC0: 67ff0000000a             beq.l   locret_409CBCC
0409CBC6: 08ee0005ff87             bset    #5,-$79(a6)
0409CBCC: 4e75                     rts

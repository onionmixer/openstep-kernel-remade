040013C4: 4e560000                 link    a6,#0
040013C8: 40c0                     move    sr,d0
040013CA: e088                     lsr.l   #8,d0
040013CC: 028000000007             andi.l  #7,d0
040013D2: 4e5e                     unlk    a6
040013D4: 4e75                     rts

040A4504: e588                     lsl.l   #2,d0
040A4506: e9ee1082ff83             bfextu  -$7D(a6){2:2},d1
040A450C: 8081                     or.l    d1,d0
040A450E: 43f9040a44c4             lea     ((loc_40A44C2+2)).l,a1
040A4514: 22710c00                 movea.l (a1,d0.l*4),a1
040A4518: 4ed1                     jmp     (a1)

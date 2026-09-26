040A418E: e588                     lsl.l   #2,d0
040A4190: e9ee1082ff83             bfextu  -$7D(a6){2:2},d1
040A4196: 8081                     or.l    d1,d0
040A4198: 43f9040a4078             lea     (loc_40A4078).l,a1
040A419E: 22710c00                 movea.l (a1,d0.l*4),a1
040A41A2: 4ed1                     jmp     (a1)

040A0BE0: 4e56ff40                 link    a6,#-$C0
040A0BE4: f327                     fsave   -(sp)
040A0BE6: 08ae0002ff24             bclr    #2,var_DC(a6)
040A0BEC: f35f                     frestore (sp)+
040A0BEE: 4e5e                     unlk    a6
040A0BF0: 52b9040b3108             addq.l  #1,(dword_40B3108).l
040A0BF6: 4ef904001b3e             jmp     std_trap

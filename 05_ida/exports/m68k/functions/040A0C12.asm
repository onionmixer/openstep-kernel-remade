040A0C12: 4e56ff40                 link    a6,#-$C0
040A0C16: f327                     fsave   -(sp)
040A0C18: 08ae0002ff24             bclr    #2,var_DC(a6)
040A0C1E: f35f                     frestore (sp)+
040A0C20: 4e5e                     unlk    a6
040A0C22: 52b9040b3104             addq.l  #1,(dword_40B3104).l
040A0C28: 4ef904001b3e             jmp     std_trap
